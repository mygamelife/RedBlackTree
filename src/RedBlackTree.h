#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode);
Node *delRedBlackTree(Node **rootPtr, Node *removeNode);
Node *delRedBlackTreex(Node **rootPtr, Node *removeNode);
Node *_delRedBlackTree(Node **rootPtr, Node *removeNode);
void checkLeftRight(Node **rootPtr);
void checkLeftLeft(Node **rootPtr);
void checkRightRight(Node **rootPtr);
void checkRightLeft(Node **rootPtr);
void childColorViolatation(Node **rootPtr);
void handleViolatation(Node **rootPtr);
void colorFlipping(Node **rootPtr, Node *removedNode);
void handleCaseOne(Node **rootPtr);
void handleCaseTwo(Node **rootPtr);
void handleCaseThree(Node **rootPtr);
int isDoubleBlack(Node *rootPtr);

#endif // RedBlackTree_H
