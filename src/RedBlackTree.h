#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode);
Node *delRedBlackTreex(Node **rootPtr, Node *removeNode);
void checkLeftRight(Node **rootPtr);
void checkLeftLeft(Node **rootPtr);
void checkRightRight(Node **rootPtr);
void checkRightLeft(Node **rootPtr);
void childColorViolatation(Node **rootPtr);
void handleViolatation(Node **rootPtr);
void colorFlipping(Node **rootPtr, Node *removedNode);

//new implement
Node *delRedBlackTree(Node **rootPtr, Node *removeNode);
Node *_delRedBlackTree(Node **rootPtr, Node *removeNode);
int isDoubleBlack(Node *rootPtr, Node *removedNode);
int caseSelect(Node *rootPtr);
int checkGrandchild(Node *rootPtr);
void handleCaseViolation(Node **rootPtr, int caseNum, Node *removedNode);
void handleCaseOne(Node **rootPtr);
void handleCaseTwo(Node **rootPtr);
void handleCaseThree(Node **rootPtr, Node *removedNode);

//remove successor
Node *removeNextLargerSuccessor(Node **parentPtr);
Node *_removeNextLargerSuccessor(Node **parentPtr);

#endif // RedBlackTree_H
