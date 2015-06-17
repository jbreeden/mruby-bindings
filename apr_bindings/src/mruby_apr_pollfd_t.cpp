/*
 * apr_pollfd_t
 * Defined in file apr_poll.h @ line 105
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprPollfdT_TYPE

/*
 * Class Methods
 */

#if BIND_AprPollfdT_INITIALIZE
mrb_value
mrb_APR_AprPollfdT_initialize(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t* native_object = (apr_pollfd_t*)malloc(sizeof(apr_pollfd_t));
  mruby_gift_apr_pollfd_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprPollfdT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprPollfdT.disown only accepts objects of type APR::AprPollfdT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprPollfdT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprPollfdT.disown only accepts objects of type APR::AprPollfdT");
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

#if BIND_AprPollfdT_p_FIELD
/* get_p
 *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_AprPollfdT_get_p(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);

  apr_pool_t * native_field = native_self->p;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@p_box"), ruby_field);

  return ruby_field;
}

/* set_p
 *
 * Parameters:
 * - value: apr_pool_t *
 */
mrb_value
mrb_APR_AprPollfdT_set_p(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@p_box"), ruby_field);

  apr_pool_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_pool_t(ruby_field));

  native_self->p = native_field;

  return ruby_field;
}
#endif

#if BIND_AprPollfdT_desc_type_FIELD
/* get_desc_type
 *
 * Return Type: apr_datatype_e
 */
mrb_value
mrb_APR_AprPollfdT_get_desc_type(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);

  apr_datatype_e native_field = native_self->desc_type;

  mrb_value ruby_field = TODO_mruby_box_apr_datatype_e(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@desc_type_box"), ruby_field);

  return ruby_field;
}

/* set_desc_type
 *
 * Parameters:
 * - value: apr_datatype_e
 */
mrb_value
mrb_APR_AprPollfdT_set_desc_type(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_datatype_e(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@desc_type_box"), ruby_field);

  apr_datatype_e native_field = TODO_mruby_unbox_apr_datatype_e(ruby_field);

  native_self->desc_type = native_field;

  return ruby_field;
}
#endif

#if BIND_AprPollfdT_reqevents_FIELD
/* get_reqevents
 *
 * Return Type: apr_int16_t
 */
mrb_value
mrb_APR_AprPollfdT_get_reqevents(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);

  apr_int16_t native_field = native_self->reqevents;

  mrb_value ruby_field = TODO_mruby_box_apr_int16_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@reqevents_box"), ruby_field);

  return ruby_field;
}

/* set_reqevents
 *
 * Parameters:
 * - value: apr_int16_t
 */
mrb_value
mrb_APR_AprPollfdT_set_reqevents(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_int16_t(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@reqevents_box"), ruby_field);

  apr_int16_t native_field = TODO_mruby_unbox_apr_int16_t(ruby_field);

  native_self->reqevents = native_field;

  return ruby_field;
}
#endif

#if BIND_AprPollfdT_rtnevents_FIELD
/* get_rtnevents
 *
 * Return Type: apr_int16_t
 */
mrb_value
mrb_APR_AprPollfdT_get_rtnevents(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);

  apr_int16_t native_field = native_self->rtnevents;

  mrb_value ruby_field = TODO_mruby_box_apr_int16_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@rtnevents_box"), ruby_field);

  return ruby_field;
}

/* set_rtnevents
 *
 * Parameters:
 * - value: apr_int16_t
 */
mrb_value
mrb_APR_AprPollfdT_set_rtnevents(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_int16_t(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@rtnevents_box"), ruby_field);

  apr_int16_t native_field = TODO_mruby_unbox_apr_int16_t(ruby_field);

  native_self->rtnevents = native_field;

  return ruby_field;
}
#endif

#if BIND_AprPollfdT_desc_FIELD
/* get_desc
 *
 * Return Type: apr_descriptor
 */
mrb_value
mrb_APR_AprPollfdT_get_desc(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);

  apr_descriptor native_field = native_self->desc;

  mrb_value ruby_field = TODO_mruby_box_apr_descriptor(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@desc_box"), ruby_field);

  return ruby_field;
}

/* set_desc
 *
 * Parameters:
 * - value: apr_descriptor
 */
mrb_value
mrb_APR_AprPollfdT_set_desc(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_descriptor(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@desc_box"), ruby_field);

  apr_descriptor native_field = TODO_mruby_unbox_apr_descriptor(ruby_field);

  native_self->desc = native_field;

  return ruby_field;
}
#endif

#if BIND_AprPollfdT_client_data_FIELD
/* get_client_data
 *
 * Return Type: void *
 */
mrb_value
mrb_APR_AprPollfdT_get_client_data(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);

  void * native_field = native_self->client_data;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@client_data_box"), ruby_field);

  return ruby_field;
}

/* set_client_data
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_APR_AprPollfdT_set_client_data(mrb_state* mrb, mrb_value self) {
  apr_pollfd_t * native_self = mruby_unbox_apr_pollfd_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@client_data_box"), ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->client_data = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprPollfdT_init(mrb_state* mrb) {
  RClass* AprPollfdT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprPollfdT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprPollfdT_class, MRB_TT_DATA);

#if BIND_AprPollfdT_INITIALIZE
  mrb_define_method(mrb, AprPollfdT_class, "initialize", mrb_APR_AprPollfdT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprPollfdT_class, "disown", mrb_APR_AprPollfdT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprPollfdT_class, "belongs_to_ruby?", mrb_APR_AprPollfdT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprPollfdT_p_FIELD
  mrb_define_method(mrb, AprPollfdT_class, "p", mrb_APR_AprPollfdT_get_p, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprPollfdT_class, "p=", mrb_APR_AprPollfdT_set_p, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprPollfdT_desc_type_FIELD
  mrb_define_method(mrb, AprPollfdT_class, "desc_type", mrb_APR_AprPollfdT_get_desc_type, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprPollfdT_class, "desc_type=", mrb_APR_AprPollfdT_set_desc_type, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprPollfdT_reqevents_FIELD
  mrb_define_method(mrb, AprPollfdT_class, "reqevents", mrb_APR_AprPollfdT_get_reqevents, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprPollfdT_class, "reqevents=", mrb_APR_AprPollfdT_set_reqevents, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprPollfdT_rtnevents_FIELD
  mrb_define_method(mrb, AprPollfdT_class, "rtnevents", mrb_APR_AprPollfdT_get_rtnevents, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprPollfdT_class, "rtnevents=", mrb_APR_AprPollfdT_set_rtnevents, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprPollfdT_desc_FIELD
  mrb_define_method(mrb, AprPollfdT_class, "desc", mrb_APR_AprPollfdT_get_desc, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprPollfdT_class, "desc=", mrb_APR_AprPollfdT_set_desc, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprPollfdT_client_data_FIELD
  mrb_define_method(mrb, AprPollfdT_class, "client_data", mrb_APR_AprPollfdT_get_client_data, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprPollfdT_class, "client_data=", mrb_APR_AprPollfdT_set_client_data, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
