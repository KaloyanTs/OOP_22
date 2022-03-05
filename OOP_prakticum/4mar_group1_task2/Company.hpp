#pragma once
const unsigned NAME_MAX = 64;
const unsigned DAUGHTER_MAX = 32;

struct Company
{
    char name[NAME_MAX];
    Company **daughters = nullptr;
    Company *mother = nullptr;
    unsigned daughterCount = 0;
    Company();
    Company(const char *_name);
    void print() const;
    bool isMyChild(const Company &c);
    void removeDaughter(Company &c);
    bool acquire(Company &c);
    ~Company();
};