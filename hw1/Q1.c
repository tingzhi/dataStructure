/* CS261- Assignment 1 - Q.1*/
/* Name: Tingzhi Li
 * Date: 4/6/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student *mystudent = malloc(10 * sizeof(struct student));
    if (mystudent == 0) {
        printf("System could not allocate memory now.\n");
    }
    /*return the pointer*/
    return mystudent;
}

void generate(struct student* students){
    /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
    
    int i, j, flag, idNum;
    // flag == 1 means id is new. flag == 0 means id has already seen.
    for (i = 0; i < 10; i++) {
        do {
            flag = 1;
            idNum = rand() % 10 + 1;    // ID between 1 and 10.
            for (j = 0; j < i && flag == 1; j++) {
                if (students[j].id == idNum) {
                    flag = 0;
                }
            }
        } while (flag == 0);
        students[i].id = idNum;
        students[i].score = rand() % 101;   // scores between 0 and 100.
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for (i = 0; i < 10; i++) {
        printf("\t%d %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i, j, temp, mini, maxi;
    double mean;
    
    // Calculate the sum of 10 students scores.
    int sum = 0;
    for (i = 0; i < 10; i++) {
        sum = sum + students[i].score;
    }
    mean = (double)sum/(double)10;

    // bubble sorting
    for (i = 9; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (students[j].score > students[j+1].score) {
                // swap them
                temp = students[j].score;
                students[j].score = students[j+1].score;
                students[j+1].score = temp;
            }
        }
    }
    // After sorting, students[0] has minimum score, students[9] has maximum score.
    mini = students[0].score;
    maxi = students[9].score;
    printf("Minimum score = %d, Maximum score = %d, Average score = %0.2f\n", mini, maxi, mean);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if (stud != 0) {
        free(stud);
    }
}

int main(){
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
