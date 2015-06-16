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

  APR_FOPEN_READ = 0x00001  # Open the file for reading
  APR_FOPEN_WRITE = 0x00002  # Open the file for writing */
  APR_FOPEN_CREATE = 0x00004  # Create the file if not there */
  APR_FOPEN_APPEND = 0x00008  # Append to the end of the file */
  APR_FOPEN_TRUNCATE = 0x00010  # Open the file and truncate to 0 length */
  APR_FOPEN_BINARY = 0x00020  # Open the file in binary mode (This flag is ignored on UNIX because it has no meaning)*/
  APR_FOPEN_EXCL = 0x00040  # Open should fail if #APR_FOPEN_CREATE and file exists. */
  APR_FOPEN_BUFFERED = 0x00080  # Open the file for buffered I/O
  APR_FOPEN_DELONCLOSE = 0x00100  # Delete the file after close
  APR_FOPEN_XTHREAD = 0x00200  # Platform dependent tag to open the file for use across multiple threads */
  APR_FOPEN_SHARELOCK = 0x00400  # Platform dependent support for higher level locked read/write access to support writes across process/machines */
  APR_FOPEN_NOCLEANUP = 0x00800  # Do not register a cleanup when the file is opened. The apr_os_file_t handle in apr_file_t will not be closed when the pool is destroyed. */
  APR_FOPEN_SENDFILE_ENABLED = 0x01000 # Advisory flag that this file should support apr_socket_sendfile operation */
  APR_FOPEN_LARGEFILE = 0x04000 # Platform dependent flag to enable large file support
  APR_FOPEN_SPARSE = 0x08000 # Platform dependent flag to enable
  APR_FOPEN_NONBLOCK = 0x40000 # Platform dependent flag to enable non blocking file io */
end
