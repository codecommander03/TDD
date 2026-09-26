#include "strings/evaluate_bracket_pairs.hpp"
#include <unordered_map>

std::string evaluate(const std::string& s,
                     std::vector<std::vector<std::string>>& knowledge) {
    std::unordered_map<std::string, std::string> m;
    for (const std::vector<std::string>& pair : knowledge) {
        m[pair[0]] = pair[1];
    }

    int n = static_cast<int>(s.size());
    std::string res;

    for (int i = 0; i < n; i++) {
        // Anything outside a bracket pair is copied through unchanged.
        if (s[i] != '(') {
            res += s[i];
            continue;
        }

        // Collect the key between '(' and its matching ')'.
        std::string key;
        i++;
        while (s[i] != ')') {
            key += s[i];
            i++;
        }

        if (m.count(key)) {
            res += m[key];
        } else {
            res += '?';
        }
    }

    return res;
}
