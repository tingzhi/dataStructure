/* CS261- Assignment 5
 * Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 5/16/2015
 * Development Environment: Xcode & MSVC
 * Solution description: Test code for the heap sort algorithm and any other heap functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"
#include "toDoList.h"


/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
    TaskP leftOne = (TaskP) left;
    TaskP rightOne = (TaskP) right;
    if (leftOne->priority < rightOne->priority)
        return -1;
    else if (leftOne->priority > rightOne->priority)
        return 1;
    else
        return 0;
}

/***************************************************************
Print type function defined by user to print their specific type
****************************************************************/


void print_type(TYPE val)
{
  struct Task *v = (struct Task*) val;

  printf("Task: %s  Priority: %d\n", v->description, v->priority);
}




/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TaskP createThing (int priority, char *desc)
{
  /*FIXME: Write this */
    TaskP newThing = malloc(sizeof(struct Task));
	newThing->priority = priority;
	strcpy(newThing->description, desc);
	return newThing;
}

//printTestResult(containsBSTree(tree, &myData1), "containsBSTree", "when test containing 50 as root");


void testHeap() {
    TaskP thing1;
    TaskP thing2;
    TaskP thing3;
    
    DynArr *mainList;
    mainList = createDynArr(3);

    thing1 = createThing(9, "task 1");
    thing2 = createThing(3, "task 2");
    thing3 = createThing(2, "task 3");
    
    addHeap(mainList,thing1, compare);
    printf("Call addHeap()... \nadding 'task1' with priority 9\n");
    printf("Print out the heap...\n");
    printDynArr(mainList, print_type);
    
    addHeap(mainList,thing2, compare);
    printf("Call addHeap()... \nadding 'task2' with priority 3\n");
    printf("Print out the heap...\n");
    printDynArr(mainList, print_type);
    printf("Call getMinHeap()...\n\n");
    print_type(getMinHeap(mainList));
    printf("\n");

    addHeap(mainList,thing3, compare);
    printf("Call addHeap()... \nadding 'task3' with priority 2\n");
    printf("Print out the heap...\n");
    printDynArr(mainList, print_type);
    printf("Call getMinHeap()...\n\n");
    print_type(getMinHeap(mainList));
    printf("\n");

    printf("Call removeMinHeap()...\n");
	free((TaskP)getMinHeap(mainList));
    removeMinHeap(mainList, compare);
    printf("Print out the heap...\n");
    printDynArr(mainList, print_type);
    
    printf("Call removeMinHeap()...\n");
	free((TaskP)getMinHeap(mainList));
    removeMinHeap(mainList, compare);
    printf("Print out the heap...\n");
    printDynArr(mainList, print_type);
    
    printf("Call removeMinHeap()...\n");
	free((TaskP)getMinHeap(mainList));
    removeMinHeap(mainList, compare);
    printf("Print out the heap...\n");
    printDynArr(mainList, print_type);
    
    printf("\n\nTest finished.\n\n");
    
    TaskP task;
    for (int i = 0; i < sizeDynArr(mainList); i++) {
        task = getDynArr(mainList, i);
        free(task);
    }
    /*free(thing1);
    free(thing2);
    free(thing3);*/
    
    deleteDynArr(mainList);
}

int main(int argc, const char * argv[])
{
	TYPE thing;

	DynArr *mainList;
	mainList = createDynArr(10);

	/* create tasks - arbitrary objects I want to sort from highest to lowest
	*/
	thing = createThing(9, "task 1");
	addDynArr(mainList, thing);

	thing = createThing(3, "task 2");
	addDynArr(mainList, thing);

	thing = createThing(2, "task 3");
	addDynArr(mainList, thing);

	thing = createThing(4, "task 4");
	addDynArr(mainList, thing);

	thing = createThing(5, "task 5");
	addDynArr(mainList, thing);

	thing = createThing(7, "task 6");
	addDynArr(mainList, thing);

	thing = createThing(8, "task 7");
	addDynArr(mainList, thing);

	thing = createThing(6, "task 8");
	addDynArr(mainList, thing);

	thing = createThing(1, "task 9");
	addDynArr(mainList, thing);

	thing = createThing(0, "task 10");
	addDynArr(mainList, thing);

    printf("\n\nTesting heap sort algorithm...\n\n");
	printf("Before Sort Called \n");
        printDynArr(mainList, print_type);

	/*build tasks*/
	printf("After Build Called \n");
	testbuildHeap(mainList, compare);
	printDynArr(mainList, print_type);

	/* sort tasks */
	sortHeap(mainList, compare);

	printf("After Sort Called \n");

	/* print sorted tasks from the dynamic array */
        printDynArr(mainList, print_type);
    
    TaskP task;
    for (int i = 0; i < sizeDynArr(mainList); i++) {
        task = getDynArr(mainList, i);
        free(task);
    }

    deleteDynArr(mainList);
    
    printf("\nStart new heap-based priority queue interface test...\n\n");
    testHeap();
    
	return 0;
}
