#include <gtest/gtest.h>
#include "math/check_divisibility_by_digit_sum_and_product.hpp"

TEST(CheckDivisibilityByDigitSumAndProduct, Example1) {
    // 99: sum 18, product 81 -> 99 % 99 == 0.
    EXPECT_TRUE(checkDivisibility(99));
}

TEST(CheckDivisibilityByDigitSumAndProduct, Example2) {
    // 23: sum 5, product 6 -> 23 % 11 != 0.
    EXPECT_FALSE(checkDivisibility(23));
}

TEST(CheckDivisibilityByDigitSumAndProduct, SingleDigit) {
    // d: sum d, product d -> d % 2d == 0 only when the remainder is d itself,
    // which is never 0 for d >= 1.
    EXPECT_FALSE(checkDivisibility(7));
    // 0 is outside the constraints, but 1 % 2 == 1 -> false.
    EXPECT_FALSE(checkDivisibility(1));
}

TEST(CheckDivisibilityByDigitSumAndProduct, ZeroDigitMakesProductZero) {
    // 10: sum 1, product 0 -> divisor 1, so every such number qualifies.
    EXPECT_TRUE(checkDivisibility(10));
    // 105: sum 6, product 0 -> 105 % 6 == 3 -> false.
    EXPECT_FALSE(checkDivisibility(105));
}

TEST(CheckDivisibilityByDigitSumAndProduct, LargeInput) {
    // 999999999: sum 81, product 9^9 = 387420489 -> divisor 387420570.
    EXPECT_FALSE(checkDivisibility(999999999));
}
