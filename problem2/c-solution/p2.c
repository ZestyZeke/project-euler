/*
 * p2.c
 *
 * Zeke Reyna
 *
 * Problem 2:
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */

#include <stdio.h>
#include <stdlib.h>
#define		DEFAULT		4000000

int main(int argc, char **argv)
{
	int bound;

	(argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

	int first, second, third;

	return 0;
}
