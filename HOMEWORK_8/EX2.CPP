#include <iostream>

//using a cycle
int factorialByCycle(int count)
{
    int result = 1;
    for(int i = 1; i <= count; i++)
    {
        result *= i;
    }
    return result;
}
//using a recursion
int factorialByRecursion(int count)
{
    if(count <= 1)
        return 1;

    return count * factorialByRecursion(count - 1);
}

int main()
{
    int number;
    int result;
    std::cout<<"Enter your number: ";
    std::cin>>number;

    result = factorialByCycle(number);

    std::cout<<"Result using a cycle: "<<result<<std::endl;

    result = factorialByRecursion(number);

    std::cout<<"Result using a recursion: "<<result<<std::endl;
}