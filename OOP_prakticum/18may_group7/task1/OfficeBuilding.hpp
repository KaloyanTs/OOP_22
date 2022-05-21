#ifndef __OFFICE_BUILDING_HPP
#define __OFFICE_BUILDING_HPP
#include "Office.hpp"
#include "ChillRoom.hpp"

class OfficeBuilding
{
    static const unsigned INIT_CAPACITY = 2;
    Room **rooms;
    size_t size, capacity;

    void clear();
    void expand(); 
    void copy(const OfficeBuilding &other);

public:
    OfficeBuilding();
    OfficeBuilding(const OfficeBuilding &other);
    OfficeBuilding &operator=(const OfficeBuilding &other);
    ~OfficeBuilding();

    OfficeBuilding &showRooms();
    OfficeBuilding &sortByCapacity();
    OfficeBuilding &addRoom(const Room &newRoom);
};

#endif