/*
 * p7.cpp
 *
 * Zeke Reyna
 *
 * A simple file used to find the nth prime number.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main( int argc, char **argv )
{
	// idea is to setup vector of ints and iterate through it
	// for every value from i = 1 to i = bound.
	// if vector[j] % i == 0 then, swap vector[j]
	// and vector[end], and then do popEnd() or something
	// of the sort. Next, need to check if this swapped value
	// is divisible by i. because this could loop for while, need a while
	// loop. so enter while( vector[j] % i == 0 ). so above 'if' scenario
	// should actually be a while that repeats itself. Unfortunately
	// this will desort the vector, but at the end can just call sort.
	return 0;
}
