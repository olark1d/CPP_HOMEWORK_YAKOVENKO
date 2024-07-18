#pragma once

enum coffeeType
{
    Espresso,
    Latte,
    Capuccino
};

class coffee
{
    public:
    coffee(coffeeType type);

    void prepare();

    int getCost();

    private:
    coffeeType m_type;
    int cost;
};