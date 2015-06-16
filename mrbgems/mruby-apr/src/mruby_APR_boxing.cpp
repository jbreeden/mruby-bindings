/*
 * TODO: Update includes
 */

#include "mruby_APR.h"


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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_allocator_t_class = mrb_define_class_under(mrb, APR_module, "AprAllocatorT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_allocator_t_class, &apr_allocator_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_array_header_t_class = mrb_define_class_under(mrb, APR_module, "AprArrayHeaderT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_array_header_t_class, &apr_array_header_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_crypto_hash_t_class = mrb_define_class_under(mrb, APR_module, "AprCryptoHashT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_crypto_hash_t_class, &apr_crypto_hash_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_dir_t_class = mrb_define_class_under(mrb, APR_module, "AprDirT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_dir_t_class, &apr_dir_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_dso_handle_t_class = mrb_define_class_under(mrb, APR_module, "AprDsoHandleT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_dso_handle_t_class, &apr_dso_handle_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_file_t_class = mrb_define_class_under(mrb, APR_module, "AprFileT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_file_t_class, &apr_file_t_data_type, unboxed));
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
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type apr_finfo_t_data_type = {
   "apr_finfo_t", free_apr_finfo_t
};

mrb_value
mruby_box_apr_finfo_t(mrb_state* mrb, apr_finfo_t *unboxed) {
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_finfo_t_class = mrb_define_class_under(mrb, APR_module, "AprFinfoT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_finfo_t_class, &apr_finfo_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_getopt_option_t_class = mrb_define_class_under(mrb, APR_module, "AprGetoptOptionT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_getopt_option_t_class, &apr_getopt_option_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_getopt_t_class = mrb_define_class_under(mrb, APR_module, "AprGetoptT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_getopt_t_class, &apr_getopt_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_hash_index_t_class = mrb_define_class_under(mrb, APR_module, "AprHashIndexT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_hash_index_t_class, &apr_hash_index_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_hash_t_class = mrb_define_class_under(mrb, APR_module, "AprHashT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_hash_t_class, &apr_hash_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_hdtr_t_class = mrb_define_class_under(mrb, APR_module, "AprHdtrT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_hdtr_t_class, &apr_hdtr_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_ipsubnet_t_class = mrb_define_class_under(mrb, APR_module, "AprIpsubnetT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_ipsubnet_t_class, &apr_ipsubnet_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_memnode_t_class = mrb_define_class_under(mrb, APR_module, "AprMemnodeT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_memnode_t_class, &apr_memnode_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_mmap_t_class = mrb_define_class_under(mrb, APR_module, "AprMmapT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_mmap_t_class, &apr_mmap_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_os_sock_info_t_class = mrb_define_class_under(mrb, APR_module, "AprOsSockInfoT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_os_sock_info_t_class, &apr_os_sock_info_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_other_child_rec_t_class = mrb_define_class_under(mrb, APR_module, "AprOtherChildRecT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_other_child_rec_t_class, &apr_other_child_rec_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_pollcb_t_class = mrb_define_class_under(mrb, APR_module, "AprPollcbT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_pollcb_t_class, &apr_pollcb_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_pollfd_t_class = mrb_define_class_under(mrb, APR_module, "AprPollfdT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_pollfd_t_class, &apr_pollfd_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_pollset_t_class = mrb_define_class_under(mrb, APR_module, "AprPollsetT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_pollset_t_class, &apr_pollset_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_pool_t_class = mrb_define_class_under(mrb, APR_module, "AprPoolT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_pool_t_class, &apr_pool_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_proc_mutex_t_class = mrb_define_class_under(mrb, APR_module, "AprProcMutexT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_proc_mutex_t_class, &apr_proc_mutex_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_proc_t_class = mrb_define_class_under(mrb, APR_module, "AprProcT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_proc_t_class, &apr_proc_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_procattr_t_class = mrb_define_class_under(mrb, APR_module, "AprProcattrT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_procattr_t_class, &apr_procattr_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_random_t_class = mrb_define_class_under(mrb, APR_module, "AprRandomT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_random_t_class, &apr_random_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_shm_t_class = mrb_define_class_under(mrb, APR_module, "AprShmT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_shm_t_class, &apr_shm_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_skiplist_class = mrb_define_class_under(mrb, APR_module, "AprSkiplist", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_skiplist_class, &apr_skiplist_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_skiplistnode_class = mrb_define_class_under(mrb, APR_module, "AprSkiplistnode", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_skiplistnode_class, &apr_skiplistnode_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_sockaddr_t_class = mrb_define_class_under(mrb, APR_module, "AprSockaddrT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_sockaddr_t_class, &apr_sockaddr_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_socket_t_class = mrb_define_class_under(mrb, APR_module, "AprSocketT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_socket_t_class, &apr_socket_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_table_entry_t_class = mrb_define_class_under(mrb, APR_module, "AprTableEntryT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_table_entry_t_class, &apr_table_entry_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_table_t_class = mrb_define_class_under(mrb, APR_module, "AprTableT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_table_t_class, &apr_table_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_thread_cond_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadCondT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_thread_cond_t_class, &apr_thread_cond_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_thread_mutex_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadMutexT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_thread_mutex_t_class, &apr_thread_mutex_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_thread_once_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadOnceT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_thread_once_t_class, &apr_thread_once_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_thread_rwlock_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadRwlockT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_thread_rwlock_t_class, &apr_thread_rwlock_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_thread_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_thread_t_class, &apr_thread_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_threadattr_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadattrT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_threadattr_t_class, &apr_threadattr_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_threadkey_t_class = mrb_define_class_under(mrb, APR_module, "AprThreadkeyT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_threadkey_t_class, &apr_threadkey_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_time_exp_t_class = mrb_define_class_under(mrb, APR_module, "AprTimeExpT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_time_exp_t_class, &apr_time_exp_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_version_t_class = mrb_define_class_under(mrb, APR_module, "AprVersionT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_version_t_class, &apr_version_t_data_type, unboxed));
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
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* apr_vformatter_buff_t_class = mrb_define_class_under(mrb, APR_module, "AprVformatterBuffT", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, apr_vformatter_buff_t_class, &apr_vformatter_buff_t_data_type, unboxed));
}

apr_vformatter_buff_t *
mruby_unbox_apr_vformatter_buff_t(mrb_value boxed) {
  return (apr_vformatter_buff_t *)DATA_PTR(boxed);
}
#endif

#if BIND_InAddr_TYPE
/*
 * Boxing implementation for in_addr
 */

static void free_in_addr(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type in_addr_data_type = {
   "in_addr", free_in_addr
};

mrb_value
mruby_box_in_addr(mrb_state* mrb, in_addr *unboxed) {
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* in_addr_class = mrb_define_class_under(mrb, APR_module, "InAddr", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, in_addr_class, &in_addr_data_type, unboxed));
}

in_addr *
mruby_unbox_in_addr(mrb_value boxed) {
  return (in_addr *)DATA_PTR(boxed);
}
#endif

#if BIND_Sockaddr_TYPE
/*
 * Boxing implementation for sockaddr
 */

static void free_sockaddr(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type sockaddr_data_type = {
   "sockaddr", free_sockaddr
};

mrb_value
mruby_box_sockaddr(mrb_state* mrb, sockaddr *unboxed) {
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* sockaddr_class = mrb_define_class_under(mrb, APR_module, "Sockaddr", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, sockaddr_class, &sockaddr_data_type, unboxed));
}

sockaddr *
mruby_unbox_sockaddr(mrb_value boxed) {
  return (sockaddr *)DATA_PTR(boxed);
}
#endif

#if BIND_SockaddrIn_TYPE
/*
 * Boxing implementation for sockaddr_in
 */

static void free_sockaddr_in(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type sockaddr_in_data_type = {
   "sockaddr_in", free_sockaddr_in
};

mrb_value
mruby_box_sockaddr_in(mrb_state* mrb, sockaddr_in *unboxed) {
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* sockaddr_in_class = mrb_define_class_under(mrb, APR_module, "SockaddrIn", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, sockaddr_in_class, &sockaddr_in_data_type, unboxed));
}

sockaddr_in *
mruby_unbox_sockaddr_in(mrb_value boxed) {
  return (sockaddr_in *)DATA_PTR(boxed);
}
#endif

#if BIND_SockaddrIn6_TYPE
/*
 * Boxing implementation for sockaddr_in6
 */

static void free_sockaddr_in6(mrb_state* mrb, void* ptr) {
  /*
   * TODO:
   * If you'd like to participate in Ruby's garbage collection,
   * you'll need to fill in this function body
   */
}

static const mrb_data_type sockaddr_in6_data_type = {
   "sockaddr_in6", free_sockaddr_in6
};

mrb_value
mruby_box_sockaddr_in6(mrb_state* mrb, sockaddr_in6 *unboxed) {
  RClass* APR_module = mrb_define_module(mrb, "APR");
  RClass* sockaddr_in6_class = mrb_define_class_under(mrb, APR_module, "SockaddrIn6", mrb->object_class);

  return mrb_obj_value(Data_Wrap_Struct(mrb, sockaddr_in6_class, &sockaddr_in6_data_type, unboxed));
}

sockaddr_in6 *
mruby_unbox_sockaddr_in6(mrb_value boxed) {
  return (sockaddr_in6 *)DATA_PTR(boxed);
}
#endif

