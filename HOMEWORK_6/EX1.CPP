#include <iostream>

int main()
{
    int startNumber;
    int numbersCount;
    int stepNumber;

    std::cout<<"Enter start number, step number and the number of elements: ";
    std::cin>>startNumber>>stepNumber>>numbersCount;

    if(startNumber > 0 && stepNumber > 0 && numbersCount > 0)
    {
        std::cout<<"Arithmetic progression: \n";
        for(int i = 0; i < numbersCount; i++)
        {
            startNumber+=stepNumber;
            std::cout<<startNumber<<" ";
        }
    }
    else
    {
        std::cout<<"Invalid input!\n";
    }
}
