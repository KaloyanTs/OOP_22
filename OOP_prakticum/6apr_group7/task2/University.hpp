#ifndef __UNIVERSITY_HPP
#define __UNIVERSITY_HPP
#include "Student.hpp"
#include <fstream>
const size_t INIT_CAPACITY = 1;

class University
{
    char name[NAME_MAX + 1];
    Student **students;
    size_t size, capacity;
    void copy(const University &other);
    void clear();
    void expand(size_t newCap);

public:
    University();
    University(const char *_name);
    University(const University &other);
    ~University();
    University &addStudent(const Student &S);
    University &removeStudent(const char *_name);
    University &write();
    University &operator=(const University &other);
friend std::ostream &operator<<(std::ostream &out, const University &U);    
    friend std::istream &operator>>(std::istream &out, University &U);
};

#endif