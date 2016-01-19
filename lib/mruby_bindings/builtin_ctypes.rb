require 'mruby_bindings/ctypes'

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

CTypes.define('ignore') do
  self.ignore = true
end

CTypes.define('void') do
  self.ignore = true
end

CTypes.typedef('int', 'time_t')

CTypes.define(CTypes.any_constness_and_sign('char', 'short', 'long', 'int', 'long long', 'size_t')) do
  self.recv_template = 'mrb_int %{value};'
  self.needs_unboxing = false
  self.needs_type_check = false
  self.format_specifier = 'i'
  boxing_fn.invocation_template = "mrb_value %{as} = mrb_fixnum_value(%{box});"
  unboxing_fn.invocation_template = "#{type_name} %{as} = (#{type_name})%{unbox};"
  self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->fixnum_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define(CTypes.any_constness_and_sign('float', 'double')) do
  self.recv_template = "mrb_float %{value};"
  self.format_specifier = 'f'
  boxing_fn.invocation_template = "mrb_value %{as} = mrb_float_value(mrb, %{box});"
  unboxing_fn.invocation_template = "#{type_name} %{as} = mrb_float(%{unbox});"
  self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->float_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Float expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define(CTypes.any_constness_and_sign('bool')) do
  self.recv_template = 'mrb_bool %{value};'
  self.format_specifier = 'b'
  self.needs_type_check = false
  boxing_fn.invocation_template = "mrb_value %{as} = mrb_bool_value(%{box});"
  unboxing_fn.invocation_template = "#{type_name} %{as} = mrb_test(%{unbox});"
  self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->true_class) && !mrb_obj_is_kind_of(mrb, %{value}, mrb->false_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "Boolean expected");
  return mrb_nil_value();
}
EOF
end

# String stuff that I'm not too sure about
# ----------------------------------------

CTypes.define('const char *') do
  self.recv_template = 'char * %{value} = NULL;'
  self.format_specifier = 'z'
  boxing_fn.invocation_template = "mrb_value %{as} = %{box} == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, %{box});"
  unboxing_fn.invocation_template = "#{type_name} %{as} = mrb_string_value_cstr(mrb, &%{unbox});"
  self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->string_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "String expected");
  return mrb_nil_value();
}
EOF
end

CTypes.define('string') do
  boxing_fn.invocation_template = "mrb_value %{as} = mrb_str_new_cstr(mrb, %{box}.c_str());"
  unboxing_fn.invocation_template = "#{type_name} %{as} = (#{type_name}) mrb_string_value_cstr(mrb, &%{unbox});"
  self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, mrb->string_class)) {
  mrb_raise(mrb, E_TYPE_ERROR, "String expected");
  return mrb_nil_value();
}
EOF
end

# Custom Semantic Types
# ---------------------

CTypes.define('return:cstring') do
  self.type_name = 'char *'
  self.recv_template = 'char * %{value};'
  self.boxing_fn.invocation_template = "mrb_value %{as} = mrb_str_new_cstr(mrb, %{box});"
  self.boxing_fn.cleanup_template = "free(%{value});"
end

CTypes.define('unused:pointer') do
  self.needs_unboxing = true
  self.needs_type_check = false
  self.unboxing_fn.invocation_template = "void * %{as} = NULL; /* Unused parameter */"
end

CTypes.define('out:int *') do
  self.type_name = 'int'
  self.recv_template = 'int %{value};'
  self.invocation_arg_template = "&%{value}"
  self.out_only = true
  self.boxing_fn.invocation_template = "mrb_value %{as} = mrb_fixnum_value(%{box});"
end

CTypes.define('out:cstring') do
  self.type_name = 'char *'
  self.recv_template = 'char * %{value} = NULL;'
  self.invocation_arg_template = "&%{value}"
  self.out_only = true
  self.boxing_fn.invocation_template = "mrb_value %{as} = mrb_str_new_cstr(mrb, %{box});"
  self.boxing_fn.cleanup_template = "free(%{value});"
end

CTypes.define('out:char**,int*') do
  self.type_name = "char *"
  self.out_only = true
  self.needs_unboxing = false
  self.recv_template = <<EOS
char * %{value} = NULL;
int %{value}_length = 0;
EOS
  self.invocation_arg_template = "&%{value}, &%{value}_length"
  self.boxing_fn.invocation_template = <<EOS
mrb_value %{as};
if (%{box} == NULL) {
  %{as} = mrb_nil_value();
} else {
  %{as} = mrb_str_new(mrb, %{box}, %{box}_length);
}
EOS
  self.boxing_fn.cleanup_template = "free(%{value});"
end

# argv / envp style arrays of c strings, terminated by a NULL string
CTypes.define('nullterminated:cstring:array') do
  self.type_name = 'char **'
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

  self.boxing_fn.cleanup_template = <<EOS
do {
  int i = 0;
  while (%{value}[i] != NULL) {
    free(%{value}[i]);
    ++i;
  }
  free(%{value});
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

  self.unboxing_fn.cleanup_template = "if (%{value} != NULL) free(%{value});"
end
