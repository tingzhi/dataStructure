/* CS261- Assignment 1 - Q.3*/
/* Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/ 
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (*number > *(number + 1))
			{
				temp = *number;
				*number = *(number + 1);
				*(number + 1) = temp;
			}
			number++;
		}
		number -= n - i;
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	int *a = (int*)malloc(n*sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
	int i;
	for (i = 0; i < n; i++)
	{
		*a = rand() % (n + 1);
		a++;
	}
    /*Print the contents of the array.*/
	a -= n;
	printf("The contents of the original array are:\n");
	for (i = 1; i < n + 1; i++)
	{
		printf("a[%d]:%d\n", i, *a++);
	}
	a -= n;
    /*Pass this array along with n to the sort() function.*/
	sort(a, n);
    /*Print the contents of the array.*/  
	printf("\nThe contents of the sorted array are:\n");
	for (i = 1; i < n + 1; i++)
	{
		printf("a[%d]:%d\n", i, *a++);
	}
    return 0;
}
