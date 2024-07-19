#include <iostream>
#include <cmath>
#include "vector2d.h"

int main() 
{
    Vector2d vec1{1.2, 5.6};
    Vector2d vec2{3.4, 7.8};
    Vector2d vec3 = vec1 + vec2;

    std::cout<<"vec1: "<<vec1<<std::endl;
    std::cout<<"vec2: "<<vec2<<std::endl;
    std::cout<<"vec3 (vec1 + vec2): "<<vec3<<std::endl;

    vec3 *= 2.0;
    std::cout<<"vec3 after scaling by 2: "<<vec3<<std::endl;

    std::cout<<"Length of vec3: "<<vec3()<<std::endl;

    std::cout<<"vec3[0]: "<<vec3[0]<<", vec3[1]: "<<vec3[1]<<std::endl;

    std::cout<<"Active instances: "<<Vector2d::getInstanceCount()<<std::endl;

    Vector2d inputVec;
    std::cout<<"Enter a vector (x y): ";
    std::cin>>inputVec;
    std::cout<<"You entered: "<<inputVec<<std::endl;

    std::cout<<"Active instances after input: "<<Vector2d::getInstanceCount()<<std::endl;
}