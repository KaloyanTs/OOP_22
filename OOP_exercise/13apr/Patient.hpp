#ifndef __PATIENT__HPP
#define __PATIENT__HPP
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
const size_t ADDRESS_MAX = 32;
const size_t INPUT_MAX = 32;

enum Condition
{
    HEALTHY = 0,
    ILL,
    SERIOUSLY_ILL,
    HEALING
};

std::ostream &operator<<(std::ostream &os, Condition C);
std::istream &operator>>(std::istream &is, Condition &C);

class Patient
{
    char *name, *diagnose, address[ADDRESS_MAX + 1];
    unsigned age;
    Condition condition;
    float good;
    void clear();
    void copy(const Patient &other);

public:
    Patient(const char *_name = "unknown",
            const char *_address = "unknown",
            unsigned _age = 0,
            const char *_diag = "unknown",
            Condition _c = HEALTHY,
            float _good = 1);
    Patient(const Patient &other);
    Patient &operator=(const Patient &other);
    ~Patient();

    const char *getName() const { return name; }
    Condition getCondition() const { return condition; }
    float getConditionScore() const { return good; }
    unsigned getAge() const { return age; }
    void setDiagnose(const char *newDiag);
    void setCodition(Condition newCond);
    void writeToBinary(std::ofstream &ofs);
    void writeToText(std::ofstream &ofs);
    void readFromText(std::ifstream &ifs);
    void readFromBinary(std::ifstream &ifs);
    bool hasDignose(const char *diag) const { return strstr(diagnose, diag); }
    bool operator==(const Patient &other) { return condition == other.condition; }
    bool operator<(const Patient &other) { return good < other.good; }
    bool operator>(const Patient &other) { return good > other.good; }
    bool operator<=(const Patient &other) { return good <= other.good; }
    bool operator>=(const Patient &other) { return good >= other.good; }
    friend std::ostream &operator<<(std::ostream &os, const Patient &P);
    friend std::istream &operator>>(std::istream &is, Patient &P);
};

#endif