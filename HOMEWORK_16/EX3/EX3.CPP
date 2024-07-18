#include <iostream>
#include <ctime>
#include <string>
#include "coffee.h"
#include "coffeeShop.h"

int main()
{
    CoffeeShop Frans_ua("Frans_ua");
    Frans_ua.getTables();
    Frans_ua.testOrders();

    int choiceCoffee;
    int tableNum;
    coffeeType type;
    std::cout<<"Make an order: \n";
    std::cout<<"Coffee type: 0 - Espresso, 1 - Latte, 2 - Capuccino\n";
    std::cin>>choiceCoffee;

    switch (choiceCoffee)
    {
    case 0:
        type = coffeeType::Espresso;
        break;

    case 1:
        type = coffeeType::Latte;
        break;

    case 2:
        type = coffeeType::Capuccino;
        break;    
    
    default:
        std::cout<<"Invalid coffee type!\n";
        return 0;
    }
    
    Frans_ua.getFreeTables();
    std::cout<<"\nChoose a table: \n";
    std::cin>>tableNum;

    Frans_ua.newOrder(tableNum, type);

    std::cout<<"For viewing the order choose a table number: \n";
    std::cin>>tableNum;

    Frans_ua.viewOrders(tableNum);
}