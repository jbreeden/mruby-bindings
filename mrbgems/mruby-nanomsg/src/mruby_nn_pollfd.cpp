/*
 * nn_pollfd
 * Defined in file nn.h @ line 367
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#if BIND_NnPollfd_TYPE

/*
 * Class Methods
 */

#if BIND_NnPollfd_INITIALIZE
mrb_value
mrb_NN_NnPollfd_initialize(mrb_state* mrb, mrb_value self) {
  nn_pollfd* native_object = (nn_pollfd*)malloc(sizeof(nn_pollfd));
  mruby_gift_nn_pollfd_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NN_NnPollfd_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPollfd.disown only accepts objects of type NN::NnPollfd");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NN_NnPollfd_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NN::NnPollfd.disown only accepts objects of type NN::NnPollfd");
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

#if BIND_NnPollfd_fd_FIELD
/* get_fd
 *
 * Return Type: int
 */
mrb_value
mrb_NN_NnPollfd_get_fd(mrb_state* mrb, mrb_value self) {
  nn_pollfd * native_self = mruby_unbox_nn_pollfd(self);

  int native_field = native_self->fd;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_fd
 *
 * Parameters:
 * - value: int
 */
mrb_value
mrb_NN_NnPollfd_set_fd(mrb_state* mrb, mrb_value self) {
  nn_pollfd * native_self = mruby_unbox_nn_pollfd(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->fd = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPollfd_events_FIELD
/* get_events
 *
 * Return Type: short
 */
mrb_value
mrb_NN_NnPollfd_get_events(mrb_state* mrb, mrb_value self) {
  nn_pollfd * native_self = mruby_unbox_nn_pollfd(self);

  short native_field = native_self->events;

  mrb_value ruby_field = TODO_mruby_box_short(mrb, native_field);

  return ruby_field;
}

/* set_events
 *
 * Parameters:
 * - value: short
 */
mrb_value
mrb_NN_NnPollfd_set_events(mrb_state* mrb, mrb_value self) {
  nn_pollfd * native_self = mruby_unbox_nn_pollfd(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_short(ruby_field);

  short native_field = TODO_mruby_unbox_short(ruby_field);

  native_self->events = native_field;

  return ruby_field;
}
#endif

#if BIND_NnPollfd_revents_FIELD
/* get_revents
 *
 * Return Type: short
 */
mrb_value
mrb_NN_NnPollfd_get_revents(mrb_state* mrb, mrb_value self) {
  nn_pollfd * native_self = mruby_unbox_nn_pollfd(self);

  short native_field = native_self->revents;

  mrb_value ruby_field = TODO_mruby_box_short(mrb, native_field);

  return ruby_field;
}

/* set_revents
 *
 * Parameters:
 * - value: short
 */
mrb_value
mrb_NN_NnPollfd_set_revents(mrb_state* mrb, mrb_value self) {
  nn_pollfd * native_self = mruby_unbox_nn_pollfd(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_short(ruby_field);

  short native_field = TODO_mruby_unbox_short(ruby_field);

  native_self->revents = native_field;

  return ruby_field;
}
#endif


void mrb_NN_NnPollfd_init(mrb_state* mrb) {
  RClass* NnPollfd_class = mrb_define_class_under(mrb, NN_module(mrb), "NnPollfd", mrb->object_class);
  MRB_SET_INSTANCE_TT(NnPollfd_class, MRB_TT_DATA);

#if BIND_NnPollfd_INITIALIZE
  mrb_define_method(mrb, NnPollfd_class, "initialize", mrb_NN_NnPollfd_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, NnPollfd_class, "disown", mrb_NN_NnPollfd_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, NnPollfd_class, "belongs_to_ruby?", mrb_NN_NnPollfd_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_NnPollfd_fd_FIELD
  mrb_define_method(mrb, NnPollfd_class, "fd", mrb_NN_NnPollfd_get_fd, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPollfd_class, "fd=", mrb_NN_NnPollfd_set_fd, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPollfd_events_FIELD
  mrb_define_method(mrb, NnPollfd_class, "events", mrb_NN_NnPollfd_get_events, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPollfd_class, "events=", mrb_NN_NnPollfd_set_events, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_NnPollfd_revents_FIELD
  mrb_define_method(mrb, NnPollfd_class, "revents", mrb_NN_NnPollfd_get_revents, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, NnPollfd_class, "revents=", mrb_NN_NnPollfd_set_revents, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
