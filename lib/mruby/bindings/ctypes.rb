require 'mruby/bindings'
require 'yaml'

module MRuby::Bindings
  module CTypes
    @types = {}
    @destructors = Hash.new { |h, k| h[k] = 'free' }
    @skip_functions = {}

    class << self
      def define(*type_names, &block)
        type_names = type_names.flatten
        last_definition = nil
        type_names.each do |type_name|
          definition = Definition.new(type_name, &block)
          @types[type_name] = definition
          last_definition = definition
        end
        last_definition
      end

      def [](name)
        @types[name]
      end

      def []=(name, val)
        @types[name] = val
      end

      def each(*args, &block)
        @types.send(:each, *args, &block)
      end

      def make_alias(underlying_type, new_type)
        self[new_type] = self[underlying_type].aliased_as(new_type)
      end

      def list_types
        @types.keys
      end

      def read_function_blueprint(row)
        case row['plan']
        when 'BUILTIN_CTYPE'
          CTypes[row['canonical_type']] # Just return the existing ctype
        when 'PTR_TO_KNOWN_VALUE_TYPE'
          CTypes.learn_pointer_to_value_type(row['type'], row['canonical_pointee_type'])
        when 'PTR_TO_UNKNOWN_VALUE_TYPE'
          CTypes.learn_pointer_to_unkown_value(row['type'], row['canonical_pointee_type'])
        when 'KNOWN_VALUE_TYPE'
          CTypes.learn_value_type(row['type'], row['canonical_type'])
        when 'UNKNOWN_VALUE_TYPE'
          CTypes.declare_type_ignorance(row['type'], row['canonical_type'])
        when 'ENUM'
          CTypes.learn_enum(row['type'])
        when 'FUNCTION_PTR'
          CTypes[row['type']] = CTypes.declare_type_ignorance(row['type'], row['canonical_type'])
        when 'VOID_PTR'
          CTypes.declare_type_ignorance(row['type'], row['canonical_type'])
        when 'NO_PLAN'
          CTypes.declare_type_ignorance(row['type'], row['canonical_type'])
        else
          raise "No handler for plan: #{row['plan']}"
        end
        self
      end

      def load_yaml_config(filename)
        @types = {} # Reset types
        YAML.load_stream(File.open(filename, 'r')).each do |ctype|
          @types[ctype.key] = ctype
        end
        self
      end

      # Argument expected to be canonical
      def learn_enum(name)
        @types[name] = @types['int'].aliased_as(name)
      end

      # Argument expected to be canonical
      def learn_pointer_to_value_type(pointer_type, canonical_value_type)
        # We don't know the type, but we know the pointee type from a struct/class decl
        # Only need to learn a new type once
        memoized = CTypes[pointer_type]
        return memoized if memoized

        type_as_id = MRuby::Bindings::Names.type_name_to_id(canonical_value_type)
        ruby_type_name = MRuby::Bindings::Hooks.translate_type_name_to_ruby(canonical_value_type)

        new_ctype = CTypes.define(pointer_type) do
          boxing_fn.name = MRuby::Bindings::Hooks.boxing_fn_name(canonical_value_type)
          boxing_fn.invocation_template = "mrb_value %{as} = (%{box} == NULL ? mrb_nil_value() : #{boxing_fn.name}(mrb, %{box}));"
          unboxing_fn.name = MRuby::Bindings::Hooks.unboxing_fn_name(canonical_value_type)
          unboxing_fn.invocation_template = "#{pointer_type} %{as} = (mrb_nil_p(%{unbox}) ? NULL : #{unboxing_fn.name}(%{unbox}));"

          self.type_check_template = <<EOF
if (!mruby_#{ MRuby::Bindings::Hooks.module_name }_typecheck_#{ ruby_type_name }(mrb, %{value})) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{ruby_type_name} expected");
  return mrb_nil_value();
}
EOF
        end
        new_ctype
      end

      # Argument expected to be canonical
      def learn_value_type(value_type, canonical_value_type)
        # We know the exact type from a struct/class decl
        # Only need to learn a new type once
        memoized = CTypes[value_type]
        return memoized if memoized

        type_as_id = MRuby::Bindings::Names.type_name_to_id(canonical_value_type)
        ruby_type_name = MRuby::Bindings::Hooks.translate_type_name_to_ruby(canonical_value_type)

        new_ctype = CTypes.define(value_type) do
          boxing_fn.name = MRuby::Bindings::Hooks.boxing_fn_name(canonical_value_type)
          boxing_fn.invocation_template = <<EOF
#{value_type}* new_%{as} = TODO_move_#{type_as_id}_to_heap(%{box});
mrb_value %{as} = #{boxing_fn.name}(mrb, &%{box});
EOF
          unboxing_fn.name = MRuby::Bindings::Hooks.unboxing_fn_name(canonical_value_type)
          unboxing_fn.invocation_template = "#{value_type} %{as} = *(#{unboxing_fn.name}(%{unbox}));"

          self.type_check_template = <<EOF
if (!mruby_#{ MRuby::Bindings::Hooks.module_name }_typecheck_#{ ruby_type_name }(mrb, %{value})) {
if (!mrb_obj_is_kind_of(mrb, %{value}, #{MRuby::Bindings::Hooks.module_name}_#{ruby_type_name}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{ruby_type_name} expected");
  return mrb_nil_value();
}
EOF
        end
        new_ctype
      end

      def learn_pointer_to_unkown_value(pointer_type, canonical_value_type)
        memoized = CTypes[pointer_type]
        return memoized if memoized

        type_as_id = MRuby::Bindings::Names.type_name_to_id(canonical_value_type)
        ruby_type_name = MRuby::Bindings::Hooks.translate_type_name_to_ruby(canonical_value_type)

        new_ctype = CTypes.define(pointer_type) do
          boxing_fn.invocation_template = "mrb_value %{as} = (%{box} == NULL ? mrb_nil_value() : mruby_#{MRuby::Bindings::Hooks.module_name}_box_void_pointer(mrb, %{box}));"
          unboxing_fn.invocation_template = "void * %{as} = (mrb_nil_p(%{unbox}) ? NULL : mruby_#{MRuby::Bindings::Hooks.module_name}_unbox_void_pointer(%{unbox}));"

          self.type_check_template = <<EOF
if (!mruby_#{MRuby::Bindings::Hooks.module_name}_typecheck_void_pointer(mrb, %{value}, "#{pointer_type}")) {
  return mrb_nil_value();
}
EOF
        end
        new_ctype
      end

      def declare_type_ignorance(type, canonical_type)
        # We don't know the type at all, insert TODO's
        # Only need to learn a new type once
        if CTypes[type]
          return CTypes[type]
        end

        type_as_id = MRuby::Bindings::Names.type_name_to_id(canonical_type)

        new_ctype = CTypes.define(type) do
          self.unknown = true
          boxing_fn.name = "TODO_mruby_box_#{type_as_id}"
          boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"
          unboxing_fn.name = "TODO_mruby_unbox_#{type_as_id}"

          # Insert the identifier into the correct place for function pointers
          if type.include? '(*)'
            unboxing_fn.invocation_template = "#{type.sub('(*)', '(*%{as})')} = #{unboxing_fn.name}(%{unbox});"
          else
            unboxing_fn.invocation_template = "#{type} %{as} = #{unboxing_fn.name}(%{unbox});"
          end

          self.type_check_template = <<EOF
TODO_type_check_#{type_as_id}(%{value});
EOF
        end
        new_ctype
      end
    end
  end
end
