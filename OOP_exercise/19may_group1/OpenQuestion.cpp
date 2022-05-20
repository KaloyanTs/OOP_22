#include "OpenQuestion.hpp"

OpenQuestion::OpenQuestion(const OpenQuestion &other)
    : Question(other), userAnswer(nullptr)
{
    copy(other);
}

OpenQuestion &OpenQuestion::operator=(const OpenQuestion &other)
{
    if (this != &other)
    {
        Question::copy(other);
        copy(other);
    }
    return *this;
}

OpenQuestion::~OpenQuestion()
{
    clear();
}

void OpenQuestion::ask()
{
    delete[] userAnswer;
    Question::ask();
    unsigned length;
    std::cin >> length;
    std::cin.get();
    userAnswer = new char[length + 1];
    std::cin.getline(userAnswer, length + 1);
}

float OpenQuestion::grade() const
{
    if (!isAnswered())
    {
        std::cerr << "Question not answered yet!\n";
        return 0;
    }
    std::cout << getQ() << '\n'
              << userAnswer << '\n';
    unsigned percentage;
    std::cin >> percentage;
    return (float)getPoints() * percentage / 100;
}

void OpenQuestion::clear()
{
    delete[] userAnswer;
}

void OpenQuestion::copy(const OpenQuestion &other)
{
    clear();
    userAnswer = (other.userAnswer
                      ? new char[strlen(other.userAnswer) + 1]
                      : nullptr);
    if (userAnswer)
        strcpy(userAnswer, other.userAnswer);
}