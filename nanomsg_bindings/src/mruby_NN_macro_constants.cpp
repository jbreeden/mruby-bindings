#include "mruby_NN.h"

void
mruby_NN_define_macro_constants(mrb_state* mrb) {
  /* WARNING
   * Code generator does it's best to determine the type of the macro
   * expansions, but mistakes will be made (as macros are just text,
   * and may contain other macros). So, you'll need to verify the
   * conversions used here are of the correct type.
   */

#ifdef AF_SP
  /* AF_SP assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "AF_SP", mrb_fixnum_value(AF_SP));
#endif
#ifdef AF_SP_RAW
  /* AF_SP_RAW assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "AF_SP_RAW", mrb_fixnum_value(AF_SP_RAW));
#endif
#ifdef BUS_H_INCLUDED
  /* Ignoring macro with no expansion: BUS_H_INCLUDED */
#endif
#ifdef EACCESS
  /* EACCESS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EACCESS", mrb_fixnum_value(EACCESS));
#endif
#ifdef EADDRINUSE
  /* EADDRINUSE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EADDRINUSE", mrb_fixnum_value(EADDRINUSE));
#endif
#ifdef EADDRNOTAVAIL
  /* EADDRNOTAVAIL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EADDRNOTAVAIL", mrb_fixnum_value(EADDRNOTAVAIL));
#endif
#ifdef EAFNOSUPPORT
  /* EAFNOSUPPORT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EAFNOSUPPORT", mrb_fixnum_value(EAFNOSUPPORT));
#endif
#ifdef ECONNABORTED
  /* ECONNABORTED assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ECONNABORTED", mrb_fixnum_value(ECONNABORTED));
#endif
#ifdef ECONNREFUSED
  /* ECONNREFUSED assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ECONNREFUSED", mrb_fixnum_value(ECONNREFUSED));
#endif
#ifdef ECONNRESET
  /* ECONNRESET assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ECONNRESET", mrb_fixnum_value(ECONNRESET));
#endif
#ifdef EFSM
  /* EFSM assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EFSM", mrb_fixnum_value(EFSM));
#endif
#ifdef EHOSTUNREACH
  /* EHOSTUNREACH assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EHOSTUNREACH", mrb_fixnum_value(EHOSTUNREACH));
#endif
#ifdef EINPROGRESS
  /* EINPROGRESS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EINPROGRESS", mrb_fixnum_value(EINPROGRESS));
#endif
#ifdef EISCONN
  /* EISCONN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EISCONN", mrb_fixnum_value(EISCONN));
#endif
#ifdef EMSGSIZE
  /* EMSGSIZE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EMSGSIZE", mrb_fixnum_value(EMSGSIZE));
#endif
#ifdef ENETDOWN
  /* ENETDOWN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENETDOWN", mrb_fixnum_value(ENETDOWN));
#endif
#ifdef ENETRESET
  /* ENETRESET assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENETRESET", mrb_fixnum_value(ENETRESET));
#endif
#ifdef ENETUNREACH
  /* ENETUNREACH assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENETUNREACH", mrb_fixnum_value(ENETUNREACH));
#endif
#ifdef ENOBUFS
  /* ENOBUFS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENOBUFS", mrb_fixnum_value(ENOBUFS));
#endif
#ifdef ENOPROTOOPT
  /* ENOPROTOOPT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENOPROTOOPT", mrb_fixnum_value(ENOPROTOOPT));
#endif
#ifdef ENOTCONN
  /* ENOTCONN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENOTCONN", mrb_fixnum_value(ENOTCONN));
#endif
#ifdef ENOTSOCK
  /* ENOTSOCK assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENOTSOCK", mrb_fixnum_value(ENOTSOCK));
#endif
#ifdef ENOTSUP
  /* ENOTSUP assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ENOTSUP", mrb_fixnum_value(ENOTSUP));
#endif
#ifdef EPROTO
  /* EPROTO assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EPROTO", mrb_fixnum_value(EPROTO));
#endif
#ifdef EPROTONOSUPPORT
  /* EPROTONOSUPPORT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "EPROTONOSUPPORT", mrb_fixnum_value(EPROTONOSUPPORT));
#endif
#ifdef ESOCKTNOSUPPORT
  /* ESOCKTNOSUPPORT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ESOCKTNOSUPPORT", mrb_fixnum_value(ESOCKTNOSUPPORT));
#endif
#ifdef ETERM
  /* ETERM assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ETERM", mrb_fixnum_value(ETERM));
#endif
#ifdef ETIMEDOUT
  /* ETIMEDOUT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "ETIMEDOUT", mrb_fixnum_value(ETIMEDOUT));
#endif
#ifdef INPROC_H_INCLUDED
  /* Ignoring macro with no expansion: INPROC_H_INCLUDED */
#endif
#ifdef IPC_H_INCLUDED
  /* Ignoring macro with no expansion: IPC_H_INCLUDED */
#endif
#ifdef NN_BUS
  /* NN_BUS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_BUS", mrb_fixnum_value(NN_BUS));
#endif
#ifdef NN_CMSG_ALIGN_
  /* Ignoring function-like macro: NN_CMSG_ALIGN_(len) */
#endif
#ifdef NN_CMSG_DATA
  /* Ignoring function-like macro: NN_CMSG_DATA(cmsg) */
#endif
#ifdef NN_CMSG_FIRSTHDR
  /* Ignoring function-like macro: NN_CMSG_FIRSTHDR(mhdr) */
#endif
#ifdef NN_CMSG_LEN
  /* Ignoring function-like macro: NN_CMSG_LEN(len) */
#endif
#ifdef NN_CMSG_NXTHDR
  /* Ignoring function-like macro: NN_CMSG_NXTHDR(mhdr, cmsg) */
#endif
#ifdef NN_CMSG_SPACE
  /* Ignoring function-like macro: NN_CMSG_SPACE(len) */
#endif
#ifdef NN_DOMAIN
  /* NN_DOMAIN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_DOMAIN", mrb_fixnum_value(NN_DOMAIN));
#endif
#ifdef NN_DONTWAIT
  /* NN_DONTWAIT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_DONTWAIT", mrb_fixnum_value(NN_DONTWAIT));
#endif
#ifdef NN_EISCONN_DEFINED
  /* Ignoring macro with no expansion: NN_EISCONN_DEFINED */
#endif
#ifdef NN_EXPORT
  /* NN_EXPORT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_EXPORT", mrb_fixnum_value(NN_EXPORT));
#endif
#ifdef NN_H_INCLUDED
  /* Ignoring macro with no expansion: NN_H_INCLUDED */
#endif
#ifdef NN_HAUSNUMERO
  /* NN_HAUSNUMERO assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_HAUSNUMERO", mrb_fixnum_value(NN_HAUSNUMERO));
#endif
#ifdef NN_INPROC
  /* NN_INPROC assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_INPROC", mrb_fixnum_value(NN_INPROC));
#endif
#ifdef NN_IPC
  /* NN_IPC assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_IPC", mrb_fixnum_value(NN_IPC));
#endif
#ifdef NN_IPV4ONLY
  /* NN_IPV4ONLY assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_IPV4ONLY", mrb_fixnum_value(NN_IPV4ONLY));
#endif
#ifdef NN_LINGER
  /* NN_LINGER assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_LINGER", mrb_fixnum_value(NN_LINGER));
#endif
#ifdef NN_MSG
  /* NN_MSG assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_MSG", mrb_fixnum_value(NN_MSG));
#endif
#ifdef NN_NS_DOMAIN
  /* NN_NS_DOMAIN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_DOMAIN", mrb_fixnum_value(NN_NS_DOMAIN));
#endif
#ifdef NN_NS_ERROR
  /* NN_NS_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_ERROR", mrb_fixnum_value(NN_NS_ERROR));
#endif
#ifdef NN_NS_FLAG
  /* NN_NS_FLAG assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_FLAG", mrb_fixnum_value(NN_NS_FLAG));
#endif
#ifdef NN_NS_LIMIT
  /* NN_NS_LIMIT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_LIMIT", mrb_fixnum_value(NN_NS_LIMIT));
#endif
#ifdef NN_NS_NAMESPACE
  /* NN_NS_NAMESPACE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_NAMESPACE", mrb_fixnum_value(NN_NS_NAMESPACE));
#endif
#ifdef NN_NS_OPTION_LEVEL
  /* NN_NS_OPTION_LEVEL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_OPTION_LEVEL", mrb_fixnum_value(NN_NS_OPTION_LEVEL));
#endif
#ifdef NN_NS_OPTION_TYPE
  /* NN_NS_OPTION_TYPE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_OPTION_TYPE", mrb_fixnum_value(NN_NS_OPTION_TYPE));
#endif
#ifdef NN_NS_OPTION_UNIT
  /* NN_NS_OPTION_UNIT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_OPTION_UNIT", mrb_fixnum_value(NN_NS_OPTION_UNIT));
#endif
#ifdef NN_NS_PROTOCOL
  /* NN_NS_PROTOCOL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_PROTOCOL", mrb_fixnum_value(NN_NS_PROTOCOL));
#endif
#ifdef NN_NS_SOCKET_OPTION
  /* NN_NS_SOCKET_OPTION assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_SOCKET_OPTION", mrb_fixnum_value(NN_NS_SOCKET_OPTION));
#endif
#ifdef NN_NS_TRANSPORT
  /* NN_NS_TRANSPORT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_TRANSPORT", mrb_fixnum_value(NN_NS_TRANSPORT));
#endif
#ifdef NN_NS_TRANSPORT_OPTION
  /* NN_NS_TRANSPORT_OPTION assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_TRANSPORT_OPTION", mrb_fixnum_value(NN_NS_TRANSPORT_OPTION));
#endif
#ifdef NN_NS_VERSION
  /* NN_NS_VERSION assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_NS_VERSION", mrb_fixnum_value(NN_NS_VERSION));
#endif
#ifdef NN_PAIR
  /* NN_PAIR assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PAIR", mrb_fixnum_value(NN_PAIR));
#endif
#ifdef NN_PIPE_IN
  /* NN_PIPE_IN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PIPE_IN", mrb_fixnum_value(NN_PIPE_IN));
#endif
#ifdef NN_PIPE_OUT
  /* NN_PIPE_OUT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PIPE_OUT", mrb_fixnum_value(NN_PIPE_OUT));
#endif
#ifdef NN_PIPE_PARSED
  /* NN_PIPE_PARSED assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PIPE_PARSED", mrb_fixnum_value(NN_PIPE_PARSED));
#endif
#ifdef NN_PIPE_RELEASE
  /* NN_PIPE_RELEASE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PIPE_RELEASE", mrb_fixnum_value(NN_PIPE_RELEASE));
#endif
#ifdef NN_PIPEBASE_PARSED
  /* NN_PIPEBASE_PARSED assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PIPEBASE_PARSED", mrb_fixnum_value(NN_PIPEBASE_PARSED));
#endif
#ifdef NN_PIPEBASE_RELEASE
  /* NN_PIPEBASE_RELEASE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PIPEBASE_RELEASE", mrb_fixnum_value(NN_PIPEBASE_RELEASE));
#endif
#ifdef NN_POLLIN
  /* NN_POLLIN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_POLLIN", mrb_fixnum_value(NN_POLLIN));
#endif
#ifdef NN_POLLOUT
  /* NN_POLLOUT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_POLLOUT", mrb_fixnum_value(NN_POLLOUT));
#endif
#ifdef NN_PROTO_BUS
  /* NN_PROTO_BUS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTO_BUS", mrb_fixnum_value(NN_PROTO_BUS));
#endif
#ifdef NN_PROTO_PAIR
  /* NN_PROTO_PAIR assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTO_PAIR", mrb_fixnum_value(NN_PROTO_PAIR));
#endif
#ifdef NN_PROTO_PIPELINE
  /* NN_PROTO_PIPELINE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTO_PIPELINE", mrb_fixnum_value(NN_PROTO_PIPELINE));
#endif
#ifdef NN_PROTO_PUBSUB
  /* NN_PROTO_PUBSUB assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTO_PUBSUB", mrb_fixnum_value(NN_PROTO_PUBSUB));
#endif
#ifdef NN_PROTO_REQREP
  /* NN_PROTO_REQREP assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTO_REQREP", mrb_fixnum_value(NN_PROTO_REQREP));
#endif
#ifdef NN_PROTO_SURVEY
  /* NN_PROTO_SURVEY assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTO_SURVEY", mrb_fixnum_value(NN_PROTO_SURVEY));
#endif
#ifdef NN_PROTOCOL
  /* NN_PROTOCOL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PROTOCOL", mrb_fixnum_value(NN_PROTOCOL));
#endif
#ifdef NN_PROTOCOL_INCLUDED
  /* Ignoring macro with no expansion: NN_PROTOCOL_INCLUDED */
#endif
#ifdef NN_PUB
  /* NN_PUB assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PUB", mrb_fixnum_value(NN_PUB));
#endif
#ifdef NN_PULL
  /* NN_PULL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PULL", mrb_fixnum_value(NN_PULL));
#endif
#ifdef NN_PUSH
  /* NN_PUSH assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_PUSH", mrb_fixnum_value(NN_PUSH));
#endif
#ifdef NN_RCVBUF
  /* NN_RCVBUF assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RCVBUF", mrb_fixnum_value(NN_RCVBUF));
#endif
#ifdef NN_RCVFD
  /* NN_RCVFD assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RCVFD", mrb_fixnum_value(NN_RCVFD));
#endif
#ifdef NN_RCVPRIO
  /* NN_RCVPRIO assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RCVPRIO", mrb_fixnum_value(NN_RCVPRIO));
#endif
#ifdef NN_RCVTIMEO
  /* NN_RCVTIMEO assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RCVTIMEO", mrb_fixnum_value(NN_RCVTIMEO));
#endif
#ifdef NN_RECONNECT_IVL
  /* NN_RECONNECT_IVL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RECONNECT_IVL", mrb_fixnum_value(NN_RECONNECT_IVL));
#endif
#ifdef NN_RECONNECT_IVL_MAX
  /* NN_RECONNECT_IVL_MAX assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RECONNECT_IVL_MAX", mrb_fixnum_value(NN_RECONNECT_IVL_MAX));
#endif
#ifdef NN_REP
  /* NN_REP assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_REP", mrb_fixnum_value(NN_REP));
#endif
#ifdef NN_REQ
  /* NN_REQ assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_REQ", mrb_fixnum_value(NN_REQ));
#endif
#ifdef NN_REQ_RESEND_IVL
  /* NN_REQ_RESEND_IVL assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_REQ_RESEND_IVL", mrb_fixnum_value(NN_REQ_RESEND_IVL));
#endif
#ifdef NN_RESPONDENT
  /* NN_RESPONDENT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_RESPONDENT", mrb_fixnum_value(NN_RESPONDENT));
#endif
#ifdef NN_SNDBUF
  /* NN_SNDBUF assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SNDBUF", mrb_fixnum_value(NN_SNDBUF));
#endif
#ifdef NN_SNDFD
  /* NN_SNDFD assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SNDFD", mrb_fixnum_value(NN_SNDFD));
#endif
#ifdef NN_SNDPRIO
  /* NN_SNDPRIO assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SNDPRIO", mrb_fixnum_value(NN_SNDPRIO));
#endif
#ifdef NN_SNDTIMEO
  /* NN_SNDTIMEO assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SNDTIMEO", mrb_fixnum_value(NN_SNDTIMEO));
#endif
#ifdef NN_SOCKADDR_MAX
  /* NN_SOCKADDR_MAX assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOCKADDR_MAX", mrb_fixnum_value(NN_SOCKADDR_MAX));
#endif
#ifdef NN_SOCKBASE_EVENT_IN
  /* NN_SOCKBASE_EVENT_IN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOCKBASE_EVENT_IN", mrb_fixnum_value(NN_SOCKBASE_EVENT_IN));
#endif
#ifdef NN_SOCKBASE_EVENT_OUT
  /* NN_SOCKBASE_EVENT_OUT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOCKBASE_EVENT_OUT", mrb_fixnum_value(NN_SOCKBASE_EVENT_OUT));
#endif
#ifdef NN_SOCKET_NAME
  /* NN_SOCKET_NAME assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOCKET_NAME", mrb_fixnum_value(NN_SOCKET_NAME));
#endif
#ifdef NN_SOCKTYPE_FLAG_NORECV
  /* NN_SOCKTYPE_FLAG_NORECV assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOCKTYPE_FLAG_NORECV", mrb_fixnum_value(NN_SOCKTYPE_FLAG_NORECV));
#endif
#ifdef NN_SOCKTYPE_FLAG_NOSEND
  /* NN_SOCKTYPE_FLAG_NOSEND assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOCKTYPE_FLAG_NOSEND", mrb_fixnum_value(NN_SOCKTYPE_FLAG_NOSEND));
#endif
#ifdef NN_SOL_SOCKET
  /* NN_SOL_SOCKET assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SOL_SOCKET", mrb_fixnum_value(NN_SOL_SOCKET));
#endif
#ifdef NN_STAT_ACCEPT_ERRORS
  /* NN_STAT_ACCEPT_ERRORS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_ACCEPT_ERRORS", mrb_fixnum_value(NN_STAT_ACCEPT_ERRORS));
#endif
#ifdef NN_STAT_ACCEPTED_CONNECTIONS
  /* NN_STAT_ACCEPTED_CONNECTIONS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_ACCEPTED_CONNECTIONS", mrb_fixnum_value(NN_STAT_ACCEPTED_CONNECTIONS));
#endif
#ifdef NN_STAT_BIND_ERRORS
  /* NN_STAT_BIND_ERRORS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_BIND_ERRORS", mrb_fixnum_value(NN_STAT_BIND_ERRORS));
#endif
#ifdef NN_STAT_BROKEN_CONNECTIONS
  /* NN_STAT_BROKEN_CONNECTIONS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_BROKEN_CONNECTIONS", mrb_fixnum_value(NN_STAT_BROKEN_CONNECTIONS));
#endif
#ifdef NN_STAT_CONNECT_ERRORS
  /* NN_STAT_CONNECT_ERRORS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_CONNECT_ERRORS", mrb_fixnum_value(NN_STAT_CONNECT_ERRORS));
#endif
#ifdef NN_STAT_CURRENT_CONNECTIONS
  /* NN_STAT_CURRENT_CONNECTIONS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_CURRENT_CONNECTIONS", mrb_fixnum_value(NN_STAT_CURRENT_CONNECTIONS));
#endif
#ifdef NN_STAT_CURRENT_EP_ERRORS
  /* NN_STAT_CURRENT_EP_ERRORS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_CURRENT_EP_ERRORS", mrb_fixnum_value(NN_STAT_CURRENT_EP_ERRORS));
#endif
#ifdef NN_STAT_CURRENT_SND_PRIORITY
  /* NN_STAT_CURRENT_SND_PRIORITY assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_CURRENT_SND_PRIORITY", mrb_fixnum_value(NN_STAT_CURRENT_SND_PRIORITY));
#endif
#ifdef NN_STAT_DROPPED_CONNECTIONS
  /* NN_STAT_DROPPED_CONNECTIONS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_DROPPED_CONNECTIONS", mrb_fixnum_value(NN_STAT_DROPPED_CONNECTIONS));
#endif
#ifdef NN_STAT_ESTABLISHED_CONNECTIONS
  /* NN_STAT_ESTABLISHED_CONNECTIONS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_ESTABLISHED_CONNECTIONS", mrb_fixnum_value(NN_STAT_ESTABLISHED_CONNECTIONS));
#endif
#ifdef NN_STAT_INPROGRESS_CONNECTIONS
  /* NN_STAT_INPROGRESS_CONNECTIONS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_STAT_INPROGRESS_CONNECTIONS", mrb_fixnum_value(NN_STAT_INPROGRESS_CONNECTIONS));
#endif
#ifdef NN_SUB
  /* NN_SUB assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SUB", mrb_fixnum_value(NN_SUB));
#endif
#ifdef NN_SUB_SUBSCRIBE
  /* NN_SUB_SUBSCRIBE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SUB_SUBSCRIBE", mrb_fixnum_value(NN_SUB_SUBSCRIBE));
#endif
#ifdef NN_SUB_UNSUBSCRIBE
  /* NN_SUB_UNSUBSCRIBE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SUB_UNSUBSCRIBE", mrb_fixnum_value(NN_SUB_UNSUBSCRIBE));
#endif
#ifdef NN_SURVEYOR
  /* NN_SURVEYOR assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SURVEYOR", mrb_fixnum_value(NN_SURVEYOR));
#endif
#ifdef NN_SURVEYOR_DEADLINE
  /* NN_SURVEYOR_DEADLINE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_SURVEYOR_DEADLINE", mrb_fixnum_value(NN_SURVEYOR_DEADLINE));
#endif
#ifdef NN_TCP
  /* NN_TCP assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_TCP", mrb_fixnum_value(NN_TCP));
#endif
#ifdef NN_TCP_NODELAY
  /* NN_TCP_NODELAY assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_TCP_NODELAY", mrb_fixnum_value(NN_TCP_NODELAY));
#endif
#ifdef NN_TRANSPORT_INCLUDED
  /* Ignoring macro with no expansion: NN_TRANSPORT_INCLUDED */
#endif
#ifdef NN_TYPE_INT
  /* NN_TYPE_INT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_TYPE_INT", mrb_fixnum_value(NN_TYPE_INT));
#endif
#ifdef NN_TYPE_NONE
  /* NN_TYPE_NONE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_TYPE_NONE", mrb_fixnum_value(NN_TYPE_NONE));
#endif
#ifdef NN_TYPE_STR
  /* NN_TYPE_STR assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_TYPE_STR", mrb_fixnum_value(NN_TYPE_STR));
#endif
#ifdef NN_UNIT_BOOLEAN
  /* NN_UNIT_BOOLEAN assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_UNIT_BOOLEAN", mrb_fixnum_value(NN_UNIT_BOOLEAN));
#endif
#ifdef NN_UNIT_BYTES
  /* NN_UNIT_BYTES assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_UNIT_BYTES", mrb_fixnum_value(NN_UNIT_BYTES));
#endif
#ifdef NN_UNIT_MILLISECONDS
  /* NN_UNIT_MILLISECONDS assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_UNIT_MILLISECONDS", mrb_fixnum_value(NN_UNIT_MILLISECONDS));
#endif
#ifdef NN_UNIT_NONE
  /* NN_UNIT_NONE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_UNIT_NONE", mrb_fixnum_value(NN_UNIT_NONE));
#endif
#ifdef NN_UNIT_PRIORITY
  /* NN_UNIT_PRIORITY assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_UNIT_PRIORITY", mrb_fixnum_value(NN_UNIT_PRIORITY));
#endif
#ifdef NN_VERSION_AGE
  /* NN_VERSION_AGE assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_VERSION_AGE", mrb_fixnum_value(NN_VERSION_AGE));
#endif
#ifdef NN_VERSION_CURRENT
  /* NN_VERSION_CURRENT assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_VERSION_CURRENT", mrb_fixnum_value(NN_VERSION_CURRENT));
#endif
#ifdef NN_VERSION_REVISION
  /* NN_VERSION_REVISION assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "NN_VERSION_REVISION", mrb_fixnum_value(NN_VERSION_REVISION));
#endif
#ifdef PAIR_H_INCLUDED
  /* Ignoring macro with no expansion: PAIR_H_INCLUDED */
#endif
#ifdef PIPELINE_H_INCLUDED
  /* Ignoring macro with no expansion: PIPELINE_H_INCLUDED */
#endif
#ifdef PROTO_SP
  /* PROTO_SP assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "PROTO_SP", mrb_fixnum_value(PROTO_SP));
#endif
#ifdef PUBSUB_H_INCLUDED
  /* Ignoring macro with no expansion: PUBSUB_H_INCLUDED */
#endif
#ifdef REQREP_H_INCLUDED
  /* Ignoring macro with no expansion: REQREP_H_INCLUDED */
#endif
#ifdef SP_HDR
  /* SP_HDR assumed to be an integer value */
  mrb_define_const(mrb, NN_module(mrb), "SP_HDR", mrb_fixnum_value(SP_HDR));
#endif
#ifdef SURVEY_H_INCLUDED
  /* Ignoring macro with no expansion: SURVEY_H_INCLUDED */
#endif
#ifdef TCP_H_INCLUDED
  /* Ignoring macro with no expansion: TCP_H_INCLUDED */
#endif
}
