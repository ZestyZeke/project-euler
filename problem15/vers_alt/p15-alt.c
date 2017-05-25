/*
 * p15-alt.c
 *
 * Zeke Reyna
 *
 * Problem is a combinatorics one. For an nxn grid, paths are given by
 * (2n choose n).
 *
 * Can solve through theorem: (n k) = (n k-1) * (n + 1 - k) / k
 *
 * This is only for even sized grids, is slightly different for odd.
 */

#include <stdio.h>
#include <stdlib.h>
#define		DEFAULT		2

typedef unsigned long long ull;

ull find_num_paths(ull n)
{
	ull retval, k;

	retval = 1;
	for (k = 1; k <= n; k++)
		retval = retval * ( (2*n) + 1 - k) / k;

	return retval;
}

int main(int argc, char **argv)
{

	ull n, num_paths;

	(argc == 2) ? (n = (ull)(atoi(argv[1]))) : (n = DEFAULT);

	num_paths = find_num_paths(n);

	printf("\nThe numer of paths for the %llux%llu grid is ", n, n);
	printf("%llu\n\n", num_paths);
	return 0;
}
