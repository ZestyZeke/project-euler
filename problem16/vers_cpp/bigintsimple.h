/*
 * bigintsimple.h
 *
 * Zeke Reyna
 *
 * Cpp vector implementation of a BigInteger class of arbitrary size. This vers.
 * uses a digit representation in String form.
 *
 */

#ifndef __BIGINTSIMPLE_H__
#define __BIGINTSIMPLE_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt {

        public:

                // default constructor
                BigInt();

                // constructor
                BigInt(const unsigned long long num);

                // constructor
                BigInt(string num);

                // destructor
                ~BigInt();

                // copy constructor
                BigInt(const BigInt& num);

                // copy assignment
                BigInt& operator=(const BigInt& num);

                friend BigInt operator+(const BigInt& n1, const BigInt& n2);
                friend BigInt operator-(const BigInt& n1, const BigInt& n2);
                friend BigInt operator*(const BigInt& n1, const BigInt& n2);
                friend BigInt operator/(const BigInt& n1, const BigInt& n2);

                /*
                 * for all operators where something else can be on the left-
                 * hand side, it needs to be a friend. Like "cout<<BigInt".
                 * Later can do 'moving && operators and stuff, but for now
                 * just do 'copying'
                 */

                // put to operator
                friend ostream& operator<<(ostream& os, const BigInt& num);

                // get from operator
                friend istream& operator>>(istream& is, BigInt& num);

                // relational operators
                friend int operator<(const BigInt& n1, const BigInt& n2);
                friend int operator>(const BigInt& n1, const BigInt& n2);
                friend int operator==(const BigInt& n1, const BigInt& n2);
                friend int operator!=(const BigInt& n1, const BigInt& n2)
                {
                        return !(n1 == n2);
                }
                friend int operator<=(const BigInt& n1, const BigInt& n2)
                {
                        return !(n1 > n2);
                }
                friend int operator>=(const BigInt& n1, const BigInt& n2)
                {
                        return !(n1 < n2);
                }

                /*
                 * need + and +=, / and /=, * and *=, - and -= operator.
                 * can do Jae thing where they call each other, + calls +=
                 * etc.
                 */

                BigInt& operator+=(const BigInt& num);
                BigInt& operator-=(const BigInt& num);
                BigInt& operator*=(const BigInt& num);
                BigInt& operator/=(const BigInt& num);

        private:
                // our structure holding the digits of our BigInt
                vector<char> digits;
};

// if the friend thing is not in place, can have + and other stuff here.
//BigInt operator+(const BigInt& n1, const BigInt& n2);
//BigInt operator-(const BigInt& n1, const BigInt& n2);
//BigInt operator*(const BigInt& n1, const BigInt& n2);
//BigInt operator/(const BigInt& n1, const BigInt& n2);

#endif
