#include <iostream>

bool calculateSum(const double* arr, int arrSize, double& sum)
{
    for(int i = 0; i < arrSize; i++)
    {
     sum += arr[i];    
    } 

    if(sum > 0)
    return true;
    else
    return false;
}

int main()
{
    const int arrSize = 10;
    double arr[arrSize];
    double sum = 0;

    std::cout<<"Enter 10 numbers: ";
    for(int i = 0; i < arrSize; i++)
    {
        std::cin>>arr[i];
    }

    if(calculateSum(arr, arrSize, sum))
    {
        std::cout<<"The sum of numbers > 0!\n";
    }
    else
    {
        std::cout<<"The sum of numbers < 0!\n";
    }


}