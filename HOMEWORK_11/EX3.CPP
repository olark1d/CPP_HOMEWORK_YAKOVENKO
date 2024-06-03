#include <iostream>

#define ROWS 4
#define COLUMNS 4

void from14to41(int arr_2d[ROWS][COLUMNS])
{
    for(int i = COLUMNS - 1; i >= 0; i--)
    {
        for(int j = 0; j < ROWS; j++)
        {
            std::cout<<arr_2d[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
}

void from41to11(int arr_2d[ROWS][COLUMNS])
{
    int turn = 2;
    for(int i = ROWS - 1; i >= 0; i--)
    {
        if(turn % 2 == 0)
        {
            for(int j = 0; j < COLUMNS; j++)
            {
                std::cout<<arr_2d[i][j]<<" ";
            }
        }
        else
        {
            for(int j = COLUMNS - 1; j >= 0; j--)
            {
                std::cout<<arr_2d[i][j]<<" ";
            }
        }
        turn++;
        std::cout<<std::endl;
    }
}

int main()
{
    int option;
    int arr_2d[ROWS][COLUMNS] = 
    {
        1, 2, 3, 4, 
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
    };

    std::cout<<"Choose the bypass option(0, 1): ";
    std::cin>>option;

    switch (option)
    {
        case 0:
        from14to41(arr_2d);
        break;

        case 1:
        from41to11(arr_2d);
        break;
    
        default:
        std::cout<<"Invalid input!\n";
    }
}