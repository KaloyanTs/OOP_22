#ifndef __UNIVERSITY_HPP
#define __UNIVERSITY_HPP
#include "Scientist.hpp"
#include <iostream>

class University
{
    size_t countScientists;
    Scientist **scientists;
    void copy(const University &U);
    void sortByTitle();
    void dealloc(Scientist **&arr, size_t size);
    unsigned searchScient(const char *name) const;
    unsigned countScientistsByTitle(Title title);
    unsigned getIncome() const;
    unsigned getExpenses() const;

public:
    University();
    University(const University &U);
    bool hireScientist(const Scientist &S);
    bool fireScientist(const char *name);
    bool elevateScientist(const char *name);
    void fireScientists(Title title);
    int getProfit() const { return getIncome() - getExpenses(); }
    const University &operator=(const University &U);
    ~University();
    void print() const;
};

#endif