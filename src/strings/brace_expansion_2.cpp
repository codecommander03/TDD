#include "strings/brace_expansion_2.hpp"
#include <functional>
#include <set>
#include <sstream>

std::vector<std::string> braceExpansionII(const std::string& expression) {
    // The set both removes duplicate words and keeps them sorted.
    std::set<std::string> ans;

    std::function<void(std::string)> dfs = [&](std::string s) {
        std::string::size_type r = s.find('}');

        // No braces left.
        if (r == std::string::npos) {
            ans.insert(s);
            return;
        }

        // The first '}' and the '{' nearest to its left delimit a group with
        // nothing nested inside it, so its commas are all top level.
        std::string::size_type l = s.rfind('{', r);

        std::string left = s.substr(0, l);
        std::string right = s.substr(r + 1);

        // Content inside { }.
        std::string inside = s.substr(l + 1, r - l - 1);

        std::string part;
        std::istringstream ss(inside);

        while (getline(ss, part, ',')) {
            dfs(left + part + right);
        }
    };

    dfs(expression);
    return std::vector<std::string>(ans.begin(), ans.end());
}
