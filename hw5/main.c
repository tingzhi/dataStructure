#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
    FILE *toDoFile;
    char desc[TASK_DESC_SIZE];

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
      /* get input command (from the keyboard) */6
      cmd = getchar();
      /* clear the trailing newline character */  //??
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
        if (cmd == 'l') {
            toDoFile = fopen("todo.txt", "r");
            if (toDoFile != NULL)
                loadList(mainList, toDoFile);
            fclose(toDoFile);
        }
        else if (cmd == 's') {
            toDoFile = fopen("todo.txt", "w");
            if (toDoFile != NULL)
                saveList(mainList, toDoFile);
            fclose(toDoFile);
        }
        else if (cmd == 'a') {  //??
            printf("Please enter the task description: ");
            scanf();
            printf("Please enter the task priority (0-999): ");
            scanf();
            createTask(prio, desc);
            printf("The task '%s' has been added to your to-do list.", desc);
        }
        else if (cmd == 'g') {
            if (isEmptyDynArr(mainList)) {
                printf("Your to-do list is empty.");
            }
            else {
                TaskP *temp = (TaskP *)getMinHeap(mainList);
                printf("Your first task is '%s'.", );
            }
        }
        else if (cmd == 'r') {
              printf("Your first task '%s' has been removed from the list.", );
            
        }
        else if (cmd == 'p') {
            printList(mainList);
        }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
