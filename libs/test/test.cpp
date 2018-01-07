/*
 * test.cpp
 *
 * for testing the bigint class
 */

#include <iostream>
#include "../bigint.h"

using namespace std;

int main()
{
        BigInt temp(161);
        BigInt temp2;
        temp2 = 150;
        BigInt temp3;
        temp3 = temp + temp2;
        BigInt temp4;
        temp4 = temp2 * 3;
        BigInt temp5;
        temp5 = temp * temp2;
        cout << "temp which is 161 is: "<< temp << "\n";
        cout << "temp2 which is 150 is: "<< temp2 << "\n";
        cout << "temp3 which is temp + temp2 is: "<<temp3<<"\n";
        cout << "temp4 which is temp2 * 3 is: "<< temp4 << "\n";
        cout << "temp5 which is temp * temp2 is: "<< temp5 << "\n";

        BigInt temp6(0);
        cout << "temp6 is: " << temp6 << "\n";
        cout << "and temp5 is: " << temp5 << "\n";
        temp6 += temp5;
        cout << "temp6 += temp5, temp6 is now: "<< temp6 << "\n";
        temp6 += temp5;
        cout << "temp6 += temp5, temp6 is now: " << temp6 << "\n";

        BigInt temp7 = temp5 * temp6;
        cout << "temp7 which is temp5 * temp6 is: " << temp7 << "\n";
        temp7++;
        cout << "temp7++ is: " << temp7 << "\n";
        ++temp7;
        cout << "++temp7 is: " << temp7 << "\n";

        BigInt temp9(2);
        temp7 = temp7 - temp9;
        cout << "temp7 - 2 is: " << temp7 << "\n";
        BigInt temp8 = temp7 - temp5;
        cout << "temp9 which is temp7 - temp5 is: " << temp8 << "\n";

        BigInt temptemp1(161);
        BigInt temptemp2(1);
        BigInt temptemp3(161);

        BigInt temptemp4 = temptemp1 - temptemp2;
        cout << "161 - 1 is: " << temptemp4 << "\n";
        BigInt temptemp5 = temptemp1 - temptemp3;
        cout << "161 - 160 is: " << temptemp5 << "\n";

        string num = "123123123123123123123";
        BigInt str_num(num);
        cout << "String num is " << num << " and BigInt strnum(num) is: ";
        cout << str_num << "\n";

        return 0;
}
