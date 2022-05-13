#ifndef __WORKER_HPP
#define __WORKER_HPP
#include "Person.hpp"

class Worker : public Person
{
    unsigned salary;

public:
    Worker(const char *name, unsigned age, unsigned s)
        : Person(name, age), salary(s) {}

    unsigned getSalary() const { return salary; }

    void print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, const Worker &W);

#endif