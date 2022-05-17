#include "GroupTicket.hpp"

void GroupTicket::print(std::ostream &os) const
{
    Ticket::print(os);
    os << " for " << groupCount
       << " people dicounted to " << getPrice();
}

unsigned calculateTotalPrice(Ticket **arr, unsigned size)
{
    unsigned s = 0;
    for (unsigned i = 0; i < size; ++i)
        s += arr[i]->getPrice();
    return s;
}

unsigned GroupTicket::getPrice() const
{
    int res = Ticket::getPrice() - groupCount * GroupTicket::DISCOUNT_PER_PERSON;
    if (res >= 0)
        return res;
    return 0;
}