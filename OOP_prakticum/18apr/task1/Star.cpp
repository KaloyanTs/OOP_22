#include "Star.hpp"

void AnalyzeStarData(const char *data)
{
    std::ifstream is(data, std::ios::in);
    if (!is.is_open())
        return;
    size_t starCount;
    is >> starCount;
    Star *arr = new Star[starCount];
    for (unsigned i = 0; i < starCount; ++i)
        is >> arr[i];
    is.close();

    float min = arr[0].getDistance();
    Star &minEl = arr[0];
    for (unsigned i = 1; i < starCount; ++i)
        if (changeMin(min, arr[i].getDistance()))
            minEl = arr[i];

    std::ofstream os(data, std::ios::out | std::ios::app);
    if (!os.is_open())
    {
        delete[] arr;
        return;
    }
    os << "\nThe closest star to us is located at "
       << minEl << " that is "
       << std::setprecision(2) << std::fixed
       << min << " lightyears away.\n";
    os.close();
    delete[] arr;
}

std::istream &operator>>(std::istream &is, Star &S)
{
    return is >> S.x >> S.y >> S.z;
}

bool rightSmaller(float f1, float f2, float EPS)
{
    return f1 - f2 >= EPS;
}

bool changeMin(float &min, float candidate)
{
    if (rightSmaller(min, candidate, 1e-6))
    {
        min = candidate;
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Star &S)
{
    return os << '(' << S.x << ',' << S.y << ',' << S.z << ')';
}