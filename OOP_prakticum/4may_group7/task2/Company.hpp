#ifndef __COMPANY_HPP
#define __COMPANY_HPP
#include "Worker.hpp"
const size_t INIT_CAPACITY = 2;

class Company
{
    Worker **workers;
    size_t size, capacity;

    void copy(const Company &other);
    void expand();
    void clear();

public:
    Company() : workers(new Worker *[INIT_CAPACITY]), size(0), capacity(INIT_CAPACITY) {}
    Company(const Company *other);
    Company &operator=(const Company &other);
    ~Company();

    void addWorker(const Worker &W);

    bool isInCompany(const char *name) const;
    void showWorkerInfo(const char *name, std::ostream &os = std::cout) const;

    void print(std::ostream &os = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const Company &C);

#endif