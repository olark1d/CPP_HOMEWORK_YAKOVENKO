#include <iostream>
#include "rectangle.h"

rectangle::rectangle(float length, float height)
   {
    m_length = length;
    m_height = height;
   };

float rectangle::getarea()
   {
    return m_length * m_height;
   };

   
float rectangle::getPerimeter()
    {
     return (m_height + m_length) * 2;
    };