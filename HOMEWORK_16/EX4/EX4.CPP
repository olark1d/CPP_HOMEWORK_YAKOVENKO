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
    int tableNumber = -1; 
    int check;

    while(check != -1)
    {
        int menu;
        std::cout<<"MENU:\n";
        std::cout<<" 1. Take a place\n"<<" 2. Make an order\n"<<" 3. Check an order\n"<<" 4. Get a receipt\n"<<"-1. Exit\n";
        std::cout<<"Select a menu item:\n";
        std::cin>>menu;

        switch (menu)
        {
        case 1:
        if(tableNumber != -1)
        std::cout<<"Your already taken a place\n";
        else
        {
            tableNumber = Frans_ua.takePlace();
        }
            break;

        case 2:
            Frans_ua.order(tableNumber);
            break;

        case 3:
            if(tableNumber != -1)
            {
                if(Frans_ua.prepare(tableNumber))
                {}
                else if(tableNumber == -1)
                std::cout<<"This table didn't made an order now\n";   
            }            
            else
            std::cout<<"You didn't take any table now!\n";
            break;

        case 4:
            if(tableNumber != -1)
            {
                if(Frans_ua.getReceipt(tableNumber))
                {
                check = -1;    
                }
                else
                std::cout<<"This table didn't made an order now\n";
            }
            else if(tableNumber == -1)
            std::cout<<"You didn't take any table now!\n";
            break;
        
        case -1:
            check = -1;
            break;

        default:
            std::cout<<"Wrong input. Try again!\n";
        }
    }
}