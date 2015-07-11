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

      if command[command.length -1].class == Hash
        options = command.pop
      end

      if command.length == 1 && command[0].class == String
        err, argv = APR.apr_tokenize_to_argv(command[0], pool)
        #argv = command
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

      puts cmd_type == APR::AprCmdtypeE::APR_SHELLCMD_ENV
      puts cmd_type == APR::AprCmdtypeE::APR_PROGRAM_ENV
      puts argv

      APR.apr_procattr_cmdtype_set proc_attr, cmd_type

      # TODO: Configure environment variables from env hash
      # TODO: Determine pipe settings from options hash
      APR.apr_procattr_io_set proc_attr, APR::APR_NO_PIPE, APR::APR_NO_PIPE, APR::APR_NO_PIPE

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
