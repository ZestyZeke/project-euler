/*
 * p10.h
 *
 * Zeke Reyna
 *
 * Finds the sum of the primes below a bound.
 */

#ifndef _p10_h_
#define _p10_h_

#include <stdio.h>
#include <stdlib.h> // might not be needed
#include <math.h> // link with -lm

#define NOT_PRIME -1
#define BOUND_DEF 10

/*
 * creates an array of numbers from 2 to
 * size + 1 [2, size + 2)
 * note: to generate numbers under a bound,
 * give (bound - 2) for size
 */
void generate_nums( int nums[], int size );

/*
 * sieves through nums array, so that only
 * primes are left (composites are replaced
 * with -1)
 */
void sieve_nums( int nums[], int size );

/*
 * sums all the numbers in int array that aren't -1
 */
unsigned long long sum_nums( int nums[], int size );

#endif
