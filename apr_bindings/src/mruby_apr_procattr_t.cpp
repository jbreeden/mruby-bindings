/*
 * apr_procattr_t
 * Defined in file apr_thread_proc.h @ line 183
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprProcattrT_TYPE

/*
 * Class Methods
 */

#if BIND_AprProcattrT_INITIALIZE
mrb_value
mrb_APR_AprProcattrT_initialize(mrb_state* mrb, mrb_value self) {
  apr_procattr_t* native_object = (apr_procattr_t*)malloc(sizeof(apr_procattr_t));
  mruby_gift_apr_procattr_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprProcattrT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcattrT.disown only accepts objects of type APR::AprProcattrT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprProcattrT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcattrT.disown only accepts objects of type APR::AprProcattrT");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_APR_AprProcattrT_init(mrb_state* mrb) {
  RClass* AprProcattrT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprProcattrT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprProcattrT_class, MRB_TT_DATA);

#if BIND_AprProcattrT_INITIALIZE
  mrb_define_method(mrb, AprProcattrT_class, "initialize", mrb_APR_AprProcattrT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprProcattrT_class, "disown", mrb_APR_AprProcattrT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprProcattrT_class, "belongs_to_ruby?", mrb_APR_AprProcattrT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
