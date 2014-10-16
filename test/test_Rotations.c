#include "unity.h"
#include "Rotations.h"
#include <stdio.h>
#include "InitNode.h"


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


/*				root
 *				 /
 *				v           root
 *				10           /
 *			   /            v
 * 			  5		--->	5
 *			 /			  /  \
 *			1			 1	 10
 */
void test_rightRotation_3_elements(void)
{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	rightRotate(&root);
	
	
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	
}




/*				root
 *				 /
 *				v                 root
 *				10                /
 *			   /  \              v
 * 			  5	  12	--->	5
 *			 /			      /  \
 *			1			     1	 10
 *								  \
 *								  12
 */
void test_rightRotation_4_elements(void)
{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, &node12, 'b');
	
	Node *root = &node10;
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	
}



/*				root
 *				 /
 *				v                 root
 *				10                /
 *			   /  \              v
 * 			  5	  12	--->	5
 *			 /\			      /  \
 *			1  6			 1	 10
 *								 / \
 *								6  12
 */
void test_rightRotation_5_elements(void)
{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node6, NULL, NULL, 'b');
	setNode(&node10, &node5, &node12, 'b');
	setNode(&node5, &node1, &node6, 'b');
	
	Node *root = &node10;
	
	rightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node6);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
}



/*				root
 *				 /
 *				v                  root
 *				5                 /
 *			     \                v
 * 			     10		--->	 10
 *			      \   		   /  \
 *			       12		 5	   12
 */
void test_leftRotation_3_elements(void)
{
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node5, NULL,&node10, 'b');
	setNode(&node10, NULL, &node12,'b');
	Node *root = &node5;
	
	leftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	
}




/*				root
 *				 /
 *				v                   root
 *				10                  /
 *			   /  \                v
 * 			  5	  12	--->	   12
 *			 	   \		      /  \
 *				   15		     10	 15
 *								/
 *							   5
 */
void test_leftRotation_4_elements(void)
{
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node12, NULL,&node15, 'b');
	setNode(&node10, &node5, &node12, 'b');
	
	Node *root = &node10;
	
	leftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node12);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.left, &node10);
	TEST_ASSERT_EQUAL_PTR(node12.right, &node15);
}



/*				root
 *				 /
 *				v                   root
 *				10                   /
 *			   /  \                 v
 * 			  5	  12	--->	  12
 *				 / \			 /  \
 *			    11  15		    10	 15
 *							   / \   
 *							  5  11
 */
void test_leftRotation_5_elements(void)
{
	setNode(&node11, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node12, &node11, &node15, 'b');
	setNode(&node10, &node5, &node12, 'b');
	
	Node *root = &node10;
	
	leftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node12);
	TEST_ASSERT_EQUAL_PTR(node11.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node11.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node11);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node12.left, &node10);
	TEST_ASSERT_EQUAL_PTR(node12.right, &node15);
}





/*				root
 *				 /
 *				v               root               root
 *				10              /                  /
 *			   /    left       v      right       v
 * 			  5	  	--->	  10      --->        6
 *			   \ 			 /                  /  \
 *			    6  		    6                  5   10
 *						   /     
 *						  5	
 */
void test_leftrightRotation_3_elements(void)
{
	setNode(&node6, NULL, NULL, 'b');
	setNode(&node5, NULL, &node6, 'b');
	setNode(&node10, &node5, NULL, 'b');
	
	Node *root = &node10;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node6);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node6.left, &node5);

}



/*				root
 *				 /
 *				v               root               root
 *				10              /                  /
 *			   /    left       v      right       v
 * 			  5	  	--->	  10      --->        6
 *			 / \ 			 /                  /  \
 *			1   6  		    6                  5   10
 *						   /                  /
 *						  5	                 1
 *						 /
 *						1
 */
void test_leftrightRotation_4_elements(void)
{
	setNode(&node6, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, &node6, 'b');
	setNode(&node10, &node5, NULL, 'b');
	
	Node *root = &node10;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node6);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node6.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);

}




/*				root
 *				 /
 *				v                  root               root
 *				12                  /                  /
 *			   /  \     left       v      right       v
 * 			  5	  15    --->	  12      --->       11
 *			 / \ 			     /  \               /  \
 *			1  11  		        11   15            5   12
 *			   /		       /                  / \   \
 *			  10 	          5	                 1  10  15
 *						     / \
 *			   			    1  10
 */
void test_leftrightRotation_6_elements(void)
{
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node11, &node10, NULL, 'b');
	setNode(&node5, &node1, &node11, 'b');
	setNode(&node12, &node5, &node15, 'b');
	
	Node *root = &node12;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node11);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node12.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node11.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node11.left, &node5);
}




/*				root
 *				 /
 *				v                  root               root
 *				11                  /                  /
 *			   /  \     left       v      right       v
 * 			  5	  12    --->	  11      --->        6
 *			 / \ 			     /  \               /  \
 *			1   6  		        6   12             5   11
 *				 \		       / \                /   / \
 *				 10		      5	 10              1   10  12
 *						     /
 *						    1
 */
void test_leftrightRotation_6_elements_with_another_pattern(void)
{
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node6, NULL, &node10, 'b');
	setNode(&node5, &node1, &node6, 'b');
	setNode(&node11, &node5, &node12, 'b');
	
	Node *root = &node11;
	
	leftRightRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node6);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node11.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node11.left, &node10);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node6.right, &node11);
	TEST_ASSERT_EQUAL_PTR(node6.left, &node5);
}



/*				root
 *				 /
 *				v                 root                 root
 *				10                 /                   /
 *			     \    right       v      left         v
 * 			      15	  	--->  10      --->       12
 *			     /  			   \                /  \
 *			    12  		       12              10  15
 *						            \     
 *						  	         15
 */
void test_rightLeftRotation_3_elements(void)
{
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node15, &node12,NULL, 'b');
	setNode(&node10, NULL, &node15, 'b');
	
	Node *root = &node10;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node12);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node12.left, &node10);

}



/*				root
 *				 /
 *				v                 root                root
 *				5                  /                   /
 *			     \      right      v      left        v
 * 			     10	  	--->	  5       --->        6
 *			    / \ 			   \                /  \
 *			   6   12  		        6              5   10
 *						            \                   \
 *						  	        10                  12
 *						             \
 *						             12
 */
void test_rightLeftRotation_4_elements(void)
{
	setNode(&node6, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node10, &node6, &node12, 'b');
	setNode(&node5, NULL, &node10, 'b');
	
	
	Node *root = &node5;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node6);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node6.left, &node5);

}




/*				root
 *				 /
 *				v                  root               root
 *				2                  /                  /
 *			   / \     right      v      left        v
 * 			  1	  10    --->	  2      --->        6
 *			 	 / \            /  \               /  \
 *		  		6  12          1   6              2   10
 *			   /	              / \            / \   \
 *			  5	        	     5  10          1  5   12
 *						             \ 
 *			   			             12
 */
void test_rightLeftRotation_6_elements(void)
{
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node6, &node5, NULL, 'b');
	setNode(&node10, &node6, &node12, 'b');
	setNode(&node2, &node1, &node10, 'b');
	
	Node *root = &node2;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node6);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node2.right, &node5);
	TEST_ASSERT_EQUAL_PTR(node2.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node6.left, &node2);
}




/*				root
 *				 /
 *				v                    root               root
 *				2                   /                  /
 *			   / \     right       v      left        v
 * 			  1	  10   --->	       2      --->        5
 *			  	 / \	         /  \               /  \
 *			    5  12	        1   5              2   10
 *			   	 \                   \            /   / \
 *			  	 6	              	 10          1   6   12
 *						            / \
 *						           6  12
 */
void test_rightLeftRotation_6_elements_with_another_pattern(void)
{
	setNode(&node6, NULL, NULL, 'b');
	setNode(&node12, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, NULL, &node6, 'b');
	setNode(&node10, &node5, &node12, 'b');
	setNode(&node2, &node1, &node10, 'b');
	
	Node *root = &node2;
	
	rightLeftRotate(&root);
	
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_PTR(node6.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node12.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node2.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node2.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node12);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node6);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node2);
}

void changeRootByVal(Node *node, Node *newNode)
{
	node = newNode;
	printf("changeRootByVal: node = %x\n", node);
}


void changeRootByRef(Node **nodePtr, Node *newNode)
{
	*nodePtr = newNode;
	printf("changeRootByRef: node = %x\n", *nodePtr);
}


// void test_changeRootByVal()
// {
	// Node *root;
	// root = &node10;
	
	// printf("test_changeRootByVal()\n");
	// printf("root is %d with address %x\n", root->data, root);
	// changeRootByRef(root, &node5);
	// printf("root is %d with address %x\n", root->data, root);
	
// }


// void test_changeRootByRef()
// {
	// Node *root;
	// root = &node10;
	
	// printf("test_changeRootByRef()\n");
	// printf("root is %d with address %x\n", root->data, root);
	// changeRootByRef(root, &node5);
	// printf("root is %d with address %x\n", root->data, root);
	
// }