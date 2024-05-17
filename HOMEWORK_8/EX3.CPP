#include <iostream>

void printFromBiggerToSmallerByCycle(int count)
{
    std::cout<<"From Bigger to Smaller by Cycle:\n";
    int number = count;
    for(int i = 0;i < count; i++)
    {
        std::cout<<number<<std::endl;;
        number--;
    }
}

void printFromSmallerToBiggerByCycle(int count)
{
    std::cout<<"From Smaller to Bigger by Cycle:\n";
    for(int i = 1;i <= count; i++)
    {
        std::cout<<i<<std::endl;;
    }
}

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

int main()
{
    int count;
    std::cout<<"Enter your number: ";
    std::cin>>count;

    printFromBiggerToSmallerByCycle(count);

    printFromSmallerToBiggerByCycle(count);

    std::cout<<"From Bigger to Smaller by Recursion:\n";

    printFromBiggerToSmallerByRecursion(count);

    std::cout<<"From Smaller to Bigger by Recursion:\n"; 

    printFromSmallerToBiggerByRecursion(count);
}