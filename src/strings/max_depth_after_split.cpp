#include "strings/max_depth_after_split.hpp"

std::vector<int> maxDepthAfterSplit(const std::string& seq) {
    int n = static_cast<int>(seq.size());
    std::vector<int> res(n), d;
    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            // Alternate groups by nesting level: even levels go to A, odd
            // levels to B, so each half gets about half of the depth.
            if (d.size() % 2 == 0) {
                res[i] = 0;
                d.push_back(0);
            } else {
                res[i] = 1;
                d.push_back(1);
            }
        } else {
            // A ')' goes to the same group as the '(' it closes.
            res[i] = d.back();
            d.pop_back();
        }
    }
    return res;
}
