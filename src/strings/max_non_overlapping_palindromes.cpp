#include "strings/max_non_overlapping_palindromes.hpp"

#include <algorithm>

int maxPalindromes(const std::string& s, int k) {
    int n = static_cast<int>(s.size()), res = 0;

    // Greedy left to right: a longer pick never helps, and any palindrome of
    // length >= k contains a centered one of length k or k+1, so only those
    // two lengths need checking at each start.
    for (int i = 0; i <= n - k;) {
        int step = 1;
        for (int d : {k, k + 1}) {
            // Compare the window's first half against its reversed tail.
            if (i + d <= n &&
                std::equal(s.begin() + i, s.begin() + i + (d >> 1), s.rbegin() + (n - (i + d)))) {
                step = d;
                ++res;
                break;
            }
        }
        i += step;
    }

    return res;
}
