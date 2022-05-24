#include "CPU.hpp"

const float CPU::CORE_PRICE = 29.99;

CPU::CPU(const std::string &label, unsigned short _cores, unsigned short _clock)
    : Component(label), cores(_cores), clockSpeed(_clock)
{
    assert(cores >= CORES_MIN && cores <= CORES_MAX);
}

CPU *CPU::clone() const
{
    return new CPU(*this);
}

double CPU::price() const
{
    return CORE_PRICE * cores;
}
