# This should be run with CRuby for testing TCP server sockets

require 'socket'

client = TCPSocket.new 'localhost', 8888
client.puts "socket data"
client.close
