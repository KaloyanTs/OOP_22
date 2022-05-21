#ifndef __FIREFLY_HPP
#define __FIREFLY_HPP
#include "Cell.hpp"

class Firefly : public Cell
{
public:
    Cell *clone() const { return new Firefly(*this); }
    void print(std::ostream &os = std::cout) const
    {
        os << (visible ? '*' : '?');
    }
    bool action(Cell *up, Cell *right, Cell *down, Cell *left, Player &p) const
    {
        std::clog << "Firefly cell\n";
        if (up)
            up->show();
        if (right)
            right->show();
        if (left)
            left->show();
        if (down)
            down->show();
        return true;
    }
};

#endif