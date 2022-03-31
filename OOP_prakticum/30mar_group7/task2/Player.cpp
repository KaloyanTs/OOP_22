#include "Player.hpp"

Player Player::operator++()
{
    Player tmp = *this;
    ++score;
    return tmp;
}

Player &Player::operator+(double add)
{
    score += add;
    return *this;
}

Player &Player::operator++(int a)
{
    if (a)
        score += a;
    else
        ++score;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &P)
{
    return os << "Number: " << P.getNumber()
              << "\tScore: " << P.getScore() << '\n';
}

std::istream &operator>>(std::istream &is, Player &P)
{
    return is >> P.number >> P.score;
}