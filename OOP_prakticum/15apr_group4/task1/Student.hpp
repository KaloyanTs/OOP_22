#ifndef __STUDENT_HPP
#define __STUDENT_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

class Student
{
    char *name;
    char *fn;
    float avg;
    unsigned group;
    void copy(const Student &other);
    void clear();

public:
    Student(const char *name = "unknown", const char *fn = "0MI0000000",
            float avg = 0, unsigned group = 0);
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    const char *getFN() const { return fn; }

    void writeToBin(std::ofstream &ifs) const;
    void readFromBin(std::ifstream &ofs);
    bool operator<(const Student &other) const;

    friend std::ofstream &operator<<(std::ofstream &os, const Student &S);
    friend std::ifstream &operator>>(std::ifstream &is, Student &S);
};

#endif