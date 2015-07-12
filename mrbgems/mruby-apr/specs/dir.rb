TestFixture.new('APR API: Directories') do
  err, @pool = APR::apr_pool_create nil
  @a_rwx = 0x070707

  def check_errno(errno)
    unless assert(errno == 0)
      raise "ERRNO(#{errno}) #{APR.apr_strerror(errno)}"
    end
  end

  describe 'APR::apr_dir_open(path: String, pool: AprPoolType): [errno: Fixnum, dir: AprDirT]' do
    it 'Gets file information for each entry in the directory' do
      err, dir = APR.apr_dir_open '.', @pool
      check_errno(err)
      APR.apr_dir_close dir
    end
  end

  describe 'APR::apr_dir_read(finfo: AprFinfoT, wanted: Fixnum, dir: AprDirT): errno: Fixnum' do
    it 'Gets file information for each entry in the directory' do
      err, dir = APR.apr_dir_open '.', @pool
      check_errno(err)

      time_pattern = "*[0-9][0-9]:[0-9][0-9]:[0-9][0-9]*"

      err, finfo = APR.apr_dir_read 0, dir

      found_cwd = false
      found_parnet = false
      while err == 0 || err == 70008
        # Just checking the access, modification, and creation times, since these should be available
        assert(0 == APR.apr_fnmatch(time_pattern, APR.apr_ctime(finfo.atime)[1], 0))
        assert(0 == APR.apr_fnmatch(time_pattern, APR.apr_ctime(finfo.mtime)[1], 0))
        assert(0 == APR.apr_fnmatch(time_pattern, APR.apr_ctime(finfo.ctime)[1], 0))
        found_cwd ||= (finfo.name == '.')
        found_parent ||= (finfo.name == '..')

        err, finfo = APR.apr_dir_read 0, dir
      end
      assert (found_parent && found_cwd)
      APR.apr_dir_close dir
    end
  end

  describe 'APR::apr_dir_make(path: String, permissions: Fixnum, pool: AprPoolType): errno: Fixnum' do
    it 'Creates a directory' do
      err = APR.apr_dir_make 'sandbox/test_create_dir', @a_rwx, @pool
      check_errno(err)
      err, dir = APR.apr_dir_open('sandbox/test_create_dir', @pool)
      check_errno(err)
    end
  end

  describe 'APR::apr_dir_make_recursive(path: String, permissions: Fixnum, pool: AprPoolType): errno: Fixnum' do
    it 'Creates a directory and any required parent directories' do
      err = APR.apr_dir_make_recursive 'sandbox/test_create_dir/some/nested/dir', @a_rwx, @pool
      check_errno(err)
      err, dir = APR.apr_dir_open('sandbox/test_create_dir/some/nested/dir', @pool)
      check_errno(err)
      APR.apr_dir_close(dir)
    end
  end

  describe 'APR::apr_dir_remove(path: String, pool: AprPoolType): errno: Fixnum' do
    it 'Deletes a directory' do
      err = APR.apr_dir_remove 'sandbox/test_create_dir/some/nested/dir', @pool
      check_errno(err)
      err = APR.apr_dir_remove 'sandbox/test_create_dir/some/nested', @pool
      check_errno(err)
      err = APR.apr_dir_remove 'sandbox/test_create_dir/some/', @pool
      check_errno(err)
      err = APR.apr_dir_remove 'sandbox/test_create_dir', @pool
    end
  end

  APR::apr_pool_destroy(@pool)
end
