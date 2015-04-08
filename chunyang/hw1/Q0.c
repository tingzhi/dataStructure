/* CS261- Assignment 1 - Q. 0*/
/* Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of the integer pointed to by iptr*/
	printf("the value of the integer pointed to by iptr is: %d\n", *iptr);	/* print as interger */
     /*Print the address pointed to by iptr*/
	printf("the address pointed to by iptr is: %X\n", iptr);	/* print as in hexadecimal */
     /*Print the address of iptr itself*/
	printf("the address of iptr itself is: %X\n", &iptr);	/* print as in hexadecimal */
}

int main(){
    
    /*declare an integer x*/
	int x;
    /*print the address of x*/
	printf("the address of x is: %X\n", &x);	/* print as in hexadecimal */
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("the value of x is: %d\n", x);	/* print as interger */
	
    return 0;
}
