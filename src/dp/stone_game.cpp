#include "dp/stone_game.hpp"

int check(int l, int r, vector<int>& p, vector<vector<int>>&dp){
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = max(p[l]-check(l+1, r, p, dp), p[r]-check(l, r-1, p, dp));

    }
bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n,vector<int>(n, -1));
    return check(0, n-1, piles, dp); 
}