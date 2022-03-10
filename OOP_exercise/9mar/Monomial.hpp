#ifndef __MONOMIAL_HPP
#define __MONOMIAL_HPP
#include <iostream>
#include <cassert>

class Monomial
{
    unsigned degree;
    int coefficient;

public:
    Monomial();
    Monomial(int _c, unsigned _d);
    Monomial(const char *exprBegin, const char *exprEnd, bool negative);
    void read();
    unsigned getDegree() const { return degree; }
    int getCoefficient() const { return coefficient; }
    Monomial operator+(const Monomial &M) const;
    void print() const;
};

#endif