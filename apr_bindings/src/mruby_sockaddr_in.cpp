/*
 * sockaddr_in
 * Defined in file apr_network_io.h @ line 240
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_SockaddrIn_TYPE

/*
 * Class Methods
 */

#if BIND_SockaddrIn_MALLOC
mrb_value
mrb_APR_SockaddrIn_malloc(mrb_state* mrb, mrb_value self) {
  sockaddr_in* native_object = (sockaddr_in*)malloc(sizeof(sockaddr_in));
  return mruby_box_sockaddr_in(mrb, native_object);
}
#endif

mrb_value
mrb_APR_SockaddrIn_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::SockaddrIn.free can only free objects of type APR::SockaddrIn");
    return mrb_nil_value();
  }

  sockaddr_in * native_to_free = mruby_unbox_sockaddr_in(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_SockaddrIn_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::SockaddrIn.clear_pointer can only clear objects of type APR::SockaddrIn");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_SockaddrIn_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::SockaddrIn.address_of can only get the address for objects of type APR::SockaddrIn");
    return mrb_nil_value();
  }

  sockaddr_in * native_object = mruby_unbox_sockaddr_in(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_SockaddrIn_init(mrb_state* mrb) {
  RClass* SockaddrIn_class = mrb_define_class_under(mrb, APR_module(mrb), "SockaddrIn", mrb->object_class);

#if BIND_SockaddrIn_MALLOC
  mrb_define_class_method(mrb, SockaddrIn_class, "malloc", mrb_APR_SockaddrIn_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, SockaddrIn_class, "free", mrb_APR_SockaddrIn_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, SockaddrIn_class, "clear_pointer", mrb_APR_SockaddrIn_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, SockaddrIn_class, "address_of", mrb_APR_SockaddrIn_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
