#ifndef __TICKET_HPP
#define __TICKET_HPP
#include <iostream>
#include <cstring>

class Ticket
{
    char *name;
    unsigned price;

    void clear();

protected:
    void copy(const Ticket &other);

public:
    Ticket(const char *n = "no show", unsigned p = 0)
        : name(new char[strlen(n) + 1]), price(p) { strcpy(name, n); }

    virtual ~Ticket() { clear(); }
    Ticket(const Ticket &other);
    Ticket &operator=(const Ticket &other);

    virtual void print(std::ostream &os = std::cout) const;
    virtual unsigned getCount() const { return 1; }
    virtual unsigned getPrice() const { return price; }
    const char *getPerformance() const { return name; }
};

std::ostream &operator<<(std::ostream &os, const Ticket &T);

#endif