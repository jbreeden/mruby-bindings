/*
 * apr_dir_t
 * Defined in file apr_file_info.h @ line 121
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprDirT_TYPE

/*
 * Class Methods
 */

#if BIND_AprDirT_INITIALIZE
mrb_value
mrb_APR_AprDirT_initialize(mrb_state* mrb, mrb_value self) {
  apr_dir_t* native_object = (apr_dir_t*)malloc(sizeof(apr_dir_t));
  mruby_gift_apr_dir_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprDirT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprDirT.disown only accepts objects of type APR::AprDirT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprDirT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprDirT.disown only accepts objects of type APR::AprDirT");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}


void mrb_APR_AprDirT_init(mrb_state* mrb) {
  RClass* AprDirT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprDirT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprDirT_class, MRB_TT_DATA);

#if BIND_AprDirT_INITIALIZE
  mrb_define_method(mrb, AprDirT_class, "initialize", mrb_APR_AprDirT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprDirT_class, "disown", mrb_APR_AprDirT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprDirT_class, "belongs_to_ruby?", mrb_APR_AprDirT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));


}

#endif
