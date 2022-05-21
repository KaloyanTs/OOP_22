#ifndef __CONFERENCE_ROOM_HPP
#define __CONFERENCE_ROOM_HPP
#include "Room.hpp"

class ConferenceRoom : public Room
{
    bool hasProjector;

public:
    Room *clone() const { return new ConferenceRoom(*this); }
    ConferenceRoom(const char *name = "none", bool free = true,
                   unsigned cap = 0, bool proj = false);

    void print() const;
};

#endif