/*
 * nn_pipebase
 * Defined in file transport.h @ line 143
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnPipebase_TYPE

/*
 * Class Methods
 */

#if BIND_NnPipebase_INITIALIZE
mrb_value
mrb_NN_NnPipebase_initialize(mrb_state* mrb, mrb_value self) {
  nn_pipebase* native_object = (nn_pipebase*)malloc(sizeof(nn_pipebase));
  mruby_gift_nn_pipebase_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnPipebase_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPipebase.disown only accepts objects of type NN::NnPipebase");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnPipebase_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPipebase.disown only accepts objects of type NN::NnPipebase");
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

#if BIND_NnPipebase_fsm_FIELD
/* get_fsm
 *
 * Return Type: struct nn_fsm
 */
mrb_value
mrb_NN_NnPipebase_get_fsm(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  struct nn_fsm native_field = native_self->fsm;

  mrb_value ruby_field = TODO_mruby_box_struct_nn_fsm(mrb, native_field);

  return ruby_field;
}

/* set_fsm
 *
 * Parameters:
 * - value: struct nn_fsm
 */
mrb_value
mrb_NN_NnPipebase_set_fsm(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_nn_fsm(ruby_field);

  struct nn_fsm native_field = TODO_mruby_unbox_struct_nn_fsm(ruby_field);

  native_self->fsm = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_vfptr_FIELD
/* get_vfptr
 *
 * Return Type: const struct nn_pipebase_vfptr *
 */
mrb_value
mrb_NN_NnPipebase_get_vfptr(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  const struct nn_pipebase_vfptr * native_field = native_self->vfptr;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_const nn_pipebase_vfptr(mrb, native_field));

  return ruby_field;
}

/* set_vfptr
 *
 * Parameters:
 * - value: const struct nn_pipebase_vfptr *
 */
mrb_value
mrb_NN_NnPipebase_set_vfptr(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnPipebaseVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebaseVfptr expected");
    return mrb_nil_value();
  }

  const struct nn_pipebase_vfptr * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_const nn_pipebase_vfptr(ruby_field));

  native_self->vfptr = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_state_FIELD
/* get_state
 *
 * Return Type: uint8_t
 */
mrb_value
mrb_NN_NnPipebase_get_state(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  uint8_t native_field = native_self->state;

  mrb_value ruby_field = TODO_mruby_box_uint8_t(mrb, native_field);

  return ruby_field;
}

/* set_state
 *
 * Parameters:
 * - value: uint8_t
 */
mrb_value
mrb_NN_NnPipebase_set_state(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_uint8_t(ruby_field);

  uint8_t native_field = TODO_mruby_unbox_uint8_t(ruby_field);

  native_self->state = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_instate_FIELD
/* get_instate
 *
 * Return Type: uint8_t
 */
mrb_value
mrb_NN_NnPipebase_get_instate(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  uint8_t native_field = native_self->instate;

  mrb_value ruby_field = TODO_mruby_box_uint8_t(mrb, native_field);

  return ruby_field;
}

/* set_instate
 *
 * Parameters:
 * - value: uint8_t
 */
mrb_value
mrb_NN_NnPipebase_set_instate(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_uint8_t(ruby_field);

  uint8_t native_field = TODO_mruby_unbox_uint8_t(ruby_field);

  native_self->instate = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_outstate_FIELD
/* get_outstate
 *
 * Return Type: uint8_t
 */
mrb_value
mrb_NN_NnPipebase_get_outstate(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  uint8_t native_field = native_self->outstate;

  mrb_value ruby_field = TODO_mruby_box_uint8_t(mrb, native_field);

  return ruby_field;
}

/* set_outstate
 *
 * Parameters:
 * - value: uint8_t
 */
mrb_value
mrb_NN_NnPipebase_set_outstate(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_uint8_t(ruby_field);

  uint8_t native_field = TODO_mruby_unbox_uint8_t(ruby_field);

  native_self->outstate = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_sock_FIELD
/* get_sock
 *
 * Return Type: struct nn_sock *
 */
mrb_value
mrb_NN_NnPipebase_get_sock(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  struct nn_sock * native_field = native_self->sock;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_nn_sock(mrb, native_field));

  return ruby_field;
}

/* set_sock
 *
 * Parameters:
 * - value: struct nn_sock *
 */
mrb_value
mrb_NN_NnPipebase_set_sock(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnSock_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSock expected");
    return mrb_nil_value();
  }

  struct nn_sock * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_nn_sock(ruby_field));

  native_self->sock = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_data_FIELD
/* get_data
 *
 * Return Type: void *
 */
mrb_value
mrb_NN_NnPipebase_get_data(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  void * native_field = native_self->data;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);

  return ruby_field;
}

/* set_data
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_NN_NnPipebase_set_data(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_PTR(ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->data = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_in_FIELD
/* get_in
 *
 * Return Type: struct nn_fsm_event
 */
mrb_value
mrb_NN_NnPipebase_get_in(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  struct nn_fsm_event native_field = native_self->in;

  mrb_value ruby_field = TODO_mruby_box_struct_nn_fsm_event(mrb, native_field);

  return ruby_field;
}

/* set_in
 *
 * Parameters:
 * - value: struct nn_fsm_event
 */
mrb_value
mrb_NN_NnPipebase_set_in(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_nn_fsm_event(ruby_field);

  struct nn_fsm_event native_field = TODO_mruby_unbox_struct_nn_fsm_event(ruby_field);

  native_self->in = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_out_FIELD
/* get_out
 *
 * Return Type: struct nn_fsm_event
 */
mrb_value
mrb_NN_NnPipebase_get_out(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  struct nn_fsm_event native_field = native_self->out;

  mrb_value ruby_field = TODO_mruby_box_struct_nn_fsm_event(mrb, native_field);

  return ruby_field;
}

/* set_out
 *
 * Parameters:
 * - value: struct nn_fsm_event
 */
mrb_value
mrb_NN_NnPipebase_set_out(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_struct_nn_fsm_event(ruby_field);

  struct nn_fsm_event native_field = TODO_mruby_unbox_struct_nn_fsm_event(ruby_field);

  native_self->out = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPipebase_options_FIELD
/* get_options
 *
 * Return Type: struct nn_ep_options
 */
mrb_value
mrb_NN_NnPipebase_get_options(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);

  struct nn_ep_options native_field = native_self->options;

  /* WARNING: Boxing a pointer to a value type.
   * If this is a stack variable, it will be deleted when this function returns.
   * If a longer lifespan is required, it should be put on the heap - consider
   * customizing this function (or add a `CTypes` definition to cover all instances)
   */
  mrb_value ruby_field = mruby_box_struct nn_ep_options(mrb, &native_field);

  return ruby_field;
}

/* set_options
 *
 * Parameters:
 * - value: struct nn_ep_options
 */
mrb_value
mrb_NN_NnPipebase_set_options(mrb_state* mrb, mrb_value self) {
  nn_pipebase * native_self = mruby_unbox_nn_pipebase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, _class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, " expected");
    return mrb_nil_value();
  }

  struct nn_ep_options native_field = *(mruby_unbox_struct nn_ep_options(ruby_field));

  native_self->options = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnPipebase_init(mrb_state* mrb) {
  RClass* NnPipebase_class = mrb_define_class_under(mrb, NN_module(mrb), "NnPipebase", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnPipebase_class, MRB_TT_DATA);

#if BIND_NnPipebase_INITIALIZE
  mrb_define_method(mrb, NnPipebase_class, "initialize", mrb_NN_NnPipebase_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnPipebase_class, "disown", mrb_NN_NnPipebase_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnPipebase_class, "belongs_to_ruby?", mrb_NN_NnPipebase_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnPipebase_fsm_FIELD
  mrb_define_method(mrb, NnPipebase_class, "fsm", mrb_NN_NnPipebase_get_fsm, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "fsm=", mrb_NN_NnPipebase_set_fsm, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_vfptr_FIELD
  mrb_define_method(mrb, NnPipebase_class, "vfptr", mrb_NN_NnPipebase_get_vfptr, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "vfptr=", mrb_NN_NnPipebase_set_vfptr, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_state_FIELD
  mrb_define_method(mrb, NnPipebase_class, "state", mrb_NN_NnPipebase_get_state, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "state=", mrb_NN_NnPipebase_set_state, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_instate_FIELD
  mrb_define_method(mrb, NnPipebase_class, "instate", mrb_NN_NnPipebase_get_instate, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "instate=", mrb_NN_NnPipebase_set_instate, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_outstate_FIELD
  mrb_define_method(mrb, NnPipebase_class, "outstate", mrb_NN_NnPipebase_get_outstate, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "outstate=", mrb_NN_NnPipebase_set_outstate, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_sock_FIELD
  mrb_define_method(mrb, NnPipebase_class, "sock", mrb_NN_NnPipebase_get_sock, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "sock=", mrb_NN_NnPipebase_set_sock, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_data_FIELD
  mrb_define_method(mrb, NnPipebase_class, "data", mrb_NN_NnPipebase_get_data, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "data=", mrb_NN_NnPipebase_set_data, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_in_FIELD
  mrb_define_method(mrb, NnPipebase_class, "in", mrb_NN_NnPipebase_get_in, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "in=", mrb_NN_NnPipebase_set_in, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_out_FIELD
  mrb_define_method(mrb, NnPipebase_class, "out", mrb_NN_NnPipebase_get_out, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "out=", mrb_NN_NnPipebase_set_out, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPipebase_options_FIELD
  mrb_define_method(mrb, NnPipebase_class, "options", mrb_NN_NnPipebase_get_options, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPipebase_class, "options=", mrb_NN_NnPipebase_set_options, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
