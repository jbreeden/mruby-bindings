/*
 * nn_cmsghdr
 * Defined in file nn.h @ line 279
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnCmsghdr_TYPE

/*
 * Class Methods
 */

#if BIND_NnCmsghdr_INITIALIZE
mrb_value
mrb_NN_NnCmsghdr_initialize(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr* native_object = (nn_cmsghdr*)malloc(sizeof(nn_cmsghdr));
  mruby_gift_nn_cmsghdr_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnCmsghdr_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnCmsghdr.disown only accepts objects of type NN::NnCmsghdr");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnCmsghdr_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnCmsghdr.disown only accepts objects of type NN::NnCmsghdr");
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

#if BIND_NnCmsghdr_cmsg_len_FIELD
/* get_cmsg_len
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnCmsghdr_get_cmsg_len(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr * native_self = mruby_unbox_nn_cmsghdr(self);

  int native_field = native_self->cmsg_len;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_cmsg_len
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnCmsghdr_set_cmsg_len(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr * native_self = mruby_unbox_nn_cmsghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->cmsg_len = native_field;

  return ruby_field;
}
#endif

#if BIND_NnCmsghdr_cmsg_level_FIELD
/* get_cmsg_level
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnCmsghdr_get_cmsg_level(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr * native_self = mruby_unbox_nn_cmsghdr(self);

  int native_field = native_self->cmsg_level;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_cmsg_level
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnCmsghdr_set_cmsg_level(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr * native_self = mruby_unbox_nn_cmsghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->cmsg_level = native_field;

  return ruby_field;
}
#endif

#if BIND_NnCmsghdr_cmsg_type_FIELD
/* get_cmsg_type
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnCmsghdr_get_cmsg_type(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr * native_self = mruby_unbox_nn_cmsghdr(self);

  int native_field = native_self->cmsg_type;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_cmsg_type
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnCmsghdr_set_cmsg_type(mrb_state* mrb, mrb_value self) {
  nn_cmsghdr * native_self = mruby_unbox_nn_cmsghdr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->cmsg_type = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnCmsghdr_init(mrb_state* mrb) {
  RClass* NnCmsghdr_class = mrb_define_class_under(mrb, NN_module(mrb), "NnCmsghdr", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnCmsghdr_class, MRB_TT_DATA);

#if BIND_NnCmsghdr_INITIALIZE
  mrb_define_method(mrb, NnCmsghdr_class, "initialize", mrb_NN_NnCmsghdr_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnCmsghdr_class, "disown", mrb_NN_NnCmsghdr_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnCmsghdr_class, "belongs_to_ruby?", mrb_NN_NnCmsghdr_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnCmsghdr_cmsg_len_FIELD
  mrb_define_method(mrb, NnCmsghdr_class, "cmsg_len", mrb_NN_NnCmsghdr_get_cmsg_len, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnCmsghdr_class, "cmsg_len=", mrb_NN_NnCmsghdr_set_cmsg_len, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnCmsghdr_cmsg_level_FIELD
  mrb_define_method(mrb, NnCmsghdr_class, "cmsg_level", mrb_NN_NnCmsghdr_get_cmsg_level, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnCmsghdr_class, "cmsg_level=", mrb_NN_NnCmsghdr_set_cmsg_level, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnCmsghdr_cmsg_type_FIELD
  mrb_define_method(mrb, NnCmsghdr_class, "cmsg_type", mrb_NN_NnCmsghdr_get_cmsg_type, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnCmsghdr_class, "cmsg_type=", mrb_NN_NnCmsghdr_set_cmsg_type, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
