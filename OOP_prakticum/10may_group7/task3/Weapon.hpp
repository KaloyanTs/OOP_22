#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include <iostream>
#include <cstring>

class Weapon
{
    char *name;
    unsigned attack;
    unsigned minimunDexterity;
    unsigned energyCost;

    void clear();
    void copy(const Weapon &other);

public:
    Weapon(const char *n = "unknown", unsigned a = 0, unsigned mD = 0, unsigned eC = 0)
        : name(new char[strlen(n) + 1]), attack(a), minimunDexterity(mD), energyCost(eC)
    {
        strcpy(name, n);
    }
    Weapon(const Weapon &other) : name(nullptr) { copy(other); }
    Weapon &operator=(const Weapon &other);
    ~Weapon();

    const char *getName() const { return name; }
    unsigned getAttack() const { return attack; }
    unsigned minDext() const { return minimunDexterity; }
    unsigned getCost() const { return energyCost; }
};

#endif