#ifndef __UNIVERSITY_HPP
#define __UNIVERSITY_HPP
#include "Classes.hpp"
#include "Specialty.hpp"
#include "Student.hpp"
#include "Subject.hpp"

class University
{
    Specialty **specialties;
    Subject **subjects;
    size_t spCount, subCount;
    size_t spCapacity, subCapacity;
    void copy(const University &U);

public:
    University();
    University(const University &U);
    const University &operator=(const University &U);
    size_t getSpecialtiesCount() const { return spCount; }
    size_t getSubjectsCount() const { return subCount; }
    Specialty *const *getSpecialties() const { return specialties; }
    Subject *const *getSubject() const { return subjects; }
    void readNewSpecialty();
    void readNewSubject();
    void printStudents() const;
    void printStructure() const;
    ~University();
};

#endif