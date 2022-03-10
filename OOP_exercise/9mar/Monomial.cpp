#include "Monomial.hpp"

Monomial::Monomial()
{
    degree = 0;
    coefficient = 0;
    std::cout << "<Monomial created successfully.>\n";
}

Monomial::Monomial(int _c, unsigned _d)
{
    degree = _d;
    coefficient = _c;
    std::cout << "<Monomial created successfully.>\n";
}

void Monomial::read()
{
    std::cout << "coefficient: ";
    std::cin >> coefficient;
    std::cout << "degree: ";
    std::cin >> degree;
}

Monomial Monomial::operator+(const Monomial &M) const
{
    assert(degree == M.degree);
    return Monomial(coefficient + M.coefficient, degree);
}

void Monomial::print() const
{
    if (!coefficient)
        std::cout << '0';
    else
    {
        if (coefficient < 0)
            std::cout << "- ";
        std::cout << (coefficient < 0 ? -coefficient : coefficient);
        if (degree)
            std::cout << "x^" << degree;
    }
}

Monomial::Monomial(const char *exprBegin, const char *exprEnd, bool negative)
{
    const char *iter = exprBegin;
    while (iter < exprEnd && *iter != 'x')
        ++iter;
    if (iter == exprEnd)
    {
        std::cout << "<Could not create Monomial from string.>\n";
        coefficient = 0;
        degree = 0;
        return;
    }
    coefficient = 0;
    for (const char *i = iter - 1; i >= exprBegin; --i)
    {
        coefficient *= 10;
        coefficient += *i - '0';
    }
    if (negative)
        coefficient = -coefficient;
    if (!*iter)
    {
        degree = 0;
        std::cout << "<Monomial created successfully.>\n";
    }
    else
    {
        iter += 2;
        degree = 0;
        const char *dIter = iter;
        while (*dIter >= '0' && *dIter <= '9')
            ++dIter;
        --dIter;
        while (dIter >= iter)
        {
            degree *= 10;
            degree += *iter - '0';
            --dIter;
        }
    }
    std::cout << "<Monomial created successfully.>\n";
}
