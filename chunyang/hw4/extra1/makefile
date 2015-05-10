all: prog


prog: animal.o compare.o

	gcc -g -Wall -std=c99 -o prog animal.o compare.o


compare.o: compare.c

	gcc -g -Wall -std=c99 -c compare.c


animal.o: animal.c bst.h

	gcc -g -Wall -std=c99 -c animal.c


clean:
	
rm animal.o

	rm compare.o

	rm prog
