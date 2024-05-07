#include <iostream>

int main()
{
    int elementNumber;
    int result;
    int index = 0;
    int firstValue = 0;
    int secondValue = 1;

    std::cout<<"Enter the element number: ";
    std::cin>>elementNumber;
    
        do
        {
            result = firstValue + secondValue;

            if(index > 0)
            {
            firstValue = secondValue;
            }

            secondValue = result;
            index++;
        } 
        while (index < elementNumber);
    
        std::cout<<"Your element = "<<result<<std::endl;

}