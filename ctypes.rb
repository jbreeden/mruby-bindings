module CTypes
  class BoxingFn
    attr_accessor :name,      # The function name
      # An sprintf-style template for rendering the boxing/unboxing code inline
      :invocation_template,
      # Code to run before returning iff an object was uboxed as a parameter to
      # a function/method. Does not apply to objects being unboxed when setting
      # a field, since the field should retain the set value. For an example,
      # see the defintion for "char *" below.
      :param_cleanup_template
  end

  class Definition
    attr_accessor :type_name, :boxing_fn, :unboxing_fn, :type_check

    def initialize(type_name)
      self.type_name = type_name
      self.boxing_fn = BoxingFn.new
      boxing_fn.name = "TODO_mruby_box_#{type_name.type_to_identifier.split(' ').join('_')}"
      self.unboxing_fn = BoxingFn.new
      unboxing_fn.name = "TODO_mruby_unbox_#{type_name.type_to_identifier.split(' ').join('_')}"
    end
  end

  @types = {}
  @typedefs = {}

  class << self
    def define(*type_names, &block)
      type_names.each do |type_name|
        definition = Definition.new(type_name)
        @types[type_name] = definition
        definition.instance_eval &block
      end
    end

    def typedef(underlying_type, new_type)
      @typedefs[new_type] = underlying_type
    end

    def [](type_name)
      # Resolve typedef chain to underlying type
      # TODO: Full resolution may not always be desired.
      #       Might want separate functions or an options
      #       for direct accessvs resolved access.
      loop {
        break unless(@typedefs[type_name] && @types[@typedefs[type_name]])
        type_name = @typedefs[type_name]
      }

      @types[type_name]
    end

    def learn_data_type(type)
      # Only need to learn a new type once
      return if CTypes[type['type_name']]

      CTypes.define(type['type_name']) do
        if type['type_is_pointer'] && $classes[type['pointee_type_usr']]
          boxing_fn.name = "mruby_box_#{type['pointee_type_name']}"
          boxing_fn.invocation_template = "mrb_value %{as} = (%{box} == NULL ? mrb_nil_value() : #{boxing_fn.name}(mrb, %{box}));"
          unboxing_fn.name = "mruby_unbox_#{type['pointee_type_name']}"
          unboxing_fn.invocation_template = "#{type['type_name']} %{as} = (mrb_nil_p(%{unbox}) ? NULL : #{unboxing_fn.name}(%{unbox}));"

          self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, #{$classes[type['pointee_type_usr']]['ruby_name']}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{$classes[type['pointee_type_usr']]['ruby_name']} expected");
  return mrb_nil_value();
}
EOF
        elsif $classes[type['type_usr']]
          boxing_fn.name = "mruby_box_#{type['type_name']}"
          boxing_fn.invocation_template = <<EOF
/* WARNING: Boxing a pointer to a value type.
 * If this is a stack variable, it will be deleted when this function returns.
 * If a longer lifespan is required, it should be put on the heap - consider
 * customizing this function (or add a `CTypes` definition to cover all instances)
 */
mrb_value %{as} = #{boxing_fn.name}(mrb, &%{box});
EOF
          unboxing_fn.name = "mruby_unbox_#{type['type_name']}"
          unboxing_fn.invocation_template = "#{type['type_name']} %{as} = *(#{unboxing_fn.name}(%{unbox}));"

          self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, #{type['ruby_name']}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{type['ruby_name']} expected");
  return mrb_nil_value();
}
EOF
        else
          boxing_fn.name = "TODO_mruby_box_#{type['type_name'].type_to_identifier.split(' ').join('_')}"
          boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"
          unboxing_fn.name = "TODO_mruby_unbox_#{type['type_name'].type_to_identifier.split(' ').join('_')}"
          if type['type_name'].include? '(*)'
            # Inserting the identifier into the correct place for function pointers
            # We won't ever have a "class" declaration for these, so it only happens
            # with these "unkown" types.
            unboxing_fn.invocation_template = "#{type['type_name'].sub('(*)', '(*%{as})')} = #{unboxing_fn.name}(%{unbox});"
          else
            unboxing_fn.invocation_template = "#{type['type_name']} %{as} = #{unboxing_fn.name}(%{unbox});"
          end

          self.type_check = <<EOF
TODO_type_check_#{type['type_name'].type_to_identifier}(%{value});
EOF
        end
      end
    end

  end
end

CTypes.define('int', 'unsigned int') do
  boxing_fn.name = 'mrb_fixnum_value'
  boxing_fn.invocation_template = <<EOF
if (%{box} > MRB_INT_MAX) {
  mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
  return mrb_nil_value();
}
mrb_value %{as} = #{boxing_fn.name}(%{box});
EOF

  unboxing_fn.name = 'mrb_fixnum'
  unboxing_fn.invocation_template = "#{type_name} %{as} = #{unboxing_fn.name}(%{unbox});"

  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->fixnum_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define('float', 'double') do
  boxing_fn.name = 'mrb_float_value'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(%{box});"

  unboxing_fn.name = 'mrb_float'
  unboxing_fn.invocation_template = "#{type_name} %{as} = #{unboxing_fn.name}(%{unbox});"

  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->float_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Float expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define('bool') do
  boxing_fn.name = 'mrb_bool_value'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(%{box});"

  unboxing_fn.name = 'mrb_test'
  unboxing_fn.invocation_template = "#{type_name} %{as} = #{unboxing_fn.name}(%{unbox});"

  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->true_class) && !mrb_obj_is_kind_of(mrb, %{value}, mrb->false_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Boolean expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define('char *') do
  boxing_fn.name = 'mrb_str_new_cstr'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"

  unboxing_fn.name = 'mrb_string_value_cstr'
  unboxing_fn.invocation_template = <<EOF
/* WARNING: Allocating new memory to create 'char *' from 'const char *'.
 *          Please verify that this memory is cleaned up correctly.
 *
 *          Has this been verified? [No]
 */
#{type_name} %{as} = strdup(#{unboxing_fn.name}(mrb, &%{unbox}));
EOF

  unboxing_fn.param_cleanup_template = <<EOF
/* WARNING: Assuming that the new string can be deallocated after the function call.
 *          Please verify that this is correct (the function does not save this parameter).
 *
 *          Has this been verified? [No]
 */
free(%{clean});
%{clean} = NULL;
EOF

self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->string_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "String expected");
  return mrb_nil_value();
}
EOF

end

CTypes.define('const char *') do
  boxing_fn.name = 'mrb_str_new_cstr'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"

  unboxing_fn.name = 'mrb_string_value_cstr'
  unboxing_fn.invocation_template = "#{type_name} %{as} = #{unboxing_fn.name}(mrb, &%{unbox});"

  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->string_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "String expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define('string') do
  boxing_fn.name = 'mrb_str_new_cstr'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box}.c_str());"

  unboxing_fn.name = 'mrb_string_value_cstr'
  unboxing_fn.invocation_template = "#{type_name} %{as} = (#{type_name}) #{unboxing_fn.name}(mrb, &%{unbox});"

  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->string_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "String expected");
  return mrb_nil_value();
}
EOF
end
