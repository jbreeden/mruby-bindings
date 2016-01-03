require 'fileutils'

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
    prev_datum = nil
    prev_type = nil
    while line = conf[:input].gets
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
      klass['ruby_name'] = MRubyBindings.type_name_to_rb_class(klass['name'])
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
    classes = $classes.values.sort_by { |c| c['ruby_name'].downcase }
    macros = $macros.sort_by { |m| m['name'].downcase }

    boxing_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/boxing_template.erb"), nil, "-")
    class_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/class_template.erb"), nil, "-")
    module_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/module_template.erb"), nil, "-")
    enums_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/enums_template.erb"), nil, "-")
    header_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/header_template.erb"), nil, "-")
    boxing_header_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/boxing_header_template.erb"), nil, "-")
    classes_header_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/classes_header_template.erb"), nil, "-")
    macros_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/macros_template.erb"), nil, "-")
    mrbgem_erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/mrbgem.rake.erb"), nil, "-")

    unless conf[:skip].include?('src')
      if $classes.any?
        to_gen = $classes.values.reject { |c| c['is_template'] }
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
      if $enums.any?
        write_file("#{conf[:output_dir]}/mrblib/#{module_name}.rb") do |file|
          file.puts(enums_erb.result binding)
        end
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
    write_file("#{conf[:output_dir]}/include/mruby_#{conf[:module_name]}_classes.h") do |out|
      out.puts "#ifndef MRUBY_#{conf[:module_name]}_CLASSES_HEADER"
      out.puts "#define MRUBY_#{conf[:module_name]}_CLASSES_HEADER"
      out.puts
      Dir["#{conf[:output_dir]}/src/*"].each do |f|
        if (f == '.' ||
            f == '..' ||
            f == "#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}.#{conf[:ext]}" ||
            f == "#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}_boxing.#{conf[:ext]}" ||
            f == "#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}_macro_constants.#{conf[:ext]}")
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
                if conf[:verbose]
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
  end
end
end
