/* CS261- Assignment 1 - Q.0*/
/* Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/6/2015
 * Development: Xcode & MSVC
 * Solution description: 
 * In the main function, declare an integer, x. Print the address of x. Pass x as an argument to fooA function.
 * In fooA function, print the value of the integer pointed to by iptr, the address pointed to by iptr, and the address of iptr itself.
 * In the main function, after calling fooA function, print the value of x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int *iptr){
    /* Print the value of the integer pointed to by iptr */
    printf("The value of the integer pointed to by iptr is %d\n", *iptr);
    // dereferencing the pointer
    
    /* Print the address pointed to by iptr */
    printf("The address pointed to by iptr is %p\n", iptr);
    // The value of iptr itself is the address needed here.
    
    /* Print the address of iptr itself */
    printf("The address of iptr itself is %p\n", &iptr);
    // Use & to get iptr's own address.
}

int main(){
    /* Declare an integer x */
    int x;
    /* Print the address of x */
    printf("The address of x is %p\n", &x);
    /* Call fooA() with the address of x */
    fooA(&x);
    /* Print the value of x */
    printf("The value of x is %d\n", x);
    return 0;
}
