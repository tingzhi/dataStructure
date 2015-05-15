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
}


int main(int argc, const char * argv[])
{
  	TYPE thing1;
	TYPE thing2;
	TYPE thing3;
	TYPE thing4;
	TYPE thing5;
	TYPE thing6;
	TYPE thing7;
	TYPE thing8;
	TYPE thing9;
	TYPE thing10;

	DynArr *mainList;
	mainList = createDynArr(10);

	/* create tasks - arbitrary objects I want to sort from highest to lowest
	 */
	thing1 = createThing(9, "task 1");
	thing2 = createThing(3, "task 2");
	thing3 = createThing(2, "task 3");
	thing4 = createThing(4, "task 4");
	thing5 = createThing(5, "task 5");
	thing6 = createThing(7, "task 6");
	thing7 = createThing(8, "task 7");
	thing8 = createThing(6, "task 8");
	thing9 = createThing(1, "task 9");
	thing10 = createThing(0, "task 10");

	/* add tasks to the dynamic array */
	addDynArr(mainList, thing1);
	addDynArr(mainList, thing2);
	addDynArr(mainList, thing3);
	addDynArr(mainList, thing4);
	addDynArr(mainList, thing5);
	addDynArr(mainList, thing6);
	addDynArr(mainList, thing7);
	addDynArr(mainList, thing8);
	addDynArr(mainList, thing9);
	addDynArr(mainList, thing10);


	printf("Before Sort Called \n");
        printDynArr(mainList, print_type);

	/* sort tasks */
	sortHeap(mainList, compare);

	printf("After Sort Called \n");

	/* print sorted tasks from the dynamic array */
        printDynArr(mainList, print_type);

	return 0;
}
