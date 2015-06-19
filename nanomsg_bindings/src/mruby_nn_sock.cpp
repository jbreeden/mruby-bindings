/*
 * nn_sock
 * Defined in file protocol.h @ line 130
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnSock_TYPE

/*
 * Class Methods
 */

#if BIND_NnSock_INITIALIZE
mrb_value
mrb_NN_NnSock_initialize(mrb_state* mrb, mrb_value self) {
  nn_sock* native_object = (nn_sock*)malloc(sizeof(nn_sock));
  mruby_gift_nn_sock_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnSock_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSock.disown only accepts objects of type NN::NnSock");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnSock_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnSock.disown only accepts objects of type NN::NnSock");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_NN_NnSock_init(mrb_state* mrb) {
  RClass* NnSock_class = mrb_define_class_under(mrb, NN_module(mrb), "NnSock", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnSock_class, MRB_TT_DATA);

#if BIND_NnSock_INITIALIZE
  mrb_define_method(mrb, NnSock_class, "initialize", mrb_NN_NnSock_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnSock_class, "disown", mrb_NN_NnSock_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnSock_class, "belongs_to_ruby?", mrb_NN_NnSock_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
