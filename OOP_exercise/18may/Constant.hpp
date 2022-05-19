#ifndef __CONSTANT_HPP
#define __CONSTANT_HPP
#include "Expression.hpp"

class Constant : public Expression
{
    const float M_value;

public:
    Constant(float v) : M_value(v) {}
    void print(std::ostream &os = std::cout) const;
    float value() { return M_value; }
};

#endif