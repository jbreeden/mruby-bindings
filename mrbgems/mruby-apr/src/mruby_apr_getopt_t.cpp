/*
 * apr_getopt_t
 * Defined in file apr_getopt.h @ line 45
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprGetoptT_TYPE

/*
 * Class Methods
 */

#if BIND_AprGetoptT_INITIALIZE
mrb_value
mrb_APR_AprGetoptT_initialize(mrb_state* mrb, mrb_value self) {
  apr_getopt_t* native_object = (apr_getopt_t*)malloc(sizeof(apr_getopt_t));
  mruby_gift_apr_getopt_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprGetoptT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprGetoptT.disown only accepts objects of type APR::AprGetoptT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprGetoptT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprGetoptT.disown only accepts objects of type APR::AprGetoptT");
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

#if BIND_AprGetoptT_cont_FIELD
/* get_cont
 *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_AprGetoptT_get_cont(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  apr_pool_t * native_field = native_self->cont;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@cont_box"), ruby_field);

  return ruby_field;
}

/* set_cont
 *
 * Parameters:
 * - value: apr_pool_t *
 */
mrb_value
mrb_APR_AprGetoptT_set_cont(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@cont_box"), ruby_field);

  apr_pool_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_pool_t(ruby_field));

  native_self->cont = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_errfn_FIELD
/* get_errfn
 *
 * Return Type: apr_getopt_err_fn_t *
 */
mrb_value
mrb_APR_AprGetoptT_get_errfn(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  apr_getopt_err_fn_t * native_field = native_self->errfn;

  mrb_value ruby_field = TODO_mruby_box_apr_getopt_err_fn_t_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@errfn_box"), ruby_field);

  return ruby_field;
}

/* set_errfn
 *
 * Parameters:
 * - value: apr_getopt_err_fn_t *
 */
mrb_value
mrb_APR_AprGetoptT_set_errfn(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_getopt_err_fn_t_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@errfn_box"), ruby_field);

  apr_getopt_err_fn_t * native_field = TODO_mruby_unbox_apr_getopt_err_fn_t_PTR(ruby_field);

  native_self->errfn = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_errarg_FIELD
/* get_errarg
 *
 * Return Type: void *
 */
mrb_value
mrb_APR_AprGetoptT_get_errarg(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  void * native_field = native_self->errarg;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@errarg_box"), ruby_field);

  return ruby_field;
}

/* set_errarg
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_APR_AprGetoptT_set_errarg(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@errarg_box"), ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->errarg = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_ind_FIELD
/* get_ind
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_ind(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->ind;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ind_box"), ruby_field);

  return ruby_field;
}

/* set_ind
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_ind(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ind_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->ind = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_opt_FIELD
/* get_opt
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_opt(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->opt;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@opt_box"), ruby_field);

  return ruby_field;
}

/* set_opt
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_opt(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@opt_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->opt = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_reset_FIELD
/* get_reset
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_reset(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->reset;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@reset_box"), ruby_field);

  return ruby_field;
}

/* set_reset
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_reset(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@reset_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->reset = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_argc_FIELD
/* get_argc
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_argc(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->argc;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@argc_box"), ruby_field);

  return ruby_field;
}

/* set_argc
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_argc(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@argc_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->argc = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_argv_FIELD
/* get_argv
 *
 * Return Type: const char **
 */
mrb_value
mrb_APR_AprGetoptT_get_argv(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  const char ** native_field = native_self->argv;

  mrb_value ruby_field = TODO_mruby_box_const_char_PTR_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@argv_box"), ruby_field);

  return ruby_field;
}

/* set_argv
 *
 * Parameters:
 * - value: const char **
 */
mrb_value
mrb_APR_AprGetoptT_set_argv(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_const_char_PTR_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@argv_box"), ruby_field);

  const char ** native_field = TODO_mruby_unbox_const_char_PTR_PTR(ruby_field);

  native_self->argv = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_place_FIELD
/* get_place
 *
 * Return Type: const char *
 */
mrb_value
mrb_APR_AprGetoptT_get_place(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  const char * native_field = native_self->place;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@place_box"), ruby_field);

  return ruby_field;
}

/* set_place
 *
 * Parameters:
 * - value: const char *
 */
mrb_value
mrb_APR_AprGetoptT_set_place(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@place_box"), ruby_field);

  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);

  native_self->place = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_interleave_FIELD
/* get_interleave
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_interleave(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->interleave;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@interleave_box"), ruby_field);

  return ruby_field;
}

/* set_interleave
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_interleave(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@interleave_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->interleave = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_skip_start_FIELD
/* get_skip_start
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_skip_start(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->skip_start;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@skip_start_box"), ruby_field);

  return ruby_field;
}

/* set_skip_start
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_skip_start(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@skip_start_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->skip_start = native_field;

  return ruby_field;
}
#endif

#if BIND_AprGetoptT_skip_end_FIELD
/* get_skip_end
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprGetoptT_get_skip_end(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);

  int native_field = native_self->skip_end;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@skip_end_box"), ruby_field);

  return ruby_field;
}

/* set_skip_end
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprGetoptT_set_skip_end(mrb_state* mrb, mrb_value self) {
  apr_getopt_t * native_self = mruby_unbox_apr_getopt_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@skip_end_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->skip_end = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprGetoptT_init(mrb_state* mrb) {
  RClass* AprGetoptT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprGetoptT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprGetoptT_class, MRB_TT_DATA);

#if BIND_AprGetoptT_INITIALIZE
  mrb_define_method(mrb, AprGetoptT_class, "initialize", mrb_APR_AprGetoptT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprGetoptT_class, "disown", mrb_APR_AprGetoptT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprGetoptT_class, "belongs_to_ruby?", mrb_APR_AprGetoptT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprGetoptT_cont_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "cont", mrb_APR_AprGetoptT_get_cont, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "cont=", mrb_APR_AprGetoptT_set_cont, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_errfn_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "errfn", mrb_APR_AprGetoptT_get_errfn, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "errfn=", mrb_APR_AprGetoptT_set_errfn, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_errarg_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "errarg", mrb_APR_AprGetoptT_get_errarg, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "errarg=", mrb_APR_AprGetoptT_set_errarg, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_ind_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "ind", mrb_APR_AprGetoptT_get_ind, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "ind=", mrb_APR_AprGetoptT_set_ind, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_opt_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "opt", mrb_APR_AprGetoptT_get_opt, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "opt=", mrb_APR_AprGetoptT_set_opt, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_reset_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "reset", mrb_APR_AprGetoptT_get_reset, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "reset=", mrb_APR_AprGetoptT_set_reset, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_argc_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "argc", mrb_APR_AprGetoptT_get_argc, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "argc=", mrb_APR_AprGetoptT_set_argc, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_argv_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "argv", mrb_APR_AprGetoptT_get_argv, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "argv=", mrb_APR_AprGetoptT_set_argv, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_place_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "place", mrb_APR_AprGetoptT_get_place, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "place=", mrb_APR_AprGetoptT_set_place, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_interleave_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "interleave", mrb_APR_AprGetoptT_get_interleave, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "interleave=", mrb_APR_AprGetoptT_set_interleave, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_skip_start_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "skip_start", mrb_APR_AprGetoptT_get_skip_start, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "skip_start=", mrb_APR_AprGetoptT_set_skip_start, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprGetoptT_skip_end_FIELD
  mrb_define_method(mrb, AprGetoptT_class, "skip_end", mrb_APR_AprGetoptT_get_skip_end, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprGetoptT_class, "skip_end=", mrb_APR_AprGetoptT_set_skip_end, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
