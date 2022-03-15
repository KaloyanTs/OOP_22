#ifndef __TITLE_HPP
#define __TITLE_HPP
#include <iostream>

class Title
{
    enum ScientificTitle
    {
        NONE,
        ASSISSTANT,
        CHIEF_ASSISSTANT,
        ASSOCIATE_PROFESSOR,
        PROFESSOR
    } value;

public:
    Title();
    Title(bool isA);
    unsigned getValue() const { return value; }
    void setValue(unsigned _v) { value = (ScientificTitle)_v; }
    void elevate();
    bool operator<(const Title &T) const;
    bool operator==(const Title &T) const;
    bool canElevate() const { return value != NONE && value != PROFESSOR; }
    void print() const;
};

#endif