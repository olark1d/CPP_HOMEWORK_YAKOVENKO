#include "vector2d.h"

int Vector2d::instanceCount = 0;

Vector2d::Vector2d(float x, float y) : x(x), y(y) 
{
    ++instanceCount;
}

Vector2d::Vector2d(const Vector2d& other) : x(other.x), y(other.y) 
{
    ++instanceCount;
}

Vector2d::~Vector2d() 
{
    --instanceCount;
}

Vector2d& Vector2d::operator=(const Vector2d& other) 
{
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) const 
{
    return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const 
{
    return Vector2d(x - secondVector.x, y - secondVector.y);
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) 
{
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) 
{
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

void Vector2d::operator*=(float scalar) 
{
    x *= scalar;
    y *= scalar;
}

float Vector2d::operator()() const 
{
    return std::sqrt(x * x + y * y);
}

float& Vector2d::operator[](std::size_t idx) 
{
    if (idx == 0) return x;
    else if (idx == 1) return y;
    throw std::out_of_range("Index out of range");
}

const float& Vector2d::operator[](std::size_t idx) const 
{
    if (idx == 0) return x;
    else if (idx == 1) return y;
    throw std::out_of_range("Index out of range");
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vec) 
{
    os << "{" << vec.x << "; " << vec.y << "}";
    return os;
}

std::
