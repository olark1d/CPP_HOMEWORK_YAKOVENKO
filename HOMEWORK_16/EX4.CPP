#include <iostream>
#include <string>

enum class coffeeType 
{
    Espresso,
    Latte,
    Cappuccino,
    Count
};

class coffee 
{
private:
    coffeeType type;
    int cost;

public:
    coffee(coffeeType t) : type(t) 
    {
        switch (type) {
            case coffeeType::Espresso:
                cost = 50;
                break;
            case coffeeType::Latte:
                cost = 100;
                break;
            case coffeeType::Cappuccino:
                cost = 120;
                break;
        }
    }

    void prepare() const 
    {
        switch (type) 
        {
            case coffeeType::Espresso:
                std::cout<<"Preparing Espresso: Water, Coffee. Time: 2 minutes\n";
                break;
            case coffeeType::Latte:
                std::cout<<"Preparing Latte: Milk, Coffee. Time: 3 minutes\n";
                break;
            case coffeeType::Cappuccino:
                std::cout<<"Preparing Cappuccino: Milk, Foam, Coffee. Time: 4 minutes\n";
                break;
        }
    }

    int getCost() const 
    {
        return cost;
    }
};

class CoffeeShop 
{
private:
    std::string name;
    static const int TABLES_COUNT = 10;
    bool m_Tables[TABLES_COUNT];
    coffee* m_Orders[TABLES_COUNT];

public:
    CoffeeShop(const std::string& shopName) : name(shopName) 
    {
        for (int i = 0; i < TABLES_COUNT; ++i) 
        {
            m_Tables[i] = true;
            m_Orders[i] = nullptr;
        }
    }

    int takePlace() 
    {
        for (int i = 0; i < TABLES_COUNT; ++i) 
        {
            if (m_Tables[i]) 
            {
                m_Tables[i] = false;
                std::cout<<"Table "<<i<<" is now occupied\n";
                return i;
            }
        }
        std::cout<<"No free tables available\n";
        return -1;
    }

    void order(int tableNumber) 
    {
        if (tableNumber >= 0 && tableNumber < TABLES_COUNT && !m_Tables[tableNumber]) 
        {
            std::cout<<"Menu:\n";
            std::cout<<"0 - Espresso\n";
            std::cout<<"1 - Latte\n";
            std::cout<<"2 - Cappuccino\n";
            std::cout<<"Enter the number of the coffee you want: ";

            int choice;
            std::cin >> choice;

            if (choice >= 0 && choice < static_cast<int>(coffeeType::Count)) 
            {
                m_Orders[tableNumber] = new coffee(static_cast<coffeeType>(choice));
                std::cout << "Order added for table " << tableNumber << "\n";
            } 
            else 
                std::cout << "Invalid choice\n";
        }
         else 
            std::cout << "Invalid table number or table is not occupied\n";
    }

    bool prepare(int tableNumber) 
    {
        if (tableNumber >= 0 && tableNumber < TABLES_COUNT && m_Orders[tableNumber] != nullptr) 
        {
            m_Orders[tableNumber]->prepare();
            return true;
        } 
        else 
        {
            std::cout<<"No order exists for table "<<tableNumber << "\n";
            return false;
        }
    }

    bool getReceipt(int tableNumber) 
    {
        if (tableNumber >= 0 && tableNumber < TABLES_COUNT && m_Orders[tableNumber] != nullptr) 
        {
            int cost = m_Orders[tableNumber]->getCost();
            std::cout<<"Receipt for table "<<tableNumber <<": "<<cost<<" UAH\n";
            delete m_Orders[tableNumber];
            m_Orders[tableNumber] = nullptr;
            m_Tables[tableNumber] = true;
            return true;
        }
        else 
        {
            std::cout<<"No order exists for table "<<tableNumber<<"\n";
            return false;
        }
    }

    ~CoffeeShop() 
    {
        for (int i = 0; i < TABLES_COUNT; ++i) 
        {
            delete m_Orders[i];
        }
    }
};

int main() 
{
    CoffeeShop shop("Coffee Haven");

    int table1 = shop.takePlace();
    shop.order(table1);
    shop.prepare(table1);
    shop.getReceipt(table1);

    int table2 = shop.takePlace();
    shop.order(table2);
    shop.prepare(table2);
    shop.getReceipt(table2);

    int table3 = shop.takePlace();
    shop.getReceipt(table3);
}