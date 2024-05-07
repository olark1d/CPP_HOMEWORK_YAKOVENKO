#include <iostream>

int main()
{
    int startNumber;
    int endNumber;
    int stepNumber;

    std::cout<<"Enter start number, step number and end number: ";
    std::cin>>startNumber>>stepNumber>>endNumber;

    if(startNumber > 0 && stepNumber > 0 && endNumber > 0)
    {
        std::cout<<"Arithmetic progression: \n";
        for(int i = startNumber; i <= endNumber; i+=stepNumber)
        {
            std::cout<< i<<" ";
        }
    }
    else
    {
        std::cout<<"Invalid input!\n";
    }
}

