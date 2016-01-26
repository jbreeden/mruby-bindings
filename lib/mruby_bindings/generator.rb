require 'fileutils'

# TODO: Stop using global variables. This project outgrew these a long time ago.
$current_function = nil
$classes = {} # Includes structs
$module_functions = {}
$enums = {}
$macros = []

module MRubyBindings
class Generator
  attr_reader :conf
  
  def initialize(conf)
    @conf = conf
  end
  
  def run
    FileUtils.rm_rf(conf[:output_dir]) if Dir.exists?(conf[:output_dir])
    Dir.mkdir conf[:output_dir]
    Dir.mkdir "#{conf[:output_dir]}/include"
    Dir.mkdir "#{conf[:output_dir]}/mrblib"
    Dir.mkdir "#{conf[:output_dir]}/src"
    FileUtils.rm_rf 'mruby-bindings.out'
    Dir.mkdir 'mruby-bindings.out'
    
    make_declaration_tree
    annotate_declarations
    print_diagnostics
    generate_bindings
  end

  def make_declaration_tree
    # Defer processing of typedefs until after all other types are known,
    # so that renaming can be performed correctly.
    typedefs = []
    
    while line = conf[:input].gets
      begin
        datum = JSON.parse(line)
        if datum['kind'] == 'TypedefDecl'
          typedefs.push(datum)
          next
        end
      rescue
        $stderr.puts "Error parsing json: #{line}"
        next
      end
      read_datum(datum)
    end
    
    typedefs.each { |t| read_datum(t) }
  end
  
  def read_datum(datum)
    case datum["kind"]
    when "TypedefDecl"
      # Handle common typedef idioms:
      #
      # Struct is defined, with a name, within a typedef to a public name.
      # Ex: `typedef struct _private_name { ... } public_name;`
      #
      # Struct is defined, then separately typedefed to a similar name,
      # such that the new name contains the orginal name minus a leading/trailing
      # character.
      # Ex: `typedef struct _my_type { ... } my_type`
      # Ex: `typedef struct my_type_s { ... } my_type_t`
      underlying_type_match = datum['underlying_type']['type_name'].
        sub('struct ', '').
        sub('enum ', '').
        sub(/^(_*)/, '').
        sub(/(_*)(t|s)?$/, '')
      underlying_type = $classes[datum['underlying_type']['type_usr']]
      
      if (underlying_type &&
          # If the typedef & the stuct definition start on the same line, it's definitely the name to use
          ( (underlying_type['file'] == datum['file'] && underlying_type['line'] == datum['line']) ||
          # Otherwise see if the names are just *really* similar
            ((-2..2) === datum['type']['type_name'].length - underlying_type_match.length) &&
             ( datum['type']['type_name'].downcase.include?(underlying_type_match) ||
               datum['type']['type_name'].downcase.include?(underlying_type_match) )
          )  
         )
        underlying_type['name'] = datum['type']['type_name']
        underlying_type['type']['type_name'] = datum['type']['type_name']
        
        $classes[datum['type']['type_usr']] = underlying_type
      end
      CTypes.typedef(datum['underlying_type']['type_name'], datum['type']['type_name'])
    when "ClassDecl", "StructDecl"
      # Ignore anonymous declarations
      # (They are named "anonymous SPACE something...")
      return nil if datum['name'] =~ /anonymous\s/i
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
      return nil if datum['name'] =~ /anonymous\s/i
      enum = $enums[datum['usr']] || datum
      enum['constants'] ||= []
      $enums[datum['usr']] = enum
    when "EnumConstantDecl"
      enum = $enums[datum['member_of']]
      unless enum
        $stderr.puts "WARNING: Enum constant '#{datum['name']}' declared for unknown type '#{datum['member_of']}'"
        return nil
      end
      enum['constants'].push(datum)
    when "CXXMethod"
      cxxClass = $classes[datum["member_of"]]
      unless cxxClass
        $stderr.puts "WARNING: Method '#{datum['name']}' declared for unknown type '#{datum['member_of']}'"
        return nil
      end
      cxxClass['member_functions'].push(datum)
      datum['params'] ||= []
      $current_function = datum
      $current_function['argc'] = 0
    when "FieldDecl"
      cxxClass = $classes[datum["member_of"]]
      unless cxxClass
        $stderr.puts "WARNING: Field '#{datum['name']}' declared for unknown type '#{datum['member_of']}'"
        return nil
      end
      cxxClass["fields"].push(datum)
    when "FunctionDecl"
      datum['params'] ||= []
      $current_function = datum
      $current_function['argc'] = 0
      $module_functions[datum['usr']] = datum
    when "ParmDecl"
      fn = $module_functions[datum['function']]
      if fn
        fn['argc'] += 1
        fn['params'] ||= []
        fn['params'].push(datum)
      end
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
    nil
  rescue StandardError => ex
    $stderr.puts "ERROR: #{ex} \n  (while processing #{datum})\n  Backtrace:\n  #{ex.backtrace.join("\n  ")}"
  end

  def annotate_declarations
    $enums.each do |usr, enum|
      CTypes.learn_enum(enum['name'])
    end
    
    $classes.each do |usr, klass|
      klass['ruby_name'] = CTypes.type_translator[klass['name']]
    end
    
    $enums.each do |usr, enum|
      enum['ruby_name'] = CTypes.type_translator[enum['name']]
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
    $module_functions.values.concat($classes.values.uniq.flat_map { |c| c['member_functions']}).each do |func|
      func['ruby_name'] = CTypes.fn_translator[func['name']]
      func['out_count'] = 0
      func['header'] = CTypes.get_fn_header(func['name'])
      func['footer'] = CTypes.get_fn_footer(func['name'])
      user_defined_ctype = CTypes.get_fn_return_type(func['name'])
      if user_defined_ctype
        if user_defined_ctype.ignore?
            func['is_void'] = true
        else
          func['out_count'] += 1
        end
      elsif func['return_type']['type_name'] == 'void'
        func['is_void'] = true
      else
        func['out_count'] += 1
      end
      func['ctype'] = user_defined_ctype
      func['ctype'] ||= CTypes.learn_data_type(func['return_type'])
      func['incomplete'] = true if func['ctype'].unknown?
      
      func['in_params'] = []
      func['out_params'] = []
      adjusted_params = []
      func['params'].each_with_index do |param, i|
        if param['name'] == ''
          param['name'] = "arg#{i + 1}"
        elsif param['name'] == 'self'
          # Collides with 'self' param in the c bindings
          param['name'] = 'c_self'
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
    puts "Writing file: #{name}" if conf[:verbose]
    File.open(name, 'w', &block)
  end

  def generate_bindings
    # Setting up locals for the templates
    gem_name = conf[:gem_name]
    module_name = conf[:module_name]
    module_functions = $module_functions.values.sort_by { |f| f['name'].downcase }
    enums = $enums.values.sort_by { |e| e['name'].downcase }
    classes = $classes.values.uniq.sort_by { |c| c['ruby_name'].downcase }
    macros = $macros.sort_by { |m| m['name'].downcase }

    boxing_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/boxing_template.erb"), nil, "-")
    class_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/class_template.erb"), nil, "-")
    module_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/module_template.erb"), nil, "-")
    enums_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/enums_template.erb"), nil, "-")
    header_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/header_template.erb"), nil, "-")
    boxing_header_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/boxing_header_template.erb"), nil, "-")
    macros_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/macros_template.erb"), nil, "-")
    mrbgem_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/mrbgem.rake.erb"), nil, "-")

    unless conf[:skip].include?('src')
      if $classes.any?
        to_gen = $classes.values.uniq.reject { |c| c['is_template'] }
        to_gen.each do |the_class|
          write_file("#{conf[:output_dir]}/src/mruby_#{MRubyBindings.type_name_to_id(the_class['name'])}.#{conf[:ext]}") do |file|
            the_class.instance_eval do
              file.puts(class_erb.result binding)
            end
          end
        end
      
        write_file "#{conf[:output_dir]}/src/mruby_#{module_name}_boxing.#{conf[:ext]}" do |file|
          file.puts(boxing_erb.result binding)
        end
      end
    end
    
    unless conf[:skip].include?('mrblib')
      write_file("#{conf[:output_dir]}/src/mruby_#{module_name}_enum_constants.#{conf[:ext]}") do |file|
        file.puts(enums_erb.result binding)
      end
    end
    
    unless conf[:skip].include?('src')
      write_file("#{conf[:output_dir]}/src/mruby_#{module_name}.#{conf[:ext]}") do |file|
        file.puts(module_erb.result binding)
      end
    end
    
    unless conf[:skip].include?('include')
      write_file("#{conf[:output_dir]}/include/mruby_#{module_name}.h") do |file|
        file.puts(header_erb.result binding)
      end
    end
    
    unless conf[:skip].include?('include') || conf[:skip].include?('boxing')
      write_file("#{conf[:output_dir]}/include/mruby_#{module_name}_boxing.h") do |file|
        file.puts(boxing_header_erb.result binding)
      end
    end
    
    unless conf[:skip].include?('macros')
      write_file("#{conf[:output_dir]}/src/mruby_#{module_name}_macro_constants.#{conf[:ext]}") do |file|
        file.puts(macros_erb.result binding)
      end
    end
    
    unless conf[:skip].include?('mrbgem.rake')
      write_file("#{conf[:output_dir]}/mrbgem.rake") do |file|
        file.puts(mrbgem_erb.result binding)
      end
    end
    
    unless conf[:skip].include?('include')
      generate_functions_header
      generate_classes_header
    end
  end

  def generate_functions_header
    FunctionsHeaderGenerator.new(conf).run
  end

  def generate_classes_header
    ClassesHeaderGenerator.new(conf).run
  end

  def print_diagnostics
    if conf[:verbose]
      File.open('mruby-bindings.out/class_definitions.txt', 'w') do |file|
        PP.pp $classes, file
      end
      File.open('mruby-bindings.out/function_definitions.txt', 'w') do |file|
        PP.pp $module_functions, file
      end
      File.open('mruby-bindings.out/enum_definitions.txt', 'w') do |file|
        PP.pp $enums, file
      end
    end
    File.open('mruby-bindings.out/fn_types.rb', 'w') do |file|
      $module_functions.values.sort_by { |f| f['name'].downcase }.each do |f|
        if f['incomplete']
          file.puts "# ## #{f['return_type']['type_name']} #{f['name']}(#{f['params'].map { |p| "#{p['type']['type_name']} #{p['name']}" }.join(', ')})"
          if f['ctype'].unknown?
            file.puts "# # Return value (#{f['return_type']['type_name']})"
            file.puts "# CTypes.set_fn_return_type('#{f['name']}', CTypes['???'])"
          end
          f['params'].each do |p|
            if p['ctype'].unknown?
              file.puts "# # Param: #{p['name']} (#{p['type']['type_name']})"
              file.puts "# CTypes.set_fn_param_type('#{f['name']}', '#{p['name']}', CTypes['???'])"
            end
          end
          file.puts
        end
      end
    end
    File.open('mruby-bindings.out/macro_types.rb', 'w') do |file|
      $macros.each do |m|
        next unless m['has_expansion'] && CTypes.get_macro_type(m['name']).nil?
        file.puts "# CTypes.set_macro_type('#{m['name']}', CTypes['???'])"
      end
    end
    File.open('mruby-bindings.out/ctypes.rb', 'w') do |file|
      file.puts <<-EOS
# CTypes.define('Example') do
#   self.needs_unboxing = true
#   self.needs_boxing_cleanup = false
#   self.needs_unboxing_cleanup = false
#   self.needs_type_check = true
#   
#   self.recv_template = 'mrb_value %{value};'
#   self.format_specifier = 'o'
#   self.get_args_template = '&%{value}'
#   self.type_check_template = nil
#   self.invocation_arg_template = '%{value}'
#   self.field_swap_template = %{old} = %{new};
#   
#   self.unboxing_fn.invocation_template = '%{as} = TODO_mruby_unbox_Example(%{unbox});'
#   self.unboxing_fn.cleanup_template = 'free(%{value});'
#   
#   self.boxing_fn.invocation_template = '%{as} = TODO_mruby_box_Example(%{box});'
#   self.boxing_fn.cleanup_template = 'free(%{value});'
# end

## This block is called to determine the Ruby class name to use for a C type.
# CTypes.translate_type_names do |name|
#   MRubyBindings.type_name_to_rb_class(name)
# end

## This block is called to determine the Ruby method name to use for a C function.
# CTypes.translate_fn_names do |name|
#   name
# end

## This block is called to determine the Ruby constant name to use for a C enum value.
# CTypes.translate_enum_names do |name|
#   name
# end
EOS
    end
  end
end
end
