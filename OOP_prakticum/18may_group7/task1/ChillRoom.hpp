#ifndef __CHILL_ROOM_HPP
#define __CHILL_ROOM_HPP
#include "ConferenceRoom.hpp"

class ChillRoom : public ConferenceRoom
{
    char *team;

    void clear();
    void copy(const ChillRoom &other);

public:
    Room *clone() const { return new ChillRoom(*this); }
    ChillRoom(const char *name = "none", bool free = true,
              unsigned capacity = 0, bool hasProjector = false,
              const char *team = "any");
    ChillRoom(const ChillRoom &other);
    ChillRoom &operator=(const ChillRoom &other);
    ~ChillRoom();

    void print() const;
};

#endif