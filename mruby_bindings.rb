class String
  def type_to_identifier
    self.sub(/\s*(struct|enum)\s*/, '').
      sub(/\s*const\s*/, '').
      gsub(/\*|&|\(|\)|,|(::)/,
        '*' => ' PTR ',
        '&' => ' REF ',
        '(' => ' LPAREN ', ')' => ' RPAREN ',
        ',' => 'COMMA',
        '::' => '_'
      ).
      split(/\s+/).
      join('_')
  end

  def type_name_to_rb
    self.sub(/(struct|enum)\s*/, '').
      split('_').
      map { |token| "#{token[0].upcase if token.length > 0}#{token[1..(token.length)] if token.length > 1}" }.
      join('')
  end
end

require_relative "./yargs.rb"
require 'fileutils'
require 'json'
require 'erb'
require 'pp'
require_relative './ctypes'
require_relative './builtin_ctypes'

USAGE = <<EOS
clang2json [CLANG_OPTIONS...] | ruby mruby_bindings.rb -g GEM_NAME -m MODULE_NAME -o OUTPUT_DIR [-f]

  -g, -gem
    The name to use for this mrbgems. Should be mruby-something
    per the mrbgems recommendation. This will be used to generate
    the appropriate mrb_YOUR_GEM_NAME_gem_init functions, for example.

  -m, --module
    The name to use for the generated module. This is the module under which
    all macros, functions, classes, etc. generated from the C headers will
    be defined in Ruby land.
    
  -e, --extension
    The extension to use for source files. Default is 'c'. Use 'cpp' or similar
    if generating bindings to C++ code.
      
  -i, --input=FILE
    Input file. Default is STDIN
    
  -l FILE
    Load a ruby file before processing. Useful for defining additional CTypes.

  -o, --output
    The output directory. This is where the generated source code will be saved.
    Default is './bindings'
  
  -v, --verbose
    Output extra comments in the generated bindings.

  -f
    If the output directory exists, mruby-bindings will refuse to overwrite it
    by default. Use -f to force the overwrite.
EOS

# TODO:
# Validate gem name is all leters and hyphens
# Validate module name is a valid ruby module identifier
# Print usage message for invalid inputs
yargs = Yargs.new(ARGV, :consume)
$gem_name = yargs.value(:g, :gem, 'gem-name')
$module_name = yargs.value(:m, :module, 'module-name')
$ext = yargs.value(:e, :extension) || 'c'
$in = yargs.value(:i, :input)
$in = $in.nil? ? $stdin : File.open($in, 'r')
$output_dir = yargs.value(
  :o, :output, :dir, :directory, 'output-dir', 'output-directory'
) || 'bindings'
$force = yargs.flag(:f, :force)
$verbose = yargs.flag(:v, :verbose)

while (file = yargs.value(:l))
  load file
end

unless $gem_name
  $stderr.puts "Must specify the gem name `-g YOUR_GEM_NAME`\n\n"
  $stderr.puts USAGE
  exit 1
end

unless $module_name
  $stderr.puts "Must specify the module name `-m YOUR_MODULE_NAME`\n\n"
  $stderr.puts USAGE
  exit 1
end

if !$force && Dir.exists?($output_dir)
  puts "Output directory (#{$output_dir}) exists. Use -f to force overwrite"
  exit 1
end

FileUtils.rm_rf($output_dir) if Dir.exists?($output_dir)
Dir.mkdir $output_dir
Dir.mkdir "#{$output_dir}/include"
Dir.mkdir "#{$output_dir}/mrblib"
Dir.mkdir "#{$output_dir}/src"

# TODO: Use one hash based on usrs for indexing, then all collections should be arrays
$current_function = nil
$classes = {} # Includes structs
$module_functions = {}
$enums = {}
$macros = []

def make_declaration_tree
  while line = $in.gets
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
        datum['name'] = datum['name']
        # Ignore anonymous declarations
        # (They are named "anonymous SPACE something...")
        next if datum['name'] =~ /anonymous\s/i
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
        $module_functions[datum['usr']] = datum
      when "ParmDecl"
        unless $current_function
          $stderr.puts "WARNING: Param encountered outside of a method or function. This is probably a function pointer, which is not yet supported."
          next
        end
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
    klass['ruby_name'] = klass['name'].type_name_to_rb
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
  $module_functions.values.concat($classes.values.flat_map { |c| c['member_functions']}).each do |func|
    CTypes.learn_data_type(func['return_type'])
    func['params'].each_with_index do |param, i|
      if param['name'] == ''
        param['name'] = "arg#{i + 1}"
      end
      CTypes.learn_data_type(param['type'])
    end
  end
end

def generate_bindings
  # Setting up locals for the templates
  gem_name = $gem_name
  module_name = $module_name
  module_functions = $module_functions.values.sort_by { |f| f['name'].downcase }
  enums = $enums.values.sort_by { |e| e['name'].downcase }
  classes = $classes.values.sort_by { |c| c['name'].downcase }
  macros = $macros.sort_by { |m| m['name'].downcase }

  boxing_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/boxing_template.erb"), nil, "-")
  class_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/class_template.erb"), nil, "-")
  module_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/module_template.erb"), nil, "-")
  enums_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/enums_template.erb"), nil, "-")
  header_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/header_template.erb"), nil, "-")
  boxing_header_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/boxing_header_template.erb"), nil, "-")
  classes_header_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/classes_header_template.erb"), nil, "-")
  macros_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/macros_template.erb"), nil, "-")

  if $classes.any?
    to_gen = $classes.values.reject { |c| c['is_template'] }
    to_gen.each do |the_class|
      the_class.instance_eval do
        File.open("#{$output_dir}/src/mruby_#{the_class['name'].type_to_identifier}.#{$ext}", "w") do |file|
          file.puts(class_erb.result binding)
        end
      end
    end
  
    File.open("#{$output_dir}/src/mruby_#{module_name}_boxing.#{$ext}", "w") do |file|
      file.puts(boxing_erb.result binding)
    end
  end
  
  if $enums.any?
    File.open("#{$output_dir}/mrblib/#{module_name}.rb", "w") do |file|
      file.puts(enums_erb.result binding)
    end
  end
  
  File.open("#{$output_dir}/src/mruby_#{module_name}.#{$ext}", "w") do |file|
    file.puts(module_erb.result binding)
  end
  
  File.open("#{$output_dir}/include/mruby_#{module_name}.h", "w") do |file|
    file.puts(header_erb.result binding)
  end
  
  File.open("#{$output_dir}/include/mruby_#{module_name}_boxing.h", "w") do |file|
    file.puts(boxing_header_erb.result binding)
  end
  
  File.open("#{$output_dir}/include/mruby_#{module_name}_boxing.h", "w") do |file|
    file.puts(boxing_header_erb.result binding)
  end
  
  File.open("#{$output_dir}/include/mruby_#{module_name}_classes.h", "w") do |file|
    file.puts(classes_header_erb.result binding)
  end
  
  File.open("#{$output_dir}/src/mruby_#{module_name}_macro_constants.#{$ext}", "w") do |file|
    file.puts(macros_erb.result binding)
  end
  
  generate_functions_header
end

def generate_functions_header
  File.open("#{$output_dir}/include/mruby_#{$module_name}_functions.h", 'w') do |out|
    out.puts "#ifndef MRUBY_#{$module_name}_FUNCTIONS_HEADER"
    out.puts "#define MRUBY_#{$module_name}_FUNCTIONS_HEADER"
    out.puts
    File.open("#{$output_dir}/src/mruby_#{$module_name}.#{$ext}", 'r') do |f|
      this_fn_name = ''
      todo = false
      f.each_line do |line|
        if line =~ /^#if BIND.*FUNCTION/
          this_fn_name = line.split(' ')[1].strip
          todo = false
          next
        end

        if line =~ /TODO/
          todo = [] unless todo # Convert to array from `false`
          todo.push(line[/TODO([^\s(]*)/])
        end

        if line =~ /^#endif/ && !this_fn_name.empty?
          if todo
            out.puts "#define #{this_fn_name} FALSE"
            if $verbose
              out.puts "/* Couln't complete binding for #{this_fn_name.sub('BIND_', '').sub('_FUNCTION', '')}"
              todo.uniq.sort.each do |todo_item|
                out.puts "  - #{todo_item}"
              end
              out.puts "*/"
            end
          else
            out.puts "#define #{this_fn_name} TRUE"
          end
          todo = false
        end

        if line =~ /gem_init/
          break
        end
      end
    end
    out.puts "#endif"
  end
end

def print_diagnostics
  File.open('mruby_bindings_diagnostics/class_definitions.txt', 'w') do |file|
    PP.pp $classes, file
  end
  File.open('mruby_bindings_diagnostics/function_definitions.txt', 'w') do |file|
    PP.pp $module_functions, file
  end
  File.open('mruby_bindings_diagnostics/enum_definitions.txt', 'w') do |file|
    PP.pp $enums, file
  end
  File.open('mruby_bindings_diagnostics/macro_definitions.txt', 'w') do |file|
    PP.pp $macros, file
  end
end

def print_todo
  todos = []
  File.open("#{$output_dir}/src/mruby_#{$module_name}.#{$ext}", "r") do |file|
    file.each_line do |line|
      todos.push(line[/TODO([^\s(]*)/]) if line.include? "TODO"
    end
  end
  todos = todos.uniq.sort
  File.open('mruby_bindings_diagnostics/todo.txt', 'w') { |f| f.write todos.join("\n") }
end

FileUtils.rm_rf 'mruby_bindings_diagnostics'
Dir.mkdir('mruby_bindings_diagnostics')
make_declaration_tree
annotate_declarations
print_diagnostics
generate_bindings
print_todo
