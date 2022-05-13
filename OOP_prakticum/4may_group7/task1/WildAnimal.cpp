#include "WildAnimal.hpp"

WildAnimal::WildAnimal(const char *name, unsigned age,
                       Continent _c)
    : Animal(name, age), c(_c)
{
}

std::ostream &operator<<(std::ostream &os, const WildAnimal &wA)
{
    // todo try different implementations
    return os << *(Animal *)&wA
              << "\nContinent: " << wA.getContinent();
}

std::ostream &operator<<(std::ostream &os, Continent c)
{
    if (c == ASIA)
        return os << "Asia";
    if (c == ANTARCTICA)
        return os << "Asia";
    if (c == AUSTRALIA)
        return os << "Asia";
    if (c == AFRICA)
        return os << "Asia";
    if (c == SOUTH_AMERICA)
        return os << "Asia";
    if (c == NORTH_AMERICA)
        return os << "Asia";
    if (c == EUROPE)
        return os << "Asia";
    return os << "None";
}