#include <iostream>

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a, b;
    int index = 0;
    while(true)
    {
        std::cout<<"Enter a: ";
        std::cin>>a;
        std::cout<<"Enter b: ";
        std::cin>>b;

        if(index == 1)
        {
            swap(&a, &b);
            std::cout<<"By pointers: a = "<<a<<", b = "<<b<<std::endl;
            break;
        }
            swap(a, b);
            std::cout<<"By reference: a = "<<a<<", b = "<<b<<std::endl;
            index++;
    }
}   