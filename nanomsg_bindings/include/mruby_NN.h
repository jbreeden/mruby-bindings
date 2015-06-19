
#ifndef NN_HEADER
#define NN_HEADER

/*
 * RClass Macros
 * -------------
 *
 * Macros for retrieving the RClass*'s defined by this gem.
 */

#define NN_module(mrb) mrb_module_get(mrb, "NN")
#define NnCmsghdr_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnCmsghdr")
#define NnCp_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnCp")
#define NnCtx_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnCtx")
#define NnEp_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnEp")
#define NnEpOptions_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnEpOptions")
#define NnEpbase_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnEpbase")
#define NnEpbaseVfptr_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnEpbaseVfptr")
#define NnIovec_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnIovec")
#define NnMsghdr_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnMsghdr")
#define NnOptset_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnOptset")
#define NnOptsetVfptr_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnOptsetVfptr")
#define NnPipe_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnPipe")
#define NnPipebase_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnPipebase")
#define NnPipebaseVfptr_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnPipebaseVfptr")
#define NnPollfd_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnPollfd")
#define NnSock_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnSock")
#define NnSockbase_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnSockbase")
#define NnSockbaseVfptr_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnSockbaseVfptr")
#define NnSocktype_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnSocktype")
#define NnSymbolProperties_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnSymbolProperties")
#define NnTransport_class(mrb) mrb_class_get_under(mrb, NN_module(mrb), "NnTransport")

/*
 * Class Bindings Options
 * ----------------------
 *
 * Use these macros to configure the generated bindings for classes & structs.
 *
 * Key:
 *
 * BIND_{type name}_TYPE                     : Should we bind the class at all?
 * BIND_{type name}_INITIALIZE               : If the class is bound, should we also bind initialize to malloc a new instance on `new`?
 * BIND_{type name}_{field name}_FIELD       : If the class is bound, should we also bind this field?
 * BIND_{type name}_{function name}_FUNCTION : If the class is bound, should we also bind this member function?
 *
 * Fields & method are disabled by default so that bindings may be added and
 * tested incrementally. The generated bindings are a good start, but they
 * will need to be verified and, sometimes, customized.
 */

#define BIND_NnCmsghdr_TYPE TRUE
#define BIND_NnCmsghdr_INITIALIZE FALSE
#define BIND_NnCmsghdr_cmsg_len_FIELD FALSE
#define BIND_NnCmsghdr_cmsg_level_FIELD FALSE
#define BIND_NnCmsghdr_cmsg_type_FIELD FALSE

#define BIND_NnCp_TYPE TRUE
#define BIND_NnCp_INITIALIZE FALSE

#define BIND_NnCtx_TYPE TRUE
#define BIND_NnCtx_INITIALIZE FALSE

#define BIND_NnEp_TYPE TRUE
#define BIND_NnEp_INITIALIZE FALSE

#define BIND_NnEpOptions_TYPE TRUE
#define BIND_NnEpOptions_INITIALIZE FALSE
#define BIND_NnEpOptions_ipv4only_FIELD FALSE
#define BIND_NnEpOptions_rcvprio_FIELD FALSE
#define BIND_NnEpOptions_sndprio_FIELD FALSE

#define BIND_NnEpbase_TYPE TRUE
#define BIND_NnEpbase_INITIALIZE FALSE
#define BIND_NnEpbase_ep_FIELD FALSE
#define BIND_NnEpbase_vfptr_FIELD FALSE

#define BIND_NnEpbaseVfptr_TYPE TRUE
#define BIND_NnEpbaseVfptr_INITIALIZE FALSE
#define BIND_NnEpbaseVfptr_destroy_FIELD FALSE
#define BIND_NnEpbaseVfptr_stop_FIELD FALSE

#define BIND_NnIovec_TYPE TRUE
#define BIND_NnIovec_INITIALIZE FALSE
#define BIND_NnIovec_iov_base_FIELD FALSE
#define BIND_NnIovec_iov_len_FIELD FALSE

#define BIND_NnMsghdr_TYPE TRUE
#define BIND_NnMsghdr_INITIALIZE FALSE
#define BIND_NnMsghdr_msg_control_FIELD FALSE
#define BIND_NnMsghdr_msg_controllen_FIELD FALSE
#define BIND_NnMsghdr_msg_iov_FIELD FALSE
#define BIND_NnMsghdr_msg_iovlen_FIELD FALSE

#define BIND_NnOptset_TYPE TRUE
#define BIND_NnOptset_INITIALIZE FALSE
#define BIND_NnOptset_vfptr_FIELD FALSE

#define BIND_NnOptsetVfptr_TYPE TRUE
#define BIND_NnOptsetVfptr_INITIALIZE FALSE
#define BIND_NnOptsetVfptr_destroy_FIELD FALSE
#define BIND_NnOptsetVfptr_getopt_FIELD FALSE
#define BIND_NnOptsetVfptr_setopt_FIELD FALSE

#define BIND_NnPipe_TYPE TRUE
#define BIND_NnPipe_INITIALIZE FALSE

#define BIND_NnPipebase_TYPE TRUE
#define BIND_NnPipebase_INITIALIZE FALSE
#define BIND_NnPipebase_data_FIELD FALSE
#define BIND_NnPipebase_fsm_FIELD FALSE
#define BIND_NnPipebase_in_FIELD FALSE
#define BIND_NnPipebase_instate_FIELD FALSE
#define BIND_NnPipebase_options_FIELD FALSE
#define BIND_NnPipebase_out_FIELD FALSE
#define BIND_NnPipebase_outstate_FIELD FALSE
#define BIND_NnPipebase_sock_FIELD FALSE
#define BIND_NnPipebase_state_FIELD FALSE
#define BIND_NnPipebase_vfptr_FIELD FALSE

#define BIND_NnPipebaseVfptr_TYPE TRUE
#define BIND_NnPipebaseVfptr_INITIALIZE FALSE
#define BIND_NnPipebaseVfptr_recv_FIELD FALSE
#define BIND_NnPipebaseVfptr_send_FIELD FALSE

#define BIND_NnPollfd_TYPE TRUE
#define BIND_NnPollfd_INITIALIZE FALSE
#define BIND_NnPollfd_events_FIELD FALSE
#define BIND_NnPollfd_fd_FIELD FALSE
#define BIND_NnPollfd_revents_FIELD FALSE

#define BIND_NnSock_TYPE TRUE
#define BIND_NnSock_INITIALIZE FALSE

#define BIND_NnSockbase_TYPE TRUE
#define BIND_NnSockbase_INITIALIZE FALSE
#define BIND_NnSockbase_sock_FIELD FALSE
#define BIND_NnSockbase_vfptr_FIELD FALSE

#define BIND_NnSockbaseVfptr_TYPE TRUE
#define BIND_NnSockbaseVfptr_INITIALIZE FALSE
#define BIND_NnSockbaseVfptr_add_FIELD FALSE
#define BIND_NnSockbaseVfptr_destroy_FIELD FALSE
#define BIND_NnSockbaseVfptr_events_FIELD FALSE
#define BIND_NnSockbaseVfptr_getopt_FIELD FALSE
#define BIND_NnSockbaseVfptr_in_FIELD FALSE
#define BIND_NnSockbaseVfptr_out_FIELD FALSE
#define BIND_NnSockbaseVfptr_recv_FIELD FALSE
#define BIND_NnSockbaseVfptr_rm_FIELD FALSE
#define BIND_NnSockbaseVfptr_send_FIELD FALSE
#define BIND_NnSockbaseVfptr_setopt_FIELD FALSE
#define BIND_NnSockbaseVfptr_stop_FIELD FALSE

#define BIND_NnSocktype_TYPE TRUE
#define BIND_NnSocktype_INITIALIZE FALSE
#define BIND_NnSocktype_create_FIELD FALSE
#define BIND_NnSocktype_domain_FIELD FALSE
#define BIND_NnSocktype_flags_FIELD FALSE
#define BIND_NnSocktype_ispeer_FIELD FALSE
#define BIND_NnSocktype_item_FIELD FALSE
#define BIND_NnSocktype_protocol_FIELD FALSE

#define BIND_NnSymbolProperties_TYPE TRUE
#define BIND_NnSymbolProperties_INITIALIZE FALSE
#define BIND_NnSymbolProperties_name_FIELD FALSE
#define BIND_NnSymbolProperties_ns_FIELD FALSE
#define BIND_NnSymbolProperties_type_FIELD FALSE
#define BIND_NnSymbolProperties_unit_FIELD FALSE
#define BIND_NnSymbolProperties_value_FIELD FALSE

#define BIND_NnTransport_TYPE TRUE
#define BIND_NnTransport_INITIALIZE FALSE
#define BIND_NnTransport_bind_FIELD FALSE
#define BIND_NnTransport_connect_FIELD FALSE
#define BIND_NnTransport_id_FIELD FALSE
#define BIND_NnTransport_init_FIELD FALSE
#define BIND_NnTransport_item_FIELD FALSE
#define BIND_NnTransport_name_FIELD FALSE
#define BIND_NnTransport_optset_FIELD FALSE
#define BIND_NnTransport_term_FIELD FALSE


/*
 * Global Function Options
 * -----------------------
 *
 * Set these macros to TRUE to enable bindings for these functions.
 * They are disabled initially so that bindings may be added and tested
 * incrementally. The generated bindings are a good start, but they
 * will need to be verified and, sometimes, customized.
 */

#define BIND_nn_allocmsg_FUNCTION FALSE
#define BIND_nn_bind_FUNCTION FALSE
#define BIND_nn_close_FUNCTION FALSE
#define BIND_nn_cmsg_nxthdr__FUNCTION FALSE
#define BIND_nn_connect_FUNCTION FALSE
#define BIND_nn_device_FUNCTION FALSE
#define BIND_nn_epbase_clear_error_FUNCTION FALSE
#define BIND_nn_epbase_getaddr_FUNCTION FALSE
#define BIND_nn_epbase_getctx_FUNCTION FALSE
#define BIND_nn_epbase_getopt_FUNCTION FALSE
#define BIND_nn_epbase_init_FUNCTION FALSE
#define BIND_nn_epbase_ispeer_FUNCTION FALSE
#define BIND_nn_epbase_set_error_FUNCTION FALSE
#define BIND_nn_epbase_stat_increment_FUNCTION FALSE
#define BIND_nn_epbase_stopped_FUNCTION FALSE
#define BIND_nn_epbase_term_FUNCTION FALSE
#define BIND_nn_errno_FUNCTION FALSE
#define BIND_nn_freemsg_FUNCTION FALSE
#define BIND_nn_getsockopt_FUNCTION FALSE
#define BIND_nn_pipe_getdata_FUNCTION FALSE
#define BIND_nn_pipe_getopt_FUNCTION FALSE
#define BIND_nn_pipe_recv_FUNCTION FALSE
#define BIND_nn_pipe_send_FUNCTION FALSE
#define BIND_nn_pipe_setdata_FUNCTION FALSE
#define BIND_nn_pipebase_getopt_FUNCTION FALSE
#define BIND_nn_pipebase_init_FUNCTION FALSE
#define BIND_nn_pipebase_ispeer_FUNCTION FALSE
#define BIND_nn_pipebase_received_FUNCTION FALSE
#define BIND_nn_pipebase_sent_FUNCTION FALSE
#define BIND_nn_pipebase_start_FUNCTION FALSE
#define BIND_nn_pipebase_stop_FUNCTION FALSE
#define BIND_nn_pipebase_term_FUNCTION FALSE
#define BIND_nn_poll_FUNCTION FALSE
#define BIND_nn_reallocmsg_FUNCTION FALSE
#define BIND_nn_recv_FUNCTION FALSE
#define BIND_nn_recvmsg_FUNCTION FALSE
#define BIND_nn_req_recv_FUNCTION FALSE
#define BIND_nn_req_send_FUNCTION FALSE
#define BIND_nn_send_FUNCTION FALSE
#define BIND_nn_sendmsg_FUNCTION FALSE
#define BIND_nn_setsockopt_FUNCTION FALSE
#define BIND_nn_shutdown_FUNCTION FALSE
#define BIND_nn_sockbase_getctx_FUNCTION FALSE
#define BIND_nn_sockbase_getopt_FUNCTION FALSE
#define BIND_nn_sockbase_init_FUNCTION FALSE
#define BIND_nn_sockbase_stat_increment_FUNCTION FALSE
#define BIND_nn_sockbase_stopped_FUNCTION FALSE
#define BIND_nn_sockbase_term_FUNCTION FALSE
#define BIND_nn_socket_FUNCTION FALSE
#define BIND_nn_strerror_FUNCTION FALSE
#define BIND_nn_symbol_FUNCTION FALSE
#define BIND_nn_symbol_info_FUNCTION FALSE
#define BIND_nn_term_FUNCTION FALSE

/*
 * Header Files
 * ------------
 *
 * These are the header files that defined the
 * classes and functions for which bindings have
 * been generated. If any of these are not needed
 * they should be commented out.
 */

#include <stdlib.h>
#include "mruby.h"
#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mruby/value.h"
#include "mruby/variable.h"
#include "bus.h"
#include "inproc.h"
#include "ipc.h"
#include "nn.h"
#include "pair.h"
#include "pipeline.h"
#include "protocol.h"
#include "pubsub.h"
#include "reqrep.h"
#include "survey.h"
#include "tcp.h"
#include "transport.h"

/*
 * Class initialization function declarations
 * ------------------------------------------
 *
 * These declarations are controlled by the macros in the
 * "Class Bindings Options" section above.
 */

#if BIND_NnCmsghdr_TYPE
void mrb_NN_NnCmsghdr_init(mrb_state* mrb);
#endif
#if BIND_NnCp_TYPE
void mrb_NN_NnCp_init(mrb_state* mrb);
#endif
#if BIND_NnCtx_TYPE
void mrb_NN_NnCtx_init(mrb_state* mrb);
#endif
#if BIND_NnEp_TYPE
void mrb_NN_NnEp_init(mrb_state* mrb);
#endif
#if BIND_NnEpOptions_TYPE
void mrb_NN_NnEpOptions_init(mrb_state* mrb);
#endif
#if BIND_NnEpbase_TYPE
void mrb_NN_NnEpbase_init(mrb_state* mrb);
#endif
#if BIND_NnEpbaseVfptr_TYPE
void mrb_NN_NnEpbaseVfptr_init(mrb_state* mrb);
#endif
#if BIND_NnIovec_TYPE
void mrb_NN_NnIovec_init(mrb_state* mrb);
#endif
#if BIND_NnMsghdr_TYPE
void mrb_NN_NnMsghdr_init(mrb_state* mrb);
#endif
#if BIND_NnOptset_TYPE
void mrb_NN_NnOptset_init(mrb_state* mrb);
#endif
#if BIND_NnOptsetVfptr_TYPE
void mrb_NN_NnOptsetVfptr_init(mrb_state* mrb);
#endif
#if BIND_NnPipe_TYPE
void mrb_NN_NnPipe_init(mrb_state* mrb);
#endif
#if BIND_NnPipebase_TYPE
void mrb_NN_NnPipebase_init(mrb_state* mrb);
#endif
#if BIND_NnPipebaseVfptr_TYPE
void mrb_NN_NnPipebaseVfptr_init(mrb_state* mrb);
#endif
#if BIND_NnPollfd_TYPE
void mrb_NN_NnPollfd_init(mrb_state* mrb);
#endif
#if BIND_NnSock_TYPE
void mrb_NN_NnSock_init(mrb_state* mrb);
#endif
#if BIND_NnSockbase_TYPE
void mrb_NN_NnSockbase_init(mrb_state* mrb);
#endif
#if BIND_NnSockbaseVfptr_TYPE
void mrb_NN_NnSockbaseVfptr_init(mrb_state* mrb);
#endif
#if BIND_NnSocktype_TYPE
void mrb_NN_NnSocktype_init(mrb_state* mrb);
#endif
#if BIND_NnSymbolProperties_TYPE
void mrb_NN_NnSymbolProperties_init(mrb_state* mrb);
#endif
#if BIND_NnTransport_TYPE
void mrb_NN_NnTransport_init(mrb_state* mrb);
#endif

/*
 * Boxing declarations
 * -------------------
 *
 * These declarations are controlled by the macros in the
 * "Class Bindings Options" section above.
 */

/*
* Extra wrapper over native pointer to indicate who owns this memory.
* (Either mruby, and it should be garage collected, or C, and it shouldn't be)
* Considered using the LSB of the pointer itself, but I don't think I can
* be assured that all memory is word-aligned (especially when C libraries
* implement their own memory management techniques like memory pools)
*/
typedef struct mruby_to_native_ref_ {
  /* If true, indicates that the object should be freed when
   * mruby GC's the ruby object containing this pointer. This
   * is set to true when an object is boxed via the `giftwrap`
   * or `gift_{type}_ptr_set` functions.
   */
  unsigned char belongs_to_ruby;

  /* A pointer to the native object */
  void* obj;

  /* For the convenience of the binding writer,
   * the data pointer can be used to associate arbitrary
   * data with a reference to a C object. This could
   * be a function pointer to invoke instead of `free` on GC,
   * a pointer back to the RObject, or even cast to an integer type
   * and used as a bit field. You get the idea...
   */
  void* data;
} mruby_to_native_ref;

#if BIND_NnCmsghdr_TYPE
mrb_value
mruby_box_nn_cmsghdr(mrb_state* mrb, nn_cmsghdr *unboxed);

mrb_value
mruby_giftwrap_nn_cmsghdr(mrb_state* mrb, nn_cmsghdr *unboxed);

void
mruby_set_nn_cmsghdr_data_ptr(mrb_value obj, nn_cmsghdr *unboxed);

void
mruby_gift_nn_cmsghdr_data_ptr(mrb_value obj, nn_cmsghdr *unboxed);

nn_cmsghdr *
mruby_unbox_nn_cmsghdr(mrb_value boxed);
#endif

#if BIND_NnCp_TYPE
mrb_value
mruby_box_nn_cp(mrb_state* mrb, nn_cp *unboxed);

mrb_value
mruby_giftwrap_nn_cp(mrb_state* mrb, nn_cp *unboxed);

void
mruby_set_nn_cp_data_ptr(mrb_value obj, nn_cp *unboxed);

void
mruby_gift_nn_cp_data_ptr(mrb_value obj, nn_cp *unboxed);

nn_cp *
mruby_unbox_nn_cp(mrb_value boxed);
#endif

#if BIND_NnCtx_TYPE
mrb_value
mruby_box_nn_ctx(mrb_state* mrb, nn_ctx *unboxed);

mrb_value
mruby_giftwrap_nn_ctx(mrb_state* mrb, nn_ctx *unboxed);

void
mruby_set_nn_ctx_data_ptr(mrb_value obj, nn_ctx *unboxed);

void
mruby_gift_nn_ctx_data_ptr(mrb_value obj, nn_ctx *unboxed);

nn_ctx *
mruby_unbox_nn_ctx(mrb_value boxed);
#endif

#if BIND_NnEp_TYPE
mrb_value
mruby_box_nn_ep(mrb_state* mrb, nn_ep *unboxed);

mrb_value
mruby_giftwrap_nn_ep(mrb_state* mrb, nn_ep *unboxed);

void
mruby_set_nn_ep_data_ptr(mrb_value obj, nn_ep *unboxed);

void
mruby_gift_nn_ep_data_ptr(mrb_value obj, nn_ep *unboxed);

nn_ep *
mruby_unbox_nn_ep(mrb_value boxed);
#endif

#if BIND_NnEpOptions_TYPE
mrb_value
mruby_box_nn_ep_options(mrb_state* mrb, nn_ep_options *unboxed);

mrb_value
mruby_giftwrap_nn_ep_options(mrb_state* mrb, nn_ep_options *unboxed);

void
mruby_set_nn_ep_options_data_ptr(mrb_value obj, nn_ep_options *unboxed);

void
mruby_gift_nn_ep_options_data_ptr(mrb_value obj, nn_ep_options *unboxed);

nn_ep_options *
mruby_unbox_nn_ep_options(mrb_value boxed);
#endif

#if BIND_NnEpbase_TYPE
mrb_value
mruby_box_nn_epbase(mrb_state* mrb, nn_epbase *unboxed);

mrb_value
mruby_giftwrap_nn_epbase(mrb_state* mrb, nn_epbase *unboxed);

void
mruby_set_nn_epbase_data_ptr(mrb_value obj, nn_epbase *unboxed);

void
mruby_gift_nn_epbase_data_ptr(mrb_value obj, nn_epbase *unboxed);

nn_epbase *
mruby_unbox_nn_epbase(mrb_value boxed);
#endif

#if BIND_NnEpbaseVfptr_TYPE
mrb_value
mruby_box_nn_epbase_vfptr(mrb_state* mrb, nn_epbase_vfptr *unboxed);

mrb_value
mruby_giftwrap_nn_epbase_vfptr(mrb_state* mrb, nn_epbase_vfptr *unboxed);

void
mruby_set_nn_epbase_vfptr_data_ptr(mrb_value obj, nn_epbase_vfptr *unboxed);

void
mruby_gift_nn_epbase_vfptr_data_ptr(mrb_value obj, nn_epbase_vfptr *unboxed);

nn_epbase_vfptr *
mruby_unbox_nn_epbase_vfptr(mrb_value boxed);
#endif

#if BIND_NnIovec_TYPE
mrb_value
mruby_box_nn_iovec(mrb_state* mrb, nn_iovec *unboxed);

mrb_value
mruby_giftwrap_nn_iovec(mrb_state* mrb, nn_iovec *unboxed);

void
mruby_set_nn_iovec_data_ptr(mrb_value obj, nn_iovec *unboxed);

void
mruby_gift_nn_iovec_data_ptr(mrb_value obj, nn_iovec *unboxed);

nn_iovec *
mruby_unbox_nn_iovec(mrb_value boxed);
#endif

#if BIND_NnMsghdr_TYPE
mrb_value
mruby_box_nn_msghdr(mrb_state* mrb, nn_msghdr *unboxed);

mrb_value
mruby_giftwrap_nn_msghdr(mrb_state* mrb, nn_msghdr *unboxed);

void
mruby_set_nn_msghdr_data_ptr(mrb_value obj, nn_msghdr *unboxed);

void
mruby_gift_nn_msghdr_data_ptr(mrb_value obj, nn_msghdr *unboxed);

nn_msghdr *
mruby_unbox_nn_msghdr(mrb_value boxed);
#endif

#if BIND_NnOptset_TYPE
mrb_value
mruby_box_nn_optset(mrb_state* mrb, nn_optset *unboxed);

mrb_value
mruby_giftwrap_nn_optset(mrb_state* mrb, nn_optset *unboxed);

void
mruby_set_nn_optset_data_ptr(mrb_value obj, nn_optset *unboxed);

void
mruby_gift_nn_optset_data_ptr(mrb_value obj, nn_optset *unboxed);

nn_optset *
mruby_unbox_nn_optset(mrb_value boxed);
#endif

#if BIND_NnOptsetVfptr_TYPE
mrb_value
mruby_box_nn_optset_vfptr(mrb_state* mrb, nn_optset_vfptr *unboxed);

mrb_value
mruby_giftwrap_nn_optset_vfptr(mrb_state* mrb, nn_optset_vfptr *unboxed);

void
mruby_set_nn_optset_vfptr_data_ptr(mrb_value obj, nn_optset_vfptr *unboxed);

void
mruby_gift_nn_optset_vfptr_data_ptr(mrb_value obj, nn_optset_vfptr *unboxed);

nn_optset_vfptr *
mruby_unbox_nn_optset_vfptr(mrb_value boxed);
#endif

#if BIND_NnPipe_TYPE
mrb_value
mruby_box_nn_pipe(mrb_state* mrb, nn_pipe *unboxed);

mrb_value
mruby_giftwrap_nn_pipe(mrb_state* mrb, nn_pipe *unboxed);

void
mruby_set_nn_pipe_data_ptr(mrb_value obj, nn_pipe *unboxed);

void
mruby_gift_nn_pipe_data_ptr(mrb_value obj, nn_pipe *unboxed);

nn_pipe *
mruby_unbox_nn_pipe(mrb_value boxed);
#endif

#if BIND_NnPipebase_TYPE
mrb_value
mruby_box_nn_pipebase(mrb_state* mrb, nn_pipebase *unboxed);

mrb_value
mruby_giftwrap_nn_pipebase(mrb_state* mrb, nn_pipebase *unboxed);

void
mruby_set_nn_pipebase_data_ptr(mrb_value obj, nn_pipebase *unboxed);

void
mruby_gift_nn_pipebase_data_ptr(mrb_value obj, nn_pipebase *unboxed);

nn_pipebase *
mruby_unbox_nn_pipebase(mrb_value boxed);
#endif

#if BIND_NnPipebaseVfptr_TYPE
mrb_value
mruby_box_nn_pipebase_vfptr(mrb_state* mrb, nn_pipebase_vfptr *unboxed);

mrb_value
mruby_giftwrap_nn_pipebase_vfptr(mrb_state* mrb, nn_pipebase_vfptr *unboxed);

void
mruby_set_nn_pipebase_vfptr_data_ptr(mrb_value obj, nn_pipebase_vfptr *unboxed);

void
mruby_gift_nn_pipebase_vfptr_data_ptr(mrb_value obj, nn_pipebase_vfptr *unboxed);

nn_pipebase_vfptr *
mruby_unbox_nn_pipebase_vfptr(mrb_value boxed);
#endif

#if BIND_NnPollfd_TYPE
mrb_value
mruby_box_nn_pollfd(mrb_state* mrb, nn_pollfd *unboxed);

mrb_value
mruby_giftwrap_nn_pollfd(mrb_state* mrb, nn_pollfd *unboxed);

void
mruby_set_nn_pollfd_data_ptr(mrb_value obj, nn_pollfd *unboxed);

void
mruby_gift_nn_pollfd_data_ptr(mrb_value obj, nn_pollfd *unboxed);

nn_pollfd *
mruby_unbox_nn_pollfd(mrb_value boxed);
#endif

#if BIND_NnSock_TYPE
mrb_value
mruby_box_nn_sock(mrb_state* mrb, nn_sock *unboxed);

mrb_value
mruby_giftwrap_nn_sock(mrb_state* mrb, nn_sock *unboxed);

void
mruby_set_nn_sock_data_ptr(mrb_value obj, nn_sock *unboxed);

void
mruby_gift_nn_sock_data_ptr(mrb_value obj, nn_sock *unboxed);

nn_sock *
mruby_unbox_nn_sock(mrb_value boxed);
#endif

#if BIND_NnSockbase_TYPE
mrb_value
mruby_box_nn_sockbase(mrb_state* mrb, nn_sockbase *unboxed);

mrb_value
mruby_giftwrap_nn_sockbase(mrb_state* mrb, nn_sockbase *unboxed);

void
mruby_set_nn_sockbase_data_ptr(mrb_value obj, nn_sockbase *unboxed);

void
mruby_gift_nn_sockbase_data_ptr(mrb_value obj, nn_sockbase *unboxed);

nn_sockbase *
mruby_unbox_nn_sockbase(mrb_value boxed);
#endif

#if BIND_NnSockbaseVfptr_TYPE
mrb_value
mruby_box_nn_sockbase_vfptr(mrb_state* mrb, nn_sockbase_vfptr *unboxed);

mrb_value
mruby_giftwrap_nn_sockbase_vfptr(mrb_state* mrb, nn_sockbase_vfptr *unboxed);

void
mruby_set_nn_sockbase_vfptr_data_ptr(mrb_value obj, nn_sockbase_vfptr *unboxed);

void
mruby_gift_nn_sockbase_vfptr_data_ptr(mrb_value obj, nn_sockbase_vfptr *unboxed);

nn_sockbase_vfptr *
mruby_unbox_nn_sockbase_vfptr(mrb_value boxed);
#endif

#if BIND_NnSocktype_TYPE
mrb_value
mruby_box_nn_socktype(mrb_state* mrb, nn_socktype *unboxed);

mrb_value
mruby_giftwrap_nn_socktype(mrb_state* mrb, nn_socktype *unboxed);

void
mruby_set_nn_socktype_data_ptr(mrb_value obj, nn_socktype *unboxed);

void
mruby_gift_nn_socktype_data_ptr(mrb_value obj, nn_socktype *unboxed);

nn_socktype *
mruby_unbox_nn_socktype(mrb_value boxed);
#endif

#if BIND_NnSymbolProperties_TYPE
mrb_value
mruby_box_nn_symbol_properties(mrb_state* mrb, nn_symbol_properties *unboxed);

mrb_value
mruby_giftwrap_nn_symbol_properties(mrb_state* mrb, nn_symbol_properties *unboxed);

void
mruby_set_nn_symbol_properties_data_ptr(mrb_value obj, nn_symbol_properties *unboxed);

void
mruby_gift_nn_symbol_properties_data_ptr(mrb_value obj, nn_symbol_properties *unboxed);

nn_symbol_properties *
mruby_unbox_nn_symbol_properties(mrb_value boxed);
#endif

#if BIND_NnTransport_TYPE
mrb_value
mruby_box_nn_transport(mrb_state* mrb, nn_transport *unboxed);

mrb_value
mruby_giftwrap_nn_transport(mrb_state* mrb, nn_transport *unboxed);

void
mruby_set_nn_transport_data_ptr(mrb_value obj, nn_transport *unboxed);

void
mruby_gift_nn_transport_data_ptr(mrb_value obj, nn_transport *unboxed);

nn_transport *
mruby_unbox_nn_transport(mrb_value boxed);
#endif


/*
 * Macro definition function declaration
 * -------------------------------------
 */
void mruby_NN_define_macro_constants(mrb_state* mrb);

#endif
