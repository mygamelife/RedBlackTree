#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
#include "ErrorCode.h"

char parentColor; //store parent color
void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *_delRedBlackTreex(Node **rootPtr, Node *removeNode);
Node *_removeNextLargerSuccessor(Node **parentPtr);

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

/*---------------------Old-----------------------------------*/
void handleViolatation(Node **rootPtr)  {
  Node *root = *rootPtr;

  if(root->left == NULL && root->right != NULL) {
    if(root->right->left !=NULL && root->right->right != NULL)
      leftRotate(&(*rootPtr));
  }

  else if(root->left != NULL && root->right == NULL) {
    if(root->left->left !=NULL && root->left->right != NULL)
      rightRotate(&(*rootPtr));
  }
}

void colorFlipping(Node **rootPtr, Node *removedNode)  {
  Node *root = *rootPtr;

  if(root->left == NULL && root->right != NULL) {
    if(root->right->color == 'b') {
      root->color = 'b';
      root->right->color = 'r';
    }
    return;
  }

  else if(root->left != NULL && root->right == NULL)  {
    if(root->left->color == 'b')  {
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

Node *delRedBlackTreex(Node **rootPtr, Node *removeNode)  {
  Node *root, *node;

  node = _delRedBlackTreex(rootPtr, removeNode);
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
    node = _delRedBlackTreex(&node->left, removeNode);

    if(node->color == 'b')  {
      handleViolatation(rootPtr);
      colorFlipping(rootPtr, node);
    }
    return node;
  }

  else if(node->data < removeNode->data)  {
    node = _delRedBlackTreex(&node->right, removeNode);

    if(node->color == 'b')  {
      handleViolatation(rootPtr);
      colorFlipping(rootPtr, node);
    }
    return node;
  }
}

/***************************************************************
 **                   New delRedBlackTree                     **
 ***************************************************************/
/**
* Note: x == not possible
*	node          removed node        return
*	-----------------------------------------
*	NULL            NULL                x
*	NULL            red                 0
*	NULL            black               1
*	NULL            double black        x
*	red             NULL                x
*	red             red                 0
*	red             black               0
*	red             double black        x
*	black           NULL                x
*	black           red                 0
*	black           black               0
*	black           double black        x
*	double black    NULL                x
*	double black    red                 1
*	double black    black               1
*	double black    double black        x
*/
int isDoubleBlack(Node *rootPtr, Node *removedNode) {

  if(rootPtr == NULL  &&  removedNode->color == 'r')
    return 0;

  else if((rootPtr == NULL ||  rootPtr->color == 'd')  &&  (removedNode->color == 'b' ||  removedNode->color == 'r'))
    return 1;

  // else if((rootPtr == NULL ||  rootPtr->color == 'd')  &&  removedNode->color == 'r')
    // return 1;

  // else if((rootPtr == NULL ||  rootPtr->color == 'd')  &&  removedNode->color == 'b')
    // return 1;

  else  return 0;
}

//pass in nephew and check if there is grandchild
int checkGrandchild(Node *rootPtr)  {

  if(rootPtr != NULL) {
    if(rootPtr->left != NULL  ||  rootPtr->color == 'd' ||  rootPtr->right != NULL)
      return 1;
  }

  else  return 0;
}

int caseSelect(Node *rootPtr) {

  if(rootPtr == NULL)
    return  0;

  Node* rootLeftPtr = rootPtr->left;
  Node* rootRightPtr = rootPtr->right;

  if(rootLeftPtr != NULL)
    printf("rootLeftPtr %d\n", rootLeftPtr->data);
  if(rootRightPtr != NULL)
    printf("rootRightPtr %d\n", rootRightPtr->data);
  // case1 sibling is black and has a red nephew
  if(rootPtr->color == 'b') {
    if((rootRightPtr != NULL && rootRightPtr->color == 'r') ||  (rootLeftPtr != NULL && rootLeftPtr->color == 'r'))
      return 1;
    // case2 sibling is black and both nephew are black
    else if((rootRightPtr == NULL || rootRightPtr->color == 'b') && (rootLeftPtr == NULL || rootLeftPtr->color == 'b'))
      return 2;
  }

  else if(rootPtr->color == 'r' && (rootPtr->left  ||  rootPtr->right))
    return 3;
}

void handleCaseViolation(Node **rootPtr, int caseNum, Node *removedNode)  {
  if(caseNum == 1)
    handleCaseOne(rootPtr);
  else if(caseNum == 2)
    handleCaseTwo(rootPtr);
  else if(caseNum == 3)
    handleCaseThree(rootPtr, removedNode);
  else return;
}

//handle Case 1
void handleCaseOne(Node **rootPtr) {
  Node *root = *rootPtr;
  parentColor = root->color;
  printf("parentColor %c\n", parentColor);

  //Rotation (Right side)
  if(root->right != NULL) {
    if(root->right->left == NULL && root->right->right != NULL) {
      leftRotate(&(*rootPtr));
      printf("(*rootPtr)->data %d\n", (*rootPtr)->data);
    }

    else if(root->right->left != NULL && root->right->right == NULL) {
      rightLeftRotate(&(*rootPtr));
      printf("(*rootPtr)->data %d\n", (*rootPtr)->data);
    }
  }

  //Rotation (left side)
  else if(root->left != NULL) {
    if(root->left->left != NULL && root->left->right == NULL) {
      rightRotate(&(*rootPtr));
      printf("(*rootPtr)->data %d\n", (*rootPtr)->data);
    }
    else if(root->left->left == NULL && root->left->right != NULL) {
      leftRightRotate(&(*rootPtr));
      printf("(*rootPtr)->data %d\n", (*rootPtr)->data);
    }
  }

  //color flipping
  (*rootPtr)->color = parentColor;
  (*rootPtr)->left->color = 'b';
  (*rootPtr)->right->color = 'b';
}

//handle Case2
void handleCaseTwo(Node **rootPtr)  {
  Node *root = *rootPtr;
  printf("Case 2 rootPtr data %d\n", root->data);

  //  flip root/parent color
  if(root->color == 'b')
    root->color = 'd';
  else  root->color = 'b';

  //  flip left/right child color
  if(root->left)
    root->left->color = (root->left->color == 'd')? 'b':'r';

  if(root->right)
    root->right->color = (root->right->color == 'd')? 'b':'r';
}

//handle Case3
void handleCaseThree(Node **rootPtr, Node *removedNode)  {
  Node *root = *rootPtr;

  //Rotation (Right side)
  if(root->right != NULL && root->right->color == 'r') {
    leftRotate(&(*rootPtr));
    printf("*rootPtr->data %d\n", (*rootPtr)->data);

    (*rootPtr)->color = 'b';
    (*rootPtr)->left->color = 'r';
  }

  //Rotation (left side)
  else if(root->left != NULL && root->left->color == 'r') {
    rightRotate(&(*rootPtr));
    printf("*rootPtr->data %d\n", (*rootPtr)->data);

    (*rootPtr)->color = 'b';
    (*rootPtr)->right->color = 'r';
  }

  Node *rootLeftPtr = (*rootPtr)->left; //left sibling
  Node *rootRightPtr = (*rootPtr)->right; //right sibling

  //check isDoubleBlack at left side(case2)
  if(isDoubleBlack(rootLeftPtr->left, removedNode)  &&  rootLeftPtr->color == 'r'  &&  !checkGrandchild(rootLeftPtr->right))  {
    // if((*rootPtr)->left->right != NULL && (*rootPtr)->left->right->color == 'b')
      handleCaseTwo(&(*rootPtr)->left); //call case2
  }
  //check isDoubleBlack at right side(case2)
  else if(isDoubleBlack(rootRightPtr->right, removedNode)  &&  rootRightPtr->color == 'r'  &&  !checkGrandchild(rootRightPtr->left))  {
    // if((*rootPtr)->right->left != NULL && (*rootPtr)->right->left->color == 'b')
      handleCaseTwo(&(*rootPtr)->right); //call case2
  }
  //check isDoubleBlack at left side(case1)
  else if(isDoubleBlack(rootLeftPtr->left, removedNode)  &&  rootLeftPtr->color == 'r'  &&  checkGrandchild(rootLeftPtr->right))  {
    // if((*rootPtr)->left->right != NULL && (*rootPtr)->left->right->color == 'b')
      handleCaseOne(&(*rootPtr)->left); //call case1
  }
  //check isDoubleBlack at right side(case1)
  else if(isDoubleBlack(rootLeftPtr->right, removedNode)  &&  rootRightPtr->color == 'r'  &&  checkGrandchild(rootRightPtr->left))  {
  // if((*rootPtr)->left->right != NULL && (*rootPtr)->left->right->color == 'b')
      handleCaseOne(&(*rootPtr)->right); //call case1
  }
}

Node *delRedBlackTree(Node **rootPtr, Node *removeNode)  {
  Node *root, *node;

  node = _delRedBlackTree(rootPtr, removeNode);

  if(*rootPtr != NULL)
    (*rootPtr)->color = 'b';

  return node;
}

Node *_delRedBlackTree(Node **rootPtr, Node *removeNode) {
  Node *root, *node = *rootPtr;
  int _case;

  if(node == NULL)
    Throw(ERR_NODE_UNAVAILABLE);

  //find removeNode
  else if(node->data == removeNode->data)  {
    *rootPtr = NULL;
    return node;
  }

  //left side
  else if(node->data > removeNode->data)  {
    node = _delRedBlackTree(&node->left, removeNode);

    if(isDoubleBlack((*rootPtr)->left, node)) {
      _case = caseSelect((*rootPtr)->right);
      printf("_case %d\n", _case);
      handleCaseViolation(&(*rootPtr), _case, node);
    }
    return node;
  }

  //right side
  else if(node->data < removeNode->data)  {
    node = _delRedBlackTree(&node->right, removeNode);

    if(isDoubleBlack((*rootPtr)->right, node)) {
      _case = caseSelect((*rootPtr)->left);
      printf("_case %d\n", _case);
      handleCaseViolation(&(*rootPtr), _case, node);
    }
    return node;
  }
}

/***************************************************************************************
 *            removeNextLargerSuccessor                                                *
 *  input :                                                                            *
 *          parentPtr can be the root or sibling                                       *
 *  output  :                                                                          *
 *            search the next larger successor from the deep left of the right child   *
 ***************************************************************************************/
Node *removeNextLargerSuccessor(Node **parentPtr) {
  Node *parent = *parentPtr, *removedNode;

  printf("Entered removeNextLargerSuccessor\n");

   if(parent->left == NULL) {
      printf("Removed successor is %d\n", parent->data);
      removedNode = parent;
      *parentPtr = NULL;

   if(parent->right != NULL) {
      (*parentPtr) = parent->right;
      (*parentPtr)->color = parent->color;
   }
    printf("RemovedNode is %d\n", removedNode->data);
    return removedNode;
  }

  else  {
    removedNode = removeNextLargerSuccessor(&(*parentPtr)->left);

    // left side have DoubleBlack
    if(isDoubleBlack((*parentPtr)->left, removedNode))  {
      printf("Pass %d into caseSelect\n", (*parentPtr)->right->data);
      int _case = caseSelect((*parentPtr)->right);
      handleCaseViolation(&(*parentPtr), _case, removedNode);
    }
    printf("After restructure\n");
    printf("%d going to return and has color %d\n", (*parentPtr)->data, (*parentPtr)->color);
    printf("-----------------------------\n");
  }
  return removedNode;
}

/***************************************************************************************
 *            integratedDelRedBlackTree                                                *
 *  input :                                                                            *
 *          parentPtr can be the root or sibling                                       *
 *  output  :                                                                          *
 *            can remove node at any position                                          *
 ***************************************************************************************/
Node *integratedDelRedBlackTree(Node **rootPtr, Node *removeNode)  {
  Node *root, *node;

  node = _integratedDelRedBlackTree(rootPtr, removeNode);

  if(*rootPtr != NULL)
    (*rootPtr)->color = 'b';

  return node;
}

Node *_integratedDelRedBlackTree(Node **rootPtr, Node *removeNode) {
  Node *root, *removedNode, *successor, *node = *rootPtr;
  int _case;

  if(node == NULL)
    Throw(ERR_NODE_UNAVAILABLE);

  //find removeNode
  else if(node->data == removeNode->data)  {

    if(node->left==NULL &&  node->left==NULL)
      *rootPtr = NULL;

    else  {
      removedNode = node;
      successor = removeNextLargerSuccessor(&(*rootPtr)->right);
      successor->left = (*rootPtr)->left;
      successor->right = (*rootPtr)->right;
      successor->color = (*rootPtr)->color;
      (*rootPtr) = successor;

      if((*rootPtr)->right)
        printf("right data %d, color %c\n", (*rootPtr)->right->data, (*rootPtr)->right->color);

      printf("Removed data %d, color %c\n", removedNode->data, removedNode->color);
      // Right side has DoubleBlack
      if(isDoubleBlack((*rootPtr)->right, removedNode)) {
        _case = caseSelect((*rootPtr)->left);
        printf("_case %d\n", _case);
        handleCaseViolation(&(*rootPtr), _case, removedNode);
      }

      // Left side has DoubleBlack
      if(isDoubleBlack((*rootPtr)->left, removedNode))  {
        _case = caseSelect((*rootPtr)->right);
        printf("_case %d\n", _case);
        handleCaseViolation(&(*rootPtr), _case, removedNode);
      }
    }

    return removedNode;
  }

  //left side
  else if(node->data > removeNode->data)  {
    node = _integratedDelRedBlackTree(&node->left, removeNode);

    if(isDoubleBlack((*rootPtr)->left, node)) {
      _case = caseSelect((*rootPtr)->right);
      printf("_case %d\n", _case);
      handleCaseViolation(&(*rootPtr), _case, node);
    }
    return node;
  }

  //right side
  else if(node->data < removeNode->data)  {
    node = _integratedDelRedBlackTree(&node->right, removeNode);

    printf("(*rootPtr) %d\n", (*rootPtr)->data);
    printf("(*rootPtr)->right data %d, color %c\n", (*rootPtr)->right->data, (*rootPtr)->right->color);
    printf("node data %d, color %c\n", node->data, node->color);
    if(isDoubleBlack((*rootPtr)->right, node)) {
      _case = caseSelect((*rootPtr)->left);
      printf("_case %d\n", _case);
      handleCaseViolation(&(*rootPtr), _case, node);
    }
    return node;
  }
}
