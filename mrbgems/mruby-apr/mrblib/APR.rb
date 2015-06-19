module APR
  APR.apr_initialize

  module AprCmdtypeE
    APR_SHELLCMD = 0
    APR_PROGRAM = 1
    APR_PROGRAM_ENV = 2
    APR_PROGRAM_PATH = 3
    APR_SHELLCMD_ENV = 4
  end

  module AprDatatypeE
    APR_NO_DESC = 0
    APR_POLL_SOCKET = 1
    APR_POLL_FILE = 2
    APR_POLL_LASTDESC = 3
  end

  module AprExitWhyE
    APR_PROC_EXIT = 1
    APR_PROC_SIGNAL = 2
    APR_PROC_SIGNAL_CORE = 4
  end

  module AprFiletypeE
    APR_NOFILE = 0
    APR_REG = 1
    APR_DIR = 2
    APR_CHR = 3
    APR_BLK = 4
    APR_PIPE = 5
    APR_LNK = 6
    APR_SOCK = 7
    APR_UNKFILE = 127
  end

  module AprInterfaceE
    APR_LOCAL = 0
    APR_REMOTE = 1
  end

  module AprKillConditionsE
    APR_KILL_NEVER = 0
    APR_KILL_ALWAYS = 1
    APR_KILL_AFTER_TIMEOUT = 2
    APR_JUST_WAIT = 3
    APR_KILL_ONLY_ONCE = 4
  end

  module AprLockmechE
    APR_LOCK_FCNTL = 0
    APR_LOCK_FLOCK = 1
    APR_LOCK_SYSVSEM = 2
    APR_LOCK_PROC_PTHREAD = 3
    APR_LOCK_POSIXSEM = 4
    APR_LOCK_DEFAULT = 5
  end

  module AprPollsetMethodE
    APR_POLLSET_DEFAULT = 0
    APR_POLLSET_SELECT = 1
    APR_POLLSET_KQUEUE = 2
    APR_POLLSET_PORT = 3
    APR_POLLSET_EPOLL = 4
    APR_POLLSET_POLL = 5
    APR_POLLSET_AIO_MSGQ = 6
  end

  module AprShutdownHowE
    APR_SHUTDOWN_READ = 0
    APR_SHUTDOWN_WRITE = 1
    APR_SHUTDOWN_READWRITE = 2
  end

  module AprWaitHowE
    APR_WAIT = 0
    APR_NOWAIT = 1
  end
end
