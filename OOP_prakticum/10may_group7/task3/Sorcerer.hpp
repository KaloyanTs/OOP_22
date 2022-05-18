#ifndef __SORCERER_HPP
#define __SORCERER_HPP
#include "Hero.hpp"

class Sorcerer : public Hero
{
public:
    Sorcerer(const char *n = "unknown", unsigned health=0,
             unsigned dex = 0,
             unsigned en = 0, unsigned bA = 0)
        : Hero(n, health, dex, en, bA, 0, 4, 10)
    {
    }

    void printType(std::ostream &os = std::cout) const;
};

#endif