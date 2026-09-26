#include <gtest/gtest.h>
#include "strings/evaluate_bracket_pairs.hpp"

TEST(EvaluateBracketPairs, Example1) {
    // Example 1: (name) -> "bob" and (age) -> "two".
    std::vector<std::vector<std::string>> knowledge = {{"name", "bob"},
                                                      {"age", "two"}};
    EXPECT_EQ(evaluate("(name)is(age)yearsold", knowledge),
              "bobistwoyearsold");
}

TEST(EvaluateBracketPairs, Example2) {
    // Example 2: "name" is not a key, so the pair becomes "?".
    std::vector<std::vector<std::string>> knowledge = {{"a", "b"}};
    EXPECT_EQ(evaluate("hi(name)", knowledge), "hi?");
}

TEST(EvaluateBracketPairs, Example3) {
    // Example 3: every (a) becomes "yes"; the trailing "aaa" is plain text.
    std::vector<std::vector<std::string>> knowledge = {{"a", "yes"}};
    EXPECT_EQ(evaluate("(a)(a)(a)aaa", knowledge), "yesyesyesaaa");
}

TEST(EvaluateBracketPairs, NoBracketPairs) {
    // Nothing to substitute, so the string passes through untouched.
    std::vector<std::vector<std::string>> knowledge = {{"a", "yes"}};
    EXPECT_EQ(evaluate("abcd", knowledge), "abcd");
}

TEST(EvaluateBracketPairs, EmptyKnowledge) {
    // With no keys known at all, each pair collapses to a single "?".
    std::vector<std::vector<std::string>> knowledge = {};
    EXPECT_EQ(evaluate("(a)x(bc)", knowledge), "?x?");
}

TEST(EvaluateBracketPairs, WholeStringIsOnePair) {
    // The one pair spans the whole string and maps to a longer value.
    std::vector<std::vector<std::string>> knowledge = {{"key", "hello"}};
    EXPECT_EQ(evaluate("(key)", knowledge), "hello");
}

TEST(EvaluateBracketPairs, ValuesAreNotSubstitutedAgain) {
    // (a) -> "b" and (b) -> "a": the inserted values are output as-is, so the
    // result is "ba" rather than being re-evaluated back to "ab".
    std::vector<std::vector<std::string>> knowledge = {{"a", "b"}, {"b", "a"}};
    EXPECT_EQ(evaluate("(a)(b)", knowledge), "ba");
}

TEST(EvaluateBracketPairs, UnusedKeysAreIgnored) {
    // Only "b" appears in s; the extra entries change nothing.
    std::vector<std::vector<std::string>> knowledge = {
        {"a", "1"}, {"b", "2"}, {"c", "3"}};
    EXPECT_EQ(evaluate("z(b)z", knowledge), "z2z");
}
