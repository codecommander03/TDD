#include "strings/maximum_length_substring.hpp"
#include <map>
#include <vector>
#include <algorithm>

int maximumLengthSubstring(std::string s) {
    int n = s.size(), res = 0, ind = -1;
    std::map<char, std::vector<int>> m;

    for (int i = 0; i < n; ++i) {
        m[s[i]].push_back(i);
        if (m[s[i]].size() > 2) {
            ind = std::max(ind, m[s[i]][0]);
            m[s[i]].erase(m[s[i]].begin());
        }
        res = std::max(res, i - ind);
    }
    return res;
}