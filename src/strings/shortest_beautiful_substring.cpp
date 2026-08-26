#include "strings/shortest_beautiful_substring.hpp"

#include <vector>

std::string shortestBeautifulSubstring(const std::string& s, int k) {
    // A beautiful substring has to begin and end on a '1', otherwise trimming
    // the leading or trailing '0's gives a shorter one with the same k ones.
    // So the only candidates are the windows that run from the k-th one back to
    // the one just added, and there is exactly one of those per '1' in s.
    std::vector<int> ones;
    std::string best;

    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        if (s[i] == '0') continue;
        ones.push_back(i);
        if (static_cast<int>(ones.size()) < k) continue;

        int start = ones[ones.size() - k];
        std::string candidate = s.substr(start, i - start + 1);

        // Shortest wins; ties are broken lexicographically. best stays empty
        // until the first candidate, and a beautiful substring is never empty
        // because k >= 1.
        if (best.empty() || candidate.size() < best.size() ||
            (candidate.size() == best.size() && candidate < best)) {
            best = candidate;
        }
    }

    return best;
}
