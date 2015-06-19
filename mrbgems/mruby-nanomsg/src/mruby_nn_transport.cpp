/*
 * nn_transport
 * Defined in file transport.h @ line 222
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnTransport_TYPE

/*
 * Class Methods
 */

#if BIND_NnTransport_INITIALIZE
mrb_value
mrb_NN_NnTransport_initialize(mrb_state* mrb, mrb_value self) {
  nn_transport* native_object = (nn_transport*)malloc(sizeof(nn_transport));
  mruby_gift_nn_transport_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnTransport_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnTransport.disown only accepts objects of type NN::NnTransport");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnTransport_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnTransport.disown only accepts objects of type NN::NnTransport");
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

#if BIND_NnTransport_name_FIELD
/* get_name
 *
 * Return Type: const char *
 */
mrb_value
mrb_NN_NnTransport_get_name(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  const char * native_field = native_self->name;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_name
 *
 * Parameters:
 * - value: const char *
 */
mrb_value
mrb_NN_NnTransport_set_name(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);

  native_self->name = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_id_FIELD
/* get_id
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnTransport_get_id(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  int native_field = native_self->id;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_id
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnTransport_set_id(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->id = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_init_FIELD
/* get_init
 *
 * Return Type: void (*)()
 */
mrb_value
mrb_NN_NnTransport_get_init(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  void (*)() native_field = native_self->init;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_init
 *
 * Parameters:
 * - value: void (*)()
 */
mrb_value
mrb_NN_NnTransport_set_init(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(ruby_field);

  void (*native_field)() = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(ruby_field);

  native_self->init = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_term_FIELD
/* get_term
 *
 * Return Type: void (*)()
 */
mrb_value
mrb_NN_NnTransport_get_term(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  void (*)() native_field = native_self->term;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_term
 *
 * Parameters:
 * - value: void (*)()
 */
mrb_value
mrb_NN_NnTransport_set_term(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(ruby_field);

  void (*native_field)() = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(ruby_field);

  native_self->term = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_bind_FIELD
/* get_bind
 *
 * Return Type: int (*)(void *, struct nn_epbase **)
 */
mrb_value
mrb_NN_NnTransport_get_bind(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  int (*)(void *, struct nn_epbase **) native_field = native_self->bind;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_epbase_PTR_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_bind
 *
 * Parameters:
 * - value: int (*)(void *, struct nn_epbase **)
 */
mrb_value
mrb_NN_NnTransport_set_bind(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_epbase_PTR_PTR_RPAREN(ruby_field);

  int (*native_field)(void *, struct nn_epbase **) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_epbase_PTR_PTR_RPAREN(ruby_field);

  native_self->bind = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_connect_FIELD
/* get_connect
 *
 * Return Type: int (*)(void *, struct nn_epbase **)
 */
mrb_value
mrb_NN_NnTransport_get_connect(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  int (*)(void *, struct nn_epbase **) native_field = native_self->connect;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_epbase_PTR_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_connect
 *
 * Parameters:
 * - value: int (*)(void *, struct nn_epbase **)
 */
mrb_value
mrb_NN_NnTransport_set_connect(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_epbase_PTR_PTR_RPAREN(ruby_field);

  int (*native_field)(void *, struct nn_epbase **) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_struct_nn_epbase_PTR_PTR_RPAREN(ruby_field);

  native_self->connect = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_optset_FIELD
/* get_optset
 *
 * Return Type: struct nn_optset *(*)()
 */
mrb_value
mrb_NN_NnTransport_get_optset(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

  struct nn_optset *(*)() native_field = native_self->optset;

  mrb_value ruby_field = TODO_mruby_box_struct_nn_optset_PTR_LPAREN_PTR_RPAREN_LPAREN_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_optset
 *
 * Parameters:
 * - value: struct nn_optset *(*)()
 */
mrb_value
mrb_NN_NnTransport_set_optset(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_nn_optset_PTR_LPAREN_PTR_RPAREN_LPAREN_RPAREN(ruby_field);

  struct nn_optset *(*native_field)() = TODO_mruby_unbox_struct_nn_optset_PTR_LPAREN_PTR_RPAREN_LPAREN_RPAREN(ruby_field);

  native_self->optset = native_field;

  return ruby_field;
}
#endif

#if BIND_NnTransport_item_FIELD
/* get_item
 *
 * Return Type: struct nn_list_item
 */
mrb_value
mrb_NN_NnTransport_get_item(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);

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
mrb_NN_NnTransport_set_item(mrb_state* mrb, mrb_value self) {
  nn_transport * native_self = mruby_unbox_nn_transport(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_nn_list_item(ruby_field);

  struct nn_list_item native_field = TODO_mruby_unbox_struct_nn_list_item(ruby_field);

  native_self->item = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnTransport_init(mrb_state* mrb) {
  RClass* NnTransport_class = mrb_define_class_under(mrb, NN_module(mrb), "NnTransport", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnTransport_class, MRB_TT_DATA);

#if BIND_NnTransport_INITIALIZE
  mrb_define_method(mrb, NnTransport_class, "initialize", mrb_NN_NnTransport_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnTransport_class, "disown", mrb_NN_NnTransport_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnTransport_class, "belongs_to_ruby?", mrb_NN_NnTransport_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnTransport_name_FIELD
  mrb_define_method(mrb, NnTransport_class, "name", mrb_NN_NnTransport_get_name, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "name=", mrb_NN_NnTransport_set_name, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_id_FIELD
  mrb_define_method(mrb, NnTransport_class, "id", mrb_NN_NnTransport_get_id, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "id=", mrb_NN_NnTransport_set_id, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_init_FIELD
  mrb_define_method(mrb, NnTransport_class, "init", mrb_NN_NnTransport_get_init, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "init=", mrb_NN_NnTransport_set_init, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_term_FIELD
  mrb_define_method(mrb, NnTransport_class, "term", mrb_NN_NnTransport_get_term, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "term=", mrb_NN_NnTransport_set_term, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_bind_FIELD
  mrb_define_method(mrb, NnTransport_class, "bind", mrb_NN_NnTransport_get_bind, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "bind=", mrb_NN_NnTransport_set_bind, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_connect_FIELD
  mrb_define_method(mrb, NnTransport_class, "connect", mrb_NN_NnTransport_get_connect, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "connect=", mrb_NN_NnTransport_set_connect, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_optset_FIELD
  mrb_define_method(mrb, NnTransport_class, "optset", mrb_NN_NnTransport_get_optset, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "optset=", mrb_NN_NnTransport_set_optset, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnTransport_item_FIELD
  mrb_define_method(mrb, NnTransport_class, "item", mrb_NN_NnTransport_get_item, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnTransport_class, "item=", mrb_NN_NnTransport_set_item, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
