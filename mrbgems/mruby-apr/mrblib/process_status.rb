module Process
  class Status
    def initialize(pid, exit_status, apr_exit_why)
      @pid = pid
      @exitstatus = exit_status
      if apr_exit_why == APR::AprExitWhyE::APR_PROC_EXIT
        @exited = true
        @signaled = false
        @coredump = false
      elsif apr_exit_why == APR::AprExitWhyE::APR_PROC_SIGNAL
        @exited = false
        @signaled = true
        @coredump = false
      elsif apr_exit_why == APR::AprExitWhyE::APR_PROC_SIGNAL_CORE
        @exited = false
        @signaled = true
        @coredump = true
      else
        raise ArgumentError.new('Invalid apr_exit_why in param #3')
      end
    end

    def coredump?
      @coredump
    end

    def exitstatus
      @exitstatus
    end

    def exited?
      @exited
    end

    def pid
      @pid
    end

    def signaled?
      @signaled
    end

    def success?
      if @exited
        @exitstatus == 0
      else
        nil
      end
    end
  end
end
