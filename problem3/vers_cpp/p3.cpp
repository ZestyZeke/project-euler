/*
 * p3.cpp
 *
 * Zeke Reyna
 *
 * A simple function that finds the largest prime factor of a number.
 */

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#define NUM 99

using namespace std;

typedef unsigned long long ull;

int main( int argc, char **argv )
{
        ull i;
        ull largest_prime;
        ull num;
        ull bound;
        vector<ull> prime_factors;
        int isPrime;

        (argc == 2) ? (num = stoull(argv[1])) : (num = NUM);

        //bound = num / 2;
        bound = (int) sqrt(num);

        for (i = 2; i < bound; i++) {

                if (num % i != 0)
                        continue;

                isPrime = 1;
                for (auto it = prime_factors.begin(); it != prime_factors.end();
                                                                        ++it ) {
                        if (i % *it == 0)
                                isPrime = 0;
                }

                if (isPrime)
                        prime_factors.push_back(i);
        }

        largest_prime = 1;
        if(!prime_factors.empty())
                largest_prime = prime_factors.back();

        cout << "\nThe largest prime factor of " << num;
        cout << " is " << largest_prime << "\n\n";

        return 0;
}
