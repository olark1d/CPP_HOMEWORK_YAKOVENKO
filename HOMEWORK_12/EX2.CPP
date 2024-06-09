#include <iostream>
#include <algorithm>

#define rows 5
#define columns 5

enum SortingDirection
{
    byRows,
    byColumns
};

void sort(int arr[rows][columns], SortingDirection Sort)
{
    if(Sort == SortingDirection::byRows)
    {
        for(int row = 0; row < rows; row++)
        {
            for(int i = 0; i < columns; i++)
            {
                for(int j = columns - 1; j >= i+1; j--)
                {   
                    if(arr[row][j] < arr[row][j-1])
                    {
                        std::swap(arr[row][j], arr[row][j-1]);
                    }
                }
            }
        }

    }

    else if(Sort == SortingDirection::byColumns)
    {
        for(int cols = 0; cols < columns; cols++)
        {
            for(int i = 0; i < rows; i++)
            {
                for(int j = rows - 1; j >= i+1; j--)
                {   
                    if(arr[j][cols] < arr[j-1][cols])
                    {
                        std::swap(arr[j][cols], arr[j-1][cols]);
                    }
                }
            }
        }
    }
}

void print(int arr[rows][columns])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main()
{
    SortingDirection Sort;
    int variant;
    int arr[rows][columns] = 
    {
        6, 4, 7, 2, 5,
        1, 34, 5, 7, 45,
        3, 8, 4, 9, 1,
        4, 5, 1, 65, 8,
        8, 3, 13, 11, 25
    };

    std::cout<<"Enter a type of sorting(0 - by rows; 1 - by columns): ";
    std::cin>>variant;

    switch(variant)
    {
        case 0:
        Sort = SortingDirection::byRows;
        break;

        case 1:
        Sort = SortingDirection::byColumns;
        break;

        default:
        std::cout<<"Invalid input!\n";
    }

    sort(arr, Sort);
    print(arr);

}