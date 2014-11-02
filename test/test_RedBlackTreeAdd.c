#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "Rotations.h"
#include <CException.h>

Node node1, node2, node5, node10, node15, node12, node6, node11, node20, node7, node30, node25, node3, node13, node40;


void setUp(void)
{
	resetNode(&node1, 1);
	resetNode(&node5, 5);
	resetNode(&node10, 10);
	resetNode(&node12, 12);
	resetNode(&node6, 6);
	resetNode(&node15, 15);
	resetNode(&node11, 11);
	resetNode(&node2, 2);
    resetNode(&node20, 20);
    resetNode(&node30, 30);
    resetNode(&node25, 25);
    resetNode(&node3, 3);
    resetNode(&node13, 13);
    resetNode(&node40, 40);
    resetNode(&node7, 7);
}

void tearDown(void)
{
}

/*    root               root
 *     |     add 10       |
 *     v      --->        v
 *   NULL               10(b)
 */
void test_addRedBlackTree_add_10_to_empty_tree(void)
{
    setNode(&node10,NULL,NULL,'r');
    Node *root = NULL ;
    
    addRedBlackTree(&root,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'b',&node10);
}


/*    root               root
 *     |      add 5       |
 *     v      --->        v
 *   10(b)               10(b)
 *                       /
 *                     5(r)
 */
void test_addRedBlackTree_add_5_to_tree_with_root_10(void)
{
    setNode(&node10,NULL,NULL,'b');
    setNode(&node5,NULL,NULL,'r');
    Node *root = &node10 ;
    
    addRedBlackTree(&root,&node5);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    TEST_ASSERT_EQUAL_NODE(&node5,NULL,'b',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
}


/*    root               root
 *     |      add 10       |
 *     v      --->        v
 *    5(b)               5(b)
 *                        \
 *                        10(r)
 */
void test_addRedBlackTree_add_10_to_tree_with_root_5(void)
{
    setNode(&node10,NULL,NULL,'r');
    setNode(&node5,NULL,NULL,'b');
    Node *root = &node5;
    
    addRedBlackTree(&root,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node5);
    TEST_ASSERT_EQUAL_NODE(NULL,&node10,'b',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL,'r',&node10);
}


 
 
 
 /*    root               root                      root                      
 *     |      add 5        |       rotate right       |     
 *     v      --->         v         --->             v       
 *    15(b)               15(b)                    10(b)                     
 *   /                   /                        /    \                     
 * 10(r)               10(r)                     5(r)  15(r)                  
 *	                   /                       
 *                   5(r)                  
 */
void test_addRedBlackTree_add_5_to_tree_with_root_15(void)
{
    setNode(&node5,NULL,NULL,'r');
    setNode(&node10,NULL,NULL,'r');
	setNode(&node15,&node10,NULL,'b');
    Node *root = &node15;
    
    addRedBlackTree(&root,&node5);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL,'r',&node15);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15,'b',&node10);
}



/*    root               root                      root                      root
 *     |      add 10       |       rotate left       |     rotate right       |
 *     v      --->         v         --->            v       --->             v
 *    15(b)               15(b)                    15(b)                     10(b)
 *   /                   /                          /                       /    \
 * 5(r)                5(r)                      10(r)                    5(r)  15(r)
 *	                     \                        /
 *                       10(r)                  5(r)
 */
void test_addRedBlackTree_add_10_to_tree_with_root_15(void)
{
    setNode(&node10,NULL,NULL,'r');
    setNode(&node5,NULL, NULL,'r');
	setNode(&node15,&node5,NULL,'b');
    Node *root = &node15;
    
    addRedBlackTree(&root,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15,'b',&node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL,'r',&node15);
}




/**
 * root -> 10(b)   add 15      10(b)  <- root
 *         /      ------->    /   \
 *      5(r)               5(r)  15(r)
 */
void test_addRedBlackTree_add_15_to_tree_with_root_10(void)
{
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, NULL, 'b');
    Node *root = &node10;

    addRedBlackTree(&root, &node15);

    TEST_ASSERT_EQUAL_PTR(root, &node10);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
    
}



/**
 * root -> 10(b)    add 5       10(b)  <- root
 *            \    ------->    /   \
 *           15(r)           5(r)  15(r)
 */
void test_addRedBlackTree_add_5_to_use_tree_with_root_10(void)
{
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node10, NULL, &node15, 'b');
    Node *root = &node10;

    addRedBlackTree(&root, &node5);

    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
}




/**
 *                             10(b)  <- root
 * root -> 10(b)    add 30        \                      12(b)   <- root
 *            \    ------->      12(r)        ------>    /   \
 *           12(r)                  \                 10(r)  15(r)
 *                                 15(r)
 */
void test_addRedBlackTree_add_15_to_use_tree_with_root_10(void)
{
    setNode(&node12, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, NULL, &node12, 'b');
    Node *root = &node10;

    addRedBlackTree(&root, &node15);

    TEST_ASSERT_EQUAL_PTR(root, &node12);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node10, &node15, 'b', &node12);
}



/**
 *                             10(b)  <- root
 * root -> 10(b)    add 15        \                       15(b)   <- root
 *            \    ------->      20(r)        ------>    /   \
 *           20(r)               /                    10(r)  20(r)
 *                            15(r)
 */
void test_addRedBlackTree_add_15_to_use_tree_to_another_side_with_root_10(void)
{
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node20, NULL, NULL, 'r');
    setNode(&node10, NULL, &node20, 'b');
    Node *root = &node10;

    addRedBlackTree(&root, &node15);

    TEST_ASSERT_EQUAL_PTR(root, &node15);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
    TEST_ASSERT_EQUAL_NODE(&node10, &node20, 'b', &node15);
}



/** 4-node case
 *                               10(b)  <- root            10(r)  <- root           10(r)  <- root
 * root -> 10(b)     add 1       /   \                     /   \                    /   \
 *         /   \    ------->   5(r)  15(r)      ----->   5(b)  15(b)      ----->  5(b)  15(b)
 *       5(r) 15(r)            /                         /                        /
 *                           1(r)                      1(r)                     1(r)
 */
void test_addRedBlackTree_add_1_to_use_tree_with_5_10_15_nodes(void)
{
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *root = &node10;

    _addRedBlackTree(&root, &node1);

    TEST_ASSERT_EQUAL_PTR(root, &node10);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    
}


/** 4-node case
 *                               10(b)  <- root            10(r)  <- root           10(r)  <- root
 * root -> 10(b)     add 7       /   \                     /   \                    /   \
 *         /   \    ------->   5(r)  15(r)      ----->   5(b)  15(b)      ----->  5(b)  15(b)
 *       5(r) 15(r)               \                         \                        \
 *                               7(r)                      7(r)                     7(r)
 */
void test_addRedBlackTree_add_7_to_use_tree_with_5_10_15_nodes(void)
{
    setNode(&node7, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *root = &node10;

    _addRedBlackTree(&root, &node7);

    TEST_ASSERT_EQUAL_PTR(root, &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);

}



/** 4-node case
 *                               10(b)  <- root            10(r)  <- root           10(r)  <- root
 * root -> 10(b)     add 13      /   \                     /   \                    /   \
 *         /   \    ------->   5(r)  15(r)      ----->   5(b)  15(b)      ----->  5(b)  15(b)
 *       5(r) 15(r)                  /                         /                        /
 *                                 13(r)                     13(r)                    13(r)
 */
void test_addRedBlackTree_add_13_to_use_tree_with_5_10_15_nodes(void)
{
    setNode(&node13, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *root = &node10;

    _addRedBlackTree(&root, &node13);

    TEST_ASSERT_EQUAL_PTR(root, &node10);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node13, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
}


/** 4-node case
 *                               10(b)  <- root            10(r)  <- root           10(r)  <- root
 * root -> 10(b)     add 20      /   \                     /   \                    /   \
 *         /   \    ------->   5(r)  15(r)      ----->   5(b)  15(b)      ----->  5(b)  15(b)
 *       5(r) 15(r)                     \                         \                        \
 *                                     20(r)                     20(r)                    20(r)
 */
void test_addRedBlackTree_add_20_to_use_tree_with_5_10_15_nodes(void)
{
    setNode(&node20, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *root = &node10;

    _addRedBlackTree(&root, &node20);

    TEST_ASSERT_EQUAL_PTR(root, &node10);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
}


/** 4-node case
 * root -> 20(b)                 20(b)  <- root            20(b)  <- root
 *         /   \     add 7       /   \                     /   \
 *      10(b) 25(b) ------->  10(b) 25(b)      ----->   10(r) 25(b)
 *      /   \                 /   \                     /   \
 *    5(r) 15(r)            5(r) 15(r)                5(b) 15(b)
 *                             \                         \
 *                            7(r)                      7(r)
 */
void test_addRedBlackTree_add_7_to_use_tree_with_5_10_15_20_25_nodes(void)
{
    setNode(&node7, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    setNode(&node25, NULL, NULL, 'b');
    setNode(&node20, &node10, &node25, 'b');
    Node *root = &node20;

    addRedBlackTree(&root, &node7);
 
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_PTR(root, &node20);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', &node20);
}


/** 4-node case
 * root ->     20(b)                             20(b)  <- root                    20(b)  <- root                     20(b)  <- root
 *         /          \                      /          \                      /          \                       /          \
 *       3(r)        30(r)                 3(r)        30(r)                 3(r)        30(r)                  3(b)        30(b)
 *      /   \        /   \       add 7    /   \        /   \                /   \        /   \                 /   \        /   \
 *    1(b) 10(b)  25(b) 40(b)  -------> 1(b) 10(b)  25(b) 40(b)  -------> 1(b) 10(b)  25(b) 40(b)  ------->  1(b) 10(r)  25(b) 40(b)
 *         /   \                             /   \                             /   \                              /   \
 *       5(r) 15(r)                        5(r) 15(r)                        5(b) 15(b)                         5(b) 15(b)
 *                                            \                                 \                                  \
 *                                           7(r)                              7(r)                               7(r)
 */
void test_addRedBlackTree_add_7_to_use_tree_with_1_4_5_10_15_20_25_30_40_nodes(void)
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    setNode(&node3, &node1, &node10, 'r');
    setNode(&node25, NULL, NULL, 'b');
    setNode(&node40, NULL, NULL, 'b');
    setNode(&node30, &node25, &node40, 'r');
    setNode(&node20, &node3, &node30, 'b');
    Node *root = &node20;

    addRedBlackTree(&root, &node7);

    TEST_ASSERT_EQUAL_PTR(root, &node20);

    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node3);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node40);
    TEST_ASSERT_EQUAL_NODE(&node25, &node40, 'b', &node30);
    TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node20);
}

