#include <iostream>

int main()
{
    int inputNum;
    int result = 1;
    std::cout<<"Enter your number: ";
    std::cin>>inputNum;

    if(inputNum > 0)
    {
        for(int i = 1; i <= inputNum; i++)
        {
            result *= i;
        }

        std::cout<<"Factorial of "<<inputNum<<" = "<<result<<std::endl; 
    
    }

    else
    {
        std::cout<<"Invalid input!\n";
    }

}