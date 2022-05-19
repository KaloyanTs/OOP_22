#ifndef __INPUT_HPP
#define __INPUT_HPP
#include "Expression.hpp"

class Input : public Expression
{
    float m_value;

public:
    void print(std::ostream &os = std::cout) const;
    float value()
    {
        std::cin >> m_value;
        return m_value;
    }
};

#endif