#include "YesNoQuestion.hpp"

void YesNoQuestion::ask()
{
    Question::ask();
    std::cin >> answer;
}

float YesNoQuestion::grade() const
{
    if (!isAnswered())
    {
        std::cerr << "Question not answered yet!\n";
        return 0;
    }
    return (answer == correct ? getPoints() : 0);
}