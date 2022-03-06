#pragma once
const unsigned BRAND_MAX = 16;
const unsigned TASTE_MAX = 16;

class Shisha
{
    unsigned long price;
    char *brand, *taste;

public:
    Shisha();
    Shisha(const char *_brand, unsigned long _price, const char *_taste);
    void read();
    const char *getBrand() const;
    const char *getTaste() const;
    unsigned long getPrice() const;
    void setPrice(unsigned long _price);
    bool areSame(const Shisha &b) const;
    void setBrand(const char *_brand);
    void setTaste(const char *_taste);
    void print() const;
    ~Shisha();
};