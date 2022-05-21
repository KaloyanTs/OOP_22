#ifndef __OFFICE_HPP
#define __OFFICE_HPP
#include "Room.hpp"

class Office : public Room
{
    char *owner;

    void clear();

protected:
    void copy(const Office &other);

public:
    Room *clone() const { return new Office(*this); }
    Office(const char *name = "none", bool free = true,
           const char *_owner = "none",
           unsigned cap = 0);
    Office(const Office &other);
    Office &operator=(const Office &other);
    ~Office();

    void print() const;
};

#endif