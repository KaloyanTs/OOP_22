#include "Worker.hpp"

void Worker::print(std::ostream &os) const
{
    Person::print(os);
    os << "\nSalary: " << salary;
}

std::ostream &operator<<(std::ostream &os, const Worker &W)
{
    W.print(os);
    return os;
}