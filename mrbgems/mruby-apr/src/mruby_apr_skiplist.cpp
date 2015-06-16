/*
 * apr_skiplist
 * Defined in file apr_skiplist.h @ line 54
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprSkiplist_TYPE

/*
 * Class Methods
 */

#if BIND_AprSkiplist_MALLOC
mrb_value
mrb_APR_AprSkiplist_malloc(mrb_state* mrb, mrb_value self) {
  apr_skiplist* native_object = (apr_skiplist*)malloc(sizeof(apr_skiplist));
  return mruby_box_apr_skiplist(mrb, native_object);
}
#endif

mrb_value
mrb_APR_AprSkiplist_free(mrb_state* mrb, mrb_value self) {
  mrb_value to_free;
  mrb_get_args(mrb, "o", &to_free);

  if (!mrb_obj_is_kind_of(mrb, to_free, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprSkiplist.free can only free objects of type APR::AprSkiplist");
    return mrb_nil_value();
  }

  apr_skiplist * native_to_free = mruby_unbox_apr_skiplist(to_free);
  if (native_to_free != NULL) {
    free(native_to_free);
  }
  DATA_PTR(to_free) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprSkiplist_clear_pointer(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprSkiplist.clear_pointer can only clear objects of type APR::AprSkiplist");
    return mrb_nil_value();
  }

  DATA_PTR(ruby_object) = NULL;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprSkiplist_address_of(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprSkiplist.address_of can only get the address for objects of type APR::AprSkiplist");
    return mrb_nil_value();
  }

  apr_skiplist * native_object = mruby_unbox_apr_skiplist(ruby_object);

  return mrb_fixnum_value((mrb_int) native_object);
}


void mrb_APR_AprSkiplist_init(mrb_state* mrb) {
  RClass* AprSkiplist_class = mrb_define_class_under(mrb, APR_module(mrb), "AprSkiplist", mrb->object_class);

#if BIND_AprSkiplist_MALLOC
  mrb_define_class_method(mrb, AprSkiplist_class, "malloc", mrb_APR_AprSkiplist_malloc, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprSkiplist_class, "free", mrb_APR_AprSkiplist_free, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprSkiplist_class, "clear_pointer", mrb_APR_AprSkiplist_clear_pointer, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprSkiplist_class, "address_of", mrb_APR_AprSkiplist_address_of, MRB_ARGS_ARG(1, 0));


}

#endif
