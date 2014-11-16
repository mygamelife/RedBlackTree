#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "CException.h"
#include "ErrorCode.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node10, node13, node15,
     node18, node20, node22, node25, node30, node40, node60; //Share to all test

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
	resetNode(&node18, 18);
	resetNode(&node20, 20);
	resetNode(&node22, 22);
	resetNode(&node25, 25);
	resetNode(&node30, 30);
	resetNode(&node40, 40);
	resetNode(&node60, 60);
}

void tearDown(void) {}

/** Test remove right side parent 7(b) with black color root
 *                parent                              parent
 *                  |                                   |
 *                  V           remove                  v             the successor 8(b) is removed and replace with
 *                 4(b)       successor 8(b)           4(b)           7(b) and doubleBlack is occurred
 *              /      \          ---->             /       \
 *          2(b)        7(b)                     2(b)        7(b)
 *        /    \       /    \                  /     \     /    \\
 *    1(b)     3(b)  6(b)   8(b)             1(b)   3(b)  6(b)   -
 *
 *              parent                                  parent                                    parent
 *                |                                       |                                         |
 *                v                                       v                                         v
 *              4(b)           Call case2               4(b)        Call case2 again                4(b)
 *            /     \           ------>               /    \\           ----->                    /     \
 *        2(b)       8(b)                         2(b)      8(d)                               2(r)      8(b)
 *      /    \     /    \\                       /   \     /    \                             /   \     /    \
 *   1(b)   3(b)  6(b)   -                   1(b)   3(b)  6(r)   -                          1(b)  3(b) 6(r)   -
 */
void test_integratedDelRedBlackTree_remove_right_side_parent_7b_and_root_is_black(void)  {
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node8, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'b');
  setNode(&node7, &node6, &node8, 'b');
  setNode(&node4, &node2, &node7, 'b');
  Node *parent = &node4;

  printf("Start test_integratedDelRedBlackTree_remove_right_side_parent_7b_and_root_is_black\n");
  Node *removedNode = integratedDelRedBlackTree(&parent, &node7);
  printf("-------------------------------------------------------------\n");

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL_PTR(&node7, removedNode);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_PTR(&node4, parent);
  TEST_ASSERT_EQUAL_NODE(&node2, &node8, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(&node6, NULL, 'b', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);
}

/** Test remove right side parent 22(b) with red color root
 *                parent                              parent
 *                  |                                   |
 *                  V           remove                  v             the successor 30(b) is removed and replace with
 *                18(r)       successor 30(b)          18(r)           22(b) and doubleBlack is occurred
 *              /      \          ---->             /       \
 *          8(b)        22(b)                     8(b)       22(b)
 *        /    \       /    \                  /     \      /    \\
 *    5(b)     10(b) 20(b)  30(b)            5(b)  10(b) 20(b)    -
 *
 *               parent                                 parent                                     parent
 *                |                                       |                                          |
 *                v                                       v                                          v
 *              18(r)           Call case2               18(r)        Call case2b again             18(b)
 *            /      \           ------>               /     \\           ----->                   /     \
 *        8(b)       30(b)                         8(b)      30(d)                              8(r)      30(b)
 *      /    \      /    \\                       /   \     /    \                             /   \     /    \
 *   5(b)   10(b) 20(b)   -                   5(b)   10(b) 20(r)  -                        5(b)  10(b) 20(r)   -
 */
void test_integratedDelRedBlackTree_remove_right_side_parent_22b_and_root_is_red(void)  {
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node8, &node5, &node10, 'b');
  setNode(&node22, &node20, &node30, 'b');
  setNode(&node18, &node8, &node22, 'r');
  Node *parent = &node18;

  printf("Start test_integratedDelRedBlackTree_remove_right_side_parent_22b_and_root_is_red\n");
  Node *removedNode = integratedDelRedBlackTree(&parent, &node22);
  printf("-------------------------------------------------------------\n");

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL_PTR(&node22, removedNode);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_PTR(&node18, parent);
  TEST_ASSERT_EQUAL_NODE(&node8, &node30, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(&node5, &node10, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}

/** Test remove right side parent 25(r) with red color
 *                parent                              parent
 *                  |                                   |
 *                  V           remove                  v             the successor 30(b) is removed and replace with
 *                18(b)       successor 30(b)          18(b)           40(r) and doubleBlack is occurred
 *              /      \          ---->             /       \
 *          8(r)        25(r)                     8(r)       25(r)
 *        /    \       /    \                  /     \      /    \\
 *    5(b)     10(b) 20(b)  30(b)            5(b)  10(b) 20(b)    -
 *                              \                                   \
 *                             40(r)                                 40(r)
 *
 *               parent                                 parent
 *                |                                       |
 *                v          replace 25(r) with           v
 *              18(b)        30(b) successor            18(b)
 *            /      \           ------>               /     \
 *        8(r)       25(r)                         8(r)      30(r)
 *      /    \      /    \                        /   \     /    \
 *   5(b)   10(b) 20(b)   40(b)               5(b)  10(b) 20(b)   40(b)
 */
void test_integratedDelRedBlackTree_remove_right_side_parent_25r_with_root_is_black(void)  {
  setNode(&node40, NULL, NULL, 'r');
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node30, NULL, &node40, 'b');
  setNode(&node8, &node5, &node10, 'r');
  setNode(&node25, &node20, &node30, 'r');
  setNode(&node18, &node8, &node25, 'r');
  Node *parent = &node18;

  printf("Start test_integratedDelRedBlackTree_remove_right_side_parent_25r_red\n");
  Node *removedNode = integratedDelRedBlackTree(&parent, &node25);
  printf("-------------------------------------------------------------\n");

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL_PTR(&node25, removedNode);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_PTR(&node18, parent);
  TEST_ASSERT_EQUAL_NODE(&node8, &node30, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(&node5, &node10, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node20, &node40, 'r', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node40);
}

/** Test remove left side parent 8(b) with red color root
 *                root                                root
 *                  |                                   |
 *        parent    V           remove                  v
 *          |      18(r)       successor 10(b)          18(r)
 *          V    /      \          ---->             /       \
 *          8(b)        22(b)                     8(b)       22(b)
 *        /    \       /    \                  /    \\     /     \
 *    5(b)     10(b) 20(b)  30(b)            5(b)    -  20(b)    30(b)
 *
 *  Call case2                    root                                   root                                    root
 *  promote doubleBlack            |         replace the deleteNode       |                                       |
 *  and color flip                 v         with successor               v           call Case2 again            v
 *    ------>                   18(r)            ----->                 18(r)             ----->                18(b)
 *                           //      \                               //      \                                /     \
 *                        8(d)       22(b)                         10(d)     22(b)                       10(b)      22(r)
 *                      /    \      /    \                       /   \     /    \                       /    \     /     \
 *                    5(r)   -  20(b)    30(b)                5(r)   -  20(b)   30(b)                5(r)     - 20(b)  30(b)
 */
void test_integratedDelRedBlackTree_remove_left_side_parent_8b_and_root_is_red(void)  {
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node8, &node5, &node10, 'b');
  setNode(&node22, &node20, &node30, 'b');
  setNode(&node18, &node8, &node22, 'r');
  Node *parent = &node18;

  printf("Start test_integratedDelRedBlackTree_remove_left_side_parent_8b_and_root_is_red\n");
  Node *removedNode = integratedDelRedBlackTree(&parent, &node8);
  printf("-------------------------------------------------------------\n");

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL_PTR(&node8, removedNode);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_PTR(&node18, parent);
  TEST_ASSERT_EQUAL_NODE(&node10, &node22, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'r', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
}

/** Test remove the root 18(r)
 *                 root                               root
 *                  |                                   |
 *                  V           remove                  v             the successor 20(b) is removed and replace with
 *                18(r)       successor 20(b)          18(r)          18(r) and doubleBlack occurred
 *              /      \          ---->             /       \
 *          8(b)        22(b)                     8(b)       22(b)
 *        /    \       /    \                  /     \      //    \
 *    5(b)     10(b) 20(b)  30(b)            5(b)  10(b)   -      30(b)
 *
 *               parent                                 parent                                     parent
 *                |                                       |                                          |
 *                v                                       v                                          v
 *              20(r)           Call case2               20(r)        Call case2b again             20(b)
 *            /      \           ------>               /     \\           ----->                   /     \
 *        8(b)       22(b)                         8(b)       22(d)                              8(r)     22(b)
 *      /    \      //    \                       /   \      /    \                            /    \     /    \
 *   5(b)   10(b)  -     30(b)                5(b)   10(b)  -     30(r)                      5(b)  10(b) -      30(r)
 */
void test_integratedDelRedBlackTree_remove_parent_node(void)  {
  setNode(&node5, NULL, NULL, 'b');
  setNode(&node10, NULL, NULL, 'b');
  setNode(&node20, NULL, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node8, &node5, &node10, 'b');
  setNode(&node22, &node20, &node30, 'b');
  setNode(&node18, &node8, &node22, 'r');
  Node *parent = &node18;

  printf("Start test_integratedDelRedBlackTree_remove_parent_node\n");
  Node *removedNode = integratedDelRedBlackTree(&parent, &node18);
  printf("-------------------------------------------------------------\n");

  TEST_ASSERT_NOT_NULL(removedNode);
  TEST_ASSERT_EQUAL_PTR(&node18, removedNode);
  TEST_ASSERT_NOT_NULL(parent);
  TEST_ASSERT_EQUAL_PTR(&node20, parent);
  TEST_ASSERT_EQUAL_NODE(&node8, &node22, 'b', parent);
  TEST_ASSERT_EQUAL_NODE(&node5, &node10, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, &node30, 'b', &node22);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);
}