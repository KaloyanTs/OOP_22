#ifndef __STUDENT_HPP
#define __STUDENT_HPP
#include <iostream>
#include <cstring>
#include <cassert>
#include "Specialty.hpp"
const unsigned NAMES_COUNT = 3;
const unsigned INPUT_MAX = 32;

class Student
{
    char **names;
    char *fn;
    const Specialty *specialty;
    unsigned credits;
    unsigned namesCount;
    void copy(const Student &S);
    void dealloc(char **&, size_t);
    unsigned countNames(const char *);

public:
    Student();
    Student(const Student &);
    const Student &operator=(const Student &);
    void print() const;
    void read(Specialty **, size_t);
    ~Student();
};

#endif