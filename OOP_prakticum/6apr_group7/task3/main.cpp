#include <iostream>
#include "Matrix.hpp"
const size_t INPUT_MAX = 32;

bool cmd(Matrix *&M, char *command)
{
    if (!strcmp(command, "exit"))
        return false;
    if (!strcmp(command, "create"))
    {
        std::cin >> command;
        delete M;
        M = new Matrix(command);
        assert(M);
        return true;
    }
    assert(M);
    if (!strcmp(command, "save"))
    {
        std::cin >> command;
        M->write(command);
        return true;
    }
    if (!strcmp(command, "paint_row"))
    {
        unsigned row;
        std::cin >> row;
        std::cin >> command;
        M->changeRowColor(row, command);
        return true;
    }
    if (!strcmp(command, "paint_col"))
    {
        unsigned col;
        std::cin >> col;
        std::cin >> command;
        M->changeColumnColor(col, command);
        return true;
    }
    if (!strcmp(command, "paint_point"))
    {
        unsigned row, col;
        std::cin >> row >> col;
        std::cin >> command;
        M->changePointColor(row, col, command);
        return true;
    }
    if (!strcmp(command, "clear"))
    {
        M->clearColors();
        return true;
    }
    return false;
}

int main()
{
    Matrix *M{nullptr};
    char command[INPUT_MAX];
    do
    {
        std::cin >> command;
    } while (cmd(M, command));
    delete M;
    return 0;
}