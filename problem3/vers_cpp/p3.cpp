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

using namespace std;

#define NUM 99

int main( int argc, char **argv )
{
        unsigned long long i;
        unsigned long long largest_prime;
        unsigned long long num;
        unsigned long long bound;
        vector<unsigned long long> prime_factors;
        vector<unsigned long long>::iterator it;
        int isPrime;

        (argc == 2) ? (num = stoull( argv[1] )) : (num = NUM);

        bound = num / 2;

        for( i = 2; i < bound; i++ ) {

                if( num % i != 0 )
                        continue;

                isPrime = 1;
                for( it = prime_factors.begin(); it != prime_factors.end(); ++it ) {
                        if( i % *it == 0 )
                                isPrime = 0;
                }

                if( isPrime )
                        prime_factors.push_back( i );
        }

        largest_prime = 1;
        if( !prime_factors.empty() )
                largest_prime = prime_factors.back();

        cout << "\nThe largest prime factor of " << num;
        cout << " is " << largest_prime << endl << endl;

        return 0;
}
