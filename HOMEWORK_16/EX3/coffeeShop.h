#pragma once
#include <string>
#include "coffee.h"

class CoffeeShop
{
public:

    CoffeeShop(std::string name);

    static const int TABLES_COUNT = 10;


    void getTables();

    void getFreeTables();

    //ONLY FOR TEST!!!!
    void testOrders();

    void newOrder(int tableNum, coffeeType type);

    void viewOrders(int tableNum);

    private:

    std::string name;

    coffee* m_Orders[TABLES_COUNT];

    bool m_Tables[TABLES_COUNT];
};