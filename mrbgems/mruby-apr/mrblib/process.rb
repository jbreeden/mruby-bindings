module Process
  # No real privates in mruby, so use a sub module for some sort of hiding
  module Util

    def self.parse_spawn_args(*command, pool)
      env = nil
      options = nil;

      if command.length == 0
        raise ArgumentError.new('Wrong number of arguments (0 for 1+)')
      end

      if command[0].class == Hash
        env = command.shift
      end

      if command.last.class == Hash
        options = command.pop
      end

      if command.length == 1 && command[0].class == String
        err, argv = APR.apr_tokenize_to_argv(command[0], pool)
        # TODO: Remove this when this bug is resolved & apr is updated
        # https://bz.apache.org/bugzilla/show_bug.cgi?id=58123
        argv = argv.map { |a|
          if a.include?(' ') || a.include?("\t")
            "\"#{a}\""
          else
            a
          end
        }

        { env: env, argv: argv, options: options, cmd_type: APR::AprCmdtypeE::APR_SHELLCMD_ENV }
      elsif command[0].class == Array
        if command[0].length != 2
          raise ArgumentError.new('wrong first argument')
        end
        { env: env, argv: [command[0][0], command[0][1]].concat(command[1..(command.length)]), options: options, cmd_type: APR::AprCmdtypeE::APR_PROGRAM_ENV }
      else
        { env: env, argv: command, options: options, cmd_type: APR::AprCmdtypeE::APR_PROGRAM_ENV }
      end
    end
  end

  def self.spawn(*command)
    # Going to mutate this, don't want to mess with client's copy
    command = command.dup

    APR.with_pool do |pool|
      err, proc_attr = APR.apr_procattr_create pool
      args = Util.parse_spawn_args(*command, pool)
      env = args[:env]
      argv = args[:argv]
      options = args[:options]
      cmd_type = args[:cmd_type]

      APR.apr_procattr_cmdtype_set proc_attr, cmd_type

      # TODO: Configure environment variables from env hash

      in_io = APR::APR_NO_PIPE
      out_io = APR::APR_NO_PIPE
      err_io = APR::APR_NO_PIPE
      if options
        if options[:in]
          # Using instance variable get to avoid exposing non standard `native_file` field on File class
          err = APR.apr_procattr_child_in_set proc_attr, nil, options[:in].instance_variable_get(:@native_file)
          APR.raise_apr_errno(err)
          in_io = APR::APR_FULL_BLOCK
        end
        if options[:out]
          err = APR.apr_procattr_child_out_set proc_attr, options[:out].instance_variable_get(:@native_file), nil
          APR.raise_apr_errno(err)
          out_io = APR::APR_FULL_BLOCK
        end
        if options[:err]
          err = APR.apr_procattr_child_err_set proc_attr, options[:err].instance_variable_get(:@native_file), nil
          APR.raise_apr_errno(err)
          err_io = APR::APR_FULL_BLOCK
        end
      end

      err, process = APR.apr_proc_create argv[0], argv, nil, proc_attr, pool
      APR.raise_apr_errno(err)

      process.pid
    end
  end

  def self.wait(pid)
    proc = APR.apr_proc_from_pid(pid)
    err, exit_code, exit_why = APR.apr_proc_wait(proc, APR::AprWaitHowE::APR_WAIT)
    $? = Process::Status.new(pid, exit_code, exit_why)
    return pid
  end
end
