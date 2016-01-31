require_relative 'lib/mruby_bindings/version.rb'

Gem::Specification.new do |spec|
  spec.author = "Jared Breeden"
  spec.name = "mruby-bindings"
  spec.email = "jared.breeden@gmail.com"
  spec.homepage = "https://github.com/jbreeden/mruby-bindings"
  spec.description = "Cooperative bindings generator for MRuby"
  spec.version = MRubyBindings::VERSION
  spec.summary = "Generates MRuby bindings to C libraries"
  spec.license = "TODO"
  spec.executables << 'mrbind'
  spec.files = Dir['./{bin,lib,templates}/**/*.{rb,erb}']
end
