/*
 * fib.cpp
 *
 * Zeke Reyna
 *
 * This is a simple function that sums fibonacci numbers
 * under a certain bound.
 */

#include <iostream>
#define BOUND 10

using namespace std;

int main( int argc, char **argv )
{
	int first, second, third;
	int sum;
	int bound;

	(argc == 2) ? bound = atoi(argv[1]) : bound = BOUND;

	first = 1;
	second = 1;
	third = 0;
	sum = 0;

	while( third < bound ) {
		if( second % 2 == 0 )
			sum += second;
		third = first + second;
		first = second;
		second = third;
	}

	cout << "\nThe sum of even valued fibonacci terms under " << bound;
	cout << " is " << sum << "\n\n";
	return 0;
}
