#include "math/circle_and_rectangle_overlapping.hpp"

#include <algorithm>

bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
    // Clamping the centre into the rectangle gives the rectangle point closest
    // to it, so the shapes meet exactly when that point is within r. The axes
    // are independent, which is why each one clamps on its own.
    int x = std::clamp(cx, x1, x2) - cx;
    int y = std::clamp(cy, y1, y2) - cy;

    // Compare squared distances to stay in integers: the spans are at most
    // 2 * 10^4, so x * x + y * y fits comfortably in an int.
    return x * x + y * y <= r * r;
}
