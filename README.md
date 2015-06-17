# mruby-bindings
Generates MRuby bindings from C Header files via libclang

# Requirements
[clang2json](https://github.com/jbreeden/clang2json)

# Usage
TODO: I'll fill this out after I've done more testing and solidified the output format.
Currently using it to generate bindings for dependencies of the [lamina](https://github.com/jbreeden/lamina) project.
This include Apache's APR, nanomsg, and maybe some CEF stuff. The new bindings will replace the limited hand-written
bindings that are currently used.

Have a peek at the [apr bindings](https://github.com/jbreeden/mruby-bindings/tree/master/apr_bindings) if you're curious what the output looks like. It should be close to complete & stable. Still need to work through macro constants and function pointers. Structs, enums, functions, typedefs, classes, and methods are currently supported. Generated bindings include type checking and a convenient macro system to configure the bindings.
