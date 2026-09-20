#include "strings/reverse_degree.hpp"

int reverseDegree(const std::string& s) {
    int n = static_cast<int>(s.size()), res = 0;
    for (int i = 0; i < n; i++) {
        res += (i + 1) * (26 - (s[i] - 'a'));
    }
    return res;
}
