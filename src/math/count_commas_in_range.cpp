#include "math/count_commas_in_range.hpp"

int countCommas(int n) {
    // Every integer in [1, 999] is written without a comma, and with
    // n <= 10^5 every integer from 1,000 upwards carries exactly one comma.
    if (n < 1000) return 0;
    else if (n == 1000) return 1;
    else if (n <= 10000) return n - 1000 + 1;
    return n - 10000 + (9000 + 1);
}
