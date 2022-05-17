#include "Ticket.hpp"

void Ticket::copy(const Ticket &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    price = other.price;
}

Ticket::Ticket(const Ticket &other)
    : name(nullptr)
{
    copy(other);
}

Ticket &Ticket::operator=(const Ticket &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

void Ticket::print(std::ostream &os) const
{
    os << '\"' << name << "\" ticket at price " << price;
}

std::ostream &operator<<(std::ostream &os, const Ticket &T)
{
    T.print(os);
    return os;
}

void Ticket::clear()
{
    delete[] name;
}