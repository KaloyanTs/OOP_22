#include "Configuration.hpp"

Configuration::Configuration()
    : arr(std::vector<const Component *>())
{
}

void Configuration::insert(const Component *c)
{
    /*
    for (const Component *ptr : arr)
        if (typeid(*ptr).hash_code() == typeid(*c).hash_code())
        {
            std::cerr << "Such part already inserted!\n";
            return;
        }
    */
    arr.push_back(c);
}

double Configuration::price() const
{
    double res = 0;
    for (const Component *c : arr)
        res += c->price();
    return res;
}

const Component &Configuration::operator[](size_t index) const
{
    return *arr[index];
}

Configuration::~Configuration()
{
    for (unsigned i = 0; i < arr.size(); ++i)
        delete arr[i];
}

std::ostream &operator<<(std::ostream &os, const Configuration &C)
{
    unsigned i = 0;
    for (size_t i = 0; i < C.size(); i++)
    {
        os << i + 1 << ": ";
        C[i].print(os);
        os << '\n';
    }
    return os << "Total price: " << C.price();
}