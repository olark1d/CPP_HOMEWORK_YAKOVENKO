#pragma once

#include <iostream>
#include <cmath>

class Vector2d 
{
private:
    float x, y;
    static int instanceCount;

public:
    Vector2d(float x = 0.0, float y = 0.0);
    Vector2d(const Vector2d& other);
    ~Vector2d();

    Vector2d& operator=(const Vector2d& other);

    Vector2d operator+(const Vector2d& secondVector) const;
    Vector2d operator-(const Vector2d& secondVector) const;

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    void operator*=(float scalar);

    float operator()() const;

    float& operator[](std::size_t idx);
    const float& operator[](std::size_t idx) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);
    friend std::istream& operator>>(std::istream& is, Vector2d& vec);

    static int getInstanceCount();
};

int Vector2d::instanceCount = 0;