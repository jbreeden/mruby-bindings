/*
 * apr_getopt_option_t
 * Defined in file apr_getopt.h @ line 78
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprGetoptOptionT_TYPE

/*
 * Class Methods
 */

#if BIND_AprGetoptOptionT_INITIALIZE
mrb_value
mrb_APR_AprGetoptOptionT_initialize(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t* native_object = (apr_getopt_option_t*)malloc(sizeof(apr_getopt_option_t));
  mruby_gift_apr_getopt_option_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprGetoptOptionT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprGetoptOptionT.disown only accepts objects of type APR::AprGetoptOptionT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprGetoptOptionT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprGetoptOptionT.disown only accepts objects of type APR::AprGetoptOptionT");
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

#if BIND_AprGetoptOptionT_name_FIELD
/* get_name
 *
 * Return Type: const char *
 */
mrb_value
mrb_APR_AprGetoptOptionT_get_name(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);

  const char * native_field = native_self->name;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@name_box"), ruby_field);

  return ruby_field;
}

/* set_name
 *
 * Parameters:
 * - value: const char *
 */
mrb_value
mrb_APR_AprGetoptOptionT_set_name(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@name_box"), ruby_field);

  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);

  native_self->name = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptOptionT_optch_FIELD
/* get_optch
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptOptionT_get_optch(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);

  int native_field = native_self->optch;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@optch_box"), ruby_field);

  return ruby_field;
}

/* set_optch
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptOptionT_set_optch(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@optch_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->optch = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptOptionT_has_arg_FIELD
/* get_has_arg
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptOptionT_get_has_arg(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);

  int native_field = native_self->has_arg;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@has_arg_box"), ruby_field);

  return ruby_field;
}

/* set_has_arg
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptOptionT_set_has_arg(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@has_arg_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->has_arg = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptOptionT_description_FIELD
/* get_description
 *
 * Return Type: const char *
 */
mrb_value
mrb_APR_AprGetoptOptionT_get_description(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);

  const char * native_field = native_self->description;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@description_box"), ruby_field);

  return ruby_field;
}

/* set_description
 *
 * Parameters:
 * - value: const char *
 */
mrb_value
mrb_APR_AprGetoptOptionT_set_description(mrb_state* mrb, mrb_value self) {
  apr_getopt_option_t * native_self = mruby_unbox_apr_getopt_option_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@description_box"), ruby_field);

  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);

  native_self->description = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprGetoptOptionT_init(mrb_state* mrb) {
  RClass* AprGetoptOptionT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprGetoptOptionT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprGetoptOptionT_class, MRB_TT_DATA);

#if BIND_AprGetoptOptionT_INITIALIZE
  mrb_define_method(mrb, AprGetoptOptionT_class, "initialize", mrb_APR_AprGetoptOptionT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprGetoptOptionT_class, "disown", mrb_APR_AprGetoptOptionT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprGetoptOptionT_class, "belongs_to_ruby?", mrb_APR_AprGetoptOptionT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprGetoptOptionT_name_FIELD
  mrb_define_method(mrb, AprGetoptOptionT_class, "name", mrb_APR_AprGetoptOptionT_get_name, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptOptionT_class, "name=", mrb_APR_AprGetoptOptionT_set_name, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptOptionT_optch_FIELD
  mrb_define_method(mrb, AprGetoptOptionT_class, "optch", mrb_APR_AprGetoptOptionT_get_optch, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptOptionT_class, "optch=", mrb_APR_AprGetoptOptionT_set_optch, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptOptionT_has_arg_FIELD
  mrb_define_method(mrb, AprGetoptOptionT_class, "has_arg", mrb_APR_AprGetoptOptionT_get_has_arg, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptOptionT_class, "has_arg=", mrb_APR_AprGetoptOptionT_set_has_arg, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptOptionT_description_FIELD
  mrb_define_method(mrb, AprGetoptOptionT_class, "description", mrb_APR_AprGetoptOptionT_get_description, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptOptionT_class, "description=", mrb_APR_AprGetoptOptionT_set_description, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
