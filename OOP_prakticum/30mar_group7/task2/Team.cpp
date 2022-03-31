#include "Team.hpp"

Team::Team(std::istream &is) : wins(0), loses(0)
{
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
    {
        std::clog << i + 1 << ":\t";
        players[i] = new (std::nothrow) Player(is);
        assert(players[i]);
    }
    sort();
}

Team &Team::operator=(const Team &other)
{
    if (this != &other)
        return copy(other);
    return *this;
}

double Team::getTeamAvgScore() const
{
    double res = 0;
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
        res += players[i]->getScore();
    return res / PLAYERS_COUNT;
}

Team::~Team()
{
    clean();
}

void Team::clean()
{
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
        delete players[i];
}

void Team::sort()
{
    unsigned iMin = 0;
    for (unsigned i = 0; i < PLAYERS_COUNT - 1; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < PLAYERS_COUNT; ++j)
            if (!(*players[j], *players[iMin]))
                iMin = j;
        Player *tmp = players[iMin];
        players[iMin] = players[i];
        players[i] = tmp;
    }
}

Team::Team()
{
    wins = loses = 0;
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
        players[i] = nullptr;
}

Team::Team(const Team &other)
{
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
        players[i] = nullptr;
    copy(other);
}

Team &Team::copy(const Team &other)
{
    wins = other.wins;
    loses = other.loses;
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
    {
        delete[] players[i];
        players[i] = new Player(*other.players[i]);
        assert(players[i]);
    }
    return *this;
}

Team Team::operator+(const Team &other)
{
    Team res;
    unsigned resC = 0, thisC = 0, otherC = 0;
    while (resC < PLAYERS_COUNT)
        if (*players[thisC], *other.players[otherC])
        {
            res.players[resC] = new (std::nothrow) Player(*other.players[otherC++]);
            assert(res.players[resC++]);
        }
        else
        {
            res.players[resC] = new (std::nothrow) Player(*players[thisC++]);
            assert(res.players[resC++]);
        }
    --resC;
    while (resC)
    {
        if (res.players[resC]->number == res.players[resC - 1]->number)
            ++res.players[resC - 1]->number;
        --resC;
    }
    return res;
}

Team &game(Team &home, Team &away)
{
    double homeScore = home.getTeamAvgScore();
    double awayScore = away.getTeamAvgScore();
    if (homeScore < awayScore)
    {
        ++home.loses;
        ++away.wins;
        return away;
    }
    if (homeScore > awayScore)
    {
        ++home.wins;
        ++away.loses;
    }
    return home;
}

std::ostream &operator<<(std::ostream &os, const Team &T)
{
    os << "---------------------\n";
    for (unsigned i = 0; i < PLAYERS_COUNT; ++i)
        if (T.players[i])
            os << *T.players[i];
        else
            os << "<no player>\n";
    os << "---------------------\n";
    return os;
}