#include "arrays/find_the_distance_value.hpp"
#include <algorithm>
#include <climits>

int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
    std::sort(arr2.begin(), arr2.end());
    arr2.push_back(INT_MAX);  // sentinel: some b is always >= a - d
    auto far = [&](int a) {  // the first b >= a - d is already past a + d
        return *std::lower_bound(arr2.begin(), arr2.end(), a - d) > a + d;
    };
    return static_cast<int>(std::count_if(arr1.begin(), arr1.end(), far));
}
