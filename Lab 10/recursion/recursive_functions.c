/*
   Lab 10
   Student: Nicholai Ponomarev
   Student #: 101182048
 */

/* SYSC 2006 Lab 10. */

#include <stdio.h>
#include <math.h>

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
	if (n == 0) {				//Base case.
		return 1;
	}
	double result = x * power(x, n - 1);	//Recursive case. "power(x, n-1)" is the recursive call.
	return result;				//Returns result from recursive case.           
}
/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
	if (n < 10) {				//Base case.
		return 1;
	}

	int result = 1 + (num_digits(n / 10));	//Recursive case. "num_digits(n/10)" is the recursive call.
	//Adds 1 to the result of the function where 
	//the new parameter is n divided by 10. 
	return result;				//Then returns this result.
}

/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */
int occurrences(int a[], int n, int target)
{
	if (n == 0) {				//Base case if we search 0 elements of array.
		return 0;				//Returns 0 b/c we search 0 elements of array.
	}

	if (n >= 0 && a[n - 1] == target) {	//Base case if target value is found.
		int result = 1 + occurrences(a, n - 1, target);	//Recursive case. Adds 1 to the recursive case.
		return result;			//everytime target is found in first n elements of the array.
	}

	return occurrences(a, n - 1, target);	//Recursive case. "occurrences(a, n - 1, target)" is the recursive call.
}								//n decreases by 1 everytime the recursive case is called.

/* Challenge exercise: return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
	return -1;
}
