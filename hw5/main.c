#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
    char desc[TASK_DESC_SIZE];
    int prio;

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
        if (cmd == 'l') {
            char fileName[30];
            FILE *toDoFile;
            printf("Please enter the filename: ");
            fgets (fileName, 30, stdin);
            char *nlptr;
            /* remove trailing newline character */
            nlptr = strchr(fileName, '\n');
            if (nlptr)
                *nlptr = '\0';

            toDoFile = fopen(fileName, "r");
            if (toDoFile != NULL)
                loadList(mainList, toDoFile);
            fclose(toDoFile);
            printf("The list has been loaded from file successfully.\n\n");
        }
        else if (cmd == 's') {
            if (isEmptyDynArr(mainList)) {
                printf("You have nothing in the to-do list. So there is nothing to be saved.\n\n");
            }
            else {
                char fileName[30];
                FILE *toDoFile;
                printf("Please enter the file name: ");
                fgets (fileName, 30, stdin);
                char *nlptr;
                /* remove trailing newline character */
                nlptr = strchr(fileName, '\n');
                if (nlptr)
                    *nlptr = '\0';

                toDoFile = fopen(fileName, "w");
                if (toDoFile != NULL)
                    saveList(mainList, toDoFile);
                fclose(toDoFile);
                printf("The list has been saved into the file successfully.\n\n");
            }
        }
        else if (cmd == 'a') {
            printf("Please enter the task description: ");
            fgets (desc, TASK_DESC_SIZE, stdin);
            char *nlptr;
            /* remove trailing newline character */
            nlptr = strchr(desc, '\n');
            if (nlptr)
                *nlptr = '\0';
            printf("Please enter the task priority (0-999): ");
            setbuf(stdin, NULL);
            scanf("%d", &prio);
            setbuf(stdin, NULL);
            addHeap(mainList, createTask(prio, desc),compare);
            printf("The task '%s' has been added to your to-do list.\n\n", desc);
        }
        else if (cmd == 'g') {
            if (isEmptyDynArr(mainList)) {
                printf("Your to-do list is empty.\n\n");
            }
            else {
                TaskP temp = (TaskP)getMinHeap(mainList);
                printf("Your first task is '%s'.\n\n", temp->description);
            }
        }
        else if (cmd == 'r') {
            if (isEmptyDynArr(mainList)) {
                printf("Your to-do list is empty!\n\n");
            }
            else {
                TaskP temp = (TaskP)getMinHeap(mainList);
                printf("Your first task '%s' has been removed from the list.\n\n", temp->description);
                removeMinHeap(mainList, compare);
            }
        }
        else if (cmd == 'p') {
            if (isEmptyDynArr(mainList)) {
                printf("Your to-do list is empty! There is nothing to print!\n\n");
            }
            else
                printList(mainList);
        }
        else if (cmd != 'e')
            printf("Wrong command, please choose again!\n\n");
      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
    printf("Bye!\n\n");
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
