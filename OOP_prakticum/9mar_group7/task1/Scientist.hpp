#ifndef __SCIENTIST_HPP
#define __SCIENTIST_HPP
#include "Title.hpp"
#include <iostream>
#include <cstring>
const unsigned NAME_MAX = 16;
const unsigned TITLE_SALARY_DIFFERENCE = 100;

class Scientist
{
    char *name;
    unsigned salary;
    unsigned profit;
    Title title;
    void copy(const Scientist &S);

public:
    Scientist();
    Scientist(const char *_n, unsigned salary, unsigned _p);
    Scientist(const Scientist &S);
    void read();
    const Title &getTitle() const { return title; }
    unsigned getSalary() const { return salary; }
    unsigned getProfit() const { return profit; }
    const char *getName() const { return name; }
    const Scientist &operator=(const Scientist &S);
    void print() const;
    bool elevate();
    ~Scientist();
};

#endif