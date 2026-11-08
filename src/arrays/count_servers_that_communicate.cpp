#include "arrays/count_servers_that_communicate.hpp"

int countServers(std::vector<std::vector<int>>& grid) {
    int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
    std::vector<int> r(n), c(m);  // servers per row / per column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                r[i]++;
                c[j]++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] && (r[i] > 1 || c[j] > 1)) res++;
        }
    }
    return res;
}
