/*
 * apr_mmap_t
 * Defined in file apr_mmap.h @ line 51
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprMmapT_TYPE

/*
 * Class Methods
 */

#if BIND_AprMmapT_MALLOC
mrb_value
mrb_APR_AprMmapT_malloc(mrb_state* mrb, mrb_value self) {
  apr_mmap_t* native_object = (apr_mmap_t*)malloc(sizeof(apr_mmap_t));
  return mruby_box_apr_mmap_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprMmapT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprMmapT.free can only free objects of type APR::AprMmapT");
    return mrb_nil_value();
  }

  apr_mmap_t * native_to_free = mruby_unbox_apr_mmap_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprMmapT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprMmapT.clear_pointer can only clear objects of type APR::AprMmapT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprMmapT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprMmapT.address_of can only get the address for objects of type APR::AprMmapT");
    return mrb_nil_value();
  }

  apr_mmap_t * native_object = mruby_unbox_apr_mmap_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}

/*
 * Fields
 */

#if BIND_AprMmapT_cntxt_FIELD
/* get_cntxt
 *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_AprMmapT_get_cntxt(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  apr_pool_t * native_field = native_self->cntxt;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@cntxt_box"), ruby_field);

  return ruby_field;
}

/* set_cntxt
 *
 * Parameters:
 * - value: apr_pool_t *
 */
mrb_value
mrb_APR_AprMmapT_set_cntxt(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@cntxt_box"), ruby_field);

  apr_pool_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_pool_t(ruby_field));

  native_self->cntxt = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_mhandle_FIELD
/* get_mhandle
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprMmapT_get_mhandle(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  int native_field = native_self->mhandle;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mhandle_box"), ruby_field);

  return ruby_field;
}

/* set_mhandle
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprMmapT_set_mhandle(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mhandle_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->mhandle = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_mv_FIELD
/* get_mv
 *
 * Return Type: void *
 */
mrb_value
mrb_APR_AprMmapT_get_mv(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  void * native_field = native_self->mv;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mv_box"), ruby_field);

  return ruby_field;
}

/* set_mv
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_APR_AprMmapT_set_mv(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mv_box"), ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->mv = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_pstart_FIELD
/* get_pstart
 *
 * Return Type: apr_off_t
 */
mrb_value
mrb_APR_AprMmapT_get_pstart(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  apr_off_t native_field = native_self->pstart;

  mrb_value ruby_field = TODO_mruby_box_apr_off_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pstart_box"), ruby_field);

  return ruby_field;
}

/* set_pstart
 *
 * Parameters:
 * - value: apr_off_t
 */
mrb_value
mrb_APR_AprMmapT_set_pstart(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pstart_box"), ruby_field);

  apr_off_t native_field = TODO_mruby_unbox_apr_off_t(ruby_field);

  native_self->pstart = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_psize_FIELD
/* get_psize
 *
 * Return Type: apr_size_t
 */
mrb_value
mrb_APR_AprMmapT_get_psize(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  apr_size_t native_field = native_self->psize;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@psize_box"), ruby_field);

  return ruby_field;
}

/* set_psize
 *
 * Parameters:
 * - value: apr_size_t
 */
mrb_value
mrb_APR_AprMmapT_set_psize(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@psize_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->psize = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_poffset_FIELD
/* get_poffset
 *
 * Return Type: apr_off_t
 */
mrb_value
mrb_APR_AprMmapT_get_poffset(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  apr_off_t native_field = native_self->poffset;

  mrb_value ruby_field = TODO_mruby_box_apr_off_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@poffset_box"), ruby_field);

  return ruby_field;
}

/* set_poffset
 *
 * Parameters:
 * - value: apr_off_t
 */
mrb_value
mrb_APR_AprMmapT_set_poffset(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@poffset_box"), ruby_field);

  apr_off_t native_field = TODO_mruby_unbox_apr_off_t(ruby_field);

  native_self->poffset = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_mm_FIELD
/* get_mm
 *
 * Return Type: void *
 */
mrb_value
mrb_APR_AprMmapT_get_mm(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  void * native_field = native_self->mm;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mm_box"), ruby_field);

  return ruby_field;
}

/* set_mm
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_APR_AprMmapT_set_mm(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mm_box"), ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->mm = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_size_FIELD
/* get_size
 *
 * Return Type: apr_size_t
 */
mrb_value
mrb_APR_AprMmapT_get_size(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  apr_size_t native_field = native_self->size;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@size_box"), ruby_field);

  return ruby_field;
}

/* set_size
 *
 * Parameters:
 * - value: apr_size_t
 */
mrb_value
mrb_APR_AprMmapT_set_size(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@size_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->size = native_field;

  return ruby_field;
}
#endif

#if BIND_AprMmapT_link_FIELD
/* get_link
 *
 * Return Type: struct (anonymous struct at C:/projects/mruby-bindings/headers/apr/apr_mmap.h:85:5)
 */
mrb_value
mrb_APR_AprMmapT_get_link(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);

  struct (anonymous struct at C:/projects/mruby-bindings/headers/apr/apr_mmap.h:85:5) native_field = native_self->link;

  mrb_value ruby_field = TODO_mruby_box_struct_LPAREN_anonymous_struct_at_C:/projects/mruby-bindings/headers/apr/apr_mmap.h:85:5_RPAREN(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@link_box"), ruby_field);

  return ruby_field;
}

/* set_link
 *
 * Parameters:
 * - value: struct (anonymous struct at C:/projects/mruby-bindings/headers/apr/apr_mmap.h:85:5)
 */
mrb_value
mrb_APR_AprMmapT_set_link(mrb_state* mrb, mrb_value self) {
  apr_mmap_t * native_self = mruby_unbox_apr_mmap_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@link_box"), ruby_field);

  struct (anonymous struct at C:/projects/mruby-bindings/headers/apr/apr_mmap.h:85:5) native_field = TODO_mruby_unbox_struct_LPAREN_anonymous_struct_at_C:/projects/mruby-bindings/headers/apr/apr_mmap.h:85:5_RPAREN(ruby_field);

  native_self->link = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprMmapT_init(mrb_state* mrb) {
  RClass* AprMmapT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprMmapT", mrb->object_class);

#if BIND_AprMmapT_MALLOC
  mrb_define_class_method(mrb, AprMmapT_class, "malloc", mrb_APR_AprMmapT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprMmapT_class, "free", mrb_APR_AprMmapT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprMmapT_class, "clear_pointer", mrb_APR_AprMmapT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprMmapT_class, "address_of", mrb_APR_AprMmapT_address_of, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprMmapT_cntxt_FIELD
  mrb_define_method(mrb, AprMmapT_class, "cntxt", mrb_APR_AprMmapT_get_cntxt, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "cntxt=", mrb_APR_AprMmapT_set_cntxt, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_mhandle_FIELD
  mrb_define_method(mrb, AprMmapT_class, "mhandle", mrb_APR_AprMmapT_get_mhandle, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "mhandle=", mrb_APR_AprMmapT_set_mhandle, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_mv_FIELD
  mrb_define_method(mrb, AprMmapT_class, "mv", mrb_APR_AprMmapT_get_mv, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "mv=", mrb_APR_AprMmapT_set_mv, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_pstart_FIELD
  mrb_define_method(mrb, AprMmapT_class, "pstart", mrb_APR_AprMmapT_get_pstart, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "pstart=", mrb_APR_AprMmapT_set_pstart, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_psize_FIELD
  mrb_define_method(mrb, AprMmapT_class, "psize", mrb_APR_AprMmapT_get_psize, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "psize=", mrb_APR_AprMmapT_set_psize, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_poffset_FIELD
  mrb_define_method(mrb, AprMmapT_class, "poffset", mrb_APR_AprMmapT_get_poffset, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "poffset=", mrb_APR_AprMmapT_set_poffset, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_mm_FIELD
  mrb_define_method(mrb, AprMmapT_class, "mm", mrb_APR_AprMmapT_get_mm, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "mm=", mrb_APR_AprMmapT_set_mm, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_size_FIELD
  mrb_define_method(mrb, AprMmapT_class, "size", mrb_APR_AprMmapT_get_size, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "size=", mrb_APR_AprMmapT_set_size, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprMmapT_link_FIELD
  mrb_define_method(mrb, AprMmapT_class, "link", mrb_APR_AprMmapT_get_link, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprMmapT_class, "link=", mrb_APR_AprMmapT_set_link, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
