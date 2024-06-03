#include <iostream>

enum SortingDirection
{
    ascending,
    descending
};

bool isSorted(const int* arr, int size, SortingDirection direction)
{
    if(direction == ascending)
    {
        for(int i = 1; i < size; i++)
        {
            if(arr[i] <= arr[i-1])
            return false;
        }
        return true;
    }
    else if(direction == descending)
    {
        for(int i = 1; i < size; i++)
        {
            if(arr[i] >= arr[i-1])
            return false;
        }
        return true;
    }
}   

int main()
{
    int size = 10;
    int arr[size];
    int intDirection;
    SortingDirection direction;

    std::cout<<"Enter 10 numbers: ";

    for(int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }

    std::cout<<"enter the verification type (ascending - 0, descending - 1): ";
    std::cin>>intDirection;

    switch (intDirection)
    {
        case 0:
        direction = SortingDirection::ascending;

        if(isSorted(arr, size, direction))
        std::cout<<"It's correct!\n";
        else
        std::cout<<"It's incorrect!\n";

        break;

        case 1:
        direction = SortingDirection::descending;

        if(isSorted(arr, size, direction))
        std::cout<<"It's correct!\n";
        else
        std::cout<<"It's incorrect!\n";

        break;
    
        default:
        std::cout<<"Invalid input!\n";
    }

}