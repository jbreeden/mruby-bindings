/*
 * apr_random_t
 * Defined in file apr_random.h @ line 63
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprRandomT_TYPE

/*
 * Class Methods
 */

#if BIND_AprRandomT_INITIALIZE
mrb_value
mrb_APR_AprRandomT_initialize(mrb_state* mrb, mrb_value self) {
  apr_random_t* native_object = (apr_random_t*)malloc(sizeof(apr_random_t));
  mruby_gift_apr_random_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprRandomT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprRandomT.disown only accepts objects of type APR::AprRandomT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprRandomT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprRandomT.disown only accepts objects of type APR::AprRandomT");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_APR_AprRandomT_init(mrb_state* mrb) {
  RClass* AprRandomT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprRandomT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprRandomT_class, MRB_TT_DATA);

#if BIND_AprRandomT_INITIALIZE
  mrb_define_method(mrb, AprRandomT_class, "initialize", mrb_APR_AprRandomT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprRandomT_class, "disown", mrb_APR_AprRandomT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprRandomT_class, "belongs_to_ruby?", mrb_APR_AprRandomT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
