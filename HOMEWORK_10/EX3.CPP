#include <iostream>

bool find(const int* arr, int size, int elem)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == elem)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const int size = 10;
    int arr[size] = {4, 65, 13, 89, 567, 123, 6565, 33, 90, 1};
    int elem;

    std::cout<<"Enter element, you want to find: ";
    std::cin>>elem;

    if(find(arr, size, elem))
    {
        std::cout<<"I find it!!!\n";
    }
    else
    {
        std::cout<<"I don't see it!!!\n";
    }
}