#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "Rotations.h"
#include <CException.h>

Node node1, node2, node5, node10, node15, node12, node6, node11, node20;


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
void test_delRedBlackTree_remove_2_from_tree_with_root_1_should_throw_error()
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
void test_delRedBlackTree_remove_1_from_tree_with_root_1_root_should_point_to_NULL()
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





