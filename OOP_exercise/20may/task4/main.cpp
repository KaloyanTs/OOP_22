#include <iostream>
#include "StepTask.hpp"
#include "DependantTask.hpp"

void completeAll(Task *arr[], int n)
{
    unsigned worked = 0;
    do
    {
        worked = 0;
        for (unsigned i = 0; i < n; ++i)
            if (arr[i]->canStart())
            {
                ++worked;
                arr[i]->doWork();
            }
    } while (worked);

    for (unsigned i = 0; i < n; ++i)
        if (!arr[i]->finished())
        {
            arr[i]->print();
            std::cout << '\n';
        }
}

int main()
{
    StepTask t1("Basic Task", 4);
    DependantTask t2("Need Basic Task", t1);
    DependantTask t3("Need depTask", t2);
    StepTask t5("Many steps", 10);
    DependantTask t4("need Many steps", t5);
    DependantTask t6("Impossible", t6);
    Task *arr[] =
        {
            &t1,
            &t2,
            &t3,
            &t4,
            &t5,
            &t6};
    completeAll(arr, 6);
    return 0;
}