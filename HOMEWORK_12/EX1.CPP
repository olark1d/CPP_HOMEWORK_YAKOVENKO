#include <iostream>

void bublesort(int* arr, int low, int high)
{
    for(int i = low; i < high; i++)
    {
        for(int j = high - 1; j >= i+1; j--)
        {
            if(arr[j] < arr[j-1])
            {
                std::swap(arr[j], arr[j-1]);
            }
        }
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

int main()
{
    const int size = 10;
    int arr[size] = {12, 3, 87, 11, 2, 7, 9, 14, 6, 34};

    bublesort(arr, 0, size);
    print(arr, size);

}