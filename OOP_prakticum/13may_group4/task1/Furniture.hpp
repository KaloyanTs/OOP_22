#ifndef __FURNITURE_HPP
#define __FURNITURE_HPP
#include <iostream>

class Furniture
{
    static unsigned ID_COUNTER;
    unsigned ID;
    unsigned height, width, length;
    const unsigned priceConst;

public:
    Furniture(unsigned l, unsigned w, unsigned h, unsigned pConst)
        : length(l), width(w), height(h), priceConst(pConst) { ID = ++ID_COUNTER; }

    virtual ~Furniture();

    unsigned getLength() const { return length; }
    unsigned getWidth() const { return width; }
    unsigned getHeight() const { return height; }
    unsigned getID() const { return ID; }
    const unsigned getPriceConst() const { return priceConst; }

    virtual void print(std::ostream &os = std::cout) const;
    void printAll(std::ostream &os = std::cout) const;
    virtual unsigned calculatePrice() const = 0;
    virtual ~Furniture() { --ID_COUNTER; }
};

std::ostream &operator<<(std::ostream &os, const Furniture &F);

#endif