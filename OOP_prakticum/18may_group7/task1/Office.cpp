#include "Office.hpp"

Office::Office(const char *name, bool free, const char *_owner, unsigned cap)
    : Room(name, free, cap), owner(new char[strlen(_owner) + 1])
{
    strcpy(owner, _owner);
}

Office::Office(const Office &other)
    : Room(other), owner(nullptr)
{
    copy(other);
}

Office &Office::operator=(const Office &other)
{
    if (this != &other)
    {
        Room::copy(other);
        copy(other);
    }
    return *this;
}

Office::~Office()
{
    clear();
}

void Office::print() const
{
    Room::print();
    std::cout << " and is owned by " << owner;
}

void Office::clear()
{
    delete[] owner;
}

void Office::copy(const Office &other)
{
    clear();
    owner = new char[strlen(other.owner) + 1];
    strcpy(owner, other.owner);
}