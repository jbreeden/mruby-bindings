/*
 * TODO: INCLUDES
 */

#include "mruby_NN.h"

#ifdef __cplusplus
extern "C" {
#endif

#if BIND_nn_allocmsg_FUNCTION
#define nn_allocmsg_REQUIRED_ARGC 2
#define nn_allocmsg_OPTIONAL_ARGC 0
/* nn_allocmsg
 *
 * Parameters:
 * - size: int
 * - type: int
 * Return Type: void *
 */
mrb_value
mrb_NN_nn_allocmsg(mrb_state* mrb, mrb_value self) {
  mrb_value size;
  mrb_value type;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &size, &type);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, type, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_size = mrb_fixnum(size);

  int native_type = mrb_fixnum(type);

  /* Invocation */
  void * result = nn_allocmsg(native_size, native_type);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_nn_bind_FUNCTION
#define nn_bind_REQUIRED_ARGC 2
#define nn_bind_OPTIONAL_ARGC 0
/* nn_bind
 *
 * Parameters:
 * - s: int
 * - addr: const char *
 * Return Type: [errno: Fixnum, endpoint: Fixnum]
 *
 * See: http://nanomsg.org/v0.5/nn_bind.3.html
 */
mrb_value
mrb_NN_nn_bind(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &addr);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, addr, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);
  const char * native_addr = mrb_string_value_cstr(mrb, &addr);

  /* Invocation */
  int result = nn_bind(native_s, native_addr);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  
  mrb_value results = mrb_ary_new(mrb);
  if (result == -1) {
    mrb_ary_push(mrb, results, mrb_fixnum_value(nn_errno()));
    mrb_ary_push(mrb, results, mrb_nil_value());
  }
  else {
    mrb_ary_push(mrb, results, mrb_fixnum_value(0));
    mrb_ary_push(mrb, results, mrb_fixnum_value(result));
  }

  return results;
}
#endif

#if BIND_nn_close_FUNCTION
#define nn_close_REQUIRED_ARGC 1
#define nn_close_OPTIONAL_ARGC 0
/* nn_close
 *
 * Parameters:
 * - s: int (socket descriptor)
 * Return Type: int (zero on success, -1 on error and errno is set)
 *
 * See: http://nanomsg.org/v0.5/nn_close.3.html
 */
mrb_value
mrb_NN_nn_close(mrb_state* mrb, mrb_value self) {
  mrb_value s;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &s);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);

  /* Invocation */
  int result = nn_close(native_s);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  
  if (result == -1)
    return mrb_fixnum_value(nn_errno());
  else
    return mrb_fixnum_value(result);
}
#endif

#if BIND_nn_cmsg_nxthdr__FUNCTION
#define nn_cmsg_nxthdr__REQUIRED_ARGC 2
#define nn_cmsg_nxthdr__OPTIONAL_ARGC 0
/* nn_cmsg_nxthdr_
 *
 * Parameters:
 * - mhdr: const nn_msghdr *
 * - cmsg: const nn_cmsghdr *
 * Return Type: struct nn_cmsghdr *
 */
mrb_value
mrb_NN_nn_cmsg_nxthdr_(mrb_state* mrb, mrb_value self) {
  mrb_value mhdr;
  mrb_value cmsg;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mhdr, &cmsg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mhdr, NnMsghdr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnMsghdr expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cmsg, NnCmsghdr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnCmsghdr expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const nn_msghdr * native_mhdr = (mrb_nil_p(mhdr) ? NULL : mruby_unbox_const nn_msghdr(mhdr));

  const nn_cmsghdr * native_cmsg = (mrb_nil_p(cmsg) ? NULL : mruby_unbox_const nn_cmsghdr(cmsg));

  /* Invocation */
  struct nn_cmsghdr * result = nn_cmsg_nxthdr_(native_mhdr, native_cmsg);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_nn_cmsghdr(mrb, result));

  return return_value;
}
#endif

#if BIND_nn_connect_FUNCTION
#define nn_connect_REQUIRED_ARGC 2
#define nn_connect_OPTIONAL_ARGC 0
/* nn_connect
 *
 * Parameters:
 * - s: int
 * - addr: const char *
 * Return Type: [errno: Fixnum, socket: Fixnum]
 *
 * See: http://nanomsg.org/v0.5/nn_connect.3.html
 */
mrb_value
mrb_NN_nn_connect(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &addr);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, addr, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);

  const char * native_addr = mrb_string_value_cstr(mrb, &addr);

  /* Invocation */
  int result = nn_connect(native_s, native_addr);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  
  mrb_value results = mrb_ary_new(mrb);
  if (result == -1) {
    mrb_ary_push(mrb, results, mrb_fixnum_value(nn_errno()));
    mrb_ary_push(mrb, results, mrb_nil_value());
  }
  else {
    mrb_ary_push(mrb, results, mrb_fixnum_value(0));
    mrb_ary_push(mrb, results, mrb_fixnum_value(result));
  }

  return results;
}
#endif

#if BIND_nn_device_FUNCTION
#define nn_device_REQUIRED_ARGC 2
#define nn_device_OPTIONAL_ARGC 0
/* nn_device
 *
 * Parameters:
 * - s1: int
 * - s2: int
 * Return Type: int
 *
 * See: http://nanomsg.org/v0.5/nn_device.3.html
 */
mrb_value
mrb_NN_nn_device(mrb_state* mrb, mrb_value self) {
  mrb_value s1;
  mrb_value s2;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s1, &s2);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s1, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, s2, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s1 = mrb_fixnum(s1);
  int native_s2 = mrb_fixnum(s2);

  /* Invocation */
  int result = nn_device(native_s1, native_s2);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  
  if (result == -1)
    return mrb_fixnum_value(nn_errno());
  else
    return mrb_fixnum_value(result);
}
#endif

#if BIND_nn_epbase_clear_error_FUNCTION
#define nn_epbase_clear_error_REQUIRED_ARGC 1
#define nn_epbase_clear_error_OPTIONAL_ARGC 0
/* nn_epbase_clear_error
 *
 * Parameters:
 * - self: nn_epbase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_clear_error(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  /* Invocation */
  nn_epbase_clear_error(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_epbase_getaddr_FUNCTION
#define nn_epbase_getaddr_REQUIRED_ARGC 1
#define nn_epbase_getaddr_OPTIONAL_ARGC 0
/* nn_epbase_getaddr
 *
 * Parameters:
 * - self: nn_epbase *
 * Return Type: const char *
 */
mrb_value
mrb_NN_nn_epbase_getaddr(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  /* Invocation */
  const char * result = nn_epbase_getaddr(native_self);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_nn_epbase_getctx_FUNCTION
#define nn_epbase_getctx_REQUIRED_ARGC 1
#define nn_epbase_getctx_OPTIONAL_ARGC 0
/* nn_epbase_getctx
 *
 * Parameters:
 * - self: nn_epbase *
 * Return Type: struct nn_ctx *
 */
mrb_value
mrb_NN_nn_epbase_getctx(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  /* Invocation */
  struct nn_ctx * result = nn_epbase_getctx(native_self);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_nn_ctx(mrb, result));

  return return_value;
}
#endif

#if BIND_nn_epbase_getopt_FUNCTION
#define nn_epbase_getopt_REQUIRED_ARGC 5
#define nn_epbase_getopt_OPTIONAL_ARGC 0
/* nn_epbase_getopt
 *
 * Parameters:
 * - self: nn_epbase *
 * - level: int
 * - option: int
 * - optval: void *
 * - optvallen: int *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_getopt(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value level;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &self, &level, &option, &optval, &optvallen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(optval);
  TODO_type_check_int_PTR(optvallen);


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  int native_level = mrb_fixnum(level);

  int native_option = mrb_fixnum(option);

  void * native_optval = TODO_mruby_unbox_void_PTR(optval);

  int * native_optvallen = TODO_mruby_unbox_int_PTR(optvallen);

  /* Invocation */
  nn_epbase_getopt(native_self, native_level, native_option, native_optval, native_optvallen);

  return mrb_nil_value();
}
#endif

#if BIND_nn_epbase_init_FUNCTION
#define nn_epbase_init_REQUIRED_ARGC 3
#define nn_epbase_init_OPTIONAL_ARGC 0
/* nn_epbase_init
 *
 * Parameters:
 * - self: nn_epbase *
 * - vfptr: const nn_epbase_vfptr *
 * - hint: void *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_init(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value vfptr;
  mrb_value hint;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &self, &vfptr, &hint);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, vfptr, NnEpbaseVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbaseVfptr expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(hint);


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  const nn_epbase_vfptr * native_vfptr = (mrb_nil_p(vfptr) ? NULL : mruby_unbox_const nn_epbase_vfptr(vfptr));

  void * native_hint = TODO_mruby_unbox_void_PTR(hint);

  /* Invocation */
  nn_epbase_init(native_self, native_vfptr, native_hint);

  return mrb_nil_value();
}
#endif

#if BIND_nn_epbase_ispeer_FUNCTION
#define nn_epbase_ispeer_REQUIRED_ARGC 2
#define nn_epbase_ispeer_OPTIONAL_ARGC 0
/* nn_epbase_ispeer
 *
 * Parameters:
 * - self: nn_epbase *
 * - socktype: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_epbase_ispeer(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value socktype;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &self, &socktype);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, socktype, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  int native_socktype = mrb_fixnum(socktype);

  /* Invocation */
  int result = nn_epbase_ispeer(native_self, native_socktype);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_epbase_set_error_FUNCTION
#define nn_epbase_set_error_REQUIRED_ARGC 2
#define nn_epbase_set_error_OPTIONAL_ARGC 0
/* nn_epbase_set_error
 *
 * Parameters:
 * - self: nn_epbase *
 * - errnum: int
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_set_error(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value errnum;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &self, &errnum);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, errnum, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  int native_errnum = mrb_fixnum(errnum);

  /* Invocation */
  nn_epbase_set_error(native_self, native_errnum);

  return mrb_nil_value();
}
#endif

#if BIND_nn_epbase_stat_increment_FUNCTION
#define nn_epbase_stat_increment_REQUIRED_ARGC 7
#define nn_epbase_stat_increment_OPTIONAL_ARGC 0
/* nn_epbase_stat_increment
 *
 * Parameters:
 * - self: nn_epbase *
 * - name: int
 * - increment: int
 * - self: nn_pipebase *
 * - msg: nn_msg *
 * - self: nn_pipebase *
 * - msg: nn_msg *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_stat_increment(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value name;
  mrb_value increment;
  mrb_value self;
  mrb_value msg;
  mrb_value self;
  mrb_value msg;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooooo", &self, &name, &increment, &self, &msg, &self, &msg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, name, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, increment, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_msg_PTR(msg);
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_msg_PTR(msg);


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  int native_name = mrb_fixnum(name);

  int native_increment = mrb_fixnum(increment);

  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  nn_msg * native_msg = TODO_mruby_unbox_nn_msg_PTR(msg);

  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  nn_msg * native_msg = TODO_mruby_unbox_nn_msg_PTR(msg);

  /* Invocation */
  nn_epbase_stat_increment(native_self, native_name, native_increment, native_self, native_msg, native_self, native_msg);

  return mrb_nil_value();
}
#endif

#if BIND_nn_epbase_stopped_FUNCTION
#define nn_epbase_stopped_REQUIRED_ARGC 1
#define nn_epbase_stopped_OPTIONAL_ARGC 0
/* nn_epbase_stopped
 *
 * Parameters:
 * - self: nn_epbase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_stopped(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  /* Invocation */
  nn_epbase_stopped(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_epbase_term_FUNCTION
#define nn_epbase_term_REQUIRED_ARGC 1
#define nn_epbase_term_OPTIONAL_ARGC 0
/* nn_epbase_term
 *
 * Parameters:
 * - self: nn_epbase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_epbase_term(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  /* Invocation */
  nn_epbase_term(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_errno_FUNCTION
#define nn_errno_REQUIRED_ARGC 0
#define nn_errno_OPTIONAL_ARGC 0
/* nn_errno
 *
 * Parameters: None
 * Return Type: int
 *
 * See: http://nanomsg.org/v0.5/nn_errno.3.html
 */
mrb_value
mrb_NN_nn_errno(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  int result = nn_errno();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_freemsg_FUNCTION
#define nn_freemsg_REQUIRED_ARGC 1
#define nn_freemsg_OPTIONAL_ARGC 0
/* nn_freemsg
 *
 * Parameters:
 * - msg: void *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_freemsg(mrb_state* mrb, mrb_value self) {
  mrb_value msg;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &msg);


  /* Type checking */
  TODO_type_check_void_PTR(msg);


  /* Unbox parameters */
  void * native_msg = TODO_mruby_unbox_void_PTR(msg);

  /* Invocation */
  int result = nn_freemsg(native_msg);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_getsockopt_FUNCTION
#define nn_getsockopt_REQUIRED_ARGC 4
#define nn_getsockopt_OPTIONAL_ARGC 0
/* nn_getsockopt
 *
 * Parameters:
 * - s: int
 * - level: int
 * - option: int
 * - type: Class
 * Return Type: [errno: Fixnum, value: instance of type param ] 
 *
 * See: http://nanomsg.org/v0.5/nn_getsockopt.3.html
 * Note that instead of 0 or -1, this function returns 0 or errno (as set by nanomsg)
 * as the first return value. The second value is the option's value.
 */
mrb_value
mrb_NN_nn_getsockopt(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value level;
  mrb_value option;
  mrb_value type;

#define THROW_UNHANDLED_TYPE() \
  mrb_raise(mrb, mrb->eStandardError_class, \
    "Error in nanomsg bindings. Allowed a type param that wasn't handled."); \
  return mrb_nil_value();

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &s, &level, &option, &type);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  // (If type isn't a class OR it's not (fixnum OR string)) throw
  if (!mrb_obj_is_kind_of(mrb, option, mrb->class_class)
      || !(mrb_class_ptr(type) == mrb->fixnum_class
           || mrb_class_ptr(type) == mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum or String class object expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);
  int native_level = mrb_fixnum(level);
  int native_option = mrb_fixnum(option);

  /* Now, what type of option were we expecting again...? */
  sock_opt_type opt_type;
  if (mrb_class_ptr(type) == mrb->fixnum_class) {
    opt_type = sock_opt_type::INT;
  }
  else if (mrb_class_ptr(type) == mrb->string_class) {
    opt_type = sock_opt_type::STRING;
  }

  /* Invocation */
  size_t * native_optvallen;
  int native_optval_as_int;
  char* native_optval_as_str;

  int result;
  if (opt_type == sock_opt_type::INT) {
    result = nn_getsockopt(native_s, native_level, native_option, &native_optval_as_int, native_optvallen);
  }
  else if (opt_type == sock_opt_type::STRING) {
    result = nn_getsockopt(native_s, native_level, native_option, &native_optval_as_str, native_optvallen);
  }
  else {
    THROW_UNHANDLED_TYPE();
  }

  /* Box the return value */
  mrb_value results = mrb_ary_new(mrb);
  if (result == 0) {
    mrb_ary_push(mrb, results, mrb_fixnum_value(result));
    if (opt_type == sock_opt_type::INT) {
      mrb_ary_push(mrb, results, mrb_fixnum_value(native_optval_as_int));
    }
    else if (opt_type == sock_opt_type::STRING) {
      mrb_ary_push(mrb, results, mrb_str_new_cstr(mrb, native_optval_as_str));
    }
    else {
      THROW_UNHANDLED_TYPE();
    }
  }
  else {
    mrb_ary_push(mrb, results, mrb_fixnum_value(nn_errno()));
    mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_nn_pipe_getdata_FUNCTION
#define nn_pipe_getdata_REQUIRED_ARGC 1
#define nn_pipe_getdata_OPTIONAL_ARGC 0
/* nn_pipe_getdata
 *
 * Parameters:
 * - self: nn_pipe *
 * Return Type: void *
 */
mrb_value
mrb_NN_nn_pipe_getdata(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipe * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipe(self));

  /* Invocation */
  void * result = nn_pipe_getdata(native_self);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_nn_pipe_getopt_FUNCTION
#define nn_pipe_getopt_REQUIRED_ARGC 30
#define nn_pipe_getopt_OPTIONAL_ARGC 0
/* nn_pipe_getopt
 *
 * Parameters:
 * - self: nn_pipe *
 * - level: int
 * - option: int
 * - optval: void *
 * - optvallen: int *
 * - self: nn_sockbase *
 * - self: nn_sockbase *
 * - self: nn_sockbase *
 * - pipe: nn_pipe *
 * - self: nn_sockbase *
 * - pipe: nn_pipe *
 * - self: nn_sockbase *
 * - pipe: nn_pipe *
 * - self: nn_sockbase *
 * - pipe: nn_pipe *
 * - self: nn_sockbase *
 * - self: nn_sockbase *
 * - msg: nn_msg *
 * - self: nn_sockbase *
 * - msg: nn_msg *
 * - self: nn_sockbase *
 * - level: int
 * - option: int
 * - optval: const void *
 * - optvallen: int
 * - self: nn_sockbase *
 * - level: int
 * - option: int
 * - optval: void *
 * - optvallen: int *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipe_getopt(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value level;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;
  mrb_value self;
  mrb_value self;
  mrb_value self;
  mrb_value pipe;
  mrb_value self;
  mrb_value pipe;
  mrb_value self;
  mrb_value pipe;
  mrb_value self;
  mrb_value pipe;
  mrb_value self;
  mrb_value self;
  mrb_value msg;
  mrb_value self;
  mrb_value msg;
  mrb_value self;
  mrb_value level;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;
  mrb_value self;
  mrb_value level;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooooooooooooooooooooooooo", &self, &level, &option, &optval, &optvallen, &self, &self, &self, &pipe, &self, &pipe, &self, &pipe, &self, &pipe, &self, &self, &msg, &self, &msg, &self, &level, &option, &optval, &optvallen, &self, &level, &option, &optval, &optvallen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(optval);
  TODO_type_check_int_PTR(optvallen);
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pipe, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pipe, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pipe, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pipe, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_msg_PTR(msg);
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_msg_PTR(msg);
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(optval);
  if (!mrb_obj_is_kind_of(mrb, optvallen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(optval);
  TODO_type_check_int_PTR(optvallen);


  /* Unbox parameters */
  nn_pipe * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipe(self));

  int native_level = mrb_fixnum(level);

  int native_option = mrb_fixnum(option);

  void * native_optval = TODO_mruby_unbox_void_PTR(optval);

  int * native_optvallen = TODO_mruby_unbox_int_PTR(optvallen);

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_pipe * native_pipe = (mrb_nil_p(pipe) ? NULL : mruby_unbox_nn_pipe(pipe));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_pipe * native_pipe = (mrb_nil_p(pipe) ? NULL : mruby_unbox_nn_pipe(pipe));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_pipe * native_pipe = (mrb_nil_p(pipe) ? NULL : mruby_unbox_nn_pipe(pipe));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_pipe * native_pipe = (mrb_nil_p(pipe) ? NULL : mruby_unbox_nn_pipe(pipe));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_msg * native_msg = TODO_mruby_unbox_nn_msg_PTR(msg);

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  nn_msg * native_msg = TODO_mruby_unbox_nn_msg_PTR(msg);

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  int native_level = mrb_fixnum(level);

  int native_option = mrb_fixnum(option);

  const void * native_optval = TODO_mruby_unbox_const_void_PTR(optval);

  int native_optvallen = mrb_fixnum(optvallen);

  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  int native_level = mrb_fixnum(level);

  int native_option = mrb_fixnum(option);

  void * native_optval = TODO_mruby_unbox_void_PTR(optval);

  int * native_optvallen = TODO_mruby_unbox_int_PTR(optvallen);

  /* Invocation */
  nn_pipe_getopt(native_self, native_level, native_option, native_optval, native_optvallen, native_self, native_self, native_self, native_pipe, native_self, native_pipe, native_self, native_pipe, native_self, native_pipe, native_self, native_self, native_msg, native_self, native_msg, native_self, native_level, native_option, native_optval, native_optvallen, native_self, native_level, native_option, native_optval, native_optvallen);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipe_recv_FUNCTION
#define nn_pipe_recv_REQUIRED_ARGC 2
#define nn_pipe_recv_OPTIONAL_ARGC 0
/* nn_pipe_recv
 *
 * Parameters:
 * - self: nn_pipe *
 * - msg: nn_msg *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_pipe_recv(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value msg;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &self, &msg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_msg_PTR(msg);


  /* Unbox parameters */
  nn_pipe * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipe(self));

  nn_msg * native_msg = TODO_mruby_unbox_nn_msg_PTR(msg);

  /* Invocation */
  int result = nn_pipe_recv(native_self, native_msg);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_pipe_send_FUNCTION
#define nn_pipe_send_REQUIRED_ARGC 2
#define nn_pipe_send_OPTIONAL_ARGC 0
/* nn_pipe_send
 *
 * Parameters:
 * - self: nn_pipe *
 * - msg: nn_msg *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_pipe_send(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value msg;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &self, &msg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_msg_PTR(msg);


  /* Unbox parameters */
  nn_pipe * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipe(self));

  nn_msg * native_msg = TODO_mruby_unbox_nn_msg_PTR(msg);

  /* Invocation */
  int result = nn_pipe_send(native_self, native_msg);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_pipe_setdata_FUNCTION
#define nn_pipe_setdata_REQUIRED_ARGC 2
#define nn_pipe_setdata_OPTIONAL_ARGC 0
/* nn_pipe_setdata
 *
 * Parameters:
 * - self: nn_pipe *
 * - data: void *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipe_setdata(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value data;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &self, &data);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipe_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipe expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);


  /* Unbox parameters */
  nn_pipe * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipe(self));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  /* Invocation */
  nn_pipe_setdata(native_self, native_data);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipebase_getopt_FUNCTION
#define nn_pipebase_getopt_REQUIRED_ARGC 5
#define nn_pipebase_getopt_OPTIONAL_ARGC 0
/* nn_pipebase_getopt
 *
 * Parameters:
 * - self: nn_pipebase *
 * - level: int
 * - option: int
 * - optval: void *
 * - optvallen: int *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipebase_getopt(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value level;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &self, &level, &option, &optval, &optvallen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(optval);
  TODO_type_check_int_PTR(optvallen);


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  int native_level = mrb_fixnum(level);

  int native_option = mrb_fixnum(option);

  void * native_optval = TODO_mruby_unbox_void_PTR(optval);

  int * native_optvallen = TODO_mruby_unbox_int_PTR(optvallen);

  /* Invocation */
  nn_pipebase_getopt(native_self, native_level, native_option, native_optval, native_optvallen);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipebase_init_FUNCTION
#define nn_pipebase_init_REQUIRED_ARGC 3
#define nn_pipebase_init_OPTIONAL_ARGC 0
/* nn_pipebase_init
 *
 * Parameters:
 * - self: nn_pipebase *
 * - vfptr: const nn_pipebase_vfptr *
 * - epbase: nn_epbase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipebase_init(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value vfptr;
  mrb_value epbase;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &self, &vfptr, &epbase);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, vfptr, NnPipebaseVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebaseVfptr expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, epbase, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  const nn_pipebase_vfptr * native_vfptr = (mrb_nil_p(vfptr) ? NULL : mruby_unbox_const nn_pipebase_vfptr(vfptr));

  nn_epbase * native_epbase = (mrb_nil_p(epbase) ? NULL : mruby_unbox_nn_epbase(epbase));

  /* Invocation */
  nn_pipebase_init(native_self, native_vfptr, native_epbase);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipebase_ispeer_FUNCTION
#define nn_pipebase_ispeer_REQUIRED_ARGC 6
#define nn_pipebase_ispeer_OPTIONAL_ARGC 0
/* nn_pipebase_ispeer
 *
 * Parameters:
 * - self: nn_pipebase *
 * - socktype: int
 * - hint: void *
 * - epbase: nn_epbase **
 * - hint: void *
 * - epbase: nn_epbase **
 * Return Type: int
 */
mrb_value
mrb_NN_nn_pipebase_ispeer(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value socktype;
  mrb_value hint;
  mrb_value epbase;
  mrb_value hint;
  mrb_value epbase;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &self, &socktype, &hint, &epbase, &hint, &epbase);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, socktype, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(hint);
  TODO_type_check_nn_epbase_PTR_PTR(epbase);
  TODO_type_check_void_PTR(hint);
  TODO_type_check_nn_epbase_PTR_PTR(epbase);


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  int native_socktype = mrb_fixnum(socktype);

  void * native_hint = TODO_mruby_unbox_void_PTR(hint);

  nn_epbase ** native_epbase = TODO_mruby_unbox_nn_epbase_PTR_PTR(epbase);

  void * native_hint = TODO_mruby_unbox_void_PTR(hint);

  nn_epbase ** native_epbase = TODO_mruby_unbox_nn_epbase_PTR_PTR(epbase);

  /* Invocation */
  int result = nn_pipebase_ispeer(native_self, native_socktype, native_hint, native_epbase, native_hint, native_epbase);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_pipebase_received_FUNCTION
#define nn_pipebase_received_REQUIRED_ARGC 1
#define nn_pipebase_received_OPTIONAL_ARGC 0
/* nn_pipebase_received
 *
 * Parameters:
 * - self: nn_pipebase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipebase_received(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  /* Invocation */
  nn_pipebase_received(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipebase_sent_FUNCTION
#define nn_pipebase_sent_REQUIRED_ARGC 1
#define nn_pipebase_sent_OPTIONAL_ARGC 0
/* nn_pipebase_sent
 *
 * Parameters:
 * - self: nn_pipebase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipebase_sent(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  /* Invocation */
  nn_pipebase_sent(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipebase_start_FUNCTION
#define nn_pipebase_start_REQUIRED_ARGC 1
#define nn_pipebase_start_OPTIONAL_ARGC 0
/* nn_pipebase_start
 *
 * Parameters:
 * - self: nn_pipebase *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_pipebase_start(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  /* Invocation */
  int result = nn_pipebase_start(native_self);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_pipebase_stop_FUNCTION
#define nn_pipebase_stop_REQUIRED_ARGC 1
#define nn_pipebase_stop_OPTIONAL_ARGC 0
/* nn_pipebase_stop
 *
 * Parameters:
 * - self: nn_pipebase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipebase_stop(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  /* Invocation */
  nn_pipebase_stop(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_pipebase_term_FUNCTION
#define nn_pipebase_term_REQUIRED_ARGC 1
#define nn_pipebase_term_OPTIONAL_ARGC 0
/* nn_pipebase_term
 *
 * Parameters:
 * - self: nn_pipebase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_pipebase_term(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnPipebase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPipebase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pipebase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_pipebase(self));

  /* Invocation */
  nn_pipebase_term(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_poll_FUNCTION
#define nn_poll_REQUIRED_ARGC 3
#define nn_poll_OPTIONAL_ARGC 0
/* nn_poll
 *
 * Parameters:
 * - fds: nn_pollfd *
 * - nfds: int
 * - timeout: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_poll(mrb_state* mrb, mrb_value self) {
  mrb_value fds;
  mrb_value nfds;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fds, &nfds, &timeout);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fds, NnPollfd_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnPollfd expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, nfds, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_pollfd * native_fds = (mrb_nil_p(fds) ? NULL : mruby_unbox_nn_pollfd(fds));

  int native_nfds = mrb_fixnum(nfds);

  int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  int result = nn_poll(native_fds, native_nfds, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_reallocmsg_FUNCTION
#define nn_reallocmsg_REQUIRED_ARGC 2
#define nn_reallocmsg_OPTIONAL_ARGC 0
/* nn_reallocmsg
 *
 * Parameters:
 * - msg: void *
 * - size: int
 * Return Type: void *
 */
mrb_value
mrb_NN_nn_reallocmsg(mrb_state* mrb, mrb_value self) {
  mrb_value msg;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &msg, &size);


  /* Type checking */
  TODO_type_check_void_PTR(msg);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_msg = TODO_mruby_unbox_void_PTR(msg);

  int native_size = mrb_fixnum(size);

  /* Invocation */
  void * result = nn_reallocmsg(native_msg, native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_nn_recv_FUNCTION
#define nn_recv_REQUIRED_ARGC 2
#define nn_recv_OPTIONAL_ARGC 0
/* nn_recv
 *
 * Parameters:
 * - s: Fixnum
 * - flags: Fixnum
 * Return Type: [errno: Fixnum, message: String]
 *
 * See: http://nanomsg.org/v0.5/nn_recv.3.html
 */
mrb_value
mrb_NN_nn_recv(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &flags);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);
  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  char* native_buf = NULL;
  int result = nn_recv(native_s, &native_buf, NN_MSG, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }

  mrb_value results = mrb_ary_new(mrb);
  if (result == -1) {
    mrb_ary_push(mrb, results, mrb_fixnum_value(nn_errno()));
    mrb_ary_push(mrb, results, mrb_nil_value());
  }
  else {
    /* No error, return 0 */
    mrb_ary_push(mrb, results, mrb_fixnum_value(0));
    /* On success, result holds the number of bytes read  */
    /* Note: This sort of kills the whole "zero-copy" thing.
       I prefer this at the moment to implementing a Message class
       that knows how to nn_freemsg itself on GC. How would that
       class return its bytes anyway? By copying them... that's how.
    */
    mrb_ary_push(mrb, results, mrb_str_new(mrb, native_buf, result));
  }

  nn_freemsg(native_buf);
  return results;
}
#endif

#if BIND_nn_recvmsg_FUNCTION
#define nn_recvmsg_REQUIRED_ARGC 3
#define nn_recvmsg_OPTIONAL_ARGC 0
/* nn_recvmsg
 *
 * Parameters:
 * - s: int
 * - msghdr: nn_msghdr *
 * - flags: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_recvmsg(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value msghdr;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &msghdr, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, msghdr, NnMsghdr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnMsghdr expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_s = mrb_fixnum(s);

  nn_msghdr * native_msghdr = (mrb_nil_p(msghdr) ? NULL : mruby_unbox_nn_msghdr(msghdr));

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  int result = nn_recvmsg(native_s, native_msghdr, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_req_recv_FUNCTION
#define nn_req_recv_REQUIRED_ARGC 16
#define nn_req_recv_OPTIONAL_ARGC 0
/* nn_req_recv
 *
 * Parameters:
 * - s: int
 * - hndl: nn_req_handle *
 * - buf: void *
 * - len: int
 * - flags: int
 * - self: nn_optset *
 * - self: nn_optset *
 * - option: int
 * - optval: const void *
 * - optvallen: int
 * - self: nn_optset *
 * - option: int
 * - optval: void *
 * - optvallen: int *
 * - self: nn_epbase *
 * - self: nn_epbase *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_req_recv(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value hndl;
  mrb_value buf;
  mrb_value len;
  mrb_value flags;
  mrb_value self;
  mrb_value self;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;
  mrb_value self;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;
  mrb_value self;
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooooooooooo", &s, &hndl, &buf, &len, &flags, &self, &self, &option, &optval, &optvallen, &self, &option, &optval, &optvallen, &self, &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_req_handle_PTR(hndl);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnOptset_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnOptset expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnOptset_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnOptset expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(optval);
  if (!mrb_obj_is_kind_of(mrb, optvallen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnOptset_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnOptset expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(optval);
  TODO_type_check_int_PTR(optvallen);
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, self, NnEpbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnEpbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_s = mrb_fixnum(s);

  nn_req_handle * native_hndl = TODO_mruby_unbox_nn_req_handle_PTR(hndl);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_len = mrb_fixnum(len);

  int native_flags = mrb_fixnum(flags);

  nn_optset * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_optset(self));

  nn_optset * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_optset(self));

  int native_option = mrb_fixnum(option);

  const void * native_optval = TODO_mruby_unbox_const_void_PTR(optval);

  int native_optvallen = mrb_fixnum(optvallen);

  nn_optset * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_optset(self));

  int native_option = mrb_fixnum(option);

  void * native_optval = TODO_mruby_unbox_void_PTR(optval);

  int * native_optvallen = TODO_mruby_unbox_int_PTR(optvallen);

  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  nn_epbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_epbase(self));

  /* Invocation */
  int result = nn_req_recv(native_s, native_hndl, native_buf, native_len, native_flags, native_self, native_self, native_option, native_optval, native_optvallen, native_self, native_option, native_optval, native_optvallen, native_self, native_self);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_req_send_FUNCTION
#define nn_req_send_REQUIRED_ARGC 5
#define nn_req_send_OPTIONAL_ARGC 0
/* nn_req_send
 *
 * Parameters:
 * - s: int
 * - hndl: nn_req_handle
 * - buf: const void *
 * - len: int
 * - flags: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_req_send(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value hndl;
  mrb_value buf;
  mrb_value len;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &s, &hndl, &buf, &len, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_nn_req_handle(hndl);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_s = mrb_fixnum(s);

  nn_req_handle native_hndl = TODO_mruby_unbox_nn_req_handle(hndl);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_len = mrb_fixnum(len);

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  int result = nn_req_send(native_s, native_hndl, native_buf, native_len, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_send_FUNCTION
#define nn_send_REQUIRED_ARGC 3
#define nn_send_OPTIONAL_ARGC 0
/* nn_send
 *
 * Parameters:
 * - s: int
 * - buf: const void *
 * - flags: int
 * Return Type: [errno: Fixnum, bytes_sent: Fixnum]
 */
mrb_value
mrb_NN_nn_send(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value buf;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &buf, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);
  const char * native_buf = mrb_string_value_ptr(mrb, buf);
  int native_len = mrb_str_strlen(mrb, mrb_str_ptr(buf));
  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  int result = nn_send(native_s, native_buf, native_len, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  if (result == -1) {
    mrb_ary_push(mrb, results, mrb_fixnum_value(nn_errno()));
    mrb_ary_push(mrb, results, mrb_nil_value());
  }
  else {
    mrb_ary_push(mrb, results, mrb_fixnum_value(0));
    mrb_ary_push(mrb, results, mrb_fixnum_value(result));
  }

  return results;
}
#endif

#if BIND_nn_sendmsg_FUNCTION
#define nn_sendmsg_REQUIRED_ARGC 3
#define nn_sendmsg_OPTIONAL_ARGC 0
/* nn_sendmsg
 *
 * Parameters:
 * - s: int
 * - msghdr: const nn_msghdr *
 * - flags: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_sendmsg(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value msghdr;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &msghdr, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, msghdr, NnMsghdr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnMsghdr expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_s = mrb_fixnum(s);

  const nn_msghdr * native_msghdr = (mrb_nil_p(msghdr) ? NULL : mruby_unbox_const nn_msghdr(msghdr));

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  int result = nn_sendmsg(native_s, native_msghdr, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_setsockopt_FUNCTION
#define nn_setsockopt_REQUIRED_ARGC 5
#define nn_setsockopt_OPTIONAL_ARGC 0
/* nn_setsockopt
 *
 * Parameters:
 * - s: int
 * - level: int
 * - option: int
 * - optval: const void *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_setsockopt(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value level;
  mrb_value option;
  mrb_value optval;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &s, &level, &option, &optval);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, level, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, optval, mrb->fixnum_class)
      && !mrb_obj_is_kind_of(mrb, optval, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum or String expected");
    return mrb_nil_value();
  }

  sock_opt_type opt_type;
  if (mrb_obj_is_kind_of(mrb, optval, mrb->fixnum_class)) {
    opt_type = sock_opt_type::INT;
  }
  if (mrb_obj_is_kind_of(mrb, optval, mrb->string_class)) {
    opt_type = sock_opt_type::STRING;
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);
  int native_level = mrb_fixnum(level);
  int native_option = mrb_fixnum(option);
  
  int native_optval_as_int;
  const char * native_optval_as_str;
  int native_optvallen;
  
  /* Invocation */
  int result;
  if (opt_type == sock_opt_type::STRING) {
    native_optval_as_str = mrb_string_value_ptr(mrb, optval);
    native_optvallen = mrb_str_strlen(mrb, mrb_str_ptr(optval));
    result = nn_setsockopt(native_s, native_level, native_option, native_optval_as_str, native_optvallen);
  }
  else if (opt_type == sock_opt_type::INT) {
    native_optval_as_int = mrb_fixnum(optval);
    native_optvallen = sizeof(int);
    result = nn_setsockopt(native_s, native_level, native_option, &native_optval_as_int, native_optvallen);
  }

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  
  mrb_value return_value;
  if (result == 0) {
    return_value = mrb_fixnum_value(result);
  }
  else {
    return_value = mrb_fixnum_value(nn_errno());
  }

  return return_value;
}
#endif

#if BIND_nn_shutdown_FUNCTION
#define nn_shutdown_REQUIRED_ARGC 2
#define nn_shutdown_OPTIONAL_ARGC 0
/* nn_shutdown
 *
 * Parameters:
 * - s: int
 * - how: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_shutdown(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value how;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &how);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, how, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_s = mrb_fixnum(s);
  int native_how = mrb_fixnum(how);

  /* Invocation */
  int result = nn_shutdown(native_s, native_how);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  
  if (result == 0)
    return mrb_fixnum_value(result);
  else
    return mrb_fixnum_value(nn_errno());
}
#endif

#if BIND_nn_sockbase_getctx_FUNCTION
#define nn_sockbase_getctx_REQUIRED_ARGC 1
#define nn_sockbase_getctx_OPTIONAL_ARGC 0
/* nn_sockbase_getctx
 *
 * Parameters:
 * - self: nn_sockbase *
 * Return Type: struct nn_ctx *
 */
mrb_value
mrb_NN_nn_sockbase_getctx(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  /* Invocation */
  struct nn_ctx * result = nn_sockbase_getctx(native_self);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_nn_ctx(mrb, result));

  return return_value;
}
#endif

#if BIND_nn_sockbase_getopt_FUNCTION
#define nn_sockbase_getopt_REQUIRED_ARGC 4
#define nn_sockbase_getopt_OPTIONAL_ARGC 0
/* nn_sockbase_getopt
 *
 * Parameters:
 * - self: nn_sockbase *
 * - option: int
 * - optval: void *
 * - optvallen: int *
 * Return Type: int
 */
mrb_value
mrb_NN_nn_sockbase_getopt(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value option;
  mrb_value optval;
  mrb_value optvallen;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &self, &option, &optval, &optvallen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(optval);
  TODO_type_check_int_PTR(optvallen);


  /* Unbox parameters */
  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  int native_option = mrb_fixnum(option);

  void * native_optval = TODO_mruby_unbox_void_PTR(optval);

  int * native_optvallen = TODO_mruby_unbox_int_PTR(optvallen);

  /* Invocation */
  int result = nn_sockbase_getopt(native_self, native_option, native_optval, native_optvallen);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_sockbase_init_FUNCTION
#define nn_sockbase_init_REQUIRED_ARGC 3
#define nn_sockbase_init_OPTIONAL_ARGC 0
/* nn_sockbase_init
 *
 * Parameters:
 * - self: nn_sockbase *
 * - vfptr: const nn_sockbase_vfptr *
 * - hint: void *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_sockbase_init(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value vfptr;
  mrb_value hint;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &self, &vfptr, &hint);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, vfptr, NnSockbaseVfptr_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbaseVfptr expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(hint);


  /* Unbox parameters */
  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  const nn_sockbase_vfptr * native_vfptr = (mrb_nil_p(vfptr) ? NULL : mruby_unbox_const nn_sockbase_vfptr(vfptr));

  void * native_hint = TODO_mruby_unbox_void_PTR(hint);

  /* Invocation */
  nn_sockbase_init(native_self, native_vfptr, native_hint);

  return mrb_nil_value();
}
#endif

#if BIND_nn_sockbase_stat_increment_FUNCTION
#define nn_sockbase_stat_increment_REQUIRED_ARGC 6
#define nn_sockbase_stat_increment_OPTIONAL_ARGC 0
/* nn_sockbase_stat_increment
 *
 * Parameters:
 * - self: nn_sockbase *
 * - name: int
 * - increment: int
 * - hint: void *
 * - sockbase: nn_sockbase **
 * - socktype: int
 * Return Type: void
 */
mrb_value
mrb_NN_nn_sockbase_stat_increment(mrb_state* mrb, mrb_value self) {
  mrb_value self;
  mrb_value name;
  mrb_value increment;
  mrb_value hint;
  mrb_value sockbase;
  mrb_value socktype;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &self, &name, &increment, &hint, &sockbase, &socktype);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, name, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, increment, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(hint);
  TODO_type_check_nn_sockbase_PTR_PTR(sockbase);
  if (!mrb_obj_is_kind_of(mrb, socktype, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  int native_name = mrb_fixnum(name);

  int native_increment = mrb_fixnum(increment);

  void * native_hint = TODO_mruby_unbox_void_PTR(hint);

  nn_sockbase ** native_sockbase = TODO_mruby_unbox_nn_sockbase_PTR_PTR(sockbase);

  int native_socktype = mrb_fixnum(socktype);

  /* Invocation */
  nn_sockbase_stat_increment(native_self, native_name, native_increment, native_hint, native_sockbase, native_socktype);

  return mrb_nil_value();
}
#endif

#if BIND_nn_sockbase_stopped_FUNCTION
#define nn_sockbase_stopped_REQUIRED_ARGC 1
#define nn_sockbase_stopped_OPTIONAL_ARGC 0
/* nn_sockbase_stopped
 *
 * Parameters:
 * - self: nn_sockbase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_sockbase_stopped(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  /* Invocation */
  nn_sockbase_stopped(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_sockbase_term_FUNCTION
#define nn_sockbase_term_REQUIRED_ARGC 1
#define nn_sockbase_term_OPTIONAL_ARGC 0
/* nn_sockbase_term
 *
 * Parameters:
 * - self: nn_sockbase *
 * Return Type: void
 */
mrb_value
mrb_NN_nn_sockbase_term(mrb_state* mrb, mrb_value self) {
  mrb_value self;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &self);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, self, NnSockbase_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSockbase expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  nn_sockbase * native_self = (mrb_nil_p(self) ? NULL : mruby_unbox_nn_sockbase(self));

  /* Invocation */
  nn_sockbase_term(native_self);

  return mrb_nil_value();
}
#endif

#if BIND_nn_socket_FUNCTION
#define nn_socket_REQUIRED_ARGC 2
#define nn_socket_OPTIONAL_ARGC 0
/* nn_socket
 *
 * Parameters:
 * - domain: Fixnum
 * - protocol: Fixnum
 * Return Type: [errno: Fixnum, socket: Fixnum]
 */
mrb_value
mrb_NN_nn_socket(mrb_state* mrb, mrb_value self) {
  mrb_value domain;
  mrb_value protocol;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &domain, &protocol);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, domain, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, protocol, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_domain = mrb_fixnum(domain);
  int native_protocol = mrb_fixnum(protocol);

  /* Invocation */
  int result = nn_socket(native_domain, native_protocol);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }

  mrb_value results = mrb_ary_new(mrb);
  if (result == -1) {
    mrb_ary_push(mrb, results, mrb_fixnum_value(nn_errno()));
    mrb_ary_push(mrb, results, mrb_nil_value());
  }
  else {
    mrb_ary_push(mrb, results, mrb_fixnum_value(0));
    mrb_ary_push(mrb, results, mrb_fixnum_value(result));
  }
  return results;
}
#endif

#if BIND_nn_strerror_FUNCTION
#define nn_strerror_REQUIRED_ARGC 1
#define nn_strerror_OPTIONAL_ARGC 0
/* nn_strerror
 *
 * Parameters:
 * - errnum: int
 * Return Type: const char *
 */
mrb_value
mrb_NN_nn_strerror(mrb_state* mrb, mrb_value self) {
  mrb_value errnum;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &errnum);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, errnum, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_errnum = mrb_fixnum(errnum);

  /* Invocation */
  const char * result = nn_strerror(native_errnum);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_nn_symbol_FUNCTION
#define nn_symbol_REQUIRED_ARGC 2
#define nn_symbol_OPTIONAL_ARGC 0
/* nn_symbol
 *
 * Parameters:
 * - i: int
 * - value: int *
 * Return Type: const char *
 */
mrb_value
mrb_NN_nn_symbol(mrb_state* mrb, mrb_value self) {
  mrb_value i;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &i, &value);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, i, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(value);


  /* Unbox parameters */
  int native_i = mrb_fixnum(i);

  int * native_value = TODO_mruby_unbox_int_PTR(value);

  /* Invocation */
  const char * result = nn_symbol(native_i, native_value);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_nn_symbol_info_FUNCTION
#define nn_symbol_info_REQUIRED_ARGC 3
#define nn_symbol_info_OPTIONAL_ARGC 0
/* nn_symbol_info
 *
 * Parameters:
 * - i: int
 * - buf: nn_symbol_properties *
 * - buflen: int
 * Return Type: int
 */
mrb_value
mrb_NN_nn_symbol_info(mrb_state* mrb, mrb_value self) {
  mrb_value i;
  mrb_value buf;
  mrb_value buflen;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &i, &buf, &buflen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, i, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buf, NnSymbolProperties_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NnSymbolProperties expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buflen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_i = mrb_fixnum(i);

  nn_symbol_properties * native_buf = (mrb_nil_p(buf) ? NULL : mruby_unbox_nn_symbol_properties(buf));

  int native_buflen = mrb_fixnum(buflen);

  /* Invocation */
  int result = nn_symbol_info(native_i, native_buf, native_buflen);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_nn_term_FUNCTION
#define nn_term_REQUIRED_ARGC 0
#define nn_term_OPTIONAL_ARGC 0
/* nn_term
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NN_nn_term(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  nn_term();
  return mrb_nil_value();
}
#endif


void mrb_mruby_nanomsg_gem_init(mrb_state* mrb) {
  RClass* NN_module = mrb_define_module(mrb, "NN");
  mruby_NN_define_macro_constants(mrb);

  /*
   * Initialize class bindings
   */
#if BIND_NnCmsghdr_TYPE
  mrb_NN_NnCmsghdr_init(mrb);
#endif
#if BIND_NnCp_TYPE
  mrb_NN_NnCp_init(mrb);
#endif
#if BIND_NnCtx_TYPE
  mrb_NN_NnCtx_init(mrb);
#endif
#if BIND_NnEp_TYPE
  mrb_NN_NnEp_init(mrb);
#endif
#if BIND_NnEpOptions_TYPE
  mrb_NN_NnEpOptions_init(mrb);
#endif
#if BIND_NnEpbase_TYPE
  mrb_NN_NnEpbase_init(mrb);
#endif
#if BIND_NnEpbaseVfptr_TYPE
  mrb_NN_NnEpbaseVfptr_init(mrb);
#endif
#if BIND_NnIovec_TYPE
  mrb_NN_NnIovec_init(mrb);
#endif
#if BIND_NnMsghdr_TYPE
  mrb_NN_NnMsghdr_init(mrb);
#endif
#if BIND_NnOptset_TYPE
  mrb_NN_NnOptset_init(mrb);
#endif
#if BIND_NnOptsetVfptr_TYPE
  mrb_NN_NnOptsetVfptr_init(mrb);
#endif
#if BIND_NnPipe_TYPE
  mrb_NN_NnPipe_init(mrb);
#endif
#if BIND_NnPipebase_TYPE
  mrb_NN_NnPipebase_init(mrb);
#endif
#if BIND_NnPipebaseVfptr_TYPE
  mrb_NN_NnPipebaseVfptr_init(mrb);
#endif
#if BIND_NnPollfd_TYPE
  mrb_NN_NnPollfd_init(mrb);
#endif
#if BIND_NnSock_TYPE
  mrb_NN_NnSock_init(mrb);
#endif
#if BIND_NnSockbase_TYPE
  mrb_NN_NnSockbase_init(mrb);
#endif
#if BIND_NnSockbaseVfptr_TYPE
  mrb_NN_NnSockbaseVfptr_init(mrb);
#endif
#if BIND_NnSocktype_TYPE
  mrb_NN_NnSocktype_init(mrb);
#endif
#if BIND_NnSymbolProperties_TYPE
  mrb_NN_NnSymbolProperties_init(mrb);
#endif
#if BIND_NnTransport_TYPE
  mrb_NN_NnTransport_init(mrb);
#endif

  /*
   * Global Functions
   */
#if BIND_nn_allocmsg_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_allocmsg", mrb_NN_nn_allocmsg, MRB_ARGS_ARG(nn_allocmsg_REQUIRED_ARGC, nn_allocmsg_OPTIONAL_ARGC));
#endif
#if BIND_nn_bind_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_bind", mrb_NN_nn_bind, MRB_ARGS_ARG(nn_bind_REQUIRED_ARGC, nn_bind_OPTIONAL_ARGC));
#endif
#if BIND_nn_close_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_close", mrb_NN_nn_close, MRB_ARGS_ARG(nn_close_REQUIRED_ARGC, nn_close_OPTIONAL_ARGC));
#endif
#if BIND_nn_cmsg_nxthdr__FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_cmsg_nxthdr_", mrb_NN_nn_cmsg_nxthdr_, MRB_ARGS_ARG(nn_cmsg_nxthdr__REQUIRED_ARGC, nn_cmsg_nxthdr__OPTIONAL_ARGC));
#endif
#if BIND_nn_connect_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_connect", mrb_NN_nn_connect, MRB_ARGS_ARG(nn_connect_REQUIRED_ARGC, nn_connect_OPTIONAL_ARGC));
#endif
#if BIND_nn_device_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_device", mrb_NN_nn_device, MRB_ARGS_ARG(nn_device_REQUIRED_ARGC, nn_device_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_clear_error_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_clear_error", mrb_NN_nn_epbase_clear_error, MRB_ARGS_ARG(nn_epbase_clear_error_REQUIRED_ARGC, nn_epbase_clear_error_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_getaddr_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_getaddr", mrb_NN_nn_epbase_getaddr, MRB_ARGS_ARG(nn_epbase_getaddr_REQUIRED_ARGC, nn_epbase_getaddr_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_getctx_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_getctx", mrb_NN_nn_epbase_getctx, MRB_ARGS_ARG(nn_epbase_getctx_REQUIRED_ARGC, nn_epbase_getctx_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_getopt_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_getopt", mrb_NN_nn_epbase_getopt, MRB_ARGS_ARG(nn_epbase_getopt_REQUIRED_ARGC, nn_epbase_getopt_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_init_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_init", mrb_NN_nn_epbase_init, MRB_ARGS_ARG(nn_epbase_init_REQUIRED_ARGC, nn_epbase_init_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_ispeer_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_ispeer", mrb_NN_nn_epbase_ispeer, MRB_ARGS_ARG(nn_epbase_ispeer_REQUIRED_ARGC, nn_epbase_ispeer_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_set_error_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_set_error", mrb_NN_nn_epbase_set_error, MRB_ARGS_ARG(nn_epbase_set_error_REQUIRED_ARGC, nn_epbase_set_error_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_stat_increment_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_stat_increment", mrb_NN_nn_epbase_stat_increment, MRB_ARGS_ARG(nn_epbase_stat_increment_REQUIRED_ARGC, nn_epbase_stat_increment_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_stopped_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_stopped", mrb_NN_nn_epbase_stopped, MRB_ARGS_ARG(nn_epbase_stopped_REQUIRED_ARGC, nn_epbase_stopped_OPTIONAL_ARGC));
#endif
#if BIND_nn_epbase_term_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_epbase_term", mrb_NN_nn_epbase_term, MRB_ARGS_ARG(nn_epbase_term_REQUIRED_ARGC, nn_epbase_term_OPTIONAL_ARGC));
#endif
#if BIND_nn_errno_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_errno", mrb_NN_nn_errno, MRB_ARGS_ARG(nn_errno_REQUIRED_ARGC, nn_errno_OPTIONAL_ARGC));
#endif
#if BIND_nn_freemsg_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_freemsg", mrb_NN_nn_freemsg, MRB_ARGS_ARG(nn_freemsg_REQUIRED_ARGC, nn_freemsg_OPTIONAL_ARGC));
#endif
#if BIND_nn_getsockopt_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_getsockopt", mrb_NN_nn_getsockopt, MRB_ARGS_ARG(nn_getsockopt_REQUIRED_ARGC, nn_getsockopt_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipe_getdata_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipe_getdata", mrb_NN_nn_pipe_getdata, MRB_ARGS_ARG(nn_pipe_getdata_REQUIRED_ARGC, nn_pipe_getdata_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipe_getopt_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipe_getopt", mrb_NN_nn_pipe_getopt, MRB_ARGS_ARG(nn_pipe_getopt_REQUIRED_ARGC, nn_pipe_getopt_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipe_recv_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipe_recv", mrb_NN_nn_pipe_recv, MRB_ARGS_ARG(nn_pipe_recv_REQUIRED_ARGC, nn_pipe_recv_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipe_send_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipe_send", mrb_NN_nn_pipe_send, MRB_ARGS_ARG(nn_pipe_send_REQUIRED_ARGC, nn_pipe_send_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipe_setdata_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipe_setdata", mrb_NN_nn_pipe_setdata, MRB_ARGS_ARG(nn_pipe_setdata_REQUIRED_ARGC, nn_pipe_setdata_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_getopt_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_getopt", mrb_NN_nn_pipebase_getopt, MRB_ARGS_ARG(nn_pipebase_getopt_REQUIRED_ARGC, nn_pipebase_getopt_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_init_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_init", mrb_NN_nn_pipebase_init, MRB_ARGS_ARG(nn_pipebase_init_REQUIRED_ARGC, nn_pipebase_init_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_ispeer_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_ispeer", mrb_NN_nn_pipebase_ispeer, MRB_ARGS_ARG(nn_pipebase_ispeer_REQUIRED_ARGC, nn_pipebase_ispeer_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_received_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_received", mrb_NN_nn_pipebase_received, MRB_ARGS_ARG(nn_pipebase_received_REQUIRED_ARGC, nn_pipebase_received_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_sent_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_sent", mrb_NN_nn_pipebase_sent, MRB_ARGS_ARG(nn_pipebase_sent_REQUIRED_ARGC, nn_pipebase_sent_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_start_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_start", mrb_NN_nn_pipebase_start, MRB_ARGS_ARG(nn_pipebase_start_REQUIRED_ARGC, nn_pipebase_start_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_stop_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_stop", mrb_NN_nn_pipebase_stop, MRB_ARGS_ARG(nn_pipebase_stop_REQUIRED_ARGC, nn_pipebase_stop_OPTIONAL_ARGC));
#endif
#if BIND_nn_pipebase_term_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_pipebase_term", mrb_NN_nn_pipebase_term, MRB_ARGS_ARG(nn_pipebase_term_REQUIRED_ARGC, nn_pipebase_term_OPTIONAL_ARGC));
#endif
#if BIND_nn_poll_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_poll", mrb_NN_nn_poll, MRB_ARGS_ARG(nn_poll_REQUIRED_ARGC, nn_poll_OPTIONAL_ARGC));
#endif
#if BIND_nn_reallocmsg_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_reallocmsg", mrb_NN_nn_reallocmsg, MRB_ARGS_ARG(nn_reallocmsg_REQUIRED_ARGC, nn_reallocmsg_OPTIONAL_ARGC));
#endif
#if BIND_nn_recv_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_recv", mrb_NN_nn_recv, MRB_ARGS_ARG(nn_recv_REQUIRED_ARGC, nn_recv_OPTIONAL_ARGC));
#endif
#if BIND_nn_recvmsg_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_recvmsg", mrb_NN_nn_recvmsg, MRB_ARGS_ARG(nn_recvmsg_REQUIRED_ARGC, nn_recvmsg_OPTIONAL_ARGC));
#endif
#if BIND_nn_req_recv_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_req_recv", mrb_NN_nn_req_recv, MRB_ARGS_ARG(nn_req_recv_REQUIRED_ARGC, nn_req_recv_OPTIONAL_ARGC));
#endif
#if BIND_nn_req_send_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_req_send", mrb_NN_nn_req_send, MRB_ARGS_ARG(nn_req_send_REQUIRED_ARGC, nn_req_send_OPTIONAL_ARGC));
#endif
#if BIND_nn_send_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_send", mrb_NN_nn_send, MRB_ARGS_ARG(nn_send_REQUIRED_ARGC, nn_send_OPTIONAL_ARGC));
#endif
#if BIND_nn_sendmsg_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sendmsg", mrb_NN_nn_sendmsg, MRB_ARGS_ARG(nn_sendmsg_REQUIRED_ARGC, nn_sendmsg_OPTIONAL_ARGC));
#endif
#if BIND_nn_setsockopt_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_setsockopt", mrb_NN_nn_setsockopt, MRB_ARGS_ARG(nn_setsockopt_REQUIRED_ARGC, nn_setsockopt_OPTIONAL_ARGC));
#endif
#if BIND_nn_shutdown_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_shutdown", mrb_NN_nn_shutdown, MRB_ARGS_ARG(nn_shutdown_REQUIRED_ARGC, nn_shutdown_OPTIONAL_ARGC));
#endif
#if BIND_nn_sockbase_getctx_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sockbase_getctx", mrb_NN_nn_sockbase_getctx, MRB_ARGS_ARG(nn_sockbase_getctx_REQUIRED_ARGC, nn_sockbase_getctx_OPTIONAL_ARGC));
#endif
#if BIND_nn_sockbase_getopt_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sockbase_getopt", mrb_NN_nn_sockbase_getopt, MRB_ARGS_ARG(nn_sockbase_getopt_REQUIRED_ARGC, nn_sockbase_getopt_OPTIONAL_ARGC));
#endif
#if BIND_nn_sockbase_init_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sockbase_init", mrb_NN_nn_sockbase_init, MRB_ARGS_ARG(nn_sockbase_init_REQUIRED_ARGC, nn_sockbase_init_OPTIONAL_ARGC));
#endif
#if BIND_nn_sockbase_stat_increment_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sockbase_stat_increment", mrb_NN_nn_sockbase_stat_increment, MRB_ARGS_ARG(nn_sockbase_stat_increment_REQUIRED_ARGC, nn_sockbase_stat_increment_OPTIONAL_ARGC));
#endif
#if BIND_nn_sockbase_stopped_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sockbase_stopped", mrb_NN_nn_sockbase_stopped, MRB_ARGS_ARG(nn_sockbase_stopped_REQUIRED_ARGC, nn_sockbase_stopped_OPTIONAL_ARGC));
#endif
#if BIND_nn_sockbase_term_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_sockbase_term", mrb_NN_nn_sockbase_term, MRB_ARGS_ARG(nn_sockbase_term_REQUIRED_ARGC, nn_sockbase_term_OPTIONAL_ARGC));
#endif
#if BIND_nn_socket_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_socket", mrb_NN_nn_socket, MRB_ARGS_ARG(nn_socket_REQUIRED_ARGC, nn_socket_OPTIONAL_ARGC));
#endif
#if BIND_nn_strerror_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_strerror", mrb_NN_nn_strerror, MRB_ARGS_ARG(nn_strerror_REQUIRED_ARGC, nn_strerror_OPTIONAL_ARGC));
#endif
#if BIND_nn_symbol_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_symbol", mrb_NN_nn_symbol, MRB_ARGS_ARG(nn_symbol_REQUIRED_ARGC, nn_symbol_OPTIONAL_ARGC));
#endif
#if BIND_nn_symbol_info_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_symbol_info", mrb_NN_nn_symbol_info, MRB_ARGS_ARG(nn_symbol_info_REQUIRED_ARGC, nn_symbol_info_OPTIONAL_ARGC));
#endif
#if BIND_nn_term_FUNCTION
  mrb_define_class_method(mrb, NN_module, "nn_term", mrb_NN_nn_term, MRB_ARGS_ARG(nn_term_REQUIRED_ARGC, nn_term_OPTIONAL_ARGC));
#endif

}

void mrb_mruby_nanomsg_gem_final(mrb_state* mrb){

}

#ifdef __cplusplus
}
#endif
