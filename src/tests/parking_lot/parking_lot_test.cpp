
#include "gtest/gtest.h"
#include "../../parking_lot/parking_lot.h"
#include "../../vehicle/vehicle.h"

TEST(ParkingLotTest, ParkAndRemoveVehicle) {
    ParkingLot parkingLot(10, "Test Lot");
    Vehicle car("1234", VehicleType::car);

    EXPECT_TRUE(parkingLot.parkVehicle(car));
    parkingLot.removeVehicle(car);
}

TEST(ParkingLotTest, ParkFull) {
    ParkingLot parkingLot(4, "Test Lot");
    Vehicle car1("1234", VehicleType::car);
    Vehicle car2("5678", VehicleType::car);

    EXPECT_TRUE(parkingLot.parkVehicle(car1));
    EXPECT_FALSE(parkingLot.parkVehicle(car2));
}
