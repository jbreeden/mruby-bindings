/*
 * nn_ep_options
 * Defined in file transport.h @ line 169
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnEpOptions_TYPE

/*
 * Class Methods
 */

#if BIND_NnEpOptions_INITIALIZE
mrb_value
mrb_NN_NnEpOptions_initialize(mrb_state* mrb, mrb_value self) {
  nn_ep_options* native_object = (nn_ep_options*)malloc(sizeof(nn_ep_options));
  mruby_gift_nn_ep_options_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnEpOptions_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnEpOptions.disown only accepts objects of type NN::NnEpOptions");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnEpOptions_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnEpOptions.disown only accepts objects of type NN::NnEpOptions");
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

#if BIND_NnEpOptions_sndprio_FIELD
/* get_sndprio
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnEpOptions_get_sndprio(mrb_state* mrb, mrb_value self) {
  nn_ep_options * native_self = mruby_unbox_nn_ep_options(self);

  int native_field = native_self->sndprio;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_sndprio
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnEpOptions_set_sndprio(mrb_state* mrb, mrb_value self) {
  nn_ep_options * native_self = mruby_unbox_nn_ep_options(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->sndprio = native_field;

  return ruby_field;
}
#endif

#if BIND_NnEpOptions_rcvprio_FIELD
/* get_rcvprio
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnEpOptions_get_rcvprio(mrb_state* mrb, mrb_value self) {
  nn_ep_options * native_self = mruby_unbox_nn_ep_options(self);

  int native_field = native_self->rcvprio;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_rcvprio
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnEpOptions_set_rcvprio(mrb_state* mrb, mrb_value self) {
  nn_ep_options * native_self = mruby_unbox_nn_ep_options(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->rcvprio = native_field;

  return ruby_field;
}
#endif

#if BIND_NnEpOptions_ipv4only_FIELD
/* get_ipv4only
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnEpOptions_get_ipv4only(mrb_state* mrb, mrb_value self) {
  nn_ep_options * native_self = mruby_unbox_nn_ep_options(self);

  int native_field = native_self->ipv4only;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_ipv4only
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnEpOptions_set_ipv4only(mrb_state* mrb, mrb_value self) {
  nn_ep_options * native_self = mruby_unbox_nn_ep_options(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->ipv4only = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnEpOptions_init(mrb_state* mrb) {
  RClass* NnEpOptions_class = mrb_define_class_under(mrb, NN_module(mrb), "NnEpOptions", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnEpOptions_class, MRB_TT_DATA);

#if BIND_NnEpOptions_INITIALIZE
  mrb_define_method(mrb, NnEpOptions_class, "initialize", mrb_NN_NnEpOptions_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnEpOptions_class, "disown", mrb_NN_NnEpOptions_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnEpOptions_class, "belongs_to_ruby?", mrb_NN_NnEpOptions_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnEpOptions_sndprio_FIELD
  mrb_define_method(mrb, NnEpOptions_class, "sndprio", mrb_NN_NnEpOptions_get_sndprio, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpOptions_class, "sndprio=", mrb_NN_NnEpOptions_set_sndprio, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnEpOptions_rcvprio_FIELD
  mrb_define_method(mrb, NnEpOptions_class, "rcvprio", mrb_NN_NnEpOptions_get_rcvprio, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpOptions_class, "rcvprio=", mrb_NN_NnEpOptions_set_rcvprio, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnEpOptions_ipv4only_FIELD
  mrb_define_method(mrb, NnEpOptions_class, "ipv4only", mrb_NN_NnEpOptions_get_ipv4only, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpOptions_class, "ipv4only=", mrb_NN_NnEpOptions_set_ipv4only, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
