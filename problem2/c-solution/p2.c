/*
 * p2.c
 *
 * Zeke Reyna
 *
 * Problem 2:
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 *
 * note: solves for positive bounds other than four million that do not exceed
 * the bounds of 'int'
 */

#include <stdio.h>
#include <stdlib.h>
#define		DEFAULT		4000000

void iterate(int *first, int *second)
{
	int third = *first + *second;
	*first = *second;
	*second = third;
}

int main(int argc, char **argv)
{
	int bound;
	int first, second;
	unsigned long long sum;

	(argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

	// first two fib nums
	first  = 1;
	second = 1;
	sum    = 0;

	for (; second < bound; iterate(&first, &second)) {
		if (second % 2 == 0)
			sum += (unsigned long long) second;
	}

	printf("\nThe sum of the even-valued Fibonacci numbers under ");
	printf("the bound %d is: %llu\n\n", bound, sum);

	return 0;
}
