#include <iostream>
#include <cstring>
#include "Player.hpp"

Player::Player() {}

Player::Player(const char *_name, Map &map)
{
    strcpy(name, _name);
    std::cout << name << ", enter size of your map: ";
    unsigned N, M, sC;
    std::cin >> N >> M;
    std::cout << name << ", enter count of ships on your map: ";
    std::cin >> sC;
    map.initMap(N, M, sC);
    Ship tmp;
    while (!map.ready)
    {
        std::cout << map.shipCount - map.shipLeft << " ships left to be placed.\n";
        tmp.read();
        map.placeShip(tmp);
    }
}

bool Player::playTurn()
{
    std::cout << "It's " << name << "'s turn:\n";
    std::cout << "Choose cell to be attacked: ";
    unsigned posY, posX;
    std::cin >> posY >> posX;
    Ship res(map.attack(posY - 1, posX - 1));
    if (res.length)
        std::cout << name << " hit a ship with length " << res.length << ".\n";
    else
        std::cout << name << " didn't hit a ship.\n";
    map.print();
    std::cout << "<End of " << name << "'s turn.>\n";
    return !map.shipsLeft();
}