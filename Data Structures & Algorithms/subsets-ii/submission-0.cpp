class Solution {
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        for(int i = start; i < nums.size(); i++) {
            cout<<i<<" "<<endl;
            if(i > start && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset, res);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }
};
