#include <iostream>
#include "DynamicArray.h"


int main()
{
    DynamicArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25); //No new heap allocations, using reserved memory
    m_container.push_back(30); //No new heap allocations, using reserved memory
    m_container.push_back(10); //No new heap allocations, using reserved memory
    m_container.push_back(39); //No new heap allocations, using reserved memory

    //......

    //OOPS, 5th element was added
    //allocate more memory on heap
    m_container.push_back(55);
}