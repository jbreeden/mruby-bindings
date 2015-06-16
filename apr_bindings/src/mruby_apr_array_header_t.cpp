/*
 * apr_array_header_t
 * Defined in file apr_tables.h @ line 59
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprArrayHeaderT_TYPE

/*
 * Class Methods
 */

#if BIND_AprArrayHeaderT_MALLOC
mrb_value
mrb_APR_AprArrayHeaderT_malloc(mrb_state* mrb, mrb_value self) {
  apr_array_header_t* native_object = (apr_array_header_t*)malloc(sizeof(apr_array_header_t));
  return mruby_box_apr_array_header_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprArrayHeaderT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprArrayHeaderT.free can only free objects of type APR::AprArrayHeaderT");
    return mrb_nil_value();
  }

  apr_array_header_t * native_to_free = mruby_unbox_apr_array_header_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprArrayHeaderT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprArrayHeaderT.clear_pointer can only clear objects of type APR::AprArrayHeaderT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprArrayHeaderT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprArrayHeaderT.address_of can only get the address for objects of type APR::AprArrayHeaderT");
    return mrb_nil_value();
  }

  apr_array_header_t * native_object = mruby_unbox_apr_array_header_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}

/*
 * Fields
 */

#if BIND_AprArrayHeaderT_pool_FIELD
/* get_pool
 *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_AprArrayHeaderT_get_pool(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);

  apr_pool_t * native_field = native_self->pool;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pool_box"), ruby_field);

  return ruby_field;
}

/* set_pool
 *
 * Parameters:
 * - value: apr_pool_t *
 */
mrb_value
mrb_APR_AprArrayHeaderT_set_pool(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pool_box"), ruby_field);

  apr_pool_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_pool_t(ruby_field));

  native_self->pool = native_field;

  return ruby_field;
}
#endif

#if BIND_AprArrayHeaderT_elt_size_FIELD
/* get_elt_size
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprArrayHeaderT_get_elt_size(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);

  int native_field = native_self->elt_size;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@elt_size_box"), ruby_field);

  return ruby_field;
}

/* set_elt_size
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprArrayHeaderT_set_elt_size(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@elt_size_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->elt_size = native_field;

  return ruby_field;
}
#endif

#if BIND_AprArrayHeaderT_nelts_FIELD
/* get_nelts
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprArrayHeaderT_get_nelts(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);

  int native_field = native_self->nelts;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@nelts_box"), ruby_field);

  return ruby_field;
}

/* set_nelts
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprArrayHeaderT_set_nelts(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@nelts_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->nelts = native_field;

  return ruby_field;
}
#endif

#if BIND_AprArrayHeaderT_nalloc_FIELD
/* get_nalloc
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprArrayHeaderT_get_nalloc(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);

  int native_field = native_self->nalloc;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@nalloc_box"), ruby_field);

  return ruby_field;
}

/* set_nalloc
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprArrayHeaderT_set_nalloc(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@nalloc_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->nalloc = native_field;

  return ruby_field;
}
#endif

#if BIND_AprArrayHeaderT_elts_FIELD
/* get_elts
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprArrayHeaderT_get_elts(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);

  char * native_field = native_self->elts;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@elts_box"), ruby_field);

  return ruby_field;
}

/* set_elts
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprArrayHeaderT_set_elts(mrb_state* mrb, mrb_value self) {
  apr_array_header_t * native_self = mruby_unbox_apr_array_header_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@elts_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->elts = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprArrayHeaderT_init(mrb_state* mrb) {
  RClass* AprArrayHeaderT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprArrayHeaderT", mrb->object_class);

#if BIND_AprArrayHeaderT_MALLOC
  mrb_define_class_method(mrb, AprArrayHeaderT_class, "malloc", mrb_APR_AprArrayHeaderT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprArrayHeaderT_class, "free", mrb_APR_AprArrayHeaderT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprArrayHeaderT_class, "clear_pointer", mrb_APR_AprArrayHeaderT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprArrayHeaderT_class, "address_of", mrb_APR_AprArrayHeaderT_address_of, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprArrayHeaderT_pool_FIELD
  mrb_define_method(mrb, AprArrayHeaderT_class, "pool", mrb_APR_AprArrayHeaderT_get_pool, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprArrayHeaderT_class, "pool=", mrb_APR_AprArrayHeaderT_set_pool, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprArrayHeaderT_elt_size_FIELD
  mrb_define_method(mrb, AprArrayHeaderT_class, "elt_size", mrb_APR_AprArrayHeaderT_get_elt_size, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprArrayHeaderT_class, "elt_size=", mrb_APR_AprArrayHeaderT_set_elt_size, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprArrayHeaderT_nelts_FIELD
  mrb_define_method(mrb, AprArrayHeaderT_class, "nelts", mrb_APR_AprArrayHeaderT_get_nelts, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprArrayHeaderT_class, "nelts=", mrb_APR_AprArrayHeaderT_set_nelts, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprArrayHeaderT_nalloc_FIELD
  mrb_define_method(mrb, AprArrayHeaderT_class, "nalloc", mrb_APR_AprArrayHeaderT_get_nalloc, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprArrayHeaderT_class, "nalloc=", mrb_APR_AprArrayHeaderT_set_nalloc, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprArrayHeaderT_elts_FIELD
  mrb_define_method(mrb, AprArrayHeaderT_class, "elts", mrb_APR_AprArrayHeaderT_get_elts, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprArrayHeaderT_class, "elts=", mrb_APR_AprArrayHeaderT_set_elts, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
