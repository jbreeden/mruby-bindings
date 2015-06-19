class NNSocket
  attr_accessor :id,
    :local_endpoints,
    :remote_endpoints

  def initialize(protocol)
    # id => addr
    self.local_endpoints = {}
    self.remote_endpoints = {}
    result = NN.nn_socket(NN::AF_SP, protocol)
    if result[0] == 0
      self.id = result[1]
    else
      raise "Could not create socket: #{NN.nn_strerror(result[0])} (ERRNO #{result[0]})"
    end
  end

  def connect(addr)
    result = NN.nn_connect(id, addr)
    self.remote_endpoints[result[1]] = addr if result[0] == 0
    result
  end

  def disconnect(addr_or_id)
    result = nil
    if addr_or_id.class == Fixnum && remote_endpoints[addr_or_id]
      result = NN.nn_shutdown(id, addr_or_id)
      remote_endpoints.delete(addr_or_id)
    else
      remote_endpoints.each do |endpoint_id, addr|
        if addr_or_id == addr
          result = NN.nn_shutdown(id, endpoint_id)
          remote_endpoints.delete(endpoint_id)
          break
        end
      end
    end
    result
  end

  def bind(addr)
    result = NN.nn_bind(id, addr)
    local_endpoints[result[1]] = addr if (result[0] == 0)
    result
  end

  def unbind(addr_or_id)
    result = nil
    if addr_or_id.class == Fixnum && local_endpoints[addr_or_id]
      result = NN.nn_shutdown(id, addr_or_id)
      local_endpoints.delete(addr_or_id)
    else
      local_endpoints.each do |endpoint_id, addr|
        if addr_or_id == addr
          result = NN.nn_shutdown(id, endpoint_id)
          local_endpoints.delete(endpoint_id)
          break
        end
      end
    end
    result
  end

  def close
    NN.nn_close(id)
  end

  def addresses
    local_endpoints.values
  end

  def address
    if addresses.length == 0
      nil
    elsif addresses.length == 1
      local_endpoints.values[0]
    else
      raise "Socket #{id} has more than one local address"
    end
  end

  def send(msg, opts = 0)
    NN.nn_send(self.id, msg, opts)
  end

  def recv(opts = 0)
    NN.nn_recv(self.id, opts)
  end
end
