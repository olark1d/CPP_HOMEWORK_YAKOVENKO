#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareByLength(std::string str1, std::string str2)
{
    return str1.size() < str2.size();
};

class LengthComparator
{
public:
    bool operator()(std::string &str1, std::string &str2) const
    {
        return str1.size() < str2.size();
    };
};

int main()
{
    std::vector<std::string> stringContainer = {"fghdgfdfdgfd", "dfgreretfd", "gfdgdfrwermjhasddsa", "ereteads"};

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);//by function

    for (int i = 0; i < stringContainer.size(); i++)
    {
        std::cout << stringContainer[i] << std::endl;
    }

    std::cout << std::endl;

    LengthComparator comparator;
    std::sort(stringContainer.begin(), stringContainer.end(), comparator);//by comparator class

    for (int i = 0; i < stringContainer.size(); i++)
    {
        std::cout << stringContainer[i] << std::endl;
    }

    std::cout << std::endl;

    std::sort(stringContainer.begin(), stringContainer.end(), [](std::string &str1, std::string &str2) {return str1.size() < str2.size();});//by lambda

    for (int i = 0; i < stringContainer.size(); i++)
    {
        std::cout << stringContainer[i] << std::endl;
    }

}
