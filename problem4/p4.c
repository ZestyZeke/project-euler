/*
 * p4.c
 *
 * Zeke Reyna
 *
 * A simple C file to find the largest palindrome
 * That's a product of two 3 digit numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100 // assuming the string rep of the # is smaller than 100
#define LOWERBOUND 100
#define UPPERBOUND 1000

int check_if_pal(int i, int j)
{
	int z;
	int retval = -1;
	int product = i * j;
	char str[SIZE], front[SIZE], end[SIZE];
	int half_length;

	sprintf(str, "%d", product);
	half_length = strlen(str) / 2;

	if (strlen(str) % 2 == 0) {
		strncpy(front, str, half_length);
		strncpy(end, str + half_length, half_length);

	} else {
		strncpy(front, str, half_length);
		strncpy(end, str + half_length + 1, half_length);
	}
	end[half_length] = '\0';

	retval = i * j;
	for (z = 0; z < half_length; z++) {
		if (front[z] != end[half_length - 1 - z])
			retval = -1;
	}

	return retval;
}

int main( int argc, char **argv )
{
	int i, j;
	int cur_pal;
	int largest_pal = 0;
	int lowerbound, upperbound;

	if (argc == 3) {
		upperbound = atoi(argv[2]);
		lowerbound = atoi(argv[1]);
	} else {
		upperbound = UPPERBOUND;
		lowerbound = LOWERBOUND;
	}

	for (i = lowerbound; i < upperbound; i++) {
		for (j = i; j < upperbound; j++) {

			cur_pal = check_if_pal(i, j);
			if (cur_pal > largest_pal)
				largest_pal = cur_pal;
		}
	}

	printf( "\nThe largest palindrome " );
	printf( "that is a sum of two products between " );
	printf( "the bounds %d and %d is: ", lowerbound, upperbound );
	printf( "%d\n\n", largest_pal );

	return 0;
}
