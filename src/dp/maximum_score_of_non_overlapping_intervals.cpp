#include "dp/maximum_score_of_non_overlapping_intervals.hpp"

#include <algorithm>
#include <utility>

namespace {

struct IntervalData {
    int end, start, weight, originalIndex;

    // Used for sorting and lower_bound comparisons.
    bool operator<(const IntervalData& other) const { return end < other.end; }
};

}  // namespace

std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
    int n = static_cast<int>(intervals.size());
    std::vector<IntervalData> sortedIntervals;

    for (int i = 0; i < n; ++i) {
        sortedIntervals.push_back({intervals[i][1], intervals[i][0], intervals[i][2], i});
    }
    std::sort(sortedIntervals.begin(), sortedIntervals.end());

    // dp[i][j] = best over the first i intervals using at most j of them, as
    // {-max_weight, sorted original indices}. Negating the weight lets a plain
    // pair comparison rank by largest weight first, then by smallest indices.
    std::vector<std::vector<std::pair<long long, std::vector<int>>>> dp(
        n + 1, std::vector<std::pair<long long, std::vector<int>>>(5, {0LL, {}}));

    for (int i = 0; i < n; ++i) {
        int start = sortedIntervals[i].start;
        int weight = sortedIntervals[i].weight;
        int originalIndex = sortedIntervals[i].originalIndex;

        // lower_bound finds the first interval whose end >= current start, so
        // everything before k finishes strictly earlier and can be combined.
        IntervalData target = {start, 0, 0, 0};
        int k = static_cast<int>(
            std::lower_bound(sortedIntervals.begin(), sortedIntervals.begin() + i, target) -
            sortedIntervals.begin());

        for (int j = 1; j <= 4; ++j) {
            long long prevWeight = dp[k][j - 1].first;
            std::vector<int> prevIndices = dp[k][j - 1].second;

            std::pair<long long, std::vector<int>> skip = dp[i][j];

            std::vector<int> takeIndices = prevIndices;
            takeIndices.push_back(originalIndex);
            std::sort(takeIndices.begin(), takeIndices.end());

            std::pair<long long, std::vector<int>> take = {prevWeight - weight, takeIndices};

            // min() prioritizes the most negative weight sum, then the
            // lexicographically smallest index list.
            dp[i + 1][j] = std::min(skip, take);
        }
    }

    return dp[n][4].second;
}
