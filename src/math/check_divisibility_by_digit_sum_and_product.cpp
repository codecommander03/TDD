#include "math/check_divisibility_by_digit_sum_and_product.hpp"

bool checkDivisibility(int n) {
    // Digit sum is at least 1 for n >= 1, so the divisor is never zero even
    // when a digit of 0 makes the digit product 0.
    int digitSum = 0;
    int digitProduct = 1;
    for (int rest = n; rest > 0; rest /= 10) {
        int digit = rest % 10;
        digitSum += digit;
        digitProduct *= digit;
    }
    return n % (digitSum + digitProduct) == 0;
}
