# No Errno module yet, no subclasses, just SystemCallError with messages & numbers
# (There is already an mrbgem for this, I just don't want a dependency at the moment)
class SystemCallError < StandardError
  def initialize(msg, errno)
    super(msg)
    @errno = errno
  end

  def errno
    @errno
  end
end
