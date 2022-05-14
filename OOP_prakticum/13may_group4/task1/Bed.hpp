#ifndef __BED_HPP
#define __BED_HPP
#include "Furniture.hpp"

class Bed : public Furniture
{
public:
    Bed(unsigned l, unsigned w, unsigned h)
        : Furniture(l, w, h, 22) {}

    void print(std::ostream &os = std::cout) const;
    unsigned calculatePrice() const;
};

#endif