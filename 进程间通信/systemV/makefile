.PHONY:all
all:client server

client:client.cpp
	g++ -o $@ $^

server:server.cpp
	g++ -o $@ $^ 

.PHON:clean

clean:
	rm -rf server client
	