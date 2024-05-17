#include <iostream>
#include "RecursiveFunctions.h"

void printFromBiggerToSmallerByRecursion(int count)
{
    if(count < 1)
        return;

    std::cout<<count<<std::endl;
    printFromBiggerToSmallerByRecursion(count - 1);
}

int number = 1;
void printFromSmallerToBiggerByRecursion(int count)
{
    if(number > count)
        return;

    std::cout<<number<<std::endl;
    number++;
    printFromSmallerToBiggerByRecursion(count);
}
