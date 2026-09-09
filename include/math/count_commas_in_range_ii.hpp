#pragma once

// Written with a comma after every third digit from the right, an integer x
// carries one comma for each power 1000^k (k >= 1) with x >= 1000^k. Return the
// total number of commas used when writing every integer from 1 to n.
// Same statement as Count Commas in Range with n up to 1e18, so both the answer
// and the running power of 1000 need 64-bit arithmetic.
long long countCommas(long long n);
