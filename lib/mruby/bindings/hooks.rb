module MRuby
  module Bindings
    module Hooks
      module Defaults
        def self.module_name
          raise "No module name defined!"
        end
        
        def self.gem_name
          raise "No gem name defined!"
        end

        def self.translate_type_name_to_ruby(name)
          name.sub(/^struct\s*/, '').
            sub(/_(s|t)$/i, '').
            each_char.reduce('') { |acc, cur|
              if acc[acc.length - 1] == '_' || acc == ''
                cur = cur.upcase
              end
              acc + cur
            }.gsub('_', '')
        end

        def self.translate_field_name_to_ruby(name)
          name
        end

        def self.translate_enum_constant_to_ruby(name)
          name
        end

        def self.translate_function_name_to_ruby(name)
          name
        end

        def self.boxing_fn_name(c_type_name)
            type_as_id = MRuby::Bindings::Names.type_name_to_id(c_type_name)
            "mruby_#{MRuby::Bindings::Hooks.module_name}_box_#{type_as_id}"
        end

        def self.giftwrap_fn_name(c_type_name)
            type_as_id = MRuby::Bindings::Names.type_name_to_id(c_type_name)
            "mruby_#{MRuby::Bindings::Hooks.module_name}_giftwrap_#{type_as_id}"
        end

        def self.unboxing_fn_name(c_type_name)
            type_as_id = MRuby::Bindings::Names.type_name_to_id(c_type_name)
            "mruby_#{MRuby::Bindings::Hooks.module_name}_unbox_#{type_as_id}"
        end

        def self.define_builtin_ctypes
            # No default action
        end
      end

      def self.method_missing(name, *args, &block)
        if Defaults.respond_to?(name)
          Defaults.send(name, *args, &block)
        else
          super
        end
      end
    end
  end
end

# Load the user's hooks
require "./mruby-bindings.in/hooks" if File.exists?('./mruby-bindings.in/hooks.rb')
