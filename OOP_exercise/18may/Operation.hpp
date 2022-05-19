#ifndef __OPERATION_HPP
#define __OPERATION_HPP
#include "Expression.hpp"
#include <cassert>

class Operation : public Expression
{
    char op;
    Expression **expr;
    size_t size;

    float do_op(float a, float b) const;

public:
    Operation(char _op, Expression **arr, size_t count)
        : op(_op), expr(new Expression *[count]), size(count)
    {
        for (unsigned i = 0; i < size; ++i)
            expr[i] = arr[i];
    }
    float value();
    void print(std::ostream &os = std::cout) const;
    ~Operation() { delete[] expr; }
};

#endif