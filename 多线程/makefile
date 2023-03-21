.PHONY:ALL
ALL:getticket test


getticket:Getticket.cpp
	g++ -o $@ $^ -std=c++11 -lpthread -g
test:test.cpp
	g++ -o $@ $^ -std=c++11 -lpthread -g

.PHONY:clean
clean:
	rm -rf test getticket


