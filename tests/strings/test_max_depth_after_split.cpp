#include <gtest/gtest.h>
#include "strings/max_depth_after_split.hpp"

#include <algorithm>

namespace {
// The problem accepts any optimal split, so the tests check the answer's
// properties rather than one exact vector. Returns max(depth(A), depth(B)),
// or -1 if the answer has the wrong length or either part is not valid.
int splitDepth(const std::string& seq, const std::vector<int>& answer) {
    if (answer.size() != seq.size()) return -1;
    int balance[2] = {0, 0}, deepest = 0;
    for (size_t i = 0; i < seq.size(); i++) {
        int g = answer[i];
        if (g != 0 && g != 1) return -1;
        balance[g] += seq[i] == '(' ? 1 : -1;
        if (balance[g] < 0) return -1;
        deepest = std::max(deepest, balance[g]);
    }
    return balance[0] == 0 && balance[1] == 0 ? deepest : -1;
}
}  // namespace

TEST(MaxDepthAfterSplit, Example1) {
    // Example 1: the expected answer [0,1,1,1,1,0] gives A = "()" and
    // B = "()()", so the best max depth is 1.
    std::string seq = "(()())";
    EXPECT_EQ(splitDepth(seq, maxDepthAfterSplit(seq)), 1);
}

TEST(MaxDepthAfterSplit, Example2) {
    // Example 2: the expected answer [0,0,0,1,1,0,1,1] gives A = "()()" and
    // B = "()()", so the best max depth is 1.
    std::string seq = "()(())()";
    EXPECT_EQ(splitDepth(seq, maxDepthAfterSplit(seq)), 1);
}

TEST(MaxDepthAfterSplit, SinglePair) {
    // "()" has depth 1, and one part has to take the whole pair.
    std::string seq = "()";
    EXPECT_EQ(splitDepth(seq, maxDepthAfterSplit(seq)), 1);
}

TEST(MaxDepthAfterSplit, SiblingPairs) {
    // "()()()" is only 1 deep, so no split can do better than 1.
    std::string seq = "()()()";
    EXPECT_EQ(splitDepth(seq, maxDepthAfterSplit(seq)), 1);
}

TEST(MaxDepthAfterSplit, EvenDepthHalves) {
    // "(((())))" is 4 deep, so each part can take two levels: depth 2.
    std::string seq = "(((())))";
    EXPECT_EQ(splitDepth(seq, maxDepthAfterSplit(seq)), 2);
}

TEST(MaxDepthAfterSplit, OddDepthRoundsUp) {
    // "((()))" is 3 deep, so one part must take two levels: depth 2.
    std::string seq = "((()))";
    EXPECT_EQ(splitDepth(seq, maxDepthAfterSplit(seq)), 2);
}

TEST(MaxDepthAfterSplit, EmptyString) {
    // Nothing to split, so the answer is empty and both parts have depth 0.
    std::string seq = "";
    EXPECT_TRUE(maxDepthAfterSplit(seq).empty());
}
