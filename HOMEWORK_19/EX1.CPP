#include <iostream>
#include <stdexcept>

class dynamicIntArray 
{
private:
    int* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity) 
    {
        int* newData = new int[newCapacity];
        for (size_t i = 0; i < size; ++i) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    dynamicIntArray() : data(nullptr), size(0), capacity(0) {}

    ~dynamicIntArray() 
    {
        delete[] data;
    }

    void pushBack(int value) 
    {
        if (size == capacity) 
        {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void popBack() 
    {
        if (size == 0) 
        {
            throw std::out_of_range("Array is empty");
        }
        --size;
    }

    int& operator[](size_t index) 
    {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const 
    {
        return size;
    }

    bool isEmpty() const 
    {
        return size == 0;
    }

    void clear() 
    {
        size = 0;
    }
};

int main() 
{
    dynamicIntArray array;

    array.pushBack(10);
    array.pushBack(20);
    array.pushBack(30);

    for (size_t i = 0; i < array.getSize(); ++i) 
    {
        std::cout<<array[i]<< " ";
    }
    std::cout<<std::endl;

    array.popBack();

    for (size_t i = 0; i < array.getSize(); ++i) 
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Size: "<<array.getSize()<<std::endl;

    std::cout<<"Is empty: "<<(array.isEmpty() ? "Yes" : "No")<<std::endl;

    array.clear();
    std::cout<<"Cleared array. Size: "<<array.getSize()<<std::endl;
}
