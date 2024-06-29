#include <iostream>
#include <string>

enum coffeeType
{
    Espresso,
    Latte,
    Capuccino
};

class Coffee
{
    private:
    coffeeType type;
    int cost;

    public:
    Coffee(coffeeType t) : type(t)
    {
        switch (type)
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
        case coffeeType::Capuccino:
            std::cout<<"Preparing Capuccino: Milk, Foam, Coffee. Time: 4 minutes\n";
            break;
        default:
            break;
        }
    }

    int getCost() const
    {
        return cost;
    }
};

int main()
{
    int choice;
    std::cout<<"------WELCOME TO OUR COFFEESHOP------\n";
    std::cout<<"Choose your coffee: \n";
    std::cout<<"1 - Espresso, 2 - Latte, 3 - Capuccino\n";
    std::cin>>choice;

    switch (choice)
    {
        case 1:
        {
            Coffee Espresso(coffeeType::Espresso);
            Espresso.prepare();
            std::cout<<"Cost: "<<Espresso.getCost()<<"UAH\n";
            break;
        }

        case 2:
        {
            Coffee Latte(coffeeType::Latte);
            Latte.prepare();
            std::cout<<"Cost: "<<Latte.getCost()<<"UAH\n";
            break;
        }

        case 3:
        {
            Coffee Capuccino(coffeeType::Capuccino);
            Capuccino.prepare();
            std::cout<<"Cost: "<<Capuccino.getCost()<<"UAH\n";
            break;
        }

        default:
            std::cout<<"Invalid input!\n";
    }


}