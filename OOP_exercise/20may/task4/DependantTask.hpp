#ifndef __DEPENDANT_TASK_HPP
#define __DEPENDANT_TASK_HPP
#include "Task.hpp"

class DependantTask : public Task
{
    const Task &priority;
    bool done;

public:
    DependantTask(const char *name, const Task &otherTask)
        : Task(name), priority(otherTask), done(false) {}

    bool finished() const { return done; }
    void doWork();
    bool canStart() const;
    void print() const;
};

#endif