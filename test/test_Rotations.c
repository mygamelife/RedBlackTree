#include "unity.h"
#include "Rotations.h"

Node node1, node5, node10; //Share to all test

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
	resetNode(&node10, 10);
}

void tearDown(void)	{}

/*
 * Root->  10
 *		    /                 5 <-Root
 *       5       --->     /  \
 *      /                1   10 
 *     1
 */
void test_rightRotate_3_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}
