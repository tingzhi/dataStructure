#include <stdio.h>

int main()
{
	/* Declare and initialize (to any value you like) a double, an int,
	 * and a char. The sample below declares and initializes a float. */
    float myFloat = 3.14;
    double a = 2.7163;
    int b = 23;
    char c = 52;
	
	/* Next, declare and initialize a pointer to each of your three
	 * variables (a double *, an int *, and a char *). The sample
	 * declares and initializes a pointer to the float declared above. */
	float *myFloatPtr = &myFloat;
    double *dPtr = &a;
    int *iPtr = &b;
    char *cPtr = &c;
	
	/* Finally, print the value, addresses, and size of each of your six 
	 * variables. Note that we use %p to print the value of pointers 
	 * because the value of a pointer is a memory address. Some useful
	 * arguments for printing variables with printf(): %c for chars, %d 
	 * for ints, %f for floats/doubles, %p for memory addresses, %lu for 
	 * unsigned longs.*/
	printf("myFloat: value = %f, address = %p, size = %lu bytes\n", myFloat, &myFloat, sizeof(myFloat));
	printf("myFloatPtr: value = %p, address = %p, size = %lu bytes\n", myFloatPtr, &myFloatPtr, sizeof(myFloatPtr));
	
    printf("a: value = %g, address = %p, size = %lu bytes\n", a, &a, sizeof(a));
    printf("aPtr: value = %p, address = %p, size = %lu bytes\n", dPtr, &dPtr, sizeof(dPtr));
    printf("b: value = %d, address = %p, size = %lu bytes\n", b, &b, sizeof(b));
    printf("bPtr: value = %p, address = %p, size = %lu bytes\n", iPtr, &iPtr, sizeof(iPtr));
    printf("c: value = %c, address = %p, size = %lu bytes\n", c, &c, sizeof(c));
    printf("cPtr: value = %p, address = %p, size = %lu bytes\n", cPtr, &cPtr, sizeof(cPtr));
	return 0;
}
