#ifndef __CPU_HPP
#define __CPU_HPP
#include "Component.hpp"
#include <cassert>

class CPU : public Component
{
    static const unsigned short CORES_MIN = 1;
    static const unsigned short CORES_MAX = 8;
    static const float CORE_PRICE;

    const unsigned short cores;
    const unsigned short clockSpeed;

public:
    CPU(const std::string &label, unsigned short _cores, unsigned short _clock);
    virtual CPU *clone() const;
    virtual double price() const;
};

#endif