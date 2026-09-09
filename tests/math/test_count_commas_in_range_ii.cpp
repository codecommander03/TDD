#include <gtest/gtest.h>
#include "math/count_commas_in_range_ii.hpp"

TEST(CountCommasInRangeII, Example1) {
    // n = 1002: only "1,000", "1,001", "1,002" carry a comma -> 3.
    EXPECT_EQ(countCommas(1002), 3);
}

TEST(CountCommasInRangeII, Example2) {
    // n = 998: every number from 1 to 998 has at most three digits -> 0.
    EXPECT_EQ(countCommas(998), 0);
}

TEST(CountCommasInRangeII, SmallestInput) {
    // n = 1: the single number "1" has no comma.
    EXPECT_EQ(countCommas(1), 0);
}

TEST(CountCommasInRangeII, BoundaryAtFirstComma) {
    // n = 999: still all three-digit numbers -> 0.
    EXPECT_EQ(countCommas(999), 0);
    // n = 1000: only "1,000" has a comma -> 1.
    EXPECT_EQ(countCommas(1000), 1);
}

TEST(CountCommasInRangeII, SingleCommaRange) {
    // Every integer in [1000, 999999] is written with exactly one comma, so
    // n = 999999 gives 999999 - 1000 + 1 = 999000.
    EXPECT_EQ(countCommas(999999), 999000);
}

TEST(CountCommasInRangeII, SecondCommaAppears) {
    // n = 1000000 splits into two groups:
    //   x >= 1000    -> 1000000 - 1000 + 1    = 999001 commas
    //   x >= 1000000 -> 1000000 - 1000000 + 1 =      1 comma  ("1,000,000")
    // total 999002.
    EXPECT_EQ(countCommas(1000000), 999002);
}

TEST(CountCommasInRangeII, ThirdCommaAppears) {
    // n = 1000000000:
    //   x >= 1e3 -> 1000000000 - 1000 + 1       = 999999001
    //   x >= 1e6 -> 1000000000 - 1000000 + 1    = 999000001
    //   x >= 1e9 -> 1000000000 - 1000000000 + 1 =         1  ("1,000,000,000")
    // total 999999001 + 999000001 + 1 = 1998999003.
    EXPECT_EQ(countCommas(1000000000LL), 1998999003LL);
}

TEST(CountCommasInRangeII, LargestInput) {
    // n = 1e18, one term per power of 1000 up to 1e18:
    //   1e18 - 1e3  + 1 = 999999999999999001
    //   1e18 - 1e6  + 1 = 999999999999000001
    //   1e18 - 1e9  + 1 = 999999999000000001
    //   1e18 - 1e12 + 1 = 999999000000000001
    //   1e18 - 1e15 + 1 = 999000000000000001
    //   1e18 - 1e18 + 1 =                  1
    // i.e. 5e18 - (1e3 + 1e6 + 1e9 + 1e12 + 1e15) + 6
    //    = 5000000000000000000 - 1001001001001000 + 6 = 4998998998998999006.
    EXPECT_EQ(countCommas(1000000000000000000LL), 4998998998998999006LL);
}
