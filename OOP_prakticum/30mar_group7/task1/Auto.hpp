#ifndef __AUTO_HPP
#define __AUTO_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const char *const NOT_INIT_MESSAGE = "<unknown>";
const size_t INPUT_MAX = 32;

class Auto
{
    char *id, *model, *owner;
    unsigned year;
    void copy(const Auto &other);
    void clean();

public:
    Auto() : id(nullptr), owner(nullptr), model(nullptr), year(0) {}
    Auto(const char *_id, const char *_m, unsigned _year, const char *_owner);
    Auto(const Auto &other);
    Auto &operator=(const Auto &other);
    const char *getID() const { return id; }
    const char *getModel() const { return model; }
    const char *getOwner() const { return owner; }
    unsigned getYear() const { return year; }
    std::ostream &print(std::ostream &os) const;
    bool operator<(const Auto &other) { return year < other.year; }
    ~Auto();
    friend std::istream &operator>>(std::istream &is, Auto &A);
};

std::ostream &operator<<(std::ostream &os, const Auto &A);

#endif