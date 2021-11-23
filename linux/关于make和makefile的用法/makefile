test: test1.o test2.o test3.o
	gcc -o $@ $^
test1.o:test1.c
	gcc -c test1.c -o test1.o
test2.o:test2.c
	gcc -c test2.c -o test2.o
test3.o:test3.c
	gcc -c test3.c -o test3.o
.PHONY:clean
clean:
	rm -rf test test1.o test2.o test3.o
