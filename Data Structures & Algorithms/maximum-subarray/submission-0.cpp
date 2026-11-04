class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(2, 0));
        vector<vector<bool>> seen(nums.size(), vector<bool>(2, false));
        return dfs(nums, 0, false, memo, seen);
    }

    int dfs(vector<int>& nums, int i, bool flag, vector<vector<int>>& memo, vector<vector<bool>>& seen){
        if(i == nums.size() - 1) return flag ? max(0, nums[i]) : nums[i];
        int f = flag ? 1 : 0;
        if(seen[i][f]) return memo[i][f];
        if(flag){
            memo[i][f] = max(0, nums[i] + dfs(nums, i + 1, true, memo, seen));
        }
        else{
            memo[i][f] = max(dfs(nums, i+1, false, memo, seen) , nums[i] + dfs(nums, i + 1, true, memo, seen));
        }
        seen[i][f] = true;

        return memo[i][f];
    }
};
