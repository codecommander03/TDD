#include "arrays/construct_uniform_parity_array_i.hpp"

bool uniformArray(std::vector<int>& nums1) {
    // If every element already shares a parity, keep nums2[i] = nums1[i].
    // Otherwise aim for all odd: leave the odd elements alone and turn each
    // even element into (even - odd), which is odd. A mixed array is exactly
    // the case where such an odd nums1[j] exists, so this always succeeds.
    return true;
}
