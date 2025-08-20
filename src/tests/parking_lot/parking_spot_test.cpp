
#include "gtest/gtest.h"
#include "../../parking_lot/parkingspot.h"
#include "../../vehicle/vehicle.h"

TEST(ParkingSpotTest, ParkAndRemoveVehicle) {
    ParkingSpot parkingSpot(Slottype::car, nullptr);
    Vehicle car("1234", VehicleType::car);

    EXPECT_TRUE(parkingSpot.isAvailable());
    EXPECT_TRUE(parkingSpot.CanParkVehicle(car));
    EXPECT_TRUE(parkingSpot.ParkVehicle(car));
    EXPECT_FALSE(parkingSpot.isAvailable());
    EXPECT_EQ(parkingSpot.getVehicle(), &car);

    EXPECT_TRUE(parkingSpot.RemoveVehicle());
    EXPECT_TRUE(parkingSpot.isAvailable());
    EXPECT_EQ(parkingSpot.getVehicle(), nullptr);
}

TEST(ParkingSpotTest, ParkWrongVehicleType) {
    ParkingSpot parkingSpot(Slottype::car, nullptr);
    Vehicle truck("5678", VehicleType::truck);

    EXPECT_TRUE(parkingSpot.isAvailable());
    EXPECT_FALSE(parkingSpot.CanParkVehicle(truck));
    EXPECT_FALSE(parkingSpot.ParkVehicle(truck));
    EXPECT_TRUE(parkingSpot.isAvailable());
    EXPECT_EQ(parkingSpot.getVehicle(), nullptr);
}
