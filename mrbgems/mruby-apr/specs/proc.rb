TestFixture.new('APR API: Processes') do
  err, @pool = APR::apr_pool_create nil

  def check_errno(errno)
    unless assert(errno == 0)
      raise "ERRNO(#{errno}) #{APR.apr_strerror(errno)}"
    end
  end

  describe 'APR::apr_proc_create(command: String, argv: Array<String>, env: Array<String>, proc_attr: AprProcattrT, pool: AprPoolT): [errno: Fixnum, proc: AprProcT]' do
    it 'Can run a shell command and redirect output to a file' do
      err, proc_attr = APR.apr_procattr_create @pool
      check_errno(err)

      err = APR.apr_procattr_cmdtype_set proc_attr, APR::AprCmdtypeE::APR_SHELLCMD_ENV
      check_errno(err)

      err, file = APR.apr_file_open "sandbox/echo_out.txt",
        APR::APR_FOPEN_CREATE | APR::APR_FOPEN_WRITE | APR::APR_FOPEN_TRUNCATE,
        APR::APR_FPROT_OS_DEFAULT,
        @pool
      check_errno(err)

      err = APR.apr_procattr_child_out_set proc_attr, file, nil
      check_errno(err)

      err, argv = APR.apr_tokenize_to_argv "echo this string of args", @pool
      assert(argv.length == 5)
      check_errno(err)

      err, process = APR.apr_proc_create "echo", argv, nil, proc_attr, @pool
      check_errno(err)

      err, exitcode, exitwhy = APR.apr_proc_wait process, APR::AprWaitHowE::APR_WAIT

      APR.apr_file_close(file)

      err, file = APR.apr_file_open "sandbox/echo_out.txt", APR::APR_FOPEN_READ, 0, @pool
      check_errno(err)

      err, str = APR.apr_file_read file, 100
      check_errno err
      # strip newline from echo before compare
      assert (str.strip == "this string of args")
      APR.apr_file_close(file)
    end

    it 'Can run a shell command and pipe output to parent via APR.apr_file_pipe_create' do
      err, proc_attr = APR.apr_procattr_create @pool
      check_errno(err)

      err = APR.apr_procattr_cmdtype_set proc_attr, APR::AprCmdtypeE::APR_SHELLCMD_ENV
      check_errno(err)

      err, readEnd, writeEnd = APR.apr_file_pipe_create @pool

      # Passing pipe ends:                            child,    parent
      err = APR.apr_procattr_child_out_set proc_attr, writeEnd, readEnd
      check_errno(err)

      err, argv = APR.apr_tokenize_to_argv "echo this string of args", @pool
      assert(argv.length == 5)
      check_errno(err)

      err, process = APR.apr_proc_create "echo", argv, nil, proc_attr, @pool
      check_errno(err)

      rr, str = APR.apr_file_read readEnd, 100
      check_errno err
      # strip newline from echo before compare
      assert (str.strip == "this string of args")

      APR.apr_file_close(readEnd)

      err, exitcode, exitwhy = APR.apr_proc_wait process, APR::AprWaitHowE::APR_WAIT
    end
  end

  describe "APR::apr_procattr_io_set(procattr: AprProcattrT, in: Fixnum, out: Fixnum, err: Fixnum): errno: Fixnum" do
    it 'Can automatically create pipes between the parent and child processes (for std in, out, & err)' do
      err, proc_attr = APR.apr_procattr_create @pool
      check_errno(err)

      err = APR.apr_procattr_cmdtype_set proc_attr, APR::AprCmdtypeE::APR_SHELLCMD_ENV
      check_errno(err)

      #                                  in                out                  err
      APR.apr_procattr_io_set proc_attr, APR::APR_NO_PIPE, APR::APR_FULL_BLOCK, APR::APR_NO_PIPE

      err, argv = APR.apr_tokenize_to_argv "echo this string of args", @pool
      assert(argv.length == 5)
      check_errno(err)

      err, process = APR.apr_proc_create "echo", argv, nil, proc_attr, @pool
      check_errno(err)

      err, str = APR.apr_file_read process.out, 100
      check_errno err
      # strip newline from echo before compare
      assert (str.strip == "this string of args")

      APR.apr_file_close(process.out)

      err, exitcode, exitwhy = APR.apr_proc_wait process, APR::AprWaitHowE::APR_WAIT
    end
  end

  APR::apr_pool_destroy(@pool)
end
