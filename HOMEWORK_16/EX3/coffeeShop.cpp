#include <iostream>
#include <string>
#include "coffeeShop.h"

CoffeeShop::CoffeeShop(std::string name)
    {
        std::cout<< "Welcome to "<<name<<" !!!\n";
    };

void CoffeeShop::getTables()
    {
        for(int i = 0; i < TABLES_COUNT; i++)
        {
            m_Tables[i] = (i + 1) % 2;
            m_Orders[i] = nullptr;
        }
    };

void CoffeeShop::getFreeTables()
    {
        for (int i = 0; i < TABLES_COUNT; i++)
        {
            if (m_Tables[i] == 0)
            {
                std::cout << "Table " << i << " is free now\n";
            }
            else
            {
                std::cout << "Table " << i << " is booked now\n";
            }        
        }
    };

    //ONLY FOR TEST!!!!
void CoffeeShop::testOrders()
    {
        m_Orders[0] = new coffee(Latte);
        m_Orders[2] = new coffee(Espresso);
        m_Orders[4] = new coffee(Espresso);
        m_Orders[6] = new coffee(Capuccino);
        m_Orders[8] = new coffee(Espresso);
    };

void CoffeeShop::newOrder(int tableNum, coffeeType type)
    {
        if(m_Tables[tableNum] == 0)
        {
        m_Orders[tableNum] = new coffee(type);
        std::cout<<"Your order is in process!\n";
        m_Tables[tableNum] = 1;
        }
        else
        {
        std::cout<<"The table number "<<tableNum<<" is booked now!\n";
        }
    };

void CoffeeShop::viewOrders(int tableNum)
    {
        if(m_Tables[tableNum] == 1)
        {
            std::cout<<"The order of table number "<<tableNum<<" is ";
            m_Orders[tableNum]->prepare();
            std::cout<<"Cost: "<<m_Orders[tableNum]->getCost()<<"UAH\n";
        }
        else
        std::cout<<"This table is free now!\n";
    };