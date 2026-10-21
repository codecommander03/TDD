#include "strings/min_operations_to_sort_string.hpp"
#include <algorithm>

int minOperations(const std::string& s) {
    int n = static_cast<int>(s.length());
    char mn = s[0], mx = s[0];
    bool isSorted = true;

    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) isSorted = false;
        mn = std::min(mn, s[i]);
        mx = std::max(mx, s[i]);
    }

    if (isSorted) return 0;
    if (n == 2) return -1;
    if (s.front() == mn || s.back() == mx)
        return 1;

    for (int i = 1; i < n - 1; i++)
        if (s[i] == mn || s[i] == mx)
            return 2;

    return 3;
}
