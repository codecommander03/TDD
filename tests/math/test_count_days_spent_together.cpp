#include <gtest/gtest.h>
#include "math/count_days_spent_together.hpp"

// LeetCode Example 1: together Aug 16, 17, 18 -> 3
TEST(CountDaysSpentTogether, Example1) {
    EXPECT_EQ(countDaysTogether("08-15", "08-18", "08-16", "08-19"), 3);
}

// LeetCode Example 2: Alice leaves Oct 31 before Bob arrives Nov 1 -> 0
TEST(CountDaysSpentTogether, Example2) {
    EXPECT_EQ(countDaysTogether("10-01", "10-31", "11-01", "12-31"), 0);
}

// Same single day for both -> 1
TEST(CountDaysSpentTogether, SameSingleDay) {
    EXPECT_EQ(countDaysTogether("01-01", "01-01", "01-01", "01-01"), 1);
}

// Both stay the whole non-leap year -> 365
TEST(CountDaysSpentTogether, WholeYear) {
    EXPECT_EQ(countDaysTogether("01-01", "12-31", "01-01", "12-31"), 365);
}

// Overlap crosses Feb -> Mar: Feb 28, Mar 1, Mar 2 (no Feb 29) -> 3
TEST(CountDaysSpentTogether, AcrossMonthBoundary) {
    EXPECT_EQ(countDaysTogether("02-27", "03-02", "02-28", "03-05"), 3);
}

// Bob's June stay lies inside Alice's year -> 30 days of June
TEST(CountDaysSpentTogether, OneRangeContainsOther) {
    EXPECT_EQ(countDaysTogether("01-01", "12-31", "06-01", "06-30"), 30);
}

// Back-to-back stays: Alice leaves May 10, Bob arrives May 11 -> 0
TEST(CountDaysSpentTogether, AdjacentNoOverlap) {
    EXPECT_EQ(countDaysTogether("05-01", "05-10", "05-11", "05-20"), 0);
}
