/*
 * p1.cpp
 *
 * Zeke Reyna
 *
 * Problem 1: Find the sum of the multiples of 3 or 5 below 1000.
 */

#include <iostream>
#define             DEFAULT         1000
using namespace std;

int main(int argc, char **argv)
{
        unsigned long long sum = 0;
        int i;
        int bound;

        (argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

        for (i = 1; i < bound; i++) {
                if (i % 3 == 0 || i % 5 == 0)
                        sum += i;
        }

        cout << "\nThe sum of the multiples of 3 or 5 below " << bound;
        cout << " are: " << sum << "\n\n";
        return 0;
}
