
/*
	Lab 11
	Nicholai Ponomarev
	101182048
*/

/* SYSC 2006 Lab 11 
 */

#include <assert.h>				// assert
#include <stdlib.h>				// malloc, free
#include <stdbool.h>
#include <stdio.h>				// printf

#include "sl_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Return a pointer to a new intnode_t (a node in a singly-linked list).

   Parameter value: the integer to be stored in the node.
   Parameter next: a pointer to the node that the new node should point to.
   This pointer should be NULL if the new node is the last node in the 
   linked list.
   Terminate (via assert) if memory for the node cannot be allocated.
 */
intnode_t * intnode_construct(int value, intnode_t * next)
{
	intnode_t * p = malloc(sizeof(intnode_t));
	assert(p != NULL);
	p->value = value;
	p->next = next;
	return p;
}
/* Parameter head points to the first node in a linked list, or is NULL
   if the linked list is empty. Insert a node containing the specified 
   integer value at the front of the linked list, and return a pointer to 
   the first node in the modified list.
 */
intnode_t * push(intnode_t * head, int value)
{
	return intnode_construct(value, head);
}

/* Parameter head points to the first node in the list.
   Return the length of a linked list (0 if the linked list is empty). 
 */
int length(intnode_t * head)
{
	int count = 0;
	for (intnode_t * current = head; current != NULL; current = current->next) {
		count += 1;
	}
	return count;
}

/* Parameter head points to the first node in a linked list.
   Print the linked list, using the format:
   value1 -> value2 -> value3 -> ... -> last_value
 */
void print_list(intnode_t * head)
{
	if (head == NULL) {
		printf("empty list");
		return;
	}

	intnode_t * current;

	/* Print every node in the linked list except the last one.

	   Notice that the loop condition is:
	   current->next != NULL
	   and not:
	   current != NULL

	   During the last iteration, the value in the second-last node is
	   printed, then current is updated to point to the last node. The
	   condition current->next != NULL now evaluates to false, so the 
	   loop exits, with current pointing to the last node (which has  
	   not yet been printed.) 
	 */
	for (current = head; current->next != NULL; current = current->next) {
		printf("%d -> ", current->value);
	}

	/* Print the last node. */
	printf("%d", current->value);
}

/*****************************************************************
 * Solutions to Lab 11
 *****************************************************************/

// Exercise 1

intnode_t * add(intnode_t * head, int elem, int index)
{
	//Initializing Var's:
	int listLength = length(head);	//Getting the length of the singly linked list in integer.
	int i = 0;					//Intializing "i" outside of for...loop for conciseness.

	//Subcases if the list is empty. 2 subcases:
	if (listLength == 0) {

		//Subcase 1: Index = 0:
		if (index == 0) {
			head = push(head, elem);	//Inserts the specified "elem" at front of linked list.
			return head;		//Return pointer to first node in the modified list.
		}
		//Subcase 2: Index is invalid. Conditions for invalid index: index is smaller than 0 or larger than length.
		else if (index < 0 || index > listLength) {
			assert(index < 0 || index > listLength);	//Function terminates if any invalid condition is true.
		}
	}
	//Subcases if the list has one or more nodes. 4 subcases:
	else if (listLength >= 1) {

		//Subcase 1: Index = 0:
		if (index == 0) {		//Body executes if index is 0. 
			head = push(head, elem);	//Inserts the specified "elem" at front of linked list.
			return head;		//Returns pointer to first ndoe in the modified list.
		}
		//Subcase 2: Index > 0 AND Index < Length:
		else if (index > 0 && index < listLength) {
			intnode_t * node = push(NULL, elem);	//Creates a linked list node where value is "elem" and it points to NULL. Using the push function.  
			intnode_t * temp = head;	//Creates a linked list node "temp" which has the value of head.
			while (i < index - 1) {	//Executes body while i is less than "index" value - 1.
				temp = temp->next;	//Sets temp with the value of the next node after current node.
				i++;			//Increaments i by 1 each iteration.
			}
			node->next = temp->next;	//Sets node->next with the value of the next node after current node.
			temp->next = node;	//Sets the next node in the linked list with value of node.
			return head;		//Returns pointer to first node in the modified list.

		}
		//Subcase 3: Index == Length:
		else if (index == listLength) {
			intnode_t * node = push(NULL, elem);	//Same as above.
			intnode_t * temp = head;	//''
			while (i < index - 1) {	//''
				temp = temp->next;	//''
				i++;			//''
			}
			temp->next = node;	//Sets the next node in the linked list with the value of node.
			return head;		//Returns pointer to first node in the modified list.
		}
		//Subcase 4: Index is invalid. Conditions for invalid index: index is smaller than 0 or larger than length.
		else if (index < 0 || index > listLength) {
			assert(index < 0 || index > listLength);	//Function terminates if any invalid condition is true.
		}
	}
}
// Exercise 2

void every_other(intnode_t * head)
{
	if (head == NULL) {
		return;
	}
	//Initiazing the previous node and the currentNode to be deleted.
	intnode_t * previousNode = head;
	intnode_t * deletedNode = head->next;

	//While loop that will look at the list and delete every other node. Based on two conditions being T.
	while (previousNode != NULL && deletedNode != NULL) {	//Both conditions have to be true for while body to execute.
		previousNode->next = deletedNode->next;	//
		free(deletedNode);		//Free's the memory of the currentNode.
		previousNode = previousNode->next;	//Updates previousNode with the value of the next node.

		//Executes if previousNode is not NULL(invalid):
		if (previousNode != NULL) {
			deletedNode = previousNode->next;	//Updates currentNode with the value of the next node.
		}
	}
}
