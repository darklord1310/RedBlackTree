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
		printf("asd\n");
		changeNodeColor(&(*rootPtr));
	}
	else
		_addRedBlackTree(&root->right, newNode);
}


void changeNodeColor(Node **nodePtr)
{
	printf("%d\n", (*nodePtr)->data);
	Node *tempnode = *nodePtr;
	tempnode = tempnode->left;
	printf("%d\n", tempnode->data);
	if(tempnode->color == 'r')
	{
		if(tempnode->left != NULL)
		{
			tempnode = tempnode->left;
			printf("%d\n", (*nodePtr)->data);
			printf("%p\n", *nodePtr);
			if(tempnode->color == 'r')
			{
				(*nodePtr)->color = 'r';
				rightRotate(&(*nodePtr));
			}
		}
	}
}