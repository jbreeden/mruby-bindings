/*
 * nn_optset_vfptr
 * Defined in file transport.h @ line 48
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnOptsetVfptr_TYPE

/*
 * Class Methods
 */

#if BIND_NnOptsetVfptr_INITIALIZE
mrb_value
mrb_NN_NnOptsetVfptr_initialize(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr* native_object = (nn_optset_vfptr*)malloc(sizeof(nn_optset_vfptr));
  mruby_gift_nn_optset_vfptr_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnOptsetVfptr_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnOptsetVfptr.disown only accepts objects of type NN::NnOptsetVfptr");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnOptsetVfptr_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnOptsetVfptr.disown only accepts objects of type NN::NnOptsetVfptr");
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

#if BIND_NnOptsetVfptr_destroy_FIELD
/* get_destroy
 *
 * Return Type: void (*)(struct nn_optset *)
 */
mrb_value
mrb_NN_NnOptsetVfptr_get_destroy(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr * native_self = mruby_unbox_nn_optset_vfptr(self);

  void (*)(struct nn_optset *) native_field = native_self->destroy;

  mrb_value ruby_field = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_destroy
 *
 * Parameters:
 * - value: void (*)(struct nn_optset *)
 */
mrb_value
mrb_NN_NnOptsetVfptr_set_destroy(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr * native_self = mruby_unbox_nn_optset_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_RPAREN(ruby_field);

  void (*native_field)(struct nn_optset *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_RPAREN(ruby_field);

  native_self->destroy = native_field;

  return ruby_field;
}
#endif

#if BIND_NnOptsetVfptr_setopt_FIELD
/* get_setopt
 *
 * Return Type: int (*)(struct nn_optset *, int, const void *, int)
 */
mrb_value
mrb_NN_NnOptsetVfptr_get_setopt(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr * native_self = mruby_unbox_nn_optset_vfptr(self);

  int (*)(struct nn_optset *, int, const void *, int) native_field = native_self->setopt;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_COMMA_intCOMMA_const_void_PTR_COMMA_int_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_setopt
 *
 * Parameters:
 * - value: int (*)(struct nn_optset *, int, const void *, int)
 */
mrb_value
mrb_NN_NnOptsetVfptr_set_setopt(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr * native_self = mruby_unbox_nn_optset_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_COMMA_intCOMMA_const_void_PTR_COMMA_int_RPAREN(ruby_field);

  int (*native_field)(struct nn_optset *, int, const void *, int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_COMMA_intCOMMA_const_void_PTR_COMMA_int_RPAREN(ruby_field);

  native_self->setopt = native_field;

  return ruby_field;
}
#endif

#if BIND_NnOptsetVfptr_getopt_FIELD
/* get_getopt
 *
 * Return Type: int (*)(struct nn_optset *, int, void *, int *)
 */
mrb_value
mrb_NN_NnOptsetVfptr_get_getopt(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr * native_self = mruby_unbox_nn_optset_vfptr(self);

  int (*)(struct nn_optset *, int, void *, int *) native_field = native_self->getopt;

  mrb_value ruby_field = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_COMMA_intCOMMA_void_PTR_COMMA_int_PTR_RPAREN(mrb, native_field);

  return ruby_field;
}

/* set_getopt
 *
 * Parameters:
 * - value: int (*)(struct nn_optset *, int, void *, int *)
 */
mrb_value
mrb_NN_NnOptsetVfptr_set_getopt(mrb_state* mrb, mrb_value self) {
  nn_optset_vfptr * native_self = mruby_unbox_nn_optset_vfptr(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_COMMA_intCOMMA_void_PTR_COMMA_int_PTR_RPAREN(ruby_field);

  int (*native_field)(struct nn_optset *, int, void *, int *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_nn_optset_PTR_COMMA_intCOMMA_void_PTR_COMMA_int_PTR_RPAREN(ruby_field);

  native_self->getopt = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnOptsetVfptr_init(mrb_state* mrb) {
  RClass* NnOptsetVfptr_class = mrb_define_class_under(mrb, NN_module(mrb), "NnOptsetVfptr", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnOptsetVfptr_class, MRB_TT_DATA);

#if BIND_NnOptsetVfptr_INITIALIZE
  mrb_define_method(mrb, NnOptsetVfptr_class, "initialize", mrb_NN_NnOptsetVfptr_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnOptsetVfptr_class, "disown", mrb_NN_NnOptsetVfptr_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnOptsetVfptr_class, "belongs_to_ruby?", mrb_NN_NnOptsetVfptr_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnOptsetVfptr_destroy_FIELD
  mrb_define_method(mrb, NnOptsetVfptr_class, "destroy", mrb_NN_NnOptsetVfptr_get_destroy, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnOptsetVfptr_class, "destroy=", mrb_NN_NnOptsetVfptr_set_destroy, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnOptsetVfptr_setopt_FIELD
  mrb_define_method(mrb, NnOptsetVfptr_class, "setopt", mrb_NN_NnOptsetVfptr_get_setopt, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnOptsetVfptr_class, "setopt=", mrb_NN_NnOptsetVfptr_set_setopt, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnOptsetVfptr_getopt_FIELD
  mrb_define_method(mrb, NnOptsetVfptr_class, "getopt", mrb_NN_NnOptsetVfptr_get_getopt, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnOptsetVfptr_class, "getopt=", mrb_NN_NnOptsetVfptr_set_getopt, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
