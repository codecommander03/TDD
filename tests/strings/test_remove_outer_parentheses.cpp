#include <gtest/gtest.h>
#include "strings/remove_outer_parentheses.hpp"

TEST(RemoveOuterParentheses, Example1) {
    // Example 1: "(()())(())" = "(()())" + "(())" -> "()()" + "()".
    std::string s = "(()())(())";
    EXPECT_EQ(removeOuterParentheses(s), "()()()");
}

TEST(RemoveOuterParentheses, Example2) {
    // Example 2: "(()())(())(()(()))" = "(()())" + "(())" + "(()(()))"
    // -> "()()" + "()" + "()(())".
    std::string s = "(()())(())(()(()))";
    EXPECT_EQ(removeOuterParentheses(s), "()()()()(())");
}

TEST(RemoveOuterParentheses, Example3) {
    // Example 3: "()()" = "()" + "()" -> "" + "".
    std::string s = "()()";
    EXPECT_EQ(removeOuterParentheses(s), "");
}

TEST(RemoveOuterParentheses, SinglePair) {
    // "()" is one primitive with nothing inside -> "".
    std::string s = "()";
    EXPECT_EQ(removeOuterParentheses(s), "");
}

TEST(RemoveOuterParentheses, DeepNesting) {
    // "((()))" is one primitive; only the outer pair goes -> "(())".
    std::string s = "((()))";
    EXPECT_EQ(removeOuterParentheses(s), "(())");
}
