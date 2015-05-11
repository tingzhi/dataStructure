/* CS261- Assignment 4 - Extra Credit 1
 * Name: Li, Tingzhi & Zhang, Chunyang
 * Date: 5/11/2015
 * Development Environment: Xcode & MSVC
 * Solution description: ??Implementation of "Guessing the animal" game using binary search tree data structure.
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"
#include "string.h"

struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:		tree cnt is 0
		tree root is null
 */

void initBSTree(struct BSTree *tree)
{

	/* Write This */
	assert(tree);
	tree->root = NULL;
	tree->cnt = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: 	
		tree != 0	
		tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	/* Write This */
	struct BSTree *newBSTree = malloc(sizeof(struct BSTree));
	assert(newBSTree);
	initBSTree(newBSTree);
	return newBSTree;  /* temporary return*/	
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	
	/* Write This */
	if (node->left == NULL)
	{
		if (node->right == NULL)
		{
			free(node);
			return;
		}
		else
		{
			_freeBST(node->right);
			node->right = NULL;
		}
	}
	else
	{
		_freeBST(node->left);
		node->left = NULL;
	}
	_freeBST(node);
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{

	/* Write This */
	assert(tree != NULL);
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{

	/* Write This */
	assert(tree != NULL);
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) { 
	/* Write This */
	assert(tree != NULL);
	return (!tree->cnt); /* temporary return val */
}


/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { 
	/* Write This */
	assert(tree != NULL);
	return (tree->cnt);    /* Temporary return valu */
}



/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)
{
	/*write this*/
	assert(val != NULL);
	if (cur == NULL)
	{
		struct Node *newNode = malloc(sizeof(struct Node));
		newNode->val = val;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	if (compare(cur->val, val) == 1 || compare(cur->val, val) == 0)
		cur->left = _addNode(cur->left, val);
	else    //(compare(cur->val, val) == -1)
		cur->right = _addNode(cur->right, val);
    return cur;
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
	val is not null
 
pose:  tree size increased by 1
	tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
    assert(tree != NULL);
    assert(val != NULL);
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}

/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	/*write this*/
	assert(tree != NULL);
	assert(val != NULL);
	struct Node *temp = tree->root;
	while (temp != NULL)
	{
		if (compare(temp->val, val) == 0)
			return 1;
		else if (compare(temp->val, val) == -1)
			temp = temp->right;
		else    // (compare(temp->val, val) == 1)
			temp = temp->left;
	}
	//printf("No such value contained in this Tree!\n");
	return 0;
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	/*write this*/
	assert(cur != NULL);
	struct Node *temp = cur;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	/*write this*/
	assert(cur != NULL);
	if (cur->left != NULL)
	{
		cur->left = _removeLeftMost(cur->left);
		return cur;
	}
	else
	{
		struct Node *temp = cur->right;
		free(cur);
		return temp;
	}
}


/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	/*write this*/
	assert(val != NULL);
    //assert(cur != NULL);
    
	if (cur != NULL)
	{
    if (compare(cur->val, val) == 0)
    {
        cur->val = _leftMost(cur);
        cur = _removeLeftMost(cur);
    }
    else if (compare(cur->val, val) == 1)
    {
        cur->left = _removeNode(cur->left, val);
    }
    else    // (compare(cur->val, val) == -1)
    {
        cur->right = _removeNode(cur->right, val);
    }
    }
	else
		printf("The Value is not in this BSTree!\n");
	return cur;
}


/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
	val		the value to be removed from the tree
 pre:	tree is not null
	val is not null
	val is in the tree
 
pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{

	/* Write This */
	assert(tree != NULL);
	assert(val != NULL);
	tree->root = _removeNode(tree->root, val);
	tree->cnt--;
}

struct BSTree *buildBSTTree() {
    struct BSTree *tree	= newBSTree();		
		
	/*Create value of the type of data that you want to store*/
	struct data *myData0 = (struct data *) malloc(sizeof(struct data));
	struct data *myData1 = (struct data *) malloc(sizeof(struct data));
	struct data *myData2 = (struct data *) malloc(sizeof(struct data));
	struct data *myData3 = (struct data *) malloc(sizeof(struct data));
	struct data *myData4 = (struct data *) malloc(sizeof(struct data));
	struct data *myData5 = (struct data *) malloc(sizeof(struct data));
	struct data *myData6 = (struct data *) malloc(sizeof(struct data));
	struct data *myData7 = (struct data *) malloc(sizeof(struct data));
	struct data *myData8 = (struct data *) malloc(sizeof(struct data));
	struct data *myData9 = (struct data *) malloc(sizeof(struct data));
	struct data *myData10 = (struct data *) malloc(sizeof(struct data));
	struct data *myData11 = (struct data *) malloc(sizeof(struct data));
	struct data *myData12 = (struct data *) malloc(sizeof(struct data));
	struct data *myData13 = (struct data *) malloc(sizeof(struct data));
	struct data *myData14 = (struct data *) malloc(sizeof(struct data));
		

	myData0->number = 80;
	myData0->name = "Can it fly";
	myData1->number = 40;
	myData1->name = "Does it have feather";
	myData2->number = 120;
	myData2->name = "Does it live in the sea";
	myData3->number = 20;
	myData3->name = "Is it blue";
	myData4->number = 60;
	myData4->name = "Does it make noise";
	myData5->number = 100;
	myData5->name = "Is it vertebrate";
	myData6->number = 140;
	myData6->name = "Is it herbivore";
	myData7->number = 10;
	myData7->name = "Is it bluejay";
	myData8->number = 30;
	myData8->name = "Is it eagle";
	myData9->number = 50;
	myData9->name = "Is it bee";
	myData10->number = 70;
	myData10->name = "Is it butterfly";
	myData11->number = 90;
	myData11->name = "Is it beaver";
	myData12->number = 110;
	myData12->name = "Is it jellyfish";
	myData13->number = 130;
	myData13->name = "Is it duck";
	myData14->number = 150;
	myData14->name = "Is it lion";
	
	/*add the values to BST*/
	addBSTree(tree, myData0);
	addBSTree(tree, myData1);
	addBSTree(tree, myData2);
	addBSTree(tree, myData3);
	addBSTree(tree, myData4);
	addBSTree(tree, myData5);
	addBSTree(tree, myData6);
	addBSTree(tree, myData7);
	addBSTree(tree, myData8);
	addBSTree(tree, myData9);
	addBSTree(tree, myData10);
	addBSTree(tree, myData11);
	addBSTree(tree, myData12);
	addBSTree(tree, myData13);
	addBSTree(tree, myData14);
    
    return tree;
}

struct BSTree *scanAdd(struct BSTree *tree, struct Node *temp)
{
	printf("Would you like to help us improve the game by adding your animal to this game?(yes, no, or exit)\n");
	char *val = malloc(20 * sizeof(char));
	scanf("%s", val);
	if (strcmp(val, "yes") == 0)
	{
		printf("Please think of a question about the animal you are thinking:\n(testing function --- please type with no space): ");
		struct data *myData = (struct data *) malloc(sizeof(struct data));
		myData->name = malloc(50 * sizeof(char));
		setbuf(stdin, NULL);
		scanf("%[^\n]", myData->name);
		myData->number = ((struct data *)temp->val)->number + 2;

		printf("Please type the animal's name: ");
		struct data *myData1 = (struct data *) malloc(sizeof(struct data));
		myData1->name = malloc(20 * sizeof(char));
		scanf("%s", myData1->name);
		myData1->number = ((struct data *)temp->val)->number + 1;

		addBSTree(tree, myData);
		addBSTree(tree, myData1);
		printf("......\nCongratulations! Data saved!\n");
	}
	else if (strcmp(val, "no") == 0)
	{
		//no codes needed here
	}
	else if (strcmp(val, "exit") == 0)
	{
		//no codes needed here
	}
	else
	{
		printf("Wrong input. Please type again.\n");
		tree = scanAdd(tree, temp);
	}
	free(val);
	return tree;
}

void printNode(struct Node *cur) {
	if (cur == 0) return;
	printf("> ");
	print_type(cur->val);
	printf("?\n");
}

struct Node *playagain(struct BSTree *tree, struct Node *cur)
{
	printf("Would you like to play again?(yes, no, or exit)\n");
	char *val = malloc(4 * sizeof(char));
	scanf("%s", val);
	if (strcmp(val, "yes") == 0)
		cur = tree->root;
	else if (strcmp(val, "no") == 0)
		cur = NULL;
	else if (strcmp(val, "exit") == 0)
		cur = NULL;
	else
	{
		printf("Wrong input. Please type again.\n");
		cur = playagain(tree, cur);
	}
	free(val);
	return cur;
}

struct Node *scanNode(struct BSTree *tree, struct Node *cur)
{
	struct Node *temp = cur;
	char *val = malloc(4 * sizeof(char));
	scanf("%s", val);
	if (cur != NULL)
	{
		if (strcmp(val, "yes") == 0)
			cur = cur->left;
		else if (strcmp(val, "no") == 0)
			cur = cur->right;
		else if (strcmp(val, "exit") == 0)
			cur = NULL;
		else
			printf("Wrong input. Please answer again.\n");
	}
	if (cur == NULL)
	{
        if (strcmp(val, "exit") == 0) {
            printf("See you next time!\n");
            return cur;
        }
		if (strcmp(val, "yes") == 0)
			printf("Excellent! I knew it!\n");
		else if (strcmp(val, "no") == 0)
		{
			printf("Sorry! I don't know what animal you are thinking...\n");
			tree = scanAdd(tree, temp);
		}
		else
            printf("Wrong input. Please answer again.\n");
		cur = playagain(tree, cur); 
		while (cur != NULL)
		{
			printNode(cur);
			cur = scanNode(tree, cur);
		}
	}
	free(val);
	return cur;
}



int main(int argc, char *argv[])
{	
	struct BSTree *animal = buildBSTTree();
	struct Node *cur = animal->root;
	printf("Welcome to Animal Game!\n\nInstructions:\n\t1st, please think of an animal.\n");
	printf("\t2nd, please answer 'yes' or 'no' for the questions.\n");
	printf("\nYou can type 'exit' anytime if you don't want to play any more =_=\n");
	printf("Have fun!\n\nNow, Game Start......\n");
	while (cur != NULL)
	{
		printNode(cur);	
		cur = scanNode(animal, cur);
	}
	printf("Game Finshed. Thank you for playing!\n");
	deleteBSTree(animal);
	return 0;
}
