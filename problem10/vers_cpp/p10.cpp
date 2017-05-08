/*
 * p10.cpp
 *
 * Zeke Reyna
 *
 * Sums the prime numbers under a given bound
 */

#include <iostream>
#include <vector>

#define BOUND_DEF 10

using namespace std;

void generate_primes( vector<int>& primes, int bound )
{
        int i;
        int isPrime;

        for( i = 2; i < bound; i++ ) {

                isPrime = 1;
                for( auto iter = primes.begin();
                                iter != primes.end() && isPrime; iter++ ) {

                        if( i % *iter == 0 )
                                isPrime = 0;
                }

                if( isPrime )
                        primes.push_back( i );
        }
}

unsigned long long sum_primes( vector<int>& primes )
{
        unsigned long long sum;

        sum = 0;
        for( auto iter = primes.begin(); iter != primes.end(); iter++ ) {
                sum += *iter;
        }

        return sum;
}

int main( int argc, char **argv )
{
        int n;
        unsigned long long sum;
        vector<int> primes;

        (argc == 2) ? (n = stoi(argv[1])) : (n = BOUND_DEF);

        generate_primes( primes, n );
        sum = sum_primes( primes );

        cout<<"\nThe sum of the primes below "<<n;
        cout<<" is "<<sum<<endl<<endl;

        return 0;
}
