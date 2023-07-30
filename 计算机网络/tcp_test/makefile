
.PHONY:all
all:client server

server:server.cpp
	g++ -o $@ $^ 

client:client.cpp
	g++ -o $@ $^ 

.PHONY:clean
clean:
	rm -rf client server
	