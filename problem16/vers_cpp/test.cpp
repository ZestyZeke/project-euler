/*
 * test.cpp
 *
 * for testing the bigint class
 */

#include <iostream>
#include "bigint.h"

using namespace std;

int main()
{
        BigInt temp(161);
        BigInt temp2;
        temp2 = 150;
        BigInt temp3;
        temp3 = temp + temp2;
        cout << "temp which is 161 is: "<< temp << "\n";
        cout << "temp2 which is 150 is: "<< temp2 << "\n";
        cout << "temp3 which is temp + temp2 is: "<<temp3<<"\n";
        return 0;
}
