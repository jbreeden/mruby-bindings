/*
 * TODO: Update includes
 */

#include "mruby_APR.h"


static void free_apr_time_t(mrb_state* mrb, void* ptr) {
   /* These are really just int64's, not shared by pointers. Just free it... */
   if (ptr != NULL) free(ptr);
}

static const mrb_data_type apr_time_t_data_type = {
   "apr_time_t", free_apr_time_t
};

mrb_value
mruby_box_apr_time_t(mrb_state* mrb, apr_time_t *unboxed) {
   apr_time_t* boxed = (apr_time_t*)malloc(sizeof(apr_time_t));
   memcpy(boxed, unboxed, sizeof(apr_time_t));
   return mrb_obj_value(Data_Wrap_Struct(mrb, AprTimeT_class(mrb), &apr_time_t_data_type, boxed));
}

apr_time_t *
mruby_unbox_apr_time_t(mrb_value boxed) {
   return (apr_time_t*)DATA_PTR(boxed);
}

#if BIND_AprAllocatorT_TYPE
/*
 * Boxing implementation for apr_allocator_t
 */

static void free_apr_allocator_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_allocator_t_data_type = {
   "apr_allocator_t", free_apr_allocator_t
};

mrb_value
mruby_box_apr_allocator_t(mrb_state* mrb, apr_allocator_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprAllocatorT_class(mrb), &apr_allocator_t_data_type, unboxed));
}

void
mruby_set_apr_allocator_t_data_ptr(mrb_value obj, apr_allocator_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_allocator_t_data_type);
}

apr_allocator_t *
mruby_unbox_apr_allocator_t(mrb_value boxed) {
  return (apr_allocator_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprArrayHeaderT_TYPE
/*
 * Boxing implementation for apr_array_header_t
 */

static void free_apr_array_header_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_array_header_t_data_type = {
   "apr_array_header_t", free_apr_array_header_t
};

mrb_value
mruby_box_apr_array_header_t(mrb_state* mrb, apr_array_header_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprArrayHeaderT_class(mrb), &apr_array_header_t_data_type, unboxed));
}

void
mruby_set_apr_array_header_t_data_ptr(mrb_value obj, apr_array_header_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_array_header_t_data_type);
}

apr_array_header_t *
mruby_unbox_apr_array_header_t(mrb_value boxed) {
  return (apr_array_header_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprCryptoHashT_TYPE
/*
 * Boxing implementation for apr_crypto_hash_t
 */

static void free_apr_crypto_hash_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_crypto_hash_t_data_type = {
   "apr_crypto_hash_t", free_apr_crypto_hash_t
};

mrb_value
mruby_box_apr_crypto_hash_t(mrb_state* mrb, apr_crypto_hash_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprCryptoHashT_class(mrb), &apr_crypto_hash_t_data_type, unboxed));
}

void
mruby_set_apr_crypto_hash_t_data_ptr(mrb_value obj, apr_crypto_hash_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_crypto_hash_t_data_type);
}

apr_crypto_hash_t *
mruby_unbox_apr_crypto_hash_t(mrb_value boxed) {
  return (apr_crypto_hash_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprDirT_TYPE
/*
 * Boxing implementation for apr_dir_t
 */

static void free_apr_dir_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_dir_t_data_type = {
   "apr_dir_t", free_apr_dir_t
};

mrb_value
mruby_box_apr_dir_t(mrb_state* mrb, apr_dir_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprDirT_class(mrb), &apr_dir_t_data_type, unboxed));
}

void
mruby_set_apr_dir_t_data_ptr(mrb_value obj, apr_dir_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_dir_t_data_type);
}

apr_dir_t *
mruby_unbox_apr_dir_t(mrb_value boxed) {
  return (apr_dir_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprDsoHandleT_TYPE
/*
 * Boxing implementation for apr_dso_handle_t
 */

static void free_apr_dso_handle_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_dso_handle_t_data_type = {
   "apr_dso_handle_t", free_apr_dso_handle_t
};

mrb_value
mruby_box_apr_dso_handle_t(mrb_state* mrb, apr_dso_handle_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprDsoHandleT_class(mrb), &apr_dso_handle_t_data_type, unboxed));
}

void
mruby_set_apr_dso_handle_t_data_ptr(mrb_value obj, apr_dso_handle_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_dso_handle_t_data_type);
}

apr_dso_handle_t *
mruby_unbox_apr_dso_handle_t(mrb_value boxed) {
  return (apr_dso_handle_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprFileT_TYPE
/*
 * Boxing implementation for apr_file_t
 */

static void free_apr_file_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_file_t_data_type = {
   "apr_file_t", free_apr_file_t
};

mrb_value
mruby_box_apr_file_t(mrb_state* mrb, apr_file_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprFileT_class(mrb), &apr_file_t_data_type, unboxed));
}

void
mruby_set_apr_file_t_data_ptr(mrb_value obj, apr_file_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_file_t_data_type);
}

apr_file_t *
mruby_unbox_apr_file_t(mrb_value boxed) {
  return (apr_file_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprFinfoT_TYPE
/*
 * Boxing implementation for apr_finfo_t
 */

static void free_apr_finfo_t(mrb_state* mrb, void* ptr) {
   if (ptr != NULL) free(ptr);
}

static const mrb_data_type apr_finfo_t_data_type = {
   "apr_finfo_t", free_apr_finfo_t
};

mrb_value
mruby_box_apr_finfo_t(mrb_state* mrb, apr_finfo_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprFinfoT_class(mrb), &apr_finfo_t_data_type, unboxed));
}

void
mruby_set_apr_finfo_t_data_ptr(mrb_value obj, apr_finfo_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_finfo_t_data_type);
}

apr_finfo_t *
mruby_unbox_apr_finfo_t(mrb_value boxed) {
  return (apr_finfo_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprGetoptOptionT_TYPE
/*
 * Boxing implementation for apr_getopt_option_t
 */

static void free_apr_getopt_option_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_getopt_option_t_data_type = {
   "apr_getopt_option_t", free_apr_getopt_option_t
};

mrb_value
mruby_box_apr_getopt_option_t(mrb_state* mrb, apr_getopt_option_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprGetoptOptionT_class(mrb), &apr_getopt_option_t_data_type, unboxed));
}

void
mruby_set_apr_getopt_option_t_data_ptr(mrb_value obj, apr_getopt_option_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_getopt_option_t_data_type);
}

apr_getopt_option_t *
mruby_unbox_apr_getopt_option_t(mrb_value boxed) {
  return (apr_getopt_option_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprGetoptT_TYPE
/*
 * Boxing implementation for apr_getopt_t
 */

static void free_apr_getopt_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_getopt_t_data_type = {
   "apr_getopt_t", free_apr_getopt_t
};

mrb_value
mruby_box_apr_getopt_t(mrb_state* mrb, apr_getopt_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprGetoptT_class(mrb), &apr_getopt_t_data_type, unboxed));
}

void
mruby_set_apr_getopt_t_data_ptr(mrb_value obj, apr_getopt_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_getopt_t_data_type);
}

apr_getopt_t *
mruby_unbox_apr_getopt_t(mrb_value boxed) {
  return (apr_getopt_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprHashIndexT_TYPE
/*
 * Boxing implementation for apr_hash_index_t
 */

static void free_apr_hash_index_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_hash_index_t_data_type = {
   "apr_hash_index_t", free_apr_hash_index_t
};

mrb_value
mruby_box_apr_hash_index_t(mrb_state* mrb, apr_hash_index_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprHashIndexT_class(mrb), &apr_hash_index_t_data_type, unboxed));
}

void
mruby_set_apr_hash_index_t_data_ptr(mrb_value obj, apr_hash_index_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_hash_index_t_data_type);
}

apr_hash_index_t *
mruby_unbox_apr_hash_index_t(mrb_value boxed) {
  return (apr_hash_index_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprHashT_TYPE
/*
 * Boxing implementation for apr_hash_t
 */

static void free_apr_hash_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_hash_t_data_type = {
   "apr_hash_t", free_apr_hash_t
};

mrb_value
mruby_box_apr_hash_t(mrb_state* mrb, apr_hash_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprHashT_class(mrb), &apr_hash_t_data_type, unboxed));
}

void
mruby_set_apr_hash_t_data_ptr(mrb_value obj, apr_hash_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_hash_t_data_type);
}

apr_hash_t *
mruby_unbox_apr_hash_t(mrb_value boxed) {
  return (apr_hash_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprHdtrT_TYPE
/*
 * Boxing implementation for apr_hdtr_t
 */

static void free_apr_hdtr_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_hdtr_t_data_type = {
   "apr_hdtr_t", free_apr_hdtr_t
};

mrb_value
mruby_box_apr_hdtr_t(mrb_state* mrb, apr_hdtr_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprHdtrT_class(mrb), &apr_hdtr_t_data_type, unboxed));
}

void
mruby_set_apr_hdtr_t_data_ptr(mrb_value obj, apr_hdtr_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_hdtr_t_data_type);
}

apr_hdtr_t *
mruby_unbox_apr_hdtr_t(mrb_value boxed) {
  return (apr_hdtr_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprIpsubnetT_TYPE
/*
 * Boxing implementation for apr_ipsubnet_t
 */

static void free_apr_ipsubnet_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_ipsubnet_t_data_type = {
   "apr_ipsubnet_t", free_apr_ipsubnet_t
};

mrb_value
mruby_box_apr_ipsubnet_t(mrb_state* mrb, apr_ipsubnet_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprIpsubnetT_class(mrb), &apr_ipsubnet_t_data_type, unboxed));
}

void
mruby_set_apr_ipsubnet_t_data_ptr(mrb_value obj, apr_ipsubnet_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_ipsubnet_t_data_type);
}

apr_ipsubnet_t *
mruby_unbox_apr_ipsubnet_t(mrb_value boxed) {
  return (apr_ipsubnet_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprMemnodeT_TYPE
/*
 * Boxing implementation for apr_memnode_t
 */

static void free_apr_memnode_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_memnode_t_data_type = {
   "apr_memnode_t", free_apr_memnode_t
};

mrb_value
mruby_box_apr_memnode_t(mrb_state* mrb, apr_memnode_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprMemnodeT_class(mrb), &apr_memnode_t_data_type, unboxed));
}

void
mruby_set_apr_memnode_t_data_ptr(mrb_value obj, apr_memnode_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_memnode_t_data_type);
}

apr_memnode_t *
mruby_unbox_apr_memnode_t(mrb_value boxed) {
  return (apr_memnode_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprMmapT_TYPE
/*
 * Boxing implementation for apr_mmap_t
 */

static void free_apr_mmap_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_mmap_t_data_type = {
   "apr_mmap_t", free_apr_mmap_t
};

mrb_value
mruby_box_apr_mmap_t(mrb_state* mrb, apr_mmap_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprMmapT_class(mrb), &apr_mmap_t_data_type, unboxed));
}

void
mruby_set_apr_mmap_t_data_ptr(mrb_value obj, apr_mmap_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_mmap_t_data_type);
}

apr_mmap_t *
mruby_unbox_apr_mmap_t(mrb_value boxed) {
  return (apr_mmap_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprOsSockInfoT_TYPE
/*
 * Boxing implementation for apr_os_sock_info_t
 */

static void free_apr_os_sock_info_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_os_sock_info_t_data_type = {
   "apr_os_sock_info_t", free_apr_os_sock_info_t
};

mrb_value
mruby_box_apr_os_sock_info_t(mrb_state* mrb, apr_os_sock_info_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprOsSockInfoT_class(mrb), &apr_os_sock_info_t_data_type, unboxed));
}

void
mruby_set_apr_os_sock_info_t_data_ptr(mrb_value obj, apr_os_sock_info_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_os_sock_info_t_data_type);
}

apr_os_sock_info_t *
mruby_unbox_apr_os_sock_info_t(mrb_value boxed) {
  return (apr_os_sock_info_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprOtherChildRecT_TYPE
/*
 * Boxing implementation for apr_other_child_rec_t
 */

static void free_apr_other_child_rec_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_other_child_rec_t_data_type = {
   "apr_other_child_rec_t", free_apr_other_child_rec_t
};

mrb_value
mruby_box_apr_other_child_rec_t(mrb_state* mrb, apr_other_child_rec_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprOtherChildRecT_class(mrb), &apr_other_child_rec_t_data_type, unboxed));
}

void
mruby_set_apr_other_child_rec_t_data_ptr(mrb_value obj, apr_other_child_rec_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_other_child_rec_t_data_type);
}

apr_other_child_rec_t *
mruby_unbox_apr_other_child_rec_t(mrb_value boxed) {
  return (apr_other_child_rec_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprPollcbT_TYPE
/*
 * Boxing implementation for apr_pollcb_t
 */

static void free_apr_pollcb_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_pollcb_t_data_type = {
   "apr_pollcb_t", free_apr_pollcb_t
};

mrb_value
mruby_box_apr_pollcb_t(mrb_state* mrb, apr_pollcb_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprPollcbT_class(mrb), &apr_pollcb_t_data_type, unboxed));
}

void
mruby_set_apr_pollcb_t_data_ptr(mrb_value obj, apr_pollcb_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_pollcb_t_data_type);
}

apr_pollcb_t *
mruby_unbox_apr_pollcb_t(mrb_value boxed) {
  return (apr_pollcb_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprPollfdT_TYPE
/*
 * Boxing implementation for apr_pollfd_t
 */

static void free_apr_pollfd_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_pollfd_t_data_type = {
   "apr_pollfd_t", free_apr_pollfd_t
};

mrb_value
mruby_box_apr_pollfd_t(mrb_state* mrb, apr_pollfd_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprPollfdT_class(mrb), &apr_pollfd_t_data_type, unboxed));
}

void
mruby_set_apr_pollfd_t_data_ptr(mrb_value obj, apr_pollfd_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_pollfd_t_data_type);
}

apr_pollfd_t *
mruby_unbox_apr_pollfd_t(mrb_value boxed) {
  return (apr_pollfd_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprPollsetT_TYPE
/*
 * Boxing implementation for apr_pollset_t
 */

static void free_apr_pollset_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_pollset_t_data_type = {
   "apr_pollset_t", free_apr_pollset_t
};

mrb_value
mruby_box_apr_pollset_t(mrb_state* mrb, apr_pollset_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprPollsetT_class(mrb), &apr_pollset_t_data_type, unboxed));
}

void
mruby_set_apr_pollset_t_data_ptr(mrb_value obj, apr_pollset_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_pollset_t_data_type);
}

apr_pollset_t *
mruby_unbox_apr_pollset_t(mrb_value boxed) {
  return (apr_pollset_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprPoolT_TYPE
/*
 * Boxing implementation for apr_pool_t
 */

static void free_apr_pool_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_pool_t_data_type = {
   "apr_pool_t", free_apr_pool_t
};

mrb_value
mruby_box_apr_pool_t(mrb_state* mrb, apr_pool_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprPoolT_class(mrb), &apr_pool_t_data_type, unboxed));
}

void
mruby_set_apr_pool_t_data_ptr(mrb_value obj, apr_pool_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_pool_t_data_type);
}

apr_pool_t *
mruby_unbox_apr_pool_t(mrb_value boxed) {
  return (apr_pool_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprProcMutexT_TYPE
/*
 * Boxing implementation for apr_proc_mutex_t
 */

static void free_apr_proc_mutex_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_proc_mutex_t_data_type = {
   "apr_proc_mutex_t", free_apr_proc_mutex_t
};

mrb_value
mruby_box_apr_proc_mutex_t(mrb_state* mrb, apr_proc_mutex_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprProcMutexT_class(mrb), &apr_proc_mutex_t_data_type, unboxed));
}

void
mruby_set_apr_proc_mutex_t_data_ptr(mrb_value obj, apr_proc_mutex_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_proc_mutex_t_data_type);
}

apr_proc_mutex_t *
mruby_unbox_apr_proc_mutex_t(mrb_value boxed) {
  return (apr_proc_mutex_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprProcT_TYPE
/*
 * Boxing implementation for apr_proc_t
 */

static void free_apr_proc_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_proc_t_data_type = {
   "apr_proc_t", free_apr_proc_t
};

mrb_value
mruby_box_apr_proc_t(mrb_state* mrb, apr_proc_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprProcT_class(mrb), &apr_proc_t_data_type, unboxed));
}

void
mruby_set_apr_proc_t_data_ptr(mrb_value obj, apr_proc_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_proc_t_data_type);
}

apr_proc_t *
mruby_unbox_apr_proc_t(mrb_value boxed) {
  return (apr_proc_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprProcattrT_TYPE
/*
 * Boxing implementation for apr_procattr_t
 */

static void free_apr_procattr_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_procattr_t_data_type = {
   "apr_procattr_t", free_apr_procattr_t
};

mrb_value
mruby_box_apr_procattr_t(mrb_state* mrb, apr_procattr_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprProcattrT_class(mrb), &apr_procattr_t_data_type, unboxed));
}

void
mruby_set_apr_procattr_t_data_ptr(mrb_value obj, apr_procattr_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_procattr_t_data_type);
}

apr_procattr_t *
mruby_unbox_apr_procattr_t(mrb_value boxed) {
  return (apr_procattr_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprRandomT_TYPE
/*
 * Boxing implementation for apr_random_t
 */

static void free_apr_random_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_random_t_data_type = {
   "apr_random_t", free_apr_random_t
};

mrb_value
mruby_box_apr_random_t(mrb_state* mrb, apr_random_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprRandomT_class(mrb), &apr_random_t_data_type, unboxed));
}

void
mruby_set_apr_random_t_data_ptr(mrb_value obj, apr_random_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_random_t_data_type);
}

apr_random_t *
mruby_unbox_apr_random_t(mrb_value boxed) {
  return (apr_random_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprShmT_TYPE
/*
 * Boxing implementation for apr_shm_t
 */

static void free_apr_shm_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_shm_t_data_type = {
   "apr_shm_t", free_apr_shm_t
};

mrb_value
mruby_box_apr_shm_t(mrb_state* mrb, apr_shm_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprShmT_class(mrb), &apr_shm_t_data_type, unboxed));
}

void
mruby_set_apr_shm_t_data_ptr(mrb_value obj, apr_shm_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_shm_t_data_type);
}

apr_shm_t *
mruby_unbox_apr_shm_t(mrb_value boxed) {
  return (apr_shm_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprSkiplist_TYPE
/*
 * Boxing implementation for apr_skiplist
 */

static void free_apr_skiplist(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_skiplist_data_type = {
   "apr_skiplist", free_apr_skiplist
};

mrb_value
mruby_box_apr_skiplist(mrb_state* mrb, apr_skiplist *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprSkiplist_class(mrb), &apr_skiplist_data_type, unboxed));
}

void
mruby_set_apr_skiplist_data_ptr(mrb_value obj, apr_skiplist *unboxed) {
  mrb_data_init(obj, unboxed, &apr_skiplist_data_type);
}

apr_skiplist *
mruby_unbox_apr_skiplist(mrb_value boxed) {
  return (apr_skiplist *)DATA_PTR(boxed);
}
#endif

#if BIND_AprSkiplistnode_TYPE
/*
 * Boxing implementation for apr_skiplistnode
 */

static void free_apr_skiplistnode(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_skiplistnode_data_type = {
   "apr_skiplistnode", free_apr_skiplistnode
};

mrb_value
mruby_box_apr_skiplistnode(mrb_state* mrb, apr_skiplistnode *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprSkiplistnode_class(mrb), &apr_skiplistnode_data_type, unboxed));
}

void
mruby_set_apr_skiplistnode_data_ptr(mrb_value obj, apr_skiplistnode *unboxed) {
  mrb_data_init(obj, unboxed, &apr_skiplistnode_data_type);
}

apr_skiplistnode *
mruby_unbox_apr_skiplistnode(mrb_value boxed) {
  return (apr_skiplistnode *)DATA_PTR(boxed);
}
#endif

#if BIND_AprSockaddrT_TYPE
/*
 * Boxing implementation for apr_sockaddr_t
 */

static void free_apr_sockaddr_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_sockaddr_t_data_type = {
   "apr_sockaddr_t", free_apr_sockaddr_t
};

mrb_value
mruby_box_apr_sockaddr_t(mrb_state* mrb, apr_sockaddr_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprSockaddrT_class(mrb), &apr_sockaddr_t_data_type, unboxed));
}

void
mruby_set_apr_sockaddr_t_data_ptr(mrb_value obj, apr_sockaddr_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_sockaddr_t_data_type);
}

apr_sockaddr_t *
mruby_unbox_apr_sockaddr_t(mrb_value boxed) {
  return (apr_sockaddr_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprSocketT_TYPE
/*
 * Boxing implementation for apr_socket_t
 */

static void free_apr_socket_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_socket_t_data_type = {
   "apr_socket_t", free_apr_socket_t
};

mrb_value
mruby_box_apr_socket_t(mrb_state* mrb, apr_socket_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprSocketT_class(mrb), &apr_socket_t_data_type, unboxed));
}

void
mruby_set_apr_socket_t_data_ptr(mrb_value obj, apr_socket_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_socket_t_data_type);
}

apr_socket_t *
mruby_unbox_apr_socket_t(mrb_value boxed) {
  return (apr_socket_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprTableEntryT_TYPE
/*
 * Boxing implementation for apr_table_entry_t
 */

static void free_apr_table_entry_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_table_entry_t_data_type = {
   "apr_table_entry_t", free_apr_table_entry_t
};

mrb_value
mruby_box_apr_table_entry_t(mrb_state* mrb, apr_table_entry_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprTableEntryT_class(mrb), &apr_table_entry_t_data_type, unboxed));
}

void
mruby_set_apr_table_entry_t_data_ptr(mrb_value obj, apr_table_entry_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_table_entry_t_data_type);
}

apr_table_entry_t *
mruby_unbox_apr_table_entry_t(mrb_value boxed) {
  return (apr_table_entry_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprTableT_TYPE
/*
 * Boxing implementation for apr_table_t
 */

static void free_apr_table_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_table_t_data_type = {
   "apr_table_t", free_apr_table_t
};

mrb_value
mruby_box_apr_table_t(mrb_state* mrb, apr_table_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprTableT_class(mrb), &apr_table_t_data_type, unboxed));
}

void
mruby_set_apr_table_t_data_ptr(mrb_value obj, apr_table_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_table_t_data_type);
}

apr_table_t *
mruby_unbox_apr_table_t(mrb_value boxed) {
  return (apr_table_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadCondT_TYPE
/*
 * Boxing implementation for apr_thread_cond_t
 */

static void free_apr_thread_cond_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_thread_cond_t_data_type = {
   "apr_thread_cond_t", free_apr_thread_cond_t
};

mrb_value
mruby_box_apr_thread_cond_t(mrb_state* mrb, apr_thread_cond_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadCondT_class(mrb), &apr_thread_cond_t_data_type, unboxed));
}

void
mruby_set_apr_thread_cond_t_data_ptr(mrb_value obj, apr_thread_cond_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_thread_cond_t_data_type);
}

apr_thread_cond_t *
mruby_unbox_apr_thread_cond_t(mrb_value boxed) {
  return (apr_thread_cond_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadMutexT_TYPE
/*
 * Boxing implementation for apr_thread_mutex_t
 */

static void free_apr_thread_mutex_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_thread_mutex_t_data_type = {
   "apr_thread_mutex_t", free_apr_thread_mutex_t
};

mrb_value
mruby_box_apr_thread_mutex_t(mrb_state* mrb, apr_thread_mutex_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadMutexT_class(mrb), &apr_thread_mutex_t_data_type, unboxed));
}

void
mruby_set_apr_thread_mutex_t_data_ptr(mrb_value obj, apr_thread_mutex_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_thread_mutex_t_data_type);
}

apr_thread_mutex_t *
mruby_unbox_apr_thread_mutex_t(mrb_value boxed) {
  return (apr_thread_mutex_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadOnceT_TYPE
/*
 * Boxing implementation for apr_thread_once_t
 */

static void free_apr_thread_once_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_thread_once_t_data_type = {
   "apr_thread_once_t", free_apr_thread_once_t
};

mrb_value
mruby_box_apr_thread_once_t(mrb_state* mrb, apr_thread_once_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadOnceT_class(mrb), &apr_thread_once_t_data_type, unboxed));
}

void
mruby_set_apr_thread_once_t_data_ptr(mrb_value obj, apr_thread_once_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_thread_once_t_data_type);
}

apr_thread_once_t *
mruby_unbox_apr_thread_once_t(mrb_value boxed) {
  return (apr_thread_once_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadRwlockT_TYPE
/*
 * Boxing implementation for apr_thread_rwlock_t
 */

static void free_apr_thread_rwlock_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_thread_rwlock_t_data_type = {
   "apr_thread_rwlock_t", free_apr_thread_rwlock_t
};

mrb_value
mruby_box_apr_thread_rwlock_t(mrb_state* mrb, apr_thread_rwlock_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadRwlockT_class(mrb), &apr_thread_rwlock_t_data_type, unboxed));
}

void
mruby_set_apr_thread_rwlock_t_data_ptr(mrb_value obj, apr_thread_rwlock_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_thread_rwlock_t_data_type);
}

apr_thread_rwlock_t *
mruby_unbox_apr_thread_rwlock_t(mrb_value boxed) {
  return (apr_thread_rwlock_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadT_TYPE
/*
 * Boxing implementation for apr_thread_t
 */

static void free_apr_thread_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_thread_t_data_type = {
   "apr_thread_t", free_apr_thread_t
};

mrb_value
mruby_box_apr_thread_t(mrb_state* mrb, apr_thread_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadT_class(mrb), &apr_thread_t_data_type, unboxed));
}

void
mruby_set_apr_thread_t_data_ptr(mrb_value obj, apr_thread_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_thread_t_data_type);
}

apr_thread_t *
mruby_unbox_apr_thread_t(mrb_value boxed) {
  return (apr_thread_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadattrT_TYPE
/*
 * Boxing implementation for apr_threadattr_t
 */

static void free_apr_threadattr_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_threadattr_t_data_type = {
   "apr_threadattr_t", free_apr_threadattr_t
};

mrb_value
mruby_box_apr_threadattr_t(mrb_state* mrb, apr_threadattr_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadattrT_class(mrb), &apr_threadattr_t_data_type, unboxed));
}

void
mruby_set_apr_threadattr_t_data_ptr(mrb_value obj, apr_threadattr_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_threadattr_t_data_type);
}

apr_threadattr_t *
mruby_unbox_apr_threadattr_t(mrb_value boxed) {
  return (apr_threadattr_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprThreadkeyT_TYPE
/*
 * Boxing implementation for apr_threadkey_t
 */

static void free_apr_threadkey_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_threadkey_t_data_type = {
   "apr_threadkey_t", free_apr_threadkey_t
};

mrb_value
mruby_box_apr_threadkey_t(mrb_state* mrb, apr_threadkey_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprThreadkeyT_class(mrb), &apr_threadkey_t_data_type, unboxed));
}

void
mruby_set_apr_threadkey_t_data_ptr(mrb_value obj, apr_threadkey_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_threadkey_t_data_type);
}

apr_threadkey_t *
mruby_unbox_apr_threadkey_t(mrb_value boxed) {
  return (apr_threadkey_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprTimeExpT_TYPE
/*
 * Boxing implementation for apr_time_exp_t
 */

static void free_apr_time_exp_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_time_exp_t_data_type = {
   "apr_time_exp_t", free_apr_time_exp_t
};

mrb_value
mruby_box_apr_time_exp_t(mrb_state* mrb, apr_time_exp_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprTimeExpT_class(mrb), &apr_time_exp_t_data_type, unboxed));
}

void
mruby_set_apr_time_exp_t_data_ptr(mrb_value obj, apr_time_exp_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_time_exp_t_data_type);
}

apr_time_exp_t *
mruby_unbox_apr_time_exp_t(mrb_value boxed) {
  return (apr_time_exp_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprVersionT_TYPE
/*
 * Boxing implementation for apr_version_t
 */

static void free_apr_version_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_version_t_data_type = {
   "apr_version_t", free_apr_version_t
};

mrb_value
mruby_box_apr_version_t(mrb_state* mrb, apr_version_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprVersionT_class(mrb), &apr_version_t_data_type, unboxed));
}

void
mruby_set_apr_version_t_data_ptr(mrb_value obj, apr_version_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_version_t_data_type);
}

apr_version_t *
mruby_unbox_apr_version_t(mrb_value boxed) {
  return (apr_version_t *)DATA_PTR(boxed);
}
#endif

#if BIND_AprVformatterBuffT_TYPE
/*
 * Boxing implementation for apr_vformatter_buff_t
 */

static void free_apr_vformatter_buff_t(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_vformatter_buff_t_data_type = {
   "apr_vformatter_buff_t", free_apr_vformatter_buff_t
};

mrb_value
mruby_box_apr_vformatter_buff_t(mrb_state* mrb, apr_vformatter_buff_t *unboxed) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, AprVformatterBuffT_class(mrb), &apr_vformatter_buff_t_data_type, unboxed));
}

void
mruby_set_apr_vformatter_buff_t_data_ptr(mrb_value obj, apr_vformatter_buff_t *unboxed) {
  mrb_data_init(obj, unboxed, &apr_vformatter_buff_t_data_type);
}

apr_vformatter_buff_t *
mruby_unbox_apr_vformatter_buff_t(mrb_value boxed) {
  return (apr_vformatter_buff_t *)DATA_PTR(boxed);
}
#endif

