#include <gtest/gtest.h>
#include "math/max_sum_of_squares_of_digits.hpp"

TEST(MaxSumOfSquaresOfDigits, PacksNines) {
    // 9 + 9 + 2 = 20; score 81 + 81 + 4 beats any spread-out split.
    EXPECT_EQ(maxSumOfSquares(3, 20), "992");
}

TEST(MaxSumOfSquaresOfDigits, TieBreaksToLargerNumber) {
    // 89 and 98 both score 145; 98 is larger.
    EXPECT_EQ(maxSumOfSquares(2, 17), "98");
}

TEST(MaxSumOfSquaresOfDigits, PadsWithZeros) {
    // Candidates 30, 21, 12: 30 scores 9, beating 21/12 at 5.
    EXPECT_EQ(maxSumOfSquares(2, 3), "30");
}

TEST(MaxSumOfSquaresOfDigits, ImpossibleReturnsEmpty) {
    // One digit can be at most 9 < 10.
    EXPECT_EQ(maxSumOfSquares(1, 10), "");
}

TEST(MaxSumOfSquaresOfDigits, ExactlyAllNines) {
    // 27 = 9 * 3 is the maximum reachable sum for 3 digits.
    EXPECT_EQ(maxSumOfSquares(3, 27), "999");
}

TEST(MaxSumOfSquaresOfDigits, SingleDigit) {
    EXPECT_EQ(maxSumOfSquares(1, 1), "1");
}
