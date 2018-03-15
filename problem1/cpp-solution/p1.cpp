/*
 * p1.cpp
 *
 * Zeke Reyna
 *
 * Problem 1: Find the sum of the multiples of 3 or 5 below 1000.
 *
 * note: solves for any positive number as well as '1000'
 */
#include <iostream>
using namespace std;
using ull = unsigned long long;
const int _DEFAULT = 1000;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
        int bound;
        (argc == 2) ? (bound = atoi(argv[1])) : (bound = _DEFAULT);

	ull sum = 0;
        for (int i = 1; i < bound; i++) {
                if (i % 3 == 0 || i % 5 == 0)
                        sum += i;
        }

        cout << "\nThe sum of the multiples of 3 or 5 below " << bound;
        cout << " are: " << sum << "\n\n";
        return 0;
}
