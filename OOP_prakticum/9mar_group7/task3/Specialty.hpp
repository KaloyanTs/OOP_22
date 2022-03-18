#ifndef __SPECIALTY_HPP
#define __SPECIALTY_HPP
#include <iostream>
#include <cstring>
#include <cassert>
#include "Student.hpp"

class Specialty
{
    char *name;
    const Student **studetns;
    size_t studentCount, studentCapacity;

public:
    const char *getName() const { return name; }
    void addStudent(const Student *);
};

#endif