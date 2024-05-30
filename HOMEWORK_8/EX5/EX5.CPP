#include <iostream>
#include "CyclicFunctions.h"
#include "RecursiveFunctions.h"

int main()
{
    int count;
    std::cout << "Enter your number: ";
    std::cin >> count;

    printFromBiggerToSmallerByCycle(count);
    printFromSmallerToBiggerByCycle(count);

    std::cout << "From Bigger to Smaller by Recursion:\n";
    printFromBiggerToSmallerByRecursion(count);

    std::cout << "From Smaller to Bigger by Recursion:\n";
    printFromSmallerToBiggerByRecursion(count);

}