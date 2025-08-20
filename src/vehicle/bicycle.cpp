#include "vehicle.h"
#include <string>

class Bicycle : public Vehicle
{
public:
    Bicycle(std::string licensePlate = "No license plate") : Vehicle(licensePlate, VehicleType::Bicycle) {}
};