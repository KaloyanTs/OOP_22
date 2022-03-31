#ifndef __TEAM_HPP
#define __TEAM_HPP
#include "Player.hpp"
#include <cassert>
const size_t PLAYERS_COUNT = 11;

class Team
{
    Player *players[PLAYERS_COUNT];
    unsigned wins, loses;
    Team &copy(const Team &other);
    void clean();
    void sort();

public:
    Team();
    Team(const Team &other);
    Team &operator=(const Team &other);
    Team(std::istream &is);
    double getTeamAvgScore() const;
    Team operator+(const Team &other);
    friend Team &game(Team &home, Team &away);
    friend std::ostream &operator<<(std::ostream &os, const Team &T);
    ~Team();
};

#endif