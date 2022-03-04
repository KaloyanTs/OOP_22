#include <iostream>
#include "Map.hpp"

Map::Map()
{
    n = 0;
    m = 0;
    shipCount = shipLeft = 0;
    ready = shipCount == shipLeft;
}

Map::Map(const Map &map)
{
    copy(map);
}

void Map::copy(const Map &map)
{
    n = map.n;
    m = map.m;
    shipCount = map.shipCount;
    shipLeft = map.shipLeft;
    ready = map.ready;
    ships = new (std::nothrow) Ship[shipCount];
    for (unsigned i = 0; i < shipCount; ++i)
        ships[i].copy(map.ships[i]);
}

void Map::initMap(unsigned _n, unsigned _m, unsigned _shipCount)
{
    n = _n;
    m = _m;
    shipCount = _shipCount;
    shipLeft = 0;
    ready = shipCount == shipLeft;
    ships = new (std::nothrow) Ship[shipCount];
    std::cout << "<Map created successfully.>\n";
}

Map::Map(unsigned _n, unsigned _m, unsigned _shipCount)
{
    initMap(_n, _m, _shipCount);
}

bool Map::placeShip(const Ship &s)
{
    if (ready)
    {
        std::cout << "<Ship could not be placed. (no more ships allowed)>\n";
        return false;
    }
    if (!s.isOnMap(*this))
    {
        std::cout << "<Ship could not be placed. (bad positioning)>\n";
        return false;
    }
    unsigned i = 0;
    while (i < shipLeft && !s.isIntersecting(ships[i]))
        ++i;
    if (i < shipLeft)
    {
        std::cout << "<Ship could not be placed. (intersecting with ship)>\n";
        return false;
    }
    ships[shipLeft++].copy(s);
    std::cout << "<Ship placed successfully.>\n";
    ready = shipCount == shipLeft;
    return true;
}

Ship Map::attack(unsigned y, unsigned x)
{
    Ship res;
    if (!ready)
    {
        std::cout << "<Attack not allowed. (more ships to be placed)>\n";
        return res;
    }
    if (y >= n || x >= m)
    {
        std::cout << "<Attack not allowed. (position not on map)>\n";
        return res;
    }
    unsigned i = 0;
    while (i < shipCount && !ships[i].hit(y, x))
        ++i;
    if (i < shipCount)
    {
        res.copy(ships[i]);
        shipLeft -= ships[i].isBroken();
    }
    std::cout << "<Attack proceeded successfully.>\n";
    return res;
}

bool Map::shipsLeft()
{
    // unsigned i = 0;
    // while (i < shipCount && ships[i].isBroken())
    //     ++i;
    // return i < shipCount;
    return shipLeft;
}

bool Map::hitShip(unsigned y, unsigned x)
{
    unsigned i = 0;
    while (i < shipCount && !ships[i].covers(y, x))
        ++i;
    return i < shipCount && ships[i].isHit(y, x);
}

void Map::print()
{
    if (!ready)
    {
        std::cout << "<Map is not ready.>\n";
        return;
    }
    for (unsigned i = 0; i < m + 2; ++i)
        std::cout << '-';
    std::cout << '\n';

    for (unsigned i = 0; i < n; ++i)
    {
        std::cout << '|';
        for (unsigned j = 0; j < m; ++j)
            std::cout << (hitShip(i, j) ? 'X' : ' ');
        std::cout << '|';
        std::cout << '\n';
    }

    for (unsigned i = 0; i < m + 2; ++i)
        std::cout << '-';
    std::cout << '\n';
}

Map::~Map()
{
    delete[] ships;
}