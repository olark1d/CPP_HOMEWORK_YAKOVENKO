#include <iostream>
#include "RecursiveFunctions.h"

void printFromBiggerToSmallerByRecursion(int count)
{
    if(count < 1)
        return;

    std::cout<<count<<std::endl;
    printFromBiggerToSmallerByRecursion(count - 1);
}

void printFromSmallerToBiggerByRecursion(int count)
{
    if (count < 1)
        return;

    printFromSmallerToBiggerByRecursion(count - 1);
    std::cout << count << std::endl;
}
