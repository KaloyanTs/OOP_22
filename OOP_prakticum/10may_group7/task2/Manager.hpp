#ifndef __MANAGER_HPP
#define __MANAGER_HPP
#include "Worker.hpp"

class Manager : public Worker
{
    static const unsigned INIT_CAPACITY = 2;
    char *companyName;
    Worker **arr;
    size_t size, capacity;

    void clear();
    void expand();

protected:
    void copy(const Manager &other);

public:
    Manager(const char *name = "unknown", unsigned age = 0, unsigned months = 0, unsigned salary = 0,
            const char *n = "unknown")
        : arr(new Worker *[INIT_CAPACITY]), size(0), capacity(INIT_CAPACITY),
          Worker(name, age, months, salary),
          companyName(new char[strlen(n) + 1])
    {
        strcpy(companyName, n);
    }

    Manager(const Manager &other);
    Manager &operator=(const Manager &other);
    ~Manager();

    Manager &addWorker(const Worker &);

    void print(std::ostream &os = std::cout, unsigned level = 0) const;
    Worker *clone() const { return new Manager(*this); }
};

#endif