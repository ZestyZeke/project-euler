/*
 * p9.cpp
 *
 * Zeke Reyna
 *
 * There exists one pythagorean triplet such that a + b + c = sum.
 * Find the product a*b*c.
 *
 * For reference: 3^2 + 4^2 = 5^2
 */

#include <iostream>
#include <cmath>

#define SUM_DEF 12
#define SUM(a,b,c) ((a)+(b)+(c))
#define SQR(x) ((x)*(x))

using namespace std;

int find_c( int a, int b )
{
        int c;

        c = (int) sqrt( SQR(a) + SQR(b) );
        if( SQR(c) != SQR(a) + SQR(b) )
                c = -1; // there is no integral c for a and b

        return c;
}

int main( int argc, char **argv )
{
        int sum;
        int i, j, c;
        int product;

        (argc == 2) ? (sum = stoi(argv[1])) : (sum = SUM_DEF);

        product = -1;
        for( i = 1; i < sum; i++ ) {
                for( j = 1; j < sum; j++ ) {

                        c = find_c( i, j );
                        if( c != -1 && SUM(i, j, c) == sum ) {
                                product = i * j * c;
                                goto found;
                        }
                }
        }
found:
        cout<<"\nThe product of the pythagorean triplets that sum to ";
        cout<<sum<<" is "<<product<<endl<<endl;

}
