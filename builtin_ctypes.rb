
def CTypes.any_constness_and_sign(*types)
  result = types.dup
  result << types.map { |type| "const #{type}" }
  result << types.map { |type| "unsigned #{type}" }
  result << types.map { |type| "const unsigned #{type}" }
  result << types.map { |type| "unsigned const #{type}" }
  result << types.map { |type| "singed #{type}" }
  result << types.map { |type| "singed const #{type}" }
  result << types.map { |type| "const singed #{type}" }
  result
end

CTypes.define(CTypes.any_constness_and_sign('char', 'short', 'long', 'int', 'long long', 'size_t')) do
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

CTypes.define(CTypes.any_constness_and_sign('float', 'double')) do
  boxing_fn.name = 'mrb_float_value'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"

  unboxing_fn.name = 'mrb_float'
  unboxing_fn.invocation_template = "#{type_name} %{as} = #{unboxing_fn.name}(%{unbox});"

  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->float_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Float expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define(CTypes.any_constness_and_sign('bool')) do
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
