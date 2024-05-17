#include <iostream>

int positive, negative, zeroes;

void userInputStat(int number)
{
    int value;
    for(int i = 0; i < number; i++)
    {
        std::cout<<"Enter your value: ";
        std::cin>>value;

        if(value > 0)
        positive++;
        else if(value < 0)
        negative++;
        else
        zeroes++;
    }

    std::cout<<"Positive: "<<positive<<std::endl;
    std::cout<<"Negative: "<<negative<<std::endl;
    std::cout<<"Zeroes: "<<zeroes<<std::endl;
}
int main()
{
    int number;
    std::cout<<"Enter number of numbers: ";
    std::cin>>number;
    std::cout<<std::endl;

    userInputStat(number);
}