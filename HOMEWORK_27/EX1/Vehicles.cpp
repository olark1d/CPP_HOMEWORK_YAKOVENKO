#include <iostream>
#include "Vehicle.h"
#include "ParkingSpace.h"
#include "Vector3d.h"

void print(const Vehicle& vehicle)
{
    vehicle.printPosition();
}

int main()
{
    Vehicle* newVehicleOnHeap = new Vehicle{ 1500, 1400 };
    Vehicle* newVehicleOnHeap2 = new Vehicle{ 1500, 1400 };

    std::cout << "Mileage calculated: " << newVehicleOnHeap->getMileage() << std::endl;

    ParkingSpace parking;

    newVehicleOnHeap->driveToParking(parking);

    parking.addVehicle(newVehicleOnHeap);
    parking.addVehicle(newVehicleOnHeap2);

    std::cout << "Free spaces are: " << parking.getFreeSpaces() << std::endl;

    std::cout << "Vehicle mass: " << newVehicleOnHeap->getMass() << std::endl;

    print(*newVehicleOnHeap);

    delete newVehicleOnHeap;

    Vehicle myCar(1500, 1300);
    myCar.move({ 25, 0 });
    myCar.move({ 0, -30 });

    std::cout << "Car 1 position: ";
    myCar.printPosition();

    std::cout << "Car 1 mileage: " << myCar.getMileage() << std::endl;

    Vector2d v1(1, 2);
    Vector2d v2(3, 4);

    std::cout << "Dot product of v1 and v2: " << v1.dotProduct(v2) << std::endl;
    Vector2d v3 = v1.negate();
    std::cout << "Negated v1: {" << v3.x << ", " << v3.y << "}\n";

    auto state = v1.getRelativeState(v2);
    std::cout << "Relative state between v1 and v2: " << static_cast<int>(state) << std::endl;

    Vector3d u1(1, 0, 0);
    Vector3d u2(0, 1, 0);
    Vector3d u3 = u1.crossProduct(u2);
    std::cout << "Cross product of u1 and u2: {" << u3.x << ", " << u3.y << ", " << u3.z << "}\n";
}
