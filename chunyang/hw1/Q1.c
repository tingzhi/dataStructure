/* CS261- Assignment 1 - Q.1*/
/* Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
	struct student *p = malloc(10 * sizeof(struct student));	 /*Allocate memory for ten students*/
	
	return p;	 /*return the pointer*/
	
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
	for (int i = 1;  i < 11; i++)
	{		
		students->id = i;
		students->score = rand() % 101;
		students++;
	}
	
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 1; i < 10; i++)
	{
		printf("ID%d: %d\t\tScore%d: %d\n", i, students->id, i, students->score);
		students++;
	}
	printf("ID10: %d\tScore10: %d\n", students->id, students->score);
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int x, y, max, min;
	float mean, sum=0;
	for (int i = 1; i < 10; i++)
	{
		x = students->score;
		sum += x;
		students++;
		y = students->score;
		if (x > y)
		{
			max = x;
			min = y;
		}
		else
		{
			max = y;
			min = x;
		}
	}
	sum += y;
	mean = sum / 10;
	printf("maximum score:%d\n", max);
	printf("minimum score:%d\n", min);
	printf("average score:%.1f\n", mean);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	assert(stud != 0);
	free(stud);
}

int main(){
    struct student* stud = NULL;
    
	stud = allocate();	/*call allocate*/
	
	generate(stud);	/*call generate*/
	
	output(stud);	/*call output*/
	
	summary(stud);	/*call summary*/
	
	deallocate(stud);	/*call deallocate*/
	
    return 0;
}
