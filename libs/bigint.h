/*
 * bigint.h
 *
 * Zeke Reyna
 *
 * Cpp vector implementation of a BigInteger class of arbitrary size.
 *
 * So far, negative numbers don't work. And only + and * operators actually
 * work.
 *
 * In future, could add a 'sign' struct that would keep track of if a number is
 * positive or negative.
 *
 * Idea is to hold two digits of an ordinary base 10 number in each char.
 * 0-99
 *
 * Operate in base 100 basically, each char is a digit.
 */

#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <iostream>
#include <vector>
#include <algorithm>

#define     BASE_SIZE       100
#define     DIGIT_SIZE      10

using namespace std;

class BigInt {

        public:

                // default constructor
                BigInt();

                // constructor
                BigInt(const unsigned long long num);

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

                // increment, decrement
                BigInt& operator++();   // ++num
                BigInt operator++(int); // num++, int is a dummy variable
                //BigInt& operator--();   // --num
                //BigInt operator--(int); // num--

        private:
                // our structure holding the digits of our BigInt
                // going to change, so that each char holds 0-99
                vector<char> digits;
};

// if the friend thing is not in place, can have + and other stuff here.
//BigInt operator+(const BigInt& n1, const BigInt& n2);
//BigInt operator-(const BigInt& n1, const BigInt& n2);
//BigInt operator*(const BigInt& n1, const BigInt& n2);
//BigInt operator/(const BigInt& n1, const BigInt& n2);

#endif
