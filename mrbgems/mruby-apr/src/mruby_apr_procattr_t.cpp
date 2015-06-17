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
  mruby_set_apr_procattr_t_data_ptr(self, native_object));
  return self;
}
#endif

mrb_value
mrb_APR_AprProcattrT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcattrT.free can only free objects of type APR::AprProcattrT");
    return mrb_nil_value();
  }

  apr_procattr_t * native_to_free = mruby_unbox_apr_procattr_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprProcattrT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcattrT.clear_pointer can only clear objects of type APR::AprProcattrT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprProcattrT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprProcattrT.address_of can only get the address for objects of type APR::AprProcattrT");
    return mrb_nil_value();
  }

  apr_procattr_t * native_object = mruby_unbox_apr_procattr_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_AprProcattrT_init(mrb_state* mrb) {
  RClass* AprProcattrT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprProcattrT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprProcattrT_class, MRB_TT_DATA);

#if BIND_AprProcattrT_INITIALIZE
  mrb_define_method(mrb, AprProcattrT_class, "initialize", mrb_APR_AprProcattrT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprProcattrT_class, "free", mrb_APR_AprProcattrT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprProcattrT_class, "clear_pointer", mrb_APR_AprProcattrT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprProcattrT_class, "address_of", mrb_APR_AprProcattrT_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
