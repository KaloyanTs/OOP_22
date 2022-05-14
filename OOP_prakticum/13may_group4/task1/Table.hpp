#ifndef __TABLE_HPP
#define __TABLE_HPP
#include "Furniture.hpp"

enum TableType
{
    TABLE_NONE = 0,
    KITCHEN,
    HALL
};

std::ostream &operator<<(std::ostream &os, TableType t);

class Table : public Furniture
{
    TableType type;

public:
    Table(unsigned l, unsigned w, unsigned h, TableType t)
        : Furniture(l, w, h, 15), type(t) {}

    TableType getType() const { return type; }

    void print(std::ostream &os = std::cout) const;
    unsigned calculatePrice() const;
};

#endif