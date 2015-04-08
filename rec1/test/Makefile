all: prog test

prog: datastructure.o main.o
	gcc -Wall -std=c99 -o prog datastructure.o main.o

test: datastructure.o test.o
	gcc -Wall -std=c99 -o test datastructure.o test.o

datastructure.o: datastructure.c
	gcc -Wall -std=c99 -c datastructure.c

main.o: main.c
	gcc -Wall -std=c99 -c main.c 

test.o: test.c
	gcc -Wall -std=c99 -c test.c

clean:
	rm -rf *.o prog test
