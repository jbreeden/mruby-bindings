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

#if BIND_AprDirT_MALLOC
mrb_value
mrb_APR_AprDirT_malloc(mrb_state* mrb, mrb_value self) {
  apr_dir_t* native_object = (apr_dir_t*)malloc(sizeof(apr_dir_t));
  return mruby_box_apr_dir_t(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprDirT_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprDirT.free can only free objects of type APR::AprDirT");
    return mrb_nil_value();
  }

  apr_dir_t * native_to_free = mruby_unbox_apr_dir_t(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprDirT_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprDirT.clear_pointer can only clear objects of type APR::AprDirT");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprDirT_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprDirT.address_of can only get the address for objects of type APR::AprDirT");
    return mrb_nil_value();
  }

  apr_dir_t * native_object = mruby_unbox_apr_dir_t(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_AprDirT_init(mrb_state* mrb) {
  RClass* AprDirT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprDirT", mrb->object_class);

#if BIND_AprDirT_MALLOC
  mrb_define_class_method(mrb, AprDirT_class, "malloc", mrb_APR_AprDirT_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprDirT_class, "free", mrb_APR_AprDirT_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprDirT_class, "clear_pointer", mrb_APR_AprDirT_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprDirT_class, "address_of", mrb_APR_AprDirT_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
