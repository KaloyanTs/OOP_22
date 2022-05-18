#include "Weapon.hpp"

void Weapon::clear()
{
    delete[] name;
}

Weapon &Weapon::operator=(const Weapon &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Weapon::~Weapon()
{
    clear();
}

void Weapon::copy(const Weapon &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    energyCost = other.energyCost;
    minimunDexterity = other.minimunDexterity;
    attack = other.attack;
}
