# Note:
# I know, it's evil, but these tests are very much order dependent.

TestFixture.new('APR API: File IO') do
  err, @pool = APR::apr_pool_create nil
  @ug_rw = 0x660 # Probably going to be "umasked" to 640

  @str_with_null = "BeforeNull\x00AfterNull"

  def check_errno(errno)
    unless assert(errno == 0)
      raise APR.apr_strerror(errno)
    end
  end

  describe 'APR::apr_file_open(name: String, mode: Fixnum, permissions: Fixnum, pool: AprPoolT): [errno: Fixnum, file: AprFileT]' do
    it 'Can open a file for writing' do
      err, file = APR.apr_file_open 'sandbox/test.txt',
        APR::APR_FOPEN_CREATE | APR::APR_FOPEN_WRITE | APR::APR_FOPEN_TRUNCATE, @ug_rw, @pool
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))
      APR.apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end

    it 'Can open a file for reading' do
      err, file = APR.apr_file_open 'sandbox/test.txt', APR::APR_FOPEN_READ, 0, @pool
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))
      APR.apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_puts(buf: String, file: AprFileT)' do
    it 'Can write to an open, writable, file' do
      err, file = APR.apr_file_open 'sandbox/test.txt',
        APR::APR_FOPEN_CREATE | APR::APR_FOPEN_WRITE | APR::APR_FOPEN_TRUNCATE, @ug_rw, @pool
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      err = APR.apr_file_puts('This is a test', file)
      check_errno(err)

      APR.apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_gets(at_most_n_bytes: Fixnum, file: AprFileT): [errno: Fixnum, str: String]' do
    it 'Reads length (1st param) characters and returns the string' do
      err, file = APR.apr_file_open 'sandbox/test.txt', APR::APR_FOPEN_READ, 0, @pool
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      err, str = APR.apr_file_gets('This is a test'.length, file)
      check_errno(err)
      assert (str == 'This is a test')

      APR::apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end

    it 'Reads as many characters as possible when length is beyond EOF' do
      err, file = APR.apr_file_open 'sandbox/test.txt', APR::APR_FOPEN_READ, 0, @pool
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      err, str = APR.apr_file_gets('This is a test'.length * 10, file)
      assert (err == 0 && str == 'This is a test')

      APR::apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_write(file: AprFileT, buffer: String, num_bytes: Fixnum): [errno: Fixnum, bytes_written: Fixnum]' do
    it 'Can write strings with nulls to a file' do
      err, file = APR.apr_file_open('sandbox/test.txt',
        APR::APR_FOPEN_CREATE | APR::APR_FOPEN_WRITE | APR::APR_FOPEN_TRUNCATE, @ug_rw, @pool)
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      buf = @str_with_null
      length = @str_with_null.length
      err, bytes_written = APR::apr_file_write(file, buf, length)

      check_errno(err)
      assert (bytes_written == length)

      APR::apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_read(file: AprFileT, Fixnum: num_bytes): [errno: Fixnum, str: String]' do
    it 'Can read strings with nulls from a file' do
      err, file = APR.apr_file_open('sandbox/test.txt', APR::APR_FOPEN_READ, 0, @pool)
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      err, str = APR::apr_file_read(file, 100)
      check_errno(err)
      assert (str.length == @str_with_null.length)

      APR::apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end

    it 'Returns EOF on first attempt to read past EOF' do
      err, file = APR.apr_file_open('sandbox/test.txt', APR::APR_FOPEN_READ, 0, @pool)
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      err, str = APR::apr_file_read(file, 100)
      check_errno(err)
      assert (str.length == @str_with_null.length)

      err, str = APR::apr_file_read(file, 100)
      assert(err == APR::APR_EOF)

      APR::apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_close(file: AprFileT): errno: Fixnum' do
    it 'Closes an AprFileT' do
      # No explicit tests yet, this is just here for the output.
    end
  end

  describe 'APR::apr_file_seek(thefile: AprFileT, where: Fixnum, offset: Fixnum): [errno: Fixnum, resulting_offset: Fixnum]' do
    it 'Can seek back from the end of the file' do
      err, file = APR.apr_file_open('sandbox/test.txt', APR::APR_FOPEN_READ, 0, @pool)
      check_errno(err)
      assert (file.kind_of?(APR::AprFileT))

      err, offset = APR.apr_file_seek(file, APR::APR_END, -4);
      check_errno(err)
      assert (offset == 16)

      err, str = APR::apr_file_read(file, 10)
      check_errno(err)
      assert (str == 'Null')

      err = APR.apr_file_close(file)
      check_errno(err)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_copy(from_path: String, to_path: String, perms: int, pool: AprPoolType): errno: Fixnum' do
    it 'Copies files by name' do
      err = APR.apr_file_copy("sandbox/test.txt", "sandbox/test_copy.txt", @ug_rw, @pool)
      check_errno(err)

      err, file = APR::apr_file_open("sandbox/test_copy.txt", APR::APR_FOPEN_READ, 0, @pool)
      check_errno(err)

      APR.apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_rename(from_path: String, to_path: String, pool: AprPoolType): errno: Fixnum' do
    it 'Renames a file' do
      err = APR.apr_file_rename("sandbox/test_copy.txt", "sandbox/test_renamed.txt", @pool)
      check_errno(err)

      err, file = APR::apr_file_open("sandbox/test_renamed.txt", APR::APR_FOPEN_READ, 0, @pool)
      check_errno(err)

      APR.apr_file_close(file)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_remove(from_path: String, to_path: String, perms: int, pool: AprPoolType): errno: Fixnum' do
    it 'Removes a file' do
      err = APR.apr_file_remove("sandbox/test_renamed.txt", @pool)
      check_errno(err)

      err, file = APR::apr_file_open("sandbox/test_renamed.txt", APR::APR_FOPEN_READ, 0, @pool)
      assert (err != 0)
      APR.apr_pool_clear(@pool)
    end
  end

  describe 'APR::apr_file_lock(file: AprFileT, lock_type: Fixnum): errno: Fixnum' do
    it 'Locks a file (either flock or iocntl based, depending on platform)' do
      # Only manual testing until process functions are available, this is just here for the output.
    end
  end

  describe 'APR::apr_file_unlock(file: AprFileT): errno: Fixnum' do
    it 'Unlocks a file (either flock or iocntl based, depending on platform)' do
      # Only manual testing until process functions are available, this is just here for the output.
    end
  end

  describe 'APR::apr_file_attrs_set(fname: String, attrs: Fixnum, attr_mask: Fixnum, pool: AprPoolT): errno: Fixnum' do
    it 'Sets attributes on a file' do
      # Only manual testing until process functions are available, this is just here for the output.
    end
  end

  APR::apr_pool_destroy(@pool)
end
