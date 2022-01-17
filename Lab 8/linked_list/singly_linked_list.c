/*
   Lab 8
   Student: Nicholai Ponomarev
   Student #: 101182048
 */

/* SYSC 2006 Lab 8
   A module that implements a singly-linked list of integers. 
 */

#include <assert.h>				// assert
#include <stdlib.h>				// malloc, free
#include <stdbool.h>
#include <stdio.h>				// printf

#include "singly_linked_list.h"

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
	for (intnode_t * curr = head; curr != NULL; curr = curr->next) {
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

	intnode_t * curr;

	/* The loop prints a every node in the linked list except the last one,
	   using the format "value -> ", where "->" represents the link from each node
	   to the following node.

	   Notice that the loop condition is:
	   curr->next != NULL
	   and not:
	   curr != NULL

	   During the last iteration, the value in the second-last node is
	   printed, then curr is updated to point to the last node. The
	   condition curr->next != NULL now evaluates to false, so the 
	   loop exits, with curr pointing to the last node (which has  
	   not yet been printed.) 
	 */

	for (curr = head; curr->next != NULL; curr = curr->next) {
		printf("%d -> ", curr->value);
	}

	/* Print the last node. */
	printf("%d", curr->value);
}

/*****************************************************************
 * Solutions to Lab 8
 *****************************************************************/

// Exercise 1

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Count the number of nodes in the linked list that contain an integer
 * equal to target, and return that count.
 * 
 * Return 0 if the linked list is empty.
 */
int count(intnode_t * head, int target)
{
	//Initializing and setting var's:
	int count = 0;

	//While loop will run if head is not NULL.
	while (head != NULL) {
		if (head->value == target)	//Executes if value in list is target value.
			count++;			//Adds 1 to var count if target is found.
		head = head->next;		//Moves on to next value in list.
	}
	return count;				//Returns accumulated count of how many times target was found.
}

// Exercise 2

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the largest integer in the linked list.
 *
 * The function terminates (via assert) if the linked list is empty.
 */
int max(intnode_t * head)
{
	//Terminates function is linked list is empty.
	assert(head != NULL);

	//Initializing and setting var's.
	int max = 0;

	//While loop will run if head is not NULL.
	while (head != NULL) {
		if (max < head->value)	//Executes if current max val smaller than value in list.
			max = head->value;	//Sets new max val to that value in list.
		head = head->next;		//Moves on to next value in list.
	}
	return max;					//Returns final max after iterating thru entire list.
}

// Exercise 3

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the index (position) of the first node that contains an 
 * integer equal to target. The first node is at index 0, the second node
 * is at index 1, etc.
 *
 * Return -1 if target is not in the linked list, or if the linked list
 * is empty.
 */
int index(intnode_t * head, int target)
{
	//Initializing and setting var's.
	int i = 0;

	//While loop executes if head is not NULL.
	while (head != NULL) {
		if (head->value == target)	//Executes if current value is target value.
			return i;			//Returns index of target.
		i++;					//Adds 1 to index if target not found.
		head = head->next;		//Moves onto next value if target not found.
	}
	return -1;					//Returns -1 if target not found.
}

// Exercise 4

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Parameter other points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Extend the linked list pointed to by head so that it contains
 * copies of the values stored in the linked list pointed to by other.
 *
 * The function terminates (via assert) if the the linked list 
 * pointed to by head is empty.
 */
void extend(intnode_t * head, intnode_t * other)
{
	//Terminates function if the linked list pointed to by head is empty.
	assert(head != NULL);

	//Executes if both lists contain actual elements, i.e., not NULL.
	if (head != NULL && other != NULL) {
		if (head->next == NULL)	//Executes if program at end of list pointed to by head.
			head->next = other;	//Adds other values to end of list pointed to by head.
		else
			extend(head->next, other);	//Calls the function. 
	}
}

// Exercise 5

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * The function terminates (via assert) if the linked list is empty.
 *
 * Copy the value in the head node to the location pointed to by
 * parameter popped_value, delete the head node, and return a pointer
 * to the first node in the modified list.
 */
intnode_t * pop(intnode_t * head, int *popped_value)
{
	//Terminates function if the linked list pointed to by head is empty.
	assert(head != NULL);

	*popped_value = head->value;	//Assigns int pointed to by popped_value with value of head of list.

	intnode_t *firstNode = head;	//Node points to the first node in head.
	free(firstNode);			//Deallocates node, so essentially removes the first node in head.
								// This step will keep repeating for as long as many times as popped_value is.
	head = head->next;			//Moves on to next value in list.

	return head;				//Returns the new modified list.
}
