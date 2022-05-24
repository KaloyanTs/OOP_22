#include <iostream>
#include <string>

struct Book
{
    std::string author;
    std::string name;
    int year;
    int pages;
    double rating;
};

template <typename T>
void selectionSort(T *arr, size_t size, bool (*less)(const T &, const T &))
{
    unsigned iMin = 0;
    for (unsigned i = 0; i < size - 1; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < size; ++j)
            if (less(arr[j], arr[iMin]))
                iMin = j;
        std::swap(arr[i], arr[iMin]);
    }
}

template <typename T>
void print(T *arr, size_t size)
{
    std::cout << "----------\n";
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << '\n';
    std::cout << "----------\n";
}

bool cmpInt(const int &a, const int &b)
{
    return b > a;
}

template <typename T>
size_t filter(T *arr, size_t size, T *out, bool (*pred)(const T &))
{
    T *outEnd = out;
    for (unsigned i = 0; i < size; ++i)
        if (pred(arr[i]))
            *outEnd++ = arr[i];
    return outEnd - out;
}

bool even(const int &a) { return a % 2 == 0; }

int main()
{
    int arr[] = {
        4,
        6,
        13,
        4,
        6,
        8,
        7};
    size_t count = sizeof(arr) / sizeof(*arr);
    selectionSort(arr, count, cmpInt);
    print(arr, count);
    print(arr, filter(arr, count, arr, even));
    return 0;
}