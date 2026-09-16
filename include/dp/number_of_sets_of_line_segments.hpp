#pragma once

// n points sit at x = 0..n-1; count the ways to draw k segments whose
// endpoints are points and whose interiors do not overlap (sharing an
// endpoint is allowed), modulo 1e9 + 7.
int numberOfSets(int n, int k);
