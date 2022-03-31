#ifndef __PLAYER_HPP
#define __PLAYER_HPP
#include <iostream>
#include <cstring>

class Player
{
    double score;
    unsigned number;

public:
    Player(unsigned _number = 0, double _score = 0) : number(_number), score(_score) {}
    Player(std::istream &is) { is >> *this; }
    Player operator++();
    Player &operator+(double add);
    Player &operator++(int a);
    double getScore() const { return score; }
    unsigned getNumber() const { return number; }
    bool operator<(const Player &right) const { return number < right.number; }
    friend bool operator,(const Player &p1, const Player &p2) { return p1.score < p2.score; }
    friend std::istream &operator>>(std::istream &is, Player &P);
    friend class Team;
};

std::ostream &operator<<(std::ostream &os, const Player &P);

#endif