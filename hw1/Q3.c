/* CS261- Assignment 1 - Q.3*/
/* Name:Tingzhi Li
 * Date:4/6/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
    /*Sort the given array number , of length n*/
    int temp;
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (number[j] > number[j+1]) {
                // swap them
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *ptr = malloc(n * sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
    for (int i = 0; i < n; i++) {
        *ptr = rand() % (n+1);
        ptr++;
    }
    /*Print the contents of the array.*/
    printf("The contents of the array:\n");
    ptr = ptr - n;
    for (int j = 0; j < n; j++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    /*Pass this array along with n to the sort() function.*/
    ptr = ptr - n;
    sort(ptr, n);
    /*Print the contents of the array.*/    
    printf("The contents of the sorted array:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    free(ptr-n);
    return 0;
}
