#ifndef __ASSASSIN_HPP
#define __ASSASSIN_HPP
#include "Hero.hpp"

class Assassin : public Hero
{
public:
    Assassin(const char *n = "unknown", unsigned h = 0, unsigned dex = 0,
             unsigned en = 0, unsigned bA = 0)
        : Hero(n, h, dex, en, bA, 0, 5, 10)
    {
    }

    void printType(std::ostream &os = std::cout) const;
};

#endif