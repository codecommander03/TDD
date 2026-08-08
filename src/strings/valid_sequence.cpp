#include "strings/valid_sequence.hpp"

std::vector<int> validSequence(std::string word1, std::string word2) {
    int n1 = word1.size(), n2 = word2.size();

    std::vector<int> R(n1 + 1, 0);
    int j = n2 - 1;
    for (int i = n1 - 1; i >= 0; --i) {
        if (j >= 0 && word1[i] == word2[j]) j--;
        R[i] = n2 - 1 - j;
    }

    std::vector<int> res;
    bool changed = false;
    j = 0;

    for (int i = 0; i < n1; ++i) {
        if (j == n2) break;

        if (word1[i] == word2[j]) {
            res.push_back(i);
            j++;
        } else if (!changed && R[i + 1] + 1 + j >= n2) {
            res.push_back(i);
            j++;
            changed = true;
        }
    }

    if (static_cast<int>(res.size()) == n2) return res;
    return {};
}