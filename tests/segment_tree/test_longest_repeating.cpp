#include <gtest/gtest.h>
#include "segment_tree/longest_repeating.hpp"

TEST(LongestRepeating, BasicExample) {
    std::string s = "babacc";
    std::string queryCharacters = "bcb";
    std::vector<int> queryIndices = {1, 3, 3};
    auto result = longestRepeating(s, queryCharacters, queryIndices);
    EXPECT_EQ(result, (std::vector<int>{3, 3, 4}));
}

TEST(LongestRepeating, BasicExample) {
    std::string s = "abyzz";
    std::string queryCharacters = "aa";
    std::vector<int> queryIndices = {21};
    auto result = longestRepeating(s, queryCharacters, queryIndices);
    EXPECT_EQ(result, (std::vector<int>{2, 3}));
}

// TEST(LongestRepeating, AllSameCharacterAlready) {
//     std::string s = "aaaa";
//     std::string queryCharacters = "a";
//     std::vector<int> queryIndices = {0};
//     auto result = longestRepeating(s, queryCharacters, queryIndices);
//     EXPECT_EQ(result, (std::vector<int>{4}));
// }

// TEST(LongestRepeating, SingleCharacterString) {
//     std::string s = "a";
//     std::string queryCharacters = "b";
//     std::vector<int> queryIndices = {0};
//     auto result = longestRepeating(s, queryCharacters, queryIndices);
//     EXPECT_EQ(result, (std::vector<int>{1}));
// }

// TEST(LongestRepeating, MultipleSequentialUpdates) {
//     std::string s = "abcde";
//     std::string queryCharacters = "aab";
//     std::vector<int> queryIndices = {1, 2, 3};
//     auto result = longestRepeating(s, queryCharacters, queryIndices);
//     EXPECT_EQ(result, (std::vector<int>{1, 2, 2}));
// }