
#include "gtest/gtest.h"
#include "../../vehicle/vehicle.h"

TEST(VehicleTest, Getters) {
    Vehicle vehicle("1234", VehicleType::car);
    EXPECT_EQ(vehicle.getLicensePlate(), "1234");
    EXPECT_EQ(vehicle.getType(), VehicleType::car);
}
