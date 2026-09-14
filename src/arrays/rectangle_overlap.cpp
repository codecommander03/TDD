#include "arrays/rectangle_overlap.hpp"

bool isRectangleOverlap(const std::vector<int>& r1, const std::vector<int>& r2) {
    // The x-ranges must properly overlap and so must the y-ranges. Strict <
    // rejects rectangles that merely touch along an edge or at a corner.
    return r1[0] < r2[2] && r2[0] < r1[2] && r1[1] < r2[3] && r2[1] < r1[3];
}
