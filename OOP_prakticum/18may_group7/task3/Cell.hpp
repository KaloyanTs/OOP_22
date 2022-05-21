#ifndef __CELL_HPP
#define __CELL_HPP
#include "Types.hpp"
#include <iostream>

class Cell
{

protected:
    bool visible;

public:
    virtual Cell *clone() const { return new Cell(*this); }
    Cell() : visible(false) {}
    virtual ~Cell() {}

    virtual void print(std::ostream &os = std::cout) const { std::cout << (visible ? ' ' : '?'); }
    virtual bool action(Cell *up, Cell *right, Cell *down, Cell *left, Player &) const { return true; }
    bool show() { return (!visible && (visible = true)); }
    bool hide() { return (visible && (visible = false)); }
};

#endif