#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode);
Node *delRedBlackTree(Node **rootPtr, Node *removeNode);
void checkLeftRight(Node **rootPtr);
void checkLeftLeft(Node **rootPtr);
void checkRightRight(Node **rootPtr);
void checkRightLeft(Node **rootPtr);
void childColorViolatation(Node **rootPtr);

#endif // RedBlackTree_H
