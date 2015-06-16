/*
 * apr_hdtr_t
 * Defined in file apr_network_io.h @ line 197
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprHdtrT_TYPE

/*
 * Class Methods
 */

#if BIND_AprHdtrT_MALLOC
mrb_value
mrb_APR_AprHdtrT_malloc(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t* native_object = (apr_hdtr_t*)malloc(sizeof(apr_hdtr_t));
  return mruby_box_apr_hdtr_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprHdtrT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprHdtrT.free can only free objects of type APR::AprHdtrT");
    return mrb_nil_value();
  }

  apr_hdtr_t * native_to_free = mruby_unbox_apr_hdtr_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprHdtrT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprHdtrT.clear_pointer can only clear objects of type APR::AprHdtrT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprHdtrT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprHdtrT.address_of can only get the address for objects of type APR::AprHdtrT");
    return mrb_nil_value();
  }

  apr_hdtr_t * native_object = mruby_unbox_apr_hdtr_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}

/*
 * Fields
 */

#if BIND_AprHdtrT_headers_FIELD
/* get_headers
 *
 * Return Type: struct iovec *
 */
mrb_value
mrb_APR_AprHdtrT_get_headers(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);

  struct iovec * native_field = native_self->headers;

  mrb_value ruby_field = TODO_mruby_box_struct_iovec_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@headers_box"), ruby_field);

  return ruby_field;
}

/* set_headers
 *
 * Parameters:
 * - value: struct iovec *
 */
mrb_value
mrb_APR_AprHdtrT_set_headers(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@headers_box"), ruby_field);

  struct iovec * native_field = TODO_mruby_unbox_struct_iovec_PTR(ruby_field);

  native_self->headers = native_field;

  return ruby_field;
}
#endif

#if BIND_AprHdtrT_numheaders_FIELD
/* get_numheaders
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprHdtrT_get_numheaders(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);

  int native_field = native_self->numheaders;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@numheaders_box"), ruby_field);

  return ruby_field;
}

/* set_numheaders
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprHdtrT_set_numheaders(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@numheaders_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->numheaders = native_field;

  return ruby_field;
}
#endif

#if BIND_AprHdtrT_trailers_FIELD
/* get_trailers
 *
 * Return Type: struct iovec *
 */
mrb_value
mrb_APR_AprHdtrT_get_trailers(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);

  struct iovec * native_field = native_self->trailers;

  mrb_value ruby_field = TODO_mruby_box_struct_iovec_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@trailers_box"), ruby_field);

  return ruby_field;
}

/* set_trailers
 *
 * Parameters:
 * - value: struct iovec *
 */
mrb_value
mrb_APR_AprHdtrT_set_trailers(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@trailers_box"), ruby_field);

  struct iovec * native_field = TODO_mruby_unbox_struct_iovec_PTR(ruby_field);

  native_self->trailers = native_field;

  return ruby_field;
}
#endif

#if BIND_AprHdtrT_numtrailers_FIELD
/* get_numtrailers
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprHdtrT_get_numtrailers(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);

  int native_field = native_self->numtrailers;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@numtrailers_box"), ruby_field);

  return ruby_field;
}

/* set_numtrailers
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprHdtrT_set_numtrailers(mrb_state* mrb, mrb_value self) {
  apr_hdtr_t * native_self = mruby_unbox_apr_hdtr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@numtrailers_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->numtrailers = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprHdtrT_init(mrb_state* mrb) {
  RClass* AprHdtrT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprHdtrT", mrb->object_class);

#if BIND_AprHdtrT_MALLOC
  mrb_define_class_method(mrb, AprHdtrT_class, "malloc", mrb_APR_AprHdtrT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprHdtrT_class, "free", mrb_APR_AprHdtrT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprHdtrT_class, "clear_pointer", mrb_APR_AprHdtrT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprHdtrT_class, "address_of", mrb_APR_AprHdtrT_address_of, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprHdtrT_headers_FIELD
  mrb_define_method(mrb, AprHdtrT_class, "headers", mrb_APR_AprHdtrT_get_headers, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprHdtrT_class, "headers=", mrb_APR_AprHdtrT_set_headers, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprHdtrT_numheaders_FIELD
  mrb_define_method(mrb, AprHdtrT_class, "numheaders", mrb_APR_AprHdtrT_get_numheaders, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprHdtrT_class, "numheaders=", mrb_APR_AprHdtrT_set_numheaders, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprHdtrT_trailers_FIELD
  mrb_define_method(mrb, AprHdtrT_class, "trailers", mrb_APR_AprHdtrT_get_trailers, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprHdtrT_class, "trailers=", mrb_APR_AprHdtrT_set_trailers, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprHdtrT_numtrailers_FIELD
  mrb_define_method(mrb, AprHdtrT_class, "numtrailers", mrb_APR_AprHdtrT_get_numtrailers, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprHdtrT_class, "numtrailers=", mrb_APR_AprHdtrT_set_numtrailers, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
