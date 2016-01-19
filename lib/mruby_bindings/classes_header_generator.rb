module MRubyBindings
class ClassesHeaderGenerator
  attr_accessor :conf
  
  def initialize(conf)
    @conf = conf
  end
  
  def run
    File.open("#{conf[:output_dir]}/include/mruby_#{conf[:module_name]}_classes.h", 'w') do |out|
      out.puts "#ifndef MRUBY_#{conf[:module_name]}_CLASSES_HEADER"
      out.puts "#define MRUBY_#{conf[:module_name]}_CLASSES_HEADER"
      out.puts
      Dir["#{conf[:output_dir]}/src/*"].each do |f|
        if (f == '.' ||
            f == '..' ||
            f.start_with?("#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}.") ||
            f.start_with?("#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}_boxing.") ||
            f.start_with?("#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}_macro_constants."))
          next
        end
        File.open(f, 'r') do |f|
          this_fn_name = ''
          todo = false
          f.each_line do |line|
            if type = line[/#if BIND_(.*)_TYPE$/, 1]
              out.puts "#define BIND_#{type}_TYPE TRUE"
              next
            end
            
            if line[/^#if BIND.*(INITIALIZE|FIELD_READER|FIELD_WRITER|FUNCTION)/, 1]
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

            if line =~ /void.*mrb.*init\(/
              break
            end
          end
        end
      end
      out.puts "#endif"
    end
  end
end
end
