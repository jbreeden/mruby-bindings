# mruby-bindings
Generates MRuby bindings from C Header files via libclang

# Requirements
[clang2json](https://github.com/jbreeden/clang2json)

# Usage
TODO: I'll fill this out after I've done more testing and solidified the output format.
Currently using it to generate bindings for dependencies of the [lamina](https://github.com/jbreeden/lamina) project.
This include Apache's APR, nanomsg, and maybe some CEF stuff. The new bindings will replace the limited hand-written
bindings that are currently used.

# Details

It should be close to complete & stable. Still need to work through function pointers. Structs, enums, functions, typedefs, 
classes, methods, and macros are currently supported. Generated bindings include type checking and a convenient macro system to configure the bindings.

Have a peek at the [APR bindings](https://github.com/jbreeden/mruby-bindings/tree/master/apr_bindings) if you're curious what the output looks like.

The supported functions for APR are listed below. Many of these bindings are exactly as generated. Others required minor tweaks (like changing "output parameters" - passed in as pointers - to return values, since there is not way for the generator to know the intentions of the library's API in that regard).

```Ruby
# Supported APR functions
apr_ctime
apr_dir_close
apr_dir_make
apr_dir_make_recursive
apr_dir_open
apr_dir_read
apr_dir_remove
apr_dir_rewind
apr_env_delete
apr_env_get
apr_env_set
apr_file_append
apr_file_attrs_set
apr_file_buffer_size_get
apr_file_close
apr_file_copy
apr_file_datasync
apr_file_eof
apr_file_flags_get
apr_file_flush
apr_file_gets
apr_file_link
apr_file_lock
apr_file_namedpipe_create
apr_file_open
apr_file_open_stderr
apr_file_open_stdin
apr_file_open_stdout
apr_file_perms_set
apr_file_pipe_create
apr_file_puts
apr_file_read
apr_file_remove
apr_file_rename
apr_file_seek
apr_file_sync
apr_file_trunc
apr_file_unlock
apr_file_write
apr_filepath_name_get
apr_fnmatch
apr_fnmatch_test
apr_initialize
apr_os_default_encoding
apr_os_locale_encoding
apr_pool_clear
apr_pool_create
apr_pool_destroy
apr_proc_create
apr_proc_detach
apr_proc_wait
apr_procattr_addrspace_set
apr_procattr_child_err_set
apr_procattr_child_in_set
apr_procattr_child_out_set
apr_procattr_cmdtype_set
apr_procattr_create
apr_procattr_detach_set
apr_procattr_dir_set
apr_procattr_error_check_set
apr_procattr_group_set
apr_procattr_io_set
apr_procattr_user_set
apr_strerror
apr_temp_dir_get
apr_terminate
apr_terminate2
apr_time_now
apr_tokenize_to_argv
```
