#ifndef __EXAM_HPP
#define __EXAM_HPP
#include "MultipleChoiceQuestion.hpp"
#include "OpenQuestion.hpp"
#include "YesNoQuestion.hpp"

class Exam
{
    static const unsigned INIT_CAPACITY = 2;
    Question **qArr;
    size_t size, capacity;

    void clear();
    void expand();
    void copy(const Exam &other);

public:
    Exam();
    Exam(const Exam &other);
    Exam &operator=(const Exam &other);
    ~Exam();

    Exam &add(const Question &q);
    Exam &answer();
    float grade() const;
};

#endif