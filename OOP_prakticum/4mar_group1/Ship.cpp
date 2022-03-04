#include <iostream>
#include "Ship.hpp"

Ship::Ship()
{
    length = 0;
    pos = nullptr;
}

Ship::Ship(const Ship &s)
{
    this->copy(s);
}

void Ship::read()
{
    if (pos)
        delete[] pos;
    std::cout << "Enter ship's length: ";
    std::cin >> length;
    std::cout << "Enter ship's \'head\' coordinates: ";
    unsigned startY, startX;
    char dir;
    std::cin >> startY >> startX;
    std::cout << "Enter direction of the ship (h for help): ";
    std::cin >> dir;
    if (dir == 'h')
    {
        std::cout << "\t1 for up\n\t2 for up-right\n";
        std::cout << "\t3 for right\n\t4 for down-right\n";
        std::cout << "\t5 for down\n\t6 for down-left\n";
        std::cout << "\t7 for left\n\t8 for up-left\n";
        std::cin >> dir;
    }
    Direction shipDir(dir - '0');
    init(length, startY - 1, startX - 1, shipDir);
    std::cout << "<Ship created successfully.>\n";
}

void Ship::init(unsigned _length, unsigned y, unsigned x, Direction dir)
{
    length = _length;
    pos = new (std::nothrow) Cell[length];
    Cell tmp = {(int)y, (int)x, false};
    tmp.y -= dir.dy;
    tmp.x -= dir.dx;
    for (unsigned i = 0; i < length; ++i)
    {
        tmp.y += dir.dy;
        tmp.x += dir.dx;
        pos[i] = tmp;
    }
}

Ship::Ship(unsigned _length, unsigned y, unsigned x, Direction dir)
{
    init(_length, y, x, dir);
}

bool Ship::isOnMap(const Map &map) const
{
    unsigned i = 0;
    while (i < length &&
           (pos[i].x >= 0 && pos[i].x < map.m) &&
           (pos[i].y >= 0 && pos[i].y < map.n))
        ++i;
    return i == length;
}

bool Ship::isIntersecting(const Ship &s) const
{
    unsigned i = 0;
    while (i < length &&
           i < s.length &&
           (s.pos[i].x != this->pos[i].x || s.pos[i].y != this->pos[i].y))
        ++i;
    return i == length || i == s.length;
}

void Ship::copy(const Ship &s)
{
    length = s.length;
    if (pos)
        delete[] pos;
    pos = new (std::nothrow) Cell[length];
    for (unsigned i = 0; i < length; ++i)
    {
        pos[i] = s.pos[i];
        pos[i].hit = false;
    }
}

bool Ship::hit(unsigned y, unsigned x)
{
    unsigned i = 0;
    while (i < length && (pos[i].x != x || pos[i].y != y))
        ++i;
    if (i == length)
        return false;
    pos[i].hit = true;
    return true;
}

bool Ship::covers(unsigned y, unsigned x) const
{
    unsigned i = 0;
    while (i < length && (pos[i].x != x || pos[i].y != y))
        ++i;
    return i < length;
}

bool Ship::isHit(unsigned y, unsigned x) const
{
    unsigned i = 0;
    while (i < length && (pos[i].x != x || pos[i].y != y))
        ++i;
    return pos[i].hit;
}

bool Ship::isBroken() const
{
    unsigned i = 0;
    while (i < length && pos[i].hit)
        ++i;
    return i == length;
}

Ship::~Ship()
{
    delete[] pos;
}
