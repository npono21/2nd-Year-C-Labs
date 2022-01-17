/*
   Lab 6
   Student: Nicholai Ponomarev
   Student #: 101182048
 */

/* SYSC 2006 Lab 6
 *
 * array_list.c 
 *
 * Prototype of a dynamically allocated, fixed-capacity list that supports a 
 * subset of the operations provided by Python's list class.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

/* Construct a new, empty list, and return a pointer to it
 * Parameter capacity is the # of elements that can be stored in the list.
 * Terminate the program via assert if capacity is <= 0.
 * Terminate the program via assert if memory for the list cannot be 
 * allocated from the heap.
 */
intlist_t * intlist_construct(int capacity)
{
	// Note - this is an incomplete function definition.
	// You must modify the function so that it correctly implements all 
	// of the requirements listed in the header comment. 

	intlist_t * list = malloc(sizeof(intlist_t));	//Dynamically allocated memory of the size of our list and points to it.

	//Initialzing struct's element:
	list->capacity = capacity;	//Selecting the capacity member of struct pointed by list and setting it to capacity.
	list->size = 0;				//Selecting the size member of struct pointed by list and setting it to 0.
	list->elems = malloc(capacity * sizeof(int));	//Selecting the elems member of struct pointed by list and setting it to malloc(capacity * sizeof(int)).
	
	return list;				//Returns list.   

	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);
	assert(list->capacity <= 0);           
}

/* Destroy the list pointed to by parameter list, deallocating all memory 
 * that was allocated from the heap.
 * Terminate the program via assert if list is NULL.
 */
void intlist_destroy(intlist_t * list)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	free(list->elems);			/* Return the array to the heap. */
	free(list);					/* Return the structure to the heap. */
}

/* Print the list pointed to by parameter list to the console.
 * Terminate the program via assert if list is NULL.
 */
void intlist_print(const intlist_t * list)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	//Assigning vars:
	int i = 0;					//Initalizing index i of type int to 0.
	int maxSize = list->size;
	int *listElems = list->elems;

	printf("[");				//Prints initial array open bracket.

	for (i; i < maxSize; i++) {	//For loop running thru each element in list.
		if (i == 0) {
			printf("%d", listElems[i]);	//Always prints the first element of the list without a space.
		} else {
			printf(" %d", listElems[i]);	//Prints every other element of list after that with space.
		}
	}

	printf("]\n");				//Prints clsosing array bracket.

}

/* Insert element at the end of the list pointed to by list.
 * Return true if element is appended; otherwise return false
 * (which indicates that the list is full.)
 * Terminate the program via assert if list is NULL.
 */
_Bool intlist_append(intlist_t * list, int element)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	//Initializing and assigning vars:
	int roomInList = (list->capacity - list->size);

	//Main code body:
	if (roomInList >= 1) {		//Code only executes if list has room for 1 or more appends.
		list->elems[list->size] = element;	//Appends element to list.
		list->size += 1;		//Increases list size by 1 because of new element.
		return true;			//Boolean function returns true.
	} else {
		return false;			//Otherwise, returns false if list has no room.
	}
}

/* Return the maximum number of integers that can be stored in the list 
 * pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_capacity(const intlist_t * list)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	return list->capacity;
}

/* Return the number of integers in the list pointed to by parameter list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_size(const intlist_t * list)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	return list->size;
}

/* Return the element located at the specified index, in the list
 * pointed to by parameter list. 
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. intlist_size() - 1.
 */
int intlist_get(const intlist_t * list, int index)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.
	assert((list->capacity - 1) > index);	//Condition: list->capacity - 1 is bigger than index.

	//Initializing and assigning vars:
	int i = 0;
	int sizeList = list->size;

	for (i; i < sizeList; i++) {	//Searched through each element of list.
		return list->elems[index];	//Returns the element of list at position index.
	}
}

/* Store element at the specified index, in the list pointed to by 
 * parameter list. Return the integer that was previously 
 * stored at that index.
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. intlist_size() - 1.
 */
int intlist_set(intlist_t * list, int index, int element)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.
	assert((list->capacity - 1) > index);	//Condition: list->capacity - 1 is bigger than index.

	//Initialzing var to store original element.
	const oriElement = list->elems[index];	//Variable is type const because it will never be changed.

	list->elems[index] = element;	//Appends element to list.
	return oriElement;			//Returns original element.
}

/* Empty the list pointed to by parameter list.
 * Memory allocated to the list is not freed, so the emptied list can 
 * continue to be used.
 * Terminate the program via assert if list is NULL.
 */
void intlist_removeall(intlist_t * list)
{
	//Causes function to terminate of any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	//Initializing and assigning vars:
	int i = 0;
	const capacity = list->capacity;

	for (i; i < capacity; i++) {	//Looks thru every element in list up to capacity.
		list->elems[i] = 0;		//Sets all elements in list to 0.
		list->size = 0;			//After for loop, sets list size to 0 b/c a list of all zero's represents nothing but 0.
	}

}
