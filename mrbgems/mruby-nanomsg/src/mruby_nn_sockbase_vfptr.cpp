/*
 * nn_sockbase_vfptr
 * Defined in file protocol.h @ line 89
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnSockbaseVfptr_TYPE

/*
 * Class Methods
 */

#if BIND_NnSockbaseVfptr_INITIALIZE
mrb_value
mrb_NN_NnSockbaseVfptr_initialize(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr* native_object = (nn_sockbase_vfptr*)malloc(sizeof(nn_sockbase_vfptr));
  mruby_gift_nn_sockbase_vfptr_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnSockbaseVfptr_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSockbaseVfptr.disown only accepts objects of type NN::NnSockbaseVfptr");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnSockbaseVfptr_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSockbaseVfptr.disown only accepts objects of type NN::NnSockbaseVfptr");
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

#if BIND_NnSockbaseVfptr_stop_FIELD
/* get_stop
 *
 * Return Type: void (*)(struct nn_sockbase *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_stop(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  void (*)(struct nn_sockbase *) native_field = native_self->stop;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_stop
 *
 * Parameters:
 * - value: void (*)(struct nn_sockbase *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_stop(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_sockbase *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(ruby_field);

  native_self->stop = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_destroy_FIELD
/* get_destroy
 *
 * Return Type: void (*)(struct nn_sockbase *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_destroy(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  void (*)(struct nn_sockbase *) native_field = native_self->destroy;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_destroy
 *
 * Parameters:
 * - value: void (*)(struct nn_sockbase *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_destroy(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_sockbase *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(ruby_field);

  native_self->destroy = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_add_FIELD
/* get_add
 *
 * Return Type: int (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_add(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  int (*)(struct nn_sockbase *, struct nn_pipe *) native_field = native_self->add;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_add
 *
 * Parameters:
 * - value: int (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_add(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_sockbase *, struct nn_pipe *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  native_self->add = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_rm_FIELD
/* get_rm
 *
 * Return Type: void (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_rm(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  void (*)(struct nn_sockbase *, struct nn_pipe *) native_field = native_self->rm;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_rm
 *
 * Parameters:
 * - value: void (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_rm(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_sockbase *, struct nn_pipe *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  native_self->rm = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_in_FIELD
/* get_in
 *
 * Return Type: void (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_in(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  void (*)(struct nn_sockbase *, struct nn_pipe *) native_field = native_self->in;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_in
 *
 * Parameters:
 * - value: void (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_in(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_sockbase *, struct nn_pipe *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  native_self->in = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_out_FIELD
/* get_out
 *
 * Return Type: void (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_out(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  void (*)(struct nn_sockbase *, struct nn_pipe *) native_field = native_self->out;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_out
 *
 * Parameters:
 * - value: void (*)(struct nn_sockbase *, struct nn_pipe *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_out(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_sockbase *, struct nn_pipe *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_pipe_PTR_RPAREN(ruby_field);

  native_self->out = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_events_FIELD
/* get_events
 *
 * Return Type: int (*)(struct nn_sockbase *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_events(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  int (*)(struct nn_sockbase *) native_field = native_self->events;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_events
 *
 * Parameters:
 * - value: int (*)(struct nn_sockbase *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_events(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_sockbase *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_RPAREN(ruby_field);

  native_self->events = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_send_FIELD
/* get_send
 *
 * Return Type: int (*)(struct nn_sockbase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_send(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  int (*)(struct nn_sockbase *, struct nn_msg *) native_field = native_self->send;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_send
 *
 * Parameters:
 * - value: int (*)(struct nn_sockbase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_send(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_sockbase *, struct nn_msg *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  native_self->send = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_recv_FIELD
/* get_recv
 *
 * Return Type: int (*)(struct nn_sockbase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_recv(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  int (*)(struct nn_sockbase *, struct nn_msg *) native_field = native_self->recv;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_recv
 *
 * Parameters:
 * - value: int (*)(struct nn_sockbase *, struct nn_msg *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_recv(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_sockbase *, struct nn_msg *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_struct_nn_msg_PTR_RPAREN(ruby_field);

  native_self->recv = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_setopt_FIELD
/* get_setopt
 *
 * Return Type: int (*)(struct nn_sockbase *, int, int, const void *, int)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_setopt(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  int (*)(struct nn_sockbase *, int, int, const void *, int) native_field = native_self->setopt;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_intCOMMA_intCOMMA_const_void_PTR_COMMA_int_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_setopt
 *
 * Parameters:
 * - value: int (*)(struct nn_sockbase *, int, int, const void *, int)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_setopt(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_intCOMMA_intCOMMA_const_void_PTR_COMMA_int_RPAREN(ruby_field);

  int (*native_field)(struct nn_sockbase *, int, int, const void *, int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_intCOMMA_intCOMMA_const_void_PTR_COMMA_int_RPAREN(ruby_field);

  native_self->setopt = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbaseVfptr_getopt_FIELD
/* get_getopt
 *
 * Return Type: int (*)(struct nn_sockbase *, int, int, void *, int *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_get_getopt(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);

  int (*)(struct nn_sockbase *, int, int, void *, int *) native_field = native_self->getopt;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_intCOMMA_intCOMMA_void_PTR_COMMA_int_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_getopt
 *
 * Parameters:
 * - value: int (*)(struct nn_sockbase *, int, int, void *, int *)
 */
mrb_value
mrb_NN_NnSockbaseVfptr_set_getopt(mrb_state* mrb, mrb_value self) {
  nn_sockbase_vfptr * native_self = mruby_unbox_nn_sockbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_intCOMMA_intCOMMA_void_PTR_COMMA_int_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_sockbase *, int, int, void *, int *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_sockbase_PTR_COMMA_intCOMMA_intCOMMA_void_PTR_COMMA_int_PTR_RPAREN(ruby_field);

  native_self->getopt = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnSockbaseVfptr_init(mrb_state* mrb) {
  RClass* NnSockbaseVfptr_class = mrb_define_class_under(mrb, NN_module(mrb), "NnSockbaseVfptr", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnSockbaseVfptr_class, MRB_TT_DATA);

#if BIND_NnSockbaseVfptr_INITIALIZE
  mrb_define_method(mrb, NnSockbaseVfptr_class, "initialize", mrb_NN_NnSockbaseVfptr_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnSockbaseVfptr_class, "disown", mrb_NN_NnSockbaseVfptr_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnSockbaseVfptr_class, "belongs_to_ruby?", mrb_NN_NnSockbaseVfptr_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnSockbaseVfptr_stop_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "stop", mrb_NN_NnSockbaseVfptr_get_stop, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "stop=", mrb_NN_NnSockbaseVfptr_set_stop, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_destroy_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "destroy", mrb_NN_NnSockbaseVfptr_get_destroy, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "destroy=", mrb_NN_NnSockbaseVfptr_set_destroy, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_add_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "add", mrb_NN_NnSockbaseVfptr_get_add, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "add=", mrb_NN_NnSockbaseVfptr_set_add, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_rm_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "rm", mrb_NN_NnSockbaseVfptr_get_rm, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "rm=", mrb_NN_NnSockbaseVfptr_set_rm, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_in_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "in", mrb_NN_NnSockbaseVfptr_get_in, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "in=", mrb_NN_NnSockbaseVfptr_set_in, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_out_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "out", mrb_NN_NnSockbaseVfptr_get_out, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "out=", mrb_NN_NnSockbaseVfptr_set_out, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_events_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "events", mrb_NN_NnSockbaseVfptr_get_events, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "events=", mrb_NN_NnSockbaseVfptr_set_events, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_send_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "send", mrb_NN_NnSockbaseVfptr_get_send, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "send=", mrb_NN_NnSockbaseVfptr_set_send, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_recv_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "recv", mrb_NN_NnSockbaseVfptr_get_recv, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "recv=", mrb_NN_NnSockbaseVfptr_set_recv, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_setopt_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "setopt", mrb_NN_NnSockbaseVfptr_get_setopt, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "setopt=", mrb_NN_NnSockbaseVfptr_set_setopt, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbaseVfptr_getopt_FIELD
  mrb_define_method(mrb, NnSockbaseVfptr_class, "getopt", mrb_NN_NnSockbaseVfptr_get_getopt, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbaseVfptr_class, "getopt=", mrb_NN_NnSockbaseVfptr_set_getopt, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
