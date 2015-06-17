/*
 * apr_version_t
 * Defined in file apr_version.h @ line 140
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprVersionT_TYPE

/*
 * Class Methods
 */

#if BIND_AprVersionT_INITIALIZE
mrb_value
mrb_APR_AprVersionT_initialize(mrb_state* mrb, mrb_value self) {
  apr_version_t* native_object = (apr_version_t*)malloc(sizeof(apr_version_t));
  mruby_gift_apr_version_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprVersionT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVersionT.disown only accepts objects of type APR::AprVersionT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprVersionT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVersionT.disown only accepts objects of type APR::AprVersionT");
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

#if BIND_AprVersionT_major_FIELD
/* get_major
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprVersionT_get_major(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);

  int native_field = native_self->major;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@major_box"), ruby_field);

  return ruby_field;
}

/* set_major
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprVersionT_set_major(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@major_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->major = native_field;

  return ruby_field;
}
#endif

#if BIND_AprVersionT_minor_FIELD
/* get_minor
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprVersionT_get_minor(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);

  int native_field = native_self->minor;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@minor_box"), ruby_field);

  return ruby_field;
}

/* set_minor
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprVersionT_set_minor(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@minor_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->minor = native_field;

  return ruby_field;
}
#endif

#if BIND_AprVersionT_patch_FIELD
/* get_patch
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprVersionT_get_patch(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);

  int native_field = native_self->patch;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@patch_box"), ruby_field);

  return ruby_field;
}

/* set_patch
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprVersionT_set_patch(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@patch_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->patch = native_field;

  return ruby_field;
}
#endif

#if BIND_AprVersionT_is_dev_FIELD
/* get_is_dev
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprVersionT_get_is_dev(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);

  int native_field = native_self->is_dev;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@is_dev_box"), ruby_field);

  return ruby_field;
}

/* set_is_dev
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprVersionT_set_is_dev(mrb_state* mrb, mrb_value self) {
  apr_version_t * native_self = mruby_unbox_apr_version_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@is_dev_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->is_dev = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprVersionT_init(mrb_state* mrb) {
  RClass* AprVersionT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprVersionT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprVersionT_class, MRB_TT_DATA);

#if BIND_AprVersionT_INITIALIZE
  mrb_define_method(mrb, AprVersionT_class, "initialize", mrb_APR_AprVersionT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprVersionT_class, "disown", mrb_APR_AprVersionT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprVersionT_class, "belongs_to_ruby?", mrb_APR_AprVersionT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprVersionT_major_FIELD
  mrb_define_method(mrb, AprVersionT_class, "major", mrb_APR_AprVersionT_get_major, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprVersionT_class, "major=", mrb_APR_AprVersionT_set_major, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprVersionT_minor_FIELD
  mrb_define_method(mrb, AprVersionT_class, "minor", mrb_APR_AprVersionT_get_minor, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprVersionT_class, "minor=", mrb_APR_AprVersionT_set_minor, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprVersionT_patch_FIELD
  mrb_define_method(mrb, AprVersionT_class, "patch", mrb_APR_AprVersionT_get_patch, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprVersionT_class, "patch=", mrb_APR_AprVersionT_set_patch, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprVersionT_is_dev_FIELD
  mrb_define_method(mrb, AprVersionT_class, "is_dev", mrb_APR_AprVersionT_get_is_dev, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprVersionT_class, "is_dev=", mrb_APR_AprVersionT_set_is_dev, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
