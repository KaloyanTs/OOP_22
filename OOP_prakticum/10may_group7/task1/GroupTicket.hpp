#ifndef __GROUP_TICKET_HPP
#define __GROUP_TICKET_HPP
#include "Ticket.hpp"

class GroupTicket : public Ticket
{
    static const unsigned DISCOUNT_PER_PERSON = 2;
    unsigned groupCount;

public:
    GroupTicket(const char *n = "no show", unsigned p = 0,
                unsigned gC = 1)
        : Ticket(n, p), groupCount(gC) {}

    void print(std::ostream &os = std::cout) const;
    unsigned getCount() const { return groupCount; }
    unsigned getPrice() const;
};

unsigned calculateTotalPrice(Ticket **arr, unsigned size);

#endif