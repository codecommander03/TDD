#include <gtest/gtest.h>
#include "strings/longest_valid_parentheses.hpp"

TEST(LongestValidParentheses, Example1) {
    // Example 1: "(()" -> 2, the substring "()".
    std::string s = "(()";
    EXPECT_EQ(longestValidParentheses(s), 2);
}

TEST(LongestValidParentheses, Example2) {
    // Example 2: ")()())" -> 4, the substring "()()".
    std::string s = ")()())";
    EXPECT_EQ(longestValidParentheses(s), 4);
}

TEST(LongestValidParentheses, Example3) {
    // Example 3: "" -> 0.
    std::string s = "";
    EXPECT_EQ(longestValidParentheses(s), 0);
}

TEST(LongestValidParentheses, WholeStringValid) {
    // "()(())" is valid end to end -> 6.
    std::string s = "()(())";
    EXPECT_EQ(longestValidParentheses(s), 6);
}

TEST(LongestValidParentheses, UnmatchedOpenSplitsRuns) {
    // "()(()": the third '(' never closes, so "()" and "()" stay apart -> 2.
    std::string s = "()(()";
    EXPECT_EQ(longestValidParentheses(s), 2);
}

TEST(LongestValidParentheses, AllSame) {
    // "(((" has no closing bracket at all -> 0.
    std::string s = "(((";
    EXPECT_EQ(longestValidParentheses(s), 0);
}

TEST(LongestValidParentheses, SingleClose) {
    // ")" alone can never be matched -> 0.
    std::string s = ")";
    EXPECT_EQ(longestValidParentheses(s), 0);
}
