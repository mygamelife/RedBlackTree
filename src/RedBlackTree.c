#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"


void addRedBlackTree(Node **rootPtr, Node *newNode)	{
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode)	{
	
	if(*rootPtr == NULL)
		*rootPtr = newNode;
	
	else if((*rootPtr)->data >= newNode->data)
		(*rootPtr)->left = newNode;
	
	else
		(*rootPtr)->right = newNode;
		
	// _addRedBlackTree(rootPtr, newNode);
}