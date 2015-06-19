/*
 * nn_epbase
 * Defined in file transport.h @ line 68
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnEpbase_TYPE

/*
 * Class Methods
 */

#if BIND_NnEpbase_INITIALIZE
mrb_value
mrb_NN_NnEpbase_initialize(mrb_state* mrb, mrb_value self) {
  nn_epbase* native_object = (nn_epbase*)malloc(sizeof(nn_epbase));
  mruby_gift_nn_epbase_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnEpbase_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnEpbase.disown only accepts objects of type NN::NnEpbase");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnEpbase_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnEpbase.disown only accepts objects of type NN::NnEpbase");
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

#if BIND_NnEpbase_vfptr_FIELD
/* get_vfptr
 *
 * Return Type: const struct nn_epbase_vfptr *
 */
mrb_value
mrb_NN_NnEpbase_get_vfptr(mrb_state* mrb, mrb_value self) {
  nn_epbase * native_self = mruby_unbox_nn_epbase(self);

  const struct nn_epbase_vfptr * native_field = native_self->vfptr;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_const nn_epbase_vfptr(mrb, native_field));

  return ruby_field;
}

/* set_vfptr
 *
 * Parameters:
 * - value: const struct nn_epbase_vfptr *
 */
mrb_value
mrb_NN_NnEpbase_set_vfptr(mrb_state* mrb, mrb_value self) {
  nn_epbase * native_self = mruby_unbox_nn_epbase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnEpbaseVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbaseVfptr expected");
    return mrb_nil_value();
  }

  const struct nn_epbase_vfptr * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_const nn_epbase_vfptr(ruby_field));

  native_self->vfptr = native_field;

  return ruby_field;
}
#endif

#if BIND_NnEpbase_ep_FIELD
/* get_ep
 *
 * Return Type: struct nn_ep *
 */
mrb_value
mrb_NN_NnEpbase_get_ep(mrb_state* mrb, mrb_value self) {
  nn_epbase * native_self = mruby_unbox_nn_epbase(self);

  struct nn_ep * native_field = native_self->ep;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_nn_ep(mrb, native_field));

  return ruby_field;
}

/* set_ep
 *
 * Parameters:
 * - value: struct nn_ep *
 */
mrb_value
mrb_NN_NnEpbase_set_ep(mrb_state* mrb, mrb_value self) {
  nn_epbase * native_self = mruby_unbox_nn_epbase(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, NnEp_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEp expected");
    return mrb_nil_value();
  }

  struct nn_ep * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_nn_ep(ruby_field));

  native_self->ep = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnEpbase_init(mrb_state* mrb) {
  RClass* NnEpbase_class = mrb_define_class_under(mrb, NN_module(mrb), "NnEpbase", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnEpbase_class, MRB_TT_DATA);

#if BIND_NnEpbase_INITIALIZE
  mrb_define_method(mrb, NnEpbase_class, "initialize", mrb_NN_NnEpbase_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnEpbase_class, "disown", mrb_NN_NnEpbase_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnEpbase_class, "belongs_to_ruby?", mrb_NN_NnEpbase_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnEpbase_vfptr_FIELD
  mrb_define_method(mrb, NnEpbase_class, "vfptr", mrb_NN_NnEpbase_get_vfptr, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpbase_class, "vfptr=", mrb_NN_NnEpbase_set_vfptr, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnEpbase_ep_FIELD
  mrb_define_method(mrb, NnEpbase_class, "ep", mrb_NN_NnEpbase_get_ep, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpbase_class, "ep=", mrb_NN_NnEpbase_set_ep, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
