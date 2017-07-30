/*
 * p3.c
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143
 */

#include <stdio.h>
#include <stdlib.h>
#define		DEFAULT		13195

int main(int argc, char **argv)
{
	unsigned long long num;
	(argc == 2) ? (num = atoi(argv[1])) : (num = DEFAULT);

	return 0;
}
