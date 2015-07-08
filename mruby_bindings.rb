class String
  def type_to_identifier
    self.gsub(/\*|&|\(|\)|,/, '*' => ' PTR ', '&' => ' REF ', '(' => ' LPAREN ', ')' => ' RPAREN ', ',' => 'COMMA').split(/\s+/).join('_')
  end
end

require 'fileutils'
require 'json'
require 'erb'
require 'pp'
require_relative './ctypes'

# TODO:
# Validate gem name is all leters and hyphens
# Validate module name is a valid ruby module identifier
# Print usage message for invalid inputs

$gem_name = ARGV[0]
$module_name = ARGV[1]
$output_dir = ARGV[2] || 'bindings'

FileUtils.rm_rf($output_dir) if Dir.exists?($output_dir)
Dir.mkdir $output_dir
Dir.mkdir "#{$output_dir}/include"
Dir.mkdir "#{$output_dir}/mrblib"
Dir.mkdir "#{$output_dir}/src"

# TODO: Use one hash based on usrs for indexing, then all collections should be arrays
$current_function = nil
$classes = {} # Includes structs
$module_functions = []
$enums = {}
$macros = []

at_exit do
  make_declaration_tree
  annotate_declarations
  print_diagnostics
  generate_bindings
end

def make_declaration_tree
  while line = $stdin.gets
    begin
      datum = JSON.parse(line)
    rescue
      $stderr.puts "Error parsing json: #{line}"
      next
    end
    begin
      case datum["kind"]
      when "TypedefDecl"
        CTypes.typedef(datum['underlying_type']['type_name'], datum['type']['type_name'])
      when "ClassDecl", "StructDecl"
        # Ignore anonymous declarations
        # (They are named "anonymous something...")
        next if datum['name'].include? ' '
        cxxClass = $classes[datum['usr']] || datum
        cxxClass['fields'] ||= []
        cxxClass['member_functions'] ||= []
        $classes[datum['usr']] = cxxClass
      when "ClassTemplate"
        cxxClass = $classes[datum["usr"]] || datum
        cxxClass['fields'] ||= []
        cxxClass['member_functions'] ||= []
        # TODO: is_template is redundant, as kind == 'ClassTemplate'
        cxxClass['is_template'] = 'true'
        $classes[datum["usr"]] = cxxClass
      when "EnumDecl"
        # Ignore anonymous declarations
        # (They are named "anonymous something...")
        next if datum['name'].include? ' '
        enum = $enums[datum['usr']] || datum
        enum['constants'] ||= []
        $enums[datum['usr']] = enum
      when "EnumConstantDecl"
        enum = $enums[datum['member_of']]
        unless enum
          $stderr.puts "WARNING: Enum constant '#{datum['name']}' declared for unkown type '#{datum['member_of']}'"
          next
        end
        enum['constants'].push(datum)
      when "CXXMethod"
        cxxClass = $classes[datum["member_of"]]
        unless cxxClass
          $stderr.puts "WARNING: Method '#{datum['name']}' declared for unkown type '#{datum['member_of']}'"
          next
        end
        cxxClass['member_functions'].push(datum)
        datum['params'] ||= []
        $current_function = datum
        $current_function['argc'] = 0
      when "FieldDecl"
        cxxClass = $classes[datum["member_of"]]
        unless cxxClass
          $stderr.puts "WARNING: Field '#{datum['name']}' declared for unkown type '#{datum['member_of']}'"
          next
        end
        cxxClass["fields"].push(datum)
      when "FunctionDecl"
        datum['params'] ||= []
        $current_function = datum
        $current_function['argc'] = 0
        $module_functions.push(datum)
      when "ParmDecl"
        $current_function['argc'] += 1
        $current_function['params'] ||= []
        $current_function['params'].push(datum)
      when "MacroDefinition"
        $macros.push(datum)
        datum['has_expansion'] = datum['text'] =~ /\s/
        if datum['text'] =~ /^[a-zA-Z_0-9]+\(/
          datum['is_function_like'] = true
          datum['argv'] = datum['text'][/[^(]+\(([^)]*)\)/, 1].split(',').map { |a| a.strip }
        else
          datum['is_function_like'] = false
        end
      end
    rescue StandardError => ex
      $stderr.puts "ERROR: #{ex} \n  (while processing #{datum})\n  Backtrace:\n  #{ex.backtrace.join("\n  ")}"
    end
  end
end

# TODO: This function name isn't really valid anymore
def annotate_declarations
  $classes.each do |usr, klass|
    klass['ruby_name'] = klass['name'].split('_').map { |token| token.capitalize }.join('')
  end

  $classes.each do |usr, klass|
    klass['fields'].each do |field|
      CTypes.learn_data_type(field['type'])
    end
  end

  # Process functions & methods.
  # - Add boxing/unboxing functions to any known param types
  # - Add boxing/unboxing functions to any known return types
  # - Add names for anonymous parameters
  $module_functions.concat($classes.values.flat_map { |c| c['member_functions']}).each do |func|
    CTypes.learn_data_type(func['return_type'])
    func['params'].each_with_index do |param, i|
      if param['name'] == ''
        param['name'] = "arg#{i + 1}"
      end
      CTypes.learn_data_type(param['type'])
    end
  end
end

def print_diagnostics
  File.open('class_definitions.txt', 'w') do |file|
    PP.pp $classes, file
  end
  File.open('function_definitions.txt', 'w') do |file|
    PP.pp $module_functions, file
  end
  File.open('enum_definitions.txt', 'w') do |file|
    PP.pp $enums, file
  end
  File.open('macro_definitions.txt', 'w') do |file|
    PP.pp $macros, file
  end
end

def generate_bindings
  # Setting up locals for the templates
  gem_name = $gem_name
  module_name = $module_name
  module_functions = $module_functions.sort_by { |f| f['name'].downcase }
  enums = $enums.values.sort_by { |e| e['name'].downcase }
  classes = $classes.values.sort_by { |c| c['name'].downcase }
  macros = $macros.sort_by { |m| m['name'].downcase }

  boxing_erb = ERB.new(File.read('boxing_template.erb'), nil, "-")
  class_erb = ERB.new(File.read('class_template.erb'), nil, "-")
  module_erb = ERB.new(File.read('module_template.erb'), nil, "-")
  enums_erb = ERB.new(File.read('enums_template.erb'), nil, "-")
  header_erb = ERB.new(File.read('header_template.erb'), nil, "-")
  macros_erb = ERB.new(File.read('macros_template.erb'), nil, "-")

  if $classes.any?
    to_gen = $classes.values.reject { |c| c['is_template'] }
    to_gen.each do |the_class|
      the_class.instance_eval do
        File.open("#{$output_dir}/src/mruby_#{the_class['name'].sub('::', '_')}.cpp", "w") do |file|
          file.puts(class_erb.result binding)
        end
      end
    end

    File.open("#{$output_dir}/src/mruby_#{module_name}_boxing.cpp", "w") do |file|
      file.puts(boxing_erb.result binding)
    end
  end

  if $enums.any?
    File.open("#{$output_dir}/mrblib/#{module_name}.rb", "w") do |file|
      file.puts(enums_erb.result binding)
    end
  end

  File.open("#{$output_dir}/src/mruby_#{module_name}.cpp", "w") do |file|
    file.puts(module_erb.result binding)
  end

  File.open("#{$output_dir}/include/mruby_#{module_name}.h", "w") do |file|
    file.puts(header_erb.result binding)
  end

  File.open("#{$output_dir}/src/mruby_#{module_name}_macro_constants.cpp", "w") do |file|
    file.puts(macros_erb.result binding)
  end
end
