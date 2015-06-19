/*
 * nn_optset
 * Defined in file transport.h @ line 46
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnOptset_TYPE

/*
 * Class Methods
 */

#if BIND_NnOptset_INITIALIZE
mrb_value
mrb_NN_NnOptset_initialize(mrb_state* mrb, mrb_value self) {
  nn_optset* native_object = (nn_optset*)malloc(sizeof(nn_optset));
  mruby_gift_nn_optset_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnOptset_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnOptset.disown only accepts objects of type NN::NnOptset");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnOptset_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnOptset.disown only accepts objects of type NN::NnOptset");
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

#if BIND_NnOptset_vfptr_FIELD
/* get_vfptr
 *
 * Return Type: const struct nn_optset_vfptr *
 */
mrb_value
mrb_NN_NnOptset_get_vfptr(mrb_state* mrb, mrb_value self) {
  nn_optset * native_self = mruby_unbox_nn_optset(self);

  const struct nn_optset_vfptr * native_field = native_self->vfptr;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_const nn_optset_vfptr(mrb, native_field));

  return ruby_field;
}

/* set_vfptr
 *
 * Parameters:
 * - value: const struct nn_optset_vfptr *
 */
mrb_value
mrb_NN_NnOptset_set_vfptr(mrb_state* mrb, mrb_value self) {
  nn_optset * native_self = mruby_unbox_nn_optset(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnOptsetVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnOptsetVfptr expected");
    return mrb_nil_value();
  }

  const struct nn_optset_vfptr * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_const nn_optset_vfptr(ruby_field));

  native_self->vfptr = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnOptset_init(mrb_state* mrb) {
  RClass* NnOptset_class = mrb_define_class_under(mrb, NN_module(mrb), "NnOptset", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnOptset_class, MRB_TT_DATA);

#if BIND_NnOptset_INITIALIZE
  mrb_define_method(mrb, NnOptset_class, "initialize", mrb_NN_NnOptset_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnOptset_class, "disown", mrb_NN_NnOptset_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnOptset_class, "belongs_to_ruby?", mrb_NN_NnOptset_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnOptset_vfptr_FIELD
  mrb_define_method(mrb, NnOptset_class, "vfptr", mrb_NN_NnOptset_get_vfptr, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnOptset_class, "vfptr=", mrb_NN_NnOptset_set_vfptr, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
