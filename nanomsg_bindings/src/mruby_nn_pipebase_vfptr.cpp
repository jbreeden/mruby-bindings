/*
 * nn_pipebase_vfptr
 * Defined in file transport.h @ line 157
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnPipebaseVfptr_TYPE

/*
 * Class Methods
 */

#if BIND_NnPipebaseVfptr_INITIALIZE
mrb_value
mrb_NN_NnPipebaseVfptr_initialize(mrb_state* mrb, mrb_value self) {
  nn_pipebase_vfptr* native_object = (nn_pipebase_vfptr*)malloc(sizeof(nn_pipebase_vfptr));
  mruby_gift_nn_pipebase_vfptr_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnPipebaseVfptr_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPipebaseVfptr.disown only accepts objects of type NN::NnPipebaseVfptr");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnPipebaseVfptr_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPipebaseVfptr.disown only accepts objects of type NN::NnPipebaseVfptr");
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

#if BIND_NnPipebaseVfptr_send_FIELD
/* get_send
 *
 * Return Type: int (*)(struct nn_pipebase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnPipebaseVfptr_get_send(mrb_state* mrb, mrb_value self) {
  nn_pipebase_vfptr * native_self = mruby_unbox_nn_pipebase_vfptr(self);

  int (*)(struct nn_pipebase *, struct nn_msg *) native_field = native_self->send;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_pipebase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_send
 *
 * Parameters:
 * - value: int (*)(struct nn_pipebase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnPipebaseVfptr_set_send(mrb_state* mrb, mrb_value self) {
  nn_pipebase_vfptr * native_self = mruby_unbox_nn_pipebase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_pipebase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_pipebase *, struct nn_msg *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_pipebase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  native_self->send = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebaseVfptr_recv_FIELD
/* get_recv
 *
 * Return Type: int (*)(struct nn_pipebase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnPipebaseVfptr_get_recv(mrb_state* mrb, mrb_value self) {
  nn_pipebase_vfptr * native_self = mruby_unbox_nn_pipebase_vfptr(self);

  int (*)(struct nn_pipebase *, struct nn_msg *) native_field = native_self->recv;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_pipebase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_recv
 *
 * Parameters:
 * - value: int (*)(struct nn_pipebase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnPipebaseVfptr_set_recv(mrb_state* mrb, mrb_value self) {
  nn_pipebase_vfptr * native_self = mruby_unbox_nn_pipebase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_pipebase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_pipebase *, struct nn_msg *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_pipebase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  native_self->recv = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnPipebaseVfptr_init(mrb_state* mrb) {
  RClass* NnPipebaseVfptr_class = mrb_define_class_under(mrb, NN_module(mrb), "NnPipebaseVfptr", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnPipebaseVfptr_class, MRB_TT_DATA);

#if BIND_NnPipebaseVfptr_INITIALIZE
  mrb_define_method(mrb, NnPipebaseVfptr_class, "initialize", mrb_NN_NnPipebaseVfptr_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnPipebaseVfptr_class, "disown", mrb_NN_NnPipebaseVfptr_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnPipebaseVfptr_class, "belongs_to_ruby?", mrb_NN_NnPipebaseVfptr_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnPipebaseVfptr_send_FIELD
  mrb_define_method(mrb, NnPipebaseVfptr_class, "send", mrb_NN_NnPipebaseVfptr_get_send, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebaseVfptr_class, "send=", mrb_NN_NnPipebaseVfptr_set_send, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebaseVfptr_recv_FIELD
  mrb_define_method(mrb, NnPipebaseVfptr_class, "recv", mrb_NN_NnPipebaseVfptr_get_recv, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebaseVfptr_class, "recv=", mrb_NN_NnPipebaseVfptr_set_recv, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
