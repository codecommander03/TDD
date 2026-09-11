#include "arrays/unique_3_digit_even_numbers.hpp"

#include <algorithm>
#include <set>

int totalNumbers(const std::vector<int>& digits) {
    int n = static_cast<int>(digits.size());
    std::set<int> seen;

    // Pick every combination of three positions, then walk all orderings of
    // that multiset. The set absorbs duplicates coming from repeated digits.
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                std::vector<int> v = {digits[i], digits[j], digits[k]};
                std::sort(v.begin(), v.end());
                do {
                    int x = 100 * v[0] + 10 * v[1] + v[2];
                    // x >= 100 rejects a leading zero; x % 2 == 0 keeps evens.
                    if (x >= 100 && x % 2 == 0) seen.insert(x);
                } while (std::next_permutation(v.begin(), v.end()));
            }
        }
    }

    return static_cast<int>(seen.size());
}
