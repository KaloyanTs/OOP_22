#ifndef __ROOM_HPP
#define __ROOM_HPP
#include <iostream>
#include <cstring>

class Room
{
    char *name;
    bool free;
    unsigned capacity;

    void clear();

protected:
    void copy(const Room &other);

public:
    virtual Room *clone() const = 0;
    Room(const char *_name = "none", bool free = true, unsigned cap = 0);
    Room(const Room &other);
    Room &operator=(const Room &other);
    virtual ~Room();

    virtual void print() const;

    bool freeRoom() { return (!free && (free = true)); }
    bool takeRoom() { return (free && !(free = false)); }

    bool operator<(const Room &other) { return capacity < other.capacity; }
};

#endif