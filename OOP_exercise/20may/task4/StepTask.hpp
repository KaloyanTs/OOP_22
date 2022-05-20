#ifndef __STEP_TASK_HPP
#define __STEP_TASK_HPP
#include "Task.hpp"

class StepTask : public Task
{
    const unsigned stepsNeeded;
    unsigned stepCounter;

public:
    StepTask(const char *name, unsigned steps = 0)
        : Task(name), stepsNeeded(steps), stepCounter(0) {}

    bool finished() const { return stepCounter >= stepsNeeded; }
    void doWork();
    bool canStart() const { return stepCounter < stepsNeeded; }
};

#endif