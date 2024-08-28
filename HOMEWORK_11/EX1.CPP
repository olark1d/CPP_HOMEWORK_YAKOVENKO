#include <iostream>

#define ROWS 5
#define COLUMNS 5

bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            if(arr_2d[i][j] == toFind)
            return true;
        }
    }
    return false;
}

int main()
{
    int toFind;
    int arr_2d[ROWS][COLUMNS] = {
        14, 34, 11, 23, 98,
        56, 27, 45, 1, 55,
        156, 234, 908, 36, 2,
        111, 222, 333, 444, 555,
        505, 101, 202, 303, 404
    };

    std::cout<<"Enter a number: ";
    std::cin>>toFind;

    if(find(arr_2d, toFind))
    {
        std::cout<<"The number was found in the array!\n";
    }
    else
    {
        std::cout<<"The nubmer wasn't found in the array!\n";
    }





}