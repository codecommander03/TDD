#include <gtest/gtest.h>
#include "arrays/cinema_seat_allocation.hpp"

TEST(CinemaSeatAllocation, Example1) {
    std::vector<std::vector<int>> reserved = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    EXPECT_EQ(maxNumberOfFamilies(3, reserved), 4);
}

TEST(CinemaSeatAllocation, Example2) {
    std::vector<std::vector<int>> reserved = {{2, 1}, {1, 8}, {2, 6}};
    EXPECT_EQ(maxNumberOfFamilies(2, reserved), 2);
}

TEST(CinemaSeatAllocation, Example3) {
    std::vector<std::vector<int>> reserved = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
    EXPECT_EQ(maxNumberOfFamilies(4, reserved), 4);
}

TEST(CinemaSeatAllocation, NoReservations) {
    // No reservations: every one of the 5 rows seats two families -> 10.
    std::vector<std::vector<int>> reserved = {};
    EXPECT_EQ(maxNumberOfFamilies(5, reserved), 10);
}
