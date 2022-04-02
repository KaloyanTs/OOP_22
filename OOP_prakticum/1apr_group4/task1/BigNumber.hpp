#ifndef __BIGNuMBER_HPP
#define __BIGNuMBER_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const size_t INPUT_MAX = 32;

class BigNumber
{
    bool negative;
    char *num;
    void copy(const BigNumber &other);
    bool isNumber(const char *str) const;
    size_t sumLength(const BigNumber &other) const;
    BigNumber simpleMultiply(unsigned n) const;
    BigNumber mulPower10(unsigned power) const;

public:
    BigNumber(const char *number = "0");
    BigNumber(long long int number);
    BigNumber(const BigNumber &other);
    BigNumber &operator=(const BigNumber &other);
    bool operator==(const BigNumber &other) const;
    bool operator!=(const BigNumber &other) const;
    bool operator<(const BigNumber &other) const;
    bool operator>(const BigNumber &other) const;
    bool operator>=(const BigNumber &other) const;
    bool operator<=(const BigNumber &other) const;

    BigNumber &operator+=(const BigNumber &other);
    BigNumber operator+(const BigNumber &other) const;
    BigNumber &operator-=(const BigNumber &other);
    BigNumber operator-(const BigNumber &other) const;
    BigNumber operator-() const;
    BigNumber &operator*=(const BigNumber &other);
    BigNumber operator*(const BigNumber &other) const;

    // Optional
    BigNumber &operator/=(const BigNumber &other);
    BigNumber operator/(const BigNumber &other) const;
    BigNumber &operator%=(const BigNumber &other);
    BigNumber operator%(const BigNumber &other) const;
    friend std::ostream &operator<<(std::ostream &os, const BigNumber &N);
    friend std::istream &operator>>(std::istream &is, BigNumber &N);
    ~BigNumber() { delete[] num; }
};

#endif