#include "graphs/count_islands_with_total_value_divisible_by_k.hpp"
#include <queue>
#include <utility>

int countIslands(std::vector<std::vector<int>>& grid, int k) {
    int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
    int res = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j]) continue;

            long long sum = grid[i][j];
            grid[i][j] = 0;  // mark as visited on push
            std::queue<std::pair<int, int>> q;
            q.push({i, j});

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int x2 = x + dx[d], y2 = y + dy[d];
                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && grid[x2][y2]) {
                        sum += grid[x2][y2];
                        grid[x2][y2] = 0;
                        q.push({x2, y2});
                    }
                }
            }
            if (sum % k == 0) res++;
        }
    }
    return res;
}
