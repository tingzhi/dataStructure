/* CS261- Assignment 1 - Q.4*/
/* Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (students->score > (students + 1)->score)
			{
				temp = students->score;
				students->score = (students + 1)->score;
				(students + 1)->score = temp;
				temp = students->id;
				students->id = (students + 1)->id;
				(students + 1)->id = temp;
			}
			students++;
		}
		students -= n - i;
	}
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 20;
    /*Allocate memory for n students using malloc.*/
	struct student *a = malloc(n*sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
	int i;
	for (i = 1; i < n+1; i++)
	{
		a->id = i;
		a->score = rand() % 101;
		a++;
	}
	a -= n;
    /*Print the contents of the array of n students.*/
	printf("The contents of the original array are:\n");
	for (i = 1; i < n+1; i++)
	{
		printf("ID:%d\t\tScore: %d\n", a->id, a->score);
		a++;
	}
	a -= n;
    /*Pass this array along with n to the sort() function*/
	sort(a, n);
    /*Print the contents of the array of n students.*/
	printf("The contents of the sorted array are:\n");
	for (i = 1; i < n + 1; i++)
	{
		printf("ID:%d\t\tScore: %d\n", a->id, a->score);
		a++;
	}

    return 0;
}
