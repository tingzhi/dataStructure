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

	printf("After initializing, we test add front 2, add back 3, add front 1 and add back 4, we get\n");
	printCirListDeque(q);
	printf("The front value is: %lf\n", frontCirListDeque(q));
	printf("The back value is: %lf\n\n", backCirListDeque(q));

	
	reverseCirListDeque(q);
	printf("By reversing the Deque,\n");
	printCirListDeque(q);

	printf("By removing the front,\n");
	removeFrontCirListDeque(q);
	printCirListDeque(q);
	printf("By removing the back,\n");
	removeBackCirListDeque(q);
	printCirListDeque(q);

	printf("Now check if the Deque is empty,\n");
	if (isEmptyCirListDeque(q))
		printf("The Deque is empty!\n");
	else
		printf("The Deque is not empty!\n");

	printf("\nNow we use two remove front to remove the left two elements and check if it's empty again,\n");
	removeFrontCirListDeque(q);
	removeFrontCirListDeque(q);
	if (isEmptyCirListDeque(q))
		printf("The Deque is empty!\n");
	else
		printf("The Deque is not empty!\n");

	printf("\nNow we print this deque again, the result is...\n");
	printCirListDeque(q);

	deleteCirListDeque(q);
	return 0;
}


