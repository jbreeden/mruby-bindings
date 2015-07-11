# This should be run with CRuby for testing TCP client sockets

require 'socket'

server = TCPServer.new 8888

client = server.accept
client.write "socket data"
client.close
