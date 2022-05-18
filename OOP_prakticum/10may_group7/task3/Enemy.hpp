#ifndef __ENEMY_HPP
#define __ENEMY_HPP

class Enemy
{
    unsigned health;
    unsigned attack;
    unsigned experienceDrop;

public:
    Enemy(unsigned h = 0, unsigned a = 0, unsigned expD = 0) : health(h), attack(a), experienceDrop(expD) {}
    unsigned getHealth() const { return health; }
    unsigned getattack() const { return attack; }
    unsigned getDrop() const { return experienceDrop; }

    bool takeDamage(unsigned damage);
};

#endif