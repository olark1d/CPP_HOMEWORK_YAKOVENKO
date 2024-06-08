#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cctype>
#include <algorithm>    
#include <cstring>

#define wordSize 5
char result[] = "*****";

int getDay(const std::tm* tmObj) //geting day
{
    return tmObj->tm_mday;
}

int getMonth(const std::tm* tmObj) //geting month
{
    return tmObj->tm_mon + 1;
}

int getYear(const std::tm* tmObj) //geting year
{
    return tmObj->tm_year + 1900;
}

void readFile(const char* fileName, std::string* WORDS_BASE, int size)
{
    std::fstream file(fileName); //reading file

    if(!file.is_open()) //checking the file
    {
        std::cout<<"File not found!\n";
    }

    for(int i = 0; i < size; i++)
    {
        std::getline(file, WORDS_BASE[i]); //writing array from file
    }
}

void roundOfGame(const char* word)
{
    std::fill(result, result + wordSize, '*'); //returns the result
    result[wordSize] = '\0';

    int exit = 0;
    int tries = 0; 
    while(exit != -1)
    {
        char input[5];
        std::cout<<"RESULT : "<<result<<std::endl;
        std::cout<<"ENTER  : ";
        std::cin>>input;
        std::cout<<std::endl;

        std::fill(result, result + wordSize, '*'); //returns the result
        result[wordSize] = '\0';

        for(int i = 0; i < wordSize; i++)
        {
            bool used[wordSize] = { false };  //bool for avoiding used symbols  
            if(word[i] == input[i] || std::tolower(word[i]) == input[i]) //fills in the letters that are in their place
            {
                result[i] = word[i];
                used[i] = true;
            }
            else
            {
                for(int j = 0; j < wordSize; j++) //fills in the letters that are in the word but not elsewhere
                {
                    if((word[i] == input[j] || std::tolower(word[i]) == input[j]) && !used[j])
                    {
                        result[j] = std::tolower(input[j]);
                        used[j] = true;
                        break;
                    }
                }
            }
        }
        tries++; //counts the number of tries
        if (strcmp(word, result) == 0) //checks the final result
        {
            exit = -1;
        }
    }
    std::cout<<"That's right!\n";
    std::cout<<"You made "<<tries<<" tries!\n\n";
}

void launchWordleOfTheDay()
{
    std::time_t t = std::time(nullptr); 
    std::tm* now = std::localtime(&t);

    // todays date to integer

    int dayNow = getDay(now);
    int monthNow = getMonth(now);
    int yearNow = getYear(now);

    // date to integer for file

    int dayFile = 0;
    int monthFile = 0;
    int yearFile = 0;

    std::fstream dateFileRead("DATE.txt"); //reading date from file
    if(dateFileRead.is_open())
    {
        dateFileRead >> dayFile;
        dateFileRead >> monthFile;
        dateFileRead >> yearFile;
        dateFileRead.close();
    }

    if(dayFile == dayNow && monthFile == monthNow && yearFile == yearNow) //checking date
    {
        std::cout<<"Already found! Come back tommorow!\n\n";
        return;
    }

    int size = 31;
    std::string Wordle_of_the_Day_base[size];

    readFile("WORD_OF_THE_DAY.txt", Wordle_of_the_Day_base, size);

    int rand = std::rand() % 26; //random word

    std::string strWord = Wordle_of_the_Day_base[rand];
    const char* word = strWord.c_str(); // string to char

    roundOfGame(word);

    std::fstream dateFileWrite("DATE.txt"); //writing date to file
    dateFileWrite << dayNow;
    dateFileWrite << "\n";
    dateFileWrite << monthNow;
    dateFileWrite << "\n";
    dateFileWrite << yearNow;
    dateFileWrite.close();
}

void launchRandomWordle()
{
    int size = 26;
    std::string Random_Word_Base[size];

    readFile("WORDS.txt", Random_Word_Base, size);

    int rand = std::rand() % 26; //random word

    std::string strWord = Random_Word_Base[rand];
    const char* word = strWord.c_str(); // string to char

    roundOfGame(word);
}


int main()
{
    std::srand(std::time(nullptr));

    std::cout<<"------WELCOME TO THE WORDLE GAME------\n";

    while(true)
    {
        //variants of game
        int choice;
        std::cout<< "1 - Wordle of the day\n"; 
        std::cout<<"2 - Random Wordle\n";
        std::cout<<"0 - Exit\n";

        std::cout<<"Enter: ";
        std::cin>>choice;
        std::cout<<std::endl;

        //launching game
        switch(choice)
        {
        case 0:
            return 0;
        case 1:
            launchWordleOfTheDay();
            break;
        case 2:
            launchRandomWordle();
            break;
        default:
            std::cout<<"Invalid input!\n";
        }
    }
}