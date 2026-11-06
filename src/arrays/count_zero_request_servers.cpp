#include "arrays/count_zero_request_servers.hpp"
#include <algorithm>
#include <unordered_map>
#include <utility>

std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x,
                              std::vector<int>& queries) {
    std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    // Answer queries in time order, remembering where each one came from
    int m_queries = static_cast<int>(queries.size());
    std::vector<std::pair<int, int>> sorted_queries(m_queries);
    for (int k = 0; k < m_queries; ++k) sorted_queries[k] = {queries[k], k};
    std::sort(sorted_queries.begin(), sorted_queries.end());

    int i = 0, j = 0, l = static_cast<int>(logs.size());
    std::unordered_map<int, int> m;  // server -> requests inside the window logs[i..j)
    std::vector<int> res(m_queries);

    for (auto& [q, original_idx] : sorted_queries) {
        // Expand: take in every log with time <= q
        while (j < l && logs[j][1] <= q) {
            m[logs[j][0]]++;
            j++;
        }
        // Shrink: drop every log with time < q - x
        while (i < j && logs[i][1] < q - x) {
            if (--m[logs[i][0]] == 0) m.erase(logs[i][0]);
            i++;
        }
        res[original_idx] = n - static_cast<int>(m.size());
    }
    return res;
}
