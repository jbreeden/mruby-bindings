/*
 * nn_iovec
 * Defined in file nn.h @ line 267
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnIovec_TYPE

/*
 * Class Methods
 */

#if BIND_NnIovec_INITIALIZE
mrb_value
mrb_NN_NnIovec_initialize(mrb_state* mrb, mrb_value self) {
  nn_iovec* native_object = (nn_iovec*)malloc(sizeof(nn_iovec));
  mruby_gift_nn_iovec_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnIovec_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnIovec.disown only accepts objects of type NN::NnIovec");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnIovec_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnIovec.disown only accepts objects of type NN::NnIovec");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}

/*
 * Fields
 */

#if BIND_NnIovec_iov_base_FIELD
/* get_iov_base
 *
 * Return Type: void *
 */
mrb_value
mrb_NN_NnIovec_get_iov_base(mrb_state* mrb, mrb_value self) {
  nn_iovec * native_self = mruby_unbox_nn_iovec(self);

  void * native_field = native_self->iov_base;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);

  return ruby_field;
}

/* set_iov_base
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_NN_NnIovec_set_iov_base(mrb_state* mrb, mrb_value self) {
  nn_iovec * native_self = mruby_unbox_nn_iovec(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_PTR(ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->iov_base = native_field;

  return ruby_field;
}
#endif

#if BIND_NnIovec_iov_len_FIELD
/* get_iov_len
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnIovec_get_iov_len(mrb_state* mrb, mrb_value self) {
  nn_iovec * native_self = mruby_unbox_nn_iovec(self);

  int native_field = native_self->iov_len;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_iov_len
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnIovec_set_iov_len(mrb_state* mrb, mrb_value self) {
  nn_iovec * native_self = mruby_unbox_nn_iovec(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->iov_len = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnIovec_init(mrb_state* mrb) {
  RClass* NnIovec_class = mrb_define_class_under(mrb, NN_module(mrb), "NnIovec", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnIovec_class, MRB_TT_DATA);

#if BIND_NnIovec_INITIALIZE
  mrb_define_method(mrb, NnIovec_class, "initialize", mrb_NN_NnIovec_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnIovec_class, "disown", mrb_NN_NnIovec_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnIovec_class, "belongs_to_ruby?", mrb_NN_NnIovec_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnIovec_iov_base_FIELD
  mrb_define_method(mrb, NnIovec_class, "iov_base", mrb_NN_NnIovec_get_iov_base, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnIovec_class, "iov_base=", mrb_NN_NnIovec_set_iov_base, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnIovec_iov_len_FIELD
  mrb_define_method(mrb, NnIovec_class, "iov_len", mrb_NN_NnIovec_get_iov_len, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnIovec_class, "iov_len=", mrb_NN_NnIovec_set_iov_len, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
