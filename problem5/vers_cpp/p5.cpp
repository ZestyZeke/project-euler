/*
 * p5.cpp
 *
 * Zeke Reyna
 *
 * Finds smallest int that is divisible by natural nums up to bound
 */

#include <iostream>

using namespace std;

#define BOUND 10

int main( int argc, char **argv )
{
	int i, num, bound;
	int isDivis;

	(argc == 2) ? bound = stoi(argv[1]) : bound = BOUND;

	num = 3;
	isDivis = 0;
	while( !isDivis && num++ ) {
		isDivis = 1;
		for( i = 1; i <= bound; i++ ) {
			if( num % i != 0 ) {
				isDivis = 0;
				break;
			}
		}
	}

	cout << "\nThe smallest number that is evenly divisible by all of ";
	cout << "the numbers from 1 to " << bound;
	cout << " is " << num << endl << endl;
	return 0;
}
