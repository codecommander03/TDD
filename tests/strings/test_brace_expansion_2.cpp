#include <gtest/gtest.h>
#include "strings/brace_expansion_2.hpp"

// Example 1: {a,b} x {c,d,e}, since {c,{d,e}} flattens to {c,d,e}.
TEST(BraceExpansionII, Example1) {
    EXPECT_EQ(braceExpansionII("{a,b}{c,{d,e}}"),
              (std::vector<std::string>{"ac", "ad", "ae", "bc", "bd", "be"}));
}

// Example 2: {a,z} union {ab,ac} union {ab,z}; "ab" appears twice and collapses.
TEST(BraceExpansionII, Example2) {
    EXPECT_EQ(braceExpansionII("{{a,z},a{b,c},{ab,z}}"),
              (std::vector<std::string>{"a", "ab", "ac", "z"}));
}

// A single letter is its own one-word set.
TEST(BraceExpansionII, SingleLetter) {
    EXPECT_EQ(braceExpansionII("a"), (std::vector<std::string>{"a"}));
}

// No braces at all, so the whole expression is one literal word.
TEST(BraceExpansionII, NoBraces) {
    EXPECT_EQ(braceExpansionII("abcd"), (std::vector<std::string>{"abcd"}));
}

// The output is sorted, not listed in the order the options appear.
TEST(BraceExpansionII, OutputIsSorted) {
    EXPECT_EQ(braceExpansionII("{b,a}"), (std::vector<std::string>{"a", "b"}));
}

// A union nested directly inside another flattens: {{a,b},c} is {a,b,c}.
TEST(BraceExpansionII, NestedUnionFlattens) {
    EXPECT_EQ(braceExpansionII("{{a,b},c}"),
              (std::vector<std::string>{"a", "b", "c"}));
}

// Literals on both sides concatenate with each option.
TEST(BraceExpansionII, LiteralsAroundAUnion) {
    EXPECT_EQ(braceExpansionII("x{a,b}y"),
              (std::vector<std::string>{"xay", "xby"}));
}

// {ab} union a{b,c} = {ab} union {ab,ac}, so "ab" is reported once.
TEST(BraceExpansionII, DuplicatesCollapse) {
    EXPECT_EQ(braceExpansionII("{ab,a{b,c}}"),
              (std::vector<std::string>{"ab", "ac"}));
}
