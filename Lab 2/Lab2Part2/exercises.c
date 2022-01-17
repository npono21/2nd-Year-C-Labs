/*
Lab 2
	Student: Nicholai Ponomarev
	Student #: 101182048
*/

/* SYSC 2006 Lab 2, Part 2.
 *
 * Incomplete implementations of the functions that will be coded during the lab. 
 */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "exercises.h"

/* Returns n! for n >= 0. (0! is defined to be 1.)
   Note that the return type is int, and n! grows rapidly as n increases,
   so this function should only be used for fairly small values of n; 
   i.e., if ints are implemented as 32-bit values, n must be <= 15.
 */
int factorial(int n)
{
	int factorial = 1;			//We have to set initial factorial to 1 because 
	//the first factorial is 0! which is 1. 
	for (n; n > 0; n--) {		//Every time the loop is executed, n is updated, in this case lowers by 1 each time.
		factorial = factorial * n;	//If factorial was not already initialized, this line wouldn not work.
	}
	//The loop will run forever as long as n > 0.
	return factorial;
}

/* Returns the number of different ordered subsets of k objects picked
   from a set of n objects, for n > 0, k > 0, n >= k.
 */
int ordered_subsets(int n, int k)
{
	int numElements = factorial(n);
	int denominator = factorial(n - k);
	int ordered_subsets = numElements / denominator;

	return ordered_subsets;
}

/* Returns the binomial coefficient (n k); that is, the number of 
   combinations of k objects that can be chosen from a set of n objects, 
   for n > 0, k > 0, n >= k.
 */
int binomial(int n, int k)
{
	int orderedSubsetsCalc = ordered_subsets(n, k);
	int coefficient = factorial(k);
	int binomial = orderedSubsetsCalc / coefficient;

	return binomial;
}

/* Returns the cosine of x (measured in radians) by calculating
 * the first n terms of the infinite series expansion of cosine.
 */
double cosine(double x, int n)
{
	return -2.0;
}
