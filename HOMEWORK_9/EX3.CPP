#include <iostream>
#include <cstring>

bool isPalindrom(const char str[])
{
    int start = 0;
    int end = std::strlen(str) - 1;
    while(start < end)
    {
        if(str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    const int size = 100;
    char str[size];

    std::cout<<"Enter your string: ";
    std::cin.getline(str, size);

    if(isPalindrom(str))
    {
        std::cout<<"It's palindrom!\n";
    }
    else
    {
        std::cout<<"It's not palindrom!\n";
    }


}