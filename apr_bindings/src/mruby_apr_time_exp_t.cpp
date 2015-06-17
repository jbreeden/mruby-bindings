/*
 * apr_time_exp_t
 * Defined in file apr_time.h @ line 91
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprTimeExpT_TYPE

/*
 * Class Methods
 */

#if BIND_AprTimeExpT_INITIALIZE
mrb_value
mrb_APR_AprTimeExpT_initialize(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t* native_object = (apr_time_exp_t*)malloc(sizeof(apr_time_exp_t));
  mruby_gift_apr_time_exp_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprTimeExpT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprTimeExpT.disown only accepts objects of type APR::AprTimeExpT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprTimeExpT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprTimeExpT.disown only accepts objects of type APR::AprTimeExpT");
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

#if BIND_AprTimeExpT_tm_usec_FIELD
/* get_tm_usec
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_usec(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_usec;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_usec_box"), ruby_field);

  return ruby_field;
}

/* set_tm_usec
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_usec(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_usec_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_usec = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_sec_FIELD
/* get_tm_sec
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_sec(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_sec;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_sec_box"), ruby_field);

  return ruby_field;
}

/* set_tm_sec
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_sec(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_sec_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_sec = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_min_FIELD
/* get_tm_min
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_min(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_min;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_min_box"), ruby_field);

  return ruby_field;
}

/* set_tm_min
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_min(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_min_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_min = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_hour_FIELD
/* get_tm_hour
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_hour(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_hour;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_hour_box"), ruby_field);

  return ruby_field;
}

/* set_tm_hour
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_hour(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_hour_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_hour = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_mday_FIELD
/* get_tm_mday
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_mday(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_mday;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_mday_box"), ruby_field);

  return ruby_field;
}

/* set_tm_mday
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_mday(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_mday_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_mday = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_mon_FIELD
/* get_tm_mon
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_mon(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_mon;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_mon_box"), ruby_field);

  return ruby_field;
}

/* set_tm_mon
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_mon(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_mon_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_mon = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_year_FIELD
/* get_tm_year
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_year(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_year;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_year_box"), ruby_field);

  return ruby_field;
}

/* set_tm_year
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_year(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_year_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_year = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_wday_FIELD
/* get_tm_wday
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_wday(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_wday;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_wday_box"), ruby_field);

  return ruby_field;
}

/* set_tm_wday
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_wday(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_wday_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_wday = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_yday_FIELD
/* get_tm_yday
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_yday(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_yday;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_yday_box"), ruby_field);

  return ruby_field;
}

/* set_tm_yday
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_yday(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_yday_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_yday = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_isdst_FIELD
/* get_tm_isdst
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_isdst(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_isdst;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_isdst_box"), ruby_field);

  return ruby_field;
}

/* set_tm_isdst
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_isdst(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_isdst_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_isdst = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTimeExpT_tm_gmtoff_FIELD
/* get_tm_gmtoff
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_get_tm_gmtoff(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);

  apr_int32_t native_field = native_self->tm_gmtoff;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_gmtoff_box"), ruby_field);

  return ruby_field;
}

/* set_tm_gmtoff
 *
 * Parameters:
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprTimeExpT_set_tm_gmtoff(mrb_state* mrb, mrb_value self) {
  apr_time_exp_t * native_self = mruby_unbox_apr_time_exp_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@tm_gmtoff_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->tm_gmtoff = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprTimeExpT_init(mrb_state* mrb) {
  RClass* AprTimeExpT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprTimeExpT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprTimeExpT_class, MRB_TT_DATA);

#if BIND_AprTimeExpT_INITIALIZE
  mrb_define_method(mrb, AprTimeExpT_class, "initialize", mrb_APR_AprTimeExpT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprTimeExpT_class, "disown", mrb_APR_AprTimeExpT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprTimeExpT_class, "belongs_to_ruby?", mrb_APR_AprTimeExpT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprTimeExpT_tm_usec_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_usec", mrb_APR_AprTimeExpT_get_tm_usec, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_usec=", mrb_APR_AprTimeExpT_set_tm_usec, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_sec_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_sec", mrb_APR_AprTimeExpT_get_tm_sec, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_sec=", mrb_APR_AprTimeExpT_set_tm_sec, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_min_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_min", mrb_APR_AprTimeExpT_get_tm_min, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_min=", mrb_APR_AprTimeExpT_set_tm_min, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_hour_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_hour", mrb_APR_AprTimeExpT_get_tm_hour, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_hour=", mrb_APR_AprTimeExpT_set_tm_hour, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_mday_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_mday", mrb_APR_AprTimeExpT_get_tm_mday, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_mday=", mrb_APR_AprTimeExpT_set_tm_mday, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_mon_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_mon", mrb_APR_AprTimeExpT_get_tm_mon, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_mon=", mrb_APR_AprTimeExpT_set_tm_mon, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_year_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_year", mrb_APR_AprTimeExpT_get_tm_year, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_year=", mrb_APR_AprTimeExpT_set_tm_year, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_wday_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_wday", mrb_APR_AprTimeExpT_get_tm_wday, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_wday=", mrb_APR_AprTimeExpT_set_tm_wday, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_yday_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_yday", mrb_APR_AprTimeExpT_get_tm_yday, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_yday=", mrb_APR_AprTimeExpT_set_tm_yday, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_isdst_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_isdst", mrb_APR_AprTimeExpT_get_tm_isdst, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_isdst=", mrb_APR_AprTimeExpT_set_tm_isdst, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTimeExpT_tm_gmtoff_FIELD
  mrb_define_method(mrb, AprTimeExpT_class, "tm_gmtoff", mrb_APR_AprTimeExpT_get_tm_gmtoff, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTimeExpT_class, "tm_gmtoff=", mrb_APR_AprTimeExpT_set_tm_gmtoff, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
