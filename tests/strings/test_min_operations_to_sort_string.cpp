#include <gtest/gtest.h>
#include "strings/min_operations_to_sort_string.hpp"

// LeetCode Example 1: sort "og" -> "dgo"
TEST(MinOperationsToSortString, Example1) {
    EXPECT_EQ(minOperations("dog"), 1);
}

// LeetCode Example 2: sort "car" -> "acrd", then "rd" -> "acdr"
TEST(MinOperationsToSortString, Example2) {
    EXPECT_EQ(minOperations("card"), 2);
}

// LeetCode Example 3: only single chars may be sorted, string can't change
TEST(MinOperationsToSortString, Example3) {
    EXPECT_EQ(minOperations("gf"), -1);
}

// Single character is already sorted
TEST(MinOperationsToSortString, SingleChar) {
    EXPECT_EQ(minOperations("a"), 0);
}

// All same is already sorted
TEST(MinOperationsToSortString, AllSame) {
    EXPECT_EQ(minOperations("aaa"), 0);
}

// "bca": one op gives "bca"/"bac" only; "bac" -> sort "ba" -> "abc" -> 2
TEST(MinOperationsToSortString, MaxInMiddle) {
    EXPECT_EQ(minOperations("bca"), 2);
}

// "cba": ops of length <= 2 reach "bca"/"cab", then "bac"/"acb",
// then "acb" -> sort "cb" -> "abc" -> 3
TEST(MinOperationsToSortString, FullyReversed) {
    EXPECT_EQ(minOperations("cba"), 3);
}
