#pragma once
#include "Direction.hpp"
#include "Ship.hpp"
#include "Cell.hpp"
const unsigned MAP_SIZE_MAX = 12;

struct Map
{
    unsigned n, m;
    unsigned shipCount, shipLeft;
    bool ready;
    Ship *ships = nullptr;
    Map();
    Map(const Map &m);
    void copy(const Map &);
    void initMap(unsigned, unsigned, unsigned);
    Map(unsigned _n, unsigned _m, unsigned _shipCount);
    bool placeShip(const Ship &s);
    Ship attack(unsigned y, unsigned x);
    bool hitShip(unsigned y, unsigned x);
    bool shipsLeft();
    void print();
    ~Map();
};