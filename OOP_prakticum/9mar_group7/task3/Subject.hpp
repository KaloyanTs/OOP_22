#ifndef __SUBJECT_HPP
#define __SUBJECT_HPP
#include "Classes.hpp"
#include "Specialty.hpp"

class Subject
{
    char *name;
    char *lecturerName;
    const Specialty *specialty;
    unsigned credits;
    void copy(const Subject &S);

public:
    Subject();
    Subject(const char *_name, const char *lName, unsigned, const char *spName, Specialty **list, size_t listSize);
    Subject(const Subject &S);
    const Subject &operator=(const Subject &S);
    const char *getName() const { return name; }
    const char *getLecturer() const { return lecturerName; }
    unsigned getCredits() const { return credits; }
    const Specialty *getSpecialty() const { return specialty; }
    void print() const;
    ~Subject();
};

#endif