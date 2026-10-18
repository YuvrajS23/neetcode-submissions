class Solution {
    int dfs(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -2){
            return dp[amount];
        }

        int res = INT_MAX;
        for(auto coin : coins){
            if(amount - coin >= 0){
                int subRes = dfs(coins, amount - coin, dp);
                if(subRes != INT_MAX) res = min(1 + subRes, res);
            }
        }
        dp[amount] = res;
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        int res = dfs(coins, amount, dp);
        if(res == INT_MAX) return -1;
        return res;
    }
};
