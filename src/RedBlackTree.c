#include "RedBlackTree.h"
#include <stdio.h>
#include "ErrorCode.h"


void addRedBlackTree(Node **rootPtr, Node *newNode)
{
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';

}



void _addRedBlackTree(Node **rootPtr, Node *newNode)
{
	Node *root;
	root = *rootPtr;
	
	if(root == NULL)
	{
		*rootPtr = newNode;
		return;
	}
		
	if(newNode->data < (*root).data)
	{
		_addRedBlackTree(&root->left, newNode);
		changeNodeColorWhenDataSmallerThanNode(&(*rootPtr));
	}
	else
    {
		_addRedBlackTree(&root->right, newNode);
        changeNodeColorWhenDataLargerThanNode(&(*rootPtr));
    }
}


void changeNodeColorWhenDataSmallerThanNode(Node **nodePtr)
{
	Node *tempnode = *nodePtr;
	tempnode = tempnode->left;
	if(tempnode->color == 'r')
	{
		if(tempnode->left != NULL)
		{
			tempnode = tempnode->left;
			if(tempnode->color == 'r')
			{
				(*nodePtr)->color = 'r';
				rightRotate(&(*nodePtr));
			}
		}
        
        if(tempnode->right != NULL)
        {
            tempnode = tempnode->right;
			if(tempnode->color == 'r')
			{
				(*nodePtr)->color = 'r';
				leftRightRotate(&(*nodePtr));
			}
        }
	}
}



void changeNodeColorWhenDataLargerThanNode(Node **nodePtr)
{
	Node *tempnode = *nodePtr;
	tempnode = tempnode->right;
	if(tempnode->color == 'r')
	{
		if(tempnode->right != NULL)
		{
			tempnode = tempnode->right;
			if(tempnode->color == 'r')
			{
				(*nodePtr)->color = 'r';
				leftRotate(&(*nodePtr));
			}
		}
        
        if(tempnode->left != NULL)
        {
            tempnode = tempnode->left;
			if(tempnode->color == 'r')
			{
				(*nodePtr)->color = 'r';
				rightLeftRotate(&(*nodePtr));
			}
        }
	}
}


