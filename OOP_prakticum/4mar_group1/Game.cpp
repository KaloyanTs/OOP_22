#include <iostream>
#include <cstring>
#include "Game.hpp"

Game::Game()
{
    p = new (std::nothrow) Player *[2];
    char tmp[NAME_MAX];
    Map tmpMap1, tmpMap2;
    std::cout << "Enter first player's name: ";
    std::cin.getline(tmp, NAME_MAX);
    p[0] = new Player(tmp, tmpMap1);
    std::cout << "Enter second player's name: ";
    std::cin.ignore();
    std::cin.getline(tmp, NAME_MAX);
    p[1] = new Player(tmp, tmpMap2);
    p[0]->map.copy(tmpMap2);
    p[1]->map.copy(tmpMap1);
    pl1Turn = true;
}

Game::~Game()
{
    delete p[0];
    delete p[1];
    delete[] p;
}

void Game::getWinnerName(char *buf)
{
    if (pl1Turn)
        strcpy(buf, p[1]->name);
    else
        strcpy(buf, p[0]->name);
}

bool Game::playTurn()
{
    if (pl1Turn)
    {
        pl1Turn = !pl1Turn;
        return p[0]->playTurn();
    }
    else
    {
        pl1Turn = !pl1Turn;
        return p[1]->playTurn();
    }
}