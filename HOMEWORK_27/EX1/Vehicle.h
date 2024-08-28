#pragma once
#include "Vector2d.h"

class ParkingSpace;

class Vehicle
{
public:
    Vehicle(int mass, int engine, const Vector2d& position = { 0, 0 });
    ~Vehicle();

    void move(const Vector2d& moveBy);
    float getMileage() const;
    void printPosition() const;
    int getMass() const { return m_mass; }

    void driveToParking(ParkingSpace& parking);

private:
    float getMassMileageCoefficient() const;
    float getEngineDisplacement() const;

    int m_mass = 0;
    int m_engine = 0;
    Vector2d m_position{};
};
