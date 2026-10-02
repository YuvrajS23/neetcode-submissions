class Solution {
    void backtrack(vector<int>& perm, vector<int>& nums, int mask, vector<vector<int>>& res){
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i=0; i < nums.size(); i++) {
            if(!(mask & (1 << i))){
                perm.push_back(nums[i]);
                backtrack(perm, nums, mask | (1<<i), res);
                perm.pop_back();
            }
        }
    } 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        backtrack(perm, nums, 0, res);
        return res;
    }
};
