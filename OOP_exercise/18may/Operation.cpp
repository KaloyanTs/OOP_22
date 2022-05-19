#include "Operation.hpp"

float Operation::value()
{
    float res = expr[0]->value();
    for (unsigned i = 1; i < size; ++i)
        res = do_op(res, expr[i]->value());
    return res;
}

void Operation::print(std::ostream &os) const
{
    os << '(';
    for (unsigned i = 0; i < size; ++i)
    {
        if (i)
            os << ' ' << op << ' ';
        os << *expr[i];
    }
    os << ')';
}

float Operation::do_op(float a, float b) const
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        assert(b);
        return a / b;
    }
    assert(false);
    return 0;
}