#include <iostream>
#include "MultipleChoiceQuestion.hpp"
#include "YesNoQuestion.hpp"
#include "OpenQuestion.hpp"
#include "Exam.hpp"

int main()
{
    PossibleAnswer Answers[] =
        {
            PossibleAnswer("2", true),
            PossibleAnswer("4", false),
            PossibleAnswer("5", true),
            PossibleAnswer("9", false)};
    PossibleAnswer *q1Answers[] =
        {&Answers[0], &Answers[1], &Answers[2], &Answers[3]};
    MultipleChoiceQuestion q1("Which of these numbers are prime?", 10, q1Answers, 4);
    YesNoQuestion q2("Water turns into ice at 0 degrees Celcius.", 20, true);
    OpenQuestion q3("When was the siege of Vienna?", 15); // 1529 correct

    Exam e;
    e.add(q1);
    e.add(q2);
    e.add(q3);
    e.answer();
    float res = e.grade();
    std::cout << "Final result: " << res << '\n';
    return 0;
}