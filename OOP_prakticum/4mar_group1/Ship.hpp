#pragma once
#include "Types.hpp"
#include "Direction.hpp"
#include "Cell.hpp"
#include "Map.hpp"

struct Ship
{
    unsigned length;
    Cell *pos = nullptr;
    Ship();
    Ship(const Ship &);
    Ship(unsigned _length, unsigned y, unsigned x, Direction dir);
    void init(unsigned _length, unsigned y, unsigned x, Direction dir);
    void read();
    bool isOnMap(const Map &m) const;
    bool isIntersecting(const Ship &s) const;
    void copy(const Ship &s);
    bool hit(unsigned y, unsigned x);
    bool isBroken() const;
    bool covers(unsigned y, unsigned x) const;
    bool isHit(unsigned y, unsigned x) const;
    ~Ship();
};