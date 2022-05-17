#ifndef __DISCOUNT_TICKET_HPP
#define __DISCOUNT_TICKET_HPP
#include "Ticket.hpp"

class DiscountTicket : public Ticket
{
    static float DISCOUNT;
    char *owner;

    void clear();

protected:
    void copy(const DiscountTicket &other);

public:
    DiscountTicket(const char *n = "no show", unsigned p = 0,
                   const char *o = "no owner")
        : Ticket(n, p),
          owner(new char[strlen(o) + 1]) { strcpy(owner, o); }
    DiscountTicket(const DiscountTicket &other);
    DiscountTicket &operator=(const DiscountTicket &other);
    ~DiscountTicket();

    void print(std::ostream &os = std::cout) const;
    const char *getOwner() const { return owner; }
    unsigned getPrice() const { return DiscountTicket::DISCOUNT * Ticket::getPrice(); }
};

#endif