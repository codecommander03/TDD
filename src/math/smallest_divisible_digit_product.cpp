#include "math/smallest_divisible_digit_product.hpp"

int smallestNumber(int n, int t) {
    const int UPPER_BOUND = 108;

    for (int i = n; i <= UPPER_BOUND; ++i) {
        int product = 1, j = i;
        while (j) {
            product *= j % 10;
            j /= 10;
        }
        if (product % t == 0) return i;
    }
    return -1;
}