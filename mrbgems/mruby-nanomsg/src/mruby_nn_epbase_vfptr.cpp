/*
 * nn_epbase_vfptr
 * Defined in file transport.h @ line 70
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnEpbaseVfptr_TYPE

/*
 * Class Methods
 */

#if BIND_NnEpbaseVfptr_INITIALIZE
mrb_value
mrb_NN_NnEpbaseVfptr_initialize(mrb_state* mrb, mrb_value self) {
  nn_epbase_vfptr* native_object = (nn_epbase_vfptr*)malloc(sizeof(nn_epbase_vfptr));
  mruby_gift_nn_epbase_vfptr_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnEpbaseVfptr_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnEpbaseVfptr.disown only accepts objects of type NN::NnEpbaseVfptr");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnEpbaseVfptr_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnEpbaseVfptr.disown only accepts objects of type NN::NnEpbaseVfptr");
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

#if BIND_NnEpbaseVfptr_stop_FIELD
/* get_stop
 *
 * Return Type: void (*)(struct nn_epbase *)
 */
mrb_value
mrb_NN_NnEpbaseVfptr_get_stop(mrb_state* mrb, mrb_value self) {
  nn_epbase_vfptr * native_self = mruby_unbox_nn_epbase_vfptr(self);

  void (*)(struct nn_epbase *) native_field = native_self->stop;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_epbase_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_stop
 *
 * Parameters:
 * - value: void (*)(struct nn_epbase *)
 */
mrb_value
mrb_NN_NnEpbaseVfptr_set_stop(mrb_state* mrb, mrb_value self) {
  nn_epbase_vfptr * native_self = mruby_unbox_nn_epbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_epbase_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_epbase *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_epbase_PTR_RPAREN(ruby_field);

  native_self->stop = native_field;

  return ruby_field;
}
#endif

#if BIND_NnEpbaseVfptr_destroy_FIELD
/* get_destroy
 *
 * Return Type: void (*)(struct nn_epbase *)
 */
mrb_value
mrb_NN_NnEpbaseVfptr_get_destroy(mrb_state* mrb, mrb_value self) {
  nn_epbase_vfptr * native_self = mruby_unbox_nn_epbase_vfptr(self);

  void (*)(struct nn_epbase *) native_field = native_self->destroy;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_epbase_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_destroy
 *
 * Parameters:
 * - value: void (*)(struct nn_epbase *)
 */
mrb_value
mrb_NN_NnEpbaseVfptr_set_destroy(mrb_state* mrb, mrb_value self) {
  nn_epbase_vfptr * native_self = mruby_unbox_nn_epbase_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_epbase_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_epbase *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_epbase_PTR_RPAREN(ruby_field);

  native_self->destroy = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnEpbaseVfptr_init(mrb_state* mrb) {
  RClass* NnEpbaseVfptr_class = mrb_define_class_under(mrb, NN_module(mrb), "NnEpbaseVfptr", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnEpbaseVfptr_class, MRB_TT_DATA);

#if BIND_NnEpbaseVfptr_INITIALIZE
  mrb_define_method(mrb, NnEpbaseVfptr_class, "initialize", mrb_NN_NnEpbaseVfptr_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnEpbaseVfptr_class, "disown", mrb_NN_NnEpbaseVfptr_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnEpbaseVfptr_class, "belongs_to_ruby?", mrb_NN_NnEpbaseVfptr_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnEpbaseVfptr_stop_FIELD
  mrb_define_method(mrb, NnEpbaseVfptr_class, "stop", mrb_NN_NnEpbaseVfptr_get_stop, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpbaseVfptr_class, "stop=", mrb_NN_NnEpbaseVfptr_set_stop, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnEpbaseVfptr_destroy_FIELD
  mrb_define_method(mrb, NnEpbaseVfptr_class, "destroy", mrb_NN_NnEpbaseVfptr_get_destroy, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnEpbaseVfptr_class, "destroy=", mrb_NN_NnEpbaseVfptr_set_destroy, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
