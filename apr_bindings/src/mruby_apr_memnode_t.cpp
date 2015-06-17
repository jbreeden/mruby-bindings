/*
 * apr_memnode_t
 * Defined in file apr_allocator.h @ line 43
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprMemnodeT_TYPE

/*
 * Class Methods
 */

#if BIND_AprMemnodeT_INITIALIZE
mrb_value
mrb_APR_AprMemnodeT_initialize(mrb_state* mrb, mrb_value self) {
  apr_memnode_t* native_object = (apr_memnode_t*)malloc(sizeof(apr_memnode_t));
  mruby_gift_apr_memnode_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprMemnodeT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprMemnodeT.disown only accepts objects of type APR::AprMemnodeT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprMemnodeT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprMemnodeT.disown only accepts objects of type APR::AprMemnodeT");
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

#if BIND_AprMemnodeT_next_FIELD
/* get_next
 *
 * Return Type: apr_memnode_t *
 */
mrb_value
mrb_APR_AprMemnodeT_get_next(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);

  apr_memnode_t * native_field = native_self->next;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_memnode_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@next_box"), ruby_field);

  return ruby_field;
}

/* set_next
 *
 * Parameters:
 * - value: apr_memnode_t *
 */
mrb_value
mrb_APR_AprMemnodeT_set_next(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprMemnodeT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprMemnodeT expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@next_box"), ruby_field);

  apr_memnode_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_memnode_t(ruby_field));

  native_self->next = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMemnodeT_ref_FIELD
/* get_ref
 *
 * Return Type: apr_memnode_t **
 */
mrb_value
mrb_APR_AprMemnodeT_get_ref(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);

  apr_memnode_t ** native_field = native_self->ref;

  mrb_value ruby_field = TODO_mruby_box_apr_memnode_t_PTR_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ref_box"), ruby_field);

  return ruby_field;
}

/* set_ref
 *
 * Parameters:
 * - value: apr_memnode_t **
 */
mrb_value
mrb_APR_AprMemnodeT_set_ref(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_memnode_t_PTR_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ref_box"), ruby_field);

  apr_memnode_t ** native_field = TODO_mruby_unbox_apr_memnode_t_PTR_PTR(ruby_field);

  native_self->ref = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMemnodeT_index_FIELD
/* get_index
 *
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_AprMemnodeT_get_index(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);

  apr_uint32_t native_field = native_self->index;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@index_box"), ruby_field);

  return ruby_field;
}

/* set_index
 *
 * Parameters:
 * - value: apr_uint32_t
 */
mrb_value
mrb_APR_AprMemnodeT_set_index(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@index_box"), ruby_field);

  unsigned int native_field = mrb_fixnum(ruby_field);

  native_self->index = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMemnodeT_free_index_FIELD
/* get_free_index
 *
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_AprMemnodeT_get_free_index(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);

  apr_uint32_t native_field = native_self->free_index;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@free_index_box"), ruby_field);

  return ruby_field;
}

/* set_free_index
 *
 * Parameters:
 * - value: apr_uint32_t
 */
mrb_value
mrb_APR_AprMemnodeT_set_free_index(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@free_index_box"), ruby_field);

  unsigned int native_field = mrb_fixnum(ruby_field);

  native_self->free_index = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMemnodeT_first_avail_FIELD
/* get_first_avail
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprMemnodeT_get_first_avail(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);

  char * native_field = native_self->first_avail;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@first_avail_box"), ruby_field);

  return ruby_field;
}

/* set_first_avail
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprMemnodeT_set_first_avail(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@first_avail_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->first_avail = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMemnodeT_endp_FIELD
/* get_endp
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprMemnodeT_get_endp(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);

  char * native_field = native_self->endp;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@endp_box"), ruby_field);

  return ruby_field;
}

/* set_endp
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprMemnodeT_set_endp(mrb_state* mrb, mrb_value self) {
  apr_memnode_t * native_self = mruby_unbox_apr_memnode_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@endp_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->endp = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprMemnodeT_init(mrb_state* mrb) {
  RClass* AprMemnodeT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprMemnodeT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprMemnodeT_class, MRB_TT_DATA);

#if BIND_AprMemnodeT_INITIALIZE
  mrb_define_method(mrb, AprMemnodeT_class, "initialize", mrb_APR_AprMemnodeT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprMemnodeT_class, "disown", mrb_APR_AprMemnodeT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprMemnodeT_class, "belongs_to_ruby?", mrb_APR_AprMemnodeT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprMemnodeT_next_FIELD
  mrb_define_method(mrb, AprMemnodeT_class, "next", mrb_APR_AprMemnodeT_get_next, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMemnodeT_class, "next=", mrb_APR_AprMemnodeT_set_next, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMemnodeT_ref_FIELD
  mrb_define_method(mrb, AprMemnodeT_class, "ref", mrb_APR_AprMemnodeT_get_ref, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMemnodeT_class, "ref=", mrb_APR_AprMemnodeT_set_ref, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMemnodeT_index_FIELD
  mrb_define_method(mrb, AprMemnodeT_class, "index", mrb_APR_AprMemnodeT_get_index, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMemnodeT_class, "index=", mrb_APR_AprMemnodeT_set_index, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMemnodeT_free_index_FIELD
  mrb_define_method(mrb, AprMemnodeT_class, "free_index", mrb_APR_AprMemnodeT_get_free_index, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMemnodeT_class, "free_index=", mrb_APR_AprMemnodeT_set_free_index, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMemnodeT_first_avail_FIELD
  mrb_define_method(mrb, AprMemnodeT_class, "first_avail", mrb_APR_AprMemnodeT_get_first_avail, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMemnodeT_class, "first_avail=", mrb_APR_AprMemnodeT_set_first_avail, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMemnodeT_endp_FIELD
  mrb_define_method(mrb, AprMemnodeT_class, "endp", mrb_APR_AprMemnodeT_get_endp, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMemnodeT_class, "endp=", mrb_APR_AprMemnodeT_set_endp, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
