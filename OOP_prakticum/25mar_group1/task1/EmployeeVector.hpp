#ifndef __EMPLOYEEVECTOR_HPP
#define __EMPLOYEEVECTOR_HPP
#include "Employee.hpp"

class EmployeeVector
{
    Employee **list;
    size_t size, capacity;
    void resize(size_t newCap);
    void copy(const EmployeeVector &eV);

public:
    EmployeeVector();
    EmployeeVector(size_t cap);
    EmployeeVector(const EmployeeVector &eV);
    //добавяне на нов служител
    const EmployeeVector &addEmployee(const Employee &E);
    //премахване на служител по неговото ЕГН
    const EmployeeVector &remove(const char *ID);
    const EmployeeVector &operator=(const EmployeeVector &eV);
    const EmployeeVector &operator+=(const EmployeeVector &other);
    size_t getCount() const { return size; }
    Employee &at(unsigned index) const;
    void print() const;
    ~EmployeeVector();
};

#endif