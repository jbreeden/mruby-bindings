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
require 'mruby_bindings/ctypes_definition'
require 'mruby_bindings/builtin_ctypes'
require 'mruby_bindings/generator'
require 'mruby_bindings/names'
require 'mruby_bindings/merge'
require 'mruby_bindings/functions_header_generator'
require 'mruby_bindings/classes_header_generator'
require 'mruby_bindings/yargs'

module MRubyBindings
  BINDING_SHA_PATTERN = /\/\* sha: (\S+) \*\//
  START_BINDING_PATTERN = /\/\* MRUBY_BINDING: (\S+) \*\//
  END_BINDING_PATTERN = /\/\* MRUBY_BINDING_END \*\//
  TEMPLATE_DIR = File.expand_path("#{File.dirname(__FILE__)}/../templates")
  
  def self.read_declarations(path, &block)
    require 'json'
    lib = Hash.new { |h, k| h[k] = [] }
    File.read(path).each_line do |l|
      decl = JSON.parse(l)
      lib[decl['kind'] + 's'].push(decl)
    end
    block[lib]
  end
  
  def self.view_declarations(decls)
    decls.each do |decl|
      File.open(decl['file'], 'r') do |f|
        f.each_line.each_with_index do |l, i|
          puts l if i >= (decl['line'].to_i - 50)
          break if i >= decl['line'].to_i
        end
      end
      $stdin.gets
      5.times { puts }
    end
  end
  
end
