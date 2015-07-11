#<
# # Module Kernel
#>
module Kernel
  #<
  # ## ``#`(command)``
  # Runs a process, waits for it to finish, and returns the exit code.
  # - Args
  #   + `command`. One of:
  #      - commandline : command line string which is passed to the standard shell
  #      - cmdname, arg1, ... : command name and one or more arguments (no shell)
  #>
  def `(command)
    err, pool = APR.apr_pool_create(nil)
    err, proc_attr = APR.apr_procattr_create pool
    APR.apr_procattr_cmdtype_set proc_attr, APR::AprCmdtypeE::APR_SHELLCMD_ENV
    APR.apr_procattr_io_set proc_attr, APR::APR_NO_PIPE, APR::APR_FULL_BLOCK, APR::APR_NO_PIPE
    err, argv = APR.apr_tokenize_to_argv command, pool

    err, process = APR.apr_proc_create argv[0], argv, nil, proc_attr, pool
    APR.raise_apr_errno(err)

    result = ""
    loop {
      err, str = APR.apr_file_read process.out, 100
      if err == APR::APR_SUCCESS || err == APR::APR_EOF
        result += str
        break if err == APR::APR_EOF
      else
        APR.raise_apr_errno(err)
      end
    }

    APR.apr_file_close(process.out)
    APR.apr_pool_destroy(pool)
    result
  end
end
