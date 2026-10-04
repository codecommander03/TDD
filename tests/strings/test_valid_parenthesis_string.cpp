#include <gtest/gtest.h>
#include "strings/valid_parenthesis_string.hpp"

TEST(ValidParenthesisString, Example1) {
    // Example 1: "()" -> true.
    std::string s = "()";
    EXPECT_TRUE(checkValidString(s));
}

TEST(ValidParenthesisString, Example2) {
    // Example 2: "(*)" -> true, '*' as empty.
    std::string s = "(*)";
    EXPECT_TRUE(checkValidString(s));
}

TEST(ValidParenthesisString, Example3) {
    // Example 3: "(*))" -> true, '*' as '(' gives "(())".
    std::string s = "(*))";
    EXPECT_TRUE(checkValidString(s));
}

TEST(ValidParenthesisString, SingleStar) {
    // "*" -> true, '*' as empty gives "".
    std::string s = "*";
    EXPECT_TRUE(checkValidString(s));
}

TEST(ValidParenthesisString, SingleClose) {
    // ")" -> false, nothing before it to match.
    std::string s = ")";
    EXPECT_FALSE(checkValidString(s));
}

TEST(ValidParenthesisString, SingleOpen) {
    // "(" -> false, nothing after it to close it.
    std::string s = "(";
    EXPECT_FALSE(checkValidString(s));
}

TEST(ValidParenthesisString, StarBeforeClose) {
    // "*)" -> true, '*' as '(' gives "()".
    std::string s = "*)";
    EXPECT_TRUE(checkValidString(s));
}

TEST(ValidParenthesisString, StarAfterCloseCannotHelp) {
    // ")*" -> false: the leading ')' is unmatched whatever '*' becomes.
    std::string s = ")*";
    EXPECT_FALSE(checkValidString(s));
}

TEST(ValidParenthesisString, StarBeforeOpenCannotHelp) {
    // "*(" -> false: the trailing '(' is never closed.
    std::string s = "*(";
    EXPECT_FALSE(checkValidString(s));
}

TEST(ValidParenthesisString, TooManyOpens) {
    // "(((*)" -> false: three '(' but at most two closers.
    std::string s = "(((*)";
    EXPECT_FALSE(checkValidString(s));
}

TEST(ValidParenthesisString, AllStars) {
    // "***" -> true, e.g. "()" + empty.
    std::string s = "***";
    EXPECT_TRUE(checkValidString(s));
}
