#include "Enemy.hpp"

bool Enemy::takeDamage(unsigned damage)
{
    if (damage >= health)
    {
        health = 0;
        return true;
    }
    health -= damage;
    return true;
}
