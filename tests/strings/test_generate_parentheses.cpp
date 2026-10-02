#include <gtest/gtest.h>
#include "strings/generate_parentheses.hpp"

#include <algorithm>

namespace {
// The problem accepts the answer in any order, so compare sorted copies.
std::vector<std::string> sorted(std::vector<std::string> v) {
    std::sort(v.begin(), v.end());
    return v;
}
}  // namespace

TEST(GenerateParentheses, Example1) {
    // Example 1: n = 3 -> ["((()))","(()())","(())()","()(())","()()()"].
    std::vector<std::string> expected = {"((()))", "(()())", "(())()",
                                         "()(())", "()()()"};
    EXPECT_EQ(sorted(generateParenthesis(3)), sorted(expected));
}

TEST(GenerateParentheses, Example2) {
    // Example 2: n = 1 -> ["()"].
    std::vector<std::string> expected = {"()"};
    EXPECT_EQ(generateParenthesis(1), expected);
}

TEST(GenerateParentheses, TwoPairs) {
    // n = 2: either nest the pairs or put them side by side.
    std::vector<std::string> expected = {"(())", "()()"};
    EXPECT_EQ(sorted(generateParenthesis(2)), sorted(expected));
}

TEST(GenerateParentheses, FourPairsCount) {
    // n = 4: the count is the 4th Catalan number, C(8,4) / 5 = 70 / 5 = 14,
    // and the answer must not repeat a string.
    std::vector<std::string> result = sorted(generateParenthesis(4));
    EXPECT_EQ(result.size(), 14u);
    EXPECT_TRUE(std::adjacent_find(result.begin(), result.end()) ==
                result.end());
}
