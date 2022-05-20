#include "Exam.hpp"

void Exam::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete qArr[i];
    delete[] qArr;
}

void Exam::copy(const Exam &other)
{
    clear();
}

Exam::Exam(const Exam &other)
    : qArr(nullptr), size(0)
{
    copy(other);
}

Exam &Exam::operator=(const Exam &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Exam::~Exam()
{
    clear();
}

Exam &Exam::add(const Question &q)
{
    if (size == capacity)
        expand();
    qArr[size++] = q.clone();
    return *this;
}

Exam &Exam::answer()
{
    for (unsigned i = 0; i < size; ++i)
        qArr[i]->ask();
    return *this;
}

float Exam::grade() const
{
    float res = 0;
    for (unsigned i = 0; i < size; ++i)
        res += qArr[i]->grade();
    return res;
}

void Exam::expand()
{
    capacity <<= 1;
    Question **newArr = new Question *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = qArr[i];
    delete[] qArr;
    qArr = newArr;
}

Exam::Exam()
    : qArr(new Question *[INIT_CAPACITY]), capacity(INIT_CAPACITY), size(0)
{
}