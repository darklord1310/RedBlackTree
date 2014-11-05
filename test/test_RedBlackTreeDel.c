#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "Rotations.h"
#include <CException.h>

Node node1, node2, node5, node10, node15, node12, node6, node11, node20, node4,node3,node7;


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




/*  3 node case
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




/*  3 node case
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




/*  4 node case
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
        TEST_ASSERT_EQUAL(root->data,5);
        TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
        TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
    }Catch(err){
        TEST_FAIL_MESSAGE("Not Expecting ERR_NODE_UNAVAILABLE to be thrown.");
    }
}




/*  4 node case
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




/*  3 node case , all black node
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




/*  3 node case , all black node
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



/* 3 node
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
        TEST_ASSERT_EQUAL_NODE(&node7, NULL, 'b', &node10);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'r', &node7);
        TEST_ASSERT_EQUAL_NODE(NULL , NULL, 'b', &node2);
        
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