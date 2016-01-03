require 'fileutils'
require 'json'
require 'erb'
require 'pp'
require 'tmpdir'
require 'mruby_bindings/commands/generate'
require 'mruby_bindings/commands/merge'
require 'mruby_bindings/commands/init'
require 'mruby_bindings/commands/enable_functions'
require 'mruby_bindings/bindings_file'
require 'mruby_bindings/ctypes'
require 'mruby_bindings/builtin_ctypes'
require 'mruby_bindings/generator'
require 'mruby_bindings/names'
require 'mruby_bindings/merge'
require 'mruby_bindings/functions_header_generator'
require 'mruby_bindings/yargs'

module MRubyBindings
  BINDING_SHA_PATTERN = /\/\* sha: (\S+) \*\//
  START_BINDING_PATTERN = /\/\* MRUBY_BINDING: (\S+) \*\//
  END_BINDING_PATTERN = /\/\* MRUBY_BINDING_END \*\//
  TEMPLATE_DIR = File.expand_path("#{File.dirname(__FILE__)}/../templates")
end
