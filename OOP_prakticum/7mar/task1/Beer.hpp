#pragma once
const unsigned NAME_MAX = 128;

class Beer
{
    char brand[NAME_MAX];
    unsigned quantity;
    void init(const char *_n, unsigned _q);

public:
    Beer();
    Beer(const char *_brand, unsigned _q);
    const char *getBrand() const;
    unsigned getQuantity() const;
    void setBrand(const char *_name);
    void setQuantity(unsigned _q);
    void add(const Beer &b);
    void print() const;
    bool contains(const char *) const;
};