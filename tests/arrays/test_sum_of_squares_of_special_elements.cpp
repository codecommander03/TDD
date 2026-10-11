#include <gtest/gtest.h>
#include "arrays/sum_of_squares_of_special_elements.hpp"

TEST(SumOfSquaresOfSpecialElements, Example1) {
    // Example 1: n = 4, special positions 1, 2, 4 -> 1 + 4 + 16 = 21.
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(sumOfSquares(nums), 21);
}

TEST(SumOfSquaresOfSpecialElements, Example2) {
    // Example 2: n = 6, special positions 1, 2, 3, 6
    // -> 4 + 49 + 1 + 9 = 63.
    std::vector<int> nums = {2, 7, 1, 19, 18, 3};
    EXPECT_EQ(sumOfSquares(nums), 63);
}

TEST(SumOfSquaresOfSpecialElements, SingleElement) {
    // n = 1: only position 1 -> 5^2 = 25.
    std::vector<int> nums = {5};
    EXPECT_EQ(sumOfSquares(nums), 25);
}

TEST(SumOfSquaresOfSpecialElements, PrimeLength) {
    // n = 5 is prime: only positions 1 and 5 -> 1 + 25 = 26.
    std::vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(sumOfSquares(nums), 26);
}

TEST(SumOfSquaresOfSpecialElements, AllSame) {
    // n = 4, positions 1, 2, 4 -> 3 * 3^2 = 27.
    std::vector<int> nums = {3, 3, 3, 3};
    EXPECT_EQ(sumOfSquares(nums), 27);
}
