#pragma once
const unsigned NAME_MAX = 16;

class Alcohol
{
    unsigned long price;
    char *name, *taste;

public:
    Alcohol();
    Alcohol(const char *_name, unsigned long _price);
    void read();
    const char *getName() const;
    unsigned long getPrice() const;
    bool areSame(const Alcohol &b) const;
    void setPrice(unsigned long _price);
    void setName(const char *_name);
    void print() const;
    ~Alcohol();
};