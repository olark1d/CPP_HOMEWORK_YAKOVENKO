#include <iostream>


void toUppercase(char str[])
{
    int action = 'A' - 'a';
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] + action;
        }
        std::cout<<str[i];
    }
    
}

int main()
{
    const int size = 100;
    char str[size];

    std::cout<<"Enter the string: ";
    std::cin.getline(str, size);

    std::cout<<"Symbols in upper case: \n";
    toUppercase(str);
}