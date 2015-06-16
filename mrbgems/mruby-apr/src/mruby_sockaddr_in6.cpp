/*
 * sockaddr_in6
 * Defined in file apr_network_io.h @ line 243
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_SockaddrIn6_TYPE

/*
 * Class Methods
 */

#if BIND_SockaddrIn6_MALLOC
mrb_value
mrb_APR_SockaddrIn6_malloc(mrb_state* mrb, mrb_value self) {
  sockaddr_in6* native_object = (sockaddr_in6*)malloc(sizeof(sockaddr_in6));
  return mruby_box_sockaddr_in6(mrb, native_object);
}
#endif

mrb_value
mrb_APR_SockaddrIn6_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::SockaddrIn6.free can only free objects of type APR::SockaddrIn6");
    return mrb_nil_value();
  }

  sockaddr_in6 * native_to_free = mruby_unbox_sockaddr_in6(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_SockaddrIn6_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::SockaddrIn6.clear_pointer can only clear objects of type APR::SockaddrIn6");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_SockaddrIn6_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::SockaddrIn6.address_of can only get the address for objects of type APR::SockaddrIn6");
    return mrb_nil_value();
  }

  sockaddr_in6 * native_object = mruby_unbox_sockaddr_in6(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_SockaddrIn6_init(mrb_state* mrb) {
  RClass* SockaddrIn6_class = mrb_define_class_under(mrb, APR_module(mrb), "SockaddrIn6", mrb->object_class);

#if BIND_SockaddrIn6_MALLOC
  mrb_define_class_method(mrb, SockaddrIn6_class, "malloc", mrb_APR_SockaddrIn6_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, SockaddrIn6_class, "free", mrb_APR_SockaddrIn6_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, SockaddrIn6_class, "clear_pointer", mrb_APR_SockaddrIn6_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, SockaddrIn6_class, "address_of", mrb_APR_SockaddrIn6_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
