#include "ChillRoom.hpp"

void ChillRoom::clear()
{
    delete[] team;
}

void ChillRoom::copy(const ChillRoom &other)
{
    clear();
    team = new char[strlen(other.team) + 1];
    strcpy(team, other.team);
}

ChillRoom::ChillRoom(
    const char *name, bool free,
    unsigned capacity,
    bool hasProjector,
    const char *_team)
    : ConferenceRoom(name, free, capacity, hasProjector),
      team(new char[strlen(_team) + 1])
{
    strcpy(team, _team);
}

ChillRoom::ChillRoom(const ChillRoom &other)
    : ConferenceRoom(other), team(nullptr)
{
    copy(other);
}

ChillRoom &ChillRoom::operator=(const ChillRoom &other)
{
    if (this != &other)
    {
        //(ConferenceRoom *)this->copy(other);  ???????
        ConferenceRoom::copy(other);
        copy(other);
    }
    return *this;
}

ChillRoom::~ChillRoom()
{
    clear();
}

void ChillRoom::print() const
{
    ConferenceRoom::print();
    std::cout << "\ncan be used by " << team;
}
