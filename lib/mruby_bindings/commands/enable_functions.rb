module MRubyBindings
module Commands
module EnableFunctions
  USAGE = <<EOS
Usage: mrbind enable-functions -g GEM_NAME -m MODULE_NAME [-o OUTPUT_DIR]

Generate the mruby_GEMNAME_functions.h header file, which enables all
functions binings without a TODO in the implementation.
EOS

  def self.run
    yargs = Yargs.new(ARGV, :consume)
    conf = {}

    conf[:gem_name] = yargs.value(:g, :gem, 'gem-name')
    conf[:module_name] = yargs.value(:m, :module, 'module-name')

    unless conf[:gem_name]
      bail("Must specify the gem name: `-g YOUR_GEM_NAME`", USAGE)
    end

    unless conf[:module_name]
      bail("Must specify the module name: `-m YOUR_MODULE_NAME`", USAGE)
    end
    
    conf[:output_dir] = yargs.value(
      :o, :output, :dir, :directory, 'output-dir', 'output-directory'
    ) || 'bindings'
    
    MRubyBindings::FunctionsHeaderGenerator.new(conf).run
    MRubyBindings::ClassesHeaderGenerator.new(conf).run
  end

end
end
end
