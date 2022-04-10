#ifndef __MATRIX_HPP
#define __MATRIX_HPP
#include "Point.hpp"

class Matrix
{
    size_t size;
    Point ***board;
    void copy(const Matrix &other);
    void clear();

public:
    Matrix() : size(0), board(nullptr) {}
    Matrix(const char *filePath);
    Matrix(const Matrix &other) : board(nullptr) { copy(other); }
    Matrix &write(const char *filePath);
    Matrix &changeRowColor(unsigned row, const char *newColor = NO_COLOR);
    Matrix &changeColumnColor(unsigned col, const char *newColor = NO_COLOR);
    Matrix &changePointColor(unsigned, unsigned, const char *newColor = NO_COLOR);
    Matrix &clearColors();
    Matrix &operator=(const Matrix &other);
    friend std::ostream &operator<<(std::ostream &os, const Matrix &M);
    ~Matrix() { clear(); };
};

#endif