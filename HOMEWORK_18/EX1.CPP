#include <iostream>
#include <memory>

enum class DrinkType
{
    Espresso,
    Latte,
    Cappuccino,
    Americano,
    BlackTea,
    GreenTea
};

enum class Size
{
    M,
    L,
    XL
};

class Drink
{
public:
    virtual void prepare() const = 0;
    virtual int getCost() const = 0;
    virtual ~Drink() {}
};

class Coffee : public Drink
{
protected:
    DrinkType type;
    Size size;
    int cost;

public:
    Coffee(DrinkType t, Size s) : type(t), size(s)
    {
        switch (type)
        {
        case DrinkType::Espresso:
            cost = 50;
            break;
        case DrinkType::Latte:
            cost = (s == Size::M) ? 100 : (s == Size::L) ? 120 : 140;
            break;
        case DrinkType::Cappuccino:
            cost = (s == Size::M) ? 120 : 140;
            break;
        case DrinkType::Americano:
            cost = 60;
            break;
        default:
            cost = 0;
            break;
        }
    }

    void prepare() const override
    {
        switch (type)
        {
        case DrinkType::Espresso:
            std::cout<<"Preparing Espresso: Water, Coffee. Time: 2 minutes\n";
            break;
        case DrinkType::Latte:
            std::cout<<"Preparing Latte: Milk, Coffee. Time: 3 minutes\n";
            break;
        case DrinkType::Cappuccino:
            std::cout<<"Preparing Cappuccino: Milk, Foam, Coffee. Time: 4 minutes\n";
            break;
        case DrinkType::Americano:
            std::cout<<"Preparing Americano: Water, Espresso. Time: 3 minutes\n";
            break;
        default:
            break;
        }
    }

    int getCost() const override
    {
        return cost;
    }
};

class Tea : public Drink
{
private:
    DrinkType type;
    Size size;
    int cost;

public:
    Tea(DrinkType t, Size s) : type(t), size(s)
    {
        cost = (t == DrinkType::BlackTea) ? 40 : 45;
    }

    void prepare() const override
    {
        if (type == DrinkType::BlackTea)
        {
            std::cout<<"Preparing Black Tea: Tea leaves, Water. Time: 3 minutes\n";
        }
        else if (type == DrinkType::GreenTea)
        {
            std::cout<<"Preparing Green Tea: Green tea leaves, Water. Time: 3 minutes\n";
        }
    }

    int getCost() const override
    {
        return cost;
    }
};

std::unique_ptr<Drink> createDrink(DrinkType type, Size size)
{
    switch (type)
    {
    case DrinkType::Espresso:
        return std::make_unique<Coffee>(type, size);
    case DrinkType::Latte:
    case DrinkType::Cappuccino:
    case DrinkType::Americano:
        return std::make_unique<Coffee>(type, size);
    case DrinkType::BlackTea:
    case DrinkType::GreenTea:
        return std::make_unique<Tea>(type, size);
    default:
        return nullptr;
    }
}

class CoffeeShop
{
public:
    void order(int tableNumber, DrinkType drinkType, Size size)
    {
        auto drink = createDrink(drinkType, size);
        std::cout<<"Order for table "<<tableNumber<<":\n";
        drink->prepare();
        std::cout<<"Cost: "<<drink->getCost()<<" UAH\n";
    }
};

int main()
{
    CoffeeShop shop;
    shop.order(1, DrinkType::Latte, Size::M);
    shop.order(2, DrinkType::Espresso, Size::M);
    shop.order(3, DrinkType::Cappuccino, Size::L);
    shop.order(4, DrinkType::BlackTea, Size::M);
    shop.order(5, DrinkType::GreenTea, Size::M);
}