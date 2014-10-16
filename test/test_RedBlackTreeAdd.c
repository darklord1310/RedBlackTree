#include <stdio.h>
#include "unity.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertions.h"
#include "Rotations.h"
#include <CException.h>

Node node1, node2, node5, node10, node15, node12, node6, node11;


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
    setNode(&node5,NULL,NULL,'r');
	setNode(&node15,&node5,NULL,'b');
    Node *root = &node15;
    
    addRedBlackTree(&root,&node10);
    
    TEST_ASSERT_EQUAL_PTR(root,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,'r',&node5);
    TEST_ASSERT_EQUAL_NODE(NULL, NULL,'r',&node15);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15,'b',&node10);
}