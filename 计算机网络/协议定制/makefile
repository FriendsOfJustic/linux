.PHONY:All
All:Calserver Calclient test


protocal=JSON


Calserver:server.cc
	g++ -o $@ $^ -std=c++11 -lpthread  -ljsoncpp -D${protocal}



Calclient:client.cc
	g++ -o $@ $^ -std=c++11  -ljsoncpp -D${protocal}


test:test.cpp
	g++ -o $@ $^ -std=c++11


.PHONY:clean
clean:
	rm -rf Calserver Calclient test
