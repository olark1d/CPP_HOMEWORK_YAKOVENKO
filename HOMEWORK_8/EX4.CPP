#include <iostream>
#include <cmath>

float getArea(float radius)
{
    float area;
    area = M_PI * (radius * radius);
    return area;
}

float getCircumference(float radius)
{
    float circuit;
    circuit = 2 * M_PI * radius;
    return circuit;
}

int main()
{
    float radius;
    float area;
    float circuit;
    std::cout<<"Enter a radius: ";
    std::cin>>radius;

    area = getArea(radius);
    std::cout<<"The area of circle: "<<area<<std::endl;

    circuit = getCircumference(radius);
    std::cout<<"The circuit of circle: "<<circuit<<std::endl;


}