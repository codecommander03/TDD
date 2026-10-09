#include <gtest/gtest.h>
#include "strings/min_insertions_to_balance.hpp"

TEST(MinInsertionsToBalance, Example1) {
    // Example 1: "(()))" -> 1, add one ')' to close the outer '('.
    std::string s = "(()))";
    EXPECT_EQ(minInsertions(s), 1);
}

TEST(MinInsertionsToBalance, Example2) {
    // Example 2: "())" -> 0, already balanced.
    std::string s = "())";
    EXPECT_EQ(minInsertions(s), 0);
}

TEST(MinInsertionsToBalance, Example3) {
    // Example 3: "))())(" -> 3: '(' before the leading "))", and "))"
    // after the trailing '('.
    std::string s = "))())(";
    EXPECT_EQ(minInsertions(s), 3);
}

TEST(MinInsertionsToBalance, SingleOpen) {
    // "(" needs "))" after it -> 2.
    std::string s = "(";
    EXPECT_EQ(minInsertions(s), 2);
}

TEST(MinInsertionsToBalance, SingleClose) {
    // ")" needs a '(' before and a ')' after -> 2.
    std::string s = ")";
    EXPECT_EQ(minInsertions(s), 2);
}

TEST(MinInsertionsToBalance, OneCloseShort) {
    // "()" has only one ')' for its '(' -> 1.
    std::string s = "()";
    EXPECT_EQ(minInsertions(s), 1);
}

TEST(MinInsertionsToBalance, SplitPairBeforeOpen) {
    // "()()))": the first "()" is one ')' short before the next '(' (1),
    // "())" is fine, the last ')' needs '(' and ')' (2) -> 3.
    std::string s = "()()))";
    EXPECT_EQ(minInsertions(s), 3);
}
