/*
 * p13-bigint.cpp
 *
 * Zeke Reyna
 *
 * Sums 100 50-digit numbers.
 */

#include <iostream>
#include <fstream>
#include "bigint.h"
using namespace std;

int main()
{

        ifstream num_file("../num-alt.txt");
        if (!num_file) {
                cout << "file could not be opened\n";
                return -1;
        }

        BigInt sum_of_nums(0);
        string num_line;
        while (getline(num_file, num_line)) {

                BigInt temp(num_line);
                sum_of_nums += temp;
        }

        cout<<"\nThe sum of all those numbers is:\n"<<sum_of_nums<<"\n\n";
        return 0;
}
