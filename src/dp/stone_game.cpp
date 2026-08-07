#include "dp/stone_game.hpp"

int check(int l, int r, std::vector<int>& p, std::vector<std::vector<int>>&dp){
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = std::max(p[l]-check(l+1, r, p, dp), p[r]-check(l, r-1, p, dp));

    }
bool stoneGame(std::vector<int>& piles) {
    int n = piles.size();
    std::vector<std::vector<int>> dp(n,std::vector<int>(n, -1));
    return check(0, n-1, piles, dp); 
}