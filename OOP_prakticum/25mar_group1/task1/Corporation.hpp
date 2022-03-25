#ifndef __CORPORATION_HPP
#define __CORPORATION_HPP
#include "EmployeeVector.hpp"

class Corporation
{
    char *name;
    EmployeeVector employees;
    const Corporation *mother;
    const Corporation **daughters;
    size_t daughterCount, daughterCapacity;
    void copy(const Corporation &C);
    void resizeDaughters(size_t newSize);

public:
    Corporation() : name(nullptr), daughters(nullptr), mother(nullptr), daughterCapacity(0), daughterCount(0) {}
    Corporation(const char *name, size_t Employeecount, size_t DaughterCap);
    Corporation(const Corporation &C) : name(nullptr), daughters(nullptr), mother(nullptr) { copy(C); }
    const EmployeeVector &getEmployees() const { return employees; }
    Corporation &hire(const Employee &E);
    const char *getName() const { return name; }
    void print() const;
    const Corporation &acquire(Corporation &C);
    const Corporation **getDaughters() const { return daughters; }
    const Corporation &getMother() const { return *mother; }
    ~Corporation();
};

#endif