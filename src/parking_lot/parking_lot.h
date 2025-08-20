#include "parkingspot.h"
#include <vector>

class ParkingLot {
private:
    std::vector<ParkingSpot> spots;
    std::string name;
    int car_rem_spots;
    int truck_rem_spots;
    int motorcycle_rem_spots;
    int bicycle_rem_spots;
public:
    ParkingLot(int numSpots, const std::string& name) : name(name){
        int carspots = numSpots/4;
        int truckspots = numSpots/4;
        int motorcyclespots = numSpots/4;
        int bicylespots = numSpots - (carspots + truckspots + motorcyclespots);
        car_rem_spots = carspots;
        truck_rem_spots = truckspots;
        motorcycle_rem_spots = motorcyclespots;
        bicycle_rem_spots = bicylespots;

        for (int i = 0; i < carspots; ++i) {
            spots.emplace_back(Slottype::car, nullptr);
        }
        for (int i = 0; i < truckspots; ++i) {
            spots.emplace_back(Slottype::truck, nullptr);
        }
        for (int i = 0; i < motorcyclespots; ++i) {
            spots.emplace_back(Slottype::Motocycle, nullptr);
        }
        for (int i = 0; i < bicylespots; ++i) {
            spots.emplace_back(Slottype::Bicycle, nullptr);
        }
    }

    bool parkVehicle(Vehicle& vehicle){
        for (auto& spot : spots) {
            if (spot.CanParkVehicle(vehicle) && spot.isAvailable()) {
                spot.ParkVehicle(vehicle);
                if (vehicle.getType() == VehicleType::car) car_rem_spots--;
                if (vehicle.getType() == VehicleType::truck) truck_rem_spots--;
                if (vehicle.getType() == VehicleType::Motocycle) motorcycle_rem_spots--;
                if (vehicle.getType() == VehicleType::Bicycle) bicycle_rem_spots--;
                return true;
            }
        }
        std::cout << "No suitable spot available for the vehicle." << std::endl;
        return false;
    }

    void removeVehicle(const Vehicle& vehicle){
        for (auto& spot : spots) {
            if (spot.getVehicle() == &vehicle) {
                if (vehicle.getType() == VehicleType::car) car_rem_spots++;
                if (vehicle.getType() == VehicleType::truck) truck_rem_spots++;
                if (vehicle.getType() == VehicleType::Motocycle) motorcycle_rem_spots++;
                if (vehicle.getType() == VehicleType::Bicycle) bicycle_rem_spots++;
                spot.RemoveVehicle();
                return;
            }
        }
        std::cout << "Vehicle not found in the parking lot." << std::endl;
    }

    string getName() const {
        return name;
    }

    void remaining_spots(){
        std::cout << "Remaining spots:" << std::endl;
        std::cout << "Car: " << car_rem_spots << std::endl;
        std::cout << "Truck: " << truck_rem_spots << std::endl;
        std::cout << "Motorcycle: " << motorcycle_rem_spots << std::endl;
        std::cout << "Bicycle: " << bicycle_rem_spots << std::endl;
        std::cout << "Total spots remaning: " << car_rem_spots + truck_rem_spots + motorcycle_rem_spots + bicycle_rem_spots << std::endl;
        std::cout << "\n";
    }

    void printParkingLot() const{
        for (const auto& spot : spots) {
            std::cout << "Spot Type: ";
            switch (spot.getType()) {
                case Slottype::car:
                    std::cout << "Car";
                    break;
                case Slottype::Motocycle:
                    std::cout << "Motocycle";
                    break;
                case Slottype::truck:
                    std::cout << "Truck";
                    break;
                case Slottype::Bicycle:
                    std::cout << "Bicycle";
                    break;
                default:
                    std::cout << "Unknown";
                    break;
            }
            std::cout << ", Vehicle: ";
            if (spot.getVehicle() != nullptr) {
                std::cout << spot.getVehicle()->getLicensePlate();
            } else {
                std::cout << "Empty";
            }
            std::cout << std::endl;
        }
    }
};