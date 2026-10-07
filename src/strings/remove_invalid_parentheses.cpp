#include "strings/remove_invalid_parentheses.hpp"

#include <functional>

std::vector<std::string> removeInvalidParentheses(const std::string& s) {
    std::vector<std::string> res;

    // Right-to-left pass: drop surplus '(' the same way forward drops ')'.
    std::function<void(std::string, int, int)> backward =
        [&](std::string s, int ri, int rj) {
            int bal = 0;

            for (int i = ri; i >= 0; i--) {
                bal += (s[i] == ')') - (s[i] == '(');

                if (bal >= 0) continue;

                // Remove one '(' from each run in [i, rj] to avoid duplicates.
                for (int j = rj; j >= i; j--)
                    if (s[j] == '(' && (j == rj || s[j + 1] != '('))
                        backward(s.substr(0, j) + s.substr(j + 1), i - 1,
                                 j - 1);

                return;
            }

            res.push_back(s);
        };

    // Left-to-right pass: at the first prefix with more ')' than '(', try
    // removing one ')' from each run in [lj, i], then keep scanning from i.
    std::function<void(std::string, int, int)> forward =
        [&](std::string s, int li, int lj) {
            int bal = 0;

            for (int i = li; i < static_cast<int>(s.size()); i++) {
                bal += (s[i] == '(') - (s[i] == ')');

                if (bal >= 0) continue;

                for (int j = lj; j <= i; j++)
                    if (s[j] == ')' && (j == lj || s[j - 1] != ')'))
                        forward(s.substr(0, j) + s.substr(j + 1), i, j);

                return;
            }

            int last = static_cast<int>(s.size()) - 1;
            backward(s, last, last);
        };

    forward(s, 0, 0);

    return res;
}
