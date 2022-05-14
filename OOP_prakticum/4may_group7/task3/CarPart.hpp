#ifndef __CARPART_HPP
#define __CARPART_HPP
#include <iostream>
#include <cstring>

class CarPart
{
    static unsigned ID_COUNTER;
    unsigned ID;
    char *manifacturer;
    char *description;

    void clear();

protected:
    void copy(const CarPart &other);

public:
    CarPart(const char *m = "unknown", const char *d = "none.")
        : manifacturer(new char[strlen(m) + 1]), description(new char[strlen(d) + 1])
    {
        ID = ++ID_COUNTER;
        strcpy(manifacturer, m);
        strcpy(description, d);
    }
    CarPart(const CarPart &other);
    CarPart &operator=(const CarPart &other);
    virtual ~CarPart();

    virtual void print(std::ostream &os = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const CarPart &cP);

#endif