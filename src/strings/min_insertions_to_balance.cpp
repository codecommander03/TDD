#include "strings/min_insertions_to_balance.hpp"

int minInsertions(const std::string& s) {
    // p: ')' still needed to close the open '('; k: insertions made so far.
    int p = 0, k = 0;
    for (char c : s) {
        if (c == '(') {
            p += 2;
            // An odd need means the previous '(' got only one ')': insert
            // the missing ')' before this '('.
            if (p % 2) {
                k++;
                p--;
            }
        } else {
            p--;
            // A ')' with nothing open: insert a '(' for it.
            if (p < 0) {
                k++;
                p += 2;
            }
        }
    }
    return p + k;
}
