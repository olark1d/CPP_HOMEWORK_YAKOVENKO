#include <iostream>

void positiveNumbers(int* arr, int size, int* positiveNum, int* negativeNum, int* zeroes)
{
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    for(int i = 0; i < size; i++)
    {
        if(*(arr+i) > 0)
        {
            *(positiveNum+index1) = *(arr+i);
            index1++;
        }
        else if (*(arr+i) < 0)
        {
            *(negativeNum+index2) = *(arr+i);
            index2++;
        }
        else
        {
            *(zeroes+index3) = *(arr+i);
            index3++;
        }
        
    }
}

void arrSum(int* arr, int* sum, int size)
{
    for(int i = 0; i < size; i++)
    {
        *sum += *(arr+i);
    }
}

int main()
{
    const int size = 10;
    int arr[size];
    int positiveNum[size] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int negativeNum[size] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int zeroes[size] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int sum = 0;

    std::cout<<"Enter 10 numbers: ";

    for(int i = 0; i < size; i++)
    {
        std::cin>>*(arr+i);
    }
    
    positiveNumbers(arr, size, positiveNum, negativeNum, zeroes);

    std::cout<<std::endl<<"Positive numbers: \n";
    for(int i = 0; i < size; i++)
    {
        if(*(positiveNum+i) != 0)
        {
        std::cout<<*(positiveNum+i);
        }
    }
    std::cout<<std::endl<<"Negative numbers: \n";
    for(int i = 0; i < size; i++)
    {
        if(*(negativeNum+i) != 0)
        {
        std::cout<<*(negativeNum+i);
        }
    }
    std::cout<<std::endl<<"Zeroes: \n";
    for(int i = 0; i < size; i++)
    {
        if(*(zeroes+i) != -1)
        {
        std::cout<<*(zeroes+i);
        }
    }
    arrSum(arr, &sum, size);
    std::cout<<std::endl<<std::endl<<"Sum of elements: "<<sum<<std::endl;
    
}