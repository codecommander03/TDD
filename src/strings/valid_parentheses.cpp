#include "strings/valid_parentheses.hpp"

#include <stack>

bool isValid(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            // A closer needs an open bracket of the same type on top.
            if (st.empty()) return false;
            if (c == ')' && st.top() == '(') st.pop();
            else if (c == '}' && st.top() == '{') st.pop();
            else if (c == ']' && st.top() == '[') st.pop();
            else return false;
        }
    }
    // Anything left on the stack was never closed.
    return st.empty();
}
