#ifndef __OPEN_QUESTION_HPP
#define __OPEN_QUESTION_HPP
#include "Question.hpp"

class OpenQuestion : public Question
{
    char *userAnswer;

    void clear();
    void copy(const OpenQuestion &other);

public:
    OpenQuestion(const char *t = "none", unsigned points = 0)
        : Question(t, points),
          userAnswer(nullptr) {}
    OpenQuestion(const OpenQuestion &other);
    OpenQuestion &operator=(const OpenQuestion &other);
    ~OpenQuestion();

    void ask();
    float grade() const;
    OpenQuestion *clone() const { return new OpenQuestion(*this); }
};

#endif