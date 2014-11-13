#ifndef RedBlackTree_H
#define RedBlackTree_H
#include "Node.h"


typedef enum {BLACK, RED, DOUBLEBLACK} NodeColor;
typedef enum {NOT_FOUR_NODE, FOUR_NODE} identify4Node;
typedef enum {case1, case2, case3} cases;

void addRedBlackTree(Node **rootPtr, Node *newnode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
void checkAndrotateWhenDataSmallerThanNode(Node **nodePtr);
void checkAndrotateWhenDataLargerThanNode(Node **nodePtr);
Node *delRedBlackTree(Node **rootPtr, Node *delnode);
Node *_delRedBlackTree(Node **rootPtr, Node *delnode);
Node *_delRedBlackTreeX(Node **rootPtr, Node *delnode);
void colorFlippingForDel(Node **rootPtr);
void colorFlippingForAdd(Node **rootPtr);
int checkNodeColor(Node **rootPtr);
int identify4node(Node **nodePtr);
int checkCases(Node **rootPtr);
int IsCase1(Node **rootPtr);
int IsCase2(Node **rootPtr);
int IsCase3(Node **rootPtr);
void forceNodeColorToBlack(Node **rootPtr);
void forceNodeColorToRed(Node **rootPtr);
void executeCasesWhenReturnFromLeft(int cases, Node **rootPtr);
void executeCasesWhenReturnFromRight(int cases, Node **rootPtr);
void RestructureRightChild(Node **rootPtr);
void RestructureLeftChild(Node **rootPtr);
Node *removeNextLargerSuccessor(Node **parentPtr);

#endif // RedBlackTree_H
