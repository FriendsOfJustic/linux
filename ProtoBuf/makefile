p=contact.proto
t=proto writefile readfile  

.PHONY:all
all:$t

proto:$p
	protoc --cpp_out=./entity $p

writefile:writefile.cc 
	g++ -o $@ $^ ./entity/*.pb.cc -std=c++11 -lprotobuf

readfile:readfile.cc 
	g++ -o $@ $^ ./entity/*.pb.cc -std=c++11 -lprotobuf


.PHONY:clean

clean:
	rm -rf $t ./entity/* contact.bin
