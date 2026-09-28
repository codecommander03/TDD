#include "strings/max_nesting_depth.hpp"
#include <algorithm>

int maxDepth(const std::string& s) {
    int cnt = 0, res = 0;
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        // Every '(' opens one more level, so the deepest point is always
        // reached right after an opening bracket.
        if (s[i] == '(') res = std::max(res, ++cnt);
        else if (s[i] == ')') cnt--;
    }
    return res;
}
