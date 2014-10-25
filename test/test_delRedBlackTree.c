#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"

Node node1, node2, node4, node5, node6, node7, node8, node10, node13, node15,
     node20, node22, node30, node40, node60; //Share to all test

/* Run reset before test*/
void setUp(void)	{
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node4, 4);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node10, 10);
	resetNode(&node13, 13);
	resetNode(&node15, 15);
	resetNode(&node20, 20);
	resetNode(&node22, 22);
	resetNode(&node30, 30);
	resetNode(&node40, 40);
	resetNode(&node60, 60);
}

void tearDown(void) {}

/**2-node case
 *          Root                  Root
 *            |                    |
 *            v                    v
 *          1(b)                 NULL
 *                  ---->
 *                remove 1
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_1(void) {
  setNode(&node1, NULL, NULL, 'b');
  Node *root, *result;
  root = &node1;

  printf("Start test_delRedBlackTree_remove_1_from_tree_with_root_1\n");
  result = delRedBlackTree(&root, &node1);
  printf("-------------------------------------------------------\n");

  TEST_ASSERT_EQUAL_PTR(&node1, result);
  TEST_ASSERT_EQUAL_PTR(NULL, root);
}

/**2-node case
 *          Root                  Root
 *            |                    |
 *            v                    v
 *          1(b)                 1(b)
 *                  ---->
 *                remove 2
 */
void test_delRedBlackTree_remove_2_from_tree_with_root_1(void) {
  CEXCEPTION_T err;
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1;

  printf("Start test_delRedBlackTree_remove_2_from_tree_with_root_1\n");

  Try {
    delRedBlackTree(&root, &node2);
    TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAILABLE to be thrown");
  }
  Catch(err)  {
    TEST_ASSERT_EQUAL_PTR(root, &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  }

  printf("-------------------------------------------------------\n");
}

/* Remove RedBlackTree
 *            Root                Root
 *            |                    |
 *            v                    v
 *          2(b)                 2(b)
 *         /         ---->
 *       1(r)       remove 1
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2(void) {
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node2, &node1, NULL, 'b');
  Node *root, *result;
  root = &node2;

  printf("Start test_delRedBlackTree_remove_1_from_tree_with_root_2\n");

  result = delRedBlackTree(&root, &node1);
  printf("-------------------------------------------------------\n");
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/* Remove RedBlackTree
 *            Root                    Root
 *            |                       |
 *            v                       v
 *          1(b)                     1(b)
 *              \         ---->
 *               5(r)   remove 1
 */
void test_delRedBlackTree_remove_5_from_tree_with_root_1(void) {
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node1, NULL, &node5, 'b');
  Node *root, *result;
  root = &node1;

  printf("Start test_delRedBlackTree_remove_5_from_tree_with_root_1\n");
  result = delRedBlackTree(&root, &node5);
  printf("-------------------------------------------------------\n");

  TEST_ASSERT_EQUAL_PTR(root, &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}