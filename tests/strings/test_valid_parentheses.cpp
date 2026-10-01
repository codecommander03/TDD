#include <gtest/gtest.h>
#include "strings/valid_parentheses.hpp"

TEST(ValidParentheses, Example1) {
    // Example 1: "()" -> true.
    std::string s = "()";
    EXPECT_TRUE(isValid(s));
}

TEST(ValidParentheses, Example2) {
    // Example 2: "()[]{}" -> true, three closed sibling pairs.
    std::string s = "()[]{}";
    EXPECT_TRUE(isValid(s));
}

TEST(ValidParentheses, Example3) {
    // Example 3: "(]" -> false, ']' does not close '('.
    std::string s = "(]";
    EXPECT_FALSE(isValid(s));
}

TEST(ValidParentheses, Example4) {
    // Example 4: "([])" -> true, '[]' nests inside '()'.
    std::string s = "([])";
    EXPECT_TRUE(isValid(s));
}

TEST(ValidParentheses, Example5) {
    // Example 5: "([)]" -> false, ')' arrives while '[' is still open.
    std::string s = "([)]";
    EXPECT_FALSE(isValid(s));
}

TEST(ValidParentheses, UnclosedOpen) {
    // "(" is never closed, so it is not valid.
    std::string s = "(";
    EXPECT_FALSE(isValid(s));
}

TEST(ValidParentheses, CloserFirst) {
    // "]" has no open bracket to close.
    std::string s = "]";
    EXPECT_FALSE(isValid(s));
}

TEST(ValidParentheses, DeepNesting) {
    // "{[()]}" closes each bracket in reverse order of opening -> true.
    std::string s = "{[()]}";
    EXPECT_TRUE(isValid(s));
}

TEST(ValidParentheses, AllSameUnbalanced) {
    // "(((" opens three times and never closes -> false.
    std::string s = "(((";
    EXPECT_FALSE(isValid(s));
}
