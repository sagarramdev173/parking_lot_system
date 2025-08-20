#include "vehicle.h"

class Truck : public Vehicle
{
public:
    Truck(std::string licensePlate) : Vehicle(licensePlate, VehicleType::truck) {}
};