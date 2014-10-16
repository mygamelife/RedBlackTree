#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"

Node node1, node5, node6, node7, node8, node10, node15, node20, node30; //Share to all test

/* Run reset before test*/
void setUp(void)	{
	resetNode(&node1, 1);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node10, 10);
	resetNode(&node15, 15);
	resetNode(&node20, 20);
	resetNode(&node30, 30);
}

void tearDown(void) {}

/*
 * Root->  NULL                10  <-Root                                         
 *                add 10
 *								---->
 */
void test_addRedBlacTree_add_10_to_empty_tree(void)	{
	setNode(&node10, NULL, NULL, 'r');
	Node *root = NULL;
	
	printf("Start test_addRedBlacTree_add_10_to_empty_tree\n");
	addRedBlackTree(&root, &node10);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
	// TEST_ASSERT_EQUAL_PTR(NULL, node10.left);
	// TEST_ASSERT_EQUAL_PTR(NULL, node10.right);
}

/*
 * Root->  	10(b)              		10(b)  <-Root                                         
 *          	      add 5     	/
 *									---->			5(r)
 */
void test_addRedBlacTree_add_5_to_tree_with_root_10(void)	{
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'r');
	Node *root = &node10;
	
	printf("Start test_addRedBlacTree_add_5_to_tree_with_root_10\n");
	addRedBlackTree(&root, &node5);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
	// TEST_ASSERT_EQUAL('b', node10.color);
	// TEST_ASSERT_EQUAL_PTR(&node5, node10.left);
	// TEST_ASSERT_EQUAL_PTR(NULL, node10.right);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	// TEST_ASSERT_EQUAL(node5.color, 'r');
	// TEST_ASSERT_EQUAL_PTR(NULL, node5.left);
	// TEST_ASSERT_EQUAL_PTR(NULL, node5.right);
}