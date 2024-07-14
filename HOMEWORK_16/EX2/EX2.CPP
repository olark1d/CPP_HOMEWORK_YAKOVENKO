#include <iostream>
#include <ctime> 
#include "coffee.h"

int main()
{
    int choice;
    coffeeType type;
    std::cout<<"Choose your coffee\n";
    std::cout<<"1 - Espresso, 2 - Latte, 3 - Capuccino\n";
    std::cin>>choice;

    switch (choice)
    {
    case 1:
        type = coffeeType::Espresso;
        break;

    case 2:
        type = coffeeType::Latte;
        break;

    case 3:
        type = coffeeType::Capuccino;
        break;

    default:
        std::cout<<"Wrong input, try again!\n";
    }

    coffee coffee(type);

    coffee.prepare();
    std::cout<<"The cost of coffee = "<<coffee.getCost()<<" UAH\n";

}