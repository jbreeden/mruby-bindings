# mruby-bindings
Generates MRuby bindings from C Header files via libclang

# Requirements
[clang2json](https://github.com/jbreeden/clang2json)

# Usage
TODO: I'll fill this out after I've done more testing and solidified the output format.
Currently using it to generate bindings for dependencies of the [lamina](https://github.com/jbreeden/lamina) project.
This include Apache's APR, nanomsg, and maybe some CEF stuff. The new bindings will replace the limited hand-written
bindings that are currently used.
