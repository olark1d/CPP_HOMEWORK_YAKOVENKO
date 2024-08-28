#include <iostream>
#include "rectangle.h"

int main()
{
    //with parameters
    rectangle rect1(5.45, 8.21);

    std::cout<<"The area of rectangle with parameters = "<<rect1.getarea()<<std::endl;
    std::cout<<"The perimeter of rectangle with parameters = "<<rect1.getPerimeter()<<std::endl;

    std::cout<<std::endl;
    
    //without parameters
    rectangle rect2;
    rect2.m_height = 3;
    rect2.m_length = 2;

    std::cout<<"The area of rectangle without parameters = "<<rect2.getarea()<<std::endl;
    std::cout<<"The perimeter of rectangle without parameters = "<<rect2.getPerimeter()<<std::endl;
}