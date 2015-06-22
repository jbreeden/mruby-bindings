# This should be run with CRuby for testing TCP client sockets

require 'socket'

server = TCPServer.new 8888

#$stderr.puts "[TCP Server listening]"
client = server.accept
#$stderr.puts "[TCP Server accepted client]"
client.puts "socket data"
#$stderr.puts "[TCP Server sent data to client. Closing.]"
client.close
