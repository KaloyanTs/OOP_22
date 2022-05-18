#include <iostream>
#include "Barbarian.hpp"
#include "Assassin.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"

int main()
{
    Assassin az("K", 45, 100, 200, 13);
    Hero *ptr = &az;
    std::cout << *ptr << '\n';
    Weapon AK47("AK47", 50, 30, 30);
    ptr->pickupWeapon(AK47);
    Enemy troll(150, 10, 423);
    az.battle(troll);
    std::cout << az << '\n';
    return 0;
}