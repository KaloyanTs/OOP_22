#pragma once
#include "Map.hpp"
const unsigned NAME_MAX = 16;

struct Player
{
    char name[NAME_MAX];
    Map map;
    Player();
    Player(const char *_name, Map &map);
    bool playTurn();
};