#include <iostream>
#include <cstring>

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
    int lenth = std::strlen(str);
    for(int i = 0; i < lenth; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            constonantsCount++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            vowelsCount++;       
        }
    }

}

int main()
{
    const int size = 100;
    int vowelsCount = 0, constonantsCount = 0;
    char str[size];

    std::cout<<"Enter your string: ";
    std::cin.getline(str, size);

    parseStringLetters(str, vowelsCount, constonantsCount);

    std::cout<<"Number of vowels: "<<vowelsCount<<std::endl;
    std::cout<<"Number of constonants: "<<constonantsCount<<std::endl;



}