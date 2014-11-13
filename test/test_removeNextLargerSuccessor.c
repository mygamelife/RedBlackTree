#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node10, node13, node15,
     node20, node22, node30, node40, node60; //Share to all test

/* Run reset before test*/
void setUp(void)	{
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node3, 3);
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

/* Test Node *removeSuccessor(Node **parentPtr);
 *       parent                     parent
 *        |                          |
 *        V                          v
 *       1(b)   successor 1(b)      NULL
 *                 ---->
 */
void test_removeSuccessor_remove_successor_with_parent_1(void)  {
  setNode(&node1, NULL, NULL, 'r');
  Node *parent = &node1;

  Node *removedNode = removeNextLargerSuccessor(&parent);

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL(1, removedNode->data);
  TEST_ASSERT_NULL(parent);
}

/* Test Node *removeSuccessor(Node **parentPtr);
 *       parent                         parent
 *        |                               |
 *        V                               v
 *       1(b)     successor 3(r)         1(b)
 *        \          ---->
 *         3(r)
 */
void test_removeSuccessor_remove_successor_with_parent_1_and_one_right_child(void)  {
  setNode(&node3, NULL, NULL, 'r');
  setNode(&node1, NULL, &node3, 'b');
  Node *parent = &node1;

  Node *removedNode = removeNextLargerSuccessor(&parent);

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL(3, removedNode->data);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', parent);
}

/* Test Node *removeSuccessor(Node **parentPtr);
 *                 parent                            parent
 *                  |                                  |
 *                  V                                  v
 *                 1(b)        successor 6(b)        1(b)
 *                    \         ---->                   \
 *                     8(b)                              8(b)
 *                    /                                 /
 *                7(b)                              7(b)
 *               /
 *           6(b)
 */
void test_removeSuccessor_remove_successor_with_parent_1_and_multiple_right_Leftchild(void)  {
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node7, &node6, NULL, 'b');
  setNode(&node8, &node7, NULL, 'b');
  setNode(&node1, NULL, &node8, 'b');
  Node *parent = &node1;

  Node *removedNode = removeNextLargerSuccessor(&parent);

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL(6, removedNode->data);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_NODE(NULL, &node8, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(&node7, NULL, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}

/* Test Node *removeSuccessor(Node **parentPtr);
 *         parent                         parent
 *           |                              |
 *           V                              v
 *          5(b)   successor  2(r)         5(b)
 *         /          ---->
 *    2(r)
 */
void test_removeSuccessor_remove_successor_with_parent_5_and_right_child_is_NULL(void)  {
  setNode(&node2, NULL, NULL, 'r');
  setNode(&node5, &node2, NULL, 'b');
  Node *parent = &node5;

  Node *removedNode = removeNextLargerSuccessor(&parent);

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL(2, removedNode->data);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', parent);
}

/* Test Node *removeSuccessor(Node **parentPtr);
 *                 parent                             parent
 *                  |                                   |
 *                  V                                   v
 *                 5(b)       successor 6(r)           5(b)
 *               /     \          ---->               /   \
 *           1(b)      8(r)                        1(b)    8(r)
 *                    /                                   /
 *                7(b)                                7(b)
 *               /
 *           6(r)
 */
void test_removeSuccessor_remove_successor_with_parent_5__one_left_child_and_multiple_right_Leftchild(void)  {
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node6, NULL, NULL, 'r');
  setNode(&node7, &node6, NULL, 'b');
  setNode(&node8, &node7, NULL, 'r');
  setNode(&node5, &node1, &node8, 'b');
  Node *parent = &node5;

  Node *succesor = removeNextLargerSuccessor(&parent);

  TEST_ASSERT_NOT_NULL(succesor);
  TEST_ASSERT_EQUAL(6, succesor->data);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_NODE(&node1, &node8, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
}