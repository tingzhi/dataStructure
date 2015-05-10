/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"


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
	if (compare(cur->val, val) == 1)
		cur->left = _addNode(cur->left, val);
	else if (compare(cur->val, val) == -1)
		cur->right = _addNode(cur->right, val);
	else if (compare(cur->val, val) == 0)
		cur->left = _addNode(cur->left, val);
	else
		printf("Compare Function Error!\n");
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
		else if (compare(temp->val, val) == 1)
			temp = temp->left;
		else
			printf("Compare Function Error!\n");
	}
	printf("No such value contained in this Tree!\n");
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
		else if (compare(cur->val, val) == -1)
		{
			cur->right = _removeNode(cur->right, val);
		}
		else
			printf("Compare Function Error!\n");
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

/*
function to print the result of a test function
param: predicate:  the result of the test 
       nameTestFunction : the name of the function that has been tested
	   message
*/
void printTestResult(int predicate, char *nameTestFunction, char *message){
	if (predicate)
	   printf("%s(): PASS %s\n",nameTestFunction, message);
    else
	   printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

int main(int argc, char *argv[]){	

	return 0;
}
