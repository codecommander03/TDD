#include <gtest/gtest.h>
#include "strings/remove_invalid_parentheses.hpp"

#include <algorithm>

namespace {
// The problem accepts the answer in any order, so compare sorted copies.
std::vector<std::string> sorted(std::vector<std::string> v) {
    std::sort(v.begin(), v.end());
    return v;
}
}  // namespace

TEST(RemoveInvalidParentheses, Example1) {
    // Example 1: "()())()" -> ["(())()","()()()"], one ')' removed.
    std::string s = "()())()";
    std::vector<std::string> expected = {"(())()", "()()()"};
    EXPECT_EQ(sorted(removeInvalidParentheses(s)), sorted(expected));
}

TEST(RemoveInvalidParentheses, Example2) {
    // Example 2: "(a)())()" -> ["(a())()","(a)()()"].
    std::string s = "(a)())()";
    std::vector<std::string> expected = {"(a())()", "(a)()()"};
    EXPECT_EQ(sorted(removeInvalidParentheses(s)), sorted(expected));
}

TEST(RemoveInvalidParentheses, Example3) {
    // Example 3: ")(" -> [""], both characters have to go.
    std::string s = ")(";
    std::vector<std::string> expected = {""};
    EXPECT_EQ(removeInvalidParentheses(s), expected);
}

TEST(RemoveInvalidParentheses, AlreadyValid) {
    // "()" needs no removals, so it is the only answer.
    std::string s = "()";
    std::vector<std::string> expected = {"()"};
    EXPECT_EQ(removeInvalidParentheses(s), expected);
}

TEST(RemoveInvalidParentheses, LettersOnly) {
    // "x" has no parentheses, so it is already valid.
    std::string s = "x";
    std::vector<std::string> expected = {"x"};
    EXPECT_EQ(removeInvalidParentheses(s), expected);
}

TEST(RemoveInvalidParentheses, AllSameOpen) {
    // "((" can never close, so both are removed -> [""].
    std::string s = "((";
    std::vector<std::string> expected = {""};
    EXPECT_EQ(removeInvalidParentheses(s), expected);
}

TEST(RemoveInvalidParentheses, StrayOnBothEnds) {
    // ")()(" -> ["()"]: drop the leading ')' and the trailing '('.
    std::string s = ")()(";
    std::vector<std::string> expected = {"()"};
    EXPECT_EQ(removeInvalidParentheses(s), expected);
}
