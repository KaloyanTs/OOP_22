#include "Memory.hpp"

const float Memory::GB_PRICE = 89.99;

Memory::Memory(const std::string &label, unsigned short cap)
    : Component(label), capacity(cap)
{
    assert(capacity >= GB_MIN && capacity <= GB_MAX);
}

Memory *Memory::clone() const
{
    return new Memory(*this);
}

double Memory::price() const
{
    return GB_PRICE * capacity;
}
