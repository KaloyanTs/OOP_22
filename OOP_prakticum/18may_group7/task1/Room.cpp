#include "Room.hpp"

Room::Room(const char *_name, bool _free, unsigned cap)
    : name(new char[strlen(_name) + 1]), free(_free), capacity(cap)
{
    strcpy(name, _name);
}

void Room::clear()
{
    delete[] name;
}

void Room::copy(const Room &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    free = other.free;
    capacity = other.capacity;
}

Room::Room(const Room &other)
    : name(nullptr)
{
    copy(other);
}

Room &Room::operator=(const Room &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Room::~Room()
{
    clear();
}

void Room::print() const
{
    std::cout << name << "has capacity " << capacity << " and is ";
    if (!free)
        std::cout << "not ";
    std::cout << "free";
}
