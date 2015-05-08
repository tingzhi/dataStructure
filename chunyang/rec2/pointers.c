#include <stdio.h>

int main()
{
	/* Declare and initialize (to any value you like) a double, an int,
	 * and a char. The sample below declares and initializes a float. */
	float myFloat = 3.14;
	double myDouble = 2.71;
	int myInt = 9;
	char myChar = 'z';
	
	/* Next, declare and initialize a pointer to each of your three
	 * variables (a double *, an int *, and a char *). The sample
	 * declares and initializes a pointer to the float declared above. */
	float *myFloatPtr = &myFloat;
	double *myDoublePtr = &myDouble;
	int *myIntPtr = &myInt;
	char *myCharPtr = &myChar;
	
	/* Finally, print the value, addresses, and size of each of your six 
	 * variables. Note that we use %p to print the value of pointers 
	 * because the value of a pointer is a memory address. Some useful
	 * arguments for printing variables with printf(): %c for chars, %d 
	 * for ints, %f for floats/doubles, %p for memory addresses, %lu for 
	 * unsigned longs.*/
	printf("myFloat: value = %f, address = %p, size = %lu bytes\n", myFloat, &myFloat, sizeof(myFloat));
	printf("myFloatPtr: value = %p, address = %p, size = %lu bytes\n\n", myFloatPtr, &myFloatPtr, sizeof(myFloatPtr));

	printf("myDouble: value = %f, address = %p, size = %lu bytes\n", myDouble, &myDouble, sizeof(myDouble));
	printf("myDoublePtr: value = %p, address = %p, size = %lu bytes\n\n", myDoublePtr, &myDoublePtr, sizeof(myDoublePtr));

	printf("myInt: value = %d, address = %p, size = %lu bytes\n", myInt, &myInt, sizeof(myInt));
	printf("myIntPtr: value = %p, address = %p, size = %lu bytes\n\n", myIntPtr, &myIntPtr, sizeof(myIntPtr));

	printf("myChar: value = %c, address = %p, size = %lu bytes\n", myChar, &myChar, sizeof(myChar));
	printf("myCharPtr: value = %p, address = %p, size = %lu bytes\n\n", myCharPtr, &myCharPtr, sizeof(myCharPtr));

	return 0;

}
