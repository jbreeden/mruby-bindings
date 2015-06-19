/*
 * nn_sockbase
 * Defined in file protocol.h @ line 81
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnSockbase_TYPE

/*
 * Class Methods
 */

#if BIND_NnSockbase_INITIALIZE
mrb_value
mrb_NN_NnSockbase_initialize(mrb_state* mrb, mrb_value self) {
  nn_sockbase* native_object = (nn_sockbase*)malloc(sizeof(nn_sockbase));
  mruby_gift_nn_sockbase_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnSockbase_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSockbase.disown only accepts objects of type NN::NnSockbase");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnSockbase_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSockbase.disown only accepts objects of type NN::NnSockbase");
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

#if BIND_NnSockbase_vfptr_FIELD
/* get_vfptr
 *
 * Return Type: const struct nn_sockbase_vfptr *
 */
mrb_value
mrb_NN_NnSockbase_get_vfptr(mrb_state* mrb, mrb_value self) {
  nn_sockbase * native_self = mruby_unbox_nn_sockbase(self);

  const struct nn_sockbase_vfptr * native_field = native_self->vfptr;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_const nn_sockbase_vfptr(mrb, native_field));

  return ruby_field;
}

/* set_vfptr
 *
 * Parameters:
 * - value: const struct nn_sockbase_vfptr *
 */
mrb_value
mrb_NN_NnSockbase_set_vfptr(mrb_state* mrb, mrb_value self) {
  nn_sockbase * native_self = mruby_unbox_nn_sockbase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnSockbaseVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbaseVfptr expected");
    return mrb_nil_value();
  }

  const struct nn_sockbase_vfptr * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_const nn_sockbase_vfptr(ruby_field));

  native_self->vfptr = native_field;

  return ruby_field;
}
#endif

#if BIND_NnSockbase_sock_FIELD
/* get_sock
 *
 * Return Type: struct nn_sock *
 */
mrb_value
mrb_NN_NnSockbase_get_sock(mrb_state* mrb, mrb_value self) {
  nn_sockbase * native_self = mruby_unbox_nn_sockbase(self);

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
mrb_NN_NnSockbase_set_sock(mrb_state* mrb, mrb_value self) {
  nn_sockbase * native_self = mruby_unbox_nn_sockbase(self);
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


void mrb_NN_NnSockbase_init(mrb_state* mrb) {
  RClass* NnSockbase_class = mrb_define_class_under(mrb, NN_module(mrb), "NnSockbase", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnSockbase_class, MRB_TT_DATA);

#if BIND_NnSockbase_INITIALIZE
  mrb_define_method(mrb, NnSockbase_class, "initialize", mrb_NN_NnSockbase_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnSockbase_class, "disown", mrb_NN_NnSockbase_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnSockbase_class, "belongs_to_ruby?", mrb_NN_NnSockbase_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnSockbase_vfptr_FIELD
  mrb_define_method(mrb, NnSockbase_class, "vfptr", mrb_NN_NnSockbase_get_vfptr, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbase_class, "vfptr=", mrb_NN_NnSockbase_set_vfptr, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnSockbase_sock_FIELD
  mrb_define_method(mrb, NnSockbase_class, "sock", mrb_NN_NnSockbase_get_sock, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnSockbase_class, "sock=", mrb_NN_NnSockbase_set_sock, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
