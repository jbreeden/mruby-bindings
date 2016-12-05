module MRuby
  module Bindings
  end
end
require "mruby/bindings/version"
require "mruby/bindings/names"
require "mruby/bindings/type_checks"
require "mruby/bindings/typedef_resolver"
require "mruby/bindings/ctypes"
require "mruby/bindings/ctypes_definition"
require "mruby/bindings/builtin_ctypes"
require "mruby/bindings/hooks"
require "mruby/bindings/indexes"
require "mruby/bindings/rendered_text"

module MRuby
  module Bindings
    module Paths
      GEM_ROOT = File.absolute_path(File.dirname(__FILE__) + "/../../")

      TEMPLATE_DIR = "#{GEM_ROOT}/templates"
      PLUMBING_DIR = "#{GEM_ROOT}/plumbing"
      LIB_DIR = "#{GEM_ROOT}/lib"
      EXE_DIR = "#{GEM_ROOT}/exe"

      OUTPUT_DIR = File.absolute_path("./mruby-bindings.out")

      INGEST_DIR = File.absolute_path("#{OUTPUT_DIR}/ingested-declarations")
      DISCOVERY_DIR = File.absolute_path("#{OUTPUT_DIR}/discovery")
      BLUEPRINT_DIR = File.absolute_path("#{OUTPUT_DIR}/blueprint")
      RENDER_DIR = File.absolute_path("#{OUTPUT_DIR}/render")

      RESULT_DIR = File.absolute_path("#{OUTPUT_DIR}/#{Hooks.gem_name}")
      SRC_RESULT_DIR = File.absolute_path("#{RESULT_DIR}/src")
      INCLUDE_RESULT_DIR = File.absolute_path("#{RESULT_DIR}/include")
      GENERATE_RESULT_DIR = File.absolute_path("#{RESULT_DIR}/include")
    end
  end
end
