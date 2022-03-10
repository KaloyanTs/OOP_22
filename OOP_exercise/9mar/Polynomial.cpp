#include "Polynomial.hpp"

Polynomial::Polynomial()
{
    elements = nullptr;
    count = 0;
    std::cout << "<Polynomial created successfully.>\n";
}

Polynomial::Polynomial(const Polynomial &P)
{
    elements = nullptr;
    copy(P);
    std::cout << "<Polynomial created successfully.>\n";
}

void Polynomial::read()
{
    std::cout << "Enter count of addends: ";
    unsigned newCount;
    std::cin >> newCount;
    Monomial **newEl = new Monomial *[newCount];
    if (!newEl)
    {
        std::cout << "<Failed to read Polynomial.>\n";
        return;
    }
    for (unsigned i = 0; i < newCount; ++i)
    {
        newEl[i] = new (std::nothrow) Monomial;
        if (!newEl[i])
        {
            dealloc(newEl, i);
            std::cout << "<Failed to read Polynomial.>\n";
            return;
        }
        std::cout << '#' << i + 1 << ":\n";
        newEl[i]->read();
    }
    if (elements)
        dealloc(elements, count);
    count = newCount;
    elements = newEl;
    std::cout << "<Polynomial read successfully.>\n";
    sortElements();
}

Polynomial Polynomial::operator+(const Polynomial &P) const
{
    Polynomial res;
    res.count = determineSumCount(P);
    res.elements = new (std::nothrow) Monomial *[res.count];
    if (!res.elements)
    {
        std::cout << "<Failed to sum Polynomial.>\n";
        return Polynomial();
    }
    unsigned thisCount = 0, PCount = 0;
    unsigned currDegree;
    int currCoeff;
    for (unsigned i = 0; i < res.count; ++i)
    {
        if (elements[thisCount]->getDegree() == P.elements[PCount]->getDegree())
        {
            res.elements[i] = new (std::nothrow) Monomial(elements[thisCount]->getDegree(),
                                                          elements[thisCount]->getCoefficient() + P.elements[PCount]->getCoefficient());
            ++thisCount;
            ++PCount;
        }
        else if (elements[thisCount]->getDegree() > P.elements[PCount]->getDegree())
        {
            res.elements[i] = new (std::nothrow) Monomial(*elements[thisCount]);
            ++thisCount;
        }
        else
        {
            res.elements[i] = new (std::nothrow) Monomial(*P.elements[P.count]);
            ++PCount;
        }
        if (!res.elements[i])
        {
            res.dealloc(res.elements, i);
            std::cout << "<Summing Polynomial failed.>\n";
            return Polynomial();
        }
    }
    std::cout << "<Polynomial summed successfully.>\n";
    return res;
}

Polynomial Polynomial::operator*(const Polynomial &P) const
{
    return Polynomial();
}

const Polynomial &Polynomial::operator=(const Polynomial &P)
{
    copy(P);
    std::cout << "<Equalization done successfully.>\n";
    return *this;
}

void Polynomial::print() const
{
    for (unsigned i = 0; i < count; ++i)
    {
        if (i && elements[i]->getCoefficient() >= 0)
            std::cout << " + ";
        else if (i)
            std::cout << ' ';
        elements[i]->print();
    }
    std::cout << '\n';
}

Polynomial::~Polynomial()
{
    dealloc(elements, count);
    std::cout << "<Polynomial deleted successfully.>\n";
}

unsigned Polynomial::determineSumCount(const Polynomial &P) const
{
    unsigned res = count + P.count;
    for (unsigned i = 0; i < count; ++i)
    {
        unsigned j = 0;
        while (j < P.count && elements[i]->getDegree() != P.elements[i]->getDegree())
            ++j;
        if (j < P.count)
            --res;
    }
    return res;
}

void Polynomial::dealloc(Monomial **arr, size_t c)
{
    for (unsigned i = 0; i < c; ++i)
        delete arr[i];
    delete[] arr;
}

int Polynomial::operator[](unsigned d) const
{
    assert(d <= elements[0]->getDegree());
    unsigned i = 0;
    while (i < count && elements[i]->getDegree() != d)
        ++i;
    return (i < count ? elements[i]->getDegree() : 0);
}

void Polynomial::copy(const Polynomial &P)
{
    Monomial **newEl = new Monomial *[P.count];
    if (!newEl)
    {
        std::cout << "<Failed to copy Polynomial.>\n";
        return;
    }
    for (unsigned i = 0; i < P.count; ++i)
    {
        newEl[i] = new (std::nothrow) Monomial(*P.elements[i]);
        if (!newEl[i])
        {
            dealloc(newEl, i);
            std::cout << "<Failed to copy Polynomial.>\n";
            return;
        }
    }
    if (elements)
        dealloc(elements, count);
    count = P.count;
    elements = newEl;
    std::cout << "<Polynomial copied successfully.>\n";
}

void Polynomial::fromString(const char *s)
{
    if (elements)
        dealloc(elements, count);
    count = 0;
    for (const char *i = s; *i; ++i)
        count += (*i == '+' || *i == '-');
    ++count;
    elements = new Monomial *[count];
    if (!elements)
    {
        count = 0;
        std::cout << "<Failed to read Polynomial.>\n";
        return;
    }
    const char *sEnd = s;
    bool negative;
    negative = *s == '-';
    if (*s == '+' || *s == '-')
        s += 2;
    for (unsigned i = 0; i < count; ++i)
    {
        while (*sEnd && *sEnd != '+' && *sEnd != '-')
            ++sEnd;
        elements[i] = new (std::nothrow) Monomial(s, sEnd, negative);
        if (!elements[i])
        {
            dealloc(elements, i);
            elements = nullptr;
            count = 0;
            std::cout << "<Failed to convert to Polynomial.>\n";
            return;
        }
        negative = *sEnd == '-';
        if (*sEnd)
            sEnd += 2;
        s = sEnd;
    }
    std::cout << "<String converted to Polynomial successfully.>\n";
    sortElements();
}

Polynomial::Polynomial(const char *s)
{
    elements = nullptr;
    count = 0;
    fromString(s);
    sortElements();
}

void Polynomial::sortElements()
{
    unsigned iMax = 0;
    for (unsigned i = 0; i < count - 1; ++i)
    {
        iMax = i;
        for (unsigned j = i; j < count; ++j)
            if (elements[j]->getDegree() > elements[iMax]->getDegree())
                iMax = j;
        Monomial *tmp = elements[i];
        elements[i] = elements[iMax];
        elements[iMax] = tmp;
    }
}
