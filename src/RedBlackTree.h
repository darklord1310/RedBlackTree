#ifndef RedBlackTree_H
#define RedBlackTree_H
#include "Node.h"


void addRedBlackTree(Node **rootPtr, Node *newnode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
void changeNodeColorWhenDataSmallerThanNode(Node **nodePtr);
void changeNodeColorWhenDataLargerThanNode(Node **nodePtr);

#endif // RedBlackTree_H
