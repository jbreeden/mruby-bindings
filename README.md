# mruby-bindings
Generates MRuby bindings from C Header files via libclang

# Requirements
[clang2json](https://github.com/jbreeden/clang2json)

# Usage

Just pipe the output of `clang2json` to the `mruby_bindings.rb` script and supply a few parameters.

```
clang2json [CLANG_OPTIONS...] | ruby mruby_bindings.rb -g GEM_NAME -m MODULE_NAME -o OUTPUT_DIR [-f]

  -g, -gem
    The name to use for this mrbgems. Should be mruby-something
    per the mrbgems recommendation. This will be used to generate
    the appropriate mrb_YOUR_GEM_NAME_gem_init functions, for example.

  -m, --module
    The name to use for the generated module. This is the module under which
    all macros, functions, classes, etc. generated from the C headers will
    be defined in Ruby land.

  -o, --output
    The output directory. This is where the generated source code will be saved.

  -f
    If the output directory exists, mruby-bindings will refuse to overwrite it
    by default. Use -f to force the overwrite.
```

# Details

It should be close to complete & stable. Still need to work through function pointers. Structs, enums, functions, typedefs,
classes, methods, and macros are currently supported. Generated bindings include type checking and a convenient macro system to configure the bindings.

Have a peek at the [APR bindings](https://github.com/jbreeden/mruby-bindings/tree/master/apr_bindings) for an example of the raw output. The [APR gem](https://github.com/jbreeden/mruby-apr) is the result of taking the raw generated code, enabling bindings and performing the necessary tweaks (like changing "output parameters" - passed in as pointers - to return values, since there is not way for the generator to know the intentions of the library's API in that regard). Many of the function bindings in the APR gem required no tweaking, and simple work as generated.
