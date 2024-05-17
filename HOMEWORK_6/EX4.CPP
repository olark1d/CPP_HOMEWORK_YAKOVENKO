#include <iostream>

int main()
{
    int height;
    int width;
    int width1;
    int width2 = 1;
    int width3 = 1;

    std::cout<<"Enter height and width of figures: ";
    std::cin>>height>>width;
        width1 = width;


    if(height > 0 && width > 0)
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = width1; j > 0; j--)
            {
                std::cout<<"*";
            }
            width1--;
            std::cout<<std::endl;
        }
        
        std::cout<<std::endl;

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width2 && j <= width; j++)
            {
                std::cout<<"*";
            }
            std::cout<<std::endl;
            width2++;
        }
        
        std::cout<<std::endl;
        
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                std::cout<<"*";
            }
            std::cout<<std::endl;
        }

        std::cout<<std::endl;

        for(int i = 0; i < height; i++)
        {
            int space = 0;
            while(space < i)
            {
                std::cout<<" ";
                space++;
            }
            for(int j = 0; j < width; j++)
            {
                std::cout<<"*";
            }
            std::cout<<std::endl;
        }

        std::cout<<std::endl;
        
        for(int i = 1; i <= height; i++)
        {
            for(int j = 0; j < width3; j++)
            {
                std::cout<<(i+j) % 2;
            }
            std::cout<<std::endl;
            width3++;
        }


    }
    else
    {
        std::cout<<"Invalid input!\n";
    }
}