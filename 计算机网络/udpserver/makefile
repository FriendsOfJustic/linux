
.PHONY:all
all:client server shellclient shellserver chatserver chatclient


shellclient:shellclient.cc
	g++ -o $@ $^ -std=c++11

shellserver:shellserver.cc
	g++ -o $@ $^ -std=c++11


client:udpclient.cc
	g++ -o $@ $^ -std=c++11

server:udpserver.cc
	g++ -o $@ $^ -std=c++11


chatclient:chatclient.cc
	g++ -o $@ $^ -std=c++11 -lpthread

chatserver:chatserver.cpp
	g++ -o $@ $^ -std=c++11


.PHONY:clean
clean:
	rm -rf server client shellclient shellserver log.txt chatserver chatclient chatlog.txt
	
