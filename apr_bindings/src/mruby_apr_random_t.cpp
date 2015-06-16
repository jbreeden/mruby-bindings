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

#if BIND_AprRandomT_MALLOC
mrb_value
mrb_APR_AprRandomT_malloc(mrb_state* mrb, mrb_value self) {
  apr_random_t* native_object = (apr_random_t*)malloc(sizeof(apr_random_t));
  return mruby_box_apr_random_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprRandomT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprRandomT.free can only free objects of type APR::AprRandomT");
    return mrb_nil_value();
  }

  apr_random_t * native_to_free = mruby_unbox_apr_random_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprRandomT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprRandomT.clear_pointer can only clear objects of type APR::AprRandomT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprRandomT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprRandomT.address_of can only get the address for objects of type APR::AprRandomT");
    return mrb_nil_value();
  }

  apr_random_t * native_object = mruby_unbox_apr_random_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_AprRandomT_init(mrb_state* mrb) {
  RClass* AprRandomT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprRandomT", mrb->object_class);

#if BIND_AprRandomT_MALLOC
  mrb_define_class_method(mrb, AprRandomT_class, "malloc", mrb_APR_AprRandomT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprRandomT_class, "free", mrb_APR_AprRandomT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprRandomT_class, "clear_pointer", mrb_APR_AprRandomT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprRandomT_class, "address_of", mrb_APR_AprRandomT_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
