/*
 * nn_socktype
 * Defined in file protocol.h @ line 171
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnSocktype_TYPE

/*
 * Class Methods
 */

#if BIND_NnSocktype_INITIALIZE
mrb_value
mrb_NN_NnSocktype_initialize(mrb_state* mrb, mrb_value self) {
  nn_socktype* native_object = (nn_socktype*)malloc(sizeof(nn_socktype));
  mruby_gift_nn_socktype_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnSocktype_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSocktype.disown only accepts objects of type NN::NnSocktype");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnSocktype_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSocktype.disown only accepts objects of type NN::NnSocktype");
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

#if BIND_NnSocktype_domain_FIELD
/* get_domain
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSocktype_get_domain(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);

  int native_field = native_self->domain;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_domain
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSocktype_set_domain(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->domain = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSocktype_protocol_FIELD
/* get_protocol
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSocktype_get_protocol(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);

  int native_field = native_self->protocol;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_protocol
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSocktype_set_protocol(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->protocol = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSocktype_flags_FIELD
/* get_flags
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnSocktype_get_flags(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);

  int native_field = native_self->flags;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_flags
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnSocktype_set_flags(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->flags = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSocktype_create_FIELD
/* get_create
 *
 * Return Type: int (*)(void *, struct nn_sockbase **)
 */
mrb_value
mrb_NN_NnSocktype_get_create(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);

  int (*)(void *, struct nn_sockbase **) native_field = native_self->create;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_sockbase_PTR_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_create
 *
 * Parameters:
 * - value: int (*)(void *, struct nn_sockbase **)
 */
mrb_value
mrb_NN_NnSocktype_set_create(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_sockbase_PTR_PTR_RPAREN(ruby_field);

  int (*native_field)(void *, struct nn_sockbase **) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_sockbase_PTR_PTR_RPAREN(ruby_field);

  native_self->create = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSocktype_ispeer_FIELD
/* get_ispeer
 *
 * Return Type: int (*)(int)
 */
mrb_value
mrb_NN_NnSocktype_get_ispeer(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);

  int (*)(int) native_field = native_self->ispeer;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_ispeer
 *
 * Parameters:
 * - value: int (*)(int)
 */
mrb_value
mrb_NN_NnSocktype_set_ispeer(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(ruby_field);

  int (*native_field)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(ruby_field);

  native_self->ispeer = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSocktype_item_FIELD
/* get_item
 *
 * Return Type: struct nn_list_item
 */
mrb_value
mrb_NN_NnSocktype_get_item(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);

  struct nn_list_item native_field = native_self->item;

  mrb_value ruby_field = TODO_mruby_box_struct_nn_list_item(mrb, native_field);

  return ruby_field;
}

/* set_item
 *
 * Parameters:
 * - value: struct nn_list_item
 */
mrb_value
mrb_NN_NnSocktype_set_item(mrb_state* mrb, mrb_value self) {
  nn_socktype * native_self = mruby_unbox_nn_socktype(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_nn_list_item(ruby_field);

  struct nn_list_item native_field = TODO_mruby_unbox_struct_nn_list_item(ruby_field);

  native_self->item = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnSocktype_init(mrb_state* mrb) {
  RClass* NnSocktype_class = mrb_define_class_under(mrb, NN_module(mrb), "NnSocktype", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnSocktype_class, MRB_TT_DATA);

#if BIND_NnSocktype_INITIALIZE
  mrb_define_method(mrb, NnSocktype_class, "initialize", mrb_NN_NnSocktype_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnSocktype_class, "disown", mrb_NN_NnSocktype_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnSocktype_class, "belongs_to_ruby?", mrb_NN_NnSocktype_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnSocktype_domain_FIELD
  mrb_define_method(mrb, NnSocktype_class, "domain", mrb_NN_NnSocktype_get_domain, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSocktype_class, "domain=", mrb_NN_NnSocktype_set_domain, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSocktype_protocol_FIELD
  mrb_define_method(mrb, NnSocktype_class, "protocol", mrb_NN_NnSocktype_get_protocol, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSocktype_class, "protocol=", mrb_NN_NnSocktype_set_protocol, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSocktype_flags_FIELD
  mrb_define_method(mrb, NnSocktype_class, "flags", mrb_NN_NnSocktype_get_flags, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSocktype_class, "flags=", mrb_NN_NnSocktype_set_flags, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSocktype_create_FIELD
  mrb_define_method(mrb, NnSocktype_class, "create", mrb_NN_NnSocktype_get_create, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSocktype_class, "create=", mrb_NN_NnSocktype_set_create, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSocktype_ispeer_FIELD
  mrb_define_method(mrb, NnSocktype_class, "ispeer", mrb_NN_NnSocktype_get_ispeer, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSocktype_class, "ispeer=", mrb_NN_NnSocktype_set_ispeer, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSocktype_item_FIELD
  mrb_define_method(mrb, NnSocktype_class, "item", mrb_NN_NnSocktype_get_item, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSocktype_class, "item=", mrb_NN_NnSocktype_set_item, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
