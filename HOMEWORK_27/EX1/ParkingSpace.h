#pragma once

class Vehicle; //forward declaration to not include "Vehicle.h" here

class ParkingSpace
{
public:
    bool addVehicle(Vehicle* vehicle);
    void removeVehicle(Vehicle* vehicle);

    int getFreeSpaces();


private:
    unsigned m_freeSlotIndex = 0;

    static constexpr unsigned PARKING_CAPACITY = 10;
    Vehicle* m_slots[PARKING_CAPACITY] = { nullptr };
};