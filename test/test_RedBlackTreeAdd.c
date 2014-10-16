#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"

Node node1, node5, node6, node7, node8, node10, node13, node15, node20, node30; //Share to all test

/* Run reset before test*/
void setUp(void)	{
	resetNode(&node1, 1);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node10, 10);
	resetNode(&node13, 13);
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
void test_addRedBlackTree_add_10_to_empty_tree(void)	{
	setNode(&node10, NULL, NULL, 'r');
	Node *root = NULL;
	
	printf("Start test_addRedBlacTree_add_10_to_empty_tree\n");
	addRedBlackTree(&root, &node10);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}

/*
 * Root->  	10(b)              		10(b)  <-Root                                         
 *          	      add 5     	/
 *									---->			5(r)
 */
void test_addRedBlackTree_add_5_to_tree_with_root_10(void)	{
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'r');
	Node *root = &node10;
	
	printf("Start test_addRedBlacTree_add_5_to_tree_with_root_10\n");
	addRedBlackTree(&root, &node5);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
}

/*
 * Root->  	10(b)              		10(b)  <-Root                                         
 *          	      add 13     	    \
 *									---->	           13(r)
 */
void test_addRedBlackTree_add_13_to_tree_with_root_10(void)	{
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node13, NULL, NULL, 'r');
	Node *root = &node10;
	
	printf("Start test_addRedBlacTree_add_13_to_tree_with_root_10\n");
	addRedBlackTree(&root, &node13);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	
	TEST_ASSERT_EQUAL_NODE(NULL, &node13, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
}

/*
 * Root->  	10(b)              		    10(b)  <-Root                  10(b)  <-Root                       13(b) <-Root
 *          	\         add 13     	    \							rotate right		 \             rotate left        /  \
 *             15(r)		---->	           15(r)        	---->           13(r)         ---->         10(r)   15(r)
 *                                      /																	\          flip color
 *                                   13(r)																 15(r)
 */
void test_addRedBlackTree_add_13_to_tree_with_root_10_and_right_child_15(void)	{
	setNode(&node13, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, NULL, &node15, 'b');
	Node *root = &node10;
	
	printf("Start test_addRedBlackTree_add_13_to_tree_with_root_10_and_right_child_15\n");
	addRedBlackTree(&root, &node13);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node13);
	
	TEST_ASSERT_EQUAL_NODE(&node10, &node15, 'b', &node13);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}

/*
 * Root->  	10(b)              		    10(b)  <-Root                   10(b)  <-Root                       8(b) <-Root
 *         /	         add 8     	   /							 rotate left		 /               rotate left        /   \
 *       5(r)      		 ---->	     5(r)        	       ---->       8(r)                ---->         5(r)    10(r)
 *                                  \    													/		               flip color
 *                                   8(r)												5(r)			
 */
void test_addRedBlackTree_add_8_to_tree_with_root_10_and_left_child_5(void)	{
	setNode(&node8, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	printf("Start test_addRedBlackTree_add_8_to_tree_with_root_10_and_left_child_5\n");
	addRedBlackTree(&root, &node8);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node8);
	
	TEST_ASSERT_EQUAL_NODE(&node5, &node10, 'b', &node8);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
}

/*
 * Root->  	8(b)              		  8(b)  <-Root                           10(b) <-Root
 *         	 \         add 20        \							 rotate left		     /   \
 *            10(r)		 ---->	        10(r)    	       ---->          8(r)    20(r)
 *                                  	\    					 flip color
 *                                     20(r)															
 */
void test_addRedBlackTree_add_20_to_tree_with_root_8_and_right_child_10(void)	{
	setNode(&node20, NULL, NULL, 'r');
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node8, NULL, &node10, 'b');
	Node *root = &node8;
	
	printf("Start test_addRedBlackTree_add_20_to_tree_with_root_8_and_right_child_10\n");
	addRedBlackTree(&root, &node20);
	printf("-----------------------------");
  
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
	TEST_ASSERT_EQUAL_NODE(&node8, &node20, 'b', &node10);
}