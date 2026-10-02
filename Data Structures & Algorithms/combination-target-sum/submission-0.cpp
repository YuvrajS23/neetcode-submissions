class Solution {
    void recursion(vector<int>& nums, int target, int start, vector<vector<int>>& res, vector<int>& subset){
        if(target == 0){
            res.push_back(subset);
            return;
        }
        if(target < 0) return;
        for(int i=start; i < nums.size(); i++){
            subset.push_back(nums[i]);
            
            recursion(nums, target - nums[i], i, res, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        recursion(nums, target, 0, res, subset);
        return res;
    }
};
