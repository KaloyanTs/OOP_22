#ifndef __WORKER_HPP
#define __WORKER_HPP
#include <iostream>
#include <cstring>

class Worker
{
    char *name;
    unsigned age, months, salary;

    void clear();

protected:
    void copy(const Worker &other);

public:
    Worker(const char *n = "unknown", unsigned a = 0,
           unsigned m = 0, unsigned s = 0)
        : name(new char[strlen(n) + 1]), age(a), months(m), salary(s)
    {
        strcpy(name, n);
    }
    Worker(const Worker &other);
    Worker &operator=(const Worker &other);
    virtual ~Worker();

    virtual void print(std::ostream &os = std::cout, unsigned level = 0) const;
    virtual Worker *clone() const { return new Worker(*this); }

    bool operator==(const Worker &other) const;
};

std::ostream &operator<<(std::ostream &os, const Worker &W);

#endif