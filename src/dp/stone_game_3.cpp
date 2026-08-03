#include "dp/stone_game_3.hpp"

class Solution {
public:
    const int N = -(5e7+1);
    int help(int i, std::vector<int>&dp, std::vector<int>&v){
        if(i==dp.size()) return 0;
        if(dp[i]!=N) return dp[i];
        int res = dp[i], sum = 0;
        for(int j=1;j<=3 && i+j<=v.size();j++){
            sum += v[i+j-1];
            res = std::max(res, sum - help(i+j, dp, v));
        }
        return dp[i] = res;
    }
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> dp(n, N);
        int res = help(0, dp, stoneValue);
        if(res > 0) return "Alice";
        else if(res==0) return "Tie";
        return "Bob";
    }  
};