#include <iostream>
#include "Game.hpp"

int main()
{
    Game g(8);
    if (g.run())
        std::clog << "You won!\n";
    else
        std::clog << "You lost!\n";
    return 0;
}