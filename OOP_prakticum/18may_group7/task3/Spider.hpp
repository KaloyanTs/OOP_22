#ifndef __SPIDER_HPP
#define __SPIDER_HPP
#include "Cell.hpp"

class Spider : public Cell
{
public:
    Cell *clone() const { return new Spider(*this); }
    void print(std::ostream &os = std::cout) const
    {
        os << (visible ? 'x' : '?');
    }
    bool action(Cell *up, Cell *right, Cell *down, Cell *left, Player &) const
    {
        std::clog << "Spider cell\n";
        return false;
    }
};

#endif