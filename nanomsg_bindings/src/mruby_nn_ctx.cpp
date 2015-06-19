/*
 * nn_ctx
 * Defined in file protocol.h @ line 32
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnCtx_TYPE

/*
 * Class Methods
 */

#if BIND_NnCtx_INITIALIZE
mrb_value
mrb_NN_NnCtx_initialize(mrb_state* mrb, mrb_value self) {
  nn_ctx* native_object = (nn_ctx*)malloc(sizeof(nn_ctx));
  mruby_gift_nn_ctx_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnCtx_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnCtx.disown only accepts objects of type NN::NnCtx");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnCtx_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnCtx.disown only accepts objects of type NN::NnCtx");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_NN_NnCtx_init(mrb_state* mrb) {
  RClass* NnCtx_class = mrb_define_class_under(mrb, NN_module(mrb), "NnCtx", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnCtx_class, MRB_TT_DATA);

#if BIND_NnCtx_INITIALIZE
  mrb_define_method(mrb, NnCtx_class, "initialize", mrb_NN_NnCtx_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnCtx_class, "disown", mrb_NN_NnCtx_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnCtx_class, "belongs_to_ruby?", mrb_NN_NnCtx_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
