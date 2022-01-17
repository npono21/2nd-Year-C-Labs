/*
   Lab 5
   Student: Nicholai Ponomarev
   Student #: 101182048
 */

/* fraction.c - SYSC 2006 Lab 5 */

#include <stdlib.h>				// abs(x)
#include <stdio.h>				// printf
#include <assert.h>				// assert

#include "fraction.h"

/* Print the fraction pointed to by pf in the form a/b. 
 */
void print_fraction(const fraction_t * pf)
{
	printf("%d/%d", pf->num, pf->den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
 */
int gcd(int a, int b)
{
	int q = abs(a);				//Sets an integer q to be the absolute val of a.
	int p = abs(b);				//Sets an integer p to be the absolute val of b.
	int r = q % p;				//Computes the modulus of q % p and stores it in r.

	while (r != 0) {			//Loop keeps running as long as r != 0. Stops when r = 0.
		q = p;					//Stores value of p in q.
		p = r;					//Stores value of r in p.
		r = q % p;				//Runs modulus operation with new q and p values.
	}

	return p;

	return -1;
}

/* Convert the fraction pointed to by pf to reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
   positive, and the numerator and denominator have no common
   divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
   are made positive, or if the numerator is positive and the 
   denominator is negative, the numerator is made negative and the 
   denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
   common divisor. 
 */
void reduce(fraction_t * pf)
{
	int num = pf->num;			//Initializes an int variable num with "->" every time needed.
	int den = pf->den;			//'' den ''.
	int GCD = gcd(num, den);	//Computes GCD with function from above.
	int reducedNum = num / GCD;	//Calculates reduced numerator using GCD.
	int reducedDen = den / GCD;	//Calculates reduced denominator with GDC.

	if (num && den > 0) {		//If-Statement executes only if the fraction is a positive fraction.
		reducedNum = num / GCD;	//''
		reducedDen = den / GCD;	//''
	}

	if (num == 0) {				//If-statement executes only if numerator is 0.
		reducedDen = 1;			//Automatically asigns denominator a value of 1.
		reducedNum = num;

	}

	if (num < 0 && den < 0) {	//Executes only if both numerator and denomintor are negative.
		reducedNum = abs(num) / GCD;	//Makes numerator positive by taking absolute value.
		reducedDen = abs(den) / GCD;	//'' denominator ''.

	}

	if ((num > 0) && (den < 0)) {	//Executes only if numerator is + but denominator is -.
		reducedNum = (num * -1) / GCD;	//Makes numerator negative by multiplying -1 to it.
		reducedDen = abs(den) / GCD;	//Make denominator positive.

	}

	*pf = (fraction_t) {
	reducedNum, reducedDen};	//Uses fraction_t struct to structure reducedNum & reducedDen.
}

/* Initialize the fraction pointed to by new_fraction 
   with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
void make_fraction(int a, int b, fraction_t * new_fraction)
{
	*new_fraction = (fraction_t) {
	a, b};						//Takes int's a and b and maked them into a fraction.
	int GCD = gcd(a, b);		//Calculated GCD for a and b.

	if (GCD != 1) {				//Returns reduced fraction if GCD is something other than 1 meaning fraction can be reduced.
		reduce(new_fraction);
	}

	if ((a > 0) && (b < 0)) {	//Makes sure that in the case if b < 0 and a > 0, returns the proper value.
		*new_fraction = (fraction_t) {
		(a * -1), abs(b)};
		reduce(new_fraction);
	}

	if (b == 0) {				//Exits the program is the denominator b = 0 because it is impossible to divide anything by 0.
		printf("The den is 0: ERROR!");
		exit(0);
	}
}

/* Initialize the fraction pointed to by sum with the sum of 
   the fractions pointed to by pf1 and pf2.
   The fraction created by this function is always in reduced form
   (see documentation for reduce).
 */
void add_fractions(const fraction_t * pf1, const fraction_t * pf2, fraction_t * sum)
{
	int f1Num = pf1->num;
	int f1Den = pf1->den;
	int f2Num = pf2->num;
	int f2Den = pf2->den;

	int addedNum = f1Num + f2Num;	//Creates a new numerator by adding original 2 together.
	int addedDen = f1Den + f2Den;	//'' denominator''.
	*sum = (fraction_t) {
	addedNum, addedDen};		//Creates new fraction with added numerator and denominator.

	if (f1Den == f2Den) {		//Straight up adds the fractions if the denominator are the same for both.
		addedNum = f1Num + f2Num;
		addedDen = f1Den + f2Den;
		*sum = (fraction_t) {
		addedNum, addedDen};
		reduce(sum);
	}

	else {						//Finds multiple to make fraction denominator = and then adds both when they are equal.
		int factor = f1Den * f2Den;
		int f1NumMultiplier = factor / f1Den;
		int newF1Num = f1NumMultiplier * f1Num;

		int f2NumMultiplier = factor / f2Den;
		int newF2Num = f2NumMultiplier * f2Num;

		int finalNum = newF1Num + newF2Num;

		*sum = (fraction_t) {
		finalNum, factor};
		reduce(sum);
	}
}

/* Initialize the fraction pointed to by product with the product of 
   the fractions pointed to by pf1 and pf2.
   The fraction created by this function is always in reduced form
   (see documentation for reduce).
 */
void multiply_fractions(const fraction_t * pf1, const fraction_t * pf2, fraction_t * product)
{
	int f1Num = pf1->num;
	int f1Den = pf1->den;
	int f2Num = pf2->num;
	int f2Den = pf2->den;

	int newNum = f1Num * f2Num;
	int newDen = f1Den * f2Den;

	*product = (fraction_t) {
	newNum, newDen};
	reduce(product);
}
