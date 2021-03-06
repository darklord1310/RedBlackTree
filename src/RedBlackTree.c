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


void colorFlippingForAdd(Node **rootPtr)
{
    if( *rootPtr != NULL)
    {
        if( (*rootPtr)->color == 'r')
            (*rootPtr)->color = 'b';
    }
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




// void colorFlippingForDel(Node **rootPtr)
// {
    // if( *rootPtr != NULL)
    // {
        // if( (*rootPtr)->color == 'b')
            // (*rootPtr)->color = 'r';
        // else if( (*rootPtr)->color == 'r')
            // (*rootPtr)->color = 'b';
    // }
// }


// Node *_delRedBlackTreeX(Node **rootPtr, Node *delnode)
// {
    // Node *node, *travelnode;
    
    // if( (*rootPtr)->left == NULL  && (*rootPtr)->right == NULL)
    // {
        // if( (*rootPtr)->data == delnode->data)
        // {
            // *rootPtr = NULL;
            // return delnode;
        // }
        // else
            // Throw(ERR_NO_NODE_UNAVAILABLE);
    // }
    
    // if ( (*rootPtr)->data <  delnode->data)
    // {
        // node = _delRedBlackTreeX(&(*rootPtr)->right, delnode);
    
        // if((*rootPtr)->right == NULL)
        // {
            // if(checkNodeColor(&(*rootPtr)->left) == BLACK)
            // {
                // colorFlippingForDel(&(*rootPtr)->left);
                // if(checkNodeColor(&(*rootPtr)->left) == RED && checkNodeColor(rootPtr) == RED)
                    // colorFlippingForDel(rootPtr);
            // }
            // if((*rootPtr)->left != NULL)
                // travelnode = (*rootPtr)->left;
            // if( (*rootPtr)->left != NULL && (travelnode->right != NULL || travelnode->left != NULL)     )
            // {
                // rightRotate(&(*rootPtr));
                // if((*rootPtr)->right != NULL)
                    // travelnode = (*rootPtr)->right;
                // colorFlippingForDel(&travelnode->left);
            // } 
        // }
    // }
    // else
    // {
        // node = _delRedBlackTreeX(&(*rootPtr)->left, delnode);

        // if(checkNodeColor(&(*rootPtr)->right) == BLACK)
        // {
            // colorFlippingForDel(&(*rootPtr)->right);
            // if(checkNodeColor(&(*rootPtr)->right) == RED && checkNodeColor(rootPtr) == RED)
                // colorFlippingForDel(rootPtr);
        // }
            
        // if((*rootPtr)->right != NULL)
            // travelnode = (*rootPtr)->right;
        // if( (*rootPtr)->left == NULL && (*rootPtr)->right != NULL && (travelnode->right != NULL || travelnode->left != NULL)     )
        // {
            // leftRotate(&(*rootPtr));
            // if((*rootPtr)->left != NULL)
                // travelnode = (*rootPtr)->left;
            // colorFlippingForDel(&travelnode->right);
        // } 
    // }
    
    // return node;
// }




Node *delRedBlackTree(Node **rootPtr, Node *delnode)
{
    Node *node = _delRedBlackTree(rootPtr, delnode);
    if( *rootPtr != NULL)
        (*rootPtr)->color = 'b';

    return node;
}



Node *_delRedBlackTree(Node **rootPtr, Node *delnode)
{
    Node *node, *temp;
    int cases;
    
    if( (*rootPtr)->data == delnode->data)
    {
        if( (*rootPtr)->left != NULL  ||  (*rootPtr)->right != NULL)
        {
            if( (*rootPtr)->right != NULL)
            {
                temp = (*rootPtr)->left;
                printf("find successor\n");
                *rootPtr = removeNextLargerSuccessor( &(*rootPtr)->right );
                printf("sucessor : %d\n", (*rootPtr)->data);
                (*rootPtr)->left = temp;
                printf("root left : %d\n", (*rootPtr)->left->data);
                RestructureLeftChild(&(*rootPtr), (*rootPtr) );
            }
            else
                *rootPtr = (*rootPtr)->left;
            return delnode;
        }
        else
        {
            *rootPtr = NULL;
            return delnode;
        }
    }
    else
    {
        if( (*rootPtr)->left == NULL  && (*rootPtr)->right == NULL)
            Throw(ERR_NO_NODE_UNAVAILABLE);
    }
    
    if ( (*rootPtr)->data <  delnode->data)
    {
        node = _delRedBlackTree(&(*rootPtr)->right, delnode);
        printf("restructure\n");
        RestructureLeftChild(&(*rootPtr), node);
    }
    else
    {
        node = _delRedBlackTree(&(*rootPtr)->left, delnode);
        RestructureRightChild(&(*rootPtr), node);
    }
    return node;
}


void RestructureLeftChild(Node **rootPtr, Node *removedNode)
{
    int cases;
            printf("asd\n");
        if( (*rootPtr)->right != NULL)
            printf("root right : %c\n", (*rootPtr)->right->color);
    if( isDoubleBlack(&(*rootPtr)->right, removedNode) == DOUBLEBLACK)
    {
        if( (*rootPtr)->left != NULL)
        {
            cases = checkCases(&(*rootPtr)->left);
            printf("cases :%d\n", cases); 
            executeCasesWhenReturnFromRight(cases, &(*rootPtr));
        }
        
        //check to see need to restructure or not
        if( (*rootPtr)->right != NULL && (*rootPtr)->right->color != 'd')
        {
            if( isDoubleBlack(&(*rootPtr)->right->right, removedNode) == DOUBLEBLACK && (*rootPtr)->right->left != NULL)
            {
                cases = checkCases(&(*rootPtr)->right->left);
                executeCasesWhenReturnFromRight(cases, &(*rootPtr)->right);               
            }
        }
        
        if( (*rootPtr)->right != NULL && (*rootPtr)->right->color == 'd')
            (*rootPtr)->right->color = 'b';
    }
}



void RestructureRightChild(Node **rootPtr, Node *removedNode)
{
    int cases;
    if( isDoubleBlack(&(*rootPtr)->left, removedNode) == DOUBLEBLACK)
    {
        if( (*rootPtr)->right != NULL)
        {   
            cases = checkCases(&(*rootPtr)->right);
            executeCasesWhenReturnFromLeft(cases, &(*rootPtr));
        }
        
        //check to see need to restructure or not
        if( (*rootPtr)->left != NULL && (*rootPtr)->left->color != 'd')
        {
            if( isDoubleBlack(&(*rootPtr)->left->left, removedNode) == DOUBLEBLACK && (*rootPtr)->left->right != NULL  )
            {
                cases = checkCases(&(*rootPtr)->left->right);
                executeCasesWhenReturnFromLeft(cases, &(*rootPtr)->left);    
            }
        }
        
        if( (*rootPtr)->left != NULL && (*rootPtr)->left->color == 'd')
            (*rootPtr)->left->color = 'b';
    }
}




//0 indicate b, 1 indicate r
int checkNodeColor(Node **rootPtr)
{
    if( *rootPtr != NULL)
    {
        if( (*rootPtr)->color == 'b')
            return BLACK;
        else if( (*rootPtr)->color == 'r')
            return RED;
    }
    else
        return BLACK;
}


void forceNodeColorToRed(Node **rootPtr)
{
    (*rootPtr)->color = 'r';
}


void forceNodeColorToBlack(Node **rootPtr)
{
    (*rootPtr)->color = 'b';
}


int isDoubleBlack(Node **rootPtr, Node *removeNode)
{
    if( (*rootPtr == NULL || (*rootPtr)->color == 'd') && removeNode->color == 'b' )
        return DOUBLEBLACK;
    else
        return 0;
}



int checkCases(Node **rootPtr)
{
    if(IsCase1(&(*rootPtr)) == 1)
        return case1;
    else if(IsCase2(&(*rootPtr)) == 1)
        return case2;
    else if(IsCase3(&(*rootPtr)) == 1)
        return case3;
}


int IsCase1(Node **rootPtr)
{
    if( (*rootPtr)->color == 'b' && ( checkNodeColor(&(*rootPtr)->right) == RED || checkNodeColor(&(*rootPtr)->left) == RED )   )
        return 1;
    else
        return 0;
}


int IsCase2(Node **rootPtr)
{    
    if( checkNodeColor(&(*rootPtr)) == BLACK && checkNodeColor(&(*rootPtr)->right) == BLACK && checkNodeColor(&(*rootPtr)->left) == BLACK  )
        return 1;
    else
        return 0;
}


int IsCase3(Node **rootPtr)
{    
    if( (*rootPtr)->color == 'r')
        return 1;
    else
        return 0;
}



void executeCasesWhenReturnFromLeft(int cases, Node **rootPtr)
{
    if( cases == case1)
    {
        if( checkNodeColor(&(*rootPtr)->right->right) == RED)
        {
            leftRotate(&(*rootPtr));
            if( checkNodeColor(&(*rootPtr)->left) == RED)
                forceNodeColorToRed(&(*rootPtr));
            else if( checkNodeColor(&(*rootPtr)->left) == BLACK )
                forceNodeColorToBlack(&(*rootPtr));
            forceNodeColorToBlack(&(*rootPtr)->left);
            forceNodeColorToBlack(&(*rootPtr)->right);
        }
        else if( checkNodeColor(&(*rootPtr)->right->left) == RED)
        {
            rightLeftRotate(&(*rootPtr));
            if( checkNodeColor(&(*rootPtr)->left) == RED)
                forceNodeColorToRed(&(*rootPtr));
            else if( checkNodeColor(&(*rootPtr)->left) == BLACK )
                forceNodeColorToBlack(&(*rootPtr));
            forceNodeColorToBlack(&(*rootPtr)->left);
            forceNodeColorToBlack(&(*rootPtr)->right);
        }
    }
    else if( cases == case2 )
    {
        if( (*rootPtr)->color == 'b')
            (*rootPtr)->color = 'd';
        else if( (*rootPtr)->color == 'r' )
            (*rootPtr)->color = 'b';
        forceNodeColorToRed(&(*rootPtr)->right);
    }
    else if( cases == case3 )
    {
        leftRotate(&(*rootPtr));
        forceNodeColorToBlack(&(*rootPtr));
        forceNodeColorToRed(&(*rootPtr)->left);
    }
}


void executeCasesWhenReturnFromRight(int cases, Node **rootPtr)
{
    if( cases == case1)
    {
        printf("case1\n");
        if( checkNodeColor(&(*rootPtr)->left->left) == RED)
        {
            rightRotate(&(*rootPtr));
            if( checkNodeColor(&(*rootPtr)->right) == RED)
                forceNodeColorToRed(&(*rootPtr));
            else if( checkNodeColor(&(*rootPtr)->right) == BLACK )
                forceNodeColorToBlack(&(*rootPtr));
            forceNodeColorToBlack(&(*rootPtr)->left);
            forceNodeColorToBlack(&(*rootPtr)->right);
        }
        else if( checkNodeColor(&(*rootPtr)->left->right) == RED)
        {
            leftRightRotate(&(*rootPtr));
            if( checkNodeColor(&(*rootPtr)->right) == RED)
                forceNodeColorToRed(&(*rootPtr));
            else if( checkNodeColor(&(*rootPtr)->right) == BLACK )
                forceNodeColorToBlack(&(*rootPtr));
            forceNodeColorToBlack(&(*rootPtr)->left);
            forceNodeColorToBlack(&(*rootPtr)->right);
        }
    }
    else if( cases == case2 )
    {   printf("case2\n");
        if( (*rootPtr)->color == 'b')
            (*rootPtr)->color = 'd';
        else if( (*rootPtr)->color == 'r' )
            (*rootPtr)->color = 'b';
        forceNodeColorToRed(&(*rootPtr)->left);
    }
    else if( cases == case3 )
    {
        printf("case3\n");
        rightRotate(&(*rootPtr));
        forceNodeColorToBlack(&(*rootPtr));
        forceNodeColorToRed(&(*rootPtr)->right);
    }
}




Node *removeNextLargerSuccessor(Node **parentPtr)
{
    Node *successorNode;
    
    if( (*parentPtr)->left != NULL)
    {
        successorNode = removeNextLargerSuccessor(&(*parentPtr)->left);
        RestructureRightChild( &(*parentPtr) , successorNode);
        return successorNode;
    }
    else
    {
        if( (*parentPtr)->right == NULL)
        {
            successorNode = *parentPtr;
            *parentPtr = NULL;
            return successorNode;
        }
        else
        {
            successorNode = *parentPtr;
            *parentPtr = (*parentPtr)->right;
            forceNodeColorToBlack(&(*parentPtr));
            return successorNode;
        }
    }
}




