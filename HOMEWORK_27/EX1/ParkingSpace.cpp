#include "ParkingSpace.h"
#include "Vehicle.h"


bool ParkingSpace::addVehicle(Vehicle* vehicle)
{
    if (m_freeSlotIndex < PARKING_CAPACITY)
    {
        m_slots[m_freeSlotIndex] = vehicle;
        m_freeSlotIndex++;
        return true;
    }

    return false;
}

void ParkingSpace::removeVehicle(Vehicle* vehicle)
{
    //TODO
}

int ParkingSpace::getFreeSpaces()
{
    return PARKING_CAPACITY - m_freeSlotIndex;
}