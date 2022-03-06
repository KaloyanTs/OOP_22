#pragma once
const unsigned COLOR_MAX = 8;

class Balloon
{
    char *color;
    unsigned price;

public:
    Balloon();
    Balloon(const char *_color, unsigned _price);
    void print() const;
    void read();
    const char *getColor() const;
    unsigned getPrice() const;
    bool areSame(const Balloon &b) const;
    void setPrice(unsigned _price);
    void setColor(const char *_color);
    ~Balloon();
};