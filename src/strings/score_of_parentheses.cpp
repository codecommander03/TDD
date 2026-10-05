#include "strings/score_of_parentheses.hpp"

#include <vector>

int scoreOfParentheses(const std::string& s) {
    // Running score of each open nesting level; the bottom is the outermost.
    std::vector<int> stk = {0};
    for (char c : s) {
        if (c == '(') stk.push_back(0);
        else {
            int p = stk.back();
            stk.pop_back();
            // Empty "()" is worth 1; a wrapped group doubles its contents.
            stk.back() += (p == 0) ? 1 : 2 * p;
        }
    }
    return stk.back();
}
