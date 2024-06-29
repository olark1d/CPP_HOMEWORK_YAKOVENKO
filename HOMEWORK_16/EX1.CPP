#include <iostream>

class rectangle 
{
    private:
    float length;
    float height;

    public:
    //without parameters
    rectangle(): length(0.0), height(0.0){}

    //with parameters
    rectangle(float length, float height): length(length), height(height){}

    float getArea() const 
    {
        return length * height;
    }

    float getPerimeter() const
    {
        return 2 * (length + height);
    }
};

int main()
{
    //without parameters
    rectangle rect1;
    std::cout<<"The first rectangle area: "<<rect1.getArea()<<std::endl;
    std::cout<<"The first rectangle perimeter: "<<rect1.getPerimeter()<<std::endl;

    //with parameters
    rectangle rect2(5.0, 3.0);
    std::cout<<"The second rectangle area: "<<rect2.getArea()<<std::endl;
    std::cout<<"The second rectangle perimeter: "<<rect2.getPerimeter()<<std::endl;
}