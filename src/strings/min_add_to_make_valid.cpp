#include "strings/min_add_to_make_valid.hpp"

int minAddToMakeValid(const std::string& s) {
    // p[0]: open '(' still waiting to close; p[1]: ')' with nothing to match.
    int p[2] = {0};
    for (char c : s) {
        bool isLeft = (c == '(');
        p[0] += isLeft;
        // On ')': if an '(' is open, p[0] -= 1; otherwise p[1] += 1.
        p[p[0] <= 0] += (1 - ((p[0] > 0) << 1)) * (!isLeft);
    }
    return p[0] + p[1];
}
