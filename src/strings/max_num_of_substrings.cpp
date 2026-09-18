#include "strings/max_num_of_substrings.hpp"

#include <algorithm>
#include <array>
#include <climits>
#include <deque>

std::vector<std::string> maxNumOfSubstrings(const std::string& s) {
    int count[26] = {};
    int first[26], last[26];

    std::fill(first, first + 26, -1);
    std::fill(last, last + 26, -1);

    // Letters in order of first appearance; a valid substring always starts at
    // the first occurrence of one of them.
    std::vector<int> order;

    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        int c = s[i] - 'a';

        if (count[c] == 0) {
            first[c] = i;
            order.push_back(c);
        }

        count[c]++;
        last[c] = i;
    }

    std::vector<std::string> res;

    // Letters whose span has not closed yet, newest in front. A candidate is
    // valid once the letters it pulls in cover its whole window with no gaps,
    // i.e. the letter counts add up to the window width.
    std::deque<std::array<int, 3>> queue;

    for (int c : order) {
        queue.push_front({first[c], last[c], count[c]});

        int left = INT_MAX;
        int right = INT_MIN;
        int total = 0;

        for (auto& item : queue) {
            total += item[2];
            left = std::min(left, item[0]);
            right = std::max(right, item[1]);

            if (total == right - left + 1) {
                break;
            }
        }

        // The newest letters closed a window: take it, and drop everything it
        // swallowed. Stopping at the smallest such window keeps the count
        // maximal and the total length minimal.
        if (total == right - left + 1) {
            res.push_back(s.substr(left, right - left + 1));
            queue.clear();
        }
    }

    return res;
}
