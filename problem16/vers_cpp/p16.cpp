/*
 * p16.cpp
 *
 * Zeke Reyna
 *
 * Power Digit Sum: What is the sum of the digits
 * of the number 2^(1000)?
 *
 * For example, 2^15 = 32768
 * and the sum of its digits is 26.
 */

#include <iostream>
#include <string>
#include "bigint.h"
#define     LIMIT       15

using namespace std;

int main(int argc, char **argv)
{
        int limit;
        (argc == 2) ? (limit = stoi(argv[1])) : (limit = LIMIT);

        BigInt num = 2;
        int i = 0;

        while (++i < limit)
                num *= 2;

        unsigned long long sum = 0;
        sum = num.sum_digits();

        cout << "\nThe sum of the digits of 2^"<<limit<<" is: "<< sum << "\n\n";
        return 0;
}
