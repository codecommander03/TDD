#include "strings/generate_parentheses.hpp"

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> v = {"("};
    // Number of '(' still open in s.
    auto cal = [](const std::string& s) {
        int res = 0;
        for (char c : s) {
            if (c == '(') res++;
            else res--;
        }
        return res;
    };
    // Grow every prefix one character at a time, only adding ')' when it
    // has an open '(' to close.
    for (int j = 2; j <= 2 * n; j++) {
        std::vector<std::string> v2;
        for (const auto& s : v) {
            v2.push_back(s + "(");
            if (cal(s) > 0) v2.push_back(s + ")");
        }
        v = v2;
    }
    // Keep only the strings where every '(' was closed.
    std::vector<std::string> v2;
    for (const std::string& s : v) if (cal(s) == 0) v2.push_back(s);
    return v2;
}
