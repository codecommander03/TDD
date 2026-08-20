#include "arrays/distribute_elements_into_two_arrays_i.hpp"

std::vector<int> resultArray(std::vector<int>& nums) {
    // The first two elements seed the two arrays; from then on each element
    // joins whichever array currently has the larger tail (ties go to arr2).
    std::vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};

    int n = static_cast<int>(nums.size());
    for (int i = 2; i < n; ++i) {
        if (arr1.back() > arr2.back()) arr1.push_back(nums[i]);
        else arr2.push_back(nums[i]);
    }

    // The result is arr1 followed by arr2.
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}
