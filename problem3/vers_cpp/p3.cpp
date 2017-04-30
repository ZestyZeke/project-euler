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

using namespace std;

#define NUM 99

int main( int argc, char **argv )
{
        long i, j;
        long largest_prime;
        unsigned long long num;
        long bound;

        (argc == 2) ? (num = stoull( argv[1] )) : (num = NUM);

        // 1 bound for large nums one for small
        bound = (long) sqrt( num );
        //bound = num/2;
        long prime_factors[ bound ];

        largest_prime = 1;
        prime_factors[0] = 1;
        prime_factors[1] = -1; // null terminated

        for( i = 2; i < bound; i++ ) {

                if( num % i == 0 ) {

                        for( j = 1; i % prime_factors[j] != 0; j++ )
                                ;

                        if( prime_factors[j] == -1 ) {
                                prime_factors[j] = i;
                                prime_factors[++j] = -1;
                        }
                }
        }

        for( i = 0; prime_factors[i] != -1; i++ )
                ;

        largest_prime = prime_factors[--i];

        cout << "\nThe largest prime factor of " << num;
        cout << " is " << largest_prime << endl << endl;

        return 0;
}
