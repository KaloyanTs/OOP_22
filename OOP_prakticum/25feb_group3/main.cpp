#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>

struct Complex
{
    double real = 0;
    double imaginary = 0;
    void init()
    {
        std::cin >> real >> imaginary;
    }
    void print() const
    {
        std::cout << std::fixed
                  << std::setprecision(2)
                  << real << " + " << imaginary << "i\n";
    }
};

void init(Complex &c)
{
    std::cin >> c.real >> c.imaginary;
}

void print(const Complex &c)
{
    std::cout << std::fixed
              << std::setprecision(2)
              << c.real << " + " << c.imaginary << "i\n";
}

void complexSum(const Complex &c1, const Complex &c2, Complex &c)
{
    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;
}

void complexDiff(const Complex &c1, const Complex &c2, Complex &c)
{
    c.real = c1.real - c2.real;
    c.imaginary = c1.imaginary - c2.imaginary;
}

void complexMul(const Complex &c1, const Complex &c2, Complex &c)
{
    c.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    c.imaginary = c1.imaginary * c2.real + c1.real * c2.imaginary;
}

double getLength(const Complex &c)
{
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

void complexDiv(const Complex &c1, const Complex &c2, Complex &c)
{
    double l = getLength(c2);
    assert(l);
    c.real = c1.real * c2.real + c1.imaginary * c2.imaginary;
    c.real /= l;
    c.imaginary = c1.imaginary * c2.real - c1.real * c2.imaginary;
    c.imaginary /= l;
}

Complex getAverage(const Complex *const *arr, size_t n)
{
    Complex av;
    av.real = av.imaginary = 0;
    for (unsigned i = 0; i < n; ++i)
        complexSum(*arr[i], av, av);
    av.real /= n;
    av.imaginary /= n;
    return av;
}

bool leftBeforeRight(const Complex &c1, const Complex &c2)
{
    return getLength(c1) <= getLength(c2);
}

void swapComplexPointers(const Complex *&c1, const Complex *&c2)
{
    const Complex *c = c1;
    c1 = c2;
    c2 = c;
}

void sortComplexArray(const Complex *arr, size_t n)
// want first argument to be const Complex **
{
    unsigned iMin = 0;
    const Complex *p1 = nullptr, *p2 = nullptr;
    for (unsigned i = 0; i < n; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < n; ++j)
            if (!leftBeforeRight(arr[iMin], arr[j]))
                iMin = j;
        p1 = arr + i;
        p2 = arr + iMin;
        swapComplexPointers(p1, p2);
    }
}

void printComplexArray(const Complex *const *arr, size_t n)
{
    for (unsigned i = 0; i < n; ++i)
    {
        std::cout << i << ": ";
        arr[i]->print();
    }
}

void deallocComplexArray(Complex **&arr, size_t &n)
{
    for (unsigned i = 0; i < n; ++i)
        delete arr[i];
    delete[] arr;
    arr = nullptr;
    n = 0;
}

int main()
{
    size_t N;
    std::cout << "Enter count of complex numbers: ";
    std::cin >> N;
    Complex **arr = new (std::nothrow) Complex *[N];
    if (!arr)
    {
        std::cout << "Not enough memory for array!\n";
        return 0;
    }
    for (unsigned i = 0; i < N; ++i)
    {
        arr[i] = new Complex;
        std::cout << "Enter complex number #" << i + 1 << ": ";
        arr[i]->init();
    }
    sortComplexArray(*arr, N);
    // invalid conversion from "Complex **" to "const Complex **"
    printComplexArray(arr, N);
    std::cout << "Average of all numbers is: ";
    getAverage(arr, N).print();
    deallocComplexArray(arr, N);
    return 0;
}