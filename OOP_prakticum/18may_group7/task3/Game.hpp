#ifndef __GAME_HPP
#define __GAME_HPP
#include "Firefly.hpp"
#include "Portal.hpp"
#include "Spider.hpp"
#include "Player.hpp"
#include <ctime>

class Game
{
    Cell ***board;
    size_t size;
    Player player;

    void clear();
    void copy(const Game &other);
    void showBoard() const;

public:
    Game(size_t n);
    Game(const Game &other);
    Game &operator=(const Game &other);
    ~Game();

    bool run(std::istream &is = std::cin, std::ostream &os = std::cout);
};

#endif