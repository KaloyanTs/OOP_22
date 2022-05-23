#ifndef __YES_NO_QUESTION_HPP
#define __YES_NO_QUESTION_HPP
#include "Question.hpp"

class YesNoQuestion : public Question
{
    const bool correct;
    bool answer;

public:
    YesNoQuestion(const char *text = "none", unsigned points = 0, bool c = false)
        : Question(text, points), correct(c) {}
    void ask();
    float grade() const;
    YesNoQuestion *clone() const { return new YesNoQuestion(*this); }
};

#endif