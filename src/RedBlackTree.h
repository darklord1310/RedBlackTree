#ifndef RedBlackTree_H
#define RedBlackTree_H
#include "Node.h"


void addRedBlackTree(Node **rootPtr, Node *newnode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
void maintainTreeStructureWhenDataSmallerThanNode(Node **nodePtr);
void maintainTreeStructureWhenDataLargerThanNode(Node **nodePtr);
Node *delRedBlackTree(Node **rootPtr, Node *delnode);
Node *_delRedBlackTree(Node **rootPtr, Node *delnode);
void colorFlippingforDel(Node **rootPtr);


#endif // RedBlackTree_H
