/* CS261- Assignment 2 - Part1
* Name: Li, Tingzhi & Zhang, Chunyang
* Date: 4/14/2015
* Development Environment: Xcode & MSVC
* Solution description:
*/
/* testDynArray.c
 * This file is used for testing the dynamicArray.c file. 
 * This test suite is by no means complete or thorough.
 * More testing is needed on your own.
*/
#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

void addDynArrTest(DynArr *dyn) {
    printf("\nTesting addDynArr...\n");
    printf("Add 3 to the dynamic array...\n");
    addDynArr(dyn, 3);
    printf("Add 4 to the dynamic array...\n");
    addDynArr(dyn, 4);
    printf("Add 10 to the dynamic array...\n");
    addDynArr(dyn, 10);
    printf("Add 5 to the dynamic array...\n");
    addDynArr(dyn, 5);
    printf("Add 6 to the dynamic array...\n");
    addDynArr(dyn, 6);
    
    printf("The array's content should be: [3,4,10,5,6]\n");
    assertTrue(EQ(getDynArr(dyn, 0), 3), "Test 1st element == 3");
    assertTrue(EQ(getDynArr(dyn, 1), 4), "Test 2nd element == 4");
    assertTrue(EQ(getDynArr(dyn, 2), 10), "Test 3rd element == 10");
    assertTrue(EQ(getDynArr(dyn, 3), 5), "Test 4th element == 5");
    assertTrue(EQ(getDynArr(dyn, 4), 6), "Test 5th element == 6");
    assertTrue(sizeDynArr(dyn) == 5, "Test size == 5");
}

void getDynArrTest(DynArr *dyn) {
    printf("\nTesting getDynArr...\n");
    printf("The array's content: ");
    for (int i = 0; i < sizeDynArr(dyn); i++) {
        printf("%g ",getDynArr(dyn,i));
    }
}

void putDynArrTest(DynArr *dyn) {
    printf("\n\nTesting putDynArr...\nCalling putDynArr(dyn, 2, 7)\n");
    putDynArr(dyn, 2, 7);
    printf("The array's content: [3,4,7,5,6]\n");
    assertTrue(EQ(getDynArr(dyn, 2), 7), "Test 3rd element == 7");
    assertTrue(sizeDynArr(dyn) == 5, "Test size == 5");
    
    printf("\nCalling putDynArr(dyn, 0, 2)\n");
    putDynArr(dyn, 0, 2);
    printf("The array's content: [2,4,7,5,6]\n");
    assertTrue(EQ(getDynArr(dyn, 0), 2), "Test 1st element == 2");
    assertTrue(sizeDynArr(dyn) == 5, "Test size == 5");
    
    printf("\nCalling putDynArr(dyn, 4, 1)\n");
    putDynArr(dyn, 4, 1);
    printf("The array's content: [2,4,7,5,1]\n");
    assertTrue(EQ(getDynArr(dyn, 4), 1), "Test 5th element == 1");
    assertTrue(sizeDynArr(dyn) == 5, "Test size == 5");
}

void swapDynArrTest(DynArr *dyn) {
    printf("\nTesting swapDynArr...\nCalling swapDynArr(dyn, 2, 4)\n");
    swapDynArr(dyn, 2, 4);
    printf("The array's content: [2,4,1,5,7]\n");
    assertTrue(EQ(getDynArr(dyn, 2), 1), "Test 3rd element == 1");
    assertTrue(EQ(getDynArr(dyn, 4), 7), "Test 5th element == 7");
    
    printf("\nCalling swapDynArr(dyn, 0, 4)\n");
    swapDynArr(dyn, 0, 4);
    printf("The array's content: [7,4,1,5,2]\n");
    assertTrue(EQ(getDynArr(dyn, 0), 7), "Test 1st element == 7");
    assertTrue(EQ(getDynArr(dyn, 4), 2), "Test 5th element == 2");
    
    printf("\nCalling swapDynArr(dyn, 0, 1)\n");
    swapDynArr(dyn, 0, 1);
    printf("The array's content: [4,7,1,5,2]\n");
    assertTrue(EQ(getDynArr(dyn, 0), 4), "Test 1st element == 4");
    assertTrue(EQ(getDynArr(dyn, 1), 7), "Test 2nd element == 7");
}

void removeAtDynArrTest(DynArr *dyn) {
    printf("\nTesting removeAtDynArr...\nCalling removeAtDynArr(dyn, 1)\n");
    removeAtDynArr(dyn, 1);
    printf("The array's content: [4,1,5,2]\n");
    assertTrue(EQ(getDynArr(dyn, 0), 4), "Test 1st element == 4");
    assertTrue(EQ(getDynArr(dyn, 3), 2), "Test 4th element == 2");
    assertTrue(sizeDynArr(dyn) == 4, "Test size == 4");
    
    printf("\nCalling removeAtDynArr(dyn, 0)\n");
    removeAtDynArr(dyn, 0);
    printf("The array's content: [1,5,2]\n");
    assertTrue(EQ(getDynArr(dyn, 0), 1), "Test 1st element == 1");
    assertTrue(EQ(getDynArr(dyn, 2), 2), "Test 4th element == 2");
    assertTrue(sizeDynArr(dyn) == 3, "Test size == 3");
}

void stackInterfaceTest(DynArr *dyn) {
    printf("\nTesting stack interface...\n");
    
    printf("The stack's content: [1,5,2] <- top\n");
    assertTrue(!isEmptyDynArr(dyn), "Testing isEmptyDynArr");
    assertTrue(EQ(topDynArr(dyn), 2), "Test topDynArr == 2");
    
    popDynArr(dyn);
    printf("Poping...\nThe stack's content: [1,5] <- top\n");
    assertTrue(EQ(topDynArr(dyn), 5), "Test topDynArr == 5");
    assertTrue(sizeDynArr(dyn) == 2, "Test size == 2");
    
    popDynArr(dyn);
    popDynArr(dyn);
    printf("Poping...\n");
    printf("Poping...\n");
    assertTrue(sizeDynArr(dyn) == 0, "Test size == 0");
    
    pushDynArr(dyn, 3);
    pushDynArr(dyn, 6);
    pushDynArr(dyn, 5);
    pushDynArr(dyn, 9);
    printf("Pushing 3...\nPushing 6...\nPushing 5...\nPushing 9...\n");
    printf("The stack's content: [3,6,5,9] <- top\n");
    assertTrue(EQ(topDynArr(dyn), 9), "Test topDynArr == 9");
    assertTrue(sizeDynArr(dyn) == 4, "Test size == 4");
    
    pushDynArr(dyn, 1);
    pushDynArr(dyn, 7);
    pushDynArr(dyn, 3);
    pushDynArr(dyn, 6);
    pushDynArr(dyn, 5);
    printf("Pushing 1...\nPushing 7...\nPushing 3...\nPushing 6...\nPushing 5...\n");
    printf("The stack's content: [3,6,5,9,1,7,3,6,5] <- top\n");
    assertTrue(EQ(topDynArr(dyn), 5), "Test topDynArr == 5");
    assertTrue(sizeDynArr(dyn) == 9, "Test size == 9");
}

void bagInterfaceTest(DynArr *dyn) {
    printf("\nTesting bag interface...\n");
    printf("The bag's content: [3,6,5,9,1,7,3,6,5]\n");
    
    assertTrue(containsDynArr(dyn, 3), "Test containing 3");
    assertTrue(containsDynArr(dyn, 6), "Test containing 6");
    assertTrue(containsDynArr(dyn, 5), "Test containing 5");
    assertTrue(containsDynArr(dyn, 9), "Test containing 9");
    assertTrue(containsDynArr(dyn, 1), "Test containing 1");
    assertTrue(containsDynArr(dyn, 7), "Test containing 7");
    
    assertTrue(!containsDynArr(dyn, 2), "Test not containing 2");
    assertTrue(!containsDynArr(dyn, 4), "Test not containing 4");
    assertTrue(!containsDynArr(dyn, 8), "Test not containing 8");
    
    removeDynArr(dyn, 3);
    printf("Removing 3...\nThe stack's content: [6,5,9,1,7,3,6,5]\n");
    assertTrue(containsDynArr(dyn, 3), "Test still containing 3");
    assertTrue(sizeDynArr(dyn) == 8, "Test size == 8");
    
    removeDynArr(dyn, 3);
    printf("Removing 3...\nThe stack's content: [6,5,9,1,7,6,5]\n");
    assertTrue(!containsDynArr(dyn, 3), "Test not containing 3");
    assertTrue(sizeDynArr(dyn) == 7, "Test size == 7");

    removeDynArr(dyn, 1);
    printf("Removing 1...\nThe stack's content: [6,5,9,7,6,5]\n");
    assertTrue(!containsDynArr(dyn, 1), "Test not containing 1");
    assertTrue(sizeDynArr(dyn) == 6, "Test size == 6");
}

// this main function contains some
int main(int argc, char* argv[]){

	DynArr *dyn;
	dyn = createDynArr(2);
    
    printf("\n\nTest Begin!\n");
    printf("\nDynamic Array Functions Tests\n");
    printf("\nCreating a dynamic array with the capacity of 2.\n");
    printf("The size of the dynamic array is %d.\n", sizeDynArr(dyn));
    
    addDynArrTest(dyn);
    getDynArrTest(dyn);
    putDynArrTest(dyn);
    swapDynArrTest(dyn);
    removeAtDynArrTest(dyn);
    
    stackInterfaceTest(dyn);
    bagInterfaceTest(dyn);
    
    deleteDynArr(dyn);
    printf("\nTest Finished!\n");
    
	return 0;
}
