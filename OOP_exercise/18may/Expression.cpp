#include "Expression.hpp"

std::ostream &operator<<(std::ostream &os, const Expression &E)
{
    E.print(os);
    return os;
}