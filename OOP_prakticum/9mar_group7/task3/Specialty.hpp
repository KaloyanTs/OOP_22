#ifndef __SPECIALTY_HPP
#define __SPECIALTY_HPP
#include <iostream>
#include <cstring>
#include <cassert>
#include "Classes.hpp"
#include "Student.hpp"
const unsigned INIT_CAPACITY = 1;

class Specialty
{
    char *name;
    const Student **students;
    size_t studentCount, studentCapacity;
    void copy(const Specialty &);

public:
    Specialty();
    Specialty(const char *);
    Specialty(const Specialty &);
    const char *getName() const { return name; }
    void setName(const char *_name);
    void addStudent(Student *);
    const Specialty &operator=(const Specialty &);
    void print() const;
    ~Specialty();
};

#endif