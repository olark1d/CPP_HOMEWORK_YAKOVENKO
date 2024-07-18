#include <iostream>
#include <ctime>
#include "coffee.h"

coffee::coffee(coffeeType type)
    {
        m_type = type;
    };

void coffee::prepare()
{
    std::time_t now = std::time(nullptr);

    switch (m_type)
    {
    case coffeeType::Espresso:
        cost = 50;
        break;

    case coffeeType::Latte:
        cost = 100;
        break;
    
    case coffeeType::Capuccino:
        cost = 120;
        break;
    }

    switch (m_type)
    {
    case coffeeType::Espresso:
        std::cout<<"Preparing Espresso: Water, Coffee. Time: "<<std::ctime(&now);
        break;

    case coffeeType::Latte:
        std::cout<<"Preparing Latte: Milk, Coffee. Time: "<<std::ctime(&now);
        break;

    case coffeeType::Capuccino:
        std::cout<<"Preparing Capuccino: Milk, Foam, Coffee. Time: "<<std::ctime(&now);
        break;
    
    default:
    std::cout<<"Wrong input!\n";
    }
};

int coffee::getCost()
{
    return cost;
};