#include <iostream>

bool isEqual(const char str1[], const char str2[])
{
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    const int size = 100;
    char str1[size];
    char str2[size];

    std::cout<<"Enter the first string: ";
    std::cin.getline(str1, size);

    std::cout<<"Enter the second string: ";
    std::cin.getline(str2, size);

    if(isEqual(str1, str2))
    {
        std::cout<<"Strings is equal!\n";
    }
    else
    {
        std::cout<<"String isn't equal!\n";
    }
    
}