/* CS261- Assignment 3 - Part3
 * Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/27/2015
 * Development Environment: Xcode & MSVC
 * Solution description: Testing code for circularly linked list.
 */

#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message)
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
	printf("Welcome to the test for cirListDeque!\n");

	struct cirListDeque *q = createCirListDeque();

	printf("\nAfter initializing, we first print this Deque:\n");
	printCirListDeque(q);

	addFrontCirListDeque(q, 2);
	addBackCirListDeque(q, 3);
	addFrontCirListDeque(q, 1);
	addBackCirListDeque(q, 4);
	
	printf("\nNow we test add front 2, add back 3, add front 1 and add back 4, we get:\n");
	printCirListDeque(q);

	//printf("The front value is: %lf\n", frontCirListDeque(q));
	assertTrue(EQ(frontCirListDeque(q), 1), "The front value should be 1");
	//printf("The back value is: %lf\n\n", backCirListDeque(q));
	assertTrue(EQ(backCirListDeque(q), 4), "The back value should be 4");

	
	reverseCirListDeque(q);
	printf("\nBy reversing the Deque:\n");
	printCirListDeque(q);
	//printf("The front value is: %lf\n", frontCirListDeque(q));
	//printf("The back value is: %lf\n\n", backCirListDeque(q));
	assertTrue(EQ(frontCirListDeque(q), 4), "The front value should be 4");
	assertTrue(EQ(backCirListDeque(q), 1), "The back value should be 1");

	printf("\nBy removing the front:\n");
	removeFrontCirListDeque(q);
	printCirListDeque(q);
	printf("By removing the back:\n");
	removeBackCirListDeque(q);
	printCirListDeque(q);

	assertTrue(EQ(frontCirListDeque(q), 3), "The front value should be 3");
	assertTrue(EQ(backCirListDeque(q), 2), "The back value should be 2");

	printf("\nNow check if the Deque is empty:\n");
	if (isEmptyCirListDeque(q))
		printf("The Deque is empty!\n");
	else
		printf("The Deque is not empty!\n");

	printf("\nNow we add back 6 and add front 5 to check again:\n");
	addFrontCirListDeque(q, 5);
	addBackCirListDeque(q, 6);
	printCirListDeque(q);
	assertTrue(EQ(frontCirListDeque(q), 5), "The front value should be 5");
	assertTrue(EQ(backCirListDeque(q), 6), "The back value should be 6");

	printf("\nNow we use four remove front to remove all of the elements,\nand check if it's empty again:\n");
	removeFrontCirListDeque(q);
	removeFrontCirListDeque(q);
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


