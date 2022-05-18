#include "Hero.hpp"

Hero &Hero::operator=(const Hero &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Hero::~Hero()
{
    clear();
}

void Hero::pickupWeapon(const Weapon &w)
{
    if (dexterity >= w.minDext())
        myWeapon = &w;
    else
        std::cerr << "Not enough dexterity to pickup this weapon!\n";
}

void Hero::clear()
{
    delete[] name;
}

void Hero::copy(const Hero &other)
{
    clear();
    myWeapon = other.myWeapon;
    dexterity = other.dexterity;
    baseAttack = other.baseAttack;
    health = other.health;
    dexterityOnLevelUp = other.dexterityOnLevelUp;
    experience = other.experience;
    level = other.level;
}

void Hero::print(std::ostream &os) const
{
    os << name << " is a";
    printType();
    os << " level " << level
       << " with health " << health
       << " and power " << baseAttack;
}

std::ostream &operator<<(std::ostream &os, const Hero &H)
{
    H.print();
    return os;
}

void Hero::battle(Enemy &enemy)
{
    unsigned saveEnergy = energy;
    unsigned saveHealth = health;
    do
    {
        if (energy)
        {
            if (myWeapon && energy >= myWeapon->getCost())

            {
                energy -= myWeapon->getCost();
                enemy.takeDamage(baseAttack + myWeapon->getAttack());
            }
            else
                enemy.takeDamage(baseAttack);
        }
        if (enemy.getHealth())
            takeDamage(enemy.getattack());
    } while (enemy.getHealth() && health);
    if (health)
    {
        health = saveHealth;
        energy = saveEnergy;
        std::clog << name << " won!\n";
        addExperience(enemy.getDrop());
    }
    else
    {
        std::clog << name << "fought bravely, but died heroically!\n";
    }
}

bool Hero::takeDamage(unsigned damage)
{
    if (damage >= health)
    {
        damage = 0;
        return true;
    }
    health -= damage;
    return true;
}

void Hero::addExperience(unsigned xp)
{
    experience += xp;
    while (experience >= 100)
    {
        experience -= 100;
        ++level;
        health += healthOnLevelUp;
        dexterity += dexterityOnLevelUp;
        std::clog << name << " leveled up to level " << level << '\n';
    }
    std::clog << 100 - experience << "xp needed to next level\n";
}
