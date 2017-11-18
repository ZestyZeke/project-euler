/*
 * p6.cpp
 *
 * Problem 6:
 * Find the difference between the sum of the squares of the first n
 * natural numbers and the square of the sum of the first n natural
 * numbers.
 */

#include <iostream>
#define         DEFAULT     10
#define         SQR(x)      ((x)*(x))
using namespace std;

/*
 * Polynomial expresssion for
 * sum of first n squares
 */
int sum_of_squares(int n)
{
        return n * (n + 1) * (2 * n + 1) / 6;
}

/*
 * nth triangular number is equal to sum of first n
 * natural numbers
 */
int square_of_sum(int n)
{
        int triangle;
        triangle = (SQR(n) + n) / 2;
        return SQR(triangle);
}

int difference(int n)
{
        int diff;
        diff = sum_of_squares(n) - square_of_sum(n);
        if (diff < 0)
                diff *= -1;
        return diff;
}

int main(int argc, char **argv)
{
        int n;
        int answer;
        (argc == 2) ? (n = stoi(argv[1])) : (n = DEFAULT);

        answer = difference(n);

        cout << "\nThe difference between the sum of the squares";
        cout << " and the square of the sum of the first " << n;
        cout << " natural numbers is: " << answer << "\n\n";

        return 0;
}
