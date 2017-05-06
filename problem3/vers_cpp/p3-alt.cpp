/*
 * p3-alt.cpp
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

/*
 * try instead to do it recursion wise. Gather from the first number
 * that divides the 'num' the other factor. Then pass these two numbers
 * to this same function in recursion, until they're prime. do it with a
 * list that can be edited in recursions. maybe make a list and add it to
 * the vector? so a vector of 2-vectors?
 */

/*
 * recursive function, given a number find two factors for it,
 * and return them as a vector<int>. Should be recursively called,
 * check if either of two factors is n. If one is, then don't
 * recursively call self because that means factor is prime
 * and doesn't need to be reduced furhter.
 */
// may have problems with values that are larger than int
vector<int> find_factors( int n )
{
        int i;
        int first_factor, second_factor;
        vector<int> retlist;

        first_factor = -1;
        second_factor = -1;
        for( i = 2; i < n; i++ ) {
                if( n % i == 0 ) {
                        first_factor = i;
                        second_factor = n / i;
                        break;
                }
        }

        retlist.push_back( first_factor );
        retlist.push_back( second_factor );

        if( first_factor < 0 )
                return retlist;
        else {
        }
}

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
