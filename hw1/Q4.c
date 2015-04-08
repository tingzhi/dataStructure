/* CS261- Assignment 1 - Q.4*/
/* Name:Li, Tingzhi & Zhang, Chunyang
 * Date:4/6/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
    /*Sort the n students based on their score*/
    /* Remember, each student must be matched with their original score after sorting */
    // bubble sort
    int temp;
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (students[j].score > students[j+1].score) {
                //swap their score
                temp = students[j].score;
                students[j].score = students[j+1].score;
                students[j+1].score = temp;
                //swap their id as well
                temp = students[j].id;
                students[j].id = students[j+1].id;
                students[j+1].id = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    /*Allocate memory for n students using malloc.*/
    struct student *mystudent = malloc(n * sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
    
    int i, j, flag, idNum;
    // flag == 1 means id is new.
    // flag == 0 means id has already seen.
    for (i = 0; i < n; i++) {
        do {
            flag = 1;
            idNum = rand() % n + 1;
            
            for (j = 0; j < i && flag == 1; j++) {
                if (mystudent[j].id == idNum) {
                    flag = 0;
                }
            }
        } while (flag == 0);
        mystudent[i].id = idNum;
        mystudent[i].score = rand() % 101;
    }
    
    /*Print the contents of the array of n students.*/
    printf("The contents of the array of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("\tID: %d Score: %d\n", mystudent[i].id, mystudent[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(mystudent, n);
    /*Print the contents of the array of n students.*/
    printf("The contents of the sorted array of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("\tID: %d Score: %d\n", mystudent[i].id, mystudent[i].score);
    }
    if (mystudent != 0) {
        free(mystudent);
    }
    return 0;
}
