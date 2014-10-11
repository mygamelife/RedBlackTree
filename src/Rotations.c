#include <stdio.h>
#include "Rotations.h"

void rightRotate(Node **rootPtr)	{
  Node *node, *currentNode;

  currentNode = *rootPtr; //Current root
  *rootPtr = currentNode->left;
  node = *rootPtr; //temp node
  
  if(node->right != NULL) {
    currentNode->left = node->right;
    node->right = NULL;
  }
  
  else
    currentNode->left = NULL;
    
  node->right = currentNode;
}

void leftRotate(Node **rootPtr)  {
  Node *node, *currentNode;

  currentNode = *rootPtr; //Current root
  *rootPtr = currentNode->right; //Rotated root
  node = *rootPtr; //node = Rotated root
  
  if(node->left != NULL) {
    currentNode->right = node->left;
    node->left = NULL;
  }

  else
    currentNode->right = NULL;
    
  node->left = currentNode;
}

void leftRightRotate(Node **rootPtr)  {
  Node *node, *currentNode;
  
  currentNode = *rootPtr;
  
  printf("RootPtr address %x\n", &rootPtr);
  printf("Root pointer address %x\n", &(*currentNode));
  printf("node data %d and address %x\n", currentNode->data, currentNode);
  printf("left data %d and address %x\n", currentNode->left->data, currentNode->left);
  printf("right data %d and address %x\n", currentNode->left->right->data, currentNode->left->right);
  printf("Node10 left address %x\n", &(currentNode->left));
  printf("------------------------------------\n");
  
  node = currentNode->left;
  leftRotate(&node);
  currentNode->left = node;

  printf("Variable inside *node address %x\n", *node);
  printf("node data %d and address %x\n", currentNode->data, currentNode);
  printf("left data %d and address %x\n", currentNode->left->data, currentNode->left);
  printf("left2 data %d and address %x\n", currentNode->left->left->data, currentNode->left->left);
  
  rightRotate(&(*rootPtr)); //Pass in *root pointer address
}