#include <iostream>
#include <cstdlib>
#include <ctime>

enum class GameElement 
    {
        rock,
        paper, 
        scissor
    };

int main()
{
    std::cout<<"Hello! Welcome to 'Rock paper scissors' game for 2 players.\n";
    int rounds = 0;
    char userSymbol;
    int statRounds = 0;
    int statWins = 0;
    int statLosses = 0;
    int statDraws = 0;
    GameElement PCChoice, userChoice;

    std::srand(std::time(nullptr));

    while(true)
    {
        std::cout<<"Enter rounds number (-1 to quit): ";
        std::cin>>rounds;
        std::cout<<std::endl;

        if(rounds == -1)
        {
            break;
        }
        else if(rounds > 0)
        {
            for(int i = 0; i < rounds; i++)
            {
                std::cout<<"To make your turn enter one of possible symbols:\n"<<
                "     r - rock     p - paper     s - scissors\n";
                std::cout<<"Your choice is ";
                std::cin>>userSymbol;

                if(userSymbol == 'r' || userSymbol == 'p' || userSymbol == 's')
                {
                    switch (userSymbol) 
                    {
                        case 'r': 
                        userChoice = GameElement::rock; 
                        break;
                        case 'p':
                        userChoice = GameElement::paper; 
                        break;
                        case 's': 
                        userChoice = GameElement::scissor; 
                        break;
                    }

                    const int PCSymbol = std::rand() % 3; // 0 - r; 1 - p; 2 - s;
                    if(PCSymbol == 0)
                    std::cout<<"PC choice is R\n";
                    else if(PCSymbol == 1)
                    std::cout<<"PC choice is P\n";
                    else
                    std::cout<<"PC choise is S\n";

                    switch (PCSymbol) 
                    {
                        case 0: 
                        PCChoice = GameElement::rock; 
                        break;
                        case 1: 
                        PCChoice = GameElement::paper; 
                        break;
                        case 2: 
                        PCChoice = GameElement::scissor; 
                        break;
                    }

                    if (userChoice == PCChoice) 
                    {
                        std::cout<<"It's DRAW\n\n";
                        statDraws++;
                    } 
                    else 
                    {
                        switch (userChoice) 
                        {
                            case GameElement::rock:
                                if(PCChoice == GameElement::paper) 
                                {
                                    std::cout << "You LOSE\n\n";
                                    statLosses++;
                                } 
                                else 
                                {
                                    std::cout << "You WIN\n\n";
                                    statWins++;
                                }
                            break;
                            case GameElement::paper:
                                if (PCChoice == GameElement::scissor) 
                                {
                                    std::cout << "You LOSE\n\n";
                                    statLosses++;
                                } 
                                else 
                                {
                                    std::cout << "You WIN\n\n";
                                    statWins++;
                                }
                            break;
                            case GameElement::scissor:
                                if (PCChoice == GameElement::rock) 
                                {
                                    std::cout << "You LOSE\n\n";
                                    statLosses++;
                                } 
                                else 
                                {
                                    std::cout << "You WIN\n\n";
                                    statWins++;
                                }
                            break;
                        }
                    }
                statRounds++;
                }
                else
                {
                   std::cout<<"Invalid symbol! Try again.\n"; 
                   i--;
                }
            }
        }
        else
        {
            std::cout<<"Invalid input! Try again.\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        if(rounds > 0)
        {
        std::cout<<"Thanks for playing. Your final stats: \n";
        std::cout<<"    number of rounds - "<<statRounds<<std::endl;
        std::cout<<"    number of wins - "<<statWins<<std::endl;
        std::cout<<"    number of losses - "<<statLosses<<std::endl;
        std::cout<<"    number of draws - "<<statDraws<<std::endl;
        if(statWins > statLosses)
        std::cout<<"---You're smarter than my PC algo!---\n";
        else if(statWins < statLosses)
        std::cout<<"---My PC is smarter than you algo!---\n";
        else 
        std::cout<<"--- You're on the same level with my PC!---\n";

        std::cout<<"---------------------------------------------------\n\n\n";
        }
    }

    std::cout<<"BYE-BYE\n";
}