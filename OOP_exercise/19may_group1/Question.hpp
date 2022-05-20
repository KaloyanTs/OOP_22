#ifndef __QUESTION_HPP
#define __QUESTION_HPP
#include <iostream>
#include <cstring>

class Question
{
    char *text;
    unsigned points;
    bool answered;

    void clear();

protected:
    void copy(const Question &other);

public:
    Question(const char *t = "none", unsigned p = 0)
        : text(new char[strlen(t) + 1]), points(p), answered(false)
    {
        strcpy(text, t);
    }
    Question(const Question &other);
    Question &operator=(const Question &other);
    virtual ~Question();

    unsigned getPoints() const { return points; }
    const char *getQ() const { return text; }
    bool isAnswered() const { return answered; }

    virtual void ask();
    virtual float grade() const = 0;
    virtual Question *clone() const = 0;
};

#endif