#include "arrays/cinema_seat_allocation.hpp"
#include <map>

int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
    // For each row that has any reservation, track which of the three
    // overlapping four-seat blocks are blocked:
    //   bit 0 -> seats 2-5, bit 1 -> seats 4-7, bit 2 -> seats 6-9.
    std::map<int, int> blocked;
    for (const auto& seat : reservedSeats) {
        int row = seat[0], col = seat[1];
        if (col >= 2 && col <= 5) blocked[row] |= 1;
        if (col >= 4 && col <= 7) blocked[row] |= 2;
        if (col >= 6 && col <= 9) blocked[row] |= 4;
    }

    // Rows with no reservation at all seat two families each.
    int res = 2 * (n - static_cast<int>(blocked.size()));

    for (const auto& [row, mask] : blocked) {
        if ((mask & 1) == 0 && (mask & 4) == 0) {
            res += 2;  // both outer blocks (2-5 and 6-9) are free
        } else if ((mask & 1) == 0 || (mask & 2) == 0 || (mask & 4) == 0) {
            res += 1;  // only a single block remains free
        }
    }
    return res;
}
