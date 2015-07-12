class PipeFile < File
  def initialize(apr_file, mode, pool)
    @native_file = apr_file
    @pool = pool
    @flags = File::Util.mode_str_to_flags(mode)
    @closed = false
  end

  attr_accessor :sibling

  def close
    APR.apr_file_flush(@native_file)
    APR.apr_file_close(@native_file)
    if @sibling.closed?
      # Don't want to destroy the pool until both siblings are closed,
      # since they belong to the same pool
      APR.apr_pool_destroy(@pool)
    end
    @closed = true
  end
end
