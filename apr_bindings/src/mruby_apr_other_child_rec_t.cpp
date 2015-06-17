/*
 * apr_other_child_rec_t
 * Defined in file apr_thread_proc.h @ line 192
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprOtherChildRecT_TYPE

/*
 * Class Methods
 */

#if BIND_AprOtherChildRecT_INITIALIZE
mrb_value
mrb_APR_AprOtherChildRecT_initialize(mrb_state* mrb, mrb_value self) {
  apr_other_child_rec_t* native_object = (apr_other_child_rec_t*)malloc(sizeof(apr_other_child_rec_t));
  mruby_gift_apr_other_child_rec_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprOtherChildRecT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprOtherChildRecT.disown only accepts objects of type APR::AprOtherChildRecT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprOtherChildRecT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprOtherChildRecT.disown only accepts objects of type APR::AprOtherChildRecT");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_APR_AprOtherChildRecT_init(mrb_state* mrb) {
  RClass* AprOtherChildRecT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprOtherChildRecT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprOtherChildRecT_class, MRB_TT_DATA);

#if BIND_AprOtherChildRecT_INITIALIZE
  mrb_define_method(mrb, AprOtherChildRecT_class, "initialize", mrb_APR_AprOtherChildRecT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprOtherChildRecT_class, "disown", mrb_APR_AprOtherChildRecT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprOtherChildRecT_class, "belongs_to_ruby?", mrb_APR_AprOtherChildRecT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
