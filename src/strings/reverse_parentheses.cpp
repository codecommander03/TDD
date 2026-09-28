#include "strings/reverse_parentheses.hpp"
#include <algorithm>
#include <queue>
#include <stack>

std::string reverseParentheses(const std::string& s) {
    std::stack<char> a;
    std::queue<char> b;

    for (char c : s) {
        if (c != ')') {
            a.push(c);
            continue;
        }

        // Popping the group into a queue reverses it, since the queue hands the
        // characters back in the order they were taken off the stack.
        while (a.top() != '(') {
            b.push(a.top());
            a.pop();
        }
        a.pop();  // Drop the matching '('.

        while (!b.empty()) {
            a.push(b.front());
            b.pop();
        }
    }

    // The stack unwinds back to front, so the answer needs one final reverse.
    std::string res;
    while (!a.empty()) {
        res += a.top();
        a.pop();
    }
    std::reverse(res.begin(), res.end());

    return res;
}
