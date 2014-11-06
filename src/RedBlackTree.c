#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
#include "ErrorCode.h"

char colorNode;
void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *_delRedBlackTreex(Node **rootPtr, Node *removeNode);

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

void handleCaseOne(Node **rootPtr)  {
  Node *root = *rootPtr;

  //Right side
  if(root->right != NULL) {
    if(root->right->right != NULL && root->right->right->color == 'r')
      leftRotate(&(*rootPtr));

    else if(root->right->left != NULL && root->right->left->color == 'r')
      rightLeftRotate(&(*rootPtr));
  }

  //Left side
  else if(root->left != NULL) {
    if(root->left->left != NULL && root->left->left->color == 'r')
      rightRotate(&(*rootPtr));

    else if(root->left->right != NULL && root->left->right->color == 'r')
      leftRightRotate(&(*rootPtr));
  }
}

void handleCaseTwo(Node **rootPtr)  {
  Node *root = *rootPtr;

  //Right side
  //Left side

}

void handleCaseThree(Node **rootPtr)  {
  //case 3
  Node *root = *rootPtr;

  //Right side
  if(root->right != NULL && root->right->color == 'r')  {
    if(root->right->left != NULL && root->right->right != NULL)
      leftRotate(&(*rootPtr));
  }
}
void handleViolatation(Node **rootPtr)  {
  Node *root = *rootPtr;
  colorNode = root->color;
  //case 1
  handleCaseOne(rootPtr);
  //case 3
  handleCaseThree(rootPtr);
  /*
  //Right Side
  if(root->left == NULL && root->right != NULL) {
    // case 1 sibling 'b' and nephew 'r' (right side)
    if(root->right->left == NULL && root->right->right != NULL) {
      if(root->right->color == 'b' && root->right->right->color == 'r')
        leftRotate(&(*rootPtr));
      }

    else if(root->right->left != NULL && root->right->right == NULL)  {
      if(root->right->color == 'b' && root->right->left->color == 'r')
        rightLeftRotate(&(*rootPtr));
    }
  }

  // Left Side
  else if(root->left != NULL && root->right == NULL) {
    // case 1 sibling 'b' and nephew 'r' (left side)
    if(root->left->left != NULL && root->left->right == NULL)  {
      if(root->left->color == 'b' && root->left->left->color == 'r')
        rightRotate(&(*rootPtr));
    }

    else if(root->left->left == NULL && root->left->right != NULL)  {
      if(root->left->color == 'b' && root->left->right->color == 'r')
        leftRightRotate(&(*rootPtr));
    }
  }
  */
}

void colorFlipping(Node **rootPtr, Node *removedNode)  {
  Node *root = *rootPtr;

  //force sibling to black color
  if(root->left != NULL && root->right != NULL) {
    root->color = colorNode;
    root->left->color = 'b';
    root->right->color = 'b';
  }

  else if(root->left == NULL && root->right != NULL) {
    if(root->color == 'b' && root->right->color == 'b') {
      root->color = 'd';
      root->right->color = 'r';
    }
    else if(root->color == 'r' && root->right->color == 'b') {
      root->color = 'b';
      root->right->color = 'r';
    }
    return;
  }

  else if(root->left != NULL && root->right == NULL)  {
    if(root->color == 'b' && root->left->color == 'b') {
      root->color = 'd';
      root->left->color = 'r';
    }
    else if(root->color == 'r' && root->left->color == 'b') {
      root->color = 'b';
      root->left->color = 'r';
    }
    return;
  }

  else if(root->data > removedNode->data)
    colorFlipping(&root->left, removedNode);

  else if(root->data < removedNode->data)
    colorFlipping(&root->right, removedNode);
}

/* -------------------------------------------------------------------------------------*/
Node *delRedBlackTreex(Node **rootPtr, Node *removeNode)  {
  Node *root, *node;

  node = _delRedBlackTree(rootPtr, removeNode);
  root = *rootPtr;

  if(root != NULL)
    root->color = 'b';

  return node;
}

Node *_delRedBlackTreex(Node **rootPtr, Node *removeNode) {
  Node *root, *node = *rootPtr;

  if(node == NULL)
    Throw(ERR_NODE_UNAVAILABLE);

  else if(node->data == removeNode->data)  {
    *rootPtr = NULL;
    return node;
  }

  else if(node->data > removeNode->data)  {
    node = _delRedBlackTree(&node->left, removeNode);

    if(node->color == 'b')  {
      handleViolatation(rootPtr);
      colorFlipping(rootPtr, node);
    }
    return node;
  }

  else if(node->data < removeNode->data)  {
    node = _delRedBlackTree(&node->right, removeNode);

    if(node->color == 'b')  {
      handleViolatation(rootPtr);
      colorFlipping(rootPtr, node);
    }
    return node;
  }
}

/* -------------------------------------------------------------------------------------*/
Node *delRedBlackTree(Node **rootPtr, Node *removeNode)  {
  Node *root, *node;

  node = _delRedBlackTree(rootPtr, removeNode);
  root = *rootPtr;

  if(root != NULL)
    root->color = 'b';

  return node;
}

Node *_delRedBlackTree(Node **rootPtr, Node *removeNode) {
  Node *root, *node = *rootPtr;

  if(node == NULL)
    Throw(ERR_NODE_UNAVAILABLE);

  else if(node->data == removeNode->data)  {
    *rootPtr = NULL;
    node->color = 'd';
    return node;
  }

  else if(node->data > removeNode->data)  {
    node = _delRedBlackTree(&node->left, removeNode);

    if(node->color == 'd')
      handleViolatation(rootPtr);
      colorFlipping(rootPtr, node);

    return node;
  }

  else if(node->data < removeNode->data)  {
    node = _delRedBlackTree(&node->right, removeNode);

    if(node->color == 'd')  {
      handleViolatation(rootPtr);
      colorFlipping(rootPtr, node);
    }

    return node;
  }
}