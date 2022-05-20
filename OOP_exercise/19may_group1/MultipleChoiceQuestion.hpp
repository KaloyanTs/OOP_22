#ifndef __MULTIPLE_CHOICE_QUESTION_HPP
#define __MULTIPLE_CHOICE_QUESTION_HPP
#include "Question.hpp"
#include "PossibleAnswer.hpp"
#include <cassert>

class MultipleChoiceQuestion : public Question
{
    const PossibleAnswer **Qanswers;
    size_t count;

    unsigned *answers;
    size_t AnsCount;

    void clear();
    void copy(const MultipleChoiceQuestion &other);

public:
    MultipleChoiceQuestion(const char *text = "none", unsigned points = 0,
                           PossibleAnswer **ans = nullptr,
                           size_t c = 0);
    MultipleChoiceQuestion(const MultipleChoiceQuestion &other);
    MultipleChoiceQuestion &operator=(const MultipleChoiceQuestion &other);
    ~MultipleChoiceQuestion();

    void ask();
    float grade() const;
    Question *clone() const { return new MultipleChoiceQuestion(*this); }
};

#endif