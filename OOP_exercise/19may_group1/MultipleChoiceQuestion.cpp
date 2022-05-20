#include "MultipleChoiceQuestion.hpp"

void MultipleChoiceQuestion::clear()
{
    for (unsigned i = 0; i < count; ++i)
        delete Qanswers[i];
    delete[] Qanswers;
    delete[] answers;
}

void MultipleChoiceQuestion::copy(const MultipleChoiceQuestion &other)
{
    clear();
    AnsCount = other.AnsCount;
    count = other.count;
    Qanswers = new const PossibleAnswer *[count];
    for (unsigned i = 0; i < count; ++i)
        Qanswers[i] = new const PossibleAnswer(*other.Qanswers[i]);
    answers = new unsigned[AnsCount];
    for (unsigned i = 0; i < AnsCount; ++i)
        answers[i] = other.answers[i];
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const char *text, unsigned points,
                                               PossibleAnswer **ans,
                                               size_t c)
    : Question(text, points),
      Qanswers(new const PossibleAnswer *[c]),
      count(c),
      AnsCount(0),
      answers(nullptr)
{
    for (unsigned i = 0; i < count; ++i)
        Qanswers[i] = new const PossibleAnswer(*ans[i]);
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion &other)
    : Question(other), Qanswers(nullptr), count(0), answers(nullptr), AnsCount(0)
{
    copy(other);
}

MultipleChoiceQuestion &MultipleChoiceQuestion::operator=(const MultipleChoiceQuestion &other)
{
    if (this != &other)
    {
        Question::copy(other);
        copy(other);
    }
    return *this;
}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{
    clear();
}

void MultipleChoiceQuestion::ask()
{
    Question::ask();
    if (!count)
        return;
    for (unsigned i = 0; i < count; ++i)
        std::cout << i + 1 << ": " << Qanswers[i]->showText() << '\n';
    std::cin >> AnsCount;
    delete[] answers;
    answers = new unsigned[AnsCount];
    for (unsigned i = 0; i < AnsCount; ++i)
    {
        std::cin >> answers[i];
        --answers[i];
        assert(answers[i] < count);
    }
}

float MultipleChoiceQuestion::grade() const
{
    if (!isAnswered())
    {
        std::cerr << "Question not answered yet";
        return 0;
    }
    unsigned CorrectCount = 0;
    for (unsigned i = 0; i < count; ++i)
        CorrectCount += Qanswers[i]->isCorrect();
    float perQuestion = (float)getPoints() / CorrectCount;
    float result = 0;
    for (unsigned i = 0; i < AnsCount; ++i)
        result += (Qanswers[answers[i]]->isCorrect() ? perQuestion : -perQuestion);
    return (result < 0 ? 0 : result);
}