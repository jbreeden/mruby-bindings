/*
 * nn_msghdr
 * Defined in file nn.h @ line 272
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnMsghdr_TYPE

/*
 * Class Methods
 */

#if BIND_NnMsghdr_INITIALIZE
mrb_value
mrb_NN_NnMsghdr_initialize(mrb_state* mrb, mrb_value self) {
  nn_msghdr* native_object = (nn_msghdr*)malloc(sizeof(nn_msghdr));
  mruby_gift_nn_msghdr_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnMsghdr_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnMsghdr.disown only accepts objects of type NN::NnMsghdr");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnMsghdr_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnMsghdr.disown only accepts objects of type NN::NnMsghdr");
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

#if BIND_NnMsghdr_msg_iov_FIELD
/* get_msg_iov
 *
 * Return Type: struct nn_iovec *
 */
mrb_value
mrb_NN_NnMsghdr_get_msg_iov(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);

  struct nn_iovec * native_field = native_self->msg_iov;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_nn_iovec(mrb, native_field));

  return ruby_field;
}

/* set_msg_iov
 *
 * Parameters:
 * - value: struct nn_iovec *
 */
mrb_value
mrb_NN_NnMsghdr_set_msg_iov(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnIovec_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnIovec expected");
    return mrb_nil_value();
  }

  struct nn_iovec * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_nn_iovec(ruby_field));

  native_self->msg_iov = native_field;

  return ruby_field;
}
#endif

#if BIND_NnMsghdr_msg_iovlen_FIELD
/* get_msg_iovlen
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnMsghdr_get_msg_iovlen(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);

  int native_field = native_self->msg_iovlen;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_msg_iovlen
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnMsghdr_set_msg_iovlen(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->msg_iovlen = native_field;

  return ruby_field;
}
#endif

#if BIND_NnMsghdr_msg_control_FIELD
/* get_msg_control
 *
 * Return Type: void *
 */
mrb_value
mrb_NN_NnMsghdr_get_msg_control(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);

  void * native_field = native_self->msg_control;

  mrb_value ruby_field = TODO_mruby_box_void_PTR(mrb, native_field);

  return ruby_field;
}

/* set_msg_control
 *
 * Parameters:
 * - value: void *
 */
mrb_value
mrb_NN_NnMsghdr_set_msg_control(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_PTR(ruby_field);

  void * native_field = TODO_mruby_unbox_void_PTR(ruby_field);

  native_self->msg_control = native_field;

  return ruby_field;
}
#endif

#if BIND_NnMsghdr_msg_controllen_FIELD
/* get_msg_controllen
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnMsghdr_get_msg_controllen(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);

  int native_field = native_self->msg_controllen;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_msg_controllen
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnMsghdr_set_msg_controllen(mrb_state* mrb, mrb_value self) {
  nn_msghdr * native_self = mruby_unbox_nn_msghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->msg_controllen = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnMsghdr_init(mrb_state* mrb) {
  RClass* NnMsghdr_class = mrb_define_class_under(mrb, NN_module(mrb), "NnMsghdr", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnMsghdr_class, MRB_TT_DATA);

#if BIND_NnMsghdr_INITIALIZE
  mrb_define_method(mrb, NnMsghdr_class, "initialize", mrb_NN_NnMsghdr_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnMsghdr_class, "disown", mrb_NN_NnMsghdr_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnMsghdr_class, "belongs_to_ruby?", mrb_NN_NnMsghdr_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnMsghdr_msg_iov_FIELD
  mrb_define_method(mrb, NnMsghdr_class, "msg_iov", mrb_NN_NnMsghdr_get_msg_iov, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnMsghdr_class, "msg_iov=", mrb_NN_NnMsghdr_set_msg_iov, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnMsghdr_msg_iovlen_FIELD
  mrb_define_method(mrb, NnMsghdr_class, "msg_iovlen", mrb_NN_NnMsghdr_get_msg_iovlen, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnMsghdr_class, "msg_iovlen=", mrb_NN_NnMsghdr_set_msg_iovlen, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnMsghdr_msg_control_FIELD
  mrb_define_method(mrb, NnMsghdr_class, "msg_control", mrb_NN_NnMsghdr_get_msg_control, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnMsghdr_class, "msg_control=", mrb_NN_NnMsghdr_set_msg_control, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnMsghdr_msg_controllen_FIELD
  mrb_define_method(mrb, NnMsghdr_class, "msg_controllen", mrb_NN_NnMsghdr_get_msg_controllen, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnMsghdr_class, "msg_controllen=", mrb_NN_NnMsghdr_set_msg_controllen, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
