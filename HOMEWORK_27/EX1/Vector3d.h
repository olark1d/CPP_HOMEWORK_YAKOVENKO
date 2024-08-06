#pragma once

struct Vector3d
{
    float x = 0;
    float y = 0;
    float z = 0;

    // Constructors
    Vector3d() = default;
    Vector3d(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

    // Methods
    Vector3d crossProduct(const Vector3d& other) const
    {
        return Vector3d(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
};

