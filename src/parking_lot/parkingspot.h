#include <iostream>
#include <string>
#include "../vehicle/vehicle.h"

#ifndef PARKING_SPOT
#define PARKING_SPOT
enum class Slottype { Bicycle, Motocycle, car, truck };

class ParkingSpot {
private:
    Slottype type;
    Vehicle* currentvehicle;
public:
    ParkingSpot(Slottype type, Vehicle* vehicle) : type(type), currentvehicle(vehicle) {}
    Slottype getType() const { return type; }
    Vehicle* getVehicle() const { return currentvehicle; }

    bool isAvailable() const { return currentvehicle == nullptr; }

    bool CanParkVehicle(const Vehicle& vehicle) {
        switch (vehicle.getType()) {
            case VehicleType::car:
                return type == Slottype::car;
            case VehicleType::Bicycle:
                return type == Slottype::Bicycle;
            case VehicleType::Motocycle:
                return type == Slottype::Motocycle;
            case VehicleType::truck:
                return type == Slottype::truck;
            default:
                std::cout << "Vehicle type not recognized." << std::endl;
                return false;
        }
    }
    bool ParkVehicle(Vehicle& vehicle) {
        if (isAvailable() && CanParkVehicle(vehicle)) {
            currentvehicle = &vehicle;
            std::cout << "Vehicle parked successfully" << std::endl;
            return true;
        }
        std::cout << "Failed to park vehicle" << std::endl;
        return false;
    }
    bool RemoveVehicle(){
        if (currentvehicle == nullptr) {
            std::cout << "No vehicle to remove" << std::endl;
            return false;
        }
        currentvehicle = nullptr;
        std::cout << "Vehicle removed successfully" << std::endl;
        return true;
    }
};
#endif // !PARKING_SPOT