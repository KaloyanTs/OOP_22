#ifndef __GP_HPP
#define __GP_HPP
#include "Patient.hpp"
const size_t INIT_CAPACITY = 2;

class GP
{
    size_t size, capacity;
    Patient **patients;
    void clear();
    void copy(const GP &other);
    void resize(size_t newCap);

public:
    GP(size_t _c = INIT_CAPACITY);
    GP(const GP &other);
    GP &operator=(const GP &other);
    ~GP();

    GP &addPatient(const Patient &P);
    GP &removePatient(const char *name);
    GP &printDiagnosed(const char *diagnose);
    GP &sortByAge();
    GP &operator+=(const Patient &P) { return addPatient(P); }
    GP operator+(const Patient &P);
    GP &operator-=(const char *name) { return removePatient(name); }
    GP operator-(const char *name);
    void showAverageCondition() const;
    void writeToBinary(const char *fileName);
    void writeToText(const char *fileName);
    void readFromBinary(const char *fileName);
    void readFromText(const char *fileName);
    void print() const;
};

#endif