#include <iostream>
#include "Game.hpp"

int main()
{
    Game g;
    while (!g.playTurn())
    {
    }
    char wName[NAME_MAX];
    g.getWinnerName(wName);
    std::cout << wName << " wins!\n";
    return 0;
}