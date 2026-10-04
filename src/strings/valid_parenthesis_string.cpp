#include "strings/valid_parenthesis_string.hpp"

#include <algorithm>

bool checkValidString(const std::string& s) {
    // [mn, mx] is the range of open-bracket balances reachable so far.
    int mn = 0, mx = 0;

    for (char c : s) {
        if (c == '(') {
            mn++;
            mx++;
        } else if (c == ')') {
            mn--;
            mx--;
        } else { // '*' forks: ')', '', '('
            mn--;
            mx++;
        }

        // no valid path remains
        if (mx < 0) return false;

        // clip negative-balance paths
        mn = std::max(mn, 0);
    }

    // some path ends with balance 0
    return mn == 0;
}
