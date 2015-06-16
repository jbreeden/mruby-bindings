/*
 * apr_proc_t
 * Defined in file apr_thread_proc.h @ line 133
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprProcT_TYPE

/*
 * Class Methods
 */

#if BIND_AprProcT_MALLOC
mrb_value
mrb_APR_AprProcT_malloc(mrb_state* mrb, mrb_value self) {
  apr_proc_t* native_object = (apr_proc_t*)malloc(sizeof(apr_proc_t));
  return mruby_box_apr_proc_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprProcT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcT.free can only free objects of type APR::AprProcT");
    return mrb_nil_value();
  }

  apr_proc_t * native_to_free = mruby_unbox_apr_proc_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprProcT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcT.clear_pointer can only clear objects of type APR::AprProcT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprProcT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcT.address_of can only get the address for objects of type APR::AprProcT");
    return mrb_nil_value();
  }

  apr_proc_t * native_object = mruby_unbox_apr_proc_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}

/*
 * Fields
 */

#if BIND_AprProcT_pid_FIELD
/* get_pid
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprProcT_get_pid(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);

  int native_field = native_self->pid;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pid_box"), ruby_field);

  return ruby_field;
}

/* set_pid
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprProcT_set_pid(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pid_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->pid = native_field;

  return ruby_field;
}
#endif

#if BIND_AprProcT_in_FIELD
/* get_in
 *
 * Return Type: apr_file_t *
 */
mrb_value
mrb_APR_AprProcT_get_in(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);

  apr_file_t * native_field = native_self->in;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_file_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@in_box"), ruby_field);

  return ruby_field;
}

/* set_in
 *
 * Parameters:
 * - value: apr_file_t *
 */
mrb_value
mrb_APR_AprProcT_set_in(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@in_box"), ruby_field);

  apr_file_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_file_t(ruby_field));

  native_self->in = native_field;

  return ruby_field;
}
#endif

#if BIND_AprProcT_out_FIELD
/* get_out
 *
 * Return Type: apr_file_t *
 */
mrb_value
mrb_APR_AprProcT_get_out(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);

  apr_file_t * native_field = native_self->out;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_file_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@out_box"), ruby_field);

  return ruby_field;
}

/* set_out
 *
 * Parameters:
 * - value: apr_file_t *
 */
mrb_value
mrb_APR_AprProcT_set_out(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@out_box"), ruby_field);

  apr_file_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_file_t(ruby_field));

  native_self->out = native_field;

  return ruby_field;
}
#endif

#if BIND_AprProcT_err_FIELD
/* get_err
 *
 * Return Type: apr_file_t *
 */
mrb_value
mrb_APR_AprProcT_get_err(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);

  apr_file_t * native_field = native_self->err;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_file_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@err_box"), ruby_field);

  return ruby_field;
}

/* set_err
 *
 * Parameters:
 * - value: apr_file_t *
 */
mrb_value
mrb_APR_AprProcT_set_err(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@err_box"), ruby_field);

  apr_file_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_file_t(ruby_field));

  native_self->err = native_field;

  return ruby_field;
}
#endif

#if BIND_AprProcT_invoked_FIELD
/* get_invoked
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprProcT_get_invoked(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);

  char * native_field = native_self->invoked;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@invoked_box"), ruby_field);

  return ruby_field;
}

/* set_invoked
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprProcT_set_invoked(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@invoked_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->invoked = native_field;

  return ruby_field;
}
#endif

#if BIND_AprProcT_hproc_FIELD
/* get_hproc
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprProcT_get_hproc(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);

  int native_field = native_self->hproc;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@hproc_box"), ruby_field);

  return ruby_field;
}

/* set_hproc
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprProcT_set_hproc(mrb_state* mrb, mrb_value self) {
  apr_proc_t * native_self = mruby_unbox_apr_proc_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@hproc_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->hproc = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprProcT_init(mrb_state* mrb) {
  RClass* AprProcT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprProcT", mrb->object_class);

#if BIND_AprProcT_MALLOC
  mrb_define_class_method(mrb, AprProcT_class, "malloc", mrb_APR_AprProcT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprProcT_class, "free", mrb_APR_AprProcT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprProcT_class, "clear_pointer", mrb_APR_AprProcT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprProcT_class, "address_of", mrb_APR_AprProcT_address_of, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprProcT_pid_FIELD
  mrb_define_method(mrb, AprProcT_class, "pid", mrb_APR_AprProcT_get_pid, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprProcT_class, "pid=", mrb_APR_AprProcT_set_pid, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprProcT_in_FIELD
  mrb_define_method(mrb, AprProcT_class, "in", mrb_APR_AprProcT_get_in, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprProcT_class, "in=", mrb_APR_AprProcT_set_in, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprProcT_out_FIELD
  mrb_define_method(mrb, AprProcT_class, "out", mrb_APR_AprProcT_get_out, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprProcT_class, "out=", mrb_APR_AprProcT_set_out, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprProcT_err_FIELD
  mrb_define_method(mrb, AprProcT_class, "err", mrb_APR_AprProcT_get_err, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprProcT_class, "err=", mrb_APR_AprProcT_set_err, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprProcT_invoked_FIELD
  mrb_define_method(mrb, AprProcT_class, "invoked", mrb_APR_AprProcT_get_invoked, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprProcT_class, "invoked=", mrb_APR_AprProcT_set_invoked, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprProcT_hproc_FIELD
  mrb_define_method(mrb, AprProcT_class, "hproc", mrb_APR_AprProcT_get_hproc, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprProcT_class, "hproc=", mrb_APR_AprProcT_set_hproc, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
