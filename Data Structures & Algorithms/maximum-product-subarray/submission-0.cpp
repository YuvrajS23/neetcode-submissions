class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;
        for(auto num: nums){
            int temp = curMax * num;
            curMax = max(num, max(num * curMax, num * curMin));
            curMin = min(num, min(temp, num * curMin));

            res = max(res, curMax);
        }

        return res;
    }
};
