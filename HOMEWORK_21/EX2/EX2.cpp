#include <iostream>
#include <algorithm>
#include <vector>

unsigned int countDivisibleBy(const std::vector<int> &vec, int number)
{
    return std::count_if(vec.begin(), vec.end(), [number](int element)
        {
            if (element % number == 0)
                return true;
            else
                return false;
        });
};

int main()
{
    std::vector<int> intVector = { 4, 56, 3, 9, 231, 6677, 8, 23, 13, 65, 48, 11, 28, 569, 891 };

    int number = 3;

    std::cout << "The number of elements that are divisible by " << number << " = " << countDivisibleBy(intVector, number) << std::endl;
}
