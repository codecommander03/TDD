#include "strings/remove_outer_parentheses.hpp"

std::string removeOuterParentheses(const std::string& s) {
    // s2 collects the current primitive, minus its closing ')'.
    std::string s2, res;
    int cnt = 0;
    for (char c : s) {
        cnt += (c == '(' ? 1 : -1);
        if (cnt == 0) {
            // Primitive closed: keep it without its opening '('.
            res += s2.substr(1);
            cnt = 0;
            s2.clear();
        } else s2 += c;
    }
    return res;
}
