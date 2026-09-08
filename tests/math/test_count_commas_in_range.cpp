#include <gtest/gtest.h>
#include "math/count_commas_in_range.hpp"

TEST(CountCommasInRange, Example1) {
    // n = 1002: "1,000", "1,001", "1,002" contribute one comma each -> 3.
    EXPECT_EQ(countCommas(1002), 3);
}

TEST(CountCommasInRange, Example2) {
    // n = 998: every number from 1 to 998 has fewer than four digits -> 0.
    EXPECT_EQ(countCommas(998), 0);
}

TEST(CountCommasInRange, SmallestInput) {
    // n = 1: the single number "1" has no comma.
    EXPECT_EQ(countCommas(1), 0);
}

TEST(CountCommasInRange, BoundaryAtFirstComma) {
    // n = 999: still all three-digit numbers -> 0.
    EXPECT_EQ(countCommas(999), 0);
    // n = 1000: only "1,000" has a comma -> 1.
    EXPECT_EQ(countCommas(1000), 1);
    // n = 1001: "1,000" and "1,001" -> 2.
    EXPECT_EQ(countCommas(1001), 2);
}

TEST(CountCommasInRange, BoundaryAtTenThousand) {
    // n = 10000: the commas come from 1,000 .. 10,000, i.e. 10000 - 999 = 9001.
    EXPECT_EQ(countCommas(10000), 9001);
    // n = 10001: one more number, one more comma.
    EXPECT_EQ(countCommas(10001), 9002);
}

TEST(CountCommasInRange, LargestInput) {
    // n = 100000: numbers 1,000 .. 100,000 each hold exactly one comma
    // (100,000 has six digits, so a single separator) -> 100000 - 999 = 99001.
    EXPECT_EQ(countCommas(100000), 99001);
}
