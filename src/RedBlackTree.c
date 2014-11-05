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
    if(checkNodeColor(&(*nodePtr)->right) == RED && checkNodeColor(&(*nodePtr)->left) == RED)
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
        if( indicator == NOT_FOUR_NODE)
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
        if( indicator == NOT_FOUR_NODE)
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
    
    if(tempnode->left != NULL)
    {
        if(checkNodeColor(&tempnode->left) == RED)
        {
            tempnode = tempnode->left;
            if(tempnode->left != NULL)
            {
                if(checkNodeColor(&tempnode->left) == RED)
                {
                    (*nodePtr)->color = 'r';
                    rightRotate(&(*nodePtr));
                }
            }
            else if(tempnode->right != NULL)
            {
                if(checkNodeColor(&tempnode->right) == RED)
                {
                    (*nodePtr)->color = 'r';
                    leftRightRotate(&(*nodePtr));
                }
            }
        }
    }
}



void checkAndrotateWhenDataLargerThanNode(Node **nodePtr)
{
	Node *tempnode = *nodePtr;
    
    if(tempnode->right != NULL)
	{
        if(checkNodeColor(&tempnode->right) == RED)
        {
            tempnode = tempnode->right;
            if(tempnode->right != NULL)
            {
                if(checkNodeColor(&tempnode->right) == RED)
                {
                    (*nodePtr)->color = 'r';
                    leftRotate(&(*nodePtr));
                }
            }
            else if(tempnode->left != NULL)
            {
                if(checkNodeColor(&tempnode->left) == RED)
                {
                    (*nodePtr)->color = 'r';
                    rightLeftRotate(&(*nodePtr));
                }
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
    Node *node, *travelnode;
    
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
    
        if((*rootPtr)->right == NULL)
        {
            if(checkNodeColor(&(*rootPtr)->left) == BLACK)
            {
                colorFlippingForDel(&(*rootPtr)->left);
                if(checkNodeColor(&(*rootPtr)->left) == RED && checkNodeColor(rootPtr) == RED)
                    colorFlippingForDel(rootPtr);
            }
            if((*rootPtr)->left != NULL)
                travelnode = (*rootPtr)->left;
            if( (*rootPtr)->left != NULL && (travelnode->right != NULL || travelnode->left != NULL)     )
            {
                rightRotate(&(*rootPtr));
                if((*rootPtr)->right != NULL)
                    travelnode = (*rootPtr)->right;
                colorFlippingForDel(&travelnode->left);
            } 
        }
    }
    else
    {
        node = _delRedBlackTree(&(*rootPtr)->left, delnode);

        if(checkNodeColor(&(*rootPtr)->right) == BLACK)
        {
            colorFlippingForDel(&(*rootPtr)->right);
            if(checkNodeColor(&(*rootPtr)->right) == RED && checkNodeColor(rootPtr) == RED)
                colorFlippingForDel(rootPtr);
        }
            
        if((*rootPtr)->right != NULL)
            travelnode = (*rootPtr)->right;
        if( (*rootPtr)->left == NULL && (*rootPtr)->right != NULL && (travelnode->right != NULL || travelnode->left != NULL)     )
        {
            leftRotate(&(*rootPtr));
            if((*rootPtr)->left != NULL)
                travelnode = (*rootPtr)->left;
            colorFlippingForDel(&travelnode->right);
        } 
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


