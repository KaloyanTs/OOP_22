#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <iostream>
#include <conio.h>

class Player
{
    size_t y, x;
    size_t size;

public:
    Player(size_t lim)
        : y(0), x(0), size(lim)
    {
    }
    size_t getY() const { return y; }
    size_t getX() const { return x; }
    bool moveTo(size_t _y, size_t _x)
    {
        if (_y < size && _x < size)
        {
            y = _y;
            x = _x;
            return true;
        }
        return false;
    }
    void userMove(std::istream &is = std::cin)
    {
        char input = getch();
        if (input == 'a')
            moveTo(y, x - 1);
        else if (input == 'w')
            moveTo(y - 1, x);
        else if (input == 'd')
            moveTo(y, x + 1);
        else if (input == 's')
            moveTo(y + 1, x);
    }

    bool isOnPosition(size_t _y, size_t _x) const
    {
        return y == _y && x == _x;
    }
};

#endif