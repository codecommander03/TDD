#include "math/count_days_spent_together.hpp"
#include <algorithm>
#include <vector>

int countDaysTogether(const std::string& arriveAlice, const std::string& leaveAlice,
                      const std::string& arriveBob, const std::string& leaveBob) {
    std::vector<int> v = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    auto hash = [&](const std::string& s) {
        int m = std::stoi(s.substr(0, 2)), d = std::stoi(s.substr(3, 2));
        return v[m - 1] + d;
    };

    int res = std::min(hash(leaveAlice), hash(leaveBob)) + 1 - std::max(hash(arriveAlice), hash(arriveBob));
    return std::max(0, res);
}
