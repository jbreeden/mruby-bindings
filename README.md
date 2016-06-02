# mruby-bindings
Generates MRuby bindings from C Header files via libclang

*TODO: mruby-bindings has been refactored into a Ruby Gem. The interface has changed, and the general workflow has been updated a lot. Need to update this readme.*

See the repos listed below for some examples. The `rakelib/mruby-bindings.rake` file in each repo shows the basic commands for working with mruby-bindings. That file is generated automatically - the template is in the `templates/` folder of this repo - then customized for the specific project as needed. The `mruby-bindings.in` folder in each repo shows some of the configuartion options that are available for influencing the generated code. `mruby-bindings` will generate a `mruby-bindings.out` folder with stubs for any information it couldn't figure out. You would simply copy these files into `mruby-bindings.in`, uncomment any sections you wish to customize, and fill in any missing information. In this way, you can coach `mruby-bindings` into creating near perfect bindings.

In addition to configuration, you can also edit the generated code by hand. `mruby-bindings` will tag code sections with a sha, which is used to determine if the code has been hand edited. If an edit is detected, `mruby-bindings` will not clobber your code changes on the next run. Additionally, adding a comment at the beginning of any file with the token `MRUBY_BINDINGS_NO_CLOBBER` will prevent any modifications to that file.

**Examples**

 - [mruby-apr](https://github.com/jbreeden/mruby-apr)
 - [mruby-sqlite](https://github.com/jbreeden/mruby-sqlite)
 - [mruby-sdl2](https://github.com/jbreeden/mruby-sdl2)
 - [mruby-wiring-pi](https://github.com/jbreeden/mruby-wiring-pi)
 - [mruby-curses](https://github.com/jbreeden/mruby-curses)
 - [mruby-zlib](https://github.com/jbreeden/mruby-zlib)

# Requirements
[clang2json](https://github.com/jbreeden/clang2json)

# Usage

*TODO: This is slightly outdated. There is now an executable called mrbind that generates a rake file for running the required commands in your project. After that point, all interaction with mruby-bindings is done through the rake tasks.*

Just pipe the output of `clang2json` to the `mruby_bindings.rb` script and supply a few parameters.

```
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
```
