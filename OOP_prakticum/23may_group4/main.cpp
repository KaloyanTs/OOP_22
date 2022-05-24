#include <iostream>
#include "CPU.hpp"
#include "Memory.hpp"
#include "Configuration.hpp"

Component *create_component()
{
    std::string type;
    std::cout << "What component do you want?\n";
    std::cout << "CPU\nmemory\n";
    std::cin >> type;
    if (type == "CPU")
    {
        std::string label;
        unsigned short cores;
        unsigned short clockSpeed;
        std::cin >> label >> cores >> clockSpeed;
        return new CPU(label, cores, clockSpeed);
    }
    else if (type == "memory")
    {
        std::string label;
        unsigned short capacity;
        std::cin >> label >> capacity;
        return new Memory(label, capacity);
    }
    return nullptr;
}

Configuration *create_configuration()
{
    Configuration *res = new Configuration;
    size_t count;
    std::clog << "Enter count of components: ";
    std::cin >> count;
    Component *buf;
    for (size_t i = 0; i < count; i++)
    {
        buf = create_component();
        if (buf)
            res->insert(buf);
        else
        {
            delete res;
            return nullptr;
        }
    }
    return res;
}

int main()
{
    Configuration *c = create_configuration();
    std::clog << *c << '\n';
    delete c;
    return 0;
}