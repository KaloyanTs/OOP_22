#ifndef __WILDANIMAL_HPP
#define __WILDANIMAL_HPP
#include "Animal.hpp"

enum Continent
{
    NONE = 0,
    ASIA,
    AFRICA,
    NORTH_AMERICA,
    SOUTH_AMERICA,
    ANTARCTICA,
    EUROPE,
    AUSTRALIA
};

std::ostream &operator<<(std::ostream &os, Continent c);

class WildAnimal : public Animal
{
    Continent c;

public:
    WildAnimal(const char *name = "unknown", unsigned age = 0,
               Continent _c = NONE);

    Continent getContinent() const { return c; }

    void setContinent(Continent _c) { c = _c; }
};

std::ostream &operator<<(std::ostream &os, const WildAnimal &wA);

#endif