#include "Rotations.h"
#include "Node.h"
#include <stdio.h>

void rightRotate(Node **nodePtr)
{
	Node *tempnode;
	setNode(&tempnode, NULL, NULL, 'b');
	tempnode = *nodePtr;
	
	
	*nodePtr = (*nodePtr)->left;
	if( (*nodePtr)->right == NULL)
	{
		(*nodePtr)->right = tempnode;
		tempnode->left = NULL;
	}
	else
	{
		tempnode->left = (*nodePtr)->right;
		(*nodePtr)->right = tempnode;
	}
}


void leftRotate(Node **nodePtr)
{
	Node *tempnode;
	setNode(&tempnode, NULL, NULL, 'b');
	tempnode = *nodePtr;
	
	
	*nodePtr = (*nodePtr)->right;
	if( (*nodePtr)->left == NULL)
	{
		(*nodePtr)->left = tempnode;
		tempnode->right = NULL;
	}
	else
	{
		tempnode->right = (*nodePtr)->left;
		(*nodePtr)->left = tempnode;
	}
}



void leftRightRotate(Node **nodePtr)
{
	leftRotate(&(*nodePtr)->left);
	rightRotate(&(*nodePtr));
}



void rightLeftRotate(Node **nodePtr)
{
	rightRotate(&(*nodePtr)->right);
	leftRotate(&(*nodePtr));

}

