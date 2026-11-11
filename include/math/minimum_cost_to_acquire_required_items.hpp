#pragma once

// Type-1 items cost cost1, type-2 items cost cost2, and a combined item worth one
// of each costs costBoth. Returns the minimum cost to get at least need1 type-1
// and need2 type-2 items.
long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2);
