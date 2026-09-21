class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> valMap;
        for(int i=0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (valMap.find(diff) != valMap.end()){
                return {valMap[diff], i};
            }
            valMap.insert({nums[i], i});
        }
        return {};
    }
};
