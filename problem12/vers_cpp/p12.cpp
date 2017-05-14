/*
 * p12.cpp
 *
 * Zeke Reyna
 *
 * A simple file to find the first triangular number that has
 * over five hundred divisors.
 */

#include <iostream>
#include <cmath>

#define DEFAULT 5
#define TRI(x) ( ((x) * (x) + (x)) / 2 )

using namespace std;

int find_num_factors( int num )
{
        int i;
        int num_factors, power;

        num_factors = 1;
        for( i = 2; i < (int) sqrt( num ); i++ ) {
                power = 0;

                while( num % i == 0 ) {
                        num /= i;
                        power++;
                }
                num_factors *= (power + 1);
        }

        if( num > 1 )
                num_factors *= 2;

        return num_factors;
}

int main( int argc, char **argv )
{
        int i, tri;
        int divis;
        int curr_num_divis;

        (argc == 2) ? (divis = stoi(argv[1])) : (divis = DEFAULT);

        i = 1;
        for( tri = 1; (tri = TRI(i)); i++ ) {

                curr_num_divis = find_num_factors( tri );
                if( curr_num_divis > divis )
                        break;
        }

        cout<<"\nThe first triangular number that has greater than "<<divis;
        cout<<" divisors is "<<tri<<"\n\n";

        return 0;
}
