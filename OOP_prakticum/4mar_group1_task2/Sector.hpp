#pragma once
#include "Company.hpp"

struct Sector
{
    Company **companies = nullptr;
    unsigned companyCount = 0;
    Sector();
    void readSector();
    bool acquire(const char *buyer, const char *bought);
    void print() const;
    ~Sector();
};