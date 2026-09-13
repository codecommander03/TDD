#include "arrays/image_overlap.hpp"

#include <algorithm>
#include <map>
#include <utility>

int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
    int n = static_cast<int>(img1.size()), res = 0;

    // Only the 1-cells matter, so collect their coordinates.
    std::vector<std::pair<int, int>> v1, v2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (img1[i][j]) v1.push_back({i, j});
            if (img2[i][j]) v2.push_back({i, j});
        }
    }

    // Every pair of 1-cells votes for the translation that would align them;
    // the translation with the most votes is the best overlap. n <= 30 keeps
    // both offsets in [-29, 29], so a stride of 60 gives each one its own key.
    std::map<int, int> m;
    for (const auto& [x1, y1] : v1) {
        for (const auto& [x2, y2] : v2) {
            res = std::max(res, ++m[(x2 - x1) * 60 + (y2 - y1)]);
        }
    }

    return res;
}
