/*
 * p4.cpp
 *
 * Zeke Reyna
 *
 * Problem 4:
 * Find the largest palindrome made from the product of
 * two 3-digit numbers.
 */

#include <iostream>
#define         TEST            2
#define         DEFAULT         3
using namespace std;

void set_bounds(int& lower, int& upper, const int digits)
{
        int i;
        lower = 1;
        upper = 1;
        for (i = 1; i < digits; i++)
                lower *= 10;
        for (i = 0; i < digits; i++)
                upper *= 10;
}

int check_if_prod_is_pal(const int first_term, const int second_term)
{
        int product, flipped, temp;
        product = first_term * second_term;
        flipped = 0;
        temp = product;

        while (temp > 0) {
                flipped *= 10;
                flipped += temp % 10;
                temp /= 10;
        }

        if (product != flipped)
                product = 0;
        return product;
}

int find_largest_pal(const int lower, const int upper)
{
        int i, j;
        int cur_pal;
        int largest_pal = 0;
        for (i = lower; i < upper; i++) {
                for (j = i; j < upper; j++) {
                        cur_pal = check_if_prod_is_pal(i, j);
                        if (cur_pal > largest_pal)
                                largest_pal = cur_pal;
                }
        }
        return largest_pal;
}

int main(int argc, char **argv)
{
        int largest_pal = 0;
        int num_digits;
        (argc == 2) ? (num_digits = stoi(argv[1])) : (num_digits = DEFAULT);

        int lower_bound, upper_bound;
        set_bounds(lower_bound, upper_bound, num_digits);

        largest_pal = find_largest_pal(lower_bound, upper_bound);

        cout<<"\nThe largest palindrome that is made from the product of";
        cout<<" two "<<num_digits<<"-digit numbers is: "<<largest_pal<<"\n\n";
        return 0;
}
