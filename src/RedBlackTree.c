#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"


void addRedBlackTree(Node **rootPtr, Node *newNode)	{
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode)	{
	Node *root = *rootPtr;
	
	if(root == NULL)	{
		*rootPtr = newNode;
		return;
	}
	
	else if(root->data >= newNode->data)	{
		_addRedBlackTree(&root->left, newNode);
		
		if((*rootPtr)->left->right != NULL)	{
			if((*rootPtr)->left->right->color == 'r' && (*rootPtr)->left->color == 'r')
				leftRightRotate(&(*rootPtr));	
			(*rootPtr)->right->color = 'r';
		}
	}
		
	else if(root->data <= newNode->data)	{
		_addRedBlackTree(&root->right, newNode);
		
		if((*rootPtr)->right->left != NULL)	{
			if((*rootPtr)->right->left->color == 'r' && (*rootPtr)->right->color == 'r')
				rightLeftRotate(&(*rootPtr));
			(*rootPtr)->left->color = 'r';
		}
		else if((*rootPtr)->right->right != NULL)	{
			if((*rootPtr)->right->right->color == 'r' && (*rootPtr)->right->color == 'r')
				leftRotate(&(*rootPtr));
			(*rootPtr)->left->color = 'r';
		}
	}
}