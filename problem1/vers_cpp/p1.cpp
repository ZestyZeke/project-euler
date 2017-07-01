/*
 * p1.cpp
 *
 * Zeke Reyna
 *
 * This function finds the sum of all multiples of 3 and 5 below 1000
 */

#include <iostream>
#include <cstdlib>

#define BOUND 10

using namespace std;

int main( int argc, char **argv )
{
	int sum;
	int i;
	int bound;

	(argc == 2) ? (bound = atoi( argv[1] )) : (bound = BOUND);

	sum = 0;
	for( i = 0; i < bound; i++ ) {
		if( i % 3 == 0 || i % 5 == 0 )
			sum += i;
	}

	cout << "\nThe sum of all multipes of 3 and 5 below " << bound;
	cout << " is "<< sum << "\n\n";

	return 0;
}
