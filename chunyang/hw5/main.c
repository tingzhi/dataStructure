#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
	  if (cmd == 'l')
	  {
		  FILE *toDoFile;
		  char fileName[TASK_DESC_SIZE];
		  printf("Please enter the filename: ");
		  setbuf(stdin, NULL);
		  scanf("%s", fileName);
		  toDoFile = fopen(fileName,'r');
		  if (toDoFile == NULL)
			  printf("Can't open the file! Please double check!\n\n");
		  else
		  {
			  loadList(mainList, toDoFile);
			  printf("The list has been loaded from file successfully.\n\n");
		  }
		  fclose(toDoFile);
	  }
	  else if (cmd == 's')
	  {
		  if (isEmptyDynArr(mainList)) 
			  printf("You have nothing in the to-do list. So there is nothing to be saved.\n\n");
		  else
		  {
			  FILE *toDoFile;
			  char fileName[TASK_DESC_SIZE];
			  printf("Please enter the filename: ");
			  setbuf(stdin, NULL);
			  scanf("%s", fileName);
			  toDoFile = fopen(fileName, 'w');
			  saveList(mainList, toDoFile);
			  fclose(toDoFile);
			  printf("The list has been saved into the file successfully.\n\n");
		  }
	  }
	  else if (cmd == 'a')
	  {
		  printf("Please enter the task description: ");
		  scanf("%s", fileName);
		  TaskP a = malloc(sizeof(struct Task));


		  setbuf(stdin, NULL);
		  scanf("%s", a->);
	  }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
