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
            //ONLY FOR TEST!!!!
            m_Tables[i] = (i + 1) % 2;
            m_Orders[i] = nullptr;
        }
    };

void CoffeeShop::testOrders()
    {
        m_Orders[0] = new coffee(Latte);
        m_Orders[2] = new coffee(Espresso);
        m_Orders[4] = new coffee(Espresso);
        m_Orders[6] = new coffee(Capuccino);
        m_Orders[8] = new coffee(Espresso);
    };

int CoffeeShop::takePlace()
    {
        int freeTables = -1;
        std::cout<<"Free tables: \n";
        for (int i = 0; i < TABLES_COUNT; i++)
        {
            if (m_Tables[i] == 0)
            {
                std::cout << "Table " << i << " is free now\n";
                freeTables++;
            }


        }
        if(freeTables == -1) 
        {
            std::cout<<"There are no free tables now. Try again later\n";
            return freeTables;
        }

        while(true)
        {
            int tableNumber;
            std::cout<<"Choose one of free tables: ";
            std::cin>>tableNumber;
            if(m_Tables[tableNumber] == 0)
            {
            std::cout<<"Your choice: The table number "<<tableNumber<<std::endl;
            m_Tables[tableNumber] = 1;
            return tableNumber;
            break;
            }
            else
            {
                std::cout<<"This table is occupied now. Try again\n";
            }
        }
    };

void CoffeeShop::order(int tableNumber)
    {
        int choice;
        coffeeType type;
        bool check;
        std::cout<<"Choose one of the drink:\n";
        std::cout<<"1. Espresso\n";
        std::cout<<"2. Latte\n";
        std::cout<<"3. Capuccino\n";

        do
        {
            
            std::cout<<"Your choice: ";
            std::cin>>choice;

            switch (choice)
            {
            case 1:
                type = coffeeType::Espresso;
                check = true;
                break;
            
            case 2:
                type = coffeeType::Latte;
                check = true;
                break;
            
            case 3:
                type = coffeeType::Capuccino;
                check = true;
                break;
            default:
                std::cout<<"Wrong drink type. Try again\n";
                check = false;
            }
        }
        while(!check);

        m_Orders[tableNumber] = new coffee(type);
        std::cout<<"Your order is in process now!\n";
    };

bool CoffeeShop::prepare(int tableNumber)
    {
        if(m_Orders[tableNumber] == nullptr)
        return false;
        else
        {
        m_Orders[tableNumber]->prepare();
        return true;
        }
        
    };

bool CoffeeShop::getReceipt(int tableNumber)
    {
        if(m_Orders[tableNumber] == nullptr)
        return false;
        else
        {
            std::cout<<"The cost of order: "<<m_Orders[tableNumber]->getCost()<<" UAH\n";
            m_Tables[tableNumber] = 0;
            delete m_Orders[tableNumber];
            std::cout<<"Goodbye! Have a nice day:)\n";
            return true;
        }
    };

