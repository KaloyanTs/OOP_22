#include "Matrix.hpp"

Matrix::Matrix(const char *filePath)
{
    std::ifstream ifs;
    ifs.open(filePath);
    assert(ifs.is_open());
    ifs >> size;
    board = new (std::nothrow) Point **[size];
    int x, y;
    char color[COLOR_MAX];
    for (unsigned i = 0; i < size; ++i)
    {
        board[i] = new Point *[size];
        assert(board[i]);
        for (unsigned j = 0; j < size; ++j)
        {
            ifs >> x >> y >> color;
            board[i][j] = new Point(x, y, color);
            assert(board[i][j]);
        }
    }
    ifs.close();
}

Matrix &Matrix::write(const char *filePath)
{
    std::ofstream ofs;
    ofs.open(filePath);
    assert(ofs.is_open());
    ofs << size << '\n';
    for (unsigned i = 0; i < size; ++i)
        for (unsigned j = 0; j < size; ++j)
            ofs << board[i][j]->x << '\t' << board[i][j]->y << '\t' << board[i][j]->color << '\n';
    ofs.close();
    return *this;
}

Matrix &Matrix::changeRowColor(unsigned row, const char *newColor)
{
    for (unsigned col = 0; col < size; ++col)
        board[row][col]->changeColor(newColor);
    return *this;
}

Matrix &Matrix::changeColumnColor(unsigned col, const char *newColor)
{
    for (unsigned row = 0; row < size; ++row)
        board[row][col]->changeColor(newColor);
    return *this;
}

Matrix &Matrix::changePointColor(unsigned row, unsigned col, const char *newColor)
{
    board[row][col]->changeColor(newColor);
    return *this;
}

Matrix &Matrix::clearColors()
{
    for (unsigned row = 0; row < size; ++row)
        changeRowColor(row);
    return *this;
}

void Matrix::clear()
{
    for (unsigned i = 0; i < size; ++i)
    {
        for (unsigned j = 0; j < size; ++j)
            delete board[i][j];
        delete[] board[i];
    }
    delete[] board;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

void Matrix::copy(const Matrix &other)
{
    clear();
    size = other.size;
    board = new Point **[size];
    assert(board);
    for (unsigned i = 0; i < size; ++i)
    {
        board[i] = new Point *[size];
        assert(board[i]);
        for (unsigned j = 0; j < size; ++j)
        {
            board[i][j] = new Point(*other.board[i][j]);
            assert(board[i][j]);
        }
    }
}
