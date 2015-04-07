#include <stdio.h>  /* These headers are for c standard libraries and use < >  */
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct student {
	int id;
	char name[40];
};

void printStudent(struct student s)
{
	printf("Student name is %s\n", s.name);
	printf("Student id is %d\n\n", s.id);
}

void initStudent(int id, char *name, struct student *s)
{
	s->id = id;
	strcpy(s->name, name); /* string function from string.h */
}

int main (int argc, char * argv[]) {
	
	int numStudents = 3; /* alternatively, these could be read in by command line!*/
	// int numStudents = atoi(argv[1]);

	struct student *myStudents = malloc(numStudents * sizeof(struct student));
	
	assert(myStudents != 0);

	/* "Joe" is a string constant stored as an array of characters terminated with '/0' to mark the end */
	initStudent(25, "Joe",  &myStudents[0]);
	initStudent(65, "Mary", &myStudents[1]);
	initStudent(36, "Kate", &myStudents[2]);
	
	printStudent(myStudents[0]); /* Notice, no need for the & here! */
	printStudent(myStudents[1]);
	printStudent(myStudents[2]);
		
	free(myStudents); /* every malloc should have a matching free somewhere in your code */
	return(0);  /* successful completion  -return status to calling environment.  0 is success, otherwise it's interpreted as an error code */
}
