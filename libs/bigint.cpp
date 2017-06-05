/*
 * bigint.cpp
 *
 * Zeke Reyna
 *
 * So far, negative numbers don't work. And only + and * operators actually
 * work.
 *
 * Idea, is to hold 2 digits in each char.
 *
 * Problems: for some reason, 0 is not printing, but everything else seems to
 * print fine.
 *
 * FUTURE IDEA: implement a deque, because of all the operations done at the
 * front or back of our vector.
 */

#include "bigint.h"

using namespace std;

BigInt::BigInt()
{
        // make sure it is empty... might be unecessary
        //while (!digits.empty())
        //       digits.pop_back();
        if (!digits.empty())
                digits.clear();

        // it might be best to do nothing, that way we get undefined behavior
        // because it really shouldn't be instantiated this way.
        //digits.push_back(0);
}


BigInt::BigInt(unsigned long long num)
{
        // make sure it is empty... might be unecessary
        if (!digits.empty())
                digits.clear();

        if (num == 0) // special case, need to make less lazy
                digits.push_back(0);

        char remainder;
        while (num > 0) {
                remainder = num % BASE_SIZE;
                num /= BASE_SIZE;

                digits.insert(digits.begin(), remainder);
                //digits.push_back(remainder);
        }
        //reverse(digits.begin(), digits.end());
}

BigInt::~BigInt()
{
        // vector destructor should be implicitly called
        //if (!digits.empty())
        //        digits.clear();
}

BigInt::BigInt(const BigInt& num)
{
        for (auto iter = num.digits.begin(); iter != num.digits.end(); ++iter)
                digits.push_back(*iter);
}

BigInt& BigInt::operator=(const BigInt& rhs)
{
        if (this == &rhs)
                return *this;

        if (!digits.empty())
                digits.clear();

        for (auto iter = rhs.digits.begin(); iter != rhs.digits.end(); ++iter)
                digits.push_back(*iter);

        return *this;
}

BigInt operator+(const BigInt& n1, const BigInt& n2)
{
        BigInt temp;
        if (!temp.digits.empty())
                temp.digits.clear();

        unsigned long long carry = 0;
        char digit = 0;
        auto iter1 = n1.digits.rbegin();
        auto iter2 = n2.digits.rbegin();
        for (; iter1 != n1.digits.rend() && iter2 != n2.digits.rend();
                                                     ++iter1, ++iter2) {

                carry += (unsigned long long) *iter1;
                carry += (unsigned long long) *iter2;
                digit  = carry % BASE_SIZE;
                carry /= BASE_SIZE;

                temp.digits.insert(temp.digits.begin(), digit);
        }

        // now, carry can still have some, and there is the possibility one of
        // the iterators didn't reach the end.

        while (iter1 != n1.digits.rend()) {

                carry += (unsigned long long) *iter1;
                digit = carry % BASE_SIZE;
                carry /= BASE_SIZE;
                temp.digits.insert(temp.digits.begin(), digit);

                ++iter1;
        }

        while (iter2 != n2.digits.rend()) {

                carry += (unsigned long long) *iter2;
                digit = carry % BASE_SIZE;
                carry /= BASE_SIZE;
                temp.digits.insert(temp.digits.begin(), digit);

                ++iter2;
        }

        while (carry > 0) {

                digit = carry % BASE_SIZE;
                temp.digits.insert(temp.digits.begin(), digit);

                carry /= BASE_SIZE;
        }

        return temp;
}

BigInt operator-(const BigInt& num, const BigInt& n2)
{
        BigInt retval;
        BigInt n1(num); // bc sub algo requires modifying the dividend

        if (n1 < n2) {
                cout << "please, subtract doesn't return negative numbers\n";
                cout << "n1 is "<< n1 << " n2 is "<< n2 << "\n";
                BigInt temp(0);
                return temp;
        }

        // need to do subtraction algorithm.
        auto iter1 = n1.digits.rbegin();
        auto iter2 = n2.digits.rbegin();

        for (; iter1 != n1.digits.rend() && iter2 != n2.digits.rend();
                                                    ++iter1, ++iter2) {

                if (*iter1 >= *iter2)
                        retval.digits.insert(retval.digits.begin(), *iter1 - *iter2);
                else {

                        auto iter_temp = iter1;

                        while (*iter_temp == 0)
                                ++iter_temp;

                        // 'borrow'
                        --*iter_temp;

                        --iter_temp;
                        while (iter_temp != iter1) {
                                *iter_temp = BASE_SIZE - 1;
                                --iter_temp;
                        }

                        char digit = (BASE_SIZE - *iter2) + *iter1;
                        retval.digits.insert(retval.digits.begin(), digit);
                }
        }

        while (iter1 != n1.digits.rend()) {
                retval.digits.insert(retval.digits.begin(), *iter1);
                ++iter1;
        }

        // clean up leading 0's
        auto iter_temp = retval.digits.begin();
        while (iter_temp != retval.digits.end() && *iter_temp == 0) {

                retval.digits.erase(iter_temp);
                iter_temp = retval.digits.begin();
        }

        // lazy coding, result of cleaning up leading 0's means that a result
        // of 0 will just be empty
        if (retval.digits.empty())
                retval.digits.push_back(0);

        return retval;
}

BigInt operator*(const BigInt& n1, const BigInt& n2)
{
        BigInt product;
        BigInt iter;

        product = n1;
        for (iter = BigInt(1); iter < n2; ++iter)
                product += n1;

        return product;
}

BigInt operator/(const BigInt& n1, const BigInt& n2)
{
        cout<<"this function doesn't work yet\n";
        BigInt temp;
        return temp;
}

ostream& operator<<(ostream& os, const BigInt& num)
{
        //string output;
        for (auto iter = num.digits.begin(); iter != num.digits.end(); ++iter) {

                // replace with variable or BASE_SIZE;
                if (*iter < DIGIT_SIZE) {
                        if (iter != num.digits.begin())
                                os << (int) 0 /*'0'*/;
                        os << (int) (*iter /*+ '0'*/);

                } else { // 10 <= *iter < 100
                        char first_digit, second_digit;
                        first_digit  = *iter / DIGIT_SIZE;
                        second_digit = *iter % DIGIT_SIZE;

                        os << (int) (first_digit  /*+ '0'*/);
                        os << (int) (second_digit /*+ '0'*/);
                }
        }

        return os;
}

istream& operator>>(istream& is, const BigInt& num)
{
        cout<<"operator>> is not implemented yet\n";
        return is;
}

int operator<(const BigInt& n1, const BigInt& n2)
{
        if (n1.digits.size() > n2.digits.size())
                return 0;
        if (n1.digits.size() < n2.digits.size())
                return 1;

        // else n1.digits.size() == n2.digits.size()
        auto iter1 = n1.digits.begin();
        auto iter2 = n2.digits.begin();

        for (; iter1 != n1.digits.end() && iter2 != n2.digits.end();
                                                 ++iter1, ++iter2) {
                if (*iter1 > *iter2)
                        return 0;
                if (*iter1 < *iter2)
                        return 1;
        }

        return 0; // for if n1 == n2
}

int operator>(const BigInt& n1, const BigInt& n2)
{
        if (n1.digits.size() > n2.digits.size())
                return 1;
        if (n1.digits.size() < n2.digits.size())
                return 0;

        // else n1.digits.size() == n2.digits.size()
        auto iter1 = n1.digits.begin();
        auto iter2 = n2.digits.begin();

        for (; iter1 != n1.digits.end() && iter2 != n2.digits.end();
                                                    ++iter1, ++iter2) {
                if (*iter1 > *iter2)
                        return 1;
                if (*iter1 < *iter2)
                        return 0;
        }

        return 0; // for if n1 == n2
}

int operator==(const BigInt& n1, const BigInt& n2)
{
        if (n1.digits.size() != n2.digits.size())
                return 0;

        auto iter1 = n1.digits.begin();
        auto iter2 = n2.digits.begin();

        for (; iter1 != n1.digits.end() && iter2 != n2.digits.end();
                                                    ++iter1, ++iter2) {
                if (*iter1 != *iter2)
                        return 0;
        }

        return 1; // for if n1 == n2
}

BigInt& BigInt::operator+=(const BigInt& num)
{
        unsigned long long carry = 0;
        char digit = 0;
        auto iter_this = digits.rbegin();
        auto iter_num = num.digits.rbegin();
        for (; iter_this != digits.rend() && iter_num != num.digits.rend();
                                                ++iter_this, ++iter_num) {

                carry += (unsigned long long) *iter_this;
                carry += (unsigned long long) *iter_num;
                digit  = carry % BASE_SIZE;
                carry /= BASE_SIZE;

                *iter_this = digit;
        }

        // now, carry can still have some, nd there is the possibility one of
        // the iterators didn't reach its end.

        while (iter_this != digits.rend() && carry != 0) {

                carry += (unsigned long long) *iter_this;
                digit  = carry % BASE_SIZE;
                carry /= BASE_SIZE;
                *iter_this = digit;

                ++iter_this;
        }

        while (iter_num != num.digits.rend()) {

                carry += (unsigned long long) *iter_num;
                digit  = carry % BASE_SIZE;
                carry /= BASE_SIZE;
                digits.insert(digits.begin(), digit);

                ++iter_num;
        }

        while (carry > 0) {

                digit = carry % BASE_SIZE;
                digits.insert(digits.begin(), digit);

                carry /= BASE_SIZE;
        }
        return *this;
}

BigInt& BigInt::operator-=(const BigInt& num)
{
        // too lazy to implement this properly atm, going to use other operators
        *this = *this - num;
        return *this;
}

BigInt& BigInt::operator*=(const BigInt& num)
{
        BigInt temp(*this);
        BigInt iter;

        for (iter = BigInt(1); iter < num; ++iter)
                *this += temp;

        return *this;
}

BigInt& BigInt::operator/=(const BigInt& num)
{
        cout << "this function is not implemented yet\n";
        return *this;
}

BigInt& BigInt::operator++()
{
        *this += 1;
        return *this;
}

BigInt BigInt::operator++(int)
{
        BigInt retval(*this);
        ++(*this);
        return retval;
}

BigInt& BigInt::operator--()
{
        *this += 1;
        return *this;
}

BigInt BigInt::operator--(int)
{
        BigInt retval(*this);
        ++(*this);
        return retval;
}

unsigned long long BigInt::sum_digits()
{
        unsigned long long sum = 0;

        for (auto iter = digits.begin(); iter != digits.end(); ++iter) {

                sum += (*iter / 10) % BASE_SIZE; // hard coding 10 no bueno
                sum += *iter % (BASE_SIZE / 10); // hard coding 10 no bueno
        }

        return sum;
}
