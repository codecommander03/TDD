#include "graphs/number_of_closed_islands.hpp"
#include <queue>
#include <utility>

int closedIsland(const std::vector<std::vector<int>>& grid) {
    int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
    std::vector<std::vector<int>> v(n, std::vector<int>(m, 0));
    int res = 0, z = 1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (grid[i][j] || v[i][j]) continue;

            std::queue<std::pair<int, int>> q;
            z++;
            bool flag = true;

            q.push({i, j});
            v[i][j] = z;  // mark as visited on push

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                    flag = false;
                }

                for (int k = 0; k < 4; k++) {
                    int x2 = x + dx[k], y2 = y + dy[k];
                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && grid[x2][y2] == 0 && v[x2][y2] == 0) {
                        v[x2][y2] = z;
                        q.push({x2, y2});
                    }
                }
            }
            if (flag) res++;
        }
    }
    return res;
}
