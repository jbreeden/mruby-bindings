/*
 * sockaddr
 * Defined in file apr_portable.h @ line 185
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_Sockaddr_TYPE

/*
 * Class Methods
 */

#if BIND_Sockaddr_MALLOC
mrb_value
mrb_APR_Sockaddr_malloc(mrb_state* mrb, mrb_value self) {
  sockaddr* native_object = (sockaddr*)malloc(sizeof(sockaddr));
  return mruby_box_sockaddr(mrb, native_object);
}
#endif

mrb_value
mrb_APR_Sockaddr_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::Sockaddr.free can only free objects of type APR::Sockaddr");
    return mrb_nil_value();
  }

  sockaddr * native_to_free = mruby_unbox_sockaddr(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_Sockaddr_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::Sockaddr.clear_pointer can only clear objects of type APR::Sockaddr");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_Sockaddr_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::Sockaddr.address_of can only get the address for objects of type APR::Sockaddr");
    return mrb_nil_value();
  }

  sockaddr * native_object = mruby_unbox_sockaddr(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_Sockaddr_init(mrb_state* mrb) {
  RClass* Sockaddr_class = mrb_define_class_under(mrb, APR_module(mrb), "Sockaddr", mrb->object_class);

#if BIND_Sockaddr_MALLOC
  mrb_define_class_method(mrb, Sockaddr_class, "malloc", mrb_APR_Sockaddr_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, Sockaddr_class, "free", mrb_APR_Sockaddr_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, Sockaddr_class, "clear_pointer", mrb_APR_Sockaddr_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, Sockaddr_class, "address_of", mrb_APR_Sockaddr_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
