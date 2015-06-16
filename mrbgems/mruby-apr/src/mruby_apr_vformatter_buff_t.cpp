/*
 * apr_vformatter_buff_t
 * Defined in file apr_lib.h @ line 59
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprVformatterBuffT_TYPE

/*
 * Class Methods
 */

#if BIND_AprVformatterBuffT_MALLOC
mrb_value
mrb_APR_AprVformatterBuffT_malloc(mrb_state* mrb, mrb_value self) {
  apr_vformatter_buff_t* native_object = (apr_vformatter_buff_t*)malloc(sizeof(apr_vformatter_buff_t));
  return mruby_box_apr_vformatter_buff_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprVformatterBuffT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVformatterBuffT.free can only free objects of type APR::AprVformatterBuffT");
    return mrb_nil_value();
  }

  apr_vformatter_buff_t * native_to_free = mruby_unbox_apr_vformatter_buff_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprVformatterBuffT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVformatterBuffT.clear_pointer can only clear objects of type APR::AprVformatterBuffT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprVformatterBuffT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVformatterBuffT.address_of can only get the address for objects of type APR::AprVformatterBuffT");
    return mrb_nil_value();
  }

  apr_vformatter_buff_t * native_object = mruby_unbox_apr_vformatter_buff_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}

/*
 * Fields
 */

#if BIND_AprVformatterBuffT_curpos_FIELD
/* get_curpos
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprVformatterBuffT_get_curpos(mrb_state* mrb, mrb_value self) {
  apr_vformatter_buff_t * native_self = mruby_unbox_apr_vformatter_buff_t(self);

  char * native_field = native_self->curpos;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@curpos_box"), ruby_field);

  return ruby_field;
}

/* set_curpos
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprVformatterBuffT_set_curpos(mrb_state* mrb, mrb_value self) {
  apr_vformatter_buff_t * native_self = mruby_unbox_apr_vformatter_buff_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@curpos_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->curpos = native_field;

  return ruby_field;
}
#endif

#if BIND_AprVformatterBuffT_endpos_FIELD
/* get_endpos
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprVformatterBuffT_get_endpos(mrb_state* mrb, mrb_value self) {
  apr_vformatter_buff_t * native_self = mruby_unbox_apr_vformatter_buff_t(self);

  char * native_field = native_self->endpos;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@endpos_box"), ruby_field);

  return ruby_field;
}

/* set_endpos
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprVformatterBuffT_set_endpos(mrb_state* mrb, mrb_value self) {
  apr_vformatter_buff_t * native_self = mruby_unbox_apr_vformatter_buff_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@endpos_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->endpos = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprVformatterBuffT_init(mrb_state* mrb) {
  RClass* AprVformatterBuffT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprVformatterBuffT", mrb->object_class);

#if BIND_AprVformatterBuffT_MALLOC
  mrb_define_class_method(mrb, AprVformatterBuffT_class, "malloc", mrb_APR_AprVformatterBuffT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprVformatterBuffT_class, "free", mrb_APR_AprVformatterBuffT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprVformatterBuffT_class, "clear_pointer", mrb_APR_AprVformatterBuffT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprVformatterBuffT_class, "address_of", mrb_APR_AprVformatterBuffT_address_of, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprVformatterBuffT_curpos_FIELD
  mrb_define_method(mrb, AprVformatterBuffT_class, "curpos", mrb_APR_AprVformatterBuffT_get_curpos, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprVformatterBuffT_class, "curpos=", mrb_APR_AprVformatterBuffT_set_curpos, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprVformatterBuffT_endpos_FIELD
  mrb_define_method(mrb, AprVformatterBuffT_class, "endpos", mrb_APR_AprVformatterBuffT_get_endpos, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprVformatterBuffT_class, "endpos=", mrb_APR_AprVformatterBuffT_set_endpos, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
