#ifndef __MEMORY_HPP
#define __MEMORY_HPP
#include "Component.hpp"
#include <cassert>

class Memory : public Component
{
    static const unsigned short GB_MIN = 1;
    static const unsigned short GB_MAX = 10000;
    static const float GB_PRICE;

    const unsigned short capacity;

public:
    Memory(const std::string &label, unsigned short cap);
    virtual Memory *clone() const;
    virtual double price() const;
};

#endif