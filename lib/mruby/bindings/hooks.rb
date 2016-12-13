module MRuby
  module Bindings
    module Hooks
      module Defaults
        def declaration_files
          ['declarations.json']
        end

        def module_name
          raise "No module name defined! Please override MRuby::Bindings::Hooks::module_name in mruby-bindings.in/hooks.rb"
        end
        
        def gem_name
          raise "No gem name defined! Please override MRuby::Bindings::Hooks::gem_name in mruby-bindings.in/hooks.rb"
        end

        def translate_type_name_to_ruby(name)
          name.sub(/^struct\s*/, '').
            sub(/_(s|t)$/i, '').
            each_char.reduce('') { |acc, cur|
              if acc[acc.length - 1] == '_' || acc == ''
                cur = cur.upcase
              end
              acc + cur
            }.gsub('_', '')
        end

        def translate_field_name_to_ruby(name)
          name
        end

        def translate_enum_constant_to_ruby(name)
          name
        end

        def translate_function_name_to_ruby(name)
          name
        end

        def boxing_fn_name(c_type_name)
            type_as_id = MRuby::Bindings::Names.type_name_to_id(c_type_name)
            "mruby_#{MRuby::Bindings::Hooks.module_name}_box_#{type_as_id}"
        end

        def giftwrap_fn_name(c_type_name)
            type_as_id = MRuby::Bindings::Names.type_name_to_id(c_type_name)
            "mruby_#{MRuby::Bindings::Hooks.module_name}_giftwrap_#{type_as_id}"
        end

        def unboxing_fn_name(c_type_name)
            type_as_id = MRuby::Bindings::Names.type_name_to_id(c_type_name)
            "mruby_#{MRuby::Bindings::Hooks.module_name}_unbox_#{type_as_id}"
        end

        def define_builtin_ctypes
            # No default action
        end

        # So we can easily call these methods on the Defaults module,
        # even if they're overrided in the Hooks module.
        extend self
      end

      extend Defaults
    end
  end
end

# Load the user's hooks
require "./mruby-bindings.in/hooks" if File.exists?('./mruby-bindings.in/hooks.rb')
