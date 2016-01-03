Gem::Specification.new do |spec|
  spec.author = "Jared Breeden"
  spec.name = "mruby-bindings"
  spec.version = "1.0.0"
  spec.summary = "Generates MRuby bindings to C libraries"
  spec.license = "TODO"
  spec.executables << 'mrbind'
  spec.files = Dir['./{bin,lib,templates}/**/*.{rb,erb}']
end
