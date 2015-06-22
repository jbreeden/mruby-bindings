TestFixture.new('Sockets') do
  err, @pool = APR.apr_pool_create(nil)

  def check_errno(errno)
    unless assert(errno == 0)
      raise "ERRNO(#{errno}) #{APR.apr_strerror(errno)}"
    end
  end

  def run_server
    err, proc_attr = APR.apr_procattr_create @pool
    check_errno(err)

    APR.apr_procattr_cmdtype_set proc_attr, APR::AprCmdtypeE::APR_SHELLCMD
    err, argv = APR.apr_tokenize_to_argv "ruby ./specs/helpers/tcp_server.rb", @pool
    err, proc = APR.apr_proc_create "ruby", argv, nil, proc_attr, @pool
    check_errno(err)
  end

  describe 'APR::apr_sockaddr_info_get' do
    it 'Creates a socket' do
      run_server

      #                                            Host         Family         Port  Flags Pool
      err, server_addr = APR.apr_sockaddr_info_get "localhost", APR::APR_INET, 8888, 0,    @pool
      check_errno(err)

      err, client = APR.apr_socket_create(APR::APR_INET, APR::SOCK_STREAM, APR::APR_PROTO_TCP, @pool)
      check_errno(err)

      err = APR.apr_socket_connect(client, server_addr)
      check_errno(err)

      err, buf = APR.apr_socket_recv(client, 100)

      assert (buf == 'socket data')
    end
  end
end
