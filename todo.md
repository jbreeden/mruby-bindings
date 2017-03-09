# TODO

KEEP THIS MINIMAL
Introduce as few new concepts as possible (rely on mruby builtin features).

- Normalize all outputs to differentiate between overwritten & protected files.
- Ensure all ruby constructs over easily overridden, or sniff for user defined
  alternatives before initializing the generated defaults.
- Avoid macros for extension specializations. Prefer mechanism accessible to ruby.
- mruby_MODULE_classes.c should probably be reduced with macros.
- Long-term, consider breaking tight coupling to "mruby" vm (may generate FFI bindings, CRuby bindings, etc)

- [ ] Overrides
  + "Global" overrides? Hooks that are always called by the specific override for that type?
  + [ ] Module Methods
    * [ ] Argument types / count
    * [ ] Return type
    * Just prepend another one?
  + [ ] Classes
    * [ ] Super Type
    * [ ] Free Function
    * [ ] Type Check (maybe this type shouldn't be VoidPointer+able?)

- Having each step produce intermediate results enables plugins
  to perform extra work - perhaps one-off for a single gem - without
  requiring code changes to (or even hooks within) the core system.

