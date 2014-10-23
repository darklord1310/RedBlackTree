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
		maintainTreeStructureWhenDataSmallerThanNode(&(*rootPtr));
	}
	else
    {
		_addRedBlackTree(&root->right, newNode);
        maintainTreeStructureWhenDataLargerThanNode(&(*rootPtr));
    }
}


void maintainTreeStructureWhenDataSmallerThanNode(Node **nodePtr)
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



void maintainTreeStructureWhenDataLargerThanNode(Node **nodePtr)
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




Node *delRedBlackTree(Node **rootPtr, Node *delnode)
{
    Node *node = _delRedBlackTree(rootPtr, delnode);
    
    if( *rootPtr != NULL)
        (*rootPtr)->color = 'b';
     

    return node;
}




Node *_delRedBlackTree(Node **rootPtr, Node *delnode)
{
    if( (*rootPtr)->left == NULL  && (*rootPtr)->right == NULL)
    {
        if( (*rootPtr)->data == delnode->data)
        {
            *rootPtr = NULL;
            return delnode;
        }
        else
            Throw(ERR_NO_NODE_UNAVAILABLE);
    }


    if ( (*rootPtr)->data <  delnode->data)
        _delRedBlackTree(&(*rootPtr)->right, delnode);
    else if ( (*rootPtr)->data >  delnode->data)
        _delRedBlackTree(&(*rootPtr)->left, delnode);
    
}

