#include "graphs/create_grid_with_exactly_one_path.hpp"

std::vector<std::string> createGrid(int m, int n) {
    std::vector<std::string> res(m, std::string(n, '.'));
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n - 1; j++) res[i][j] = '#';
    }
    return res;
}
