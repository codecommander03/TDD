#include <gtest/gtest.h>
#include "strings/min_add_to_make_valid.hpp"

TEST(MinAddToMakeValid, Example1) {
    // Example 1: "())" -> 1, the last ')' needs a '('.
    std::string s = "())";
    EXPECT_EQ(minAddToMakeValid(s), 1);
}

TEST(MinAddToMakeValid, Example2) {
    // Example 2: "(((" -> 3, each '(' needs a ')'.
    std::string s = "(((";
    EXPECT_EQ(minAddToMakeValid(s), 3);
}

TEST(MinAddToMakeValid, AlreadyValid) {
    // "()" is already valid -> 0.
    std::string s = "()";
    EXPECT_EQ(minAddToMakeValid(s), 0);
}

TEST(MinAddToMakeValid, SingleClose) {
    // ")" -> 1, add a '(' before it.
    std::string s = ")";
    EXPECT_EQ(minAddToMakeValid(s), 1);
}

TEST(MinAddToMakeValid, CloseBeforeOpen) {
    // ")(" -> 2: the ')' can't use the later '(', so both need partners.
    std::string s = ")(";
    EXPECT_EQ(minAddToMakeValid(s), 2);
}

TEST(MinAddToMakeValid, UnmatchedOnBothSides) {
    // "()))((" -> 4: "()" matches, then two lone ')' and two lone '('.
    std::string s = "()))((";
    EXPECT_EQ(minAddToMakeValid(s), 4);
}
