#pragma once

#include <cmath>

struct Vector2d
{
    float x = 0;
    float y = 0;

    // Constructors
    Vector2d() = default;
    Vector2d(float xVal, float yVal) : x(xVal), y(yVal) {}
    Vector2d(float x0, float y0, float x1, float y1)
        : x(x1 - x0), y(y1 - y0) {}

    // Methods
    float dotProduct(const Vector2d& other) const
    {
        return x * other.x + y * other.y;
    }

    Vector2d negate() const
    {
        return Vector2d(-x, -y);
    }

    enum class VectorRelativeState
    {
        Identical,
        CoDirected,
        OppositeDirected,
        AcuteAngle,
        ObtuseAngle,
        RightAngle
    };

    VectorRelativeState getRelativeState(const Vector2d& other) const
    {
        float dot = dotProduct(other);
        float cross = x * other.y - y * other.x;
        float cosTheta = dot / (std::sqrt(x * x + y * y) * std::sqrt(other.x * other.x + other.y * other.y));

        if (dot == 0)
            return VectorRelativeState::RightAngle;
        if (cross == 0)
        {
            return (dot > 0) ? VectorRelativeState::CoDirected : VectorRelativeState::OppositeDirected;
        }
        if (cosTheta > 0)
            return VectorRelativeState::AcuteAngle;
        return VectorRelativeState::ObtuseAngle;
    }

    void scale(float factorX, float factorY)
    {
        x *= factorX;
        y *= factorY;
    }
};
