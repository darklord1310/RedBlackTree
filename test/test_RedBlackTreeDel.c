#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "Rotations.h"
#include <CException.h>

Node node1, node2, node5, node10, node15, node12, node6, node11, node20, node4, node3, node7, node8, node13, node40, node25, node30, node50;


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
    resetNode(&node4, 4);
    resetNode(&node3, 3);
    resetNode(&node7, 7);
    resetNode(&node8, 8);
    resetNode(&node13, 13);
    resetNode(&node40, 40);
    resetNode(&node25, 25);
    resetNode(&node30, 30);
    resetNode(&node50, 50);
}   

void tearDown(void)
{
}


/* 2 node case
 *      root
 *       /    remove 2
 *      v      ----->   Throw ERR_NODE_UNAVAILABLE
 *    1(b)
 *
 */
void test_delRedBlackTree_2_node_remove_2_from_tree_with_root_1_should_throw_error()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    Node *root = &node1;
    
    Try{
        Node *node = delRedBlackTree(&root, &node2);
        TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAILABLE to be thrown. But receive none");
    }Catch(err){
        TEST_ASSERT_EQUAL_PTR(root, &node1);
        TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    }
}



/*  2 node case
 *      root                root
 *       /     remove 1      /
 *      v      ----->       v
 *     1(b)               NULL
 *
 */
void test_delRedBlackTree_2_node_remove_1_from_tree_with_root_1_root_should_point_to_NULL()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    Node *root = &node1;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node1);  
        TEST_ASSERT_EQUAL(1 , node->data);
        TEST_ASSERT_EQUAL_PTR(root,NULL);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  3 node case, empty child, delete left
 *      root                root
 *       /     remove 2      /
 *      v      ----->       v
 *     5(b)               5(b)
 *    /
 *  2(r)
 *
 */
void test_delRedBlackTree_3_node_remove_2_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'r');
    setNode(&node5, &node2, NULL, 'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL(root->data , 5);
        TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  3 node case, empty child, delete right
 *      root                 root
 *       /     remove 10      /
 *      v      ----->        v
 *     5(b)                5(b)
 *      \  
 *      10(r)
 *
 */
void test_delRedBlackTree_3_node_remove_10_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node10, NULL, NULL, 'r');
    setNode(&node5, NULL, &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node10);  
        TEST_ASSERT_EQUAL(10 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  4 node case , delete left
 *      root                 root
 *       /     remove 2       /
 *      v      ----->        v
 *     5(b)                5(b)
 *    /  \                   \
 * 2(r)   10(r)               10(r)
 *
 */
void test_delRedBlackTree_4_node_remove_2_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node10, NULL, NULL, 'r');
    setNode(&node2, NULL, NULL, 'r');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL(5, root->data);
        TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  4 node case, delete right
 *      root                 root
 *       /     remove 10      /
 *      v      ----->        v
 *     5(b)                5(b)
 *    /  \                /
 * 2(r)   10(r)         2(r)
 *
 */
void test_delRedBlackTree_4_node_remove_10_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node10, NULL, NULL, 'r');
    setNode(&node2, NULL, NULL, 'r');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node10);  
        TEST_ASSERT_EQUAL(10 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2,NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL, 'r', &node2);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  3 node case , all black node, delete right
 *      root                 root
 *       /     remove 10      /
 *      v      ----->        v
 *     5(b)                5(b)
 *    /  \                /
 * 2(b)   10(b)         2(r)
 *
 */
void test_delRedBlackTree_3_all_black_node_remove_10_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node10, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node10);  
        TEST_ASSERT_EQUAL(10 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2,NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node2);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  3 node case , all black node, delete left
 *      root                 root
 *       /     remove 2       /
 *      v      ----->        v
 *     5(b)                5(b)
 *    /  \                   \
 * 2(b)   10(b)              10(r)
 *
 */
void test_delRedBlackTree_3_all_black_node_remove_2_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node10, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL , &node10, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node10);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* 3 node , left rotate
 *      root                 root
 *       /     remove 2       /
 *      v      ----->        v
 *     5(b)                10(b)
 *    /  \                /   \
 * 2(b)   10(r)        5(b)    15(b)
 *       /  \             \
 *     6(b)  15(b)         6(r)
 *
 */
void test_delRedBlackTree_3_node_remove_2_from_tree_with_root_5_root_should_point_to_10()
{
    CEXCEPTION_T err;
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, &node6, &node15, 'r');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL(root->data,10);
        TEST_ASSERT_EQUAL_NODE(&node5 , &node15, 'b', &node10);
        TEST_ASSERT_EQUAL_NODE(NULL , &node6, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node6);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node15);

    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* 3 node
 *      root                 root
 *       /     remove 6       /
 *      v      ----->        v
 *     5(b)                5(b)
 *    /  \                /   \
 * 2(b)   10(r)        2(b)    10(b)
 *       /  \                   \
 *     6(b)  15(b)              15(r)
 *
 */
void test_delRedBlackTree_3_node_remove_6_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, &node6, &node15, 'r');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node6);  
        TEST_ASSERT_EQUAL(6 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node10, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node15);
         TEST_ASSERT_EQUAL_NODE(NULL , &node15, 'b', &node10);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
       
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* 3 node
 *      root                 root
 *       /     remove 15      /
 *      v      ----->        v
 *     5(b)                5(b)
 *    /  \                /   \
 * 2(b)   10(r)        2(b)    10(b)
 *       /  \                 /
 *     6(b)  15(b)          6(r)   
 *
 */
void test_delRedBlackTree_3_node_remove_15_from_tree_with_root_5_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, &node6, &node15, 'r');
    setNode(&node5, &node2 , &node10,  'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node15);  
        TEST_ASSERT_EQUAL(15 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node10, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        TEST_ASSERT_EQUAL_NODE(&node6, NULL , 'b', &node10);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node6);
        
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}


/* 3 node, right rotate
 *           root                 root
 *            /     remove 15      /
 *           v      ----->        v
 *         10(b)                6(b)
 *        /  \                 /   \
 *    6(r)   15(b)         2(b)    10(b)
 *    /  \                        /
 * 2(b)  7(b)                   7(r)
 *
 */
void test_delRedBlackTree_3_node_remove_15_from_tree_with_root_10_root_should_point_to_6()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node6, &node2, &node7, 'r');
    setNode(&node10, &node6 , &node15,  'b');
    Node *root = &node10;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node15);  
        TEST_ASSERT_EQUAL(15 , node->data);
        TEST_ASSERT_EQUAL(root->data,6);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node10, 'b', &node6);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node7);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        TEST_ASSERT_EQUAL_NODE(&node7, NULL, 'b', &node10);   
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}





/* 3 node
 *             root                 root
 *              /     remove 7       /
 *             v      ----->        v
 *           10(b)                10(b)
 *          /  \                 /   \
 *      5(r)   15(b)         5(b)    15(b)
 *      /  \                 /
 *   2(b)  7(b)           2(r)   
 *
 */
void test_delRedBlackTree_3_node_remove_7_from_tree_with_root_10_root_should_point_to_10()
{
    CEXCEPTION_T err;
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node5, &node2 , &node7,  'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *root = &node10;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node7);  
        TEST_ASSERT_EQUAL(7 , node->data);
        TEST_ASSERT_EQUAL(root->data,10);
        TEST_ASSERT_EQUAL_NODE(&node5 , &node15, 'b', &node10);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node2);
        TEST_ASSERT_EQUAL_NODE(&node2, NULL , 'b', &node5);
        
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/* 3 node
 *             root                 root
 *              /     remove 2       /
 *             v      ----->        v
 *           10(b)                10(b)
 *          /  \                 /   \
 *      5(r)   15(b)         5(b)    15(b)
 *      /  \                    \
 *   2(b)  7(b)                 7(r)
 *
 */
void test_delRedBlackTree_3_node_remove_2_from_tree_with_root_10_root_should_point_to_10()
{
    CEXCEPTION_T err;
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node5, &node2 , &node7,  'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *root = &node10;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL(root->data,10);
        TEST_ASSERT_EQUAL_NODE(&node5 , &node15, 'b', &node10);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node7);
        TEST_ASSERT_EQUAL_NODE(NULL ,&node7,  'b', &node5);
        
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}





/* 4 node
 *             root                       root
 *              /     remove 3             /
 *             v      ----->              v
 *            4(b)                      4(b)
 *          /     \                    /   \
 *       2(r)      6(r)            2(b)    6(r)
 *      /  \       /   \            /     /   \
 *   1(b)  3(b)  5(b)  7(b)     1(r)   5(b)   7(b)
 *
 */
void test_delRedBlackTree_4_node_remove_3_from_tree_with_root_4_root_should_point_to_4()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node2, &node1 , &node3,  'r');
    setNode(&node4, &node2 , &node6,  'b');
    Node *root = &node4;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node3);  
        TEST_ASSERT_EQUAL(3 , node->data);
        TEST_ASSERT_EQUAL_NODE(&node1, NULL , 'b', &node2);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node1);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node6, 'b', &node4);
        TEST_ASSERT_EQUAL_NODE(&node5, &node7 , 'r', &node6);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node7);

        TEST_ASSERT_EQUAL(root->data,4);

    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* 4 node
 *             root                       root
 *              /     remove 1             /
 *             v      ----->              v
 *            4(b)                      4(b)
 *          /     \                   /      \
 *       2(r)      6(r)           2(b)      6(r)
 *      /  \       /   \             \     /   \
 *   1(b)  3(b)  5(b)  7(b)         3(r) 5(b) 7(b)
 *
 */
void test_delRedBlackTree_4_node_remove_1_from_tree_with_root_4_root_should_point_to_4()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node2, &node1 , &node3,  'r');
    setNode(&node4, &node2 , &node6,  'b');
    Node *root = &node4;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node1);  
        TEST_ASSERT_EQUAL(1 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL ,&node3,  'b', &node2);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node3);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node6, 'b', &node4);
        TEST_ASSERT_EQUAL_NODE(&node5, &node7 , 'r', &node6);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node7);

        TEST_ASSERT_EQUAL(root->data,4);

    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/* 4 node
 *             root                       root
 *              /     remove 5             /
 *             v      ----->              v
 *            4(b)                      4(b)
 *          /     \                   /      \
 *       2(r)      6(r)           2(r)      6(b)
 *      /  \       /   \         /   \         \  
 *   1(b)  3(b)  5(b)  7(b)    1(b) 3(b)       7(r)
 *
 */
void test_delRedBlackTree_4_node_remove_5_from_tree_with_root_4_root_should_point_to_4()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node2, &node1 , &node3,  'r');
    setNode(&node4, &node2 , &node6,  'b');
    Node *root = &node4;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node5);  
        TEST_ASSERT_EQUAL(5 , node->data);
        TEST_ASSERT_EQUAL_NODE(&node1 ,&node3,  'r', &node2);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node3);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node6, 'b', &node4);
        TEST_ASSERT_EQUAL_NODE(NULL ,&node7, 'b', &node6);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node7);
         TEST_ASSERT_EQUAL(root->data,4);

    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/* 4 node
 *             root                       root
 *              /     remove 7             /
 *             v      ----->              v
 *            4(b)                      4(b)
 *          /     \                   /      \
 *       2(r)      6(r)           2(r)      6(b)
 *      /  \       /   \         /   \      / 
 *   1(b)  3(b)  5(b)  7(b)    1(b) 3(b)   5(r)    
 *
 */
void test_delRedBlackTree_4_node_remove_7_from_tree_with_root_4_root_should_point_to_4()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node3, NULL, NULL, 'b');
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node6, &node5, &node7, 'r');
    setNode(&node2, &node1 , &node3,  'r');
    setNode(&node4, &node2 , &node6,  'b');
    Node *root = &node4;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node7);  
        TEST_ASSERT_EQUAL(7 , node->data);
        TEST_ASSERT_EQUAL_NODE(&node1 ,&node3,  'r', &node2);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node3);
        TEST_ASSERT_EQUAL_NODE(&node2 , &node6, 'b', &node4);
        TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node6);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node5);
        TEST_ASSERT_EQUAL(root->data,4);

    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}





/* 3 node, The sibling is black and it has a red right newphew
 * Case 1a)
 *      root                 root                          root
 *       /     remove 2       /         rotate left         /
 *      v      ----->        v             ---->           v
 *     5(b)                5(b)                          10(b)
 *    /  \               //   \                         /   \
 * 2(b)   10(b)        NULL  10(b)                   5(b)   15(b)
 *         \                   \
 *         15(r)              15(r)
 *
 */
void test_delRedBlackTree_3_node_extra_test_case_remove_2_from_tree_with_root_5_root_should_point_to_10()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, NULL , &node15,  'b');
    setNode(&node5, &node2, &node10, 'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node15);
        TEST_ASSERT_EQUAL(root->data,10);
        TEST_ASSERT_EQUAL_NODE(&node5 ,&node15, 'b', &node10);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}
 

/* 3 node, The sibling is black and it has a red left newphew
 * Case 1b)
 *      root                 root                          root
 *       /     remove 2       /   right left rotate         /
 *      v      ----->        v      --------->             v
 *     5(b)                5(b)                          7(b)
 *    /  \               //   \                         /   \
 * 2(b)   10(b)        NULL  10(b)                   5(b)   10(b)
 *        /                 /
 *      7(r)              7(r)
 *
 */
void test_delRedBlackTree_3_node_extra_test_case_with_another_side_remove_2_from_tree_with_root_5_root_should_point_to_10()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'r');
    setNode(&node10, &node7, NULL, 'b');
    setNode(&node5, &node2, &node10, 'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node10);
        TEST_ASSERT_EQUAL(root->data,7);
        TEST_ASSERT_EQUAL_NODE(&node5 ,&node10, 'b', &node7);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}







 
/* 3 node all black, The sibling is black and both newphews are black
 * Case 2a)
 *      root                 root                      root
 *       /     remove 2       /                         //
 *      v      ----->        v      --------->         v
 *     5(b)                5(b)                       5(d)
 *    /  \               //   \                          \
 * 2(b)   10(b)        NULL  10(b)                       10(r)
 *     
 *
 */
void test_delRedBlackTree_3_node_all_black_remove_2_from_tree_with_root_5_color_black()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, NULL, NULL, 'b');
    setNode(&node5, &node2, &node10, 'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL, &node10 , 'd', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node10);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* 3 node all black, The sibling is black and both newphews are black
 * Case 2b)
 *      root                 root                      root
 *       /     remove 2       /                         /
 *      v      ----->        v      --------->         v
 *     5(r)                5(r)                       5(b)
 *    /  \               //   \                          \
 * 2(b)   10(b)        NULL  10(b)                       10(r)
 *     
 *
 */
void test_delRedBlackTree_3_node_all_black_remove_2_from_tree_with_root_5_color_red()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, NULL, NULL, 'b');
    setNode(&node5, &node2, &node10, 'r');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node10);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL, &node10 , 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* 3 node, The sibling is red
 * Case 3)
 *      root                 root                      root
 *       /     remove 2       /     rotate left         /
 *      v      ----->        v      --------->         v
 *     5(b)                5(r)                       7(b)
 *    /  \               //   \                      /   \
 * 2(b)   7(r)        NULL   7(r)                 5(b)   8(b)
 *       /  \               /   \                    \
 *    6(b)  8(b)          6(b)  8(b)                 6(r)
 */
void test_delRedBlackTree_3_node_remove_2_from_tree_with_root_5_root_should_point_to_7()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node8, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node7, &node6, &node8, 'r');
    setNode(&node5, &node2, &node7, 'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node2);  
        TEST_ASSERT_EQUAL(2 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node8);
        TEST_ASSERT_EQUAL(7,root->data);
        TEST_ASSERT_EQUAL_NODE(&node5, &node8 , 'b', &node7);
        TEST_ASSERT_EQUAL_NODE(NULL, &node6 , 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node6);
        
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



/* Combination test
 *            root                 root                      root                      root
 *             /     remove 1      /       case3             /          case1          /
 *            v      ----->        v      --------->        v         ------->        v
 *           2(b)                2(b)                     5(b)                      5(b)
 *          /  \                //   \                    /   \                     /    \
 *       1(r)   5(r)         NULL   5(r)               2(r)   6(b)               3(r)   6(b)
 *             /  \                /   \             //   \                      /   \
 *          3(b)  6(b)           3(b)  6(b)               3(b)                2(b)   4(b)
 *            \                    \                        \
 *            4(r)                 4(r)                     4(r)
 *
 */
void test_delRedBlackTree_3_node_combination_test_remove_1_from_tree_with_root_2_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node4, NULL, NULL, 'r');
    setNode(&node3, NULL, &node4, 'b');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node5, &node3, &node6, 'r');
    setNode(&node2, &node1, &node5, 'b');
    Node *root = &node2;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node1);  
        TEST_ASSERT_EQUAL(1 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        TEST_ASSERT_EQUAL_NODE(&node2, &node4, 'r', &node3);
        TEST_ASSERT_EQUAL_NODE(&node3, &node6 , 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node4);
        
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node6);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



//Mirror cases
/* 3 node, The sibling is black and it has a red left newphew
 * Case 1a)
 *          root                 root                          root
 *          /     remove 15      /         rotate right         /
 *         v      ----->        v             ---->            v
 *        10(b)               10(b)                          5(b)
 *      /   \                /   \\                         /   \
 *   5(b)   15(b)         5(b)   NULL                    2(b)   10(b)
 *   /                    /
 * 2(r)                2(r)
 *
 */
void test_delRedBlackTree_3_node_mirror_case_remove_15_from_tree_with_root_10_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node5, &node2, NULL, 'b');
    setNode(&node10, &node5 , &node15,  'b');
    Node *root = &node10;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node15);  
        TEST_ASSERT_EQUAL(15 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node10);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2 ,&node10, 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}





//Mirror cases
/* 3 node, The sibling is black and it has a red right newphew
 * Case 1b)
 *          root                 root                          root
 *          /     remove 15      /         rotate right         /
 *         v      ----->        v             ---->            v
 *        10(b)               10(b)                          7(b)
 *      /   \                /   \\                         /   \
 *   5(b)   15(b)         5(b)   NULL                    5(b)   10(b)
 *      \                    \
 *      7(r)                 7(r)
 *
 */
void test_delRedBlackTree_3_node_mirror_case_remove_15_from_tree_with_root_10_root_should_point_to_7()
{
    CEXCEPTION_T err;
    setNode(&node7, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node5, NULL, &node7, 'b');
    setNode(&node10, &node5 , &node15,  'b');
    Node *root = &node10;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node15);  
        TEST_ASSERT_EQUAL(15 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node10);
        TEST_ASSERT_EQUAL(root->data,7);
        TEST_ASSERT_EQUAL_NODE(&node5 ,&node10, 'b', &node7);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



//Mirror cases
/* 3 node all black, The sibling is black and both newphews are black
 * Case 2a)
 *      root                 root                      root
 *       /     remove 2       /                         //
 *      v      ----->        v      --------->         v
 *     5(b)                5(b)                       5(d)
 *    /  \               /   \\                      /
 * 2(b)   10(b)        2(b)   NULL                 2(r)
 *     
 *
 */
void test_delRedBlackTree_3_node_all_black_remove_10_from_tree_with_root_5_color_black()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, NULL, NULL, 'b');
    setNode(&node5, &node2, &node10, 'b');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node10);  
        TEST_ASSERT_EQUAL(10 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node2);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2, NULL, 'd', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}


//Mirror cases
/* 3 node all black, The sibling is black and both newphews are black
 * Case 2b)
 *      root                 root                      root
 *       /     remove 10      /                         /
 *      v      ----->        v      --------->         v
 *     5(r)                5(r)                       5(b)
 *    /  \               /   \\                      /
 * 2(b)   10(b)        2(b)  NULL                  2(r)
 *     
 *
 */
void test_delRedBlackTree_3_node_all_black_remove_10_from_tree_with_root_5_color_red()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node10, NULL, NULL, 'b');
    setNode(&node5, &node2, &node10, 'r');
    Node *root = &node5;
    Node *node;
    
    Try{
        node = _delRedBlackTree(&root, &node10);  
        TEST_ASSERT_EQUAL(10 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node2);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node2, NULL, 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




//Mirror cases
/* 3 node, The sibling is red
 * Case 3)
 *            root                 root                      root
 *             /     remove 20      /     rotate left         /
 *            v      ----->        v      --------->         v
 *           15(b)                15(b)                     5(b)
 *          /  \                /   \\                    /   \
 *       5(r)   20(b)        5(r)   NULL               2(b)   15(b)
 *      /  \                /   \                            /
 *   2(b)  7(b)           2(b)  7(b)                       7(r)
 */
void test_delRedBlackTree_3_node_remove_20_from_tree_with_root_15_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node5, &node2, &node7, 'r');
    setNode(&node15, &node5, &node20, 'b');
    Node *root = &node15;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node20);  
        TEST_ASSERT_EQUAL(20 , node->data);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node7);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(&node7, NULL, 'b', &node15);
        TEST_ASSERT_EQUAL_NODE(&node2, &node15 , 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




//Mirror cases
/* Combination test
 * 
 *            root                 root                      root                      root
 *             /     remove 20      /       case3             /          case1          /
 *            v      ----->        v      --------->         v         ------->        v
 *           15(b)                15(b)                     5(b)                      5(b)
 *          /  \                /   \\                    /   \                     /    \
 *       5(r)   20(b)        5(r)   NULL               2(b)   15(r)               2(b)   7(r)
 *      /  \                /   \                            /                          /   \
 *   2(b)  7(b)           2(b)  7(b)                       7(b)                      6(b)   15(b)
 *        /                    /                          /
 *      6(r)                 6(r)                       6(r)
 *
 */
void test_delRedBlackTree_3_node_combination_test_remove_20_from_tree_with_root_15_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node2, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'r');
    setNode(&node7, &node6, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node5, &node2, &node7, 'r');
    setNode(&node15, &node5, &node20, 'b');
    Node *root = &node15;
    Node *node;
    
    Try{
        node = delRedBlackTree(&root, &node20);  
        TEST_ASSERT_EQUAL(20 , node->data);
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node6);
        TEST_ASSERT_EQUAL_NODE(&node6, &node15, 'r', &node7);
        TEST_ASSERT_EQUAL_NODE(&node2, &node7 , 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node15);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}





/* test Remove Next Larger Successor
 * 
 *        parent left              parent left       
 *             /     sucessor 3      /         
 *            v       ----->        v         
 *           3(b)                4(b)                    
 *          /  \                /   \               
 *       NULL  4(r)          NULL   NULL             
 *
 */
void test_removeNextLargerSuccessor_given_3_node_remove_sucessor_3_parent_left_should_point_to_4()
{
    setNode(&node4, NULL, NULL, 'r');
    setNode(&node3, NULL, &node4, 'b');
    Node *parent = &node3;
    Node *node;

    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(3 , node->data);
    TEST_ASSERT_EQUAL_PTR(&node4, parent);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node4);

}




/* test Remove Next Larger Successor
 * 
 *        parent left              parent left       
 *             /     sucessor 3     //         
 *            v       ----->        v         
 *           3(b)                 NULL                   
 *          /  \                             
 *       NULL  NULL                       
 *
 */
void test_removeNextLargerSuccessor_given_2_node_remove_sucessor_3_parent_left_should_point_to_NULL()
{
    setNode(&node3, NULL, NULL, 'b');
    Node *parent = &node3;
    Node *node;

    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(3 , node->data);
    TEST_ASSERT_EQUAL_PTR(NULL,parent);
}




/* test Remove Next Larger Successor
 * 
 *        parent left             parent left      
 *             /     sucessor 3      /         
 *            v       ----->        v         
 *           3(r)                  NULL                   
 *          /  \                             
 *       NULL  NULL             
 *
 */
void test_removeNextLargerSuccessor_given_2_node_remove_successor_3_parent_left_should_point_to_NULL()
{
    setNode(&node3, NULL, NULL, 'r');
    Node *parent = &node3;
    Node *node;

    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(3 , node->data);
    TEST_ASSERT_EQUAL_PTR(NULL, parent);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node4);
}
 
 

 
/* test Remove Next Larger Successor
 * 
 *           parent                 parent    
 *             /     sucessor 5       /         
 *            v       ----->         v         
 *           12(b)                  12(b)                   
 *          /  \                       \    
 *       5(r)  15(r)                   15(r)
 *
 */
void test_removeNextLargerSuccessor_given_3_node_remove_successor_12_parent_should_point_to_12()
{
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node12, &node5, &node15, 'b');
    Node *parent = &node12;
    Node *node;

    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(5 , node->data);
    TEST_ASSERT_EQUAL_PTR(&node12, parent);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(NULL , &node15, 'b', &node12);
}



/* test Remove Next Larger Successor
 * 
 *           parent                 parent    
 *             /     sucessor 1       /         
 *            v       ----->         v         
 *           11(b)                  11(b)                   
 *          /  \                   /   \    
 *       5(b)  15(b)             5(b)  15(b)
 *      /     /                        /
 *    1(r)   12(r)                   12(r)
 */
void test_removeNextLargerSuccessor_remove_successor_1_parent_should_point_to_11()
{
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node12, NULL, NULL, 'r');
    setNode(&node5, &node1, NULL, 'b');
    setNode(&node15, &node12, NULL, 'b');
    setNode(&node11, &node5, &node15, 'b');
    Node *parent = &node11;
    Node *node;

    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(1 , node->data);
    TEST_ASSERT_EQUAL_PTR(&node11, parent);
    TEST_ASSERT_EQUAL_NODE(&node5 , &node15, 'b', &node11);
    TEST_ASSERT_EQUAL_NODE(&node12 , NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node12);
}



/** test Remove Next Larger Successor
 *
 *      parent's left                      parent's left                   parent's left
 *            |                                  |                               |
 *            v                                  v                               v
 *          10(b)                              10(b)                           10(b)
 *       /         \       successor 1      /         \                     /        \
 *     5(r)       15(r)   ------------>   5(r)       15(r)  ------------> 5(b)       15(r)
 *    /   \       /   \                  //  \       /   \                   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)               7(r)  13(b) 20(b)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_7_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'r');
    setNode(&node15, &node13, &node20, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
}




/* test Remove Next Larger Successor
 * 
 *           parent                    parent                        parent 
 *             /     successor 1          /                            //
 *            v       ----->            v            ------->         v
 *           10(b)                     10(b)                         10(d)    
 *         /     \                   //     \                       /     \
 *       5(b)    15(b)             5(d)     15(b)                5(b)     15(r)
 *      /  \    /    \                \    /   \                    \    /    \
 *  1(b)  6(b) 12(b) 20(b)          6(r) 12(b)  20(b)              6(r) 12(b) 20(b)
 */
void test_removeNextLargerSuccessor_remove_successor_1_parent_should_point_to_10()
{
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node12, NULL, NULL, 'b');
    setNode(&node5, &node1, &node6, 'b');
    setNode(&node15, &node12, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10;
    Node *node;
    
    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(1 , node->data);
    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_NODE(&node12 , &node20, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node12);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(&node5 , &node15, 'd', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
    
}


/** test Remove Next Larger Succesor
 *
 *      parent's left                      parent's left                   parent's left                   parent's left
 *            |                                  |                               |                               |
 *            v                                  v                               v                               v
 *          10(r)                              10(r)                           10(r)                           10(b)
 *       /         \       successor 1      /         \                     //        \                     /        \
 *     5(b)       15(b)   ------------>   5(b)       15(b)  ------------> 5(d)       15(b)  ------------> 5(b)       15(r)
 *    /   \       /   \                  //  \       /   \                   \       /   \                   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)               7(r)  13(b) 20(b)               7(r)  13(b) 20(b)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_7_10_13_15_20_should_remove_successor_1_with_parent_being_red(void)
{
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node5, &node15, 'r');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
}



/* test Remove Next Larger Successor
 * 
 *           parent                    parent                   
 *             /     sucessor 1          /                        
 *            v       ----->            v               
 *           10(b)                     10(b)                       
 *         /     \                   /     \                 
 *       5(b)    15(b)             5(d)     15(b)                
 *      /  \    /    \            /   \    /   \               
 *  1(b)  6(b) 12(b) 20(b)     2(b) 6(b) 12(b) 20(b)              
 *     \
 *    2(r)
 */
void test_removeNextLargerSuccessor_remove_successor_1_parent_should_point_to_10_2_should_more_up()
{
    setNode(&node2, NULL, NULL, 'r');
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node12, NULL, NULL, 'b');
    setNode(&node1, NULL, &node2, 'b');
    setNode(&node5, &node1, &node6, 'b');
    setNode(&node15, &node12, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10;
    Node *node;

    node = removeNextLargerSuccessor(&parent);  
    TEST_ASSERT_EQUAL(1 , node->data);
    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_NODE(&node5 , &node15, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(&node12 , &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node2, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node12);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node6);
}


/** test Remove Next Larger Successor
 *
 *      parent's left                      parent's left                   parent's left
 *            |                                  |                               |
 *            v                                  v                               v
 *          10(b)                              10(b)                           10(b)
 *       /         \       successor 1      /         \                      /        \
 *     5(r)       15(r)   ------------>   5(r)       15(r)  ------------> 7(r)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)          5(b) 8(b)  13(b) 20(b)
 *          \                                  \
 *          8(r)                               8(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_7_8_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node8, NULL, NULL, 'r');
    setNode(&node7, NULL, &node8, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'r');
    setNode(&node15, &node13, &node20, 'r');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
    TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'r', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
}


/** test Remove Next Larger Successor
 *
 *      parent's left                      parent's left                   parent's left
 *            |                                  |                               |
 *            v                                  v                               v
 *          10(b)                              10(b)                           10(b)
 *       /         \       successor 1      /         \                      /        \
 *     5(b)       15(b)   ------------>   5(b)       15(b)  ------------> 6(b)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \
 *  1(b) 7(b)  13(b) 20(b)             NULL 7(b)  13(b) 20(b)          5(b) 7(b)  13(b) 20(b)
 *       /                                  /
 *     6(r)                               6(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_6_7_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node6, NULL, NULL, 'r');
    setNode(&node7, &node6, NULL, 'b');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(&node5, &node7, 'b', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node6, &node15, 'b', &node10);
}



/** test Remove Next Larger Successor
 *
 *      parent's left                      parent's left                   parent's left                        parent's left
 *            |                                  |                               |                                    |
 *            v                                  v                               v                                    v
 *          10(b)                              10(b)                           10(b)                                10(b)
 *       /         \       successor 1      /         \                      /        \                          /        \
 *     5(b)       15(b)   ------------>   5(b)       15(b)  ------------> 7(b)       15(b)   ------------>     7(b)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \                    /   \       /   \
 *  1(b) 7(r)  13(b) 20(b)             NULL 7(r)  13(b) 20(b)          5(r) 8(b)  13(b) 20(b)               5(b) 8(b)  13(b) 20(b)
 *       /  \                               /  \                      //  \                                    \
 *     6(b) 8(b)                          6(b) 8(b)                 NULL 6(b)                                 6(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_5_6_7_8_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node6, NULL, NULL, 'b');
    setNode(&node8, NULL, NULL, 'b');
    setNode(&node7, &node6, &node8, 'r');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node5, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node5, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
    TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
}

/** test Remove Next Larger Successor
 *
 *      parent's left                      parent's left                   parent's left                        parent's left
 *            |                                  |                               |                                    |
 *            v                                  v                               v                                    v
 *          10(b)                              10(b)                           10(b)                                10(b)
 *       /         \       successor 1      /         \                      /        \                          /        \
 *     4(b)       15(b)   ------------>   4(b)       15(b)  ------------> 7(b)       15(b)   ------------>     7(b)       15(b)
 *    /   \       /   \                  //  \       /   \               /   \       /   \                    /   \       /   \
 *  1(b) 7(r)  13(b) 20(b)             NULL 7(r)  13(b) 20(b)          4(r) 8(b)  13(b) 20(b)               5(r) 8(b)  13(b) 20(b)
 *       /  \                               /  \                      //  \                                /   \
 *     5(b) 8(b)                          5(b) 8(b)                 NULL 5(b)                            4(b) 6(b)
 *        \                                  \                              \
 *       6(r)                               6(r)                           6(r)
 */
void test_removeNextLargerSuccessor_given_nodes_1_4_5_6_7_8_10_13_15_20_should_remove_successor_1(void)
{
    setNode(&node6, NULL, NULL, 'r');
    setNode(&node5, NULL, &node6, 'b');
    setNode(&node8, NULL, NULL, 'b');
    setNode(&node7, &node5, &node8, 'r');
    setNode(&node13, NULL, NULL, 'b');
    setNode(&node20, NULL, NULL, 'b');
    setNode(&node1, NULL, NULL, 'b');
    setNode(&node4, &node1, &node7, 'b');
    setNode(&node15, &node13, &node20, 'b');
    setNode(&node10, &node4, &node15, 'b');
    Node *parent = &node10, *removeNode;

    removeNode = removeNextLargerSuccessor(&parent);

    TEST_ASSERT_EQUAL_PTR(&node10, parent);
    TEST_ASSERT_EQUAL_PTR(&node1, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node4);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node8);
    TEST_ASSERT_EQUAL_NODE(&node4, &node6, 'r', &node5);
    TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(&node13, &node20, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node7, &node15, 'b', &node10);
}





/** Remove internal node test
 *            root                              root                            root                            root
 *            |                                  |                                |                               |
 *            v                                  v                                v                               v
 *          20(r)                              20(r)                            20(r)                           20(b)
 *       /         \        remove 30       /         \                      /        \\                     /        \
 *    10(b)       30(b)   ------------>  10(b)       40(b)  ------------> 10(b)      40(d) ------------>  10(r)      40(b)
 *    /   \       /   \                  /   \       /                   /   \       /                    /   \       /
 *  5(b) 15(b)  25(b) 40(b)            5(b) 15(b)  25(b)               5(b) 15(b)  25(r)                5(b) 15(b)  25(r)
 */
void test_delRedBlackTree_remove_30_should_replace_with_40_from_tree_with_5_10_15_20_30_25_40_nodes_with_parent_being_red(void)
{
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node10, &node5, &node15, 'b');
    setNode(&node25, NULL, NULL, 'b');
    setNode(&node40, NULL, NULL, 'b');
    setNode(&node30, &node25, &node40, 'b');
    setNode(&node20, &node10, &node30, 'r');
    Node *parent = &node20, *removeNode;

    removeNode = _delRedBlackTree(&parent, &node30);
    TEST_ASSERT_EQUAL_PTR(&node20, parent);
    TEST_ASSERT_EQUAL_PTR(&node30, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
    
    TEST_ASSERT_EQUAL_NODE(&node25, NULL, 'b', &node40);
    TEST_ASSERT_EQUAL_NODE(&node10, &node40, 'b', &node20);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
}





/** Remove internal node test
 *           root                               root                             root                           root
 *            |                                  |                                |                               |
 *            v                                  v                                v                               v
 *          20(b)                              20(b)                            20(b)                           20(d)
 *       /         \        remove 30       /         \                      /        \\                     /        \
 *    10(b)       30(b)   ------------>  10(b)       40(b)  ------------> 10(b)      40(d) ------------>  10(r)      40(b)
 *    /   \       /   \                  /   \       /                   /   \       /                    /   \       /
 *  5(b) 15(b)  25(b) 40(b)            5(b) 15(b)  25(b)               5(b) 15(b)  25(r)                5(b) 15(b)  25(r)
 */
void test_delRedBlackTree_remove_30_should_replace_with_40_from_tree_with_5_10_15_20_30_25_40_nodes_with_parent_being_black(void)
{
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node10, &node5, &node15, 'b');
    setNode(&node25, NULL, NULL, 'b');
    setNode(&node40, NULL, NULL, 'b');
    setNode(&node30, &node25, &node40, 'b');
    setNode(&node20, &node10, &node30, 'b');
    Node *parent = &node20, *removeNode;

    removeNode = _delRedBlackTree(&parent, &node30);

    TEST_ASSERT_EQUAL_PTR(&node20, parent);
    TEST_ASSERT_EQUAL_PTR(&node30, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
    TEST_ASSERT_EQUAL_NODE(&node25, NULL, 'b', &node40);
    TEST_ASSERT_EQUAL_NODE(&node10, &node40, 'd', &node20);
}



/** Remove internal node test
 *           root                               root
 *            |                                  |
 *            v                                  v
 *          20(b)                              20(b)
 *       /         \        remove 30       /         \
 *    10(b)       30(b)   ------------>  10(b)       25(b)
 *    /   \       /                      /   \
 *  5(r) 15(r)  25(r)                 5(b) 15(b)
 */
void test_delRedBlackTree_remove_30_should_replace_with_25_from_tree_with_5_10_15_20_30_25_nodes(void)
{
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'r');
    setNode(&node10, &node5, &node15, 'b');
    setNode(&node25, NULL, NULL, 'r');
    setNode(&node30, &node25, NULL, 'b');
    setNode(&node20, &node10, &node30, 'b');
    Node *parent = &node20, *removeNode;

    printf("test\n");
    removeNode = _delRedBlackTree(&parent, &node30);
    printf("end\n");
    TEST_ASSERT_EQUAL_PTR(&node20, parent);
    TEST_ASSERT_EQUAL_PTR(&node30, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
    TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', &node20);
}



/** Remove internal node test
 *           root                               root
 *            |                                  |
 *            v                                  v
 *          20(r)                              20(r)
 *       /         \        remove 30       /         \
 *    10(b)       30(b)   ------------>  10(b)       40(b)
 *    /   \       /   \                  /   \       /   \
 *  5(b) 15(b)  25(b) 40(b)            5(b) 15(b) 25(b) 50(r)
 *                        \
 *                       50(r)
 */
void test_delRedBlackTree_remove_30_should_replace_with_40_from_tree_with_5_10_15_20_30_25_40_50_nodes(void)
{
    setNode(&node5, NULL, NULL, 'b');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node10, &node5, &node15, 'b');
    setNode(&node25, NULL, NULL, 'b');
    setNode(&node50, NULL, NULL, 'r');
    setNode(&node40, NULL, &node50, 'b');
    setNode(&node30, &node25, &node40, 'b');
    setNode(&node20, &node10, &node30, 'r');
    Node *parent = &node20, *removeNode;

    removeNode = _delRedBlackTree(&parent, &node30);

    TEST_ASSERT_EQUAL_PTR(&node20, parent);
    TEST_ASSERT_EQUAL_PTR(&node30, removeNode);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
    TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node50);
    TEST_ASSERT_EQUAL_NODE(&node25, &node50, 'b', &node40);
    TEST_ASSERT_EQUAL_NODE(&node10, &node40, 'r', &node20);
}



 /* Remove root test
 * 
 *            root                 root        
 *             /     remove 3       /         
 *            v      ----->        v         
 *           3(b)                1(b)                    
 *          /  \                /   \               
 *       1(r)   NULL        NULL   NULL             
 *
 */
void test_delRedBlackTree_given_2_node_with_root_is_3_remove_3_root_should_point_to_1()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node3, &node1, NULL, 'b');
    Node *root = &node3;
    Node *node;

    Try{
        node = delRedBlackTree(&root, &node3);  
        TEST_ASSERT_EQUAL(3 , node->data);
        TEST_ASSERT_EQUAL_PTR(&node1, root);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node1);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}



 /* Remove root test
 * 
 *            root                 root        
 *             /     remove 3       /         
 *            v      ----->        v         
 *           3(b)                5(b)                    
 *          /  \                /   \               
 *       1(r)   5(r)        1(r)   NULL             
 *
 */
void test_delRedBlackTree_given_2_node_with_root_is_3_remove_3_root_should_point_to_5()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node5, NULL, NULL, 'r');
    setNode(&node3, &node1, &node5, 'b');
    Node *root = &node3;
    Node *node;

    Try{
        node = delRedBlackTree(&root, &node3);  
        TEST_ASSERT_EQUAL(3 , node->data);
        TEST_ASSERT_EQUAL_PTR(&node5, root);
        TEST_ASSERT_EQUAL_NODE(&node1 , NULL, 'b', &node5);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}


 /* Remove root test
 * 
 *              root                        root
 *               /                           /
 *              v         remove 5          v
 *           5(b)          ----->          7(b)
 *          /   \                         /   \
 *       1(r)  12(r)                   1(r)  12(r)          
 *             /  \                             \
 *          7(b)  15(b)                         15(b)
 *
 */
void test_delRedBlackTree_given_root_is_5_remove_3_root_should_point_to_7()
{
    CEXCEPTION_T err;
    setNode(&node1, NULL, NULL, 'r');
    setNode(&node15, NULL, NULL, 'b');
    setNode(&node7, NULL, NULL, 'b');
    setNode(&node5, &node1, &node12, 'b');
    setNode(&node12, &node7, &node15, 'r');
    Node *root = &node5;
    Node *node;

    Try{
        printf("here\n");
        node = delRedBlackTree(&root, root); 
        printf("end\n");
        TEST_ASSERT_EQUAL(5 , node->data);
        TEST_ASSERT_EQUAL_PTR(&node7, root);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node1);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node15);
        TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'r', &node12);
        TEST_ASSERT_EQUAL_NODE(&node1, &node12, 'b', &node7);
        
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}