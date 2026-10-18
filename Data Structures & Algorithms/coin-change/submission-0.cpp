class Solution {
    int dfs(vector<int>& coins, int amount, unordered_map<int, int>& dp){
        if(dp.count(amount)){
            return dp[amount];
        }

        if(amount == 0){
            return 0;
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
        unordered_map<int, int> dp;
        dp[0] = 0;
        int res = dfs(coins, amount, dp);
        if(res == INT_MAX) return -1;
        return res;
    }
};
