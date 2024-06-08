#include <iostream>
#include "CyclicFunctions.h"

void printFromBiggerToSmallerByCycle(int count)
{
    std::cout<<"From Bigger to Smaller by Cycle:\n";
    int number = count;
    for(int i = 0; i < count; i++)
    {
        std::cout<<number<<std::endl;
        number--;
    }
}

void printFromSmallerToBiggerByCycle(int count)
{
    std::cout<<"From Smaller to Bigger by Cycle:\n";
    for(int i = 1; i <= count; i++)
    {
        std::cout<<i<<std::endl;
    }
}
