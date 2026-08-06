#include <gtest/gtest.h>
#include "math/smallest_divisible_digit_product.hpp"

TEST(SmallestDivisibleDigitProduct, NAlreadySatisfies) {
    EXPECT_EQ(smallestNumber(10, 2), 10);
}

TEST(SmallestDivisibleDigitProduct, NeedsToSearchForward) {
    EXPECT_EQ(smallestNumber(15, 3), 16);
}

TEST(SmallestDivisibleDigitProduct, SingleDigitN) {
    EXPECT_EQ(smallestNumber(3, 3), 3);
}

TEST(SmallestDivisibleDigitProduct, ZeroDigitTrick) {
    // Any number containing a 0 digit has product 0, divisible by any t
    EXPECT_EQ(smallestNumber(9, 5), 10);
}