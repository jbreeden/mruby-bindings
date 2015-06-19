/*
 * nn_pipe
 * Defined in file protocol.h @ line 56
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnPipe_TYPE

/*
 * Class Methods
 */

#if BIND_NnPipe_INITIALIZE
mrb_value
mrb_NN_NnPipe_initialize(mrb_state* mrb, mrb_value self) {
  nn_pipe* native_object = (nn_pipe*)malloc(sizeof(nn_pipe));
  mruby_gift_nn_pipe_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnPipe_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPipe.disown only accepts objects of type NN::NnPipe");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnPipe_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPipe.disown only accepts objects of type NN::NnPipe");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_NN_NnPipe_init(mrb_state* mrb) {
  RClass* NnPipe_class = mrb_define_class_under(mrb, NN_module(mrb), "NnPipe", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnPipe_class, MRB_TT_DATA);

#if BIND_NnPipe_INITIALIZE
  mrb_define_method(mrb, NnPipe_class, "initialize", mrb_NN_NnPipe_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnPipe_class, "disown", mrb_NN_NnPipe_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnPipe_class, "belongs_to_ruby?", mrb_NN_NnPipe_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
