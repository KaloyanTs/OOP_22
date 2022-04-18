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
    char group;
    void copy(const Student &other);
    void clear();

public:
    Student(const char *name = "unknown", const char *fn = "0MI0000000",
            float avg = 0, char group = 0);
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    void writeToBin(std::ofstream &ifs) const;
    void readFromBin(std::ifstream &ofs);
    bool operator<(const Student &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Student &S);
    friend std::istream &operator>>(std::istream &is, Student &S);
};

#endif