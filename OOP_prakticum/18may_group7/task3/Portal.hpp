#ifndef __PORTAL_HPP
#define __PORTAL_HPP
#include "Player.hpp"
#include "Cell.hpp"

class Portal : public Cell
{
public:
    Cell *clone() const { return new Portal(*this); }
    void print(std::ostream &os = std::cout) const
    {
        os << (visible ? '^' : '?');
    }
    bool action(Cell *up, Cell *right, Cell *down, Cell *left, Player &p) const
    {
        std::clog << "Portal cell\n";
        p.moveTo(0, 0);
        return true;
    }
};

#endif