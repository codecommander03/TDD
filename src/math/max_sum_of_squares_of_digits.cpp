#include "math/max_sum_of_squares_of_digits.hpp"
#include <algorithm>

std::string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum) return "";
    // Greedy: pack 9s first; squares reward big digits, and leading 9s give the largest number.
    std::string res = "";
    for (int i = 0; i < num; i++) {
        int x = std::min(sum, 9);
        res += std::to_string(x);
        sum -= x;
    }
    return res;
}
