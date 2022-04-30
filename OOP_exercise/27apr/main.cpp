#include <iostream>

class A
{
    char a;

protected:
    void printA() const { std::cout << a << ' '; }

public:
    A(char _a = 'a') : a(_a) {}
};

class B : protected A
{
    char b;

protected:
public:
    B(char a = 'a', char _b = 'b') : A(a), b(_b) {}
    void printB() const
    {
        A::printA();
        std::cout << b << ' ';
    }
};

class Bcontainer : private B
{
    B b;
    void test() const { b.printB(); }
};

class C : public B
{
    char c;

protected:
public:
    C(char a = 'a', char b = 'b', char _c = 'c') : B(a, b), c(_c) {}
    void printC() const
    {
        B::printB();
        std::cout << c << ' ';
    }
};

int main()
{
    B varB;
    return 0;
}