#ifndef __PLYNOMIAL_HPP
#define __PLYNOMIAL_HPP
#include "Monomial.hpp"

class Polynomial
{
    Monomial **elements;
    size_t count;
    void copy(const Polynomial &P);
    void sortElements();
    void dealloc(Monomial **arr, size_t c);
    unsigned determineSumCount(const Polynomial &P) const;

public:
    Polynomial();
    Polynomial(const Polynomial &P);
    Polynomial(const char *s);
    void fromString(const char *s);
    void read();
    Polynomial operator+(const Polynomial &P) const;
    Polynomial operator*(const Polynomial &P) const;
    int operator[](unsigned d) const;
    const Polynomial &operator=(const Polynomial &P);
    void print() const;
    ~Polynomial();
};

#endif