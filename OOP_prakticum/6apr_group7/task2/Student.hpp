#ifndef __STUDENT_HPP
#define __STUDENT_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const size_t NAME_MAX = 31;

class Student
{
    char name[NAME_MAX + 1];
    unsigned age;
    friend class University;

public:
    Student() : age(0), name("") {}
    Student(const char *_name, unsigned _age) : age(_age) { strcpy(name, _name); }
    friend std::ostream &operator<<(std::ostream &out, const Student &S);
    friend std::istream &operator>>(std::istream &in, Student &S);
};

#endif