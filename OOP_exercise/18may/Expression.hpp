#ifndef __EXPRESSION_HPP
#define __EXPRESSION_HPP
#include <iostream>

class Expression
{

public:
    virtual float value() = 0;
    virtual void print(std::ostream &os = std::cout) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Expression &E);

#endif