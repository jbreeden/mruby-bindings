# Note:
# I know, it's evil, but these tests are very much order dependent.

TestFixture.new('Directories') do
  APR::apr_initialize
  err, @pool = APR::apr_pool_create nil

  def check_errno(errno)
    unless assert(errno == 0)
      raise APR.apr_strerror(errno)
    end
  end

  describe 'APR::apr_dir_read(finfo: AprFinfoT, wanted: Fixnum, dir: AprDirT): errno: Fixnum' do
    it 'Gets file information for each entry in the directory' do
      err, dir = APR.apr_dir_open '.', @pool
      check_errno(err)

      err, finfo = APR.apr_dir_read 0, dir

      puts "atime: #{APR.apr_ctime(finfo.atime)[1]}"
    end
  end

  APR::apr_pool_destroy(@pool)
end
