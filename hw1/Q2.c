/* CS261- Assignment 1 - Q.2*/
/* Name:Li, Tingzhi & Zhang, Chunyang
 * Date:4/6/2015
 * Development environment: Xcode & MSVC
 * Solution description: Use foo function to observe the difference between pass-by-value and "pass-by-reference."
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2*(*a);
    /*Set b to half its original value*/
    *b = (*b)/2;
    /*Assign a+b to c*/
    c = (*a) + (*b);
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x, y, z;
    x = 7;
    y = 8;
    z = 9;
    /*Print the values of x, y and z*/
    printf("The origianl values are: x = %d, y = %d, z = %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int ret = foo(&x, &y,z);
    /*Print the value returned by foo*/
    printf("The value returned by foo function is %d\n", ret);
    /*Print the values of x, y and z again*/
    printf("After using foo function, the values are: x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
/*Is the return value different than the value of z?  Why?*/

/* The return value is 18 and the value of z is 9. They are different. That is because when main function calls foo function, we passed the pointers of x and y to foo function, but we copied the value of z to foo function since C is pass-by-value. So only the changes that foo function made to x and y will reflected outside of foo function. The changes that foo function made to z will not be reflected in main function. */
