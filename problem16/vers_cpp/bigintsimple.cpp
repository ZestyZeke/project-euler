/*
 * bigintsimple.cpp
 *
 * Zeke Reyna
 *
 * Uses digits in base 10, should be easier.
 */

#include "bigint.h"

// default constructor
// puts a zero
BigInt::BigInt()
{
        // should i destroy the digits representation just in case?
        digits.push_back(0);
}


// constructor
BigInt::BigInt(unsigned long long num)
{
        // should i destroy the digits rep just in case?
        char remainder;
        while (num > 0) {
                remainder = num % 10 + '0'; // need to get char vers of digit
                num /= 10;

                //digits.push_back(remainder);
                digits.insert(digits.begin(), remainder);
        }
        //reverse(digits.begin(), digits.end()); // might be a better way to do this
}

BigInt::BigInt(string num)
{
        for (auto c : num) {
                if (c < '0' || c > '9') {
                        cout<<"um you can't push that\n";
                        break;
                }
                digits.push_back(c);
        }
}

// destructor
BigInt::~BigInt()
{
        // vector destructor should be implicitly called
}

// copy constructor
BigInt::BigInt(const BigInt& num)
{
        for (auto iter = num.digits.begin(); iter != num.digits.end(); iter++)
                digits.push_back(*iter);
}

// copy assignment
BigInt& BigInt::operator=(const BigInt& rhs)
{
        if (this == &rhs)
                return *this;

        digits.clear();

        for (auto iter = rhs.digits.begin(); iter != rhs.digits.end(); iter++)
                digits.push_back(*iter);

        return *this;
}

// operator+
BigInt operator+(const BigInt& n1, const BigInt& n2)
{
        BigInt temp; // default constructor puts a zero.
        while (!temp.digits.empty()) // kind of unnecessary
                temp.digits.pop_back();

        unsigned long long carry = 0;
        char digit;
        auto iter1 = n1.digits.rbegin();
        auto iter2 = n2.digits.rbegin();
        for (; iter1 != n1.digits.rend() && iter2 != n2.digits.rend();
                                                     iter1++, iter2++) {

                carry += (unsigned long long) *iter1;
                carry += (unsigned long long) *iter2;
                digit = carry % sizeof(char);
                carry /= sizeof(char);

                temp.digits.insert(temp.digits.begin(), digit);
        }

        // now, carry can still have some, and there is the possibility one of
        // the iterators didn't reach the end.

        while (iter1 != n1.digits.rend()) {

                carry += (unsigned long long) *iter1;
                digit = carry % sizeof(char);
                carry /= sizeof(char);
                temp.digits.insert(temp.digits.begin(), digit);

                iter1++;
        }

        while (iter2 != n2.digits.rend()) {

                carry += (unsigned long long) *iter2;
                digit = carry % sizeof(char);
                carry /= sizeof(char);
                temp.digits.insert(temp.digits.begin(), digit);

                iter2++;
        }

        while (carry > 0) {

                digit = carry % sizeof(char);
                temp.digits.insert(temp.digits.begin(), digit);

                carry /= sizeof(char);
        }

        return temp;
}

// operator-
BigInt operator-(const BigInt& n1, const BigInt& n2)
{
        cout<<"this function doesnt currently work\n";
        BigInt temp;
        return temp;
}

// operator*
BigInt operator*(const BigInt& n1, const BigInt& n2)
{
        cout<<"this function doesn't work yet\n";
        BigInt temp;
        return temp;
}

// operator/
BigInt operator/(const BigInt& n1, const BigInt& n2)
{
        cout<<"this function doesn't work yet\n";
        BigInt temp;
        return temp;
}

// put-to operator
ostream& operator<<(ostream& os, const BigInt& num)
{
        string output;
        for (auto iter = num.digits.begin(); iter != num.digits.end(); iter++)
                output << *iter;

        os << output;

        return os;
}

// get-from operator
istream& operator>>(istream& is, const BigInt& num)
{
}

int operator<(const BigInt& n1, const BigInt& n2)
{
}

int operator>(const BigInt& n1, const BigInt& n2)
{
}

int operator==(const BigInt& n1, const BigInt& n2)
{
}

// operator+=
BigInt& BigInt::operator+=(const BigInt& num)
{
}

// operator-=
BigInt& BigInt::operator-=(const BigInt& num)
{
}

// operator*=
BigInt& BigInt::operator*=(const BigInt& num)
{
}

// operator/=
BigInt& BigInt::operator/=(const BigInt& num)
{
}

