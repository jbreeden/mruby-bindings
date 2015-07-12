class IO
  def self.pipe
    err, pool = APR.apr_pool_create(nil)
    APR.raise_apr_errno(err)

    err, readEnd, writeEnd = APR.apr_file_pipe_create pool
    APR.raise_apr_errno(err)

    read_file = PipeFile.new(readEnd, 'r', pool)
    write_file = PipeFile.new(writeEnd, 'w', pool)

    # tell them about eachother so they can destroy the shared pool correctly
    read_file.sibling = write_file
    write_file.sibling = read_file

    [read_file, write_file]
  end
end
