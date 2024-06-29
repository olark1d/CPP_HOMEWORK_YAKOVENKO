#include <iostream>
#include <string>

enum class coffeeType 
{
    Espresso,
    Latte,
    Cappuccino
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

    void takeOrder(int tableIndex, coffeeType coffeeType) 
    {
        if (tableIndex >= 0 && tableIndex < TABLES_COUNT) 
        {
            if (m_Tables[tableIndex]) 
            {
                m_Orders[tableIndex] = new coffee(coffeeType);
                m_Tables[tableIndex] = false;
                std::cout<<"Order taken for table "<<tableIndex << "\n";
            } 
            else 
                std::cout<<"Table "<<tableIndex<<" is already occupied\n";
        }
        else 
            std::cout << "Invalid table index!\n";
    }

    void freeTable(int tableIndex) 
    {
        if (tableIndex >= 0 && tableIndex < TABLES_COUNT) 
        {
            delete m_Orders[tableIndex];
            m_Orders[tableIndex] = nullptr;
            m_Tables[tableIndex] = true;
            std::cout<<"Table "<<tableIndex<<" is now free\n";
        } 
        else 
            std::cout <<"Invalid table index\n";
    }

    void showOrders() const 
    {
        for (int i = 0; i < TABLES_COUNT; ++i) 
        {
            if (!m_Tables[i] && m_Orders[i] != nullptr) 
            {
                std::cout<<"Table "<<i<<" has an order ";
                m_Orders[i]->prepare();
                std::cout<<"Cost: "<<m_Orders[i]->getCost()<<" UAH\n";
            }
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

    shop.takeOrder(1, coffeeType::Latte);
    shop.takeOrder(3, coffeeType::Espresso);
    shop.showOrders();

    shop.freeTable(1);
    shop.showOrders();
}