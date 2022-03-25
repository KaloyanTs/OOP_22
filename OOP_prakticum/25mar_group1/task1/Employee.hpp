#ifndef __EMPLOYEE_HPP
#define __EMPLOYEE_HPP
#include <iostream>
#include <cstring>
#include <cassert>

class Employee
{
    char *name, *ID, *position;
    unsigned salary;
    void copy(const Employee &);

public:
    Employee();
    Employee(const char *_n, const char *_id, const char *pos, unsigned _s);
    Employee(const Employee &E);
    const char *getName() const { return name; }
    const char *getID() const { return ID; }
    const char *getPosition() const { return position; }
    unsigned getSalary() const { return salary; }
    void setPosition(const char *_p);
    void setSalary(unsigned _s) { salary = _s; }
    const Employee &operator=(const Employee &C);
    void print() const;
    ~Employee();
};

#endif