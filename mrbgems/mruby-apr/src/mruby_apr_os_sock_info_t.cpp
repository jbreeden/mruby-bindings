/*
 * apr_os_sock_info_t
 * Defined in file apr_portable.h @ line 183
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprOsSockInfoT_TYPE

/*
 * Class Methods
 */

#if BIND_AprOsSockInfoT_INITIALIZE
mrb_value
mrb_APR_AprOsSockInfoT_initialize(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t* native_object = (apr_os_sock_info_t*)malloc(sizeof(apr_os_sock_info_t));
  mruby_gift_apr_os_sock_info_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprOsSockInfoT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprOsSockInfoT.disown only accepts objects of type APR::AprOsSockInfoT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprOsSockInfoT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprOsSockInfoT.disown only accepts objects of type APR::AprOsSockInfoT");
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

#if BIND_AprOsSockInfoT_os_sock_FIELD
/* get_os_sock
 *
 * Return Type: apr_os_sock_t *
 */
mrb_value
mrb_APR_AprOsSockInfoT_get_os_sock(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);

  apr_os_sock_t * native_field = native_self->os_sock;

  mrb_value ruby_field = TODO_mruby_box_apr_os_sock_t_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@os_sock_box"), ruby_field);

  return ruby_field;
}

/* set_os_sock
 *
 * Parameters:
 * - value: apr_os_sock_t *
 */
mrb_value
mrb_APR_AprOsSockInfoT_set_os_sock(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_os_sock_t_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@os_sock_box"), ruby_field);

  apr_os_sock_t * native_field = TODO_mruby_unbox_apr_os_sock_t_PTR(ruby_field);

  native_self->os_sock = native_field;

  return ruby_field;
}
#endif

#if BIND_AprOsSockInfoT_local_FIELD
/* get_local
 *
 * Return Type: struct sockaddr *
 */
mrb_value
mrb_APR_AprOsSockInfoT_get_local(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);

  struct sockaddr * native_field = native_self->local;

  mrb_value ruby_field = TODO_mruby_box_struct_sockaddr_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@local_box"), ruby_field);

  return ruby_field;
}

/* set_local
 *
 * Parameters:
 * - value: struct sockaddr *
 */
mrb_value
mrb_APR_AprOsSockInfoT_set_local(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_sockaddr_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@local_box"), ruby_field);

  struct sockaddr * native_field = TODO_mruby_unbox_struct_sockaddr_PTR(ruby_field);

  native_self->local = native_field;

  return ruby_field;
}
#endif

#if BIND_AprOsSockInfoT_remote_FIELD
/* get_remote
 *
 * Return Type: struct sockaddr *
 */
mrb_value
mrb_APR_AprOsSockInfoT_get_remote(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);

  struct sockaddr * native_field = native_self->remote;

  mrb_value ruby_field = TODO_mruby_box_struct_sockaddr_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@remote_box"), ruby_field);

  return ruby_field;
}

/* set_remote
 *
 * Parameters:
 * - value: struct sockaddr *
 */
mrb_value
mrb_APR_AprOsSockInfoT_set_remote(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_sockaddr_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@remote_box"), ruby_field);

  struct sockaddr * native_field = TODO_mruby_unbox_struct_sockaddr_PTR(ruby_field);

  native_self->remote = native_field;

  return ruby_field;
}
#endif

#if BIND_AprOsSockInfoT_family_FIELD
/* get_family
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprOsSockInfoT_get_family(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);

  int native_field = native_self->family;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@family_box"), ruby_field);

  return ruby_field;
}

/* set_family
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprOsSockInfoT_set_family(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@family_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->family = native_field;

  return ruby_field;
}
#endif

#if BIND_AprOsSockInfoT_type_FIELD
/* get_type
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprOsSockInfoT_get_type(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);

  int native_field = native_self->type;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@type_box"), ruby_field);

  return ruby_field;
}

/* set_type
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprOsSockInfoT_set_type(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@type_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->type = native_field;

  return ruby_field;
}
#endif

#if BIND_AprOsSockInfoT_protocol_FIELD
/* get_protocol
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprOsSockInfoT_get_protocol(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);

  int native_field = native_self->protocol;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@protocol_box"), ruby_field);

  return ruby_field;
}

/* set_protocol
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprOsSockInfoT_set_protocol(mrb_state* mrb, mrb_value self) {
  apr_os_sock_info_t * native_self = mruby_unbox_apr_os_sock_info_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@protocol_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->protocol = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprOsSockInfoT_init(mrb_state* mrb) {
  RClass* AprOsSockInfoT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprOsSockInfoT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprOsSockInfoT_class, MRB_TT_DATA);

#if BIND_AprOsSockInfoT_INITIALIZE
  mrb_define_method(mrb, AprOsSockInfoT_class, "initialize", mrb_APR_AprOsSockInfoT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprOsSockInfoT_class, "disown", mrb_APR_AprOsSockInfoT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprOsSockInfoT_class, "belongs_to_ruby?", mrb_APR_AprOsSockInfoT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprOsSockInfoT_os_sock_FIELD
  mrb_define_method(mrb, AprOsSockInfoT_class, "os_sock", mrb_APR_AprOsSockInfoT_get_os_sock, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprOsSockInfoT_class, "os_sock=", mrb_APR_AprOsSockInfoT_set_os_sock, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprOsSockInfoT_local_FIELD
  mrb_define_method(mrb, AprOsSockInfoT_class, "local", mrb_APR_AprOsSockInfoT_get_local, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprOsSockInfoT_class, "local=", mrb_APR_AprOsSockInfoT_set_local, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprOsSockInfoT_remote_FIELD
  mrb_define_method(mrb, AprOsSockInfoT_class, "remote", mrb_APR_AprOsSockInfoT_get_remote, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprOsSockInfoT_class, "remote=", mrb_APR_AprOsSockInfoT_set_remote, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprOsSockInfoT_family_FIELD
  mrb_define_method(mrb, AprOsSockInfoT_class, "family", mrb_APR_AprOsSockInfoT_get_family, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprOsSockInfoT_class, "family=", mrb_APR_AprOsSockInfoT_set_family, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprOsSockInfoT_type_FIELD
  mrb_define_method(mrb, AprOsSockInfoT_class, "type", mrb_APR_AprOsSockInfoT_get_type, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprOsSockInfoT_class, "type=", mrb_APR_AprOsSockInfoT_set_type, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprOsSockInfoT_protocol_FIELD
  mrb_define_method(mrb, AprOsSockInfoT_class, "protocol", mrb_APR_AprOsSockInfoT_get_protocol, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprOsSockInfoT_class, "protocol=", mrb_APR_AprOsSockInfoT_set_protocol, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
