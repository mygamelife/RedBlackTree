#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
void addRedBlackTree(Node **rootPtr, Node *newNode);
void checkLeftRight(Node **rootPtr);
void checkLeftLeft(Node **rootPtr);
void checkRightRight(Node **rootPtr);
void checkRightLeft(Node **rootPtr);
void childColorViolatation(Node **rootPtr);

#endif // RedBlackTree_H
