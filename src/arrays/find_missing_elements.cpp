#include "arrays/find_missing_elements.hpp"
#include <unordered_set>
#include <algorithm>

std::vector<int> findMissingElements(const std::vector<int>& nums) {
    std::unordered_set<int> present(nums.begin(), nums.end());

    int lo = *std::min_element(nums.begin(), nums.end());
    int hi = *std::max_element(nums.begin(), nums.end());

    std::vector<int> missing;
    for (int v = lo; v <= hi; ++v) {
        if (present.find(v) == present.end()) {
            missing.push_back(v);
        }
    }
    return missing;
}