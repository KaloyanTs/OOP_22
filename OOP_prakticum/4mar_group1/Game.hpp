#pragma once
#include "Player.hpp"

struct Game
{
    Player **p;
    bool pl1Turn;
    Game();
    ~Game();
    void getWinnerName(char *buf);
    bool playTurn();
};