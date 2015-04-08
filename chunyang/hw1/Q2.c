/* CS261- Assignment 1 - Q.2*/
/* Name: Li, Tingzhi & Zhang, Chunyang	
 * Date: 4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
	*a *= 2; /*Set a to double its original value*/

	*b /= 2; /*Set b to half its original value*/

	c = *a + *b; /*Assign a+b to c*/

	return c; /*Return c*/
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7, y = 8, z = 9;
    /*Print the values of x, y and z*/
	printf("the original values are: x = %d, y = %d, z = %d\n", x, y, z);
	/*Call foo() appropriately, passing x,y,z as parameters*/
	int c = foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("the value returned by foo is: %d\n", c);
    /*Print the values of x, y and z again*/
	printf("after using foo function, the values are: x = %d, y = %d, z = %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/

	/* The return value is different than the value of z. 
	The reason is that we didn't use pointers to change the value of z. And as C pass-by-value, 
	changing the value of c in foo function will not affect the main function. 
	Although we use return c to return the value, the value will not be returned to z, but another integer like c I declared.
	If we declare a pointer as *c for z like x and y,
	the value of z will be changed because c contains the address for z, 
	in which case we do not need to declare c in the main function again.*/
    return 0;
}
    
    
