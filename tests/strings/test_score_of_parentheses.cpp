#include <gtest/gtest.h>
#include "strings/score_of_parentheses.hpp"

TEST(ScoreOfParentheses, Example1) {
    // Example 1: "()" -> 1.
    std::string s = "()";
    EXPECT_EQ(scoreOfParentheses(s), 1);
}

TEST(ScoreOfParentheses, Example2) {
    // Example 2: "(())" -> 2 * 1 = 2.
    std::string s = "(())";
    EXPECT_EQ(scoreOfParentheses(s), 2);
}

TEST(ScoreOfParentheses, Example3) {
    // Example 3: "()()" -> 1 + 1 = 2.
    std::string s = "()()";
    EXPECT_EQ(scoreOfParentheses(s), 2);
}

TEST(ScoreOfParentheses, NestedAndAdjacent) {
    // "(()(()))" -> 2 * (1 + 2) = 6.
    std::string s = "(()(()))";
    EXPECT_EQ(scoreOfParentheses(s), 6);
}

TEST(ScoreOfParentheses, DeepNesting) {
    // "((()))" -> 2 * 2 * 1 = 4.
    std::string s = "((()))";
    EXPECT_EQ(scoreOfParentheses(s), 4);
}

TEST(ScoreOfParentheses, SumOfGroups) {
    // "()(())" -> 1 + 2 = 3.
    std::string s = "()(())";
    EXPECT_EQ(scoreOfParentheses(s), 3);
}
