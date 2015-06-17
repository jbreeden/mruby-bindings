module APR

  module AprCmdtypeE
    Apr_Shellcmd = 0
    Apr_Program = 1
    Apr_Program_Env = 2
    Apr_Program_Path = 3
    Apr_Shellcmd_Env = 4
  end

  module AprDatatypeE
    Apr_No_Desc = 0
    Apr_Poll_Socket = 1
    Apr_Poll_File = 2
    Apr_Poll_Lastdesc = 3
  end

  module AprExitWhyE
    Apr_Proc_Exit = 1
    Apr_Proc_Signal = 2
    Apr_Proc_Signal_Core = 4
  end

  module AprFiletypeE
    Apr_Nofile = 0
    Apr_Reg = 1
    Apr_Dir = 2
    Apr_Chr = 3
    Apr_Blk = 4
    Apr_Pipe = 5
    Apr_Lnk = 6
    Apr_Sock = 7
    Apr_Unkfile = 127
  end

  module AprInterfaceE
    Apr_Local = 0
    Apr_Remote = 1
  end

  module AprKillConditionsE
    Apr_Kill_Never = 0
    Apr_Kill_Always = 1
    Apr_Kill_After_Timeout = 2
    Apr_Just_Wait = 3
    Apr_Kill_Only_Once = 4
  end

  module AprLockmechE
    Apr_Lock_Fcntl = 0
    Apr_Lock_Flock = 1
    Apr_Lock_Sysvsem = 2
    Apr_Lock_Proc_Pthread = 3
    Apr_Lock_Posixsem = 4
    Apr_Lock_Default = 5
  end

  module AprPollsetMethodE
    Apr_Pollset_Default = 0
    Apr_Pollset_Select = 1
    Apr_Pollset_Kqueue = 2
    Apr_Pollset_Port = 3
    Apr_Pollset_Epoll = 4
    Apr_Pollset_Poll = 5
    Apr_Pollset_Aio_Msgq = 6
  end

  module AprShutdownHowE
    Apr_Shutdown_Read = 0
    Apr_Shutdown_Write = 1
    Apr_Shutdown_Readwrite = 2
  end

  module AprWaitHowE
    Apr_Wait = 0
    Apr_Nowait = 1
  end

  self.apr_initialize
  @pool = nil
  def self.pool
    unless @pool
      err, @pool = self.apr_pool_create(nil)
    end
    @pool
  end
end
