#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

unsigned int uniqueWordsCount(const std::string& line) 
{
    std::set<std::string> uniqueWords;
    std::istringstream stream(line);
    std::string word;

    while (stream >> word) 
    {
            if (!uniqueWords.empty())
            {
                auto finded = uniqueWords.find(word);
                if (finded != uniqueWords.end())
                {
                    uniqueWords.erase(word);
                }
                else
                {
                    uniqueWords.insert(word);
                };
            }
            else
            {
                uniqueWords.insert(word);
            };
    }

    return uniqueWords.size();
}

int main()
{
    std::string line;
    std::cout << "Enter your words: ";
    std::getline(std::cin, line);

    std::cout << "Number of unique words = " << uniqueWordsCount(line) << std::endl;
}