#include "RedBlackTree.h"
#include <stdio.h>
#include "ErrorCode.h"


void addRedBlackTree(Node **rootPtr, Node *newNode)
{
	_addRedBlackTree(rootPtr, newNode);
    (*rootPtr)->color = 'b';
}


//0 indicate not fournode, 1 indicate fournode
int identify4node(Node **nodePtr)
{
    int left, right;
        
    left = checkNodeColor(&(*nodePtr)->left);
    right = checkNodeColor(&(*nodePtr)->right);
    
    if(left == RED && right == RED)
        return FOUR_NODE;
    else
        return NOT_FOUR_NODE;
}



void _addRedBlackTree(Node **rootPtr, Node *newNode)
{
    int indicator;
    
	if(*rootPtr == NULL)
	{  
		*rootPtr = newNode;
		return;
	}

	if(newNode->data < (*rootPtr)->data)
	{
        indicator = identify4node(rootPtr);
		_addRedBlackTree(&(*rootPtr)->left, newNode);
        if(indicator == NOT_FOUR_NODE)
            checkAndrotateWhenDataSmallerThanNode(rootPtr);
        else
        {
            (*rootPtr)->color = 'r';
            colorFlippingForAdd(&(*rootPtr)->left);
            colorFlippingForAdd(&(*rootPtr)->right);
        }
	}
	else
    {
         indicator = identify4node(rootPtr);
		_addRedBlackTree(&(*rootPtr)->right, newNode);
        if(indicator == NOT_FOUR_NODE)
            checkAndrotateWhenDataLargerThanNode(rootPtr);
        else
        {
            (*rootPtr)->color = 'r';
            colorFlippingForAdd(&(*rootPtr)->left);
            colorFlippingForAdd(&(*rootPtr)->right);
        }
    }
}


void checkAndrotateWhenDataSmallerThanNode(Node **nodePtr)
{
	Node *tempnode = *nodePtr;
    int color;
    
    if(tempnode->left != NULL)
        color = checkNodeColor(&tempnode->left);
 
	if(color == RED)
	{
        tempnode = tempnode->left;
		if(tempnode->left != NULL)
		{
            color = checkNodeColor(&tempnode->left);
			if(color == RED)
			{
				(*nodePtr)->color = 'r';
				rightRotate(&(*nodePtr));
			}
		}
        else if(tempnode->right != NULL)
        {
            color = checkNodeColor(&tempnode->right);
			if(color == RED)
			{
				(*nodePtr)->color = 'r';
				leftRightRotate(&(*nodePtr));
			}
        }
	}
}



void checkAndrotateWhenDataLargerThanNode(Node **nodePtr)
{
	Node *tempnode = *nodePtr;
    int color;
    
    if(tempnode->right != NULL)
        color = checkNodeColor(&tempnode->right);
	
	if(color == RED)
	{
        tempnode = tempnode->right;
		if(tempnode->right != NULL)
		{
			color = checkNodeColor(&tempnode->right);
			if(color == RED)
			{
				(*nodePtr)->color = 'r';
				leftRotate(&(*nodePtr));
			}
		}
        else if(tempnode->left != NULL)
        {
            color = checkNodeColor(&tempnode->left);
			if(color == RED)
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
    Node *node;
    int left,right;
    
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
    {
        node = _delRedBlackTree(&(*rootPtr)->right, delnode);
        left = checkNodeColor(&(*rootPtr)->left);
        right = checkNodeColor(&(*rootPtr)->right);
        
        if(left == BLACK && right == RED)
            colorFlippingForDel(&(*rootPtr)->right);
        else if(left == BLACK && right == BLACK)
            colorFlippingForDel(&(*rootPtr)->left);
    }
    else
    {
        left = checkNodeColor(&(*rootPtr)->left);
        right = checkNodeColor(&(*rootPtr)->right);
        
        if(left == BLACK && right == RED)
        {
            leftRotate(&(*rootPtr));
            node = _delRedBlackTree(&(*rootPtr)->left, delnode);
        }
        else if(left == BLACK && right == BLACK)
        {
            node = _delRedBlackTree(&(*rootPtr)->left, delnode);
            colorFlippingForDel(&(*rootPtr)->right);
        }
        else
            node = _delRedBlackTree(&(*rootPtr)->left, delnode);
    }
    
    return node;
}



void colorFlippingForDel(Node **rootPtr)
{
    if( *rootPtr != NULL)
    {
        if( (*rootPtr)->color == 'b')
            (*rootPtr)->color = 'r';
        else if( (*rootPtr)->color == 'r')
            (*rootPtr)->color = 'b';
    }
}



void colorFlippingForAdd(Node **rootPtr)
{
    if( *rootPtr != NULL)
    {
        if( (*rootPtr)->color == 'r')
            (*rootPtr)->color = 'b';
    }
}


//0 indicate b, 1 indicate r
int checkNodeColor(Node **rootPtr)
{
    if( *rootPtr != NULL)
    {
        if( (*rootPtr)->color == 'b')
            return BLACK;
        else
            return RED;
    }
}