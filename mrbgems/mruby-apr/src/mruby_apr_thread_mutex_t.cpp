/*
 * apr_thread_mutex_t
 * Defined in file apr_thread_mutex.h @ line 41
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprThreadMutexT_TYPE

/*
 * Class Methods
 */

#if BIND_AprThreadMutexT_INITIALIZE
mrb_value
mrb_APR_AprThreadMutexT_initialize(mrb_state* mrb, mrb_value self) {
  apr_thread_mutex_t* native_object = (apr_thread_mutex_t*)malloc(sizeof(apr_thread_mutex_t));
  mruby_set_apr_thread_mutex_t_data_ptr(self, native_object));
  return self;
}
#endif

mrb_value
mrb_APR_AprThreadMutexT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprThreadMutexT.free can only free objects of type APR::AprThreadMutexT");
    return mrb_nil_value();
  }

  apr_thread_mutex_t * native_to_free = mruby_unbox_apr_thread_mutex_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprThreadMutexT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprThreadMutexT.clear_pointer can only clear objects of type APR::AprThreadMutexT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprThreadMutexT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprThreadMutexT.address_of can only get the address for objects of type APR::AprThreadMutexT");
    return mrb_nil_value();
  }

  apr_thread_mutex_t * native_object = mruby_unbox_apr_thread_mutex_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_AprThreadMutexT_init(mrb_state* mrb) {
  RClass* AprThreadMutexT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprThreadMutexT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprThreadMutexT_class, MRB_TT_DATA);

#if BIND_AprThreadMutexT_INITIALIZE
  mrb_define_method(mrb, AprThreadMutexT_class, "initialize", mrb_APR_AprThreadMutexT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprThreadMutexT_class, "free", mrb_APR_AprThreadMutexT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprThreadMutexT_class, "clear_pointer", mrb_APR_AprThreadMutexT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprThreadMutexT_class, "address_of", mrb_APR_AprThreadMutexT_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
