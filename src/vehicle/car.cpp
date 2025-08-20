#include "vehicle.h"

class car : public Vehicle
{
public:
    car(std::string licensePlate) : Vehicle(licensePlate, VehicleType::car) {}
};