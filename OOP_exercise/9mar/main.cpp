#include <iostream>
#include "Polynomial.hpp"

int main()
{
    Polynomial p1, p2;
    p1.fromString("5x^0 + 4x^2 - 1x^1");
    p2.fromString("5x^4 + 2x^2 + 1x^1");
    Polynomial p3 = p1 + p2;
    return 0;
}