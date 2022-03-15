#include "Title.hpp"

Title::Title()
{
    value = NONE;
}

Title::Title(bool isA)
{
    if (isA)
        value = ASSISSTANT;
    else
        value = NONE;
}

void Title::print() const
{
    if (value == NONE)
        std::cout << "NONE";
    else if (value == ASSISSTANT)
        std::cout << "ASSISSTANT";
    else if (value == CHIEF_ASSISSTANT)
        std::cout << "CHIEF ASSISSTANT";
    else if (value == ASSOCIATE_PROFESSOR)
        std::cout << "ASSOCIATE PROFESSOR";
    else
        std::cout << "PROFESSOR";
}

void Title::elevate()
{
    if (value == NONE)
        return;
    else if (value == ASSISSTANT)
        value = CHIEF_ASSISSTANT;
    else if (value == CHIEF_ASSISSTANT)
        value = ASSOCIATE_PROFESSOR;
    else if (value == ASSOCIATE_PROFESSOR)
        value = PROFESSOR;
    else
        value = NONE;
}

bool Title::operator<(const Title &T) const
{
    if (value == PROFESSOR)
        return false;
    if (value == ASSOCIATE_PROFESSOR)
        return T.value == PROFESSOR;
    if (value == CHIEF_ASSISSTANT)
        return T.value != CHIEF_ASSISSTANT || T.value != ASSISSTANT;
    if (value == ASSISSTANT)
        return T.value != ASSISSTANT;
    return true;
}
bool Title::operator==(const Title &T) const
{
    return T.value == value;
}
