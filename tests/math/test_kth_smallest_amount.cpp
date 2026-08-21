#include <gtest/gtest.h>
#include "math/kth_smallest_amount.hpp"

TEST(KthSmallestAmount, Example1) {
    // Only multiples of 3 are reachable: 3, 6, 9, ...
    std::vector<int> coins = {3, 6, 9};
    EXPECT_EQ(findKthSmallest(coins, 3), 9);
}

TEST(KthSmallestAmount, Example2) {
    // 2, 4, 5, 6, 8, 10, 12 -> the 7th is 12.
    std::vector<int> coins = {5, 2};
    EXPECT_EQ(findKthSmallest(coins, 7), 12);
}

TEST(KthSmallestAmount, SingleCoin) {
    std::vector<int> coins = {1};
    EXPECT_EQ(findKthSmallest(coins, 1), 1);
    EXPECT_EQ(findKthSmallest(coins, 10), 10);
}

TEST(KthSmallestAmount, OverlappingProgressions) {
    // 2, 3, 4, 5, 6 -> the 5th is 6, counted once despite 6 being reachable twice.
    std::vector<int> coins = {2, 3, 5};
    EXPECT_EQ(findKthSmallest(coins, 1), 2);
    EXPECT_EQ(findKthSmallest(coins, 5), 6);
}

TEST(KthSmallestAmount, LargeKOnSingleCoin) {
    // Exercises the 64-bit range: the answer is far beyond int.
    std::vector<int> coins = {25};
    EXPECT_EQ(findKthSmallest(coins, 1000000000), 25000000000LL);
}

TEST(KthSmallestAmount, CoprimeCoinsForceLargeLcm) {
    // The full-subset LCM (2*3*5*7*11*13 = 30030) still fits, but partial
    // products are what actually drive the inclusion-exclusion here.
    std::vector<int> coins = {2, 3, 5, 7, 11, 13};
    // 1 is unreachable, so the sequence runs 2, 3, ..., 11 and the 10th is 11.
    EXPECT_EQ(findKthSmallest(coins, 10), 11);
}

TEST(KthSmallestAmount, SharedFactorsCountedOnce) {
    // 4, 6, 8, 10, 12, 15, 16, 18, 20, 24, 28, 30 -> the 12th is 30, which is a
    // multiple of 6, 10 and 15 at once.
    std::vector<int> coins = {4, 6, 10, 15};
    EXPECT_EQ(findKthSmallest(coins, 12), 30);
}
