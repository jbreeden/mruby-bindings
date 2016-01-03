module MRubyBindings
module Commands
module Generate
  USAGE = <<EOS
Usage: mrbind generate -g GEM_NAME -m MODULE_NAME -o OUTPUT_DIR [OTHER_OPTIONS...]

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
    
    Example 1:
      clang2json [CLANG_OPTIONS] header_file.h | mrbind -m MyModule -g mruby-gem-name
      
    Example 2:
      clang2json [CLANG_OPTIONS] header_file.h > declarations.json
      mrbind -m MyModule -g mruby-gem-name -input declarations.json
    
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

  def self.run
    yargs = Yargs.new(ARGV, :consume)
    conf = {}

    conf[:gem_name] = yargs.value(:g, :gem, 'gem-name')
    conf[:module_name] = yargs.value(:m, :module, 'module-name')
    conf[:ext] = yargs.value(:e, :extension) || 'c'
    conf[:input] = yargs.value(:i, :input)
    conf[:input] = conf[:input].nil? ? $stdin : File.open(conf[:input], 'r')
    conf[:includes] = yargs.value(:includes)
    conf[:output_dir] = yargs.value(
      :o, :output, :dir, :directory, 'output-dir', 'output-directory'
    ) || 'bindings'
    conf[:force] = yargs.flag(:f, :force)
    conf[:verbose] = yargs.flag(:v, :verbose)

    conf[:skip] = []
    while (skip = yargs.value(:skip))
      conf[:skip].push(skip)
    end

    while (file = yargs.value(:l, :load))
      load file
    end

    unless conf[:gem_name]
      bail("Must specify the gem name: `-g YOUR_GEM_NAME`", USAGE)
    end

    unless conf[:module_name]
      bail("Must specify the module name: `-m YOUR_MODULE_NAME`", USAGE)
    end

    if !conf[:force] && Dir.exists?(conf[:output_dir])
      $stderr.puts "Output directory (#{conf[:output_dir]}) exists. Use -f to force overwrite."
      exit 1
    end

    MRubyBindings::Generator.new(conf).run
  end
end
end
end
