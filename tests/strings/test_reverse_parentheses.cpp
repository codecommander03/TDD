#include <gtest/gtest.h>
#include "strings/reverse_parentheses.hpp"

TEST(ReverseParentheses, Example1) {
    // Example 1: the single group "abcd" reverses to "dcba".
    EXPECT_EQ(reverseParentheses("(abcd)"), "dcba");
}

TEST(ReverseParentheses, Example2) {
    // Example 2: (love) -> "evol" giving "(uevoli)", which reverses to
    // "iloveu".
    EXPECT_EQ(reverseParentheses("(u(love)i)"), "iloveu");
}

TEST(ReverseParentheses, Example3) {
    // Example 3: (oc) -> "co", so (etco) -> "octe", so (edocteel) -> "leetcode".
    EXPECT_EQ(reverseParentheses("(ed(et(oc))el)"), "leetcode");
}

TEST(ReverseParentheses, LettersOutsideTheBrackets) {
    // (mno) -> "onm", so the outer group is "bcdefghijklonmp" reversed to
    // "pmnolkjihgfedcb", with 'a' and 'q' left in place.
    EXPECT_EQ(reverseParentheses("a(bcdefghijkl(mno)p)q"),
              "apmnolkjihgfedcbq");
}

TEST(ReverseParentheses, NoParentheses) {
    // Nothing to reverse, so the string is returned as it is.
    EXPECT_EQ(reverseParentheses("abcd"), "abcd");
}

TEST(ReverseParentheses, SingleCharacter) {
    EXPECT_EQ(reverseParentheses("a"), "a");
}

TEST(ReverseParentheses, EmptyGroupsDisappear) {
    // "(())" holds no letters, so only the brackets are removed.
    EXPECT_EQ(reverseParentheses("(())"), "");
}

TEST(ReverseParentheses, SiblingGroupsReverseIndependently) {
    // "(ab)(cd)" reverses each group in place: "ba" followed by "dc".
    EXPECT_EQ(reverseParentheses("(ab)(cd)"), "badc");
}

TEST(ReverseParentheses, DoubleNestingRestoresOrder) {
    // The inner reverse of "ab" is undone by the outer one, so "ab" comes back.
    EXPECT_EQ(reverseParentheses("((ab))"), "ab");
}
