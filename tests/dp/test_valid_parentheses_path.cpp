#include <gtest/gtest.h>
#include "dp/valid_parentheses_path.hpp"

TEST(ValidParenthesesPath, Example1) {
    // Example 1: the statement lists two valid paths, spelling "()(())" and
    // "((()))".
    std::vector<std::vector<char>> grid = {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'},
        {'(', '(', ')'},
    };
    EXPECT_TRUE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, Example2) {
    // Example 2: both paths start with ')', so neither can be valid.
    std::vector<std::vector<char>> grid = {
        {')', ')'},
        {'(', '('},
    };
    EXPECT_FALSE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, SingleCell) {
    // A one-character string can never be balanced.
    std::vector<std::vector<char>> grid = {{'('}};
    EXPECT_FALSE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, SingleRowPair) {
    // The only path spells "()".
    std::vector<std::vector<char>> grid = {{'(', ')'}};
    EXPECT_TRUE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, OddPathLength) {
    // Every path through a 2x2 grid has 3 cells, so none can be balanced.
    std::vector<std::vector<char>> grid = {
        {'(', ')'},
        {')', ')'},
    };
    EXPECT_FALSE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, BalancedCountButDipsBelowZero) {
    // "())(" has two of each, but the prefix "())" closes more than it opens.
    std::vector<std::vector<char>> grid = {{'(', ')', ')', '('}};
    EXPECT_FALSE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, OnlyOnePathWorks) {
    // Right, right, down spells "(())"; right-down-right and down-right-right
    // both spell "((()", which is left open.
    std::vector<std::vector<char>> grid = {
        {'(', '(', ')'},
        {'(', '(', ')'},
    };
    EXPECT_TRUE(hasValidPath(grid));
}

TEST(ValidParenthesesPath, NoPathCloses) {
    // All three paths through this grid spell "((()", which never closes.
    std::vector<std::vector<char>> grid = {
        {'(', '(', '('},
        {'(', '(', ')'},
    };
    EXPECT_FALSE(hasValidPath(grid));
}
