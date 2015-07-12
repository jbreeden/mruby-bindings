TestFixture.new('APR API: Sockets') do
  err, @pool = APR.apr_pool_create(nil)

  def run_server
    err, proc_attr = APR.apr_procattr_create @pool
    APR.raise_apr_errno(err)

    APR.apr_procattr_cmdtype_set proc_attr, APR::AprCmdtypeE::APR_SHELLCMD
    err, argv = APR.apr_tokenize_to_argv "ruby ./specs/helpers/tcp_server.rb", @pool
    err, proc = APR.apr_proc_create "ruby", argv, nil, proc_attr, @pool
    APR.raise_apr_errno(err)
  end

  describe 'APR::apr_sockaddr_info_get' do
    it 'Creates a socket' do
      run_server

      #                                            Host         Family         Port  Flags Pool
      err, server_addr = APR.apr_sockaddr_info_get "localhost", APR::APR_INET, 8888, 0,    @pool
      APR.raise_apr_errno(err)

      err, client = APR.apr_socket_create(APR::APR_INET, APR::SOCK_STREAM, APR::APR_PROTO_TCP, @pool)
      APR.raise_apr_errno(err)

      try_count = 0
      begin
        err = APR.apr_socket_connect(client, server_addr)
        APR.raise_apr_errno(err)
      rescue Exception => ex
        if try_count < 5
          try_count += 1
          retry
        end
        raise ex
      end

      err, buf = APR.apr_socket_recv(client, 100)
      APR.raise_apr_errno(err)

      assert (buf == 'socket data')
    end
  end
end
