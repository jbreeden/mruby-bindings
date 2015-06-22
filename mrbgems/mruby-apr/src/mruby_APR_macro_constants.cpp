#include "mruby_APR.h"

void
mruby_APR_define_macro_constants(mrb_state* mrb) {
  
   /* Need to add a few constants that are in system headers, not APR (and so not generated) */
#ifdef SOCK_STREAM
   mrb_define_const(mrb, APR_module(mrb), "SOCK_STREAM", mrb_fixnum_value(SOCK_STREAM));
#endif
#ifdef SOCK_DGRAM
   mrb_define_const(mrb, APR_module(mrb), "SOCK_DGRAM", mrb_fixnum_value(SOCK_DGRAM));
#endif
#ifdef SOCK_RAW
   mrb_define_const(mrb, APR_module(mrb), "SOCK_RAW", mrb_fixnum_value(SOCK_RAW));
#endif
#ifdef SOCK_RDM
   mrb_define_const(mrb, APR_module(mrb), "SOCK_RDM", mrb_fixnum_value(SOCK_RDM));
#endif
#ifdef SOCK_SEQPACKET
   mrb_define_const(mrb, APR_module(mrb), "SOCK_SEQPACKET", mrb_fixnum_value(SOCK_SEQPACKET));
#endif

#ifdef _APR_FNMATCH_H_
  /* Ignoring macro with no expansion: _APR_FNMATCH_H_ */
#endif
#ifdef _WIN32_WINNT
  /* _WIN32_WINNT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "_WIN32_WINNT", mrb_fixnum_value(_WIN32_WINNT));
#endif
#ifdef APR_ALIGN
  /* Ignoring function-like macro: APR_ALIGN(size, boundary) */
#endif
#ifdef APR_ALIGN_DEFAULT
  /* Ignoring function-like macro: APR_ALIGN_DEFAULT(size) */
#endif
#ifdef APR_ALLOCATOR_H
  /* Ignoring macro with no expansion: APR_ALLOCATOR_H */
#endif
#ifdef APR_ALLOCATOR_MAX_FREE_UNLIMITED
  /* APR_ALLOCATOR_MAX_FREE_UNLIMITED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ALLOCATOR_MAX_FREE_UNLIMITED", mrb_fixnum_value(APR_ALLOCATOR_MAX_FREE_UNLIMITED));
#endif
#ifdef APR_ANONYMOUS
  /* APR_ANONYMOUS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ANONYMOUS", mrb_fixnum_value(APR_ANONYMOUS));
#endif
#ifdef APR_ANYADDR
  /* APR_ANYADDR appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_ANYADDR", mrb_str_new_cstr(mrb, APR_ANYADDR));
#endif
#ifdef APR_APPEND
  /* APR_APPEND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_APPEND", mrb_fixnum_value(APR_APPEND));
#endif
#ifdef APR_ARRAY_IDX
  /* Ignoring function-like macro: APR_ARRAY_IDX(ary, i, type) */
#endif
#ifdef APR_ARRAY_PUSH
  /* Ignoring function-like macro: APR_ARRAY_PUSH(ary, type) */
#endif
#ifdef APR_ASCII_BLANK
  /* APR_ASCII_BLANK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ASCII_BLANK", mrb_fixnum_value(APR_ASCII_BLANK));
#endif
#ifdef APR_ASCII_CR
  /* APR_ASCII_CR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ASCII_CR", mrb_fixnum_value(APR_ASCII_CR));
#endif
#ifdef APR_ASCII_LF
  /* APR_ASCII_LF assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ASCII_LF", mrb_fixnum_value(APR_ASCII_LF));
#endif
#ifdef APR_ASCII_TAB
  /* APR_ASCII_TAB assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ASCII_TAB", mrb_fixnum_value(APR_ASCII_TAB));
#endif
#ifdef APR_ATOMIC_H
  /* Ignoring macro with no expansion: APR_ATOMIC_H */
#endif
#ifdef APR_BADARG
  /* APR_BADARG assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_BADARG", mrb_fixnum_value(APR_BADARG));
#endif
#ifdef APR_BADCH
  /* APR_BADCH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_BADCH", mrb_fixnum_value(APR_BADCH));
#endif
#ifdef APR_BEGIN_DECLS
  /* APR_BEGIN_DECLS appears to be a string */
  //mrb_define_const(mrb, APR_module(mrb), "APR_BEGIN_DECLS", mrb_str_new_cstr(mrb, APR_BEGIN_DECLS));
#endif
#ifdef APR_BINARY
  /* APR_BINARY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_BINARY", mrb_fixnum_value(APR_BINARY));
#endif
#ifdef APR_BUFFERED
  /* APR_BUFFERED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_BUFFERED", mrb_fixnum_value(APR_BUFFERED));
#endif
#ifdef APR_CHARSET_EBCDIC
  /* APR_CHARSET_EBCDIC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CHARSET_EBCDIC", mrb_fixnum_value(APR_CHARSET_EBCDIC));
#endif
#ifdef APR_CHILD_BLOCK
  /* APR_CHILD_BLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CHILD_BLOCK", mrb_fixnum_value(APR_CHILD_BLOCK));
#endif
#ifdef APR_CHILD_DONE
  /* APR_CHILD_DONE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CHILD_DONE", mrb_fixnum_value(APR_CHILD_DONE));
#endif
#ifdef APR_CHILD_NOTDONE
  /* APR_CHILD_NOTDONE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CHILD_NOTDONE", mrb_fixnum_value(APR_CHILD_NOTDONE));
#endif
#ifdef APR_COPYRIGHT
  /* APR_COPYRIGHT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_COPYRIGHT", mrb_str_new_cstr(mrb, APR_COPYRIGHT));
#endif
#ifdef APR_CREATE
  /* APR_CREATE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CREATE", mrb_fixnum_value(APR_CREATE));
#endif
#ifdef APR_CTIME_LEN
  /* APR_CTIME_LEN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CTIME_LEN", mrb_fixnum_value(APR_CTIME_LEN));
#endif
#ifdef APR_CUR
  /* APR_CUR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_CUR", mrb_fixnum_value(APR_CUR));
#endif
#ifdef APR_DECLARE
  /* Ignoring function-like macro: APR_DECLARE(type) */
#endif
#ifdef APR_DECLARE_DATA
  /* APR_DECLARE_DATA assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "APR_DECLARE_DATA", mrb_fixnum_value(APR_DECLARE_DATA));
#endif
#ifdef APR_DECLARE_INHERIT_SET
  /* Ignoring function-like macro: APR_DECLARE_INHERIT_SET(type) */
#endif
#ifdef APR_DECLARE_INHERIT_UNSET
  /* Ignoring function-like macro: APR_DECLARE_INHERIT_UNSET(type) */
#endif
#ifdef APR_DECLARE_NONSTD
  /* Ignoring function-like macro: APR_DECLARE_NONSTD(type) */
#endif
#ifdef APR_DELONCLOSE
  /* APR_DELONCLOSE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_DELONCLOSE", mrb_fixnum_value(APR_DELONCLOSE));
#endif
#ifdef APR_DETACH
  /* APR_DETACH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_DETACH", mrb_fixnum_value(APR_DETACH));
#endif
#ifdef APR_DSO_DOT_H
  /* Ignoring macro with no expansion: APR_DSO_DOT_H */
#endif
#ifdef APR_DSOPATH
  /* APR_DSOPATH appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_DSOPATH", mrb_str_new_cstr(mrb, APR_DSOPATH));
#endif
#ifdef APR_EABOVEROOT
  /* APR_EABOVEROOT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EABOVEROOT", mrb_fixnum_value(APR_EABOVEROOT));
#endif
#ifdef APR_EABSOLUTE
  /* APR_EABSOLUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EABSOLUTE", mrb_fixnum_value(APR_EABSOLUTE));
#endif
#ifdef APR_EACCES
  /* APR_EACCES assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EACCES", mrb_fixnum_value(APR_EACCES));
#endif
#ifdef APR_EAFNOSUPPORT
  /* APR_EAFNOSUPPORT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EAFNOSUPPORT", mrb_fixnum_value(APR_EAFNOSUPPORT));
#endif
#ifdef APR_EAGAIN
  /* APR_EAGAIN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EAGAIN", mrb_fixnum_value(APR_EAGAIN));
#endif
#ifdef APR_EBADDATE
  /* APR_EBADDATE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EBADDATE", mrb_fixnum_value(APR_EBADDATE));
#endif
#ifdef APR_EBADF
  /* APR_EBADF assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EBADF", mrb_fixnum_value(APR_EBADF));
#endif
#ifdef APR_EBADIP
  /* APR_EBADIP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EBADIP", mrb_fixnum_value(APR_EBADIP));
#endif
#ifdef APR_EBADMASK
  /* APR_EBADMASK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EBADMASK", mrb_fixnum_value(APR_EBADMASK));
#endif
#ifdef APR_EBADPATH
  /* APR_EBADPATH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EBADPATH", mrb_fixnum_value(APR_EBADPATH));
#endif
#ifdef APR_EBUSY
  /* APR_EBUSY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EBUSY", mrb_fixnum_value(APR_EBUSY));
#endif
#ifdef APR_ECONNABORTED
  /* APR_ECONNABORTED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ECONNABORTED", mrb_fixnum_value(APR_ECONNABORTED));
#endif
#ifdef APR_ECONNREFUSED
  /* APR_ECONNREFUSED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ECONNREFUSED", mrb_fixnum_value(APR_ECONNREFUSED));
#endif
#ifdef APR_ECONNRESET
  /* APR_ECONNRESET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ECONNRESET", mrb_fixnum_value(APR_ECONNRESET));
#endif
#ifdef APR_EDSOOPEN
  /* APR_EDSOOPEN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EDSOOPEN", mrb_fixnum_value(APR_EDSOOPEN));
#endif
#ifdef APR_EEXIST
  /* APR_EEXIST assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EEXIST", mrb_fixnum_value(APR_EEXIST));
#endif
#ifdef APR_EFTYPE
  /* APR_EFTYPE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EFTYPE", mrb_fixnum_value(APR_EFTYPE));
#endif
#ifdef APR_EGENERAL
  /* APR_EGENERAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EGENERAL", mrb_fixnum_value(APR_EGENERAL));
#endif
#ifdef APR_EHOSTUNREACH
  /* APR_EHOSTUNREACH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EHOSTUNREACH", mrb_fixnum_value(APR_EHOSTUNREACH));
#endif
#ifdef APR_EINCOMPLETE
  /* APR_EINCOMPLETE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EINCOMPLETE", mrb_fixnum_value(APR_EINCOMPLETE));
#endif
#ifdef APR_EINIT
  /* APR_EINIT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EINIT", mrb_fixnum_value(APR_EINIT));
#endif
#ifdef APR_EINPROGRESS
  /* APR_EINPROGRESS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EINPROGRESS", mrb_fixnum_value(APR_EINPROGRESS));
#endif
#ifdef APR_EINTR
  /* APR_EINTR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EINTR", mrb_fixnum_value(APR_EINTR));
#endif
#ifdef APR_EINVAL
  /* APR_EINVAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EINVAL", mrb_fixnum_value(APR_EINVAL));
#endif
#ifdef APR_EINVALSOCK
  /* APR_EINVALSOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EINVALSOCK", mrb_fixnum_value(APR_EINVALSOCK));
#endif
#ifdef APR_EMFILE
  /* APR_EMFILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EMFILE", mrb_fixnum_value(APR_EMFILE));
#endif
#ifdef APR_EMISMATCH
  /* APR_EMISMATCH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EMISMATCH", mrb_fixnum_value(APR_EMISMATCH));
#endif
#ifdef APR_ENAMETOOLONG
  /* APR_ENAMETOOLONG assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENAMETOOLONG", mrb_fixnum_value(APR_ENAMETOOLONG));
#endif
#ifdef APR_END
  /* APR_END assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_END", mrb_fixnum_value(APR_END));
#endif
#ifdef APR_END_DECLS
  /* APR_END_DECLS assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "APR_END_DECLS", mrb_fixnum_value(APR_END_DECLS));
#endif
#ifdef APR_ENETUNREACH
  /* APR_ENETUNREACH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENETUNREACH", mrb_fixnum_value(APR_ENETUNREACH));
#endif
#ifdef APR_ENFILE
  /* APR_ENFILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENFILE", mrb_fixnum_value(APR_ENFILE));
#endif
#ifdef APR_ENODIR
  /* APR_ENODIR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENODIR", mrb_fixnum_value(APR_ENODIR));
#endif
#ifdef APR_ENOENT
  /* APR_ENOENT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOENT", mrb_fixnum_value(APR_ENOENT));
#endif
#ifdef APR_ENOLOCK
  /* APR_ENOLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOLOCK", mrb_fixnum_value(APR_ENOLOCK));
#endif
#ifdef APR_ENOMEM
  /* APR_ENOMEM assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOMEM", mrb_fixnum_value(APR_ENOMEM));
#endif
#ifdef APR_ENOPOLL
  /* APR_ENOPOLL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOPOLL", mrb_fixnum_value(APR_ENOPOLL));
#endif
#ifdef APR_ENOPOOL
  /* APR_ENOPOOL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOPOOL", mrb_fixnum_value(APR_ENOPOOL));
#endif
#ifdef APR_ENOPROC
  /* APR_ENOPROC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOPROC", mrb_fixnum_value(APR_ENOPROC));
#endif
#ifdef APR_ENOSHMAVAIL
  /* APR_ENOSHMAVAIL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOSHMAVAIL", mrb_fixnum_value(APR_ENOSHMAVAIL));
#endif
#ifdef APR_ENOSOCKET
  /* APR_ENOSOCKET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOSOCKET", mrb_fixnum_value(APR_ENOSOCKET));
#endif
#ifdef APR_ENOSPC
  /* APR_ENOSPC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOSPC", mrb_fixnum_value(APR_ENOSPC));
#endif
#ifdef APR_ENOSTAT
  /* APR_ENOSTAT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOSTAT", mrb_fixnum_value(APR_ENOSTAT));
#endif
#ifdef APR_ENOTDIR
  /* APR_ENOTDIR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTDIR", mrb_fixnum_value(APR_ENOTDIR));
#endif
#ifdef APR_ENOTEMPTY
  /* APR_ENOTEMPTY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTEMPTY", mrb_fixnum_value(APR_ENOTEMPTY));
#endif
#ifdef APR_ENOTENOUGHENTROPY
  /* APR_ENOTENOUGHENTROPY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTENOUGHENTROPY", mrb_fixnum_value(APR_ENOTENOUGHENTROPY));
#endif
#ifdef APR_ENOTHDKEY
  /* APR_ENOTHDKEY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTHDKEY", mrb_fixnum_value(APR_ENOTHDKEY));
#endif
#ifdef APR_ENOTHREAD
  /* APR_ENOTHREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTHREAD", mrb_fixnum_value(APR_ENOTHREAD));
#endif
#ifdef APR_ENOTIME
  /* APR_ENOTIME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTIME", mrb_fixnum_value(APR_ENOTIME));
#endif
#ifdef APR_ENOTIMPL
  /* APR_ENOTIMPL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTIMPL", mrb_fixnum_value(APR_ENOTIMPL));
#endif
#ifdef APR_ENOTSOCK
  /* APR_ENOTSOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ENOTSOCK", mrb_fixnum_value(APR_ENOTSOCK));
#endif
#ifdef APR_ENV_H
  /* Ignoring macro with no expansion: APR_ENV_H */
#endif
#ifdef APR_EOF
  /* APR_EOF assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EOF", mrb_fixnum_value(APR_EOF));
#endif
#ifdef APR_EOL_STR
  /* APR_EOL_STR appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_EOL_STR", mrb_str_new_cstr(mrb, APR_EOL_STR));
#endif
#ifdef APR_EPATHWILD
  /* APR_EPATHWILD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EPATHWILD", mrb_fixnum_value(APR_EPATHWILD));
#endif
#ifdef APR_EPIPE
  /* APR_EPIPE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EPIPE", mrb_fixnum_value(APR_EPIPE));
#endif
#ifdef APR_EPROC_UNKNOWN
  /* APR_EPROC_UNKNOWN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EPROC_UNKNOWN", mrb_fixnum_value(APR_EPROC_UNKNOWN));
#endif
#ifdef APR_ERELATIVE
  /* APR_ERELATIVE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ERELATIVE", mrb_fixnum_value(APR_ERELATIVE));
#endif
#ifdef APR_ERRNO_H
  /* Ignoring macro with no expansion: APR_ERRNO_H */
#endif
#ifdef APR_ESCAPE_H
  /* Ignoring macro with no expansion: APR_ESCAPE_H */
#endif
#ifdef APR_ESCAPE_STRING
  /* APR_ESCAPE_STRING assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ESCAPE_STRING", mrb_fixnum_value(APR_ESCAPE_STRING));
#endif
#ifdef APR_ESPIPE
  /* APR_ESPIPE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ESPIPE", mrb_fixnum_value(APR_ESPIPE));
#endif
#ifdef APR_ESYMNOTFOUND
  /* APR_ESYMNOTFOUND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ESYMNOTFOUND", mrb_fixnum_value(APR_ESYMNOTFOUND));
#endif
#ifdef APR_ETIMEDOUT
  /* APR_ETIMEDOUT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_ETIMEDOUT", mrb_fixnum_value(APR_ETIMEDOUT));
#endif
#ifdef APR_EXCL
  /* APR_EXCL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EXCL", mrb_fixnum_value(APR_EXCL));
#endif
#ifdef APR_EXDEV
  /* APR_EXDEV assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_EXDEV", mrb_fixnum_value(APR_EXDEV));
#endif
#ifdef APR_FILE_ATTR_EXECUTABLE
  /* APR_FILE_ATTR_EXECUTABLE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILE_ATTR_EXECUTABLE", mrb_fixnum_value(APR_FILE_ATTR_EXECUTABLE));
#endif
#ifdef APR_FILE_ATTR_HIDDEN
  /* APR_FILE_ATTR_HIDDEN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILE_ATTR_HIDDEN", mrb_fixnum_value(APR_FILE_ATTR_HIDDEN));
#endif
#ifdef APR_FILE_ATTR_READONLY
  /* APR_FILE_ATTR_READONLY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILE_ATTR_READONLY", mrb_fixnum_value(APR_FILE_ATTR_READONLY));
#endif
#ifdef APR_FILE_INFO_H
  /* Ignoring macro with no expansion: APR_FILE_INFO_H */
#endif
#ifdef APR_FILE_IO_H
  /* Ignoring macro with no expansion: APR_FILE_IO_H */
#endif
#ifdef APR_FILE_NOCLEANUP
  /* APR_FILE_NOCLEANUP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILE_NOCLEANUP", mrb_fixnum_value(APR_FILE_NOCLEANUP));
#endif
#ifdef APR_FILE_SOURCE_PERMS
  /* APR_FILE_SOURCE_PERMS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILE_SOURCE_PERMS", mrb_fixnum_value(APR_FILE_SOURCE_PERMS));
#endif
#ifdef APR_FILEBASED
  /* APR_FILEBASED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEBASED", mrb_fixnum_value(APR_FILEBASED));
#endif
#ifdef APR_FILEPATH_ENCODING_LOCALE
  /* APR_FILEPATH_ENCODING_LOCALE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_ENCODING_LOCALE", mrb_fixnum_value(APR_FILEPATH_ENCODING_LOCALE));
#endif
#ifdef APR_FILEPATH_ENCODING_UNKNOWN
  /* APR_FILEPATH_ENCODING_UNKNOWN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_ENCODING_UNKNOWN", mrb_fixnum_value(APR_FILEPATH_ENCODING_UNKNOWN));
#endif
#ifdef APR_FILEPATH_ENCODING_UTF8
  /* APR_FILEPATH_ENCODING_UTF8 assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_ENCODING_UTF8", mrb_fixnum_value(APR_FILEPATH_ENCODING_UTF8));
#endif
#ifdef APR_FILEPATH_NATIVE
  /* APR_FILEPATH_NATIVE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_NATIVE", mrb_fixnum_value(APR_FILEPATH_NATIVE));
#endif
#ifdef APR_FILEPATH_NOTABOVEROOT
  /* APR_FILEPATH_NOTABOVEROOT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_NOTABOVEROOT", mrb_fixnum_value(APR_FILEPATH_NOTABOVEROOT));
#endif
#ifdef APR_FILEPATH_NOTABSOLUTE
  /* APR_FILEPATH_NOTABSOLUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_NOTABSOLUTE", mrb_fixnum_value(APR_FILEPATH_NOTABSOLUTE));
#endif
#ifdef APR_FILEPATH_NOTRELATIVE
  /* APR_FILEPATH_NOTRELATIVE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_NOTRELATIVE", mrb_fixnum_value(APR_FILEPATH_NOTRELATIVE));
#endif
#ifdef APR_FILEPATH_SECUREROOT
  /* APR_FILEPATH_SECUREROOT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_SECUREROOT", mrb_fixnum_value(APR_FILEPATH_SECUREROOT));
#endif
#ifdef APR_FILEPATH_SECUREROOTTEST
  /* APR_FILEPATH_SECUREROOTTEST assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_SECUREROOTTEST", mrb_fixnum_value(APR_FILEPATH_SECUREROOTTEST));
#endif
#ifdef APR_FILEPATH_TRUENAME
  /* APR_FILEPATH_TRUENAME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILEPATH_TRUENAME", mrb_fixnum_value(APR_FILEPATH_TRUENAME));
#endif
#ifdef APR_FILES_AS_SOCKETS
  /* APR_FILES_AS_SOCKETS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FILES_AS_SOCKETS", mrb_fixnum_value(APR_FILES_AS_SOCKETS));
#endif
#ifdef APR_FINFO_ATIME
  /* APR_FINFO_ATIME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_ATIME", mrb_fixnum_value(APR_FINFO_ATIME));
#endif
#ifdef APR_FINFO_CSIZE
  /* APR_FINFO_CSIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_CSIZE", mrb_fixnum_value(APR_FINFO_CSIZE));
#endif
#ifdef APR_FINFO_CTIME
  /* APR_FINFO_CTIME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_CTIME", mrb_fixnum_value(APR_FINFO_CTIME));
#endif
#ifdef APR_FINFO_DEV
  /* APR_FINFO_DEV assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_DEV", mrb_fixnum_value(APR_FINFO_DEV));
#endif
#ifdef APR_FINFO_DIRENT
  /* APR_FINFO_DIRENT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_DIRENT", mrb_fixnum_value(APR_FINFO_DIRENT));
#endif
#ifdef APR_FINFO_GPROT
  /* APR_FINFO_GPROT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_GPROT", mrb_fixnum_value(APR_FINFO_GPROT));
#endif
#ifdef APR_FINFO_GROUP
  /* APR_FINFO_GROUP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_GROUP", mrb_fixnum_value(APR_FINFO_GROUP));
#endif
#ifdef APR_FINFO_ICASE
  /* APR_FINFO_ICASE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_ICASE", mrb_fixnum_value(APR_FINFO_ICASE));
#endif
#ifdef APR_FINFO_IDENT
  /* APR_FINFO_IDENT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_IDENT", mrb_fixnum_value(APR_FINFO_IDENT));
#endif
#ifdef APR_FINFO_INODE
  /* APR_FINFO_INODE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_INODE", mrb_fixnum_value(APR_FINFO_INODE));
#endif
#ifdef APR_FINFO_LINK
  /* APR_FINFO_LINK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_LINK", mrb_fixnum_value(APR_FINFO_LINK));
#endif
#ifdef APR_FINFO_MIN
  /* APR_FINFO_MIN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_MIN", mrb_fixnum_value(APR_FINFO_MIN));
#endif
#ifdef APR_FINFO_MTIME
  /* APR_FINFO_MTIME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_MTIME", mrb_fixnum_value(APR_FINFO_MTIME));
#endif
#ifdef APR_FINFO_NAME
  /* APR_FINFO_NAME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_NAME", mrb_fixnum_value(APR_FINFO_NAME));
#endif
#ifdef APR_FINFO_NLINK
  /* APR_FINFO_NLINK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_NLINK", mrb_fixnum_value(APR_FINFO_NLINK));
#endif
#ifdef APR_FINFO_NORM
  /* APR_FINFO_NORM assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_NORM", mrb_fixnum_value(APR_FINFO_NORM));
#endif
#ifdef APR_FINFO_OWNER
  /* APR_FINFO_OWNER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_OWNER", mrb_fixnum_value(APR_FINFO_OWNER));
#endif
#ifdef APR_FINFO_PROT
  /* APR_FINFO_PROT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_PROT", mrb_fixnum_value(APR_FINFO_PROT));
#endif
#ifdef APR_FINFO_SIZE
  /* APR_FINFO_SIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_SIZE", mrb_fixnum_value(APR_FINFO_SIZE));
#endif
#ifdef APR_FINFO_TYPE
  /* APR_FINFO_TYPE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_TYPE", mrb_fixnum_value(APR_FINFO_TYPE));
#endif
#ifdef APR_FINFO_UPROT
  /* APR_FINFO_UPROT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_UPROT", mrb_fixnum_value(APR_FINFO_UPROT));
#endif
#ifdef APR_FINFO_USER
  /* APR_FINFO_USER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_USER", mrb_fixnum_value(APR_FINFO_USER));
#endif
#ifdef APR_FINFO_WPROT
  /* APR_FINFO_WPROT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FINFO_WPROT", mrb_fixnum_value(APR_FINFO_WPROT));
#endif
#ifdef APR_FLOCK_EXCLUSIVE
  /* APR_FLOCK_EXCLUSIVE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FLOCK_EXCLUSIVE", mrb_fixnum_value(APR_FLOCK_EXCLUSIVE));
#endif
#ifdef APR_FLOCK_NONBLOCK
  /* APR_FLOCK_NONBLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FLOCK_NONBLOCK", mrb_fixnum_value(APR_FLOCK_NONBLOCK));
#endif
#ifdef APR_FLOCK_SHARED
  /* APR_FLOCK_SHARED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FLOCK_SHARED", mrb_fixnum_value(APR_FLOCK_SHARED));
#endif
#ifdef APR_FLOCK_TYPEMASK
  /* APR_FLOCK_TYPEMASK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FLOCK_TYPEMASK", mrb_fixnum_value(APR_FLOCK_TYPEMASK));
#endif
#ifdef APR_FNM_CASE_BLIND
  /* APR_FNM_CASE_BLIND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FNM_CASE_BLIND", mrb_fixnum_value(APR_FNM_CASE_BLIND));
#endif
#ifdef APR_FNM_NOESCAPE
  /* APR_FNM_NOESCAPE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FNM_NOESCAPE", mrb_fixnum_value(APR_FNM_NOESCAPE));
#endif
#ifdef APR_FNM_NOMATCH
  /* APR_FNM_NOMATCH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FNM_NOMATCH", mrb_fixnum_value(APR_FNM_NOMATCH));
#endif
#ifdef APR_FNM_PATHNAME
  /* APR_FNM_PATHNAME assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FNM_PATHNAME", mrb_fixnum_value(APR_FNM_PATHNAME));
#endif
#ifdef APR_FNM_PERIOD
  /* APR_FNM_PERIOD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FNM_PERIOD", mrb_fixnum_value(APR_FNM_PERIOD));
#endif
#ifdef APR_FOPEN_APPEND
  /* APR_FOPEN_APPEND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_APPEND", mrb_fixnum_value(APR_FOPEN_APPEND));
#endif
#ifdef APR_FOPEN_BINARY
  /* APR_FOPEN_BINARY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_BINARY", mrb_fixnum_value(APR_FOPEN_BINARY));
#endif
#ifdef APR_FOPEN_BUFFERED
  /* APR_FOPEN_BUFFERED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_BUFFERED", mrb_fixnum_value(APR_FOPEN_BUFFERED));
#endif
#ifdef APR_FOPEN_CREATE
  /* APR_FOPEN_CREATE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_CREATE", mrb_fixnum_value(APR_FOPEN_CREATE));
#endif
#ifdef APR_FOPEN_DELONCLOSE
  /* APR_FOPEN_DELONCLOSE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_DELONCLOSE", mrb_fixnum_value(APR_FOPEN_DELONCLOSE));
#endif
#ifdef APR_FOPEN_EXCL
  /* APR_FOPEN_EXCL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_EXCL", mrb_fixnum_value(APR_FOPEN_EXCL));
#endif
#ifdef APR_FOPEN_LARGEFILE
  /* APR_FOPEN_LARGEFILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_LARGEFILE", mrb_fixnum_value(APR_FOPEN_LARGEFILE));
#endif
#ifdef APR_FOPEN_NOCLEANUP
  /* APR_FOPEN_NOCLEANUP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_NOCLEANUP", mrb_fixnum_value(APR_FOPEN_NOCLEANUP));
#endif
#ifdef APR_FOPEN_NONBLOCK
  /* APR_FOPEN_NONBLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_NONBLOCK", mrb_fixnum_value(APR_FOPEN_NONBLOCK));
#endif
#ifdef APR_FOPEN_READ
  /* APR_FOPEN_READ assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_READ", mrb_fixnum_value(APR_FOPEN_READ));
#endif
#ifdef APR_FOPEN_SENDFILE_ENABLED
  /* APR_FOPEN_SENDFILE_ENABLED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_SENDFILE_ENABLED", mrb_fixnum_value(APR_FOPEN_SENDFILE_ENABLED));
#endif
#ifdef APR_FOPEN_SHARELOCK
  /* APR_FOPEN_SHARELOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_SHARELOCK", mrb_fixnum_value(APR_FOPEN_SHARELOCK));
#endif
#ifdef APR_FOPEN_SPARSE
  /* APR_FOPEN_SPARSE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_SPARSE", mrb_fixnum_value(APR_FOPEN_SPARSE));
#endif
#ifdef APR_FOPEN_TRUNCATE
  /* APR_FOPEN_TRUNCATE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_TRUNCATE", mrb_fixnum_value(APR_FOPEN_TRUNCATE));
#endif
#ifdef APR_FOPEN_WRITE
  /* APR_FOPEN_WRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_WRITE", mrb_fixnum_value(APR_FOPEN_WRITE));
#endif
#ifdef APR_FOPEN_XTHREAD
  /* APR_FOPEN_XTHREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FOPEN_XTHREAD", mrb_fixnum_value(APR_FOPEN_XTHREAD));
#endif
#ifdef APR_FPROT_FILE_SOURCE_PERMS
  /* APR_FPROT_FILE_SOURCE_PERMS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_FILE_SOURCE_PERMS", mrb_fixnum_value(APR_FPROT_FILE_SOURCE_PERMS));
#endif
#ifdef APR_FPROT_GEXECUTE
  /* APR_FPROT_GEXECUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_GEXECUTE", mrb_fixnum_value(APR_FPROT_GEXECUTE));
#endif
#ifdef APR_FPROT_GREAD
  /* APR_FPROT_GREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_GREAD", mrb_fixnum_value(APR_FPROT_GREAD));
#endif
#ifdef APR_FPROT_GSETID
  /* APR_FPROT_GSETID assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_GSETID", mrb_fixnum_value(APR_FPROT_GSETID));
#endif
#ifdef APR_FPROT_GWRITE
  /* APR_FPROT_GWRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_GWRITE", mrb_fixnum_value(APR_FPROT_GWRITE));
#endif
#ifdef APR_FPROT_OS_DEFAULT
  /* APR_FPROT_OS_DEFAULT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_OS_DEFAULT", mrb_fixnum_value(APR_FPROT_OS_DEFAULT));
#endif
#ifdef APR_FPROT_UEXECUTE
  /* APR_FPROT_UEXECUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_UEXECUTE", mrb_fixnum_value(APR_FPROT_UEXECUTE));
#endif
#ifdef APR_FPROT_UREAD
  /* APR_FPROT_UREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_UREAD", mrb_fixnum_value(APR_FPROT_UREAD));
#endif
#ifdef APR_FPROT_USETID
  /* APR_FPROT_USETID assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_USETID", mrb_fixnum_value(APR_FPROT_USETID));
#endif
#ifdef APR_FPROT_UWRITE
  /* APR_FPROT_UWRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_UWRITE", mrb_fixnum_value(APR_FPROT_UWRITE));
#endif
#ifdef APR_FPROT_WEXECUTE
  /* APR_FPROT_WEXECUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_WEXECUTE", mrb_fixnum_value(APR_FPROT_WEXECUTE));
#endif
#ifdef APR_FPROT_WREAD
  /* APR_FPROT_WREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_WREAD", mrb_fixnum_value(APR_FPROT_WREAD));
#endif
#ifdef APR_FPROT_WSTICKY
  /* APR_FPROT_WSTICKY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_WSTICKY", mrb_fixnum_value(APR_FPROT_WSTICKY));
#endif
#ifdef APR_FPROT_WWRITE
  /* APR_FPROT_WWRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FPROT_WWRITE", mrb_fixnum_value(APR_FPROT_WWRITE));
#endif
#ifdef APR_FROM_OS_ERROR
  /* Ignoring function-like macro: APR_FROM_OS_ERROR(e) */
#endif
#ifdef APR_FULL_BLOCK
  /* APR_FULL_BLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FULL_BLOCK", mrb_fixnum_value(APR_FULL_BLOCK));
#endif
#ifdef APR_FULL_NONBLOCK
  /* APR_FULL_NONBLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_FULL_NONBLOCK", mrb_fixnum_value(APR_FULL_NONBLOCK));
#endif
#ifdef APR_GENERAL_H
  /* Ignoring macro with no expansion: APR_GENERAL_H */
#endif
#ifdef apr_get_netos_error
  /* Ignoring function-like macro: apr_get_netos_error() */
#endif
#ifdef apr_get_os_error
  /* Ignoring function-like macro: apr_get_os_error() */
#endif
#ifdef APR_GETOPT_H
  /* Ignoring macro with no expansion: APR_GETOPT_H */
#endif
#ifdef APR_GEXECUTE
  /* APR_GEXECUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_GEXECUTE", mrb_fixnum_value(APR_GEXECUTE));
#endif
#ifdef apr_global_mutex_child_init
  /* apr_global_mutex_child_init assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_child_init", mrb_fixnum_value(apr_global_mutex_child_init));
#endif
#ifdef apr_global_mutex_create
  /* apr_global_mutex_create assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_create", mrb_fixnum_value(apr_global_mutex_create));
#endif
#ifdef apr_global_mutex_destroy
  /* apr_global_mutex_destroy assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_destroy", mrb_fixnum_value(apr_global_mutex_destroy));
#endif
#ifdef APR_GLOBAL_MUTEX_H
  /* Ignoring macro with no expansion: APR_GLOBAL_MUTEX_H */
#endif
#ifdef apr_global_mutex_lock
  /* apr_global_mutex_lock assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_lock", mrb_fixnum_value(apr_global_mutex_lock));
#endif
#ifdef apr_global_mutex_lockfile
  /* apr_global_mutex_lockfile assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_lockfile", mrb_fixnum_value(apr_global_mutex_lockfile));
#endif
#ifdef apr_global_mutex_name
  /* apr_global_mutex_name assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_name", mrb_fixnum_value(apr_global_mutex_name));
#endif
#ifdef apr_global_mutex_pool_get
  /* apr_global_mutex_pool_get assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_pool_get", mrb_fixnum_value(apr_global_mutex_pool_get));
#endif
#ifdef apr_global_mutex_t
  /* apr_global_mutex_t assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_t", mrb_fixnum_value(apr_global_mutex_t));
#endif
#ifdef apr_global_mutex_trylock
  /* apr_global_mutex_trylock assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_trylock", mrb_fixnum_value(apr_global_mutex_trylock));
#endif
#ifdef apr_global_mutex_unlock
  /* apr_global_mutex_unlock assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_global_mutex_unlock", mrb_fixnum_value(apr_global_mutex_unlock));
#endif
#ifdef APR_GREAD
  /* APR_GREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_GREAD", mrb_fixnum_value(APR_GREAD));
#endif
#ifdef APR_GSETID
  /* APR_GSETID assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_GSETID", mrb_fixnum_value(APR_GSETID));
#endif
#ifdef APR_GWRITE
  /* APR_GWRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_GWRITE", mrb_fixnum_value(APR_GWRITE));
#endif
#ifdef APR_H
  /* Ignoring macro with no expansion: APR_H */
#endif
#ifdef APR_HAS_DSO
  /* APR_HAS_DSO assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_DSO", mrb_fixnum_value(APR_HAS_DSO));
#endif
#ifdef APR_HAS_FCNTL_SERIALIZE
  /* APR_HAS_FCNTL_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_FCNTL_SERIALIZE", mrb_fixnum_value(APR_HAS_FCNTL_SERIALIZE));
#endif
#ifdef APR_HAS_FLOCK_SERIALIZE
  /* APR_HAS_FLOCK_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_FLOCK_SERIALIZE", mrb_fixnum_value(APR_HAS_FLOCK_SERIALIZE));
#endif
#ifdef APR_HAS_FORK
  /* APR_HAS_FORK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_FORK", mrb_fixnum_value(APR_HAS_FORK));
#endif
#ifdef APR_HAS_INLINE
  /* APR_HAS_INLINE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_INLINE", mrb_fixnum_value(APR_HAS_INLINE));
#endif
#ifdef APR_HAS_LARGE_FILES
  /* APR_HAS_LARGE_FILES assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_LARGE_FILES", mrb_fixnum_value(APR_HAS_LARGE_FILES));
#endif
#ifdef APR_HAS_MMAP
  /* APR_HAS_MMAP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_MMAP", mrb_fixnum_value(APR_HAS_MMAP));
#endif
#ifdef APR_HAS_OS_UUID
  /* APR_HAS_OS_UUID assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_OS_UUID", mrb_fixnum_value(APR_HAS_OS_UUID));
#endif
#ifdef APR_HAS_OTHER_CHILD
  /* APR_HAS_OTHER_CHILD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_OTHER_CHILD", mrb_fixnum_value(APR_HAS_OTHER_CHILD));
#endif
#ifdef APR_HAS_POSIXSEM_SERIALIZE
  /* APR_HAS_POSIXSEM_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_POSIXSEM_SERIALIZE", mrb_fixnum_value(APR_HAS_POSIXSEM_SERIALIZE));
#endif
#ifdef APR_HAS_PROC_INVOKED
  /* APR_HAS_PROC_INVOKED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_PROC_INVOKED", mrb_fixnum_value(APR_HAS_PROC_INVOKED));
#endif
#ifdef APR_HAS_PROC_PTHREAD_SERIALIZE
  /* APR_HAS_PROC_PTHREAD_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_PROC_PTHREAD_SERIALIZE", mrb_fixnum_value(APR_HAS_PROC_PTHREAD_SERIALIZE));
#endif
#ifdef APR_HAS_RANDOM
  /* APR_HAS_RANDOM assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_RANDOM", mrb_fixnum_value(APR_HAS_RANDOM));
#endif
#ifdef APR_HAS_SENDFILE
  /* APR_HAS_SENDFILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_SENDFILE", mrb_fixnum_value(APR_HAS_SENDFILE));
#endif
#ifdef APR_HAS_SHARED_MEMORY
  /* APR_HAS_SHARED_MEMORY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_SHARED_MEMORY", mrb_fixnum_value(APR_HAS_SHARED_MEMORY));
#endif
#ifdef APR_HAS_SO_ACCEPTFILTER
  /* APR_HAS_SO_ACCEPTFILTER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_SO_ACCEPTFILTER", mrb_fixnum_value(APR_HAS_SO_ACCEPTFILTER));
#endif
#ifdef APR_HAS_SYSVSEM_SERIALIZE
  /* APR_HAS_SYSVSEM_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_SYSVSEM_SERIALIZE", mrb_fixnum_value(APR_HAS_SYSVSEM_SERIALIZE));
#endif
#ifdef APR_HAS_THREADS
  /* APR_HAS_THREADS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_THREADS", mrb_fixnum_value(APR_HAS_THREADS));
#endif
#ifdef APR_HAS_UNICODE_FS
  /* APR_HAS_UNICODE_FS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_UNICODE_FS", mrb_fixnum_value(APR_HAS_UNICODE_FS));
#endif
#ifdef APR_HAS_USER
  /* APR_HAS_USER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_USER", mrb_fixnum_value(APR_HAS_USER));
#endif
#ifdef APR_HAS_XTHREAD_FILES
  /* APR_HAS_XTHREAD_FILES assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAS_XTHREAD_FILES", mrb_fixnum_value(APR_HAS_XTHREAD_FILES));
#endif
#ifdef APR_HASH_H
  /* Ignoring macro with no expansion: APR_HASH_H */
#endif
#ifdef APR_HASH_KEY_STRING
  /* APR_HASH_KEY_STRING assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HASH_KEY_STRING", mrb_fixnum_value(APR_HASH_KEY_STRING));
#endif
#ifdef APR_HAVE_ARPA_INET_H
  /* APR_HAVE_ARPA_INET_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_ARPA_INET_H", mrb_fixnum_value(APR_HAVE_ARPA_INET_H));
#endif
#ifdef APR_HAVE_CONIO_H
  /* APR_HAVE_CONIO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_CONIO_H", mrb_fixnum_value(APR_HAVE_CONIO_H));
#endif
#ifdef APR_HAVE_CORKABLE_TCP
  /* APR_HAVE_CORKABLE_TCP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_CORKABLE_TCP", mrb_fixnum_value(APR_HAVE_CORKABLE_TCP));
#endif
#ifdef APR_HAVE_CRYPT_H
  /* APR_HAVE_CRYPT_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_CRYPT_H", mrb_fixnum_value(APR_HAVE_CRYPT_H));
#endif
#ifdef APR_HAVE_CTYPE_H
  /* APR_HAVE_CTYPE_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_CTYPE_H", mrb_fixnum_value(APR_HAVE_CTYPE_H));
#endif
#ifdef APR_HAVE_DIRENT_H
  /* APR_HAVE_DIRENT_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_DIRENT_H", mrb_fixnum_value(APR_HAVE_DIRENT_H));
#endif
#ifdef APR_HAVE_ERRNO_H
  /* APR_HAVE_ERRNO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_ERRNO_H", mrb_fixnum_value(APR_HAVE_ERRNO_H));
#endif
#ifdef APR_HAVE_FCNTL_H
  /* APR_HAVE_FCNTL_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_FCNTL_H", mrb_fixnum_value(APR_HAVE_FCNTL_H));
#endif
#ifdef APR_HAVE_GETRLIMIT
  /* APR_HAVE_GETRLIMIT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_GETRLIMIT", mrb_fixnum_value(APR_HAVE_GETRLIMIT));
#endif
#ifdef APR_HAVE_ICONV
  /* APR_HAVE_ICONV assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_ICONV", mrb_fixnum_value(APR_HAVE_ICONV));
#endif
#ifdef APR_HAVE_IN_ADDR
  /* APR_HAVE_IN_ADDR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_IN_ADDR", mrb_fixnum_value(APR_HAVE_IN_ADDR));
#endif
#ifdef APR_HAVE_INET_ADDR
  /* APR_HAVE_INET_ADDR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_INET_ADDR", mrb_fixnum_value(APR_HAVE_INET_ADDR));
#endif
#ifdef APR_HAVE_INET_NETWORK
  /* APR_HAVE_INET_NETWORK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_INET_NETWORK", mrb_fixnum_value(APR_HAVE_INET_NETWORK));
#endif
#ifdef APR_HAVE_IO_H
  /* APR_HAVE_IO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_IO_H", mrb_fixnum_value(APR_HAVE_IO_H));
#endif
#ifdef APR_HAVE_IOVEC
  /* APR_HAVE_IOVEC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_IOVEC", mrb_fixnum_value(APR_HAVE_IOVEC));
#endif
#ifdef APR_HAVE_IPV6
  /* APR_HAVE_IPV6 assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_IPV6", mrb_fixnum_value(APR_HAVE_IPV6));
#endif
#ifdef APR_HAVE_LIMITS_H
  /* APR_HAVE_LIMITS_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_LIMITS_H", mrb_fixnum_value(APR_HAVE_LIMITS_H));
#endif
#ifdef APR_HAVE_MEMCHR
  /* APR_HAVE_MEMCHR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_MEMCHR", mrb_fixnum_value(APR_HAVE_MEMCHR));
#endif
#ifdef APR_HAVE_MEMMOVE
  /* APR_HAVE_MEMMOVE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_MEMMOVE", mrb_fixnum_value(APR_HAVE_MEMMOVE));
#endif
#ifdef APR_HAVE_NETDB_H
  /* APR_HAVE_NETDB_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_NETDB_H", mrb_fixnum_value(APR_HAVE_NETDB_H));
#endif
#ifdef APR_HAVE_NETINET_IN_H
  /* APR_HAVE_NETINET_IN_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_NETINET_IN_H", mrb_fixnum_value(APR_HAVE_NETINET_IN_H));
#endif
#ifdef APR_HAVE_NETINET_SCTP_H
  /* APR_HAVE_NETINET_SCTP_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_NETINET_SCTP_H", mrb_fixnum_value(APR_HAVE_NETINET_SCTP_H));
#endif
#ifdef APR_HAVE_NETINET_SCTP_UIO_H
  /* APR_HAVE_NETINET_SCTP_UIO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_NETINET_SCTP_UIO_H", mrb_fixnum_value(APR_HAVE_NETINET_SCTP_UIO_H));
#endif
#ifdef APR_HAVE_NETINET_TCP_H
  /* APR_HAVE_NETINET_TCP_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_NETINET_TCP_H", mrb_fixnum_value(APR_HAVE_NETINET_TCP_H));
#endif
#ifdef APR_HAVE_PROCESS_H
  /* APR_HAVE_PROCESS_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_PROCESS_H", mrb_fixnum_value(APR_HAVE_PROCESS_H));
#endif
#ifdef APR_HAVE_PTHREAD_H
  /* APR_HAVE_PTHREAD_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_PTHREAD_H", mrb_fixnum_value(APR_HAVE_PTHREAD_H));
#endif
#ifdef APR_HAVE_SA_STORAGE
  /* APR_HAVE_SA_STORAGE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SA_STORAGE", mrb_fixnum_value(APR_HAVE_SA_STORAGE));
#endif
#ifdef APR_HAVE_SCTP
  /* APR_HAVE_SCTP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SCTP", mrb_fixnum_value(APR_HAVE_SCTP));
#endif
#ifdef APR_HAVE_SEMAPHORE_H
  /* APR_HAVE_SEMAPHORE_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SEMAPHORE_H", mrb_fixnum_value(APR_HAVE_SEMAPHORE_H));
#endif
#ifdef APR_HAVE_SETRLIMIT
  /* APR_HAVE_SETRLIMIT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SETRLIMIT", mrb_fixnum_value(APR_HAVE_SETRLIMIT));
#endif
#ifdef APR_HAVE_SHMEM_BEOS
  /* APR_HAVE_SHMEM_BEOS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_BEOS", mrb_fixnum_value(APR_HAVE_SHMEM_BEOS));
#endif
#ifdef APR_HAVE_SHMEM_MMAP_ANON
  /* APR_HAVE_SHMEM_MMAP_ANON assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_MMAP_ANON", mrb_fixnum_value(APR_HAVE_SHMEM_MMAP_ANON));
#endif
#ifdef APR_HAVE_SHMEM_MMAP_SHM
  /* APR_HAVE_SHMEM_MMAP_SHM assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_MMAP_SHM", mrb_fixnum_value(APR_HAVE_SHMEM_MMAP_SHM));
#endif
#ifdef APR_HAVE_SHMEM_MMAP_TMP
  /* APR_HAVE_SHMEM_MMAP_TMP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_MMAP_TMP", mrb_fixnum_value(APR_HAVE_SHMEM_MMAP_TMP));
#endif
#ifdef APR_HAVE_SHMEM_MMAP_ZERO
  /* APR_HAVE_SHMEM_MMAP_ZERO assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_MMAP_ZERO", mrb_fixnum_value(APR_HAVE_SHMEM_MMAP_ZERO));
#endif
#ifdef APR_HAVE_SHMEM_SHMGET
  /* APR_HAVE_SHMEM_SHMGET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_SHMGET", mrb_fixnum_value(APR_HAVE_SHMEM_SHMGET));
#endif
#ifdef APR_HAVE_SHMEM_SHMGET_ANON
  /* APR_HAVE_SHMEM_SHMGET_ANON assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SHMEM_SHMGET_ANON", mrb_fixnum_value(APR_HAVE_SHMEM_SHMGET_ANON));
#endif
#ifdef APR_HAVE_SIGACTION
  /* APR_HAVE_SIGACTION assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SIGACTION", mrb_fixnum_value(APR_HAVE_SIGACTION));
#endif
#ifdef APR_HAVE_SIGNAL_H
  /* APR_HAVE_SIGNAL_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SIGNAL_H", mrb_fixnum_value(APR_HAVE_SIGNAL_H));
#endif
#ifdef APR_HAVE_SIGSUSPEND
  /* APR_HAVE_SIGSUSPEND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SIGSUSPEND", mrb_fixnum_value(APR_HAVE_SIGSUSPEND));
#endif
#ifdef APR_HAVE_SIGWAIT
  /* APR_HAVE_SIGWAIT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SIGWAIT", mrb_fixnum_value(APR_HAVE_SIGWAIT));
#endif
#ifdef APR_HAVE_STDARG_H
  /* APR_HAVE_STDARG_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STDARG_H", mrb_fixnum_value(APR_HAVE_STDARG_H));
#endif
#ifdef APR_HAVE_STDDEF_H
  /* APR_HAVE_STDDEF_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STDDEF_H", mrb_fixnum_value(APR_HAVE_STDDEF_H));
#endif
#ifdef APR_HAVE_STDINT_H
  /* APR_HAVE_STDINT_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STDINT_H", mrb_fixnum_value(APR_HAVE_STDINT_H));
#endif
#ifdef APR_HAVE_STDIO_H
  /* APR_HAVE_STDIO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STDIO_H", mrb_fixnum_value(APR_HAVE_STDIO_H));
#endif
#ifdef APR_HAVE_STDLIB_H
  /* APR_HAVE_STDLIB_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STDLIB_H", mrb_fixnum_value(APR_HAVE_STDLIB_H));
#endif
#ifdef APR_HAVE_STRCASECMP
  /* APR_HAVE_STRCASECMP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRCASECMP", mrb_fixnum_value(APR_HAVE_STRCASECMP));
#endif
#ifdef APR_HAVE_STRDUP
  /* APR_HAVE_STRDUP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRDUP", mrb_fixnum_value(APR_HAVE_STRDUP));
#endif
#ifdef APR_HAVE_STRICMP
  /* APR_HAVE_STRICMP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRICMP", mrb_fixnum_value(APR_HAVE_STRICMP));
#endif
#ifdef APR_HAVE_STRING_H
  /* APR_HAVE_STRING_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRING_H", mrb_fixnum_value(APR_HAVE_STRING_H));
#endif
#ifdef APR_HAVE_STRINGS_H
  /* APR_HAVE_STRINGS_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRINGS_H", mrb_fixnum_value(APR_HAVE_STRINGS_H));
#endif
#ifdef APR_HAVE_STRNCASECMP
  /* APR_HAVE_STRNCASECMP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRNCASECMP", mrb_fixnum_value(APR_HAVE_STRNCASECMP));
#endif
#ifdef APR_HAVE_STRNICMP
  /* APR_HAVE_STRNICMP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRNICMP", mrb_fixnum_value(APR_HAVE_STRNICMP));
#endif
#ifdef APR_HAVE_STRSTR
  /* APR_HAVE_STRSTR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRSTR", mrb_fixnum_value(APR_HAVE_STRSTR));
#endif
#ifdef APR_HAVE_STRUCT_RLIMIT
  /* APR_HAVE_STRUCT_RLIMIT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_STRUCT_RLIMIT", mrb_fixnum_value(APR_HAVE_STRUCT_RLIMIT));
#endif
#ifdef APR_HAVE_SYS_IOCTL_H
  /* APR_HAVE_SYS_IOCTL_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_IOCTL_H", mrb_fixnum_value(APR_HAVE_SYS_IOCTL_H));
#endif
#ifdef APR_HAVE_SYS_SENDFILE_H
  /* APR_HAVE_SYS_SENDFILE_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_SENDFILE_H", mrb_fixnum_value(APR_HAVE_SYS_SENDFILE_H));
#endif
#ifdef APR_HAVE_SYS_SIGNAL_H
  /* APR_HAVE_SYS_SIGNAL_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_SIGNAL_H", mrb_fixnum_value(APR_HAVE_SYS_SIGNAL_H));
#endif
#ifdef APR_HAVE_SYS_SOCKET_H
  /* APR_HAVE_SYS_SOCKET_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_SOCKET_H", mrb_fixnum_value(APR_HAVE_SYS_SOCKET_H));
#endif
#ifdef APR_HAVE_SYS_SOCKIO_H
  /* APR_HAVE_SYS_SOCKIO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_SOCKIO_H", mrb_fixnum_value(APR_HAVE_SYS_SOCKIO_H));
#endif
#ifdef APR_HAVE_SYS_SYSLIMITS_H
  /* APR_HAVE_SYS_SYSLIMITS_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_SYSLIMITS_H", mrb_fixnum_value(APR_HAVE_SYS_SYSLIMITS_H));
#endif
#ifdef APR_HAVE_SYS_TIME_H
  /* APR_HAVE_SYS_TIME_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_TIME_H", mrb_fixnum_value(APR_HAVE_SYS_TIME_H));
#endif
#ifdef APR_HAVE_SYS_TYPES_H
  /* APR_HAVE_SYS_TYPES_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_TYPES_H", mrb_fixnum_value(APR_HAVE_SYS_TYPES_H));
#endif
#ifdef APR_HAVE_SYS_UIO_H
  /* APR_HAVE_SYS_UIO_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_UIO_H", mrb_fixnum_value(APR_HAVE_SYS_UIO_H));
#endif
#ifdef APR_HAVE_SYS_UN_H
  /* APR_HAVE_SYS_UN_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_UN_H", mrb_fixnum_value(APR_HAVE_SYS_UN_H));
#endif
#ifdef APR_HAVE_SYS_WAIT_H
  /* APR_HAVE_SYS_WAIT_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_SYS_WAIT_H", mrb_fixnum_value(APR_HAVE_SYS_WAIT_H));
#endif
#ifdef APR_HAVE_TIME_H
  /* APR_HAVE_TIME_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_TIME_H", mrb_fixnum_value(APR_HAVE_TIME_H));
#endif
#ifdef APR_HAVE_UNION_SEMUN
  /* APR_HAVE_UNION_SEMUN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_UNION_SEMUN", mrb_fixnum_value(APR_HAVE_UNION_SEMUN));
#endif
#ifdef APR_HAVE_UNISTD_H
  /* APR_HAVE_UNISTD_H assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_HAVE_UNISTD_H", mrb_fixnum_value(APR_HAVE_UNISTD_H));
#endif
#ifdef APR_INADDR_NONE
  /* APR_INADDR_NONE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INADDR_NONE", mrb_fixnum_value(APR_INADDR_NONE));
#endif
#ifdef APR_INCHILD
  /* APR_INCHILD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INCHILD", mrb_fixnum_value(APR_INCHILD));
#endif
#ifdef APR_INCOMPLETE
  /* APR_INCOMPLETE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INCOMPLETE", mrb_fixnum_value(APR_INCOMPLETE));
#endif
#ifdef APR_INCOMPLETE_READ
  /* APR_INCOMPLETE_READ assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INCOMPLETE_READ", mrb_fixnum_value(APR_INCOMPLETE_READ));
#endif
#ifdef APR_INCOMPLETE_WRITE
  /* APR_INCOMPLETE_WRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INCOMPLETE_WRITE", mrb_fixnum_value(APR_INCOMPLETE_WRITE));
#endif
#ifdef APR_INET
  /* APR_INET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INET", mrb_fixnum_value(APR_INET));
#endif
#ifdef APR_INET6
  /* APR_INET6 assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INET6", mrb_fixnum_value(APR_INET6));
#endif
#ifdef apr_inet_addr
  /* apr_inet_addr assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_inet_addr", mrb_fixnum_value(apr_inet_addr));
#endif
#ifdef APR_INHERIT_H
  /* Ignoring macro with no expansion: APR_INHERIT_H */
#endif
#ifdef APR_INLINE
  /* APR_INLINE assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "APR_INLINE", mrb_fixnum_value(APR_INLINE));
#endif
#ifdef APR_INPARENT
  /* APR_INPARENT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INPARENT", mrb_fixnum_value(APR_INPARENT));
#endif
#ifdef APR_INT16_MAX
  /* APR_INT16_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT16_MAX", mrb_fixnum_value(APR_INT16_MAX));
#endif
#ifdef APR_INT16_MIN
  /* APR_INT16_MIN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT16_MIN", mrb_fixnum_value(APR_INT16_MIN));
#endif
#ifdef APR_INT32_MAX
  /* APR_INT32_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT32_MAX", mrb_fixnum_value(APR_INT32_MAX));
#endif
#ifdef APR_INT32_MIN
  /* APR_INT32_MIN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT32_MIN", mrb_fixnum_value(APR_INT32_MIN));
#endif
#ifdef APR_INT64_C
  /* Ignoring function-like macro: APR_INT64_C(val) */
#endif
#ifdef APR_INT64_MAX
  /* APR_INT64_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT64_MAX", mrb_fixnum_value(APR_INT64_MAX));
#endif
#ifdef APR_INT64_MIN
  /* APR_INT64_MIN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT64_MIN", mrb_fixnum_value(APR_INT64_MIN));
#endif
#ifdef APR_INT64_T_FMT
  /* APR_INT64_T_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_INT64_T_FMT", mrb_str_new_cstr(mrb, APR_INT64_T_FMT));
#endif
#ifdef APR_IPV4_ADDR_OK
  /* APR_IPV4_ADDR_OK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_IPV4_ADDR_OK", mrb_fixnum_value(APR_IPV4_ADDR_OK));
#endif
#ifdef APR_IPV6_ADDR_OK
  /* APR_IPV6_ADDR_OK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_IPV6_ADDR_OK", mrb_fixnum_value(APR_IPV6_ADDR_OK));
#endif
#ifdef APR_IPV6_V6ONLY
  /* APR_IPV6_V6ONLY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_IPV6_V6ONLY", mrb_fixnum_value(APR_IPV6_V6ONLY));
#endif
#ifdef APR_IS_BIGENDIAN
  /* APR_IS_BIGENDIAN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_IS_BIGENDIAN", mrb_fixnum_value(APR_IS_BIGENDIAN));
#endif
#ifdef APR_IS_DEV_STRING
  /* APR_IS_DEV_STRING appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_IS_DEV_STRING", mrb_str_new_cstr(mrb, APR_IS_DEV_STRING));
#endif
#ifdef apr_isalnum
  /* Ignoring function-like macro: apr_isalnum(c) */
#endif
#ifdef apr_isalpha
  /* Ignoring function-like macro: apr_isalpha(c) */
#endif
#ifdef apr_isascii
  /* Ignoring function-like macro: apr_isascii(c) */
#endif
#ifdef apr_iscntrl
  /* Ignoring function-like macro: apr_iscntrl(c) */
#endif
#ifdef apr_isdigit
  /* Ignoring function-like macro: apr_isdigit(c) */
#endif
#ifdef apr_isgraph
  /* Ignoring function-like macro: apr_isgraph(c) */
#endif
#ifdef apr_islower
  /* Ignoring function-like macro: apr_islower(c) */
#endif
#ifdef apr_isprint
  /* Ignoring function-like macro: apr_isprint(c) */
#endif
#ifdef apr_ispunct
  /* Ignoring function-like macro: apr_ispunct(c) */
#endif
#ifdef apr_isspace
  /* Ignoring function-like macro: apr_isspace(c) */
#endif
#ifdef apr_isupper
  /* Ignoring function-like macro: apr_isupper(c) */
#endif
#ifdef apr_isxdigit
  /* Ignoring function-like macro: apr_isxdigit(c) */
#endif
#ifdef APR_KEYBASED
  /* APR_KEYBASED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_KEYBASED", mrb_fixnum_value(APR_KEYBASED));
#endif
#ifdef apr_killpg
  /* Ignoring function-like macro: apr_killpg(x, y) */
#endif
#ifdef APR_LARGEFILE
  /* APR_LARGEFILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_LARGEFILE", mrb_fixnum_value(APR_LARGEFILE));
#endif
#ifdef APR_LIB_H
  /* Ignoring macro with no expansion: APR_LIB_H */
#endif
#ifdef APR_LIMIT_CPU
  /* APR_LIMIT_CPU assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_LIMIT_CPU", mrb_fixnum_value(APR_LIMIT_CPU));
#endif
#ifdef APR_LIMIT_MEM
  /* APR_LIMIT_MEM assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_LIMIT_MEM", mrb_fixnum_value(APR_LIMIT_MEM));
#endif
#ifdef APR_LIMIT_NOFILE
  /* APR_LIMIT_NOFILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_LIMIT_NOFILE", mrb_fixnum_value(APR_LIMIT_NOFILE));
#endif
#ifdef APR_LIMIT_NPROC
  /* APR_LIMIT_NPROC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_LIMIT_NPROC", mrb_fixnum_value(APR_LIMIT_NPROC));
#endif
#ifdef APR_MAJOR_VERSION
  /* APR_MAJOR_VERSION assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MAJOR_VERSION", mrb_fixnum_value(APR_MAJOR_VERSION));
#endif
#ifdef APR_MAX_IOVEC_SIZE
  /* APR_MAX_IOVEC_SIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MAX_IOVEC_SIZE", mrb_fixnum_value(APR_MAX_IOVEC_SIZE));
#endif
#ifdef APR_MAX_SECS_TO_LINGER
  /* APR_MAX_SECS_TO_LINGER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MAX_SECS_TO_LINGER", mrb_fixnum_value(APR_MAX_SECS_TO_LINGER));
#endif
#ifdef APR_MEMNODE_T_SIZE
  /* APR_MEMNODE_T_SIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MEMNODE_T_SIZE", mrb_fixnum_value(APR_MEMNODE_T_SIZE));
#endif
#ifdef APR_MINOR_VERSION
  /* APR_MINOR_VERSION assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MINOR_VERSION", mrb_fixnum_value(APR_MINOR_VERSION));
#endif
#ifdef APR_MMAP_CANDIDATE
  /* Ignoring function-like macro: APR_MMAP_CANDIDATE(filelength) */
#endif
#ifdef APR_MMAP_H
  /* Ignoring macro with no expansion: APR_MMAP_H */
#endif
#ifdef APR_MMAP_LIMIT
  /* APR_MMAP_LIMIT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MMAP_LIMIT", mrb_fixnum_value(APR_MMAP_LIMIT));
#endif
#ifdef APR_MMAP_READ
  /* APR_MMAP_READ assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MMAP_READ", mrb_fixnum_value(APR_MMAP_READ));
#endif
#ifdef APR_MMAP_THRESHOLD
  /* APR_MMAP_THRESHOLD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MMAP_THRESHOLD", mrb_fixnum_value(APR_MMAP_THRESHOLD));
#endif
#ifdef APR_MMAP_WRITE
  /* APR_MMAP_WRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_MMAP_WRITE", mrb_fixnum_value(APR_MMAP_WRITE));
#endif
#ifdef APR_NETWORK_IO_H
  /* Ignoring macro with no expansion: APR_NETWORK_IO_H */
#endif
#ifdef APR_NO_FILE
  /* APR_NO_FILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_NO_FILE", mrb_fixnum_value(APR_NO_FILE));
#endif
#ifdef APR_NO_FILE
  /* APR_NO_FILE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_NO_FILE", mrb_fixnum_value(APR_NO_FILE));
#endif
#ifdef APR_NO_PIPE
  /* APR_NO_PIPE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_NO_PIPE", mrb_fixnum_value(APR_NO_PIPE));
#endif
#ifdef APR_NOTDETACH
  /* APR_NOTDETACH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_NOTDETACH", mrb_fixnum_value(APR_NOTDETACH));
#endif
#ifdef APR_NOTFOUND
  /* APR_NOTFOUND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_NOTFOUND", mrb_fixnum_value(APR_NOTFOUND));
#endif
#ifdef APR_O_NONBLOCK_INHERITED
  /* APR_O_NONBLOCK_INHERITED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_O_NONBLOCK_INHERITED", mrb_fixnum_value(APR_O_NONBLOCK_INHERITED));
#endif
#ifdef APR_OC_REASON_DEATH
  /* APR_OC_REASON_DEATH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OC_REASON_DEATH", mrb_fixnum_value(APR_OC_REASON_DEATH));
#endif
#ifdef APR_OC_REASON_LOST
  /* APR_OC_REASON_LOST assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OC_REASON_LOST", mrb_fixnum_value(APR_OC_REASON_LOST));
#endif
#ifdef APR_OC_REASON_RESTART
  /* APR_OC_REASON_RESTART assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OC_REASON_RESTART", mrb_fixnum_value(APR_OC_REASON_RESTART));
#endif
#ifdef APR_OC_REASON_RUNNING
  /* APR_OC_REASON_RUNNING assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OC_REASON_RUNNING", mrb_fixnum_value(APR_OC_REASON_RUNNING));
#endif
#ifdef APR_OC_REASON_UNREGISTER
  /* APR_OC_REASON_UNREGISTER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OC_REASON_UNREGISTER", mrb_fixnum_value(APR_OC_REASON_UNREGISTER));
#endif
#ifdef APR_OC_REASON_UNWRITABLE
  /* APR_OC_REASON_UNWRITABLE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OC_REASON_UNWRITABLE", mrb_fixnum_value(APR_OC_REASON_UNWRITABLE));
#endif
#ifdef APR_OFF_T_FMT
  /* APR_OFF_T_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_OFF_T_FMT", mrb_str_new_cstr(mrb, APR_OFF_T_FMT));
#endif
#ifdef APR_OFFSET
  /* Ignoring function-like macro: APR_OFFSET(p_type, field) */
#endif
#ifdef APR_OFFSETOF
  /* Ignoring function-like macro: APR_OFFSETOF(s_type, field) */
#endif
#ifdef APR_OS_DEFAULT
  /* APR_OS_DEFAULT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_DEFAULT", mrb_fixnum_value(APR_OS_DEFAULT));
#endif
#ifdef APR_OS_ERRSPACE_SIZE
  /* APR_OS_ERRSPACE_SIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_ERRSPACE_SIZE", mrb_fixnum_value(APR_OS_ERRSPACE_SIZE));
#endif
#ifdef apr_os_global_mutex_get
  /* apr_os_global_mutex_get assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_os_global_mutex_get", mrb_fixnum_value(apr_os_global_mutex_get));
#endif
#ifdef apr_os_global_mutex_t
  /* apr_os_global_mutex_t assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "apr_os_global_mutex_t", mrb_fixnum_value(apr_os_global_mutex_t));
#endif
#ifdef APR_OS_START_CANONERR
  /* APR_OS_START_CANONERR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_CANONERR", mrb_fixnum_value(APR_OS_START_CANONERR));
#endif
#ifdef APR_OS_START_EAIERR
  /* APR_OS_START_EAIERR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_EAIERR", mrb_fixnum_value(APR_OS_START_EAIERR));
#endif
#ifdef APR_OS_START_ERROR
  /* APR_OS_START_ERROR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_ERROR", mrb_fixnum_value(APR_OS_START_ERROR));
#endif
#ifdef APR_OS_START_STATUS
  /* APR_OS_START_STATUS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_STATUS", mrb_fixnum_value(APR_OS_START_STATUS));
#endif
#ifdef APR_OS_START_SYSERR
  /* APR_OS_START_SYSERR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_SYSERR", mrb_fixnum_value(APR_OS_START_SYSERR));
#endif
#ifdef APR_OS_START_USEERR
  /* APR_OS_START_USEERR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_USEERR", mrb_fixnum_value(APR_OS_START_USEERR));
#endif
#ifdef APR_OS_START_USERERR
  /* APR_OS_START_USERERR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OS_START_USERERR", mrb_fixnum_value(APR_OS_START_USERERR));
#endif
#ifdef APR_OVERLAP_TABLES_MERGE
  /* APR_OVERLAP_TABLES_MERGE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OVERLAP_TABLES_MERGE", mrb_fixnum_value(APR_OVERLAP_TABLES_MERGE));
#endif
#ifdef APR_OVERLAP_TABLES_SET
  /* APR_OVERLAP_TABLES_SET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_OVERLAP_TABLES_SET", mrb_fixnum_value(APR_OVERLAP_TABLES_SET));
#endif
#ifdef APR_PARENT_BLOCK
  /* APR_PARENT_BLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PARENT_BLOCK", mrb_fixnum_value(APR_PARENT_BLOCK));
#endif
#ifdef APR_PATCH_VERSION
  /* APR_PATCH_VERSION assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PATCH_VERSION", mrb_fixnum_value(APR_PATCH_VERSION));
#endif
#ifdef APR_PATH_MAX
  /* APR_PATH_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PATH_MAX", mrb_fixnum_value(APR_PATH_MAX));
#endif
#ifdef apr_pcalloc
  /* Ignoring function-like macro: apr_pcalloc(p, size) */
#endif
#ifdef APR_PID_T_FMT
  /* APR_PID_T_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_PID_T_FMT", mrb_str_new_cstr(mrb, APR_PID_T_FMT));
#endif
#ifdef APR_POLL_H
  /* Ignoring macro with no expansion: APR_POLL_H */
#endif
#ifdef APR_POLLERR
  /* APR_POLLERR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLERR", mrb_fixnum_value(APR_POLLERR));
#endif
#ifdef APR_POLLHUP
  /* APR_POLLHUP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLHUP", mrb_fixnum_value(APR_POLLHUP));
#endif
#ifdef APR_POLLIN
  /* APR_POLLIN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLIN", mrb_fixnum_value(APR_POLLIN));
#endif
#ifdef APR_POLLNVAL
  /* APR_POLLNVAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLNVAL", mrb_fixnum_value(APR_POLLNVAL));
#endif
#ifdef APR_POLLOUT
  /* APR_POLLOUT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLOUT", mrb_fixnum_value(APR_POLLOUT));
#endif
#ifdef APR_POLLPRI
  /* APR_POLLPRI assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLPRI", mrb_fixnum_value(APR_POLLPRI));
#endif
#ifdef APR_POLLSET_NOCOPY
  /* APR_POLLSET_NOCOPY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLSET_NOCOPY", mrb_fixnum_value(APR_POLLSET_NOCOPY));
#endif
#ifdef APR_POLLSET_NODEFAULT
  /* APR_POLLSET_NODEFAULT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLSET_NODEFAULT", mrb_fixnum_value(APR_POLLSET_NODEFAULT));
#endif
#ifdef APR_POLLSET_THREADSAFE
  /* APR_POLLSET_THREADSAFE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLSET_THREADSAFE", mrb_fixnum_value(APR_POLLSET_THREADSAFE));
#endif
#ifdef APR_POLLSET_WAKEABLE
  /* APR_POLLSET_WAKEABLE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POLLSET_WAKEABLE", mrb_fixnum_value(APR_POLLSET_WAKEABLE));
#endif
#ifdef APR_POOL__FILE_LINE__
  /* APR_POOL__FILE_LINE__ appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_POOL__FILE_LINE__", mrb_str_new_cstr(mrb, APR_POOL__FILE_LINE__));
#endif
#ifdef apr_pool_create
  /* Ignoring function-like macro: apr_pool_create(newpool, parent) */
#endif
#ifdef apr_pool_create_core
  /* Ignoring function-like macro: apr_pool_create_core(newpool) */
#endif
#ifdef apr_pool_create_unmanaged
  /* Ignoring function-like macro: apr_pool_create_unmanaged(newpool) */
#endif
#ifdef APR_POOL_DEBUG
  /* APR_POOL_DEBUG assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_POOL_DEBUG", mrb_fixnum_value(APR_POOL_DEBUG));
#endif
#ifdef APR_POOL_DECLARE_ACCESSOR
  /* Ignoring function-like macro: APR_POOL_DECLARE_ACCESSOR(type) */
#endif
#ifdef APR_POOL_IMPLEMENT_ACCESSOR
  /* Ignoring function-like macro: APR_POOL_IMPLEMENT_ACCESSOR(type) */
#endif
#ifdef apr_pool_join
  /* Ignoring macro with no expansion: apr_pool_join */
#endif
#ifdef apr_pool_lock
  /* Ignoring function-like macro: apr_pool_lock(pool, lock) */
#endif
#ifdef APR_POOLS_H
  /* Ignoring macro with no expansion: APR_POOLS_H */
#endif
#ifdef APR_PORTABLE_H
  /* Ignoring macro with no expansion: APR_PORTABLE_H */
#endif
#ifdef APR_PROC_CHECK_CORE_DUMP
  /* Ignoring function-like macro: APR_PROC_CHECK_CORE_DUMP(x) */
#endif
#ifdef APR_PROC_CHECK_EXIT
  /* Ignoring function-like macro: APR_PROC_CHECK_EXIT(x) */
#endif
#ifdef APR_PROC_CHECK_SIGNALED
  /* Ignoring function-like macro: APR_PROC_CHECK_SIGNALED(x) */
#endif
#ifdef APR_PROC_DETACH_DAEMONIZE
  /* APR_PROC_DETACH_DAEMONIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROC_DETACH_DAEMONIZE", mrb_fixnum_value(APR_PROC_DETACH_DAEMONIZE));
#endif
#ifdef APR_PROC_DETACH_FOREGROUND
  /* APR_PROC_DETACH_FOREGROUND assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROC_DETACH_FOREGROUND", mrb_fixnum_value(APR_PROC_DETACH_FOREGROUND));
#endif
#ifdef APR_PROC_MUTEX_H
  /* Ignoring macro with no expansion: APR_PROC_MUTEX_H */
#endif
#ifdef APR_PROC_MUTEX_IS_GLOBAL
  /* APR_PROC_MUTEX_IS_GLOBAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROC_MUTEX_IS_GLOBAL", mrb_fixnum_value(APR_PROC_MUTEX_IS_GLOBAL));
#endif
#ifdef APR_PROCATTR_USER_SET_REQUIRES_PASSWORD
  /* APR_PROCATTR_USER_SET_REQUIRES_PASSWORD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROCATTR_USER_SET_REQUIRES_PASSWORD", mrb_fixnum_value(APR_PROCATTR_USER_SET_REQUIRES_PASSWORD));
#endif
#ifdef APR_PROCESS_LOCK_IS_GLOBAL
  /* APR_PROCESS_LOCK_IS_GLOBAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROCESS_LOCK_IS_GLOBAL", mrb_fixnum_value(APR_PROCESS_LOCK_IS_GLOBAL));
#endif
#ifdef APR_PROTO_SCTP
  /* APR_PROTO_SCTP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROTO_SCTP", mrb_fixnum_value(APR_PROTO_SCTP));
#endif
#ifdef APR_PROTO_TCP
  /* APR_PROTO_TCP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROTO_TCP", mrb_fixnum_value(APR_PROTO_TCP));
#endif
#ifdef APR_PROTO_UDP
  /* APR_PROTO_UDP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_PROTO_UDP", mrb_fixnum_value(APR_PROTO_UDP));
#endif
#ifdef APR_RANDOM_H
  /* Ignoring macro with no expansion: APR_RANDOM_H */
#endif
#ifdef APR_READ
  /* APR_READ assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_READ", mrb_fixnum_value(APR_READ));
#endif
#ifdef APR_READ_BLOCK
  /* APR_READ_BLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_READ_BLOCK", mrb_fixnum_value(APR_READ_BLOCK));
#endif
#ifdef APR_RESET_NODELAY
  /* APR_RESET_NODELAY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_RESET_NODELAY", mrb_fixnum_value(APR_RESET_NODELAY));
#endif
#ifdef APR_RFC822_DATE_LEN
  /* APR_RFC822_DATE_LEN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_RFC822_DATE_LEN", mrb_fixnum_value(APR_RFC822_DATE_LEN));
#endif
#ifdef APR_RING_CHECK
  /* Ignoring function-like macro: APR_RING_CHECK(hp, elem, link, msg) */
#endif
#ifdef APR_RING_CHECK_CONSISTENCY
  /* Ignoring function-like macro: APR_RING_CHECK_CONSISTENCY(hp, elem, link) */
#endif
#ifdef APR_RING_CHECK_ELEM
  /* Ignoring function-like macro: APR_RING_CHECK_ELEM(ep, elem, link, msg) */
#endif
#ifdef APR_RING_CHECK_ELEM_CONSISTENCY
  /* Ignoring function-like macro: APR_RING_CHECK_ELEM_CONSISTENCY(ep, elem, link) */
#endif
#ifdef APR_RING_CHECK_ONE
  /* Ignoring function-like macro: APR_RING_CHECK_ONE(msg, ptr) */
#endif
#ifdef APR_RING_CONCAT
  /* Ignoring function-like macro: APR_RING_CONCAT(h1, h2, elem, link) */
#endif
#ifdef APR_RING_ELEM_INIT
  /* Ignoring function-like macro: APR_RING_ELEM_INIT(ep, link) */
#endif
#ifdef APR_RING_EMPTY
  /* Ignoring function-like macro: APR_RING_EMPTY(hp, elem, link) */
#endif
#ifdef APR_RING_ENTRY
  /* Ignoring function-like macro: APR_RING_ENTRY(elem) */
#endif
#ifdef APR_RING_FIRST
  /* Ignoring function-like macro: APR_RING_FIRST(hp) */
#endif
#ifdef APR_RING_FOREACH
  /* Ignoring function-like macro: APR_RING_FOREACH(ep, head, elem, link) */
#endif
#ifdef APR_RING_FOREACH_SAFE
  /* Ignoring function-like macro: APR_RING_FOREACH_SAFE(ep1, ep2, head, elem, link) */
#endif
#ifdef APR_RING_H
  /* Ignoring macro with no expansion: APR_RING_H */
#endif
#ifdef APR_RING_HEAD
  /* Ignoring function-like macro: APR_RING_HEAD(head, elem) */
#endif
#ifdef APR_RING_INIT
  /* Ignoring function-like macro: APR_RING_INIT(hp, elem, link) */
#endif
#ifdef APR_RING_INSERT_AFTER
  /* Ignoring function-like macro: APR_RING_INSERT_AFTER(lep, nep, link) */
#endif
#ifdef APR_RING_INSERT_BEFORE
  /* Ignoring function-like macro: APR_RING_INSERT_BEFORE(lep, nep, link) */
#endif
#ifdef APR_RING_INSERT_HEAD
  /* Ignoring function-like macro: APR_RING_INSERT_HEAD(hp, nep, elem, link) */
#endif
#ifdef APR_RING_INSERT_TAIL
  /* Ignoring function-like macro: APR_RING_INSERT_TAIL(hp, nep, elem, link) */
#endif
#ifdef APR_RING_LAST
  /* Ignoring function-like macro: APR_RING_LAST(hp) */
#endif
#ifdef APR_RING_NEXT
  /* Ignoring function-like macro: APR_RING_NEXT(ep, link) */
#endif
#ifdef APR_RING_PREPEND
  /* Ignoring function-like macro: APR_RING_PREPEND(h1, h2, elem, link) */
#endif
#ifdef APR_RING_PREV
  /* Ignoring function-like macro: APR_RING_PREV(ep, link) */
#endif
#ifdef APR_RING_REMOVE
  /* Ignoring function-like macro: APR_RING_REMOVE(ep, link) */
#endif
#ifdef APR_RING_SENTINEL
  /* Ignoring function-like macro: APR_RING_SENTINEL(hp, elem, link) */
#endif
#ifdef APR_RING_SPLICE_AFTER
  /* Ignoring function-like macro: APR_RING_SPLICE_AFTER(lep, ep1, epN, link) */
#endif
#ifdef APR_RING_SPLICE_BEFORE
  /* Ignoring function-like macro: APR_RING_SPLICE_BEFORE(lep, ep1, epN, link) */
#endif
#ifdef APR_RING_SPLICE_HEAD
  /* Ignoring function-like macro: APR_RING_SPLICE_HEAD(hp, ep1, epN, elem, link) */
#endif
#ifdef APR_RING_SPLICE_TAIL
  /* Ignoring function-like macro: APR_RING_SPLICE_TAIL(hp, ep1, epN, elem, link) */
#endif
#ifdef APR_RING_UNSPLICE
  /* Ignoring function-like macro: APR_RING_UNSPLICE(ep1, epN, link) */
#endif
#ifdef APR_SENDFILE_DISCONNECT_SOCKET
  /* APR_SENDFILE_DISCONNECT_SOCKET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SENDFILE_DISCONNECT_SOCKET", mrb_fixnum_value(APR_SENDFILE_DISCONNECT_SOCKET));
#endif
#ifdef APR_SENDFILE_ENABLED
  /* APR_SENDFILE_ENABLED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SENDFILE_ENABLED", mrb_fixnum_value(APR_SENDFILE_ENABLED));
#endif
#ifdef APR_SET
  /* APR_SET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SET", mrb_fixnum_value(APR_SET));
#endif
#ifdef apr_set_netos_error
  /* Ignoring function-like macro: apr_set_netos_error(e) */
#endif
#ifdef apr_set_os_error
  /* Ignoring function-like macro: apr_set_os_error(e) */
#endif
#ifdef APR_SHARELOCK
  /* APR_SHARELOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SHARELOCK", mrb_fixnum_value(APR_SHARELOCK));
#endif
#ifdef APR_SHM_H
  /* Ignoring macro with no expansion: APR_SHM_H */
#endif
#ifdef APR_SHM_NS_GLOBAL
  /* APR_SHM_NS_GLOBAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SHM_NS_GLOBAL", mrb_fixnum_value(APR_SHM_NS_GLOBAL));
#endif
#ifdef APR_SHM_NS_LOCAL
  /* APR_SHM_NS_LOCAL assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SHM_NS_LOCAL", mrb_fixnum_value(APR_SHM_NS_LOCAL));
#endif
#ifdef apr_signal
  /* Ignoring function-like macro: apr_signal(a, b) */
#endif
#ifdef APR_SIGNAL_H
  /* Ignoring macro with no expansion: APR_SIGNAL_H */
#endif
#ifdef APR_SIZE_MAX
  /* APR_SIZE_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SIZE_MAX", mrb_fixnum_value(APR_SIZE_MAX));
#endif
#ifdef APR_SIZE_T_FMT
  /* APR_SIZE_T_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_SIZE_T_FMT", mrb_str_new_cstr(mrb, APR_SIZE_T_FMT));
#endif
#ifdef APR_SIZEOF_VOIDP
  /* APR_SIZEOF_VOIDP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SIZEOF_VOIDP", mrb_fixnum_value(APR_SIZEOF_VOIDP));
#endif
#ifdef APR_SKIPLIST_H
  /* Ignoring macro with no expansion: APR_SKIPLIST_H */
#endif
#ifdef APR_SO_BROADCAST
  /* APR_SO_BROADCAST assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_BROADCAST", mrb_fixnum_value(APR_SO_BROADCAST));
#endif
#ifdef APR_SO_DEBUG
  /* APR_SO_DEBUG assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_DEBUG", mrb_fixnum_value(APR_SO_DEBUG));
#endif
#ifdef APR_SO_DISCONNECTED
  /* APR_SO_DISCONNECTED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_DISCONNECTED", mrb_fixnum_value(APR_SO_DISCONNECTED));
#endif
#ifdef APR_SO_KEEPALIVE
  /* APR_SO_KEEPALIVE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_KEEPALIVE", mrb_fixnum_value(APR_SO_KEEPALIVE));
#endif
#ifdef APR_SO_LINGER
  /* APR_SO_LINGER assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_LINGER", mrb_fixnum_value(APR_SO_LINGER));
#endif
#ifdef APR_SO_NONBLOCK
  /* APR_SO_NONBLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_NONBLOCK", mrb_fixnum_value(APR_SO_NONBLOCK));
#endif
#ifdef APR_SO_RCVBUF
  /* APR_SO_RCVBUF assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_RCVBUF", mrb_fixnum_value(APR_SO_RCVBUF));
#endif
#ifdef APR_SO_REUSEADDR
  /* APR_SO_REUSEADDR assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_REUSEADDR", mrb_fixnum_value(APR_SO_REUSEADDR));
#endif
#ifdef APR_SO_SNDBUF
  /* APR_SO_SNDBUF assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SO_SNDBUF", mrb_fixnum_value(APR_SO_SNDBUF));
#endif
#ifdef APR_SSIZE_T_FMT
  /* APR_SSIZE_T_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_SSIZE_T_FMT", mrb_str_new_cstr(mrb, APR_SSIZE_T_FMT));
#endif
#ifdef APR_STATUS_IS_ANONYMOUS
  /* Ignoring function-like macro: APR_STATUS_IS_ANONYMOUS(s) */
#endif
#ifdef APR_STATUS_IS_BADARG
  /* Ignoring function-like macro: APR_STATUS_IS_BADARG(s) */
#endif
#ifdef APR_STATUS_IS_BADCH
  /* Ignoring function-like macro: APR_STATUS_IS_BADCH(s) */
#endif
#ifdef APR_STATUS_IS_CHILD_DONE
  /* Ignoring function-like macro: APR_STATUS_IS_CHILD_DONE(s) */
#endif
#ifdef APR_STATUS_IS_CHILD_NOTDONE
  /* Ignoring function-like macro: APR_STATUS_IS_CHILD_NOTDONE(s) */
#endif
#ifdef APR_STATUS_IS_DETACH
  /* Ignoring function-like macro: APR_STATUS_IS_DETACH(s) */
#endif
#ifdef APR_STATUS_IS_EABOVEROOT
  /* Ignoring function-like macro: APR_STATUS_IS_EABOVEROOT(s) */
#endif
#ifdef APR_STATUS_IS_EABSOLUTE
  /* Ignoring function-like macro: APR_STATUS_IS_EABSOLUTE(s) */
#endif
#ifdef APR_STATUS_IS_EACCES
  /* Ignoring function-like macro: APR_STATUS_IS_EACCES(s) */
#endif
#ifdef APR_STATUS_IS_EAFNOSUPPORT
  /* Ignoring function-like macro: APR_STATUS_IS_EAFNOSUPPORT(s) */
#endif
#ifdef APR_STATUS_IS_EAGAIN
  /* Ignoring function-like macro: APR_STATUS_IS_EAGAIN(s) */
#endif
#ifdef APR_STATUS_IS_EBADDATE
  /* Ignoring function-like macro: APR_STATUS_IS_EBADDATE(s) */
#endif
#ifdef APR_STATUS_IS_EBADF
  /* Ignoring function-like macro: APR_STATUS_IS_EBADF(s) */
#endif
#ifdef APR_STATUS_IS_EBADIP
  /* Ignoring function-like macro: APR_STATUS_IS_EBADIP(s) */
#endif
#ifdef APR_STATUS_IS_EBADMASK
  /* Ignoring function-like macro: APR_STATUS_IS_EBADMASK(s) */
#endif
#ifdef APR_STATUS_IS_EBADPATH
  /* Ignoring function-like macro: APR_STATUS_IS_EBADPATH(s) */
#endif
#ifdef APR_STATUS_IS_EBUSY
  /* Ignoring function-like macro: APR_STATUS_IS_EBUSY(s) */
#endif
#ifdef APR_STATUS_IS_ECONNABORTED
  /* Ignoring function-like macro: APR_STATUS_IS_ECONNABORTED(s) */
#endif
#ifdef APR_STATUS_IS_ECONNREFUSED
  /* Ignoring function-like macro: APR_STATUS_IS_ECONNREFUSED(s) */
#endif
#ifdef APR_STATUS_IS_ECONNRESET
  /* Ignoring function-like macro: APR_STATUS_IS_ECONNRESET(s) */
#endif
#ifdef APR_STATUS_IS_EDSOOPEN
  /* Ignoring function-like macro: APR_STATUS_IS_EDSOOPEN(s) */
#endif
#ifdef APR_STATUS_IS_EEXIST
  /* Ignoring function-like macro: APR_STATUS_IS_EEXIST(s) */
#endif
#ifdef APR_STATUS_IS_EFTYPE
  /* Ignoring function-like macro: APR_STATUS_IS_EFTYPE(s) */
#endif
#ifdef APR_STATUS_IS_EGENERAL
  /* Ignoring function-like macro: APR_STATUS_IS_EGENERAL(s) */
#endif
#ifdef APR_STATUS_IS_EHOSTUNREACH
  /* Ignoring function-like macro: APR_STATUS_IS_EHOSTUNREACH(s) */
#endif
#ifdef APR_STATUS_IS_EINCOMPLETE
  /* Ignoring function-like macro: APR_STATUS_IS_EINCOMPLETE(s) */
#endif
#ifdef APR_STATUS_IS_EINIT
  /* Ignoring function-like macro: APR_STATUS_IS_EINIT(s) */
#endif
#ifdef APR_STATUS_IS_EINPROGRESS
  /* Ignoring function-like macro: APR_STATUS_IS_EINPROGRESS(s) */
#endif
#ifdef APR_STATUS_IS_EINTR
  /* Ignoring function-like macro: APR_STATUS_IS_EINTR(s) */
#endif
#ifdef APR_STATUS_IS_EINVAL
  /* Ignoring function-like macro: APR_STATUS_IS_EINVAL(s) */
#endif
#ifdef APR_STATUS_IS_EINVALSOCK
  /* Ignoring function-like macro: APR_STATUS_IS_EINVALSOCK(s) */
#endif
#ifdef APR_STATUS_IS_EMFILE
  /* Ignoring function-like macro: APR_STATUS_IS_EMFILE(s) */
#endif
#ifdef APR_STATUS_IS_EMISMATCH
  /* Ignoring function-like macro: APR_STATUS_IS_EMISMATCH(s) */
#endif
#ifdef APR_STATUS_IS_ENAMETOOLONG
  /* Ignoring function-like macro: APR_STATUS_IS_ENAMETOOLONG(s) */
#endif
#ifdef APR_STATUS_IS_ENETUNREACH
  /* Ignoring function-like macro: APR_STATUS_IS_ENETUNREACH(s) */
#endif
#ifdef APR_STATUS_IS_ENFILE
  /* Ignoring function-like macro: APR_STATUS_IS_ENFILE(s) */
#endif
#ifdef APR_STATUS_IS_ENODIR
  /* Ignoring function-like macro: APR_STATUS_IS_ENODIR(s) */
#endif
#ifdef APR_STATUS_IS_ENOENT
  /* Ignoring function-like macro: APR_STATUS_IS_ENOENT(s) */
#endif
#ifdef APR_STATUS_IS_ENOLOCK
  /* Ignoring function-like macro: APR_STATUS_IS_ENOLOCK(s) */
#endif
#ifdef APR_STATUS_IS_ENOMEM
  /* Ignoring function-like macro: APR_STATUS_IS_ENOMEM(s) */
#endif
#ifdef APR_STATUS_IS_ENOPOLL
  /* Ignoring function-like macro: APR_STATUS_IS_ENOPOLL(s) */
#endif
#ifdef APR_STATUS_IS_ENOPOOL
  /* Ignoring function-like macro: APR_STATUS_IS_ENOPOOL(s) */
#endif
#ifdef APR_STATUS_IS_ENOPROC
  /* Ignoring function-like macro: APR_STATUS_IS_ENOPROC(s) */
#endif
#ifdef APR_STATUS_IS_ENOSHMAVAIL
  /* Ignoring function-like macro: APR_STATUS_IS_ENOSHMAVAIL(s) */
#endif
#ifdef APR_STATUS_IS_ENOSOCKET
  /* Ignoring function-like macro: APR_STATUS_IS_ENOSOCKET(s) */
#endif
#ifdef APR_STATUS_IS_ENOSPC
  /* Ignoring function-like macro: APR_STATUS_IS_ENOSPC(s) */
#endif
#ifdef APR_STATUS_IS_ENOSTAT
  /* Ignoring function-like macro: APR_STATUS_IS_ENOSTAT(s) */
#endif
#ifdef APR_STATUS_IS_ENOTDIR
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTDIR(s) */
#endif
#ifdef APR_STATUS_IS_ENOTEMPTY
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTEMPTY(s) */
#endif
#ifdef APR_STATUS_IS_ENOTENOUGHENTROPY
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTENOUGHENTROPY(s) */
#endif
#ifdef APR_STATUS_IS_ENOTHDKEY
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTHDKEY(s) */
#endif
#ifdef APR_STATUS_IS_ENOTHREAD
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTHREAD(s) */
#endif
#ifdef APR_STATUS_IS_ENOTIME
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTIME(s) */
#endif
#ifdef APR_STATUS_IS_ENOTIMPL
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTIMPL(s) */
#endif
#ifdef APR_STATUS_IS_ENOTSOCK
  /* Ignoring function-like macro: APR_STATUS_IS_ENOTSOCK(s) */
#endif
#ifdef APR_STATUS_IS_EOF
  /* Ignoring function-like macro: APR_STATUS_IS_EOF(s) */
#endif
#ifdef APR_STATUS_IS_EPATHWILD
  /* Ignoring function-like macro: APR_STATUS_IS_EPATHWILD(s) */
#endif
#ifdef APR_STATUS_IS_EPIPE
  /* Ignoring function-like macro: APR_STATUS_IS_EPIPE(s) */
#endif
#ifdef APR_STATUS_IS_EPROC_UNKNOWN
  /* Ignoring function-like macro: APR_STATUS_IS_EPROC_UNKNOWN(s) */
#endif
#ifdef APR_STATUS_IS_ERELATIVE
  /* Ignoring function-like macro: APR_STATUS_IS_ERELATIVE(s) */
#endif
#ifdef APR_STATUS_IS_ESPIPE
  /* Ignoring function-like macro: APR_STATUS_IS_ESPIPE(s) */
#endif
#ifdef APR_STATUS_IS_ESYMNOTFOUND
  /* Ignoring function-like macro: APR_STATUS_IS_ESYMNOTFOUND(s) */
#endif
#ifdef APR_STATUS_IS_ETIMEDOUT
  /* Ignoring function-like macro: APR_STATUS_IS_ETIMEDOUT(s) */
#endif
#ifdef APR_STATUS_IS_EXDEV
  /* Ignoring function-like macro: APR_STATUS_IS_EXDEV(s) */
#endif
#ifdef APR_STATUS_IS_FILEBASED
  /* Ignoring function-like macro: APR_STATUS_IS_FILEBASED(s) */
#endif
#ifdef APR_STATUS_IS_INCHILD
  /* Ignoring function-like macro: APR_STATUS_IS_INCHILD(s) */
#endif
#ifdef APR_STATUS_IS_INCOMPLETE
  /* Ignoring function-like macro: APR_STATUS_IS_INCOMPLETE(s) */
#endif
#ifdef APR_STATUS_IS_INPARENT
  /* Ignoring function-like macro: APR_STATUS_IS_INPARENT(s) */
#endif
#ifdef APR_STATUS_IS_KEYBASED
  /* Ignoring function-like macro: APR_STATUS_IS_KEYBASED(s) */
#endif
#ifdef APR_STATUS_IS_NOTDETACH
  /* Ignoring function-like macro: APR_STATUS_IS_NOTDETACH(s) */
#endif
#ifdef APR_STATUS_IS_NOTFOUND
  /* Ignoring function-like macro: APR_STATUS_IS_NOTFOUND(s) */
#endif
#ifdef APR_STATUS_IS_TIMEUP
  /* Ignoring function-like macro: APR_STATUS_IS_TIMEUP(s) */
#endif
#ifdef APR_STATUS_IS_TIMEUP
  /* Ignoring function-like macro: APR_STATUS_IS_TIMEUP(s) */
#endif
#ifdef APR_STRINGIFY
  /* Ignoring function-like macro: APR_STRINGIFY(n) */
#endif
#ifdef APR_STRINGIFY
  /* Ignoring function-like macro: APR_STRINGIFY(n) */
#endif
#ifdef APR_STRINGIFY_HELPER
  /* Ignoring function-like macro: APR_STRINGIFY_HELPER(n) */
#endif
#ifdef APR_STRINGIFY_HELPER
  /* Ignoring function-like macro: APR_STRINGIFY_HELPER(n) */
#endif
#ifdef APR_STRINGS_H
  /* Ignoring macro with no expansion: APR_STRINGS_H */
#endif
#ifdef APR_SUCCESS
  /* APR_SUCCESS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_SUCCESS", mrb_fixnum_value(APR_SUCCESS));
#endif
#ifdef APR_SUPPORT_H
  /* Ignoring macro with no expansion: APR_SUPPORT_H */
#endif
#ifdef APR_TABLES_H
  /* Ignoring macro with no expansion: APR_TABLES_H */
#endif
#ifdef APR_TCP_DEFER_ACCEPT
  /* APR_TCP_DEFER_ACCEPT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_TCP_DEFER_ACCEPT", mrb_fixnum_value(APR_TCP_DEFER_ACCEPT));
#endif
#ifdef APR_TCP_NODELAY
  /* APR_TCP_NODELAY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_TCP_NODELAY", mrb_fixnum_value(APR_TCP_NODELAY));
#endif
#ifdef APR_TCP_NODELAY_INHERITED
  /* APR_TCP_NODELAY_INHERITED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_TCP_NODELAY_INHERITED", mrb_fixnum_value(APR_TCP_NODELAY_INHERITED));
#endif
#ifdef APR_TCP_NOPUSH
  /* APR_TCP_NOPUSH assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_TCP_NOPUSH", mrb_fixnum_value(APR_TCP_NOPUSH));
#endif
#ifdef APR_TCP_NOPUSH_FLAG
  /* Ignoring macro with no expansion: APR_TCP_NOPUSH_FLAG */
#endif
#ifdef APR_THREAD_COND_H
  /* Ignoring macro with no expansion: APR_THREAD_COND_H */
#endif
#ifdef APR_THREAD_FUNC
  /* APR_THREAD_FUNC assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "APR_THREAD_FUNC", mrb_fixnum_value(APR_THREAD_FUNC));
#endif
#ifdef APR_THREAD_MUTEX_DEFAULT
  /* APR_THREAD_MUTEX_DEFAULT assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_THREAD_MUTEX_DEFAULT", mrb_fixnum_value(APR_THREAD_MUTEX_DEFAULT));
#endif
#ifdef APR_THREAD_MUTEX_H
  /* Ignoring macro with no expansion: APR_THREAD_MUTEX_H */
#endif
#ifdef APR_THREAD_MUTEX_NESTED
  /* APR_THREAD_MUTEX_NESTED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_THREAD_MUTEX_NESTED", mrb_fixnum_value(APR_THREAD_MUTEX_NESTED));
#endif
#ifdef APR_THREAD_MUTEX_UNNESTED
  /* APR_THREAD_MUTEX_UNNESTED assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_THREAD_MUTEX_UNNESTED", mrb_fixnum_value(APR_THREAD_MUTEX_UNNESTED));
#endif
#ifdef APR_THREAD_PROC_H
  /* Ignoring macro with no expansion: APR_THREAD_PROC_H */
#endif
#ifdef APR_THREAD_RWLOCK_H
  /* Ignoring macro with no expansion: APR_THREAD_RWLOCK_H */
#endif
#ifdef apr_time_as_msec
  /* Ignoring function-like macro: apr_time_as_msec(time) */
#endif
#ifdef APR_TIME_C
  /* Ignoring function-like macro: APR_TIME_C(val) */
#endif
#ifdef apr_time_from_msec
  /* Ignoring function-like macro: apr_time_from_msec(msec) */
#endif
#ifdef apr_time_from_sec
  /* Ignoring function-like macro: apr_time_from_sec(sec) */
#endif
#ifdef APR_TIME_H
  /* Ignoring macro with no expansion: APR_TIME_H */
#endif
#ifdef apr_time_make
  /* Ignoring function-like macro: apr_time_make(sec, usec) */
#endif
#ifdef apr_time_msec
  /* Ignoring function-like macro: apr_time_msec(time) */
#endif
#ifdef apr_time_sec
  /* Ignoring function-like macro: apr_time_sec(time) */
#endif
#ifdef APR_TIME_T_FMT
  /* APR_TIME_T_FMT assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "APR_TIME_T_FMT", mrb_fixnum_value(APR_TIME_T_FMT));
#endif
#ifdef apr_time_usec
  /* Ignoring function-like macro: apr_time_usec(time) */
#endif
#ifdef APR_TIMEUP
  /* APR_TIMEUP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_TIMEUP", mrb_fixnum_value(APR_TIMEUP));
#endif
#ifdef APR_TO_OS_ERROR
  /* Ignoring function-like macro: APR_TO_OS_ERROR(e) */
#endif
#ifdef apr_tolower
  /* Ignoring function-like macro: apr_tolower(c) */
#endif
#ifdef apr_toupper
  /* Ignoring function-like macro: apr_toupper(c) */
#endif
#ifdef APR_TRUNCATE
  /* APR_TRUNCATE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_TRUNCATE", mrb_fixnum_value(APR_TRUNCATE));
#endif
#ifdef APR_UEXECUTE
  /* APR_UEXECUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UEXECUTE", mrb_fixnum_value(APR_UEXECUTE));
#endif
#ifdef APR_UINT16_MAX
  /* APR_UINT16_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UINT16_MAX", mrb_fixnum_value(APR_UINT16_MAX));
#endif
#ifdef APR_UINT32_MAX
  /* APR_UINT32_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UINT32_MAX", mrb_fixnum_value(APR_UINT32_MAX));
#endif
#ifdef APR_UINT64_C
  /* Ignoring function-like macro: APR_UINT64_C(val) */
#endif
#ifdef APR_UINT64_MAX
  /* APR_UINT64_MAX assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UINT64_MAX", mrb_fixnum_value(APR_UINT64_MAX));
#endif
#ifdef APR_UINT64_T_FMT
  /* APR_UINT64_T_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_UINT64_T_FMT", mrb_str_new_cstr(mrb, APR_UINT64_T_FMT));
#endif
#ifdef APR_UINT64_T_HEX_FMT
  /* APR_UINT64_T_HEX_FMT appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_UINT64_T_HEX_FMT", mrb_str_new_cstr(mrb, APR_UINT64_T_HEX_FMT));
#endif
#ifdef APR_UNSPEC
  /* APR_UNSPEC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UNSPEC", mrb_fixnum_value(APR_UNSPEC));
#endif
#ifdef APR_UREAD
  /* APR_UREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UREAD", mrb_fixnum_value(APR_UREAD));
#endif
#ifdef APR_USE_FCNTL_SERIALIZE
  /* APR_USE_FCNTL_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_FCNTL_SERIALIZE", mrb_fixnum_value(APR_USE_FCNTL_SERIALIZE));
#endif
#ifdef APR_USE_FLOCK_SERIALIZE
  /* APR_USE_FLOCK_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_FLOCK_SERIALIZE", mrb_fixnum_value(APR_USE_FLOCK_SERIALIZE));
#endif
#ifdef APR_USE_POSIXSEM_SERIALIZE
  /* APR_USE_POSIXSEM_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_POSIXSEM_SERIALIZE", mrb_fixnum_value(APR_USE_POSIXSEM_SERIALIZE));
#endif
#ifdef APR_USE_PROC_PTHREAD_SERIALIZE
  /* APR_USE_PROC_PTHREAD_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_PROC_PTHREAD_SERIALIZE", mrb_fixnum_value(APR_USE_PROC_PTHREAD_SERIALIZE));
#endif
#ifdef APR_USE_PTHREAD_SERIALIZE
  /* APR_USE_PTHREAD_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_PTHREAD_SERIALIZE", mrb_fixnum_value(APR_USE_PTHREAD_SERIALIZE));
#endif
#ifdef APR_USE_SHMEM_BEOS
  /* APR_USE_SHMEM_BEOS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_BEOS", mrb_fixnum_value(APR_USE_SHMEM_BEOS));
#endif
#ifdef APR_USE_SHMEM_MMAP_ANON
  /* APR_USE_SHMEM_MMAP_ANON assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_MMAP_ANON", mrb_fixnum_value(APR_USE_SHMEM_MMAP_ANON));
#endif
#ifdef APR_USE_SHMEM_MMAP_SHM
  /* APR_USE_SHMEM_MMAP_SHM assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_MMAP_SHM", mrb_fixnum_value(APR_USE_SHMEM_MMAP_SHM));
#endif
#ifdef APR_USE_SHMEM_MMAP_TMP
  /* APR_USE_SHMEM_MMAP_TMP assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_MMAP_TMP", mrb_fixnum_value(APR_USE_SHMEM_MMAP_TMP));
#endif
#ifdef APR_USE_SHMEM_MMAP_ZERO
  /* APR_USE_SHMEM_MMAP_ZERO assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_MMAP_ZERO", mrb_fixnum_value(APR_USE_SHMEM_MMAP_ZERO));
#endif
#ifdef APR_USE_SHMEM_SHMGET
  /* APR_USE_SHMEM_SHMGET assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_SHMGET", mrb_fixnum_value(APR_USE_SHMEM_SHMGET));
#endif
#ifdef APR_USE_SHMEM_SHMGET_ANON
  /* APR_USE_SHMEM_SHMGET_ANON assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SHMEM_SHMGET_ANON", mrb_fixnum_value(APR_USE_SHMEM_SHMGET_ANON));
#endif
#ifdef APR_USE_SYSVSEM_SERIALIZE
  /* APR_USE_SYSVSEM_SERIALIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USE_SYSVSEM_SERIALIZE", mrb_fixnum_value(APR_USE_SYSVSEM_SERIALIZE));
#endif
#ifdef APR_USEC_PER_SEC
  /* APR_USEC_PER_SEC assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USEC_PER_SEC", mrb_fixnum_value(APR_USEC_PER_SEC));
#endif
#ifdef APR_USER_H
  /* Ignoring macro with no expansion: APR_USER_H */
#endif
#ifdef APR_USETID
  /* APR_USETID assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_USETID", mrb_fixnum_value(APR_USETID));
#endif
#ifdef APR_UTIL_ERRSPACE_SIZE
  /* APR_UTIL_ERRSPACE_SIZE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UTIL_ERRSPACE_SIZE", mrb_fixnum_value(APR_UTIL_ERRSPACE_SIZE));
#endif
#ifdef APR_UTIL_START_STATUS
  /* APR_UTIL_START_STATUS assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UTIL_START_STATUS", mrb_fixnum_value(APR_UTIL_START_STATUS));
#endif
#ifdef APR_UWRITE
  /* APR_UWRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_UWRITE", mrb_fixnum_value(APR_UWRITE));
#endif
#ifdef APR_VERSION_AT_LEAST
  /* Ignoring function-like macro: APR_VERSION_AT_LEAST(major, minor, patch) */
#endif
#ifdef APR_VERSION_H
  /* Ignoring macro with no expansion: APR_VERSION_H */
#endif
#ifdef APR_VERSION_STRING
  /* APR_VERSION_STRING appears to be a string */
  mrb_define_const(mrb, APR_module(mrb), "APR_VERSION_STRING", mrb_str_new_cstr(mrb, APR_VERSION_STRING));
#endif
#ifdef APR_VERSION_STRING_CSV
  /* APR_VERSION_STRING_CSV assumed to be an integer value */
  //mrb_define_const(mrb, APR_module(mrb), "APR_VERSION_STRING_CSV", mrb_fixnum_value(APR_VERSION_STRING_CSV));
#endif
#ifdef APR_WANT_IOVEC
  /* Ignoring macro with no expansion: APR_WANT_IOVEC */
#endif
#ifdef APR_WANT_IOVEC
  /* Ignoring macro with no expansion: APR_WANT_IOVEC */
#endif
#ifdef APR_WANT_MEMFUNC
  /* Ignoring macro with no expansion: APR_WANT_MEMFUNC */
#endif
#ifdef APR_WANT_MEMFUNC
  /* Ignoring macro with no expansion: APR_WANT_MEMFUNC */
#endif
#ifdef APR_WANT_STDIO
  /* Ignoring macro with no expansion: APR_WANT_STDIO */
#endif
#ifdef APR_WEXECUTE
  /* APR_WEXECUTE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_WEXECUTE", mrb_fixnum_value(APR_WEXECUTE));
#endif
#ifdef APR_WREAD
  /* APR_WREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_WREAD", mrb_fixnum_value(APR_WREAD));
#endif
#ifdef APR_WRITE
  /* APR_WRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_WRITE", mrb_fixnum_value(APR_WRITE));
#endif
#ifdef APR_WRITE_BLOCK
  /* APR_WRITE_BLOCK assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_WRITE_BLOCK", mrb_fixnum_value(APR_WRITE_BLOCK));
#endif
#ifdef APR_WSTICKY
  /* APR_WSTICKY assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_WSTICKY", mrb_fixnum_value(APR_WSTICKY));
#endif
#ifdef APR_WWRITE
  /* APR_WWRITE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_WWRITE", mrb_fixnum_value(APR_WWRITE));
#endif
#ifdef APR_XTHREAD
  /* APR_XTHREAD assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APR_XTHREAD", mrb_fixnum_value(APR_XTHREAD));
#endif
#ifdef APRMAXHOSTLEN
  /* APRMAXHOSTLEN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "APRMAXHOSTLEN", mrb_fixnum_value(APRMAXHOSTLEN));
#endif
#ifdef HUGE_STRING_LEN
  /* HUGE_STRING_LEN assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "HUGE_STRING_LEN", mrb_fixnum_value(HUGE_STRING_LEN));
#endif
#ifdef IN6_IS_ADDR_V4MAPPED
  /* Ignoring function-like macro: IN6_IS_ADDR_V4MAPPED(a) */
#endif
#ifdef NOIME
  /* Ignoring macro with no expansion: NOIME */
#endif
#ifdef NOMCX
  /* Ignoring macro with no expansion: NOMCX */
#endif
#ifdef NOUSER
  /* Ignoring macro with no expansion: NOUSER */
#endif
#ifdef STDERR_FILENO
  /* STDERR_FILENO assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "STDERR_FILENO", mrb_fixnum_value(STDERR_FILENO));
#endif
#ifdef STDIN_FILENO
  /* STDIN_FILENO assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "STDIN_FILENO", mrb_fixnum_value(STDIN_FILENO));
#endif
#ifdef STDOUT_FILENO
  /* STDOUT_FILENO assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "STDOUT_FILENO", mrb_fixnum_value(STDOUT_FILENO));
#endif
#ifdef strcasecmp
  /* Ignoring function-like macro: strcasecmp(s1, s2) */
#endif
#ifdef strncasecmp
  /* Ignoring function-like macro: strncasecmp(s1, s2, n) */
#endif
#ifdef SW_HIDE
  /* SW_HIDE assumed to be an integer value */
  mrb_define_const(mrb, APR_module(mrb), "SW_HIDE", mrb_fixnum_value(SW_HIDE));
#endif
#ifdef WIN32_LEAN_AND_MEAN
  /* Ignoring macro with no expansion: WIN32_LEAN_AND_MEAN */
#endif
}
