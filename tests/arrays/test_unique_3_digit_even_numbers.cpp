#include <gtest/gtest.h>
#include "arrays/unique_3_digit_even_numbers.hpp"

TEST(Unique3DigitEvenNumbers, Example1) {
    // Example 1: all four digits are distinct and nonzero, so the last digit
    // must be 2 or 4 and the first two are any ordered pair of the remaining
    // three: 3 * 2 = 6 numbers per choice of last digit -> 12.
    std::vector<int> digits = {1, 2, 3, 4};
    EXPECT_EQ(totalNumbers(digits), 12);
}

TEST(Unique3DigitEvenNumbers, Example2) {
    // Example 2: the only multiset is {0, 2, 2}; its orderings are 022, 202,
    // 220. The leading zero drops 022, leaving 202 and 220.
    std::vector<int> digits = {0, 2, 2};
    EXPECT_EQ(totalNumbers(digits), 2);
}

TEST(Unique3DigitEvenNumbers, Example3) {
    // Example 3: every ordering of {6, 6, 6} is 666.
    std::vector<int> digits = {6, 6, 6};
    EXPECT_EQ(totalNumbers(digits), 1);
}

TEST(Unique3DigitEvenNumbers, Example4) {
    // Example 4: with only odd digits no arrangement can end in an even digit.
    std::vector<int> digits = {1, 3, 5};
    EXPECT_EQ(totalNumbers(digits), 0);
}

TEST(Unique3DigitEvenNumbers, TwoLeadingZeroCandidates) {
    // {0, 0, 2} orders as 002, 020, 200; the first two have a leading zero and
    // 020 is not a three-digit number either, so only 200 counts.
    std::vector<int> digits = {0, 0, 2};
    EXPECT_EQ(totalNumbers(digits), 1);
}

TEST(Unique3DigitEvenNumbers, RepeatedDigitsCountedOnce) {
    // Two 2s and two 4s give the multisets {2,2,4} -> 224, 242, 422 and
    // {2,4,4} -> 244, 424, 442. All six are even and distinct.
    std::vector<int> digits = {2, 2, 4, 4};
    EXPECT_EQ(totalNumbers(digits), 6);
}
