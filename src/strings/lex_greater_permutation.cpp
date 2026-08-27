#include "strings/lex_greater_permutation.hpp"

#include <array>

std::string lexGreaterPermutation(const std::string& s, const std::string& target) {
    int n = static_cast<int>(s.size());
    std::array<int, 26> count{};
    for (char ch : s) count[ch - 'a']++;

    // The answer keeps target as a prefix for as long as it can, because any
    // position where it rises above target makes the string bigger than every
    // continuation that stays equal. So first match target greedily; the loop
    // stops at the first position whose letter s cannot supply, or runs off the
    // end when s can spell target exactly.
    int p = 0;
    while (p < n && count[target[p] - 'a'] > 0) {
        count[target[p] - 'a']--;
        p++;
    }

    // Spelling target exactly is not strictly greater, so give back the last
    // letter and look for a rise there instead.
    if (p == n) {
        p--;
        count[target[p] - 'a']++;
    }

    // Walk the prefix backwards looking for the deepest position that can rise
    // above target, handing back the letter matched at each step. The deepest
    // one wins: a longer shared prefix means a smaller result.
    while (p >= 0) {
        for (int j = target[p] - 'a' + 1; j < 26; j++) {
            if (count[j] == 0) continue;

            // Above target from here on, so the rest is free to be as small as
            // possible: the remaining letters in sorted order.
            count[j]--;
            std::string res = target.substr(0, p);
            res += static_cast<char>('a' + j);
            for (int k = 0; k < 26; k++) res.append(count[k], static_cast<char>('a' + k));
            return res;
        }

        p--;
        if (p >= 0) count[target[p] - 'a']++;
    }

    return "";
}
