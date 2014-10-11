#include <stdio.h>
#include "unity.h"
#include "Rotations.h"

Node node1, node5, node7, node8, node10, node20; //Share to all test

void setNode(Node *target, Node *left, Node *right, char color)	{
	target->left = left;
	target->right = right;
	target->color = color;
}

void resetNode(Node *target, int data)	{
	target->left = NULL;
	target->right = NULL;
	target->color = 'b';
	target->data = data;
}

/* Run reset before test*/
void setUp(void)	{
	resetNode(&node1, 1);
	resetNode(&node5, 5);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node10, 10);
	resetNode(&node20, 20);
}

void tearDown(void)	{}

/*
 * Root->  10               5  <-Root            
 *		    /               /  \
 *       5       --->    1   10
 *      /                  
 *     1                         
 *                                 
 */
void test_rightRotate_3_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	printf("Root address %x\n", &root);
  printf("test_rightRotate_3_elements\n");
	rightRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/*
 * Root->  10                 5  <-Root            
 *		    /  \              /   \
 *       5   20    --->    1     10
 *      /                         \
 *     1                           20
 *                                 
 */
void test_rightRotate_4_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, &node20, 'b');
	setNode(&node20, NULL, NULL, 'b');
	Node *root = &node10;
	
  printf("test_rightRotate_4_elements\n");
	rightRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/*
 * Root->  10                 5  <-Root            
 *		    /  \              /  \
 *       5   20    --->    1    10
 *      / \                    /  \
 *     1   8                  8   20
 *                                 
 */
void test_rightRotate_5_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, &node8, 'b');
	setNode(&node8, NULL, NULL, 'b');
	setNode(&node10, &node5, &node20, 'b');
	setNode(&node20, NULL, NULL, 'b');
	Node *root = &node10;
	
  printf("test_rightRotate_5_elements\n");
	rightRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node8.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node8.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node8);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/*
 * Root->  1                   5    <-Root
 *          \                /  \
 *           5    -->       1    10
 *            \
 *             10                    
 */
void test_leftRotate_3_elements(void)	{
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, &node10, 'b');
	setNode(&node1, NULL, &node5, 'b');
	Node *root = &node1;
	
  printf("test_leftRotate_3_elements\n");
	leftRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/*
 * Root->   5                    10    <-Root
 *        /  \                 /   \
 *       1    10    --->     5      20
 *             \            / 
 *              20         1           
 */
void test_leftRotate_4_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node10, NULL, &node20, 'b');
	setNode(&node5, &node1, &node10, 'b');
	Node *root = &node5;
	
  printf("test_leftRotate_4_elements\n");
	leftRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

/*
 * Root->   5                     10    <-Root
 *        /  \                  /   \
 *       1    10    --->      5      20
 *           /  \            / \
 *         8     20         1   8        
 */
void test_leftRotate_5_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node8, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node10, &node8, &node20, 'b');
	setNode(&node5, &node1, &node10, 'b');
	Node *root = &node5;
	
  printf("test_leftRotate_5_elements\n");
	leftRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node8.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node8.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node8);
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

/*
 * Root->  10        Root->   10          Root->   7
 *        /                  /                   /  \ 
 *       5       -->        7      -->         5     10
 *     / \                 /
 *    -   7               5
 */

void test_leftRightRotate_3_elements(void)	{
	setNode(&node7, NULL, NULL, 'b');
	setNode(&node5, NULL, &node7, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
  printf("test_leftRightRotate_3_elements\n");
  printf("Root pointer address %x\n", &root); 
  leftRightRotate(&root);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node7.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);  
}