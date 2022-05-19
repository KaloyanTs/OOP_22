#include <iostream>
#include "Constant.hpp"
#include "Operation.hpp"
#include "Input.hpp"

int main()
{
    // todo parser
    Input in;
    Constant c(5);
    Expression *arr[] = {
        &in,
        &c};
    Operation op1('+', arr, 2);

    Constant c2(7);
    Expression *arr2[] = {
        &in,
        &c2};
    Operation op2('+', arr2, 2);

    Expression *arr3[] =
        {
            &op1,
            &op2};
    Operation op3('/', arr3, 2);

    arr3[0] = &op3;
    arr3[1] = &op2;
    Operation op4('*', arr3, 2);
    std::cout << op4 << " = " << op4.value() << '\n';

    return 0;
}