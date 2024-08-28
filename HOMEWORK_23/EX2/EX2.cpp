#include<iostream>
#include <string>
#include <sstream>
#include <map>

std::string mostOccuredWord(const std::string& line) 
{
    std::map<std::string, int> wordCount;
    std::stringstream stream(line);
    std::string word;
    std::string mostFrequentWord;
    int maxCount = 0;

    while (stream >> word) 
    {
        wordCount[word]++;
        if (wordCount[word] > maxCount) 
        {
            maxCount = wordCount[word];
            mostFrequentWord = word;
        }
    }

    return mostFrequentWord;
}

int main()
{
    std::string line;
    std::cout << "Enter your words: ";
    std::getline(std::cin, line);

    std::cout << "The most occured word is " << mostOccuredWord(line) << std::endl;
}
