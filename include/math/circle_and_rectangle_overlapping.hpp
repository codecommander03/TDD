#pragma once

// Circle of radius r centred at (cx, cy) against the axis-aligned rectangle
// with (x1, y1) bottom-left and (x2, y2) top-right. True when the two share at
// least one point, boundaries included.
bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2);
