#ifndef RedBlackTree_H
#define RedBlackTree_H
#include "Node.h"


typedef enum {BLACK, RED} NodeColor;
typedef enum {NOT_FOUR_NODE, FOUR_NODE} identify4Node;


void addRedBlackTree(Node **rootPtr, Node *newnode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
void checkAndrotateWhenDataSmallerThanNode(Node **nodePtr);
void checkAndrotateWhenDataLargerThanNode(Node **nodePtr);
Node *delRedBlackTree(Node **rootPtr, Node *delnode);
Node *_delRedBlackTree(Node **rootPtr, Node *delnode);
void colorFlippingForDel(Node **rootPtr);
void colorFlippingForAdd(Node **rootPtr);
int checkNodeColor(Node **rootPtr);
int identify4node(Node **nodePtr);

#endif // RedBlackTree_H
