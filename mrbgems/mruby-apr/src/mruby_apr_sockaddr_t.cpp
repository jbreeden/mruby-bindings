/*
 * apr_sockaddr_t
 * Defined in file apr_network_io.h @ line 209
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprSockaddrT_TYPE

/*
 * Class Methods
 */

#if BIND_AprSockaddrT_INITIALIZE
mrb_value
mrb_APR_AprSockaddrT_initialize(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t* native_object = (apr_sockaddr_t*)malloc(sizeof(apr_sockaddr_t));
  mruby_gift_apr_sockaddr_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprSockaddrT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprSockaddrT.disown only accepts objects of type APR::AprSockaddrT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprSockaddrT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprSockaddrT.disown only accepts objects of type APR::AprSockaddrT");
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

#if BIND_AprSockaddrT_pool_FIELD
/* get_pool
 *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_AprSockaddrT_get_pool(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

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
mrb_APR_AprSockaddrT_set_pool(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pool_box"), ruby_field);

  apr_pool_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_pool_t(ruby_field));

  native_self->pool = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_hostname_FIELD
/* get_hostname
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprSockaddrT_get_hostname(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  char * native_field = native_self->hostname;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@hostname_box"), ruby_field);

  return ruby_field;
}

/* set_hostname
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprSockaddrT_set_hostname(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@hostname_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->hostname = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_servname_FIELD
/* get_servname
 *
 * Return Type: char *
 */
mrb_value
mrb_APR_AprSockaddrT_get_servname(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  char * native_field = native_self->servname;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@servname_box"), ruby_field);

  return ruby_field;
}

/* set_servname
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_APR_AprSockaddrT_set_servname(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@servname_box"), ruby_field);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->servname = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_port_FIELD
/* get_port
 *
 * Return Type: apr_port_t
 */
mrb_value
mrb_APR_AprSockaddrT_get_port(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  apr_port_t native_field = native_self->port;

  mrb_value ruby_field = TODO_mruby_box_apr_port_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@port_box"), ruby_field);

  return ruby_field;
}

/* set_port
 *
 * Parameters:
 * - value: apr_port_t
 */
mrb_value
mrb_APR_AprSockaddrT_set_port(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_apr_port_t(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@port_box"), ruby_field);

  apr_port_t native_field = TODO_mruby_unbox_apr_port_t(ruby_field);

  native_self->port = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_family_FIELD
/* get_family
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprSockaddrT_get_family(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  apr_int32_t native_field = native_self->family;

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
 * - value: apr_int32_t
 */
mrb_value
mrb_APR_AprSockaddrT_set_family(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
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

#if BIND_AprSockaddrT_salen_FIELD
/* get_salen
 *
 * Return Type: apr_socklen_t
 */
mrb_value
mrb_APR_AprSockaddrT_get_salen(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  apr_socklen_t native_field = native_self->salen;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@salen_box"), ruby_field);

  return ruby_field;
}

/* set_salen
 *
 * Parameters:
 * - value: apr_socklen_t
 */
mrb_value
mrb_APR_AprSockaddrT_set_salen(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@salen_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->salen = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_ipaddr_len_FIELD
/* get_ipaddr_len
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprSockaddrT_get_ipaddr_len(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  int native_field = native_self->ipaddr_len;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ipaddr_len_box"), ruby_field);

  return ruby_field;
}

/* set_ipaddr_len
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprSockaddrT_set_ipaddr_len(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ipaddr_len_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->ipaddr_len = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_addr_str_len_FIELD
/* get_addr_str_len
 *
 * Return Type: int
 */
mrb_value
mrb_APR_AprSockaddrT_get_addr_str_len(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  int native_field = native_self->addr_str_len;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@addr_str_len_box"), ruby_field);

  return ruby_field;
}

/* set_addr_str_len
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_APR_AprSockaddrT_set_addr_str_len(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@addr_str_len_box"), ruby_field);

  int native_field = mrb_fixnum(ruby_field);

  native_self->addr_str_len = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_ipaddr_ptr_FIELD
/* get_ipaddr_ptr
 *
 * Return Type: void *
 */
mrb_value
mrb_APR_AprSockaddrT_get_ipaddr_ptr(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  void * native_field = native_self->ipaddr_ptr;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ipaddr_ptr_box"), ruby_field);

  return ruby_field;
}

/* set_ipaddr_ptr
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_APR_AprSockaddrT_set_ipaddr_ptr(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_PTR(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ipaddr_ptr_box"), ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->ipaddr_ptr = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_next_FIELD
/* get_next
 *
 * Return Type: apr_sockaddr_t *
 */
mrb_value
mrb_APR_AprSockaddrT_get_next(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  apr_sockaddr_t * native_field = native_self->next;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_sockaddr_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@next_box"), ruby_field);

  return ruby_field;
}

/* set_next
 *
 * Parameters:
 * - value: apr_sockaddr_t *
 */
mrb_value
mrb_APR_AprSockaddrT_set_next(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@next_box"), ruby_field);

  apr_sockaddr_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_sockaddr_t(ruby_field));

  native_self->next = native_field;

  return ruby_field;
}
#endif

#if BIND_AprSockaddrT_sa_FIELD
/* get_sa
 *
 * Return Type: union (anonymous union at C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5)
 */
mrb_value
mrb_APR_AprSockaddrT_get_sa(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);

  union (anonymous union at C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5) native_field = native_self->sa;

  mrb_value ruby_field = TODO_mruby_box_union_LPAREN_anonymous_union_at_C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5_RPAREN(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@sa_box"), ruby_field);

  return ruby_field;
}

/* set_sa
 *
 * Parameters:
 * - value: union (anonymous union at C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5)
 */
mrb_value
mrb_APR_AprSockaddrT_set_sa(mrb_state* mrb, mrb_value self) {
  apr_sockaddr_t * native_self = mruby_unbox_apr_sockaddr_t(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_union_LPAREN_anonymous_union_at_C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5_RPAREN(ruby_field);

  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@sa_box"), ruby_field);

  union (anonymous union at C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5) native_field = TODO_mruby_unbox_union_LPAREN_anonymous_union_at_C:/projects/mruby-bindings/headers/apr/apr_network_io.h:238:5_RPAREN(ruby_field);

  native_self->sa = native_field;

  return ruby_field;
}
#endif


void mrb_APR_AprSockaddrT_init(mrb_state* mrb) {
  RClass* AprSockaddrT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprSockaddrT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprSockaddrT_class, MRB_TT_DATA);

#if BIND_AprSockaddrT_INITIALIZE
  mrb_define_method(mrb, AprSockaddrT_class, "initialize", mrb_APR_AprSockaddrT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprSockaddrT_class, "disown", mrb_APR_AprSockaddrT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprSockaddrT_class, "belongs_to_ruby?", mrb_APR_AprSockaddrT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprSockaddrT_pool_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "pool", mrb_APR_AprSockaddrT_get_pool, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "pool=", mrb_APR_AprSockaddrT_set_pool, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_hostname_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "hostname", mrb_APR_AprSockaddrT_get_hostname, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "hostname=", mrb_APR_AprSockaddrT_set_hostname, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_servname_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "servname", mrb_APR_AprSockaddrT_get_servname, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "servname=", mrb_APR_AprSockaddrT_set_servname, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_port_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "port", mrb_APR_AprSockaddrT_get_port, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "port=", mrb_APR_AprSockaddrT_set_port, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_family_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "family", mrb_APR_AprSockaddrT_get_family, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "family=", mrb_APR_AprSockaddrT_set_family, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_salen_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "salen", mrb_APR_AprSockaddrT_get_salen, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "salen=", mrb_APR_AprSockaddrT_set_salen, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_ipaddr_len_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "ipaddr_len", mrb_APR_AprSockaddrT_get_ipaddr_len, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "ipaddr_len=", mrb_APR_AprSockaddrT_set_ipaddr_len, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_addr_str_len_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "addr_str_len", mrb_APR_AprSockaddrT_get_addr_str_len, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "addr_str_len=", mrb_APR_AprSockaddrT_set_addr_str_len, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_ipaddr_ptr_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "ipaddr_ptr", mrb_APR_AprSockaddrT_get_ipaddr_ptr, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "ipaddr_ptr=", mrb_APR_AprSockaddrT_set_ipaddr_ptr, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_next_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "next", mrb_APR_AprSockaddrT_get_next, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "next=", mrb_APR_AprSockaddrT_set_next, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprSockaddrT_sa_FIELD
  mrb_define_method(mrb, AprSockaddrT_class, "sa", mrb_APR_AprSockaddrT_get_sa, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, AprSockaddrT_class, "sa=", mrb_APR_AprSockaddrT_set_sa, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
