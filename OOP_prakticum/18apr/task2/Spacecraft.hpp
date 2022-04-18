#ifndef __SPACECRAFT_HPP
#define __SPACECRAFT_HPP
#include <iostream>
#include <cstring>
#include <fstream>

class Spacecraft
{
    unsigned launchYear;
    char *name;
    void copy(const Spacecraft &other);
    void clear();

public:
    Spacecraft(const char *name = "unknown", unsigned year = 0);
    Spacecraft(const Spacecraft &other);
    Spacecraft &operator=(const Spacecraft &S);
    ~Spacecraft();

    void writeToBin(std::ofstream &ofs);
    void readFromBin(std::ifstream &ifs);

    friend std::ostream &operator<<(std::ostream &ofs, const Spacecraft &Sp);
};

#endif