#ifndef __POSSIBLE_ANSWER_HPP
#define __POSSIBLE_ANSWER_HPP
#include <iostream>
#include <cstring>

class PossibleAnswer
{
    char *answer;
    bool correct;

    void clear();
    void copy(const PossibleAnswer &other);

public:
    PossibleAnswer(const char *a = "none", bool isCorrect = false);
    PossibleAnswer(const PossibleAnswer &other);
    PossibleAnswer &operator=(const PossibleAnswer &other);
    ~PossibleAnswer();

    bool isCorrect() const { return correct; }
    const char *showText() const { return answer; }
};

#endif