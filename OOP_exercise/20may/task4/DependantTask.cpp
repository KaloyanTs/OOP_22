#include "DependantTask.hpp"

void DependantTask::doWork()
{
    done = canStart();
}

bool DependantTask::canStart() const
{
    return !done && priority.finished();
}

void DependantTask::print() const
{
    Task::print();
    std::cout << "\n\tdependant of:\n\t";
    if (this != &priority)
        priority.print();
    else
        Task::print();
}
