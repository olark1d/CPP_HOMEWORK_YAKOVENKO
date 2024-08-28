#pragma once
#include <string>
#include "coffee.h"

class CoffeeShop
{
    public:
    CoffeeShop(std::string name);

    static const int TABLES_COUNT = 10;

    void getTables();
        //ONLY FOR TEST!!!!
    void testOrders();

    int takePlace();


    void order(int tableNumber);

    bool prepare(int tableNumber);

    bool getReceipt(int tableNumber);

    private:

    std::string name;

    coffee* m_Orders[TABLES_COUNT];

    bool m_Tables[TABLES_COUNT];
};