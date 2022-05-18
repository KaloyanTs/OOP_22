#ifndef __HERO_HPP
#define __HERO_HPP
#include "Weapon.hpp"
#include "Enemy.hpp"

class Hero
{
    char *name;
    unsigned health;
    unsigned dexterity;
    unsigned energy;
    unsigned baseAttack;
    unsigned experience;
    unsigned level;
    unsigned healthOnLevelUp;
    unsigned dexterityOnLevelUp;
    const Weapon *myWeapon;

    void clear();
    bool takeDamage(unsigned damage);
    void addExperience(unsigned xp);

protected:
    void copy(const Hero &other);

public:
    Hero(const char *n = "unknown", unsigned Health = 0, unsigned dex = 0,
         unsigned en = 0, unsigned bA = 0,
         unsigned exp = 0,
         unsigned hOnLvlUp = 0, unsigned dexOnLvlUp = 0)
        : name(new char[strlen(n) + 1]), health(Health),
          dexterity(dex),
          energy(en), baseAttack(bA),
          experience(exp), level(1),
          healthOnLevelUp(hOnLvlUp), dexterityOnLevelUp(dexOnLvlUp),
          myWeapon(nullptr)
    {
        strcpy(name, n);
    }

    Hero(const Hero &other) : name(nullptr) { copy(other); }
    Hero &operator=(const Hero &other);
    virtual ~Hero();

    void pickupWeapon(const Weapon &w);

    virtual void printType(std::ostream &os = std::cout) const = 0;

    void print(std::ostream &os = std::cout) const;

    void battle(Enemy &enemy);
};

std::ostream &operator<<(std::ostream &os, const Hero &H);

#endif