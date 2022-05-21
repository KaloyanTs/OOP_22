#include "Game.hpp"

void Game::clear()
{
    for (unsigned i = 0; i < size; ++i)
    {
        for (unsigned j = 0; j < size; ++j)
            delete board[i][j];
        delete[] board[i];
    }
    delete[] board;
}

void Game::copy(const Game &other)
{
    clear();
    player = other.player;
    size = other.size;
    board = new Cell **[size];
    for (unsigned i = 0; i < size; ++i)
    {
        board[i] = new Cell *[size];
        for (unsigned j = 0; j < size; ++j)
            board[i][j] = other.board[i][j]->clone();
    }
}

Game::Game(const Game &other)
    : size(0), board(nullptr), player(0)
{
    copy(other);
}

Game &Game::operator=(const Game &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Game::~Game()
{
    clear();
}

bool Game::run(std::istream &is, std::ostream &os)
{
    size_t x = player.getX();
    size_t y = player.getY();
    board[y][x]->show();
    Cell *up{nullptr}, *right{nullptr},
        *down{nullptr}, *left{nullptr};
    while (!player.isOnPosition(size - 1, size - 1) &&
           board[y][x]->action(up, right, down, left, player))
    {
        showBoard();
        player.userMove();
        std::cout << "\x1B[2J\x1B[H"; // fix
        x = player.getX();
        y = player.getY();
        up = (y > 0 ? board[y - 1][x] : nullptr);
        right = (x < size - 1 ? board[y][x + 1] : nullptr);
        down = (y < size - 1 ? board[y + 1][x] : nullptr);
        left = (x > 0 ? board[y][x - 1] : nullptr);
        board[y][x]->show();
    }
    showBoard();
    return player.isOnPosition(size - 1, size - 1);
}

Game::Game(size_t n)
    : player(n), size(n), board(new Cell **[n])
{
    srand(time(NULL));
    Cell *arr[] =
        {
            new Cell,
            new Spider,
            new Portal,
            new Firefly};
    size_t count = sizeof(arr) / sizeof(*arr);

    for (unsigned i = 0; i < size; ++i)
    {
        board[i] = new Cell *[n];
        for (unsigned j = 0; j < size; ++j)
            if ((i || j) && (i != size - 1 || j <= size - 1))
            {
                unsigned type = rand() % (2 * count - 1);
                if (type >= count)
                    type = 0;
                board[i][j] = arr[type]->clone();
            }
            else
                board[i][j] = arr[0]->clone();
    }

    for (unsigned i = 0; i < count; ++i)
        delete arr[i];
}

void Game::showBoard() const
{
    for (unsigned i = 0; i < 2 * size; ++i)
        std::cout << '-';
    std::cout << '\n';
    for (unsigned i = 0; i < size; ++i)
    {
        for (unsigned j = 0; j < size; ++j)
        {
            board[i][j]->print();
            std::cout << (player.isOnPosition(i, j) ? 'o' : ' ');
        }

        std::cout << '\n';
    }
    for (unsigned i = 0; i < 2 * size; ++i)
        std::cout << '-';
    std::cout << '\n';
}
