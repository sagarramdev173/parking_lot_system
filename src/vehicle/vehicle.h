#include <iostream>
#include <string>

#ifndef VEHICLE
#define VEHICLE
enum class VehicleType{ Bicycle, Motocycle, car, truck};

using namespace std;

class Vehicle
{
private:
    std::string licensePlate;
    VehicleType type;
public:
    Vehicle(std::string licensePlate, VehicleType type) : licensePlate(licensePlate), type(type) {}
    virtual ~Vehicle() = default;
    std::string getLicensePlate() const { return licensePlate; }
    VehicleType getType() const { return type; }
};
#endif // !VEHICLE