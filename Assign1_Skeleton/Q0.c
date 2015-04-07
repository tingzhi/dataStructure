/* CS261- Assignment 1 - Q. 0*/
/* Name: Tingzhi Li
 * Date: 4/6/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int *iptr){
    /*Print the value of the integer pointed to by iptr*/
    printf("The value of the integer pointed to by iptr is %d\n", *iptr);
    /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr is %p\n", iptr);
    /*Print the address of iptr itself*/
    printf("The address of iptr itself is %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x;
    /*print the address of x*/
    printf("The address of x is %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x is %d\n", x);
    return 0;
}
