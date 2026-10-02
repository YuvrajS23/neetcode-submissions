class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for(long i = 0; i <= (1 << n) - 1; i++){
            vector<int> subset;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};
