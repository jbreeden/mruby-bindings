module ID
  def self.type_name_to_id(type)
    type.sub(/\s*(struct|enum)\s*/, '').
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
  
  def self.type_name_to_rb_class(type)
    type.sub(/(struct|enum)\s*/, '').
      split('_').
      map { |token| "#{token[0].upcase if token.length > 0}#{token[1..(token.length)] if token.length > 1}" }.
      join('')
  end
  
  # Just makes the first character of each `_` separated token is captialized
  def self.to_rb_const(enum)
    enum.split('_').map { |token| token[0].upcase + token[1..(token.length)] }.join('_')
  end
end

module MacroBox
  # Helping the macro type detection system.
  # See use of MacroBox below
  TRUE = true
  FALSE = false
end

require_relative "./yargs.rb"
require 'fileutils'
require 'json'
require 'erb'
require 'pp'
require_relative './ctypes'
require_relative './builtin_ctypes'

USAGE = <<EOS
clang2json [CLANG_OPTIONS...] | ruby mruby_bindings.rb -g GEM_NAME -m MODULE_NAME -o OUTPUT_DIR [OTHER_OPTIONS...]

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
    
  --includes=FILE
    By default, include statements are inserted for every header file encountered
    in the type information from clang2json. These are naive, including only the
    file names. Additionally, you often don't need to - or can't - actually include
    them all when you compile the final gem. This option allows you to override
    the list of include statements, by pointing to a file that you've setup
    ahead of time.
    
    Example:
    
      my_includes.h
      ----------------
      | #include "my/file.h"
      | #include "some/other/file.h"
      
      Invocation
      ----------
      | clang2json OPTIONS | mruby_bindings --includes ./my_includes.h OTHER_OPTIONS...
      
  --skip=(macros|src|include|mrblib|boxing|mrbgem.rake)
    Skip generation of the indicated portion of the mrbgem.
    
    If you've made manual changes to part of the generated bindings that you 
    don't want to overwrite, this is the option for the job.
    
    This shouldn't be needed often. It was only added to handle the macros case.
    Mruby-bindings has a hard time figuring out what macro expansions actually
    are (strings? integers?). It tries its best, but you're going to have to
    manually tweak them (mostly commenting useless ones out). Afterwards, use
    `--skip macros` and they will no longer be generated.
    
    WARNING
      The output directory is cleared before generating bindings.
      
      Any skipped portions simply won't exist. You should be copying the
      generated bindings to another folder (call this new folder your "master"
      files). As required, you can regenerate the bindings, and copy the result
      over your "master" files. In this way, the skipped portions will not
      overwrite your manual changes. This is the basic loop you'll go through -
      as you define additional CTypes other binding configurations - until you
      get bindings that are complete & functional.
    
    RECOMMENDATION
      Use Rake. Define Rake tasks for running clang2json & mruby_bindings, as 
      well as pulling the generated code to your master files.
    
    RECOMMENDATION
      When you first generate bindings, put them under version
      control. Each time you add a CType or change a setting, check the diff
      of the output to see the changes. Only then, once you've acheived the 
      effect you want, should you copy the generated code to your master files.
    
    May be specified multiple times.
    
  -l FILE
    Load a ruby file before processing. Useful for defining additional CTypes.

  -o, --output
    The output directory. This is where the generated source code will be saved.
    Default is './bindings'
  
  -v, --verbose
    Output extra comments in the generated bindings, as well as console logs.

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
$includes = yargs.value(:includes)
$output_dir = yargs.value(
  :o, :output, :dir, :directory, 'output-dir', 'output-directory'
) || 'bindings'
$force = yargs.flag(:f, :force)
$verbose = yargs.flag(:v, :verbose)

$skip = []
while (skip = yargs.value(:skip))
  $skip.push(skip)
end

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
  prev_datum = nil
  prev_type = nil
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
        ###### This has implications when there are pointers to this type.
        ###### The pointee_type_name also need to be adjusted.
        ###### Disabling until that is worked out.
        ## Handle common typedef idioms:
        ## 1) Type is declared then typedefed for a friendly name 
        ##    (typedef struct _my_struct my_struct).
        ## 
        ## NOTE: Anonymous types declared in the typedef are handled by clang2json
        ## So `typedef struct { fields... } TypeName;` will yield a StructDecl node
        ## with the name set to TypeName already.
        # if prev_type &&
        #      prev_type['usr'] == datum['underlying_type']['type_usr'] &&
        #      prev_type['name'] =~ /^(struct|enum) /
        #   prev_type['name'] = datum['type']['type_name']
        # else
          CTypes.typedef(datum['underlying_type']['type_name'], datum['type']['type_name'])
        # end
      when "ClassDecl", "StructDecl"
        datum['name'] = datum['name']
        # Ignore anonymous declarations
        # (They are named "anonymous SPACE something...")
        next if datum['name'] =~ /anonymous\s/i
        cxxClass = $classes[datum['usr']] || datum
        cxxClass['fields'] ||= []
        cxxClass['member_functions'] ||= []
        $classes[datum['usr']] = cxxClass
        prev_type = cxxClass
      when "ClassTemplate"
        cxxClass = $classes[datum["usr"]] || datum
        cxxClass['fields'] ||= []
        cxxClass['member_functions'] ||= []
        # TODO: is_template is redundant, as kind == 'ClassTemplate'
        cxxClass['is_template'] = 'true'
        $classes[datum["usr"]] = cxxClass
        prev_type = cxxClass
      when "EnumDecl"
        # Ignore anonymous declarations
        # (They are named "anonymous something...")
        next if datum['name'] =~ /anonymous\s/i
        enum = $enums[datum['usr']] || datum
        enum['constants'] ||= []
        $enums[datum['usr']] = enum
        prev_type = cxxClass
      when "EnumConstantDecl"
        enum = $enums[datum['member_of']]
        unless enum
          $stderr.puts "WARNING: Enum constant '#{datum['name']}' declared for unknown type '#{datum['member_of']}'"
          next
        end
        enum['constants'].push(datum)
      when "CXXMethod"
        cxxClass = $classes[datum["member_of"]]
        unless cxxClass
          $stderr.puts "WARNING: Method '#{datum['name']}' declared for unknown type '#{datum['member_of']}'"
          next
        end
        cxxClass['member_functions'].push(datum)
        datum['params'] ||= []
        $current_function = datum
        $current_function['argc'] = 0
      when "FieldDecl"
        cxxClass = $classes[datum["member_of"]]
        unless cxxClass
          $stderr.puts "WARNING: Field '#{datum['name']}' declared for unknown type '#{datum['member_of']}'"
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
      prev_datum = datum
    rescue StandardError => ex
      $stderr.puts "ERROR: #{ex} \n  (while processing #{datum})\n  Backtrace:\n  #{ex.backtrace.join("\n  ")}"
    end
  end
end

def annotate_declarations
  $enums.each do |usr, enum|
    CTypes.learn_enum(enum['name'])
  end
  
  $classes.each do |usr, klass|
    klass['ruby_name'] = ID.type_name_to_rb_class(klass['name'])
  end

  $classes.each do |usr, klass|
    klass['fields'].each do |field|
      CTypes.learn_data_type(field['type'])
      field['ctype'] = CTypes[field['type']]
    end
  end

  # Process functions & methods.
  # - Add boxing/unboxing functions to any known param types
  # - Add boxing/unboxing functions to any known return types
  # - Add names for anonymous parameters
  # - Associate parameters & return values with specified types
  $module_functions.values.concat($classes.values.flat_map { |c| c['member_functions']}).each do |func|
    func['out_count'] = 0
    if func['return_type']['type_name'] != 'void'
      func['out_count'] += 1
    else
      func['is_void'] = true
    end
    func['ctype'] = CTypes.get_fn_return_type(func['name'])
    func['ctype'] ||= CTypes.learn_data_type(func['return_type'])
    func['incomplete'] = true if func['ctype'].unknown?
    
    func['in_params'] = []
    func['out_params'] = []
    adjusted_params = []
    func['params'].each_with_index do |param, i|
      if param['name'] == ''
        param['name'] = "arg#{i + 1}"
      end
      ctype = CTypes.get_fn_param_type(func['name'], param['name']) 
      ctype ||= CTypes.learn_data_type(param['type'])
      param['ctype'] = ctype
      func['incomplete'] = true if ctype.unknown?
      next if ctype.ignore?
      adjusted_params.push(param)
      if ctype.out_only?
        func['out_count'] += 1
        func['out_params'].push(param)
      else
        func['in_params'].push(param)
      end
    end
    func['params'] = adjusted_params
  end
end

def write_file(name, &block)
  puts "Writing file: #{name}" if $verbose
  File.open(name, 'w', &block)
end

def generate_bindings
  # Setting up locals for the templates
  gem_name = $gem_name
  module_name = $module_name
  module_functions = $module_functions.values.sort_by { |f| f['name'].downcase }
  enums = $enums.values.sort_by { |e| e['name'].downcase }
  classes = $classes.values.sort_by { |c| c['ruby_name'].downcase }
  macros = $macros.sort_by { |m| m['name'].downcase }

  boxing_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/boxing_template.erb"), nil, "-")
  class_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/class_template.erb"), nil, "-")
  module_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/module_template.erb"), nil, "-")
  enums_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/enums_template.erb"), nil, "-")
  header_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/header_template.erb"), nil, "-")
  boxing_header_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/boxing_header_template.erb"), nil, "-")
  classes_header_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/classes_header_template.erb"), nil, "-")
  macros_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/macros_template.erb"), nil, "-")
  mrbgem_erb = ERB.new(File.read("#{File.dirname(__FILE__)}/templates/mrbgem.rake.erb"), nil, "-")

  unless $skip.include?('src')
    if $classes.any?
      to_gen = $classes.values.reject { |c| c['is_template'] }
      to_gen.each do |the_class|
        the_class.instance_eval do
          write_file("#{$output_dir}/src/mruby_#{ID.type_name_to_id(the_class['name'])}.#{$ext}") do |file|
            file.puts(class_erb.result binding)
          end
        end
      end
    
      write_file "#{$output_dir}/src/mruby_#{module_name}_boxing.#{$ext}" do |file|
        file.puts(boxing_erb.result binding)
      end
    end
  end
  
  unless $skip.include?('mrblib')
    if $enums.any?
      write_file("#{$output_dir}/mrblib/#{module_name}.rb") do |file|
        file.puts(enums_erb.result binding)
      end
    end
  end
  
  unless $skip.include?('src')
    write_file("#{$output_dir}/src/mruby_#{module_name}.#{$ext}") do |file|
      file.puts(module_erb.result binding)
    end
  end
  
  unless $skip.include?('include')
    write_file("#{$output_dir}/include/mruby_#{module_name}.h") do |file|
      file.puts(header_erb.result binding)
    end
  end
  
  unless $skip.include?('include') || $skip.include?('boxing')
    write_file("#{$output_dir}/include/mruby_#{module_name}_boxing.h") do |file|
      file.puts(boxing_header_erb.result binding)
    end
  end
  
  unless $skip.include?('macros')
    write_file("#{$output_dir}/src/mruby_#{module_name}_macro_constants.#{$ext}") do |file|
      file.puts(macros_erb.result binding)
    end
  end
  
  unless $skip.include?('mrbgem.rake')
    write_file("#{$output_dir}/mrbgem.rake") do |file|
      file.puts(mrbgem_erb.result binding)
    end
  end
  
  unless $skip.include?('include')
    generate_functions_header
    generate_classes_header
  end
end

def generate_functions_header
  write_file("#{$output_dir}/include/mruby_#{$module_name}_functions.h") do |out|
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
          # todo is set to false after each function is processed.
          # So, create a new array to hold the todo's for the next function.
          todo = [] unless todo
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

def generate_classes_header
  write_file("#{$output_dir}/include/mruby_#{$module_name}_classes.h") do |out|
    out.puts "#ifndef MRUBY_#{$module_name}_CLASSES_HEADER"
    out.puts "#define MRUBY_#{$module_name}_CLASSES_HEADER"
    out.puts
    Dir["#{$output_dir}/src/*"].each do |f|
      if (f == '.' ||
          f == '..' ||
          f == "#{$output_dir}/src/mruby_#{$module_name}.#{$ext}" ||
          f == "#{$output_dir}/src/mruby_#{$module_name}_boxing.#{$ext}" ||
          f == "#{$output_dir}/src/mruby_#{$module_name}_macro_constants.#{$ext}")
        next
      end
      File.open(f, 'r') do |f|
        this_fn_name = ''
        this_fn_type = nil
        todo = false
        f.each_line do |line|
          if type = line[/#if BIND_(.*)_TYPE$/, 1]
            out.puts "#define BIND_#{type}_TYPE TRUE"
            next
          end
          
          if this_fn_type = line[/^#if BIND.*(FIELD_READER|FIELD_WRITER|FUNCTION)/, 1]
            this_fn_name = line.split(' ')[1].strip
            todo = false
            next
          end

          if line =~ /TODO/
            # todo is set to false after each function is processed.
            # So, create a new array to hold the todo's for the next function.
            todo = [] unless todo
            todo.push(line[/TODO([^\s(]*)/])
          end

          if line =~ /^#endif/ && !this_fn_name.empty?
            if todo
              out.puts "#define #{this_fn_name} FALSE"
              if $verbose
                out.puts "/* Couln't complete binding for #{this_fn_name.sub('BIND_', '').sub(this_fn_type, '')}"
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

          if line =~ /void.*mrb.*init\(/
            break
          end
        end
      end
    end
    out.puts "#endif"
  end
end

def print_diagnostics
  if $verbose
    File.open('mruby_bindings_diagnostics/class_definitions.txt', 'w') do |file|
      PP.pp $classes, file
    end
    File.open('mruby_bindings_diagnostics/function_definitions.txt', 'w') do |file|
      PP.pp $module_functions, file
    end
    File.open('mruby_bindings_diagnostics/enum_definitions.txt', 'w') do |file|
      PP.pp $enums, file
    end
  end
  File.open('mruby_bindings_diagnostics/fn_types.rb', 'w') do |file|
    $module_functions.values.sort_by { |f| f['name'].downcase }.each do |f|
      if f['incomplete']
        file.puts "# ## #{f['return_type']['type_name']} #{f['name']}(#{f['params'].map { |p| "#{p['type']['type_name']} #{p['name']}" }.join(', ')})"
        if f['ctype'].unknown?
          file.puts "# # Return value"
          file.puts "# CTypes.set_fn_return_type('#{f['name']}', CTypes['???'])"
        end
        f['params'].each do |p|
          if p['ctype'].unknown?
            file.puts "# # Param: #{p['name']}"
            file.puts "# CTypes.set_fn_param_type('#{f['name']}', '#{p['name']}', CTypes['???'])"
          end
        end
        file.puts
      end
    end
  end
  File.open('mruby_bindings_diagnostics/macro_types.rb', 'w') do |file|
    $macros.each do |m|
      next unless m['has_expansion'] && CTypes.get_macro_type(m['name']).nil?
      file.puts "# CTypes.set_macro_type('#{m['name']}', CTypes['???'])"
    end
  end
end

FileUtils.rm_rf 'mruby_bindings_diagnostics'
Dir.mkdir('mruby_bindings_diagnostics')
make_declaration_tree
annotate_declarations
print_diagnostics
generate_bindings
