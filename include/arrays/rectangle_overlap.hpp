#pragma once
#include <vector>

// Each rectangle is [x1, y1, x2, y2] with (x1, y1) bottom-left and (x2, y2)
// top-right. True only when the shared region has positive area.
bool isRectangleOverlap(const std::vector<int>& r1, const std::vector<int>& r2);
