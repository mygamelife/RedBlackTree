#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
#include "ErrorCode.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *_delRedBlackTree(Node **rootPtr, Node *removeNode);

void addRedBlackTree(Node **rootPtr, Node *newNode)	{
	_addRedBlackTree(rootPtr, newNode);

  Node *root = *rootPtr;
  root->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode)	{
	Node *root = *rootPtr;

	if(root == NULL)	{
		*rootPtr = newNode;
		return;
	}

	else if(root->data >= newNode->data)	{
		_addRedBlackTree(&root->left, newNode);

    if(root->left != NULL)  {
      if(root->right != NULL)
        childColorViolatation(rootPtr);  //handle 4-node

      else if(root->left->left != NULL)
        checkLeftLeft(rootPtr); // handle 3-node

      else if(root->left->right != NULL)
        checkLeftRight(rootPtr); // handle 3-node
    }
  }

	else if(root->data <= newNode->data)	{
		_addRedBlackTree(&root->right, newNode);

    if(root->right != NULL)  {
      if(root->left != NULL)
        childColorViolatation(rootPtr);

      if(root->right->right != NULL)
        checkRightRight(rootPtr);

      else if(root->right->left != NULL)
        checkRightLeft(rootPtr);
    }
   }
}

/* Check currentNode left-right node
 * input : Root node
 * ouput : LeftRightRotate if left-right node is not NULL and flip right node color to 'r'
 */
void checkLeftRight(Node **rootPtr) {
  Node *root = *rootPtr;

  if(root->left->right->color == 'r' && root->left->color == 'r')  {
    leftRightRotate(&(*rootPtr));
    (*rootPtr)->right->color = 'r';
  }
}

/* Check currentNode left-left node
 * input : Root node
 * ouput : rightRotate if left-left node is not NULL and flip right node color to 'r'
 */
void checkLeftLeft(Node **rootPtr)  {
  Node *root = *rootPtr;

  if(root->left->left->color == 'r' && root->left->color == 'r')  {
    rightRotate(&(*rootPtr));
    (*rootPtr)->right->color = 'r';
  }
}

/* Check currentNode right-right node
 * input : Root node
 * ouput : leftRotate if right-right node is not NULL and flip left node color to 'r'
 */
void checkRightRight(Node **rootPtr)  {
  Node *root = *rootPtr;

  if(root->right->right->color == 'r' && root->right->color == 'r') {
    leftRotate(&(*rootPtr));
    (*rootPtr)->left->color = 'r';
  }
}

/* Check currentNode right-left node
 * input : Root node
 * ouput : rightRotate if left-left node is not NULL and flip right node color to 'r'
 */
void checkRightLeft(Node **rootPtr) {
  Node *root = *rootPtr;

  if(root->right->left->color == 'r' && root->right->color == 'r')  {
    rightLeftRotate(&(*rootPtr));
    (*rootPtr)->left->color = 'r';
	}
}

/* Verify the child color
 * input : Root node
 * ouput : flip left and right node color if 3 nodes are red color
 */
void childColorViolatation(Node **rootPtr)  {
  Node *root = *rootPtr;

  if(root->left->color == 'r' && root->right->color == 'r') {
    if(root->left->left != NULL && root->left->left->color == 'r')	{
      root->left->color = 'b';
      root->right->color = 'b';
      root->color = 'r';
    }

    else if(root->left->right != NULL && root->left->right->color == 'r')	{
      root->left->color = 'b';
      root->right->color = 'b';
      root->color = 'r';
    }

    else if(root->right->left != NULL && root->right->left->color == 'r')	{
      root->left->color = 'b';
      root->right->color = 'b';
      root->color = 'r';
    }

    else if(root->right->right != NULL && root->right->right->color == 'r')	{
      root->left->color = 'b';
      root->right->color = 'b';
      root->color = 'r';
    }
  }
}

Node *delRedBlackTree(Node **rootPtr, Node *removeNode)  {
  _delRedBlackTree(rootPtr, removeNode);

  Node *node = *rootPtr;
  node->color = 'b';
  
  return node;
}

Node *_delRedBlackTree(Node **rootPtr, Node *removeNode) {
  Node *node = *rootPtr;
  
  if(node->data == removeNode->data)
    return node;
    
  else if(node->data > removeNode->data)  {
    _delRedBlackTree(&node->left, removeNode);
    printf("node data %d\n", node->data);
  } 
  
  else Throw(ERR_NODE_UNAVAILABLE);
}