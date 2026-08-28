#include "strings/lex_palindromic_permutation.hpp"

#include <array>

namespace {

bool spellable(const std::array<int, 26>& count) {
    for (int c : count)
        if (c < 0) return false;
    return true;
}

}  // namespace

std::string lexPalindromicPermutation(const std::string& s, const std::string& target) {
    std::array<int, 26> count{};
    for (char ch : s) count[ch - 'a']++;

    // A palindrome can afford at most one letter with an odd count, and that
    // letter is pinned to the middle. Pull it out so the rest is all pairs.
    char middle = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 0) continue;
        if (middle != 0) return "";
        middle = static_cast<char>('a' + i);
        count[i]--;
    }

    // The first half determines the whole palindrome, so the search only ever
    // picks half of the letters and every pick spends a pair.
    int half = static_cast<int>(s.size()) / 2;
    for (int i = 0; i < half; i++) count[target[i] - 'a'] -= 2;

    // The best candidate is the one matching target for as long as possible, so
    // start with the half copied outright: then both halves agree and the
    // comparison comes down to the mirrored tail.
    if (spellable(count)) {
        std::string head = target.substr(0, half);
        std::string tail;
        if (middle != 0) tail += middle;
        tail.append(head.rbegin(), head.rend());
        if (tail > target.substr(half)) return head + tail;
    }

    // Otherwise the half has to rise above target somewhere. Walk backwards
    // handing back a pair at each step: that both undoes letters s could not
    // supply and frees the position to hold something larger. The deepest
    // position that can rise wins, since a longer shared prefix is smaller.
    for (int i = half - 1; i >= 0; i--) {
        count[target[i] - 'a'] += 2;
        if (!spellable(count)) continue;

        for (int j = target[i] - 'a' + 1; j < 26; j++) {
            if (count[j] == 0) continue;

            // Past the rise the palindrome already beats target, so the rest of
            // the half is free to be as small as it can: the leftovers sorted.
            count[j] -= 2;
            std::string head = target.substr(0, i);
            head += static_cast<char>('a' + j);
            for (int k = 0; k < 26; k++) head.append(count[k] / 2, static_cast<char>('a' + k));

            std::string res = head;
            if (middle != 0) res += middle;
            res.append(head.rbegin(), head.rend());
            return res;
        }
    }

    return "";
}
