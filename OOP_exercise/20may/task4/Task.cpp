#include "Task.hpp"

unsigned Task::TASK_COUNTER = 0;

Task::Task(const char *_name)
    : name(new char[strlen(_name) + 1]), number(++TASK_COUNTER)
{
    strcpy(name, _name);
}

void Task::print() const
{
    std::cout << number << ": " << name;
}

void Task::clear()
{
    delete[] name;
}

void Task::copy(const Task &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Task::Task(const Task &other)
    : name(nullptr), number(++TASK_COUNTER)
{
    copy(other);
}

Task &Task::operator=(const Task &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Task::~Task()
{
    --TASK_COUNTER;
    clear();
}