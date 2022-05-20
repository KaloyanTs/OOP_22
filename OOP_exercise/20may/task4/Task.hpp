#ifndef __TASK_HPP
#define __TASK_HPP
#include <iostream>
#include <cstring>

class Task
{
    static unsigned TASK_COUNTER;
    char *name;
    unsigned number;

    void clear();

protected:
    void copy(const Task &other);

public:
    Task(const char *_name = "no task");
    Task(const Task &other);
    Task &operator=(const Task &other);
    virtual ~Task();

    virtual bool finished() const = 0;
    virtual void doWork() = 0;
    virtual bool canStart() const = 0;
    virtual void print() const;
};

#endif