/*
   Lab 4
   Student: Nicholai Ponomarev
   Student #: 101182048
*/

/* fraction.c - SYSC 2006 Lab 4 */

#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf

#include "fraction.h"

/* Print fraction f in the form a/b. */
void print_fraction(fraction_t f)
{
	printf("%d/%d", f.num, f.den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
*/
int gcd(int a, int b){

	int q = abs(a);			//Sets an integer q to be the absolute val of a.
	int p = abs(b);			//Sets an integer p to be the absolute val of b.
	int r = q % p;			//Computes the modulus of q % p and stores it in r.

	while (r != 0){			//Loop keeps running as long as r != 0. Stops when r = 0.
		q = p;				//Stores value of p in q.
		p = r;				//Stores value of r in p.
		r = q % p;			//Runs modulus operation with new q and p values.
	}

	return p;				//Returns the value for p (GCD) when loop finishes, i.e., r = 0.

}

/* Return the reduced form of fraction f.

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
fraction_t reduce(fraction_t f)
{ 
	int GCD = gcd(f.num, f.den);		//Computes GCD with function from above.
	int reducedNum = f.num/GCD;			//Calculates reduced numerator using GCD.
	int reducedDen = f.den/GCD;			//Calculates reduced denominator with GDC.
	fraction_t reducedF = {reducedNum, reducedDen};			//Creates a new fraction using reduced numerator and denominator.

	if (f.num && f.den > 0){			//If-Statement executes only if the fraction is a positive fraction.
		reducedNum = f.num/GCD;			//''
		reducedDen = f.den/GCD;			//''
		fraction_t reducedF = {reducedNum, reducedDen};			//''
		return reducedF;		//Returns the calculated reduces fraction.
	}		

	if (f.num == 0){			//If-statement executes only if numerator is 0.
		reducedDen = 1;			//Automatically asigns denominator a value of 1.
		reducedNum = f.num;
		fraction_t reducedF = {reducedNum, reducedDen};
		return reducedF;
	}

	if (f.num < 0 && f.den < 0){			//Executes only if both numerator and denomintor are negative.
		reducedNum = abs(f.num)/GCD;		//Makes numerator positive by taking absolute value.
		reducedDen = abs(f.den)/GCD;		//'' denominator ''.
		fraction_t reducedF = {reducedNum, reducedDen};
		return reducedF;
	}
			
	if ((f.num > 0) && (f.den < 0)){			//Executes only if numerator is + but denominator is -.
		reducedNum = (f.num * -1)/GCD;			//Makes numerator negative by multiplying -1 to it.
		reducedDen = abs(f.den)/GCD;			//Make denominator positive.
		fraction_t reducedF = {reducedNum, reducedDen};
		return reducedF;
	}
	
    return reducedF;		//Returns reduced fraction is none of the if-statements are executes (i.e, not needed).
}

/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
*/
fraction_t make_fraction(int a, int b)
{
	fraction_t originalF = {a, b};			//Takes int's a and b and maked them into a fraction.
	int GCD = gcd(a, b);			//Calculated GCD for a and b.

	if (GCD == 1 && (a, b > 0)){			//Returns original fraction is a and b > 0 and GCD is 1.
		fraction_t originalF = {a, b};
		return originalF;
	}

	if (GCD != 1){			//Returns reduced fraction if GCD is something other than 1 meaning fraction can be reduced.
		fraction_t reducedF = reduce(originalF);
		return reducedF;
	}

	if ((a > 0) && (b < 0)){			//Makes sure that in the case if b < 0 and a > 0, returns the proper value.
		fraction_t originalF = {(a*-1), abs(b)};
		fraction_t reducedF = reduce(originalF);
		return reducedF;	
	}

	if (b == 0){		//Exits the program is the denominator b = 0 because it is impossible to divide anything by 0.
		printf("The den is 0: ERROR!");
		exit(0);	
	}

    return originalF;
}

/* Return the sum of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t add_fractions(fraction_t f1, fraction_t f2)
{
	int addedNum = f1.num + f2.num;			//Creates a new numerator by adding original 2 together.
	int addedDen = f1.den + f2.den;			//'' denominator''.
	fraction_t addedF = {addedNum, addedDen};		//Creates new fraction with added numerator and denominator.

	if (f1.den == f2.den){				//Straight up adds the fractions if the denominator are the same for both.
		addedNum = f1.num + f2.num;
		addedDen = f1.den + f2.den;
		fraction_t addedF = {addedNum, addedDen};
		fraction_t reducedAddedF = reduce(addedF);
		return reducedAddedF;
	}

	else {				//Finds multiple to make fraction denominator = and then adds both when they are equal.
		int factor = f1.den * f2.den;
		int f1NumMultiplier = factor / f1.den;
		int newF1Num = f1NumMultiplier * f1.num;

		int f2NumMultiplier = factor / f2.den;
		int newF2Num = f2NumMultiplier * f2.num;

		int finalNum = newF1Num + newF2Num;

		fraction_t addedF = {finalNum, factor};
		fraction_t reducedAddedF = reduce(addedF);

		return reducedAddedF;
	}

	return addedF;
}

/* Return the product of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t multiply_fractions(fraction_t f1, fraction_t f2)		//Straightforward program to * fractions.
{
	int newNum = f1.num * f2.num;
	int newDen = f1.den * f2.den;

	fraction_t fProduct = {newNum, newDen};
	fraction_t reducedFProduct = reduce(fProduct);

	return reducedFProduct;
}
