/*
   Lab 3
   Student: Nicholai Ponomarev
   Student #: 101182048
 */

/* SYSC 2006 Lab 3. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the n doubles in x[]. 
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], double n)
{
	double initialSum = 0;
	int i = 0;					//initializes counter for for-loop to 0.

	for (i; i < n; i++)
		initialSum += fabs(x[i]);

	double avg_magnitude = initialSum / n;

	return avg_magnitude;
}

/* Exercise 2. */

/* Return the average power of the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], double n)
{
	double initialSum = 0;
	int i = 0;					//initializes counter for for-loop to 0.

	for (i; i < n; i++)			//Runs through each element in array.
		initialSum += pow((x[i]), 2);	//Same exact code as above just instead of fabs
										// we have pow because a pow automatically converts
	double avg_power = initialSum / n;	// a negative number to a positive.

	return avg_power;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
	double max = arr[0];		//This initializes a max to be the first element in arr[].
	int i = 1;

	for (i; i < n; i++)			//Runs through each element in array.
		if (arr[i] > max)		//Compares every element with the current maximum element.
			max = arr[i];		//If current element is greater than max, it becomes max.
								//Loop continues for every element until true max is found.
	return max;					//Max is returned.
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
	double min = arr[0];		//This initializes a min to be the first element in arr[].
	int i = 1;

	for (i; i < n; i++)			//Runs through each element in array.
		if (arr[i] < min)		//Compares every element with the current minimum element.
			min = arr[i];		//If current element is smaller than min, it becomes min.
								//Loop continues for every element until true min is found.
	return min;					//Min is returned.
}

/* Exercise 5. */

/* Normalize the n doubles in x[]. 
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
	double minOfArray = min(x, n);	//Gets the min val of array.
	double maxOfArray = max(x, n);	//Gets the max val of array.
	double divisor = maxOfArray - minOfArray;	//Gets the divisor to make code cleaner later on.
	int i = 0;

	for (i; i < n; i++)			//Runs through each element in array.
		x[i] = (x[i] - minOfArray) / divisor;	//Calculates the normalixes val according to formula
}												// and writes it to whichever element is is taking 
												// denoted by x[i].
