#ifndef __WARRIOR_HPP
#define __WARRIOR_HPP
#include "Hero.hpp"

class Warrior : public Hero
{
public:
    Warrior(const char *n = "unknown", unsigned h = 0,
            unsigned dex = 0,
            unsigned en = 0, unsigned bA = 0)
        : Hero(n, h, dex, en, bA, 0, 6, 6)
    {
    }

    void printType(std::ostream &os = std::cout) const;
};

#endif