module MRubyBindings
class FunctionsHeaderGenerator
  attr_accessor :conf
  
  def initialize(conf)
    @conf = conf
  end
  
  def run
    File.open("#{conf[:output_dir]}/include/mruby_#{conf[:module_name]}_functions.h", 'w') do |out|
      out.puts "#ifndef MRUBY_#{conf[:module_name]}_FUNCTIONS_HEADER"
      out.puts "#define MRUBY_#{conf[:module_name]}_FUNCTIONS_HEADER"
      out.puts
      File.open(Dir["#{conf[:output_dir]}/src/mruby_#{conf[:module_name]}.*"][0], 'r') do |f|
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

          if line =~ /gem_init/
            break
          end
        end
      end
      out.puts "#endif"
    end
  end
end
end
