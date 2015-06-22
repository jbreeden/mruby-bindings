# This should be run with CRuby for testing TCP server sockets

require 'socket'

$stderr.puts "[TCP Client connecting]"
client = TCPSocket.new 'localhost', 8888
$stderr.puts "[TCP Client connected, sending data]"
client.puts "socket data"
$stderr.puts "[TCP Client finished, closing]"
client.close
