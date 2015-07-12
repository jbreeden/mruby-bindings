
#ifndef APR_HEADER
#define APR_HEADER

/*
 * RClass Macros
 * -------------
 *
 * Macros for retrieving the RClass*'s defined by this gem.
 */

#define APR_module(mrb) mrb_module_get(mrb, "APR")
#define AprTimeT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprTimeT")
#define AprAllocatorT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprAllocatorT")
#define AprArrayHeaderT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprArrayHeaderT")
#define AprCryptoHashT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprCryptoHashT")
#define AprDirT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprDirT")
#define AprDsoHandleT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprDsoHandleT")
#define AprFileT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprFileT")
#define AprFinfoT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprFinfoT")
#define AprGetoptOptionT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprGetoptOptionT")
#define AprGetoptT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprGetoptT")
#define AprHashIndexT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprHashIndexT")
#define AprHashT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprHashT")
#define AprHdtrT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprHdtrT")
#define AprIpsubnetT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprIpsubnetT")
#define AprMemnodeT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprMemnodeT")
#define AprMmapT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprMmapT")
#define AprOsSockInfoT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprOsSockInfoT")
#define AprOtherChildRecT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprOtherChildRecT")
#define AprPollcbT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprPollcbT")
#define AprPollfdT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprPollfdT")
#define AprPollsetT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprPollsetT")
#define AprPoolT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprPoolT")
#define AprProcMutexT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprProcMutexT")
#define AprProcT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprProcT")
#define AprProcattrT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprProcattrT")
#define AprRandomT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprRandomT")
#define AprShmT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprShmT")
#define AprSkiplist_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprSkiplist")
#define AprSkiplistnode_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprSkiplistnode")
#define AprSockaddrT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprSockaddrT")
#define AprSocketT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprSocketT")
#define AprTableEntryT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprTableEntryT")
#define AprTableT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprTableT")
#define AprThreadCondT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadCondT")
#define AprThreadMutexT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadMutexT")
#define AprThreadOnceT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadOnceT")
#define AprThreadRwlockT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadRwlockT")
#define AprThreadT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadT")
#define AprThreadattrT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadattrT")
#define AprThreadkeyT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprThreadkeyT")
#define AprTimeExpT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprTimeExpT")
#define AprVersionT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprVersionT")
#define AprVformatterBuffT_class(mrb) mrb_class_get_under(mrb, APR_module(mrb), "AprVformatterBuffT")

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

#define BIND_AprAllocatorT_TYPE TRUE
#define BIND_AprAllocatorT_INITIALIZE FALSE

#define BIND_AprArrayHeaderT_TYPE TRUE
#define BIND_AprArrayHeaderT_INITIALIZE FALSE
#define BIND_AprArrayHeaderT_elt_size_FIELD FALSE
#define BIND_AprArrayHeaderT_elts_FIELD FALSE
#define BIND_AprArrayHeaderT_nalloc_FIELD FALSE
#define BIND_AprArrayHeaderT_nelts_FIELD FALSE
#define BIND_AprArrayHeaderT_pool_FIELD FALSE

#define BIND_AprCryptoHashT_TYPE TRUE
#define BIND_AprCryptoHashT_INITIALIZE FALSE
#define BIND_AprCryptoHashT_add_FIELD FALSE
#define BIND_AprCryptoHashT_data_FIELD FALSE
#define BIND_AprCryptoHashT_finish_FIELD FALSE
#define BIND_AprCryptoHashT_init_FIELD FALSE
#define BIND_AprCryptoHashT_size_FIELD FALSE

#define BIND_AprDirT_TYPE TRUE
#define BIND_AprDirT_INITIALIZE FALSE

#define BIND_AprDsoHandleT_TYPE TRUE
#define BIND_AprDsoHandleT_INITIALIZE FALSE

#define BIND_AprFileT_TYPE TRUE
#define BIND_AprFileT_INITIALIZE FALSE

#define BIND_AprFinfoT_TYPE TRUE
#define BIND_AprFinfoT_INITIALIZE TRUE
#define BIND_AprFinfoT_atime_FIELD TRUE
#define BIND_AprFinfoT_csize_FIELD TRUE
#define BIND_AprFinfoT_ctime_FIELD TRUE
#define BIND_AprFinfoT_device_FIELD TRUE
#define BIND_AprFinfoT_filehand_FIELD TRUE
#define BIND_AprFinfoT_filetype_FIELD TRUE
#define BIND_AprFinfoT_fname_FIELD TRUE
#define BIND_AprFinfoT_group_FIELD FALSE
#define BIND_AprFinfoT_inode_FIELD FALSE
#define BIND_AprFinfoT_mtime_FIELD TRUE
#define BIND_AprFinfoT_name_FIELD TRUE
#define BIND_AprFinfoT_nlink_FIELD TRUE
#define BIND_AprFinfoT_pool_FIELD FALSE
#define BIND_AprFinfoT_protection_FIELD TRUE
#define BIND_AprFinfoT_size_FIELD TRUE
#define BIND_AprFinfoT_user_FIELD FALSE
#define BIND_AprFinfoT_valid_FIELD TRUE

#define BIND_AprGetoptOptionT_TYPE TRUE
#define BIND_AprGetoptOptionT_INITIALIZE FALSE
#define BIND_AprGetoptOptionT_description_FIELD FALSE
#define BIND_AprGetoptOptionT_has_arg_FIELD FALSE
#define BIND_AprGetoptOptionT_name_FIELD FALSE
#define BIND_AprGetoptOptionT_optch_FIELD FALSE

#define BIND_AprGetoptT_TYPE TRUE
#define BIND_AprGetoptT_INITIALIZE FALSE
#define BIND_AprGetoptT_argc_FIELD FALSE
#define BIND_AprGetoptT_argv_FIELD FALSE
#define BIND_AprGetoptT_cont_FIELD FALSE
#define BIND_AprGetoptT_errarg_FIELD FALSE
#define BIND_AprGetoptT_errfn_FIELD FALSE
#define BIND_AprGetoptT_ind_FIELD FALSE
#define BIND_AprGetoptT_interleave_FIELD FALSE
#define BIND_AprGetoptT_opt_FIELD FALSE
#define BIND_AprGetoptT_place_FIELD FALSE
#define BIND_AprGetoptT_reset_FIELD FALSE
#define BIND_AprGetoptT_skip_end_FIELD FALSE
#define BIND_AprGetoptT_skip_start_FIELD FALSE

#define BIND_AprHashIndexT_TYPE TRUE
#define BIND_AprHashIndexT_INITIALIZE FALSE

#define BIND_AprHashT_TYPE TRUE
#define BIND_AprHashT_INITIALIZE FALSE

#define BIND_AprHdtrT_TYPE TRUE
#define BIND_AprHdtrT_INITIALIZE FALSE
#define BIND_AprHdtrT_headers_FIELD FALSE
#define BIND_AprHdtrT_numheaders_FIELD FALSE
#define BIND_AprHdtrT_numtrailers_FIELD FALSE
#define BIND_AprHdtrT_trailers_FIELD FALSE

#define BIND_AprIpsubnetT_TYPE TRUE
#define BIND_AprIpsubnetT_INITIALIZE FALSE

#define BIND_AprMemnodeT_TYPE TRUE
#define BIND_AprMemnodeT_INITIALIZE FALSE
#define BIND_AprMemnodeT_endp_FIELD FALSE
#define BIND_AprMemnodeT_first_avail_FIELD FALSE
#define BIND_AprMemnodeT_free_index_FIELD FALSE
#define BIND_AprMemnodeT_index_FIELD FALSE
#define BIND_AprMemnodeT_next_FIELD FALSE
#define BIND_AprMemnodeT_ref_FIELD FALSE

#define BIND_AprMmapT_TYPE TRUE
#define BIND_AprMmapT_INITIALIZE FALSE
#define BIND_AprMmapT_cntxt_FIELD FALSE
#define BIND_AprMmapT_link_FIELD FALSE
#define BIND_AprMmapT_mhandle_FIELD FALSE
#define BIND_AprMmapT_mm_FIELD FALSE
#define BIND_AprMmapT_mv_FIELD FALSE
#define BIND_AprMmapT_poffset_FIELD FALSE
#define BIND_AprMmapT_psize_FIELD FALSE
#define BIND_AprMmapT_pstart_FIELD FALSE
#define BIND_AprMmapT_size_FIELD FALSE

#define BIND_AprOsSockInfoT_TYPE TRUE
#define BIND_AprOsSockInfoT_INITIALIZE FALSE
#define BIND_AprOsSockInfoT_family_FIELD FALSE
#define BIND_AprOsSockInfoT_local_FIELD FALSE
#define BIND_AprOsSockInfoT_os_sock_FIELD FALSE
#define BIND_AprOsSockInfoT_protocol_FIELD FALSE
#define BIND_AprOsSockInfoT_remote_FIELD FALSE
#define BIND_AprOsSockInfoT_type_FIELD FALSE

#define BIND_AprOtherChildRecT_TYPE TRUE
#define BIND_AprOtherChildRecT_INITIALIZE FALSE

#define BIND_AprPollcbT_TYPE TRUE
#define BIND_AprPollcbT_INITIALIZE FALSE

#define BIND_AprPollfdT_TYPE TRUE
#define BIND_AprPollfdT_INITIALIZE FALSE
#define BIND_AprPollfdT_client_data_FIELD FALSE
#define BIND_AprPollfdT_desc_FIELD FALSE
#define BIND_AprPollfdT_desc_type_FIELD FALSE
#define BIND_AprPollfdT_p_FIELD FALSE
#define BIND_AprPollfdT_reqevents_FIELD FALSE
#define BIND_AprPollfdT_rtnevents_FIELD FALSE

#define BIND_AprPollsetT_TYPE TRUE
#define BIND_AprPollsetT_INITIALIZE FALSE

#define BIND_AprPoolT_TYPE TRUE
#define BIND_AprPoolT_INITIALIZE FALSE

#define BIND_AprProcMutexT_TYPE TRUE
#define BIND_AprProcMutexT_INITIALIZE FALSE

#define BIND_AprProcT_TYPE TRUE
#define BIND_AprProcT_INITIALIZE FALSE
#define BIND_AprProcT_err_FIELD TRUE
#define BIND_AprProcT_hproc_FIELD FALSE
#define BIND_AprProcT_in_FIELD TRUE
#define BIND_AprProcT_invoked_FIELD FALSE
#define BIND_AprProcT_out_FIELD TRUE
#define BIND_AprProcT_pid_FIELD TRUE

#define BIND_AprProcattrT_TYPE TRUE
#define BIND_AprProcattrT_INITIALIZE FALSE

#define BIND_AprRandomT_TYPE TRUE
#define BIND_AprRandomT_INITIALIZE FALSE

#define BIND_AprShmT_TYPE TRUE
#define BIND_AprShmT_INITIALIZE FALSE

#define BIND_AprSkiplist_TYPE TRUE
#define BIND_AprSkiplist_INITIALIZE FALSE

#define BIND_AprSkiplistnode_TYPE TRUE
#define BIND_AprSkiplistnode_INITIALIZE FALSE

#define BIND_AprSockaddrT_TYPE TRUE
#define BIND_AprSockaddrT_INITIALIZE FALSE
#define BIND_AprSockaddrT_addr_str_len_FIELD FALSE
#define BIND_AprSockaddrT_family_FIELD FALSE
#define BIND_AprSockaddrT_hostname_FIELD FALSE
#define BIND_AprSockaddrT_ipaddr_len_FIELD FALSE
#define BIND_AprSockaddrT_ipaddr_ptr_FIELD FALSE
#define BIND_AprSockaddrT_next_FIELD FALSE
#define BIND_AprSockaddrT_pool_FIELD FALSE
#define BIND_AprSockaddrT_port_FIELD FALSE
#define BIND_AprSockaddrT_sa_FIELD FALSE
#define BIND_AprSockaddrT_salen_FIELD FALSE
#define BIND_AprSockaddrT_servname_FIELD FALSE

#define BIND_AprSocketT_TYPE TRUE
#define BIND_AprSocketT_INITIALIZE FALSE

#define BIND_AprTableEntryT_TYPE TRUE
#define BIND_AprTableEntryT_INITIALIZE FALSE
#define BIND_AprTableEntryT_key_FIELD FALSE
#define BIND_AprTableEntryT_key_checksum_FIELD FALSE
#define BIND_AprTableEntryT_val_FIELD FALSE

#define BIND_AprTableT_TYPE TRUE
#define BIND_AprTableT_INITIALIZE FALSE

#define BIND_AprThreadCondT_TYPE TRUE
#define BIND_AprThreadCondT_INITIALIZE FALSE

#define BIND_AprThreadMutexT_TYPE TRUE
#define BIND_AprThreadMutexT_INITIALIZE FALSE

#define BIND_AprThreadOnceT_TYPE TRUE
#define BIND_AprThreadOnceT_INITIALIZE FALSE

#define BIND_AprThreadRwlockT_TYPE TRUE
#define BIND_AprThreadRwlockT_INITIALIZE FALSE

#define BIND_AprThreadT_TYPE TRUE
#define BIND_AprThreadT_INITIALIZE FALSE

#define BIND_AprThreadattrT_TYPE TRUE
#define BIND_AprThreadattrT_INITIALIZE FALSE

#define BIND_AprThreadkeyT_TYPE TRUE
#define BIND_AprThreadkeyT_INITIALIZE FALSE

#define BIND_AprTimeExpT_TYPE TRUE
#define BIND_AprTimeExpT_INITIALIZE FALSE
#define BIND_AprTimeExpT_tm_gmtoff_FIELD FALSE
#define BIND_AprTimeExpT_tm_hour_FIELD FALSE
#define BIND_AprTimeExpT_tm_isdst_FIELD FALSE
#define BIND_AprTimeExpT_tm_mday_FIELD FALSE
#define BIND_AprTimeExpT_tm_min_FIELD FALSE
#define BIND_AprTimeExpT_tm_mon_FIELD FALSE
#define BIND_AprTimeExpT_tm_sec_FIELD FALSE
#define BIND_AprTimeExpT_tm_usec_FIELD FALSE
#define BIND_AprTimeExpT_tm_wday_FIELD FALSE
#define BIND_AprTimeExpT_tm_yday_FIELD FALSE
#define BIND_AprTimeExpT_tm_year_FIELD FALSE

#define BIND_AprVersionT_TYPE TRUE
#define BIND_AprVersionT_INITIALIZE FALSE
#define BIND_AprVersionT_is_dev_FIELD FALSE
#define BIND_AprVersionT_major_FIELD FALSE
#define BIND_AprVersionT_minor_FIELD FALSE
#define BIND_AprVersionT_patch_FIELD FALSE

#define BIND_AprVformatterBuffT_TYPE TRUE
#define BIND_AprVformatterBuffT_INITIALIZE FALSE
#define BIND_AprVformatterBuffT_curpos_FIELD FALSE
#define BIND_AprVformatterBuffT_endpos_FIELD FALSE


/*
 * Global Function Options
 * -----------------------
 *
 * Set these macros to TRUE to enable bindings for these functions.
 * They are disabled initially so that bindings may be added and tested
 * incrementally. The generated bindings are a good start, but they
 * will need to be verified and, sometimes, customized.
 */

#define BIND_apr_allocator_alloc_FUNCTION FALSE
#define BIND_apr_allocator_create_FUNCTION FALSE
#define BIND_apr_allocator_destroy_FUNCTION FALSE
#define BIND_apr_allocator_free_FUNCTION FALSE
#define BIND_apr_allocator_max_free_set_FUNCTION FALSE
#define BIND_apr_allocator_mutex_get_FUNCTION FALSE
#define BIND_apr_allocator_mutex_set_FUNCTION FALSE
#define BIND_apr_allocator_owner_get_FUNCTION FALSE
#define BIND_apr_allocator_owner_set_FUNCTION FALSE
#define BIND_apr_app_initialize_FUNCTION FALSE
#define BIND_apr_array_append_FUNCTION FALSE
#define BIND_apr_array_cat_FUNCTION FALSE
#define BIND_apr_array_clear_FUNCTION FALSE
#define BIND_apr_array_copy_FUNCTION FALSE
#define BIND_apr_array_copy_hdr_FUNCTION FALSE
#define BIND_apr_array_make_FUNCTION FALSE
#define BIND_apr_array_pop_FUNCTION FALSE
#define BIND_apr_array_pstrcat_FUNCTION FALSE
#define BIND_apr_array_push_FUNCTION FALSE
#define BIND_apr_atoi64_FUNCTION FALSE
#define BIND_apr_atomic_add32_FUNCTION FALSE
#define BIND_apr_atomic_cas32_FUNCTION FALSE
#define BIND_apr_atomic_casptr_FUNCTION FALSE
#define BIND_apr_atomic_dec32_FUNCTION FALSE
#define BIND_apr_atomic_inc32_FUNCTION FALSE
#define BIND_apr_atomic_init_FUNCTION FALSE
#define BIND_apr_atomic_read32_FUNCTION FALSE
#define BIND_apr_atomic_set32_FUNCTION FALSE
#define BIND_apr_atomic_sub32_FUNCTION FALSE
#define BIND_apr_atomic_xchg32_FUNCTION FALSE
#define BIND_apr_atomic_xchgptr_FUNCTION FALSE
#define BIND_apr_collapse_spaces_FUNCTION FALSE
#define BIND_apr_cpystrn_FUNCTION FALSE
#define BIND_apr_crypto_sha256_new_FUNCTION FALSE
#define BIND_apr_ctime_FUNCTION TRUE
#define BIND_apr_dir_close_FUNCTION TRUE
#define BIND_apr_dir_make_FUNCTION TRUE
#define BIND_apr_dir_make_recursive_FUNCTION TRUE
#define BIND_apr_dir_open_FUNCTION TRUE
#define BIND_apr_dir_read_FUNCTION TRUE
#define BIND_apr_dir_remove_FUNCTION TRUE
#define BIND_apr_dir_rewind_FUNCTION TRUE
#define BIND_apr_dso_error_FUNCTION FALSE
#define BIND_apr_dso_load_FUNCTION FALSE
#define BIND_apr_dso_sym_FUNCTION FALSE
#define BIND_apr_dso_unload_FUNCTION FALSE
#define BIND_apr_env_delete_FUNCTION TRUE
#define BIND_apr_env_get_FUNCTION TRUE
#define BIND_apr_env_set_FUNCTION TRUE
#define BIND_apr_escape_echo_FUNCTION FALSE
#define BIND_apr_escape_entity_FUNCTION FALSE
#define BIND_apr_escape_hex_FUNCTION FALSE
#define BIND_apr_escape_path_FUNCTION FALSE
#define BIND_apr_escape_path_segment_FUNCTION FALSE
#define BIND_apr_escape_shell_FUNCTION FALSE
#define BIND_apr_escape_urlencoded_FUNCTION FALSE
#define BIND_apr_file_append_FUNCTION TRUE
#define BIND_apr_file_attrs_set_FUNCTION TRUE
#define BIND_apr_file_buffer_set_FUNCTION FALSE
#define BIND_apr_file_buffer_size_get_FUNCTION TRUE
#define BIND_apr_file_close_FUNCTION TRUE
#define BIND_apr_file_copy_FUNCTION TRUE
#define BIND_apr_file_data_get_FUNCTION FALSE
#define BIND_apr_file_data_set_FUNCTION FALSE
#define BIND_apr_file_datasync_FUNCTION TRUE
#define BIND_apr_file_dup_FUNCTION FALSE
#define BIND_apr_file_dup2_FUNCTION FALSE
#define BIND_apr_file_eof_FUNCTION TRUE
#define BIND_apr_file_flags_get_FUNCTION TRUE
#define BIND_apr_file_flush_FUNCTION TRUE
#define BIND_apr_file_getc_FUNCTION TRUE
#define BIND_apr_file_gets_FUNCTION TRUE
#define BIND_apr_file_info_get_FUNCTION FALSE
#define BIND_apr_file_link_FUNCTION TRUE
#define BIND_apr_file_lock_FUNCTION TRUE
#define BIND_apr_file_mktemp_FUNCTION FALSE
#define BIND_apr_file_mtime_set_FUNCTION FALSE
#define BIND_apr_file_name_get_FUNCTION FALSE
#define BIND_apr_file_namedpipe_create_FUNCTION TRUE
#define BIND_apr_file_open_FUNCTION TRUE
#define BIND_apr_file_open_flags_stderr_FUNCTION FALSE
#define BIND_apr_file_open_flags_stdin_FUNCTION FALSE
#define BIND_apr_file_open_flags_stdout_FUNCTION FALSE
#define BIND_apr_file_open_stderr_FUNCTION TRUE
#define BIND_apr_file_open_stdin_FUNCTION TRUE
#define BIND_apr_file_open_stdout_FUNCTION TRUE
#define BIND_apr_file_perms_set_FUNCTION TRUE
#define BIND_apr_file_pipe_create_FUNCTION TRUE
#define BIND_apr_file_pipe_create_ex_FUNCTION FALSE
#define BIND_apr_file_pipe_timeout_get_FUNCTION FALSE
#define BIND_apr_file_pipe_timeout_set_FUNCTION FALSE
#define BIND_apr_file_printf_FUNCTION FALSE
#define BIND_apr_file_putc_FUNCTION FALSE
#define BIND_apr_file_puts_FUNCTION TRUE
#define BIND_apr_file_read_FUNCTION TRUE
#define BIND_apr_file_read_full_FUNCTION FALSE
#define BIND_apr_file_remove_FUNCTION TRUE
#define BIND_apr_file_rename_FUNCTION TRUE
#define BIND_apr_file_seek_FUNCTION TRUE
#define BIND_apr_file_setaside_FUNCTION FALSE
#define BIND_apr_file_sync_FUNCTION TRUE
#define BIND_apr_file_trunc_FUNCTION TRUE
#define BIND_apr_file_ungetc_FUNCTION TRUE
#define BIND_apr_file_unlock_FUNCTION TRUE
#define BIND_apr_file_write_FUNCTION TRUE
#define BIND_apr_file_write_full_FUNCTION FALSE
#define BIND_apr_file_writev_FUNCTION FALSE
#define BIND_apr_file_writev_full_FUNCTION FALSE
#define BIND_apr_filepath_encoding_FUNCTION FALSE
#define BIND_apr_filepath_get_FUNCTION FALSE
#define BIND_apr_filepath_list_merge_FUNCTION FALSE
#define BIND_apr_filepath_list_split_FUNCTION FALSE
#define BIND_apr_filepath_merge_FUNCTION FALSE
#define BIND_apr_filepath_name_get_FUNCTION TRUE
#define BIND_apr_filepath_root_FUNCTION FALSE
#define BIND_apr_filepath_set_FUNCTION FALSE
#define BIND_apr_fnmatch_FUNCTION TRUE
#define BIND_apr_fnmatch_test_FUNCTION TRUE
#define BIND_apr_generate_random_bytes_FUNCTION FALSE
#define BIND_apr_gethostname_FUNCTION FALSE
#define BIND_apr_getnameinfo_FUNCTION FALSE
#define BIND_apr_getopt_FUNCTION FALSE
#define BIND_apr_getopt_init_FUNCTION FALSE
#define BIND_apr_getopt_long_FUNCTION FALSE
#define BIND_apr_getservbyname_FUNCTION FALSE
#define BIND_apr_gid_compare_FUNCTION FALSE
#define BIND_apr_gid_get_FUNCTION FALSE
#define BIND_apr_gid_name_get_FUNCTION FALSE
#define BIND_apr_hash_clear_FUNCTION FALSE
#define BIND_apr_hash_copy_FUNCTION FALSE
#define BIND_apr_hash_count_FUNCTION FALSE
#define BIND_apr_hash_do_FUNCTION FALSE
#define BIND_apr_hash_first_FUNCTION FALSE
#define BIND_apr_hash_get_FUNCTION FALSE
#define BIND_apr_hash_make_FUNCTION FALSE
#define BIND_apr_hash_make_custom_FUNCTION FALSE
#define BIND_apr_hash_merge_FUNCTION FALSE
#define BIND_apr_hash_next_FUNCTION FALSE
#define BIND_apr_hash_overlay_FUNCTION FALSE
#define BIND_apr_hash_set_FUNCTION FALSE
#define BIND_apr_hash_this_FUNCTION FALSE
#define BIND_apr_hash_this_key_FUNCTION FALSE
#define BIND_apr_hash_this_key_len_FUNCTION FALSE
#define BIND_apr_hash_this_val_FUNCTION FALSE
#define BIND_apr_hashfunc_default_FUNCTION FALSE
#define BIND_apr_initialize_FUNCTION TRUE
#define BIND_apr_ipsubnet_create_FUNCTION FALSE
#define BIND_apr_ipsubnet_test_FUNCTION FALSE
#define BIND_apr_is_empty_array_FUNCTION FALSE
#define BIND_apr_is_empty_table_FUNCTION FALSE
#define BIND_apr_itoa_FUNCTION FALSE
#define BIND_apr_ltoa_FUNCTION FALSE
#define BIND_apr_match_glob_FUNCTION FALSE
#define BIND_apr_mcast_hops_FUNCTION FALSE
#define BIND_apr_mcast_interface_FUNCTION FALSE
#define BIND_apr_mcast_join_FUNCTION FALSE
#define BIND_apr_mcast_leave_FUNCTION FALSE
#define BIND_apr_mcast_loopback_FUNCTION FALSE
#define BIND_apr_mmap_create_FUNCTION FALSE
#define BIND_apr_mmap_delete_FUNCTION FALSE
#define BIND_apr_mmap_dup_FUNCTION FALSE
#define BIND_apr_mmap_offset_FUNCTION FALSE
#define BIND_apr_off_t_toa_FUNCTION FALSE
#define BIND_apr_os_default_encoding_FUNCTION TRUE
#define BIND_apr_os_dir_get_FUNCTION FALSE
#define BIND_apr_os_dir_put_FUNCTION FALSE
#define BIND_apr_os_dso_handle_get_FUNCTION FALSE
#define BIND_apr_os_dso_handle_put_FUNCTION FALSE
#define BIND_apr_os_exp_time_get_FUNCTION FALSE
#define BIND_apr_os_exp_time_put_FUNCTION FALSE
#define BIND_apr_os_file_get_FUNCTION FALSE
#define BIND_apr_os_file_put_FUNCTION FALSE
#define BIND_apr_os_imp_time_get_FUNCTION FALSE
#define BIND_apr_os_imp_time_put_FUNCTION FALSE
#define BIND_apr_os_locale_encoding_FUNCTION TRUE
#define BIND_apr_os_pipe_put_FUNCTION FALSE
#define BIND_apr_os_pipe_put_ex_FUNCTION FALSE
#define BIND_apr_os_proc_mutex_get_FUNCTION FALSE
#define BIND_apr_os_proc_mutex_put_FUNCTION FALSE
#define BIND_apr_os_shm_get_FUNCTION FALSE
#define BIND_apr_os_shm_put_FUNCTION FALSE
#define BIND_apr_os_sock_get_FUNCTION FALSE
#define BIND_apr_os_sock_make_FUNCTION FALSE
#define BIND_apr_os_sock_put_FUNCTION FALSE
#define BIND_apr_os_thread_current_FUNCTION FALSE
#define BIND_apr_os_thread_equal_FUNCTION FALSE
#define BIND_apr_os_thread_get_FUNCTION FALSE
#define BIND_apr_os_thread_put_FUNCTION FALSE
#define BIND_apr_os_threadkey_get_FUNCTION FALSE
#define BIND_apr_os_threadkey_put_FUNCTION FALSE
#define BIND_apr_os_uuid_get_FUNCTION FALSE
#define BIND_apr_palloc_FUNCTION FALSE
#define BIND_apr_palloc_debug_FUNCTION FALSE
#define BIND_apr_parse_addr_port_FUNCTION FALSE
#define BIND_apr_password_get_FUNCTION FALSE
#define BIND_apr_pcalloc_debug_FUNCTION FALSE
#define BIND_apr_pescape_echo_FUNCTION FALSE
#define BIND_apr_pescape_entity_FUNCTION FALSE
#define BIND_apr_pescape_hex_FUNCTION FALSE
#define BIND_apr_pescape_path_FUNCTION FALSE
#define BIND_apr_pescape_path_segment_FUNCTION FALSE
#define BIND_apr_pescape_shell_FUNCTION FALSE
#define BIND_apr_pescape_urlencoded_FUNCTION FALSE
#define BIND_apr_pmemdup_FUNCTION FALSE
#define BIND_apr_poll_FUNCTION FALSE
#define BIND_apr_poll_method_defname_FUNCTION FALSE
#define BIND_apr_pollcb_add_FUNCTION FALSE
#define BIND_apr_pollcb_create_FUNCTION FALSE
#define BIND_apr_pollcb_create_ex_FUNCTION FALSE
#define BIND_apr_pollcb_poll_FUNCTION FALSE
#define BIND_apr_pollcb_remove_FUNCTION FALSE
#define BIND_apr_pollset_add_FUNCTION FALSE
#define BIND_apr_pollset_create_FUNCTION FALSE
#define BIND_apr_pollset_create_ex_FUNCTION FALSE
#define BIND_apr_pollset_destroy_FUNCTION FALSE
#define BIND_apr_pollset_method_name_FUNCTION FALSE
#define BIND_apr_pollset_poll_FUNCTION FALSE
#define BIND_apr_pollset_remove_FUNCTION FALSE
#define BIND_apr_pollset_wakeup_FUNCTION FALSE
#define BIND_apr_pool_abort_get_FUNCTION FALSE
#define BIND_apr_pool_abort_set_FUNCTION FALSE
#define BIND_apr_pool_allocator_get_FUNCTION FALSE
#define BIND_apr_pool_child_cleanup_set_FUNCTION FALSE
#define BIND_apr_pool_cleanup_for_exec_FUNCTION FALSE
#define BIND_apr_pool_cleanup_kill_FUNCTION FALSE
#define BIND_apr_pool_cleanup_null_FUNCTION FALSE
#define BIND_apr_pool_cleanup_register_FUNCTION FALSE
#define BIND_apr_pool_cleanup_run_FUNCTION FALSE
#define BIND_apr_pool_clear_FUNCTION TRUE
#define BIND_apr_pool_clear_debug_FUNCTION FALSE
#define BIND_apr_pool_create_FUNCTION TRUE
#define BIND_apr_pool_create_core_ex_FUNCTION FALSE
#define BIND_apr_pool_create_core_ex_debug_FUNCTION FALSE
#define BIND_apr_pool_create_ex_FUNCTION FALSE
#define BIND_apr_pool_create_ex_debug_FUNCTION FALSE
#define BIND_apr_pool_create_unmanaged_ex_FUNCTION FALSE
#define BIND_apr_pool_create_unmanaged_ex_debug_FUNCTION FALSE
#define BIND_apr_pool_destroy_FUNCTION TRUE
#define BIND_apr_pool_destroy_debug_FUNCTION FALSE
#define BIND_apr_pool_initialize_FUNCTION FALSE
#define BIND_apr_pool_is_ancestor_FUNCTION FALSE
#define BIND_apr_pool_note_subprocess_FUNCTION FALSE
#define BIND_apr_pool_parent_get_FUNCTION FALSE
#define BIND_apr_pool_pre_cleanup_register_FUNCTION FALSE
#define BIND_apr_pool_tag_FUNCTION FALSE
#define BIND_apr_pool_terminate_FUNCTION FALSE
#define BIND_apr_pool_userdata_get_FUNCTION FALSE
#define BIND_apr_pool_userdata_set_FUNCTION FALSE
#define BIND_apr_pool_userdata_setn_FUNCTION FALSE
#define BIND_apr_proc_create_FUNCTION TRUE
#define BIND_apr_proc_detach_FUNCTION TRUE
#define BIND_apr_proc_kill_FUNCTION FALSE
#define BIND_apr_proc_mutex_child_init_FUNCTION FALSE
#define BIND_apr_proc_mutex_cleanup_FUNCTION FALSE
#define BIND_apr_proc_mutex_create_FUNCTION FALSE
#define BIND_apr_proc_mutex_defname_FUNCTION FALSE
#define BIND_apr_proc_mutex_destroy_FUNCTION FALSE
#define BIND_apr_proc_mutex_lock_FUNCTION FALSE
#define BIND_apr_proc_mutex_lockfile_FUNCTION FALSE
#define BIND_apr_proc_mutex_name_FUNCTION FALSE
#define BIND_apr_proc_mutex_trylock_FUNCTION FALSE
#define BIND_apr_proc_mutex_unlock_FUNCTION FALSE
#define BIND_apr_proc_other_child_alert_FUNCTION FALSE
#define BIND_apr_proc_other_child_refresh_FUNCTION FALSE
#define BIND_apr_proc_other_child_refresh_all_FUNCTION FALSE
#define BIND_apr_proc_other_child_register_FUNCTION FALSE
#define BIND_apr_proc_other_child_unregister_FUNCTION FALSE
#define BIND_apr_proc_wait_FUNCTION TRUE
#define BIND_apr_proc_wait_all_procs_FUNCTION FALSE
#define BIND_apr_procattr_addrspace_set_FUNCTION TRUE
#define BIND_apr_procattr_child_err_set_FUNCTION TRUE
#define BIND_apr_procattr_child_errfn_set_FUNCTION FALSE
#define BIND_apr_procattr_child_in_set_FUNCTION TRUE
#define BIND_apr_procattr_child_out_set_FUNCTION TRUE
#define BIND_apr_procattr_cmdtype_set_FUNCTION TRUE
#define BIND_apr_procattr_create_FUNCTION TRUE
#define BIND_apr_procattr_detach_set_FUNCTION TRUE
#define BIND_apr_procattr_dir_set_FUNCTION TRUE
#define BIND_apr_procattr_error_check_set_FUNCTION TRUE
#define BIND_apr_procattr_group_set_FUNCTION TRUE
#define BIND_apr_procattr_io_set_FUNCTION TRUE
#define BIND_apr_procattr_user_set_FUNCTION TRUE
#define BIND_apr_psprintf_FUNCTION FALSE
#define BIND_apr_pstrcat_FUNCTION FALSE
#define BIND_apr_pstrcatv_FUNCTION FALSE
#define BIND_apr_pstrdup_FUNCTION FALSE
#define BIND_apr_pstrmemdup_FUNCTION FALSE
#define BIND_apr_pstrndup_FUNCTION FALSE
#define BIND_apr_punescape_entity_FUNCTION FALSE
#define BIND_apr_punescape_hex_FUNCTION FALSE
#define BIND_apr_punescape_url_FUNCTION FALSE
#define BIND_apr_pvsprintf_FUNCTION FALSE
#define BIND_apr_random_add_entropy_FUNCTION FALSE
#define BIND_apr_random_after_fork_FUNCTION FALSE
#define BIND_apr_random_barrier_FUNCTION FALSE
#define BIND_apr_random_init_FUNCTION FALSE
#define BIND_apr_random_insecure_bytes_FUNCTION FALSE
#define BIND_apr_random_insecure_ready_FUNCTION FALSE
#define BIND_apr_random_secure_bytes_FUNCTION FALSE
#define BIND_apr_random_secure_ready_FUNCTION FALSE
#define BIND_apr_random_standard_new_FUNCTION FALSE
#define BIND_apr_rfc822_date_FUNCTION FALSE
#define BIND_apr_shm_attach_FUNCTION FALSE
#define BIND_apr_shm_attach_ex_FUNCTION FALSE
#define BIND_apr_shm_baseaddr_get_FUNCTION FALSE
#define BIND_apr_shm_create_FUNCTION FALSE
#define BIND_apr_shm_create_ex_FUNCTION FALSE
#define BIND_apr_shm_destroy_FUNCTION FALSE
#define BIND_apr_shm_detach_FUNCTION FALSE
#define BIND_apr_shm_remove_FUNCTION FALSE
#define BIND_apr_shm_size_get_FUNCTION FALSE
#define BIND_apr_signal_block_FUNCTION FALSE
#define BIND_apr_signal_description_get_FUNCTION FALSE
#define BIND_apr_signal_init_FUNCTION FALSE
#define BIND_apr_signal_unblock_FUNCTION FALSE
#define BIND_apr_skiplist_add_index_FUNCTION FALSE
#define BIND_apr_skiplist_alloc_FUNCTION FALSE
#define BIND_apr_skiplist_destroy_FUNCTION FALSE
#define BIND_apr_skiplist_find_FUNCTION FALSE
#define BIND_apr_skiplist_find_compare_FUNCTION FALSE
#define BIND_apr_skiplist_free_FUNCTION FALSE
#define BIND_apr_skiplist_getlist_FUNCTION FALSE
#define BIND_apr_skiplist_init_FUNCTION FALSE
#define BIND_apr_skiplist_insert_FUNCTION FALSE
#define BIND_apr_skiplist_insert_compare_FUNCTION FALSE
#define BIND_apr_skiplist_merge_FUNCTION FALSE
#define BIND_apr_skiplist_next_FUNCTION FALSE
#define BIND_apr_skiplist_peek_FUNCTION FALSE
#define BIND_apr_skiplist_pop_FUNCTION FALSE
#define BIND_apr_skiplist_previous_FUNCTION FALSE
#define BIND_apr_skiplist_remove_FUNCTION FALSE
#define BIND_apr_skiplist_remove_all_FUNCTION FALSE
#define BIND_apr_skiplist_remove_compare_FUNCTION FALSE
#define BIND_apr_skiplist_set_compare_FUNCTION FALSE
#define BIND_apr_sleep_FUNCTION TRUE
#define BIND_apr_snprintf_FUNCTION FALSE
#define BIND_apr_sockaddr_equal_FUNCTION TRUE
#define BIND_apr_sockaddr_info_get_FUNCTION TRUE
#define BIND_apr_sockaddr_ip_get_FUNCTION TRUE
#define BIND_apr_sockaddr_ip_getbuf_FUNCTION FALSE
#define BIND_apr_sockaddr_is_wildcard_FUNCTION TRUE
#define BIND_apr_socket_accept_FUNCTION TRUE
#define BIND_apr_socket_addr_get_FUNCTION TRUE
#define BIND_apr_socket_atmark_FUNCTION FALSE
#define BIND_apr_socket_atreadeof_FUNCTION FALSE
#define BIND_apr_socket_bind_FUNCTION TRUE
#define BIND_apr_socket_close_FUNCTION TRUE
#define BIND_apr_socket_connect_FUNCTION TRUE
#define BIND_apr_socket_create_FUNCTION TRUE
#define BIND_apr_socket_data_get_FUNCTION FALSE
#define BIND_apr_socket_data_set_FUNCTION FALSE
#define BIND_apr_socket_listen_FUNCTION TRUE
#define BIND_apr_socket_opt_get_FUNCTION TRUE
#define BIND_apr_socket_opt_set_FUNCTION TRUE
#define BIND_apr_socket_protocol_get_FUNCTION TRUE
#define BIND_apr_socket_recv_FUNCTION TRUE
#define BIND_apr_socket_recvfrom_FUNCTION TRUE
#define BIND_apr_socket_send_FUNCTION TRUE
#define BIND_apr_socket_sendfile_FUNCTION FALSE
#define BIND_apr_socket_sendto_FUNCTION TRUE
#define BIND_apr_socket_sendv_FUNCTION FALSE
#define BIND_apr_socket_shutdown_FUNCTION TRUE
#define BIND_apr_socket_timeout_get_FUNCTION TRUE
#define BIND_apr_socket_timeout_set_FUNCTION TRUE
#define BIND_apr_socket_type_get_FUNCTION TRUE
#define BIND_apr_stat_FUNCTION FALSE
#define BIND_apr_strerror_FUNCTION TRUE
#define BIND_apr_to_os_error_FUNCTION TRUE
#define BIND_apr_strfsize_FUNCTION FALSE
#define BIND_apr_strftime_FUNCTION FALSE
#define BIND_apr_strnatcasecmp_FUNCTION FALSE
#define BIND_apr_strnatcmp_FUNCTION FALSE
#define BIND_apr_strtoff_FUNCTION FALSE
#define BIND_apr_strtoi64_FUNCTION FALSE
#define BIND_apr_strtok_FUNCTION FALSE
#define BIND_apr_table_add_FUNCTION FALSE
#define BIND_apr_table_addn_FUNCTION FALSE
#define BIND_apr_table_clear_FUNCTION FALSE
#define BIND_apr_table_clone_FUNCTION FALSE
#define BIND_apr_table_compress_FUNCTION FALSE
#define BIND_apr_table_copy_FUNCTION FALSE
#define BIND_apr_table_do_FUNCTION FALSE
#define BIND_apr_table_elts_FUNCTION FALSE
#define BIND_apr_table_get_FUNCTION FALSE
#define BIND_apr_table_getm_FUNCTION FALSE
#define BIND_apr_table_make_FUNCTION FALSE
#define BIND_apr_table_merge_FUNCTION FALSE
#define BIND_apr_table_mergen_FUNCTION FALSE
#define BIND_apr_table_overlap_FUNCTION FALSE
#define BIND_apr_table_overlay_FUNCTION FALSE
#define BIND_apr_table_set_FUNCTION FALSE
#define BIND_apr_table_setn_FUNCTION FALSE
#define BIND_apr_table_unset_FUNCTION FALSE
#define BIND_apr_table_vdo_FUNCTION FALSE
#define BIND_apr_temp_dir_get_FUNCTION TRUE
#define BIND_apr_terminate_FUNCTION TRUE
#define BIND_apr_terminate2_FUNCTION TRUE
#define BIND_apr_thread_cond_broadcast_FUNCTION FALSE
#define BIND_apr_thread_cond_create_FUNCTION FALSE
#define BIND_apr_thread_cond_destroy_FUNCTION FALSE
#define BIND_apr_thread_cond_signal_FUNCTION FALSE
#define BIND_apr_thread_cond_timedwait_FUNCTION FALSE
#define BIND_apr_thread_cond_wait_FUNCTION FALSE
#define BIND_apr_thread_create_FUNCTION FALSE
#define BIND_apr_thread_data_get_FUNCTION FALSE
#define BIND_apr_thread_data_set_FUNCTION FALSE
#define BIND_apr_thread_detach_FUNCTION FALSE
#define BIND_apr_thread_exit_FUNCTION FALSE
#define BIND_apr_thread_join_FUNCTION FALSE
#define BIND_apr_thread_mutex_create_FUNCTION FALSE
#define BIND_apr_thread_mutex_destroy_FUNCTION FALSE
#define BIND_apr_thread_mutex_lock_FUNCTION FALSE
#define BIND_apr_thread_mutex_trylock_FUNCTION FALSE
#define BIND_apr_thread_mutex_unlock_FUNCTION FALSE
#define BIND_apr_thread_once_FUNCTION FALSE
#define BIND_apr_thread_once_init_FUNCTION FALSE
#define BIND_apr_thread_rwlock_create_FUNCTION FALSE
#define BIND_apr_thread_rwlock_destroy_FUNCTION FALSE
#define BIND_apr_thread_rwlock_rdlock_FUNCTION FALSE
#define BIND_apr_thread_rwlock_tryrdlock_FUNCTION FALSE
#define BIND_apr_thread_rwlock_trywrlock_FUNCTION FALSE
#define BIND_apr_thread_rwlock_unlock_FUNCTION FALSE
#define BIND_apr_thread_rwlock_wrlock_FUNCTION FALSE
#define BIND_apr_thread_yield_FUNCTION FALSE
#define BIND_apr_threadattr_create_FUNCTION FALSE
#define BIND_apr_threadattr_detach_get_FUNCTION FALSE
#define BIND_apr_threadattr_detach_set_FUNCTION FALSE
#define BIND_apr_threadattr_guardsize_set_FUNCTION FALSE
#define BIND_apr_threadattr_stacksize_set_FUNCTION FALSE
#define BIND_apr_threadkey_data_get_FUNCTION FALSE
#define BIND_apr_threadkey_data_set_FUNCTION FALSE
#define BIND_apr_threadkey_private_create_FUNCTION FALSE
#define BIND_apr_threadkey_private_delete_FUNCTION FALSE
#define BIND_apr_threadkey_private_get_FUNCTION FALSE
#define BIND_apr_threadkey_private_set_FUNCTION FALSE
#define BIND_apr_time_ansi_put_FUNCTION FALSE
#define BIND_apr_time_clock_hires_FUNCTION FALSE
#define BIND_apr_time_exp_get_FUNCTION FALSE
#define BIND_apr_time_exp_gmt_FUNCTION FALSE
#define BIND_apr_time_exp_gmt_get_FUNCTION FALSE
#define BIND_apr_time_exp_lt_FUNCTION FALSE
#define BIND_apr_time_exp_tz_FUNCTION FALSE
#define BIND_apr_time_now_FUNCTION TRUE
#define BIND_apr_tokenize_to_argv_FUNCTION TRUE
#define BIND_apr_uid_compare_FUNCTION FALSE
#define BIND_apr_uid_current_FUNCTION FALSE
#define BIND_apr_uid_get_FUNCTION FALSE
#define BIND_apr_uid_homepath_get_FUNCTION FALSE
#define BIND_apr_uid_name_get_FUNCTION FALSE
#define BIND_apr_unescape_entity_FUNCTION FALSE
#define BIND_apr_unescape_hex_FUNCTION FALSE
#define BIND_apr_unescape_url_FUNCTION FALSE
#define BIND_apr_version_FUNCTION FALSE
#define BIND_apr_version_string_FUNCTION FALSE
#define BIND_apr_vformatter_FUNCTION FALSE
#define BIND_apr_vsnprintf_FUNCTION FALSE
#define BIND_apr_wait_for_io_or_timeout_FUNCTION FALSE

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
#include "apr.h"
#include "apr_allocator.h"
#include "apr_atomic.h"
#include "apr_dso.h"
#include "apr_env.h"
#include "apr_errno.h"
#include "apr_escape.h"
#include "apr_file_info.h"
#include "apr_file_io.h"
#include "apr_fnmatch.h"
#include "apr_general.h"
#include "apr_getopt.h"
#include "apr_global_mutex.h"
#include "apr_hash.h"
#include "apr_inherit.h"
#include "apr_lib.h"
#include "apr_mmap.h"
#include "apr_network_io.h"
#include "apr_poll.h"
#include "apr_pools.h"
#include "apr_portable.h"
#include "apr_proc_mutex.h"
#include "apr_random.h"
#include "apr_ring.h"
#include "apr_shm.h"
#include "apr_signal.h"
#include "apr_skiplist.h"
#include "apr_strings.h"
#include "apr_support.h"
#include "apr_tables.h"
#include "apr_thread_cond.h"
#include "apr_thread_mutex.h"
#include "apr_thread_proc.h"
#include "apr_thread_rwlock.h"
#include "apr_time.h"
#include "apr_user.h"
#include "apr_version.h"

/*
 * Class initialization function declarations
 * ------------------------------------------
 *
 * These declarations are controlled by the macros in the
 * "Class Bindings Options" section above.
 */

#if BIND_AprAllocatorT_TYPE
void mrb_APR_AprAllocatorT_init(mrb_state* mrb);
#endif
#if BIND_AprArrayHeaderT_TYPE
void mrb_APR_AprArrayHeaderT_init(mrb_state* mrb);
#endif
#if BIND_AprCryptoHashT_TYPE
void mrb_APR_AprCryptoHashT_init(mrb_state* mrb);
#endif
#if BIND_AprDirT_TYPE
void mrb_APR_AprDirT_init(mrb_state* mrb);
#endif
#if BIND_AprDsoHandleT_TYPE
void mrb_APR_AprDsoHandleT_init(mrb_state* mrb);
#endif
#if BIND_AprFileT_TYPE
void mrb_APR_AprFileT_init(mrb_state* mrb);
#endif
#if BIND_AprFinfoT_TYPE
void mrb_APR_AprFinfoT_init(mrb_state* mrb);
#endif
#if BIND_AprGetoptOptionT_TYPE
void mrb_APR_AprGetoptOptionT_init(mrb_state* mrb);
#endif
#if BIND_AprGetoptT_TYPE
void mrb_APR_AprGetoptT_init(mrb_state* mrb);
#endif
#if BIND_AprHashIndexT_TYPE
void mrb_APR_AprHashIndexT_init(mrb_state* mrb);
#endif
#if BIND_AprHashT_TYPE
void mrb_APR_AprHashT_init(mrb_state* mrb);
#endif
#if BIND_AprHdtrT_TYPE
void mrb_APR_AprHdtrT_init(mrb_state* mrb);
#endif
#if BIND_AprIpsubnetT_TYPE
void mrb_APR_AprIpsubnetT_init(mrb_state* mrb);
#endif
#if BIND_AprMemnodeT_TYPE
void mrb_APR_AprMemnodeT_init(mrb_state* mrb);
#endif
#if BIND_AprMmapT_TYPE
void mrb_APR_AprMmapT_init(mrb_state* mrb);
#endif
#if BIND_AprOsSockInfoT_TYPE
void mrb_APR_AprOsSockInfoT_init(mrb_state* mrb);
#endif
#if BIND_AprOtherChildRecT_TYPE
void mrb_APR_AprOtherChildRecT_init(mrb_state* mrb);
#endif
#if BIND_AprPollcbT_TYPE
void mrb_APR_AprPollcbT_init(mrb_state* mrb);
#endif
#if BIND_AprPollfdT_TYPE
void mrb_APR_AprPollfdT_init(mrb_state* mrb);
#endif
#if BIND_AprPollsetT_TYPE
void mrb_APR_AprPollsetT_init(mrb_state* mrb);
#endif
#if BIND_AprPoolT_TYPE
void mrb_APR_AprPoolT_init(mrb_state* mrb);
#endif
#if BIND_AprProcMutexT_TYPE
void mrb_APR_AprProcMutexT_init(mrb_state* mrb);
#endif
#if BIND_AprProcT_TYPE
void mrb_APR_AprProcT_init(mrb_state* mrb);
#endif
#if BIND_AprProcattrT_TYPE
void mrb_APR_AprProcattrT_init(mrb_state* mrb);
#endif
#if BIND_AprRandomT_TYPE
void mrb_APR_AprRandomT_init(mrb_state* mrb);
#endif
#if BIND_AprShmT_TYPE
void mrb_APR_AprShmT_init(mrb_state* mrb);
#endif
#if BIND_AprSkiplist_TYPE
void mrb_APR_AprSkiplist_init(mrb_state* mrb);
#endif
#if BIND_AprSkiplistnode_TYPE
void mrb_APR_AprSkiplistnode_init(mrb_state* mrb);
#endif
#if BIND_AprSockaddrT_TYPE
void mrb_APR_AprSockaddrT_init(mrb_state* mrb);
#endif
#if BIND_AprSocketT_TYPE
void mrb_APR_AprSocketT_init(mrb_state* mrb);
#endif
#if BIND_AprTableEntryT_TYPE
void mrb_APR_AprTableEntryT_init(mrb_state* mrb);
#endif
#if BIND_AprTableT_TYPE
void mrb_APR_AprTableT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadCondT_TYPE
void mrb_APR_AprThreadCondT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadMutexT_TYPE
void mrb_APR_AprThreadMutexT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadOnceT_TYPE
void mrb_APR_AprThreadOnceT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadRwlockT_TYPE
void mrb_APR_AprThreadRwlockT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadT_TYPE
void mrb_APR_AprThreadT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadattrT_TYPE
void mrb_APR_AprThreadattrT_init(mrb_state* mrb);
#endif
#if BIND_AprThreadkeyT_TYPE
void mrb_APR_AprThreadkeyT_init(mrb_state* mrb);
#endif
#if BIND_AprTimeExpT_TYPE
void mrb_APR_AprTimeExpT_init(mrb_state* mrb);
#endif
#if BIND_AprVersionT_TYPE
void mrb_APR_AprVersionT_init(mrb_state* mrb);
#endif
#if BIND_AprVformatterBuffT_TYPE
void mrb_APR_AprVformatterBuffT_init(mrb_state* mrb);
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

mrb_value
mruby_box_apr_time_t(mrb_state* mrb, apr_time_t *unboxed);

mrb_value
mruby_giftwrap_apr_time_t(mrb_state* mrb, apr_time_t *unboxed);

void
mruby_set_apr_time_t_data_ptr(mrb_value obj, apr_time_t *unboxed);

void
mruby_gift_apr_time_t_data_ptr(mrb_value obj, apr_time_t *unboxed);

apr_time_t *
mruby_unbox_apr_time_t(mrb_value boxed);

#if BIND_AprAllocatorT_TYPE
mrb_value
mruby_box_apr_allocator_t(mrb_state* mrb, apr_allocator_t *unboxed);

mrb_value
mruby_giftwrap_apr_allocator_t(mrb_state* mrb, apr_allocator_t *unboxed);

void
mruby_set_apr_allocator_t_data_ptr(mrb_value obj, apr_allocator_t *unboxed);

void
mruby_gift_apr_allocator_t_data_ptr(mrb_value obj, apr_allocator_t *unboxed);

apr_allocator_t *
mruby_unbox_apr_allocator_t(mrb_value boxed);
#endif

#if BIND_AprArrayHeaderT_TYPE
mrb_value
mruby_box_apr_array_header_t(mrb_state* mrb, apr_array_header_t *unboxed);

mrb_value
mruby_giftwrap_apr_array_header_t(mrb_state* mrb, apr_array_header_t *unboxed);

void
mruby_set_apr_array_header_t_data_ptr(mrb_value obj, apr_array_header_t *unboxed);

void
mruby_gift_apr_array_header_t_data_ptr(mrb_value obj, apr_array_header_t *unboxed);

apr_array_header_t *
mruby_unbox_apr_array_header_t(mrb_value boxed);
#endif

#if BIND_AprCryptoHashT_TYPE
mrb_value
mruby_box_apr_crypto_hash_t(mrb_state* mrb, apr_crypto_hash_t *unboxed);

mrb_value
mruby_giftwrap_apr_crypto_hash_t(mrb_state* mrb, apr_crypto_hash_t *unboxed);

void
mruby_set_apr_crypto_hash_t_data_ptr(mrb_value obj, apr_crypto_hash_t *unboxed);

void
mruby_gift_apr_crypto_hash_t_data_ptr(mrb_value obj, apr_crypto_hash_t *unboxed);

apr_crypto_hash_t *
mruby_unbox_apr_crypto_hash_t(mrb_value boxed);
#endif

#if BIND_AprDirT_TYPE
mrb_value
mruby_box_apr_dir_t(mrb_state* mrb, apr_dir_t *unboxed);

mrb_value
mruby_giftwrap_apr_dir_t(mrb_state* mrb, apr_dir_t *unboxed);

void
mruby_set_apr_dir_t_data_ptr(mrb_value obj, apr_dir_t *unboxed);

void
mruby_gift_apr_dir_t_data_ptr(mrb_value obj, apr_dir_t *unboxed);

apr_dir_t *
mruby_unbox_apr_dir_t(mrb_value boxed);
#endif

#if BIND_AprDsoHandleT_TYPE
mrb_value
mruby_box_apr_dso_handle_t(mrb_state* mrb, apr_dso_handle_t *unboxed);

mrb_value
mruby_giftwrap_apr_dso_handle_t(mrb_state* mrb, apr_dso_handle_t *unboxed);

void
mruby_set_apr_dso_handle_t_data_ptr(mrb_value obj, apr_dso_handle_t *unboxed);

void
mruby_gift_apr_dso_handle_t_data_ptr(mrb_value obj, apr_dso_handle_t *unboxed);

apr_dso_handle_t *
mruby_unbox_apr_dso_handle_t(mrb_value boxed);
#endif

#if BIND_AprFileT_TYPE
mrb_value
mruby_box_apr_file_t(mrb_state* mrb, apr_file_t *unboxed);

mrb_value
mruby_giftwrap_apr_file_t(mrb_state* mrb, apr_file_t *unboxed);

void
mruby_set_apr_file_t_data_ptr(mrb_value obj, apr_file_t *unboxed);

void
mruby_gift_apr_file_t_data_ptr(mrb_value obj, apr_file_t *unboxed);

apr_file_t *
mruby_unbox_apr_file_t(mrb_value boxed);
#endif

#if BIND_AprFinfoT_TYPE
mrb_value
mruby_box_apr_finfo_t(mrb_state* mrb, apr_finfo_t *unboxed);

mrb_value
mruby_giftwrap_apr_finfo_t(mrb_state* mrb, apr_finfo_t *unboxed);

void
mruby_set_apr_finfo_t_data_ptr(mrb_value obj, apr_finfo_t *unboxed);

void
mruby_gift_apr_finfo_t_data_ptr(mrb_value obj, apr_finfo_t *unboxed);

apr_finfo_t *
mruby_unbox_apr_finfo_t(mrb_value boxed);
#endif

#if BIND_AprGetoptOptionT_TYPE
mrb_value
mruby_box_apr_getopt_option_t(mrb_state* mrb, apr_getopt_option_t *unboxed);

mrb_value
mruby_giftwrap_apr_getopt_option_t(mrb_state* mrb, apr_getopt_option_t *unboxed);

void
mruby_set_apr_getopt_option_t_data_ptr(mrb_value obj, apr_getopt_option_t *unboxed);

void
mruby_gift_apr_getopt_option_t_data_ptr(mrb_value obj, apr_getopt_option_t *unboxed);

apr_getopt_option_t *
mruby_unbox_apr_getopt_option_t(mrb_value boxed);
#endif

#if BIND_AprGetoptT_TYPE
mrb_value
mruby_box_apr_getopt_t(mrb_state* mrb, apr_getopt_t *unboxed);

mrb_value
mruby_giftwrap_apr_getopt_t(mrb_state* mrb, apr_getopt_t *unboxed);

void
mruby_set_apr_getopt_t_data_ptr(mrb_value obj, apr_getopt_t *unboxed);

void
mruby_gift_apr_getopt_t_data_ptr(mrb_value obj, apr_getopt_t *unboxed);

apr_getopt_t *
mruby_unbox_apr_getopt_t(mrb_value boxed);
#endif

#if BIND_AprHashIndexT_TYPE
mrb_value
mruby_box_apr_hash_index_t(mrb_state* mrb, apr_hash_index_t *unboxed);

mrb_value
mruby_giftwrap_apr_hash_index_t(mrb_state* mrb, apr_hash_index_t *unboxed);

void
mruby_set_apr_hash_index_t_data_ptr(mrb_value obj, apr_hash_index_t *unboxed);

void
mruby_gift_apr_hash_index_t_data_ptr(mrb_value obj, apr_hash_index_t *unboxed);

apr_hash_index_t *
mruby_unbox_apr_hash_index_t(mrb_value boxed);
#endif

#if BIND_AprHashT_TYPE
mrb_value
mruby_box_apr_hash_t(mrb_state* mrb, apr_hash_t *unboxed);

mrb_value
mruby_giftwrap_apr_hash_t(mrb_state* mrb, apr_hash_t *unboxed);

void
mruby_set_apr_hash_t_data_ptr(mrb_value obj, apr_hash_t *unboxed);

void
mruby_gift_apr_hash_t_data_ptr(mrb_value obj, apr_hash_t *unboxed);

apr_hash_t *
mruby_unbox_apr_hash_t(mrb_value boxed);
#endif

#if BIND_AprHdtrT_TYPE
mrb_value
mruby_box_apr_hdtr_t(mrb_state* mrb, apr_hdtr_t *unboxed);

mrb_value
mruby_giftwrap_apr_hdtr_t(mrb_state* mrb, apr_hdtr_t *unboxed);

void
mruby_set_apr_hdtr_t_data_ptr(mrb_value obj, apr_hdtr_t *unboxed);

void
mruby_gift_apr_hdtr_t_data_ptr(mrb_value obj, apr_hdtr_t *unboxed);

apr_hdtr_t *
mruby_unbox_apr_hdtr_t(mrb_value boxed);
#endif

#if BIND_AprIpsubnetT_TYPE
mrb_value
mruby_box_apr_ipsubnet_t(mrb_state* mrb, apr_ipsubnet_t *unboxed);

mrb_value
mruby_giftwrap_apr_ipsubnet_t(mrb_state* mrb, apr_ipsubnet_t *unboxed);

void
mruby_set_apr_ipsubnet_t_data_ptr(mrb_value obj, apr_ipsubnet_t *unboxed);

void
mruby_gift_apr_ipsubnet_t_data_ptr(mrb_value obj, apr_ipsubnet_t *unboxed);

apr_ipsubnet_t *
mruby_unbox_apr_ipsubnet_t(mrb_value boxed);
#endif

#if BIND_AprMemnodeT_TYPE
mrb_value
mruby_box_apr_memnode_t(mrb_state* mrb, apr_memnode_t *unboxed);

mrb_value
mruby_giftwrap_apr_memnode_t(mrb_state* mrb, apr_memnode_t *unboxed);

void
mruby_set_apr_memnode_t_data_ptr(mrb_value obj, apr_memnode_t *unboxed);

void
mruby_gift_apr_memnode_t_data_ptr(mrb_value obj, apr_memnode_t *unboxed);

apr_memnode_t *
mruby_unbox_apr_memnode_t(mrb_value boxed);
#endif

#if BIND_AprMmapT_TYPE
mrb_value
mruby_box_apr_mmap_t(mrb_state* mrb, apr_mmap_t *unboxed);

mrb_value
mruby_giftwrap_apr_mmap_t(mrb_state* mrb, apr_mmap_t *unboxed);

void
mruby_set_apr_mmap_t_data_ptr(mrb_value obj, apr_mmap_t *unboxed);

void
mruby_gift_apr_mmap_t_data_ptr(mrb_value obj, apr_mmap_t *unboxed);

apr_mmap_t *
mruby_unbox_apr_mmap_t(mrb_value boxed);
#endif

#if BIND_AprOsSockInfoT_TYPE
mrb_value
mruby_box_apr_os_sock_info_t(mrb_state* mrb, apr_os_sock_info_t *unboxed);

mrb_value
mruby_giftwrap_apr_os_sock_info_t(mrb_state* mrb, apr_os_sock_info_t *unboxed);

void
mruby_set_apr_os_sock_info_t_data_ptr(mrb_value obj, apr_os_sock_info_t *unboxed);

void
mruby_gift_apr_os_sock_info_t_data_ptr(mrb_value obj, apr_os_sock_info_t *unboxed);

apr_os_sock_info_t *
mruby_unbox_apr_os_sock_info_t(mrb_value boxed);
#endif

#if BIND_AprOtherChildRecT_TYPE
mrb_value
mruby_box_apr_other_child_rec_t(mrb_state* mrb, apr_other_child_rec_t *unboxed);

mrb_value
mruby_giftwrap_apr_other_child_rec_t(mrb_state* mrb, apr_other_child_rec_t *unboxed);

void
mruby_set_apr_other_child_rec_t_data_ptr(mrb_value obj, apr_other_child_rec_t *unboxed);

void
mruby_gift_apr_other_child_rec_t_data_ptr(mrb_value obj, apr_other_child_rec_t *unboxed);

apr_other_child_rec_t *
mruby_unbox_apr_other_child_rec_t(mrb_value boxed);
#endif

#if BIND_AprPollcbT_TYPE
mrb_value
mruby_box_apr_pollcb_t(mrb_state* mrb, apr_pollcb_t *unboxed);

mrb_value
mruby_giftwrap_apr_pollcb_t(mrb_state* mrb, apr_pollcb_t *unboxed);

void
mruby_set_apr_pollcb_t_data_ptr(mrb_value obj, apr_pollcb_t *unboxed);

void
mruby_gift_apr_pollcb_t_data_ptr(mrb_value obj, apr_pollcb_t *unboxed);

apr_pollcb_t *
mruby_unbox_apr_pollcb_t(mrb_value boxed);
#endif

#if BIND_AprPollfdT_TYPE
mrb_value
mruby_box_apr_pollfd_t(mrb_state* mrb, apr_pollfd_t *unboxed);

mrb_value
mruby_giftwrap_apr_pollfd_t(mrb_state* mrb, apr_pollfd_t *unboxed);

void
mruby_set_apr_pollfd_t_data_ptr(mrb_value obj, apr_pollfd_t *unboxed);

void
mruby_gift_apr_pollfd_t_data_ptr(mrb_value obj, apr_pollfd_t *unboxed);

apr_pollfd_t *
mruby_unbox_apr_pollfd_t(mrb_value boxed);
#endif

#if BIND_AprPollsetT_TYPE
mrb_value
mruby_box_apr_pollset_t(mrb_state* mrb, apr_pollset_t *unboxed);

mrb_value
mruby_giftwrap_apr_pollset_t(mrb_state* mrb, apr_pollset_t *unboxed);

void
mruby_set_apr_pollset_t_data_ptr(mrb_value obj, apr_pollset_t *unboxed);

void
mruby_gift_apr_pollset_t_data_ptr(mrb_value obj, apr_pollset_t *unboxed);

apr_pollset_t *
mruby_unbox_apr_pollset_t(mrb_value boxed);
#endif

#if BIND_AprPoolT_TYPE
mrb_value
mruby_box_apr_pool_t(mrb_state* mrb, apr_pool_t *unboxed);

mrb_value
mruby_giftwrap_apr_pool_t(mrb_state* mrb, apr_pool_t *unboxed);

void
mruby_set_apr_pool_t_data_ptr(mrb_value obj, apr_pool_t *unboxed);

void
mruby_gift_apr_pool_t_data_ptr(mrb_value obj, apr_pool_t *unboxed);

apr_pool_t *
mruby_unbox_apr_pool_t(mrb_value boxed);
#endif

#if BIND_AprProcMutexT_TYPE
mrb_value
mruby_box_apr_proc_mutex_t(mrb_state* mrb, apr_proc_mutex_t *unboxed);

mrb_value
mruby_giftwrap_apr_proc_mutex_t(mrb_state* mrb, apr_proc_mutex_t *unboxed);

void
mruby_set_apr_proc_mutex_t_data_ptr(mrb_value obj, apr_proc_mutex_t *unboxed);

void
mruby_gift_apr_proc_mutex_t_data_ptr(mrb_value obj, apr_proc_mutex_t *unboxed);

apr_proc_mutex_t *
mruby_unbox_apr_proc_mutex_t(mrb_value boxed);
#endif

#if BIND_AprProcT_TYPE
mrb_value
mruby_box_apr_proc_t(mrb_state* mrb, apr_proc_t *unboxed);

mrb_value
mruby_giftwrap_apr_proc_t(mrb_state* mrb, apr_proc_t *unboxed);

void
mruby_set_apr_proc_t_data_ptr(mrb_value obj, apr_proc_t *unboxed);

void
mruby_gift_apr_proc_t_data_ptr(mrb_value obj, apr_proc_t *unboxed);

apr_proc_t *
mruby_unbox_apr_proc_t(mrb_value boxed);
#endif

#if BIND_AprProcattrT_TYPE
mrb_value
mruby_box_apr_procattr_t(mrb_state* mrb, apr_procattr_t *unboxed);

mrb_value
mruby_giftwrap_apr_procattr_t(mrb_state* mrb, apr_procattr_t *unboxed);

void
mruby_set_apr_procattr_t_data_ptr(mrb_value obj, apr_procattr_t *unboxed);

void
mruby_gift_apr_procattr_t_data_ptr(mrb_value obj, apr_procattr_t *unboxed);

apr_procattr_t *
mruby_unbox_apr_procattr_t(mrb_value boxed);
#endif

#if BIND_AprRandomT_TYPE
mrb_value
mruby_box_apr_random_t(mrb_state* mrb, apr_random_t *unboxed);

mrb_value
mruby_giftwrap_apr_random_t(mrb_state* mrb, apr_random_t *unboxed);

void
mruby_set_apr_random_t_data_ptr(mrb_value obj, apr_random_t *unboxed);

void
mruby_gift_apr_random_t_data_ptr(mrb_value obj, apr_random_t *unboxed);

apr_random_t *
mruby_unbox_apr_random_t(mrb_value boxed);
#endif

#if BIND_AprShmT_TYPE
mrb_value
mruby_box_apr_shm_t(mrb_state* mrb, apr_shm_t *unboxed);

mrb_value
mruby_giftwrap_apr_shm_t(mrb_state* mrb, apr_shm_t *unboxed);

void
mruby_set_apr_shm_t_data_ptr(mrb_value obj, apr_shm_t *unboxed);

void
mruby_gift_apr_shm_t_data_ptr(mrb_value obj, apr_shm_t *unboxed);

apr_shm_t *
mruby_unbox_apr_shm_t(mrb_value boxed);
#endif

#if BIND_AprSkiplist_TYPE
mrb_value
mruby_box_apr_skiplist(mrb_state* mrb, apr_skiplist *unboxed);

mrb_value
mruby_giftwrap_apr_skiplist(mrb_state* mrb, apr_skiplist *unboxed);

void
mruby_set_apr_skiplist_data_ptr(mrb_value obj, apr_skiplist *unboxed);

void
mruby_gift_apr_skiplist_data_ptr(mrb_value obj, apr_skiplist *unboxed);

apr_skiplist *
mruby_unbox_apr_skiplist(mrb_value boxed);
#endif

#if BIND_AprSkiplistnode_TYPE
mrb_value
mruby_box_apr_skiplistnode(mrb_state* mrb, apr_skiplistnode *unboxed);

mrb_value
mruby_giftwrap_apr_skiplistnode(mrb_state* mrb, apr_skiplistnode *unboxed);

void
mruby_set_apr_skiplistnode_data_ptr(mrb_value obj, apr_skiplistnode *unboxed);

void
mruby_gift_apr_skiplistnode_data_ptr(mrb_value obj, apr_skiplistnode *unboxed);

apr_skiplistnode *
mruby_unbox_apr_skiplistnode(mrb_value boxed);
#endif

#if BIND_AprSockaddrT_TYPE
mrb_value
mruby_box_apr_sockaddr_t(mrb_state* mrb, apr_sockaddr_t *unboxed);

mrb_value
mruby_giftwrap_apr_sockaddr_t(mrb_state* mrb, apr_sockaddr_t *unboxed);

void
mruby_set_apr_sockaddr_t_data_ptr(mrb_value obj, apr_sockaddr_t *unboxed);

void
mruby_gift_apr_sockaddr_t_data_ptr(mrb_value obj, apr_sockaddr_t *unboxed);

apr_sockaddr_t *
mruby_unbox_apr_sockaddr_t(mrb_value boxed);
#endif

#if BIND_AprSocketT_TYPE
mrb_value
mruby_box_apr_socket_t(mrb_state* mrb, apr_socket_t *unboxed);

mrb_value
mruby_giftwrap_apr_socket_t(mrb_state* mrb, apr_socket_t *unboxed);

void
mruby_set_apr_socket_t_data_ptr(mrb_value obj, apr_socket_t *unboxed);

void
mruby_gift_apr_socket_t_data_ptr(mrb_value obj, apr_socket_t *unboxed);

apr_socket_t *
mruby_unbox_apr_socket_t(mrb_value boxed);
#endif

#if BIND_AprTableEntryT_TYPE
mrb_value
mruby_box_apr_table_entry_t(mrb_state* mrb, apr_table_entry_t *unboxed);

mrb_value
mruby_giftwrap_apr_table_entry_t(mrb_state* mrb, apr_table_entry_t *unboxed);

void
mruby_set_apr_table_entry_t_data_ptr(mrb_value obj, apr_table_entry_t *unboxed);

void
mruby_gift_apr_table_entry_t_data_ptr(mrb_value obj, apr_table_entry_t *unboxed);

apr_table_entry_t *
mruby_unbox_apr_table_entry_t(mrb_value boxed);
#endif

#if BIND_AprTableT_TYPE
mrb_value
mruby_box_apr_table_t(mrb_state* mrb, apr_table_t *unboxed);

mrb_value
mruby_giftwrap_apr_table_t(mrb_state* mrb, apr_table_t *unboxed);

void
mruby_set_apr_table_t_data_ptr(mrb_value obj, apr_table_t *unboxed);

void
mruby_gift_apr_table_t_data_ptr(mrb_value obj, apr_table_t *unboxed);

apr_table_t *
mruby_unbox_apr_table_t(mrb_value boxed);
#endif

#if BIND_AprThreadCondT_TYPE
mrb_value
mruby_box_apr_thread_cond_t(mrb_state* mrb, apr_thread_cond_t *unboxed);

mrb_value
mruby_giftwrap_apr_thread_cond_t(mrb_state* mrb, apr_thread_cond_t *unboxed);

void
mruby_set_apr_thread_cond_t_data_ptr(mrb_value obj, apr_thread_cond_t *unboxed);

void
mruby_gift_apr_thread_cond_t_data_ptr(mrb_value obj, apr_thread_cond_t *unboxed);

apr_thread_cond_t *
mruby_unbox_apr_thread_cond_t(mrb_value boxed);
#endif

#if BIND_AprThreadMutexT_TYPE
mrb_value
mruby_box_apr_thread_mutex_t(mrb_state* mrb, apr_thread_mutex_t *unboxed);

mrb_value
mruby_giftwrap_apr_thread_mutex_t(mrb_state* mrb, apr_thread_mutex_t *unboxed);

void
mruby_set_apr_thread_mutex_t_data_ptr(mrb_value obj, apr_thread_mutex_t *unboxed);

void
mruby_gift_apr_thread_mutex_t_data_ptr(mrb_value obj, apr_thread_mutex_t *unboxed);

apr_thread_mutex_t *
mruby_unbox_apr_thread_mutex_t(mrb_value boxed);
#endif

#if BIND_AprThreadOnceT_TYPE
mrb_value
mruby_box_apr_thread_once_t(mrb_state* mrb, apr_thread_once_t *unboxed);

mrb_value
mruby_giftwrap_apr_thread_once_t(mrb_state* mrb, apr_thread_once_t *unboxed);

void
mruby_set_apr_thread_once_t_data_ptr(mrb_value obj, apr_thread_once_t *unboxed);

void
mruby_gift_apr_thread_once_t_data_ptr(mrb_value obj, apr_thread_once_t *unboxed);

apr_thread_once_t *
mruby_unbox_apr_thread_once_t(mrb_value boxed);
#endif

#if BIND_AprThreadRwlockT_TYPE
mrb_value
mruby_box_apr_thread_rwlock_t(mrb_state* mrb, apr_thread_rwlock_t *unboxed);

mrb_value
mruby_giftwrap_apr_thread_rwlock_t(mrb_state* mrb, apr_thread_rwlock_t *unboxed);

void
mruby_set_apr_thread_rwlock_t_data_ptr(mrb_value obj, apr_thread_rwlock_t *unboxed);

void
mruby_gift_apr_thread_rwlock_t_data_ptr(mrb_value obj, apr_thread_rwlock_t *unboxed);

apr_thread_rwlock_t *
mruby_unbox_apr_thread_rwlock_t(mrb_value boxed);
#endif

#if BIND_AprThreadT_TYPE
mrb_value
mruby_box_apr_thread_t(mrb_state* mrb, apr_thread_t *unboxed);

mrb_value
mruby_giftwrap_apr_thread_t(mrb_state* mrb, apr_thread_t *unboxed);

void
mruby_set_apr_thread_t_data_ptr(mrb_value obj, apr_thread_t *unboxed);

void
mruby_gift_apr_thread_t_data_ptr(mrb_value obj, apr_thread_t *unboxed);

apr_thread_t *
mruby_unbox_apr_thread_t(mrb_value boxed);
#endif

#if BIND_AprThreadattrT_TYPE
mrb_value
mruby_box_apr_threadattr_t(mrb_state* mrb, apr_threadattr_t *unboxed);

mrb_value
mruby_giftwrap_apr_threadattr_t(mrb_state* mrb, apr_threadattr_t *unboxed);

void
mruby_set_apr_threadattr_t_data_ptr(mrb_value obj, apr_threadattr_t *unboxed);

void
mruby_gift_apr_threadattr_t_data_ptr(mrb_value obj, apr_threadattr_t *unboxed);

apr_threadattr_t *
mruby_unbox_apr_threadattr_t(mrb_value boxed);
#endif

#if BIND_AprThreadkeyT_TYPE
mrb_value
mruby_box_apr_threadkey_t(mrb_state* mrb, apr_threadkey_t *unboxed);

mrb_value
mruby_giftwrap_apr_threadkey_t(mrb_state* mrb, apr_threadkey_t *unboxed);

void
mruby_set_apr_threadkey_t_data_ptr(mrb_value obj, apr_threadkey_t *unboxed);

void
mruby_gift_apr_threadkey_t_data_ptr(mrb_value obj, apr_threadkey_t *unboxed);

apr_threadkey_t *
mruby_unbox_apr_threadkey_t(mrb_value boxed);
#endif

#if BIND_AprTimeExpT_TYPE
mrb_value
mruby_box_apr_time_exp_t(mrb_state* mrb, apr_time_exp_t *unboxed);

mrb_value
mruby_giftwrap_apr_time_exp_t(mrb_state* mrb, apr_time_exp_t *unboxed);

void
mruby_set_apr_time_exp_t_data_ptr(mrb_value obj, apr_time_exp_t *unboxed);

void
mruby_gift_apr_time_exp_t_data_ptr(mrb_value obj, apr_time_exp_t *unboxed);

apr_time_exp_t *
mruby_unbox_apr_time_exp_t(mrb_value boxed);
#endif

#if BIND_AprVersionT_TYPE
mrb_value
mruby_box_apr_version_t(mrb_state* mrb, apr_version_t *unboxed);

mrb_value
mruby_giftwrap_apr_version_t(mrb_state* mrb, apr_version_t *unboxed);

void
mruby_set_apr_version_t_data_ptr(mrb_value obj, apr_version_t *unboxed);

void
mruby_gift_apr_version_t_data_ptr(mrb_value obj, apr_version_t *unboxed);

apr_version_t *
mruby_unbox_apr_version_t(mrb_value boxed);
#endif

#if BIND_AprVformatterBuffT_TYPE
mrb_value
mruby_box_apr_vformatter_buff_t(mrb_state* mrb, apr_vformatter_buff_t *unboxed);

mrb_value
mruby_giftwrap_apr_vformatter_buff_t(mrb_state* mrb, apr_vformatter_buff_t *unboxed);

void
mruby_set_apr_vformatter_buff_t_data_ptr(mrb_value obj, apr_vformatter_buff_t *unboxed);

void
mruby_gift_apr_vformatter_buff_t_data_ptr(mrb_value obj, apr_vformatter_buff_t *unboxed);

apr_vformatter_buff_t *
mruby_unbox_apr_vformatter_buff_t(mrb_value boxed);
#endif


/*
 * Macro definition function declaration
 * -------------------------------------
 */
void mruby_APR_define_macro_constants(mrb_state* mrb);

#endif
