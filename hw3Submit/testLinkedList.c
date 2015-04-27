/* CS261- Assignment 3 - Part3
 * Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 4/27/2015
 * Development Environment: Xcode & MSVC
 * Solution description: Testing code for linked list and bag interface.
 */

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message)
{
    printf("%s: ", message);
    if (predicate)
        printf("PASSED\n");
    else
        printf("FAILED\n");
}

void addFrontListTest(struct linkedList *lst) {
    printf("\nTesting addFrontList...\n");
    /* Add 3, 4, 10, 5, 6 */
    printf("Add 3 to the front of the list...\n");
    addFrontList(lst, 3);
    printf("Add 4 to the front of the list...\n");
    addFrontList(lst, 4);
    printf("Add 10 to the front of the list...\n");
    addFrontList(lst, 10);
    printf("Add 5 to the front of the list...\n");
    addFrontList(lst, 5);
    printf("Add 6 to the front of the list...\n");
    addFrontList(lst, 6);
    
    printf("The list content should be: [6<=>5<=>10<=>4<=>3]\n");
    printf("Call printList function...\n");
    printList(lst);
}

void addBackListTest(struct linkedList *lst) {
    printf("\n\nTesting addBackList...\n");
    /* Add 2, 5, 7, 1, 9 */
    printf("Add 2 to the back of the list...\n");
    addBackList(lst, 2);
    printf("Add 5 to the back of the list...\n");
    addBackList(lst, 5);
    printf("Add 7 to the back of the list...\n");
    addBackList(lst, 7);
    printf("Add 1 to the back of the list...\n");
    addBackList(lst, 1);
    printf("Add 9 to the back of the list...\n");
    addBackList(lst, 9);
    
    printf("The list content should be: [6<=>5<=>10<=>4<=>3<=>2<=>5<=>7<=>1<=>9]\n");
    printf("Call printList function...\n");
    printList(lst);
}

void frontListTest(struct linkedList *lst) {
    printf("\n\nTesting frontList...\nCalling frontList(lst)\n");
    assertTrue(EQ(frontList(lst), 6), "Testing the front link value == 6");
    
    printf("\nCall RemoveFrontList Function\n");
    removeFrontList(lst);
    printf("The list content should be: [5<=>10<=>4<=>3<=>2<=>5<=>7<=>1<=>9]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling frontList(lst)\n");
    assertTrue(EQ(frontList(lst), 5), "Testing the front link value == 5");
    
    printf("\nCall RemoveFrontList Function\n");
    removeFrontList(lst);
    printf("The list content should be: [10<=>4<=>3<=>2<=>5<=>7<=>1<=>9]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling frontList(lst)\n");
    assertTrue(EQ(frontList(lst), 10), "Testing the front link value == 10");

    printf("\nCall RemoveFrontList Function\n");
    removeFrontList(lst);
    printf("The list content should be: [4<=>3<=>2<=>5<=>7<=>1<=>9]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling frontList(lst)\n");
    assertTrue(EQ(frontList(lst), 4), "Testing the front link value == 4");

    printf("\nCall RemoveFrontList Function\n");
    removeFrontList(lst);
    printf("The list content should be: [3<=>2<=>5<=>7<=>1<=>9]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling frontList(lst)\n");
    assertTrue(EQ(frontList(lst), 3), "Testing the front link value == 3");
}

void backListTest(struct linkedList *lst) {
    printf("\n\nTesting backList...\nCalling backList(lst)\n");
    assertTrue(EQ(backList(lst), 9), "Testing the last link value == 9");
    
    printf("\nCall RemoveBackList Function\n");
    removeBackList(lst);
    printf("The list content should be: [3<=>2<=>5<=>7<=>1]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling backList(lst)\n");
    assertTrue(EQ(backList(lst), 1), "Testing the last link value == 1");

    printf("\nCall RemoveBackList Function\n");
    removeBackList(lst);
    printf("The list content should be: [3<=>2<=>5<=>7]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling backList(lst)\n");
    assertTrue(EQ(backList(lst), 7), "Testing the last link value == 7");

    printf("\nCall RemoveBackList Function\n");
    removeBackList(lst);
    printf("The list content should be: [3<=>2<=>5]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling backList(lst)\n");
    assertTrue(EQ(backList(lst), 5), "Testing the last link value == 5");

    printf("\nCall RemoveBackList Function\n");
    removeBackList(lst);
    printf("The list content should be: [3<=>2]\n");
    printf("Call printList function...\n");
    printList(lst);
    printf("\nCalling backList(lst)\n");
    assertTrue(EQ(backList(lst), 2), "Testing the last link value == 2");
}

void removeFrontListTest(struct linkedList *lst) {
    printf("\n\nTesting removeFrontList...\nCalling removeFrontList(lst)\n");
    removeFrontList(lst);
    printf("The list content should be: [2]\n");
    printf("Call printList function...\n");
    printList(lst);
    
    printf("\n\nCalling removeFrontList(lst)\n");
    removeFrontList(lst);
    printf("The list content should be empty.\n");
    printf("Call printList function...\n");
    printList(lst);
}

void removeBackListTest(struct linkedList *lst) {
    printf("\n\nTesting removeBackList...\n");
    /* Add 3, 4, 10*/
    printf("Add 3 to the front of the list...\n");
    addFrontList(lst, 3);
    printf("Add 4 to the front of the list...\n");
    addFrontList(lst, 4);
    printf("Add 10 to the front of the list...\n");
    addFrontList(lst, 10);
    printf("The list content should be: [10<=>4<=>3]\n");
    printf("Call printList function...\n");
    printList(lst);
    
    printf("\n\nCalling removeBackList(lst)\n");
    removeBackList(lst);
    printf("The list content should be: [10<=>4]\n");
    printf("Call printList function...\n");
    printList(lst);
    
    printf("\n\nCalling removeBackList(lst)\n");
    removeBackList(lst);
    printf("The list content should be: [10]\n");
    printf("Call printList function...\n");
    printList(lst);
    
    printf("\n\nCalling removeBackList(lst)\n");
    removeBackList(lst);
    printf("The list content should be empty!\n");
    printf("Call printList function...\n");
    printList(lst);
}

void emptyTest(struct linkedList *lst) {
    printf("\n\nTesting isEmptyList...\n");
    assertTrue(isEmptyList(lst), "Testing the linked list is empty!");
    printf("\nAdd 3 to the linked list...\n");
    addBackList(lst, 3);
    printf("The linked list content should be: [3]\n");
    printf("Call printList function...\n");
    printList(lst);
    assertTrue(!isEmptyList(lst), "\nTesting the linked list is NOT empty!");
}

void bagInterfaceTest(struct linkedList *lst) {
    printf("\nTesting addList Function...\n");
    printf("Add 6,5,9,1,7,3,6,5 to the bag...\n");
    addList(lst, 6);
    addList(lst, 5);
    addList(lst, 9);
    addList(lst, 1);
    addList(lst, 7);
    addList(lst, 3);
    addList(lst, 6);
    addList(lst, 5);
    
    printf("The bag content should be: [3,6,5,9,1,7,3,6,5]\n");
    printf("Call printList function...\n");
    printList(lst);
    
    printf("\n\nTesting containsList Function...\n");
    assertTrue(containsList(lst, 3), "Test containing 3");
    assertTrue(containsList(lst, 6), "Test containing 6");
    assertTrue(containsList(lst, 5), "Test containing 5");
    assertTrue(containsList(lst, 9), "Test containing 9");
    assertTrue(containsList(lst, 1), "Test containing 1");
    assertTrue(containsList(lst, 7), "Test containing 7");
    
    assertTrue(!containsList(lst, 2), "Test not containing 2");
    assertTrue(!containsList(lst, 4), "Test not containing 4");
    assertTrue(!containsList(lst, 8), "Test not containing 8");
    
    removeList(lst, 3);
    printf("\nRemoving 3...\nThe bag content: [6,5,9,1,7,3,6,5]\n");
    assertTrue(containsList(lst, 3), "Test still containing 3");
    
    removeList(lst, 3);
    printf("\nRemoving 3...\nThe bag content: [6,5,9,1,7,6,5]\n");
    assertTrue(!containsList(lst, 3), "Test not containing 3");
    
    removeList(lst, 1);
    printf("\nRemoving 1...\nThe bag content: [6,5,9,7,6,5]\n");
    assertTrue(!containsList(lst, 1), "Test not containing 1");
    
    printf("\nRemoving 2...\nIt should print an error!\n");
    removeList(lst, 2);
}

int main(int argc, char* argv[]) {
    /* Test your linked list in here! */
    printf("\n\nHello from test code!\n");
    
    printf("Create a linked list...\n");
    struct linkedList *nlst;
    nlst = createLinkedList();
    
    printf("\nDeque Interface Test Begin!\n");
    addFrontListTest(nlst);
    addBackListTest(nlst);
    frontListTest(nlst);
    backListTest(nlst);
    removeFrontListTest(nlst);
    removeBackListTest(nlst);
    emptyTest(nlst);
    
    printf("\n\nBag Interface Test Begin!\n");
    
    bagInterfaceTest(nlst);
    deleteLinkedList(nlst);
    printf("\nTest Finished!\n");
    
    return 0;
}


