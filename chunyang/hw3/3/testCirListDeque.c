#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
	struct cirListDeque *q = createCirListDeque();
	addFrontCirListDeque(q, 2);
	addBackCirListDeque(q, 3);
	addFrontCirListDeque(q, 1);
	addBackCirListDeque(q, 4);

	printCirListDeque(q);

	reverseCirListDeque(q);
	printCirListDeque(q);

	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printCirListDeque(q);

	TYPE i = frontCirListDeque(q);
	TYPE j = backCirListDeque(q);
	printf("front: %lf\tback: %lf\n", i, j);

	deleteCirListDeque(q);
	return 0;
}


