#include "DiscountTicket.hpp"

float DiscountTicket::DISCOUNT = 0.5;

DiscountTicket::DiscountTicket(const DiscountTicket &other)
    : Ticket(other), owner(nullptr)
{
    copy(other);
}

DiscountTicket &DiscountTicket::operator=(const DiscountTicket &other)
{
    if (this != &other)
    {
        //(Ticket *)this->copy(other);
        Ticket::copy(other);
        copy(other);
    }
    return *this;
}

DiscountTicket::~DiscountTicket()
{
    clear();
}

void DiscountTicket::print(std::ostream &os) const
{
    Ticket::print(os);
    os << " discounted to " << getPrice();
}

void DiscountTicket::copy(const DiscountTicket &other)
{
    Ticket::copy(other);
    clear();
    owner = new char[strlen(other.owner) + 1];
    strcpy(owner, other.owner);
}

void DiscountTicket::clear()
{
    delete[] owner;
}