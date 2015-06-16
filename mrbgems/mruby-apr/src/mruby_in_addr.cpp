/*
 * in_addr
 * Defined in file apr_network_io.h @ line 199
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_InAddr_TYPE

/*
 * Class Methods
 */

#if BIND_InAddr_MALLOC
mrb_value
mrb_APR_InAddr_malloc(mrb_state* mrb, mrb_value self) {
  in_addr* native_object = (in_addr*)malloc(sizeof(in_addr));
  return mruby_box_in_addr(mrb, native_object);
}
#endif

mrb_value
mrb_APR_InAddr_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::InAddr.free can only free objects of type APR::InAddr");
    return mrb_nil_value();
  }

  in_addr * native_to_free = mruby_unbox_in_addr(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_InAddr_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::InAddr.clear_pointer can only clear objects of type APR::InAddr");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_InAddr_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::InAddr.address_of can only get the address for objects of type APR::InAddr");
    return mrb_nil_value();
  }

  in_addr * native_object = mruby_unbox_in_addr(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_InAddr_init(mrb_state* mrb) {
  RClass* InAddr_class = mrb_define_class_under(mrb, APR_module(mrb), "InAddr", mrb->object_class);

#if BIND_InAddr_MALLOC
  mrb_define_class_method(mrb, InAddr_class, "malloc", mrb_APR_InAddr_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, InAddr_class, "free", mrb_APR_InAddr_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, InAddr_class, "clear_pointer", mrb_APR_InAddr_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, InAddr_class, "address_of", mrb_APR_InAddr_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
