#ifndef __STAR_HPP
#define __STAR_HPP
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

struct Star
{
    float x, y, z;
    float getDistance() const { return sqrt(x * x + y * y + z * z); }
};

std::istream &operator>>(std::istream &is, Star &S);
std::ostream &operator<<(std::ostream &is, const Star &S);

void AnalyzeStarData(const char *);

bool leftSmaller(float f1, float f2, float EPS);

bool changeMin(float &max, float candidate);

#endif