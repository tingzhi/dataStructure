/* CS261- Assignment 1 - Q. 0*/
/* Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of the integer pointed to by iptr*/
	printf("the value of the integer pointed to by iptr is: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
	printf("the address pointed to by iptr is: %p\n", iptr);
     /*Print the address of iptr itself*/
	printf("the address of iptr itself is: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x;
    /*print the address of x*/
	printf("the address of x is: %p\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("the value of x is: %d\n", x);
	
    return 0;
}
