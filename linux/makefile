test1:test1.o
	gcc test1.o -o test
test1.o:test1.s
	gcc -c test1.s -o test1.o
test1.s:test1.i
	gcc -S test1.i -o test1.s
test1.i:test1.c
	gcc -E test1.c -o test1.i
.PHONY:clean
clean:
	rm -rf test1.i test1.s test1.o test1
