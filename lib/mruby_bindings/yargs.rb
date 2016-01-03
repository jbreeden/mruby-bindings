# Dead simple argument parser for ruby.
# So simple, it is the README.
#
# Description:
#
# - Does NOT bark about unexpected arguments. That's your problem.
# - Always checks for the first value of the flag/value from left to right.
# - If consuming, can check for the same flag/value multiple times.
# - Flags & values may be prefixed with '-' or '--', no matter the name
# - Values can be separated from their field name by whitespace OR an '=' sign, but not both
#
# Usage:
#
# ```Ruby
# # Pass :consume if & only if you want to remove arguments as you find them
# yargs = Yargs.new(ARGV, :consume)
#
# # Check a flag [ie: an arg prefixed with '-' or '--']
# flag_given = yargs.flag(:f, :fetch)
# do_something if flag_given
#
# # Get a value [ie: an arg prefixed with '-' or '--' followed by (spaces OR an '=') and the value ]
# start_interval = yargs.value(:i, :interval)
# do_something unless start_interval.nil?
#
# # Since we're consuming, we could check for interval again
# # (In RL, I'd give them different names, but you get the idea)
# end_interval = yargs.value(:i, :interval)
# do_something unless end_interval.nil?
# ```

class Yargs
  def initialize(argv, mode = nil)
    @argv = argv
    @consume = (mode == :consume)
  end

  def flag(*names)
    name_regex = "(#{names.join('|')})"
    index = @argv.find_index { |e| e =~ /^(-){1,2}#{name_regex}$/ }
    if index != nil
      @argv.delete_at(index) if @consume
      return true
    end
    return false
  end

  def value(*names)
    name_regex = "(#{names.join('|')})"
    index = @argv.find_index { |e| e =~ /^(-){1,2}#{name_regex}(=.*)?$/ }
    if index != nil
      equals_index = @argv[index].index('=')
      if equals_index
        val = @argv[index][(equals_index + 1)..(@argv[index].length)]
        @argv.delete_at(index) if @consume
        return val
      else
        if (index + 1) < @argv.length && !(@argv[index + 1] =~ /^-{1,2}/)
          val =  @argv[index + 1]
          @argv.delete_at(index + 1) if @consume
          @argv.delete_at(index) if @consume
          return val
        end
      end
    end
    return nil
  end
end
