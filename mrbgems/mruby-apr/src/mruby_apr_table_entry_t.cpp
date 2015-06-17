/*
 * apr_table_entry_t
 * Defined in file apr_tables.h @ line 78
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprTableEntryT_TYPE

/*
 * Class Methods
 */

#if BIND_AprTableEntryT_INITIALIZE
mrb_value
mrb_APR_AprTableEntryT_initialize(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t* native_object = (apr_table_entry_t*)malloc(sizeof(apr_table_entry_t));
  mruby_gift_apr_table_entry_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprTableEntryT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprTableEntryT.disown only accepts objects of type APR::AprTableEntryT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprTableEntryT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprTableEntryT.disown only accepts objects of type APR::AprTableEntryT");
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

#if BIND_AprTableEntryT_key_FIELD
/* get_key
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprTableEntryT_get_key(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t * native_self = mruby_unbox_apr_table_entry_t(self);

  char * native_field = native_self->key;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@key_box"), ruby_field);

  return ruby_field;
}

/* set_key
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprTableEntryT_set_key(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t * native_self = mruby_unbox_apr_table_entry_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@key_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->key = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTableEntryT_val_FIELD
/* get_val
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprTableEntryT_get_val(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t * native_self = mruby_unbox_apr_table_entry_t(self);

  char * native_field = native_self->val;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@val_box"), ruby_field);

  return ruby_field;
}

/* set_val
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprTableEntryT_set_val(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t * native_self = mruby_unbox_apr_table_entry_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@val_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->val = native_field;

  return ruby_field;
}
#endif

#if BIND_AprTableEntryT_key_checksum_FIELD
/* get_key_checksum
 *
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_AprTableEntryT_get_key_checksum(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t * native_self = mruby_unbox_apr_table_entry_t(self);

  apr_uint32_t native_field = native_self->key_checksum;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@key_checksum_box"), ruby_field);

  return ruby_field;
}

/* set_key_checksum
 *
 * Parameters:
 * - value: apr_uint32_t
 */
mrb_value
mrb_APR_AprTableEntryT_set_key_checksum(mrb_state* mrb, mrb_value self) {
  apr_table_entry_t * native_self = mruby_unbox_apr_table_entry_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@key_checksum_box"), ruby_field);

  unsigned int native_field = mrb_fixnum(ruby_field);

  native_self->key_checksum = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprTableEntryT_init(mrb_state* mrb) {
  RClass* AprTableEntryT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprTableEntryT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprTableEntryT_class, MRB_TT_DATA);

#if BIND_AprTableEntryT_INITIALIZE
  mrb_define_method(mrb, AprTableEntryT_class, "initialize", mrb_APR_AprTableEntryT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprTableEntryT_class, "disown", mrb_APR_AprTableEntryT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprTableEntryT_class, "belongs_to_ruby?", mrb_APR_AprTableEntryT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprTableEntryT_key_FIELD
  mrb_define_method(mrb, AprTableEntryT_class, "key", mrb_APR_AprTableEntryT_get_key, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTableEntryT_class, "key=", mrb_APR_AprTableEntryT_set_key, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTableEntryT_val_FIELD
  mrb_define_method(mrb, AprTableEntryT_class, "val", mrb_APR_AprTableEntryT_get_val, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTableEntryT_class, "val=", mrb_APR_AprTableEntryT_set_val, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprTableEntryT_key_checksum_FIELD
  mrb_define_method(mrb, AprTableEntryT_class, "key_checksum", mrb_APR_AprTableEntryT_get_key_checksum, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprTableEntryT_class, "key_checksum=", mrb_APR_AprTableEntryT_set_key_checksum, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
