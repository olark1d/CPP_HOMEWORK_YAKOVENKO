#include <iostream>
#include "Vehicle.h"
#include "ParkingSpace.h"

Vehicle::Vehicle(int mass, int engine, const Vector2d& position)
    : m_mass(mass), m_engine(engine), m_position(position)
{
    std::cout << "Using c-tor with 3 parameters\n";
    getEngineDisplacement();
}

Vehicle::~Vehicle()
{
    std::cout << "D-tor is being called, object is being destroyed\n";
}

void Vehicle::move(const Vector2d& moveBy)
{
    m_position.x += moveBy.x;
    m_position.y += moveBy.y;
}

float Vehicle::getMileage() const
{
    return 4 * getMassMileageCoefficient() * getEngineDisplacement();
}

void Vehicle::printPosition() const
{
    std::cout << "{ " << m_position.x << ", " << m_position.y << " }\n";
}

void Vehicle::driveToParking(ParkingSpace& parking)
{
    parking.addVehicle(this);
}

float Vehicle::getMassMileageCoefficient() const
{
    if (m_mass < 1100)
    {
        return 0.5f;
    }

    if (m_mass < 1600)
    {
        return 1.0f;
    }

    if (m_mass < 2500)
    {
        return 1.3f;
    }

    return 2.0f;
}

float Vehicle::getEngineDisplacement() const
{
    if (m_engine < 1600)
    {
        return 1.0f;
    }

    if (m_engine < 3)
    {
        return 2.0f;
    }

    return 3.0f;
}
