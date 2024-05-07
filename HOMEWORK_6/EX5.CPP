#include <iostream>

int main()
{
    char symbol;
    int sum = 0;

    while(true)
    {
        std::cout<<"Enter your symbol, \".\" for exit: ";
        std::cin>>symbol;

        if(symbol == '.')
        {
            std::cout<<"Exit!\n";
            break;
        }

        if(islower(symbol))
        {
            symbol = toupper(symbol);
            std::cout<<"Uppercase character: "<<symbol<<"\n";
        }
        else if(isdigit(symbol))
        {
            int digit = symbol - '0';
            sum += digit;
            std::cout<<"Now sum of digits = "<<sum<<"\n";
        }
        else
        {
            std::cout<<"Invalid input!\n";
        }
    }
}