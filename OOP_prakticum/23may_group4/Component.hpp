#ifndef __COMPONENT_HPP
#define __COMPONENT_HPP
#include <iostream>
#include <string>

class Component
{
    const std::string label;

public:
    Component(const std::string &_label) : label(_label) {}

    virtual ~Component(){};
    virtual Component *clone() const = 0;
    virtual double price() const = 0;
    void print(std::ostream &os) const;
};

#endif