TestFixture.new('nanomsg') do
  def setup_sockets protocol, bindings
    # AF_SP: "Assured forwarding scalability protocol"
    err, node0 = NN.nn_socket NN::AF_SP, protocol
    assert(err == 0)
    err, node1 = NN.nn_socket NN::AF_SP, protocol
    assert(err == 0)

    err, endpoint = NN.nn_bind(node0, "tcp://127.0.0.1:8888")
    assert(err == 0)
    err, endpoint = NN.nn_bind(node1, "tcp://127.0.0.1:8889")
    assert(err == 0)
    err, endpoint = NN.nn_connect(node0, "tcp://127.0.0.1:8889")
    assert(err == 0)
    err, endpoint = NN.nn_connect(node1, "tcp://127.0.0.1:8888")
    assert(err == 0)

    [node0, node1]
  end

  describe 'NN_PAIR Protocol' do
    it 'Allows peer-to-peer communication over tcp' do
      addr1 = "tcp://127.0.0.1:8888"
      addr2 = "tcp://127.0.0.1:8889"
      node0, node1 = setup_sockets(NN::NN_PAIR,
        NN::NN_PAIR => {addr1 => addr2},
        addr2 => addr1)

      msg = "message"

      err, bytes_sent = NN.nn_send(node0, msg, 0)
      assert(err == 0 && bytes_sent == msg.length)

      err, received_msg = NN.nn_recv(node1, 0)
      assert (received_msg == msg)

      NN.nn_close(node0)
      NN.nn_close(node1)
    end
  end

  describe 'NNSocket class' do
    it 'Provides an OO interface to nanomsg' do
      sockets = (0..1).map do |i|
        s = NNSocket.new(NN::NN_PAIR)
        s.bind("tcp://127.0.0.1:888#{ 8 + i}")
        s
      end
      sockets[0].connect(sockets[1].address)
      sockets[1].connect(sockets[0].address)

      msg = "message"
      sockets[0].send(msg)
      received = sockets[1].recv

      assert (received[1] == msg)
    end
  end
end
