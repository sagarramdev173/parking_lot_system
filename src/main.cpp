#include "parking_lot/parking_lot.h"
#include "vehicle/vehicle.h"
#include "vehicle/car.cpp"
#include "vehicle/motorcyle.cpp"
#include "vehicle/truck.cpp"
#include "vehicle/bicycle.cpp"

int main()
{
    ParkingLot mylot(20, "My Parking Lot");
    std::cout << "Parking Lot Name: " << mylot.getName() << std::endl;
    mylot.remaining_spots();
    car car1("ABC123");
    mylot.parkVehicle(car1);
    Motorcyle motorcycle1("XYZ789");
    mylot.parkVehicle(motorcycle1);
    mylot.remaining_spots();
    Truck truck1("DEF456");
    mylot.parkVehicle(truck1);
    Bicycle bicycle1;
    mylot.parkVehicle(bicycle1);
    mylot.removeVehicle(car1);
    mylot.remaining_spots();
    mylot.printParkingLot();
    return 0;
}