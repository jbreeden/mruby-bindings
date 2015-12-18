
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
  self.recv_type = 'mrb_int'
  self.needs_unboxing = false
  self.needs_type_check = false
  self.format_specifier = 'i'
  boxing_fn.name = 'mrb_fixnum_value'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(%{box});"
  unboxing_fn.invocation_template = "#{type_name} %{as} = (#{type_name})%{unbox};"
  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->fixnum_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define(CTypes.any_constness_and_sign('float', 'double')) do
  self.recv_type = type_name
  self.format_specifier = 'f'
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
  self.recv_type = 'mrb_bool'
  self.format_specifier = 'b'
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
  self.recv_type = type_name
  self.format_specifier = 'z!'
  self.needs_unboxing = true # Would be false since we set a format specifier, but we have to strdup
  self.needs_type_check = false # Would be true since needs_unboxing
  boxing_fn.name = 'mrb_str_new_cstr'
  boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"

  unboxing_fn.name = 'mrb_string_value_cstr'
  unboxing_fn.invocation_template = <<EOF
/* WARNING: Allocating new memory to create 'char *' from 'const char *'.
 *          Please verify that this memory is cleaned up correctly.
 *
 *          Has this been verified? [No]
 */
#{type_name} %{as} = strdup(%{unbox});
EOF

  unboxing_fn.param_cleanup_template = <<EOF
/* WARNING: Assuming that the new string can be deallocated after the function call.
 *          Please verify that this is correct (the function does not save this parameter).
 *
 *          Has this been verified? [No]
 */
free(%{value});
%{value} = NULL;
EOF

  self.return_cleanup = "free(%{value});"

  # TODO: Remove once the class_template is updated like the module_template
  #       to use format specifiers
  self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->string_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "String expected");
  return mrb_nil_value();
}
EOF

end

CTypes.define('const char *') do
  self.recv_type = 'char *'
  self.format_specifier = 'z!'
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

CTypes.define('unused:pointer') do
  self.recv_type = "mrb_value"
  self.needs_unboxing = true
  self.needs_type_check = false
  self.unboxing_fn.invocation_template = "void * %{as} = NULL; /* Unused parameter */"
end

CTypes.define('out:int') do
  self.type_name = 'int'
  self.recv_type = 'int'
  self.out_only = true
  self.boxing_fn.invocation_template = "mrb_value %{as} = mrb_fixnum_value(%{box});"
end

CTypes.define('out:cstring') do
  self.type_name = 'char *'
  self.recv_type = 'char *'
  self.out_only = true
  self.boxing_fn.invocation_template = "mrb_value %{as} = mrb_str_new_cstr(mrb, %{box});"
  self.return_cleanup = "free(%{value});"
end

CTypes.define('nullterminated:cstring:array') do
  self.type_name = 'char **'
  self.recv_type = 'mrb_value'
  self.format_specifier = 'A!'
  self.needs_unboxing = true
  self.needs_type_check = false

  self.boxing_fn.invocation_template = <<EOS
mrb_value %{as} = mrb_ary_new(mrb);
do {
  int i = 0;
  while (%{box}[i] != NULL) {
    mrb_ary_push(mrb, %{as}, mrb_str_new_cstr(mrb, %{box}[i]));
    ++i;
  }
} while (0);
EOS

  self.unboxing_fn.invocation_template = <<EOS
char ** %{as} = NULL;
do {
  if (mrb_nil_p(%{unbox})) {
    %{as} = NULL;
  } else {
    int len = mrb_ary_len(mrb, %{unbox});
    %{as} = (char**)calloc((len + 1), sizeof(char*));
    for (int i = 0; i < len; i++) {
      mrb_value str = mrb_ary_ref(mrb, %{unbox}, i);
      %{as}[i] = mrb_string_value_cstr(mrb, &str);
    }
    %{as}[len] = NULL;
  }
} while (0);
EOS

  self.unboxing_fn.param_cleanup_template = "if (%{value} != NULL) free(%{value});"
  self.return_cleanup = <<EOS
do {
  int i = 0;
  while (%{value}[i] != NULL) {
    free(%{value}[i]);
    ++i;
  }
  free(%{value});
} while (0);
EOS
end
