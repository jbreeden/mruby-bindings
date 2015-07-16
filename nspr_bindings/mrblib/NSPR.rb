module NSPR

  module Ploptstatus
    PL_OPT_OK = 0
    PL_OPT_EOL = 1
    PL_OPT_BAD = 2
  end

  module Prstatus
    PR_FAILURE = -1
    PR_SUCCESS = 0
  end

  module Prsysinfo
    PR_SI_HOSTNAME = 0
    PR_SI_SYSNAME = 1
    PR_SI_RELEASE = 2
    PR_SI_ARCHITECTURE = 3
    PR_SI_HOSTNAME_UNTRUNCATED = 4
  end
end
