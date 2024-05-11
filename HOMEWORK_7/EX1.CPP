#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout<<"Hello! Welcome to 'Rock paper scissors' game for 2 players.\n";
    int rounds = 0;
    char userSymbol;
    int statRounds = 0;
    int statWins = 0;
    int statLosses = 0;
    int statDraws = 0;

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
            
        

                int PCSymbol = std::rand() % 3; // 0 - r; 1 - p; 2 - s;

                switch (userSymbol)
                {
                    case 'r':
                        if(PCSymbol == 0)
                        {   
                            std::cout<<"PC choise is R\n"<<"It's DRAW\n\n";
                            statDraws++;
                            statRounds++;
                        }
                        else if(PCSymbol == 1)
                        {
                            std::cout<<"PC choise is P\n"<<"You LOSE\n\n";
                            statLosses++;
                            statRounds++;
                        }
                        else
                        {
                            std::cout<<"PC choise is S\n"<<"You WIN\n\n";
                            statWins++;
                            statRounds++;
                        }
                    break;
                    case 'p':
                        if(PCSymbol == 0)
                        {   
                            std::cout<<"PC choise is R\n"<<"You WIN\n\n";
                            statWins++;
                            statRounds++;
                        }
                        else if(PCSymbol == 1)
                        {
                            std::cout<<"PC choise is P\n"<<"It's DRAW\n\n";
                            statDraws++;
                            statRounds++;
                        }
                        else
                        {
                            std::cout<<"PC choise is S\n"<<"You LOSE\n\n";
                            statLosses++;
                            statRounds++;
                        }
                    break;
                    case 's':
                        if(PCSymbol == 0)
                        {   
                            std::cout<<"PC choise is R\n"<<"You Lose\n\n";
                            statLosses++;
                            statRounds++;
                        }
                        else if(PCSymbol == 1)
                        {
                            std::cout<<"PC choise is P\n"<<"You WIN\n\n";
                            statWins++;
                            statRounds++;
                        }
                        else
                        {
                            std::cout<<"PC choise is S\n"<<"It's DRAW\n\n";
                            statDraws++;
                            statRounds++;
                        }   

                    break;            
                    default:
                    std::cout<<"Invalid symbol! Try again.\n\n";
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