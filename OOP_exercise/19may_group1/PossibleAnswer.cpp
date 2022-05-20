#include "PossibleAnswer.hpp"

PossibleAnswer::PossibleAnswer(const char *a, bool isCorrect)
    : answer(new char[strlen(a) + 1]), correct(isCorrect)
{
    strcpy(answer, a);
}

void PossibleAnswer::clear()
{
    delete[] answer;
}

void PossibleAnswer::copy(const PossibleAnswer &other)
{
    clear();
    correct = other.correct;
    answer = new char[strlen(other.answer) + 1];
    strcpy(answer, other.answer);
}

PossibleAnswer::PossibleAnswer(const PossibleAnswer &other)
    : answer(nullptr)
{
    copy(other);
}

PossibleAnswer &PossibleAnswer::operator=(const PossibleAnswer &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

PossibleAnswer::~PossibleAnswer()
{
    clear();
}
