# mruby-bindings
Generates MRuby bindings from C Header files via libclang

# Requirements
[clang2json](https://github.com/jbreeden/clang2json)

# Usage

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
      | clang2json OPTIONS | mruby_bindings -h ./my_includes.h OTHER_OPTIONS...
      
  --skip=(macros|src|include|mrblib|boxing|mrbgem.rake)
    Skip generation of the indicated portion of the mrbgem.
    
    If you've made manual changes to part of the generated bindings that you don't 
    want to overwrite, this is the option for the job.
    
    This shouldn't be needed often. It was only added to handle the macros case.
    Mruby-bindings has a hard time figuring out what macro expansions actually
    are (strings? integers?). It tries its best, but you're going to have to
    manually tweak them (mostly commenting useless ones out). Afterwards, use
    `--skip macros` and they will no longer be generated.
    
    WARNING: The output directory is cleared before generating bindings. So any
    skipped portions simply won't exist. You should be copying the generated
    bindings to another folder. Then, as required, you can regenerate the bindings,
    and copy the result over your "master" files. In this way, the skipped portions
    will not overwrite your manual changes. This is the basic loop you'll go
    through - as you define additional CTypes other binding configurations - until
    you get bindings that are complete & functional.
    
    RECOMMENDATION: When you first generate bindings, put them under version
    control. Each time you add a CType or change a setting, check the diff
    of the output to see the changes. Only then, once you've acheived the effect
    you want, should you copy the generated code to your master files.
    
    May be specified multiple times.
    
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
```

# Details

It should be close to complete & stable. Still need to work through function pointers. Structs, enums, functions, typedefs,
classes, methods, and macros are currently supported. Generated bindings include type checking and a convenient macro system to configure the bindings.

Have a peek at the [APR bindings](https://github.com/jbreeden/mruby-bindings/tree/master/apr_bindings) for an example of the raw output. The [APR gem](https://github.com/jbreeden/mruby-apr) is the result of taking the raw generated code, enabling bindings and performing the necessary tweaks (like changing "output parameters" - passed in as pointers - to return values, since there is not way for the generator to know the intentions of the library's API in that regard). Many of the function bindings in the APR gem required no tweaking, and simple work as generated.
