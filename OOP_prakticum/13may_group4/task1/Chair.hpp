#ifndef __CHAIR_HPP
#define __CHAIR_HPP
#include "Furniture.hpp"

enum ChairType
{
    CHAIR_NONE = 0,
    WOODEN,
    METAL,
    PLASTIC
};

std::ostream &operator<<(std::ostream &os, ChairType t);

class Chair : public Furniture
{
    ChairType type;

public:
    Chair(unsigned l, unsigned w, unsigned h, ChairType t)
        : Furniture(l, w, h, 9), type(t) {}

    ChairType getType() const { return type; }

    void print(std::ostream &os = std::cout) const;
    unsigned calculatePrice() const;
};

#endif