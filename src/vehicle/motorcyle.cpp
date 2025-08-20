#include "vehicle.h"

class Motorcyle : public Vehicle
{
public:
    Motorcyle(std::string licensePlate) : Vehicle(licensePlate, VehicleType::Motocycle) {}
};