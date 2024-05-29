#include <iostream>
#include "RecursiveFunctions.h"

void printFromBiggerToSmallerByRecursion(int count)
{
    if(count < 1)
        return;

    std::cout<<count<<std::endl;
    printFromBiggerToSmallerByRecursion(count - 1);
}

void printFromSmallerToBiggerByRecursion(int count, int number)
{
    if(number > count)
    return;

    std::cout<<number<<std::endl;
    printFromSmallerToBiggerByRecursion(count, number + 1);
}
