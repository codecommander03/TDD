#include "strings/longest_valid_parentheses.hpp"

#include <algorithm>
#include <vector>

int longestValidParentheses(const std::string& s) {
    int res = 0;
    // Indices of unmatched '(' sitting on top of the last index that cannot
    // be part of a valid run (starts as -1, just before the string).
    std::vector<int> st = {-1};
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        if (s[i] == '(') st.push_back(i);
        else {
            st.pop_back();
            // Nothing left to match: this ')' is the new barrier.
            if (st.empty()) st.push_back(i);
            else res = std::max(res, i - st.back());
        }
    }
    return res;
}
