TestFixture.new('APR API: Time') do
  err, @pool = APR::apr_pool_create nil

  def check_errno(errno)
    unless assert(errno == 0)
      raise APR.apr_strerror(errno)
    end
  end

  describe 'APR::apr_time_now(pool: AprPoolT): time: AprTimeT' do
    it 'Gets the current time' do
      time = APR.apr_time_now 0
      err, time_s = APR.apr_ctime(time)

      check_errno(err)
      assert(0 == APR.apr_fnmatch("*[0-9][0-9]:[0-9][0-9]:[0-9][0-9]*", time_s, 0))
    end
  end

  APR::apr_pool_destroy(@pool)
end
