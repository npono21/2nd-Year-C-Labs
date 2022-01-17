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
	int newSize = 2 * (list->capacity);
	int roomInList = (list->capacity - list->size);

	//Main code body:
	if (roomInList <= 0) {		//Code executes if list has no more room. Otherwise skips to next portion.
		increase_capacity(list, newSize);		//Creates room by calling on increase_capacity to increase
	}											//list size by double.

	//This code executes no matter what, if room >= 1, it skips if statement and executes code below.
	list->elems[list->size] = element;	//Appends element to list.
	list->size += 1;		//Increases list size by 1 because of new element.
	return true;			//Boolean function returns true. Will always return true.
							/*The reason why we never need to return false is because this program
							will never evaluate to false. Unlike before, if there is no room initially,
							we make room. Therefore, there is no need to return false because it will
							never return.*/
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

/*
   Lab 7
   Student: Nicholai Ponomarev
   Student #: 101182048
 */

/* SYSC 2006 Lab 7
 *
 * additional_functions.c 
 */

/* Return the index (position) of the first occurrence of an integer
 * equal to target in the list pointed to by parameter list. 
 * Return -1 if target is not in the list.
 * Terminate the program via assert if list is NULL.
 */

int intlist_index(const intlist_t * list, int target)
{
	//Causes function to terminate if any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	//Initializing and assigning vars:
	int i = 0;
	int sizeList = list->size;

	for (i; i < sizeList; i++) {	//Searches through every element in list.
		if (list->elems[i] == target) {	//Nested if looking for target.
			return i;		//Returns index of target if found.
		}
	}
	return -1;			//Returns -1 if target is not found.
}

/* Count the number of integers that are equal to target, in the list 
 * pointed to by parameter list, and return that number.
 * Terminate the program via assert if list is NULL.
 */
int intlist_count(const intlist_t * list, int target)
{
	//Causes function to terminate if any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	//Initializing and assigning vars:
	int i = 0;
	int sizeList = list->size;
	int count = 0;

	for (i; i < sizeList; i++) {		//Searches through every element in list.
		if (list->elems[i] == target) {		//Nested if looking for target.
			count += 1;		//Adds 1 to var count if target is found.
		}	
	}
	return count;		//Returns amount of time target was found.
}

/* Determine if an integer in the list pointed to by parameter list 
 * is equal to target.
 * Return true if target is in the list, otherwise return false.
 * Terminate the program via assert if list is NULL.
 */
_Bool intlist_contains(const intlist_t * list, int target)
{
	//Causes function to terminate if any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.

	//Initializing and assigning vars:
	int i = 0;
	int sizeList = list->size;

	for (i; i < sizeList; i++){		//Searches through every element in list.
		if (list->elems[i] == target){		//Nested if looking for target.
			return true;	//Returns true if target is in list.
		}	
	}
	return false;		//Returns false if target is not in list.
}

/* Increase the capacity of the list pointed to by parameter list to
 * the specified new capacity.
 * Terminate the program via assert if new_capacity is not greater than the
 * list's current capacity, or if the memory required to increase the
 * list's capacity cannot be allocated.
 */
void increase_capacity(intlist_t *list, int new_capacity)
{
	//Declaring and Initializing Integers:
	int oldCapacity = list->capacity;
	int i = 0;
	int listSize = list->size;

	//Causes function to terminate if any of the two conditions below are T.
	assert(list != NULL);		//Terminates function if parameter list is NULL.
    assert(oldCapacity < new_capacity);  	//Terminate the program via assert if new_capacity is not greater than the list's current capacity
    
	//Memory Allocation:
    intlist_t *oldList = malloc(sizeof(intlist_t)); //oldMemory points to the memory that the old list took on the heap.
    oldList->elems = malloc(new_capacity*sizeof(int)); 	//Allocating memory needed according to the new_capacity.
  
	//For statement that adds the elements of the old list to the new list in exact order as before.
	for(i; i < listSize; i++) {		//Goes thru each element in list.
        oldList->elems[i] = list->elems[i];		//Adds element of old list to new list in same index.
    }

    list->capacity = new_capacity; 		//Increases the capacity of the new list to whatever int new_capacity represents.
    list->elems = oldList->elems;		//Sets the new list elements to the old list elements.	
}

/* Delete the integer at the specified position in the list pointed
 * to by parameter list.
 * Parameter index is the position of the integer that should be removed.
 * Terminate the program via assert if list is NULL, or if index
 * is not in the range 0 .. intlist_size() - 1.

 */

void intlist_delete(intlist_t *list, int index)
{
}

