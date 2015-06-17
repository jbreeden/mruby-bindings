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

#if BIND_AprVformatterBuffT_INITIALIZE
mrb_value
mrb_APR_AprVformatterBuffT_initialize(mrb_state* mrb, mrb_value self) {
  apr_vformatter_buff_t* native_object = (apr_vformatter_buff_t*)malloc(sizeof(apr_vformatter_buff_t));
  mruby_gift_apr_vformatter_buff_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprVformatterBuffT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVformatterBuffT.disown only accepts objects of type APR::AprVformatterBuffT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprVformatterBuffT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprVformatterBuffT.disown only accepts objects of type APR::AprVformatterBuffT");
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

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

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

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

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
  MRB_SET_INSTANCE_TT(AprVformatterBuffT_class, MRB_TT_DATA);

#if BIND_AprVformatterBuffT_INITIALIZE
  mrb_define_method(mrb, AprVformatterBuffT_class, "initialize", mrb_APR_AprVformatterBuffT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprVformatterBuffT_class, "disown", mrb_APR_AprVformatterBuffT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprVformatterBuffT_class, "belongs_to_ruby?", mrb_APR_AprVformatterBuffT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

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
