#include "Question.hpp"

void Question::clear()
{
    delete[] text;
}

void Question::copy(const Question &other)
{
    clear();
    text = new char[strlen(other.text) + 1];
    strcpy(text, other.text);
    points = other.points;
    answered = other.answered;
}

Question::Question(const Question &other)
    : text(nullptr)
{
    copy(other);
}

Question &Question::operator=(const Question &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Question::~Question()
{
    clear();
}

void Question::ask()
{
    answered = true;
    std::cout << text << '\n';
}
