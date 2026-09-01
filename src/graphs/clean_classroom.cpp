#include "graphs/clean_classroom.hpp"

#include <array>
#include <queue>

int minMoves(const std::vector<std::string>& classroom, int energy) {
    int m = static_cast<int>(classroom.size());
    int n = static_cast<int>(classroom[0].size());
    int cnt = 0, sx = 0, sy = 0;

    // Number the litter cells so the set still uncollected fits in a bitmask.
    std::vector<std::vector<int>> id(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (classroom[i][j] == 'S') sx = i, sy = j;
            else if (classroom[i][j] == 'L') id[i][j] = cnt++;
        }
    }
    if (cnt == 0) return 0;

    // A cell alone is not a state: the same square is worth revisiting with a
    // fuller battery or with less litter left, so all three go in the key.
    std::vector<bool> vis(static_cast<size_t>(m) * n * (energy + 1) * (1 << cnt), false);
    auto index = [&](int x, int y, int e, int mask) {
        return ((static_cast<size_t>(x * n + y) * (energy + 1) + e) << cnt) + mask;
    };

    std::queue<std::array<int, 4>> q;
    int full = (1 << cnt) - 1;
    q.push({sx, sy, energy, full});
    vis[index(sx, sy, energy, full)] = true;

    // Every move costs the same, so the level a state is found on is its
    // distance from the start.
    const int dirs[5] = {-1, 0, 1, 0, -1};
    for (int moves = 0; !q.empty(); ++moves) {
        for (int sz = static_cast<int>(q.size()); sz > 0; --sz) {
            auto [x, y, e, mask] = q.front();
            q.pop();

            if (mask == 0) return moves;
            if (e == 0) continue;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (classroom[nx][ny] == 'X') continue;

                // A reset pad refills the battery every time it is stepped on,
                // and litter is swept up simply by walking over it.
                int ne = classroom[nx][ny] == 'R' ? energy : e - 1;
                int nmask = classroom[nx][ny] == 'L' ? mask & ~(1 << id[nx][ny]) : mask;
                size_t next = index(nx, ny, ne, nmask);
                if (!vis[next]) {
                    vis[next] = true;
                    q.push({nx, ny, ne, nmask});
                }
            }
        }
    }
    return -1;
}
