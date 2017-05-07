/*
 * p6.cpp
 *
 * Zeke Reyna
 *
 * Find the difference between the sum of the squares of the first n natural
 * numbers and the square of the sum of the first n natural numbers.
 */

#include <iostream>

#define BOUND 10

using namespace std;

int sqr( int n )
{
        return n * n;
}

int triangle( int n )
{
        return ( sqr(n) + n ) / 2;
}

int sum_of_squares( int n )
{
        return n * (n + 1) * (2 * n + 1) / 6;
}

int main( int argc, char **argv )
{
        /*
         * sum of first n natural numbers is the triangular number
         *
         * sum of squares of n natural numbers is
         * n(n+1)(2n+1)
         */

        int bound, answer;
        (argc == 2) ? (bound = stoi( argv[1] )) : (bound = BOUND);

        answer = sum_of_squares( bound ) - sqr( triangle( bound ) );

        if( answer < 0 )
                answer = -1 * answer;

        cout << "\nThe difference between the Sum of the Squares and the";
        cout << " square of the sum of the first " << bound << " natural";
        cout << " numbers is " << answer << endl << endl;
        return 0;
}
