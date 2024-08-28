#pragma once

class rectangle 
{
   public:

    //c-tor without parameters
   rectangle(){};

    //c-tor with parameters
   rectangle(float length, float height);

   float getarea();

   float getPerimeter();

   float m_length = 0;
   float m_height = 0;
};