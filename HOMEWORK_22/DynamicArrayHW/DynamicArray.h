#pragma once
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

template <typename Type>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    Type& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();
    void push_back(const Type& element);

    void pop_back();
    Type back() const;

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;
    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;

private:
    Type* m_data;
    std::size_t m_size;
    std::size_t m_capacity;

    void reallocate(std::size_t newCapacity);
};

template <typename Type>
DynamicArray<Type>::DynamicArray()
    : m_data(nullptr), m_size(0), m_capacity(0) {}

template <typename Type>
DynamicArray<Type>::DynamicArray(std::size_t size)
    : m_size(size), m_capacity(size)
{
    m_data = new Type[m_capacity];
}

template <typename Type>
DynamicArray<Type>::DynamicArray(const DynamicArray& other)
    : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_data = new Type[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

template <typename Type>
DynamicArray<Type>::~DynamicArray()
{
    delete[] m_data;
}

template <typename Type>
DynamicArray<Type>& DynamicArray<Type>::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] m_data;

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new Type[m_capacity];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    return *this;
}

template <typename Type>
Type& DynamicArray<Type>::operator[](std::size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename Type>
void DynamicArray<Type>::setSize(std::size_t newSize)
{
    if (newSize > m_capacity)
    {
        reserve(newSize);
    }
    m_size = newSize;
}

template <typename Type>
std::size_t DynamicArray<Type>::getSize() const
{
    return m_size;
}

template <typename Type>
void DynamicArray<Type>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <typename Type>
void DynamicArray<Type>::push_back(const Type& element)
{
    if (m_size >= m_capacity)
    {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = element;
}

template <typename Type>
void DynamicArray<Type>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template <typename Type>
Type DynamicArray<Type>::back() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("Array is empty");
    }
    return m_data[m_size - 1];
}

template <typename Type>
void DynamicArray<Type>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > m_capacity)
    {
        reallocate(reservedSpace);
    }
}

template <typename Type>
std::size_t DynamicArray<Type>::getCapacity() const
{
    return m_capacity;
}

template <typename Type>
void DynamicArray<Type>::shrinkToFit()
{
    if (m_size < m_capacity)
    {
        reallocate(m_size);
    }
}

template <typename Type>
bool DynamicArray<Type>::operator==(const DynamicArray& other) const
{
    if (m_size != other.m_size)
    {
        return false;
    }
    for (std::size_t i = 0; i < m_size; ++i)
    {
        if (m_data[i] != other.m_data[i])
        {
            return false;
        }
    }
    return true;
}

template <typename Type>
void DynamicArray<Type>::reallocate(std::size_t newCapacity)
{
    Type* newData = new Type[newCapacity];
    std::copy(m_data, m_data + m_size, newData);
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}
