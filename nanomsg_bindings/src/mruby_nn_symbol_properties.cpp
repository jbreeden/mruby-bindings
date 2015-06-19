/*
 * nn_symbol_properties
 * Defined in file nn.h @ line 223
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnSymbolProperties_TYPE

/*
 * Class Methods
 */

#if BIND_NnSymbolProperties_INITIALIZE
mrb_value
mrb_NN_NnSymbolProperties_initialize(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties* native_object = (nn_symbol_properties*)malloc(sizeof(nn_symbol_properties));
  mruby_gift_nn_symbol_properties_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnSymbolProperties_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSymbolProperties.disown only accepts objects of type NN::NnSymbolProperties");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnSymbolProperties_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSymbolProperties.disown only accepts objects of type NN::NnSymbolProperties");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}

/*
 * Fields
 */

#if BIND_NnSymbolProperties_value_FIELD
/* get_value
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSymbolProperties_get_value(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);

  int native_field = native_self->value;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_value
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSymbolProperties_set_value(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->value = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSymbolProperties_name_FIELD
/* get_name
 *
 * Return Type: const char *
 */
mrb_value
mrb_NN_NnSymbolProperties_get_name(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);

  const char * native_field = native_self->name;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_name
 *
 * Parameters:
 * - value: const char *
 */
mrb_value
mrb_NN_NnSymbolProperties_set_name(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);

  native_self->name = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSymbolProperties_ns_FIELD
/* get_ns
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSymbolProperties_get_ns(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);

  int native_field = native_self->ns;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_ns
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSymbolProperties_set_ns(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->ns = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSymbolProperties_type_FIELD
/* get_type
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSymbolProperties_get_type(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);

  int native_field = native_self->type;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_type
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSymbolProperties_set_type(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->type = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSymbolProperties_unit_FIELD
/* get_unit
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSymbolProperties_get_unit(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);

  int native_field = native_self->unit;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_unit
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSymbolProperties_set_unit(mrb_state* mrb, mrb_value self) {
  nn_symbol_properties * native_self = mruby_unbox_nn_symbol_properties(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->unit = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnSymbolProperties_init(mrb_state* mrb) {
  RClass* NnSymbolProperties_class = mrb_define_class_under(mrb, NN_module(mrb), "NnSymbolProperties", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnSymbolProperties_class, MRB_TT_DATA);

#if BIND_NnSymbolProperties_INITIALIZE
  mrb_define_method(mrb, NnSymbolProperties_class, "initialize", mrb_NN_NnSymbolProperties_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnSymbolProperties_class, "disown", mrb_NN_NnSymbolProperties_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnSymbolProperties_class, "belongs_to_ruby?", mrb_NN_NnSymbolProperties_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnSymbolProperties_value_FIELD
  mrb_define_method(mrb, NnSymbolProperties_class, "value", mrb_NN_NnSymbolProperties_get_value, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSymbolProperties_class, "value=", mrb_NN_NnSymbolProperties_set_value, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSymbolProperties_name_FIELD
  mrb_define_method(mrb, NnSymbolProperties_class, "name", mrb_NN_NnSymbolProperties_get_name, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSymbolProperties_class, "name=", mrb_NN_NnSymbolProperties_set_name, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSymbolProperties_ns_FIELD
  mrb_define_method(mrb, NnSymbolProperties_class, "ns", mrb_NN_NnSymbolProperties_get_ns, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSymbolProperties_class, "ns=", mrb_NN_NnSymbolProperties_set_ns, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSymbolProperties_type_FIELD
  mrb_define_method(mrb, NnSymbolProperties_class, "type", mrb_NN_NnSymbolProperties_get_type, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSymbolProperties_class, "type=", mrb_NN_NnSymbolProperties_set_type, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSymbolProperties_unit_FIELD
  mrb_define_method(mrb, NnSymbolProperties_class, "unit", mrb_NN_NnSymbolProperties_get_unit, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSymbolProperties_class, "unit=", mrb_NN_NnSymbolProperties_set_unit, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
