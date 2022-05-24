#ifndef __CONFIGURATION_HPP
#define __CONFIGURATION_HPP
#include "CPU.hpp"
#include "Memory.hpp"
#include <vector>
#include <typeinfo>

class Configuration
{
    static const size_t INIT_SIZE = 1;
    std::vector<const Component *> arr;

    Configuration();
    void insert(const Component *c);

public:
    Configuration(const Configuration &other) = delete;
    double price() const;
    size_t size() const { return arr.size(); };

    const Component &operator[](size_t index) const;
    ~Configuration();
    friend Configuration *create_configuration();
};

std::ostream &operator<<(std::ostream &os, const Configuration &C);

#endif