#include "OfficeBuilding.hpp"

OfficeBuilding::OfficeBuilding()
    : size(0), capacity(INIT_CAPACITY), rooms(new Room *[INIT_CAPACITY])
{
}

void OfficeBuilding::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete rooms[i];
    delete[] rooms;
}

void OfficeBuilding::copy(const OfficeBuilding &other)
{
    clear();
    capacity = other.capacity;
    size = other.size;
    rooms = new Room *[capacity];
    for (unsigned i = 0; i < size; ++i)
        rooms[i] = other.rooms[i]->clone();
}

OfficeBuilding::OfficeBuilding(const OfficeBuilding &other)
    : size(0), rooms(nullptr)
{
    copy(other);
}

OfficeBuilding &OfficeBuilding::operator=(const OfficeBuilding &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

OfficeBuilding::~OfficeBuilding()
{
    clear();
}

OfficeBuilding &OfficeBuilding::showRooms()
{
    for (unsigned i = 0; i < size; ++i)
    {
        std::cout << i + 1 << ": ";
        rooms[i]->print();
        std::cout << '\n';
    }
    return *this;
}

OfficeBuilding &OfficeBuilding::sortByCapacity()
{
    unsigned iMin{0};
    Room *tmp{nullptr};
    for (unsigned i = 0; i < size - 1; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < size; ++j)
            if (*rooms[j] < *rooms[iMin])
                iMin = j;
        tmp = rooms[i];
        rooms[i] = rooms[iMin];
        rooms[iMin] = tmp;
    }
    return *this;
}

OfficeBuilding &OfficeBuilding::addRoom(const Room &newRoom)
{
    if (size == capacity)
        expand();
    rooms[size++] = newRoom.clone();
    return *this;
}

void OfficeBuilding::expand()
{
    capacity <<= 1;
    Room **newArr = new Room *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = rooms[i];
    delete[] rooms;
    rooms = newArr;
}
